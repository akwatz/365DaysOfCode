#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h>
//#include "../include/externs.h"
#include "include/cephes.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
            R A N D O M  E X C U R S I O N S  V A R I A N T  T E S T
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define ALPHA 0.01

void
RandomExcursionsVariant(int epsilon[] , int n)
{
	int		i, p, J, x, constraint, count, *S_k;
	int		stateX[18] = { -9, -8, -7, -6, -5, -4, -3, -2, -1, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double	p_value;
	
	if ( (S_k = (int *)calloc(n, sizeof(int))) == NULL ) {
		printf("\t\tRANDOM EXCURSIONS VARIANT: Insufficent memory allocated.\n");
		return;
	}
	J = 0;
	S_k[0] = 2*(int)epsilon[0] - 1;
	for ( i=1; i<n; i++ ) {
		S_k[i] = S_k[i-1] + 2*epsilon[i] - 1;
		if ( S_k[i] == 0 )
			J++;
	}
	if ( S_k[n-1] != 0 )
		J++;

	printf("\t\t\tRANDOM EXCURSIONS VARIANT TEST\n");
	printf("\t\t--------------------------------------------\n");
	printf("\t\tCOMPUTATIONAL INFORMATION:\n");
	printf("\t\t--------------------------------------------\n");
	printf("\t\t(a) Number Of Cycles (J) = %d\n", J);
	printf("\t\t(b) Sequence Length (n)  = %d\n", n);
	printf("\t\t--------------------------------------------\n");

	//constraint = (int)MAX(0.005*pow(n, 0.5), 500);
	constraint = 1;

	if (J < constraint) {
		printf("\n\t\tWARNING:  TEST NOT APPLICABLE.  THERE ARE AN\n");
		printf("\t\t\t  INSUFFICIENT NUMBER OF CYCLES.\n");
		printf("\t\t---------------------------------------------\n");
		for ( i=0; i<18; i++ )
			printf("%f\n", 0.0);
	}
	else {
		for ( p=0; p<=17; p++ ) {
			x = stateX[p];
			count = 0;
			for ( i=0; i<n; i++ )
				if ( S_k[i] == x )
					count++;
			p_value = erfc(fabs(count-J)/(sqrt(2.0*J*(4.0*fabs(x)-2))));

			if ( isNegative(p_value) || isGreaterThanOne(p_value) )
				printf("\t\t(b) WARNING: P_VALUE IS OUT OF RANGE.\n");
			printf("%s\t\t", p_value < ALPHA ? "FAILURE" : "SUCCESS");
			printf("(x = %2d) Total visits = %4d; p-value = %f\n", x, count, p_value);
			printf("%f\n", p_value);
		}
	}
	printf("\n");
	free(S_k);
}
