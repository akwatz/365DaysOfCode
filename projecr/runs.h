#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
//#include "./include/externs.h"
#include "./include/cephes.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                              R U N S  T E S T 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Runs(int epsilon[] , int n)
{
	int		S, k;
	double	pi, V, erfc_arg, p_value;

	S = 0;
	for ( k=0; k<n; k++ )
		if ( epsilon[k] )
			S++;
	pi = (double)S / (double)n;

	if ( fabs(pi - 0.5) > (2.0 / sqrt(n)) ) {
		printf("\t\t\t\tRUNS TEST\n");
		printf("\t\t------------------------------------------\n");
		printf("\t\tPI ESTIMATOR CRITERIA NOT MET! PI = %f\n", pi);
		p_value = 0.0;
	}
	else {

		V = 1;
		for ( k=1; k<n; k++ )
			if ( epsilon[k] != epsilon[k-1] )
				V++;
	
		erfc_arg = fabs(V - 2.0 * n * pi * (1-pi)) / (2.0 * pi * (1-pi) * sqrt(2*n));
		p_value = erfc(erfc_arg);
		
		printf("\t\t\t\tRUNS TEST\n");
		printf("\t\t------------------------------------------\n");
		printf("\t\tCOMPUTATIONAL INFORMATION:\n");
		printf("\t\t------------------------------------------\n");
		printf("\t\t(a) Pi                        = %f\n", pi);
		printf("\t\t(b) V_n_obs (Total # of runs) = %d\n", (int)V);
		printf("\t\t(c) V_n_obs - 2 n pi (1-pi)\n");
		printf("\t\t    -----------------------   = %f\n", erfc_arg);
		printf("\t\t      2 sqrt(2n) pi (1-pi)\n");
		printf("\t\t------------------------------------------\n");
		if ( isNegative(p_value) || isGreaterThanOne(p_value) )
			printf("WARNING:  P_VALUE IS OUT OF RANGE.\n");

		printf("%s\t\tp_value = %f\n\n", p_value < 0.01 ? "FAILURE" : "SUCCESS", p_value);
	}

	printf("%f\n", p_value);
}
