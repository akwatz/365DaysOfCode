#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//#include "../include/externs.h"
#include "include/cephes.h"  

#define ALPHA 0.01


void
LinearComplexity(int epsilon[] , int M, int n)
{
	int       i, ii, j, d, N, L, m, N_, parity, sign, K = 6;
	double    p_value, T_, mean, nu[7], chi2;
	double    pi[7] = { 0.01047, 0.03125, 0.12500, 0.50000, 0.25000, 0.06250, 0.020833 };
	int  *T, *P, *B_, *C;
	
	N = (int)floor(n/M);
	if ( ((B_ = (int *) calloc(M, sizeof(int))) == NULL) ||
		 ((C  = (int *) calloc(M, sizeof(int))) == NULL) ||
		 ((P  = (int *) calloc(M, sizeof(int))) == NULL) ||
		 ((T  = (int *) calloc(M, sizeof(int))) == NULL) ) {
		printf("Insufficient Memory for Work Space:: Linear Complexity Test\n");
		if ( B_!= NULL )
			free(B_);
		if ( C != NULL )
			free(C);
		if ( P != NULL )
			free(P);
		if ( T != NULL )
			free(T);
		return;
	}


	printf("-----------------------------------------------------\n");
	printf("\tL I N E A R  C O M P L E X I T Y\n");
	printf("-----------------------------------------------------\n");
	printf("\tM (substring length)     = %d\n", M);
	printf("\tN (number of substrings) = %d\n", N);
	printf("-----------------------------------------------------\n");
	printf("        F R E Q U E N C Y                            \n");
	printf("-----------------------------------------------------\n");
	printf("  C0   C1   C2   C3   C4   C5   C6    CHI2    P-value\n");
	printf("-----------------------------------------------------\n");

	for ( i=0; i<K+1; i++ )
		nu[i] = 0.00;
	for ( ii=0; ii<N; ii++ ) {
		for ( i=0; i<M; i++ ) {
			B_[i] = 0;
			C[i] = 0;
			T[i] = 0;
			P[i] = 0;
		}
		L = 0;
		m = -1;
		d = 0;
		C[0] = 1;
		B_[0] = 1;
		
		/* DETERMINE LINEAR COMPLEXITY */
		N_ = 0;
		while ( N_ < M ) {
			d = (int)epsilon[ii*M+N_];
			for ( i=1; i<=L; i++ )
				d += C[i] * epsilon[ii*M+N_-i];
			d = d%2;
			if ( d == 1 ) {
				for ( i=0; i<M; i++ ) {
					T[i] = C[i];
					P[i] = 0;
				}
				for ( j=0; j<M; j++ )
					if ( B_[j] == 1 )
						P[j+N_-m] = 1;
				for ( i=0; i<M; i++ )
					C[i] = (C[i] + P[i])%2;
				if ( L <= N_/2 ) {
					L = N_ + 1 - L;
					m = N_;
					for ( i=0; i<M; i++ )
						B_[i] = T[i];
				}
			}
			N_++;
		}
		if ( (parity = (M+1)%2) == 0 ) 
			sign = -1;
		else 
			sign = 1;
		mean = M/2.0 + (9.0+sign)/36.0 - 1.0/pow(2, M) * (M/3.0 + 2.0/9.0);
		if ( (parity = M%2) == 0 )
			sign = 1;
		else 
			sign = -1;
		T_ = sign * (L - mean) + 2.0/9.0;
		
		if ( T_ <= -2.5 )
			nu[0]++;
		else if ( T_ > -2.5 && T_ <= -1.5 )
			nu[1]++;
		else if ( T_ > -1.5 && T_ <= -0.5 )
			nu[2]++;
		else if ( T_ > -0.5 && T_ <= 0.5 )
			nu[3]++;
		else if ( T_ > 0.5 && T_ <= 1.5 )
			nu[4]++;
		else if ( T_ > 1.5 && T_ <= 2.5 )
			nu[5]++;
		else
			nu[6]++;
	}
	chi2 = 0.00;
	for ( i=0; i<K+1; i++ ) 
		printf("%4d ", (int)nu[i]);
	for ( i=0; i<K+1; i++ )
		chi2 += pow(nu[i]-N*pi[i], 2) / (N*pi[i]);
	p_value = cephes_igamc(K/2.0, chi2/2.0);

	printf("%9.6f%9.6f\n", chi2, p_value);
	printf("%f\n", p_value);

	printf("%s\t\tp_value = %f\n\n", p_value < 0.01 ? "FAILURE" : "SUCCESS", p_value);

	free(B_);
	free(P);
	free(C);
	free(T);
}
