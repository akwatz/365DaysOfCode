#include <stdio.h>
#include <math.h>
#include <string.h>
//#include "../include/externs.h"
#include "include/cephes.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                    B L O C K  F R E Q U E N C Y  T E S T
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void blockFrequency(int epsilon[] , int M , int n)
{
	int		i, j, N, blockSum;
	double	p_value, sum, pi, v, chi_squared;
	
	N = n/M; 		/* # OF SUBSTRING BLOCKS      */
	sum = 0.0;
	
	for ( i=0; i<N; i++ ) {
		blockSum = 0;
		for ( j=0; j<M; j++ )
			blockSum += epsilon[j+i*M];
		pi = (double)blockSum/(double)M;
		v = pi - 0.5;
		sum += v*v;
	}
	chi_squared = 4.0 * M * sum;
	p_value = cephes_igamc(N/2.0, chi_squared/2.0);

	printf("\t\t\tBLOCK FREQUENCY TEST\n");
	printf("\t\t---------------------------------------------\n");
	printf("\t\tCOMPUTATIONAL INFORMATION:\n");
	printf("\t\t---------------------------------------------\n");
	printf("\t\t(a) Chi^2           = %f\n", chi_squared);
	printf("\t\t(b) # of substrings = %d\n", N);
	printf("\t\t(c) block length    = %d\n", M);
	printf("\t\t(d) Note: %d bits were discarded.\n", n % M);
	printf("\t\t---------------------------------------------\n");

	printf("%s\t\tp_value = %f\n\n", p_value < 0.01 ? "FAILURE" : "SUCCESS", p_value);
	printf("%f\n", p_value);
}
