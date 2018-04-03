#include "frequency.h"
//#include "functions/block_frequency_test.h"
#include"functions/runs.h"
#include "longestRuns.h"

int main(int argc, char **argv)
{

	long max_len = 1000000;
	char binaryStr[max_len];
	int length=1;

	if(argc < 2)
	{
		printf("Enter the binary string\n");
		scanf("%s",binaryStr);
	}
	else
	{
		char *filename = argv[1],tmp;
		printf("File Name: %s\n", filename);

		FILE *fptr; 
		fptr = fopen(filename, "r");

		if(fptr != NULL)
		{
			printf("File has been opened\n");
		}
		else
		{
			printf("File is empty\n");
			return 0;
		}

		//reading file
	
		
		fgets(binaryStr,max_len,fptr);

		

	}
	length = strlen(binaryStr);

	int intArr[length];

	int i;

	for(i = 0 ; i < length ; i++)
		intArr[i] = binaryStr[i] - '0';

	//frequency(intArr , length);
	Runs(intArr , length);
	
//	int m;
//	scanf("%d",&m);
//	blockFrequency(binaryStr,m,length);



//	runs(binaryStr,length);

	//longestRunOfOnes(binaryStr,length);
	
	return 0;
}