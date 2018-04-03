#include <stdio.h>
#include <math.h>
#include <string.h>
#include "./include/externs.h"
#include "./include/erf.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                          F R E Q U E N C Y  T E S T
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void frequency(int intArr[] , int n)
{
	int		i;
	double	f, s_obs, p_value, sum, sqrt2 = sqrt(2);
	
	sum = 0.0;
	for ( i=0; i<n; i++ )
		sum += 2*(int)intArr[i]-1;
	s_obs = fabs(sum)/sqrt(n);
	f = s_obs/sqrt2;
	p_value = erfc(f);

	printf("\t\t\t      FREQUENCY TEST\n");
	printf("\t\t---------------------------------------------\n");
	printf("\t\tCOMPUTATIONAL INFORMATION:\n");
	printf("\t\t---------------------------------------------\n");
	printf("\t\t(a) The nth partial sum = %d\n", (int)sum);
	printf("\t\t(b) S_n/n               = %f\n", sum/n);
	printf("\t\t---------------------------------------------\n");

	printf("%s\t\tp_value = %f\n\n", p_value < ALPHA ? "FAILURE" : "SUCCESS", p_value);
	printf("%f\n", p_value);
}
