#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000000
int x[N];

int main()
{
	srand(time(NULL));
	int n = N;
	int tmp1, tmp2, i;
	int k = N / 2 ;
	FILE *pFile;
	pFile = fopen("data", "w");
	for(i = 0; i < n; i++){
		x[i] = i;
	}
	for(i = 0; i < k; i++){
		tmp1 = x[i];
		tmp2 = rand()%(n-i) + i;
		x[i] = x[tmp2];
		x[tmp2] = tmp1;
	}
	for(i = 0; i < k; i++){
		fprintf(pFile,"%d ", x[i]);
	}
	fclose(pFile);
	return 0;
}
