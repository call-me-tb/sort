#include <stdio.h>
#include "../../typedef.h"

#define ARRAY_LENTH		10


uint32 array_lenth = 0;

uint32 partition(uint32 *array, uint32 begin, uint32 end)
{
	uint32 split = *(array+end);
	uint32 idx;
	uint32 mid = begin - 1;

	for(idx = begin; idx < end; idx++)
	{
		if(*(array+idx) < split)
		{
			uint32 temp;
			mid++;
			temp = *(array+idx);
			*(array+idx) = *(array+mid);
		   	*(array+mid) = temp;	
		}
	}
	*(array+end) = *(array+mid+1);
	*(array+mid+1) = split;
	return mid+1;
}

void quicksort(uint32 *array, uint32 begin, uint32 end)
{
	if(begin < end)
	{
		uint32 mid = partition(array, begin, end);
		quicksort(array, begin, mid-1);
		quicksort(array, mid+1, end);
	}
}
void input(uint32 *array)
{
	uint32 i = 1;

	for(i = 1; i <= ARRAY_LENTH; i++)
		array[i] = 0;

	printf("please input %ld intergers.\n", array_lenth);

	i = 1;	
	while(i <= array_lenth)
	{
		scanf("%ld", array+i);
		i++;
	}
}

void output(uint32 *array)
{
	uint32 i = 1;

	printf("sort result:\n");

	for(i = 1; i <= array_lenth; i++)
		printf("%ld ", array[i]);

	printf("\n");
}
int main(void)
{
	uint32 n;
	uint32 a[ARRAY_LENTH+1] = {0};
	
	printf("input the number of datas: ");
	while(scanf("%ld", &n))
	{
		n = (n > ARRAY_LENTH)? ARRAY_LENTH:n;
		array_lenth = n;
		input(a);
		quicksort(a, 1, n);
		output(a);
		printf("input the number of datas: ");
	}
	return 1;
}
