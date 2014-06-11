#include <stdio.h>
#include "../../typedef.h"

#define HEAP_LENTH	10

#define LEFT(i) 	(i<<1)
#define RIGHT(i)	((i<<1)+1)
#define PARENT(i)	(i>>1)

uint32 heap_lenth = HEAP_LENTH;

void max_heapify(uint32 *array, uint32 idx)
{
	uint32 ileft = LEFT(idx);
	uint32 iright = RIGHT(idx);
	uint32 large = idx;

	if((ileft <= heap_lenth) && array[ileft] > array[large])
		large = ileft;	
	if((iright <= heap_lenth) && array[iright] > array[large])
		large = iright;

	if(large != idx)
	{
		uint32 itemp;
		itemp = array[large];
		array[large] = array[idx];
		array[idx] = itemp;

		max_heapify(array, large);	
	}
}

void build_max_heap(uint32 *array)
{
	uint32 i;
	
	for(i = (heap_lenth>>1); i > 0; i--)
		max_heapify(array, i);
}

void heapsort(uint32 *array)
{
	uint32 ltemp = heap_lenth;

	build_max_heap(array);

	while(heap_lenth > 1)	
	{
		uint32 temp;
		temp = array[1];
		array[1] = array[heap_lenth];
		array[heap_lenth] = temp;
		heap_lenth--;
		max_heapify(array, 1);	
	}
	heap_lenth = ltemp;		
}

void input(uint32 *array)
{
	uint32 i = 1;

	for(i = 1; i <= HEAP_LENTH; i++)
		array[i] = 0;

	printf("please input %ld intergers.\n", heap_lenth);

	i = 1;	
	while(i <= heap_lenth)
	{
		scanf("%ld", array+i);
		i++;
	}
}

void output(uint32 *array)
{
	uint32 i = 1;

	printf("max heap sort result:\n");

	for(i = 1; i <= heap_lenth; i++)
		printf("%ld ", array[i]);

	printf("\n");
}

uint32 heap_maximum(uint32 *array)
{	
	return array[1];
}

uint32 heap_extract_maximum(uint32 *array)
{
	uint32 max = array[1];

	array[1] = array[heap_lenth];
	heap_lenth--;
	max_heapify(array, 1);

	return max;	
}

void heap_increase_key(uint32 *array, uint32 idx, uint32 key)
{
	uint32 p;
	uint32 c;

	if(idx > heap_lenth)
		return;

	if(key < array[idx])
		return;

	array[idx] = key;
	c = idx;
	p = PARENT(c);

	while((p >= 1) && (array[p] < array[c]))
	{
		uint32 temp;
		temp = array[p];
		array[p] = array[c];
		array[c] = temp;
		c = p;
		p = PARENT(c);
	}
}

void max_heap_insert(uint32 *array, uint32 key)
{
	if(heap_lenth >= HEAP_LENTH)
		return;

	heap_lenth++;
	array[heap_lenth] = 0;
	heap_increase_key(array, heap_lenth, key);
}

int main(void)
{
	uint32 n;
	uint32 a[HEAP_LENTH+1] = {0};
	
	printf("input the number of datas: ");
	while(scanf("%ld", &n))
	{
		uint32 max;
		n = (n > HEAP_LENTH)? HEAP_LENTH:n;
		heap_lenth = n;
		input(a);
		build_max_heap(a);
		max = heap_maximum(a);
		printf("max = %ld\n", max);
		max = heap_extract_maximum(a);
		max = heap_maximum(a);
		printf("after extract maximum, now max = %ld\n", max);
		max_heap_insert(a, max + 1);
		max = heap_maximum(a);
		printf("after insert a big one, now max = %ld\n", max);
		heapsort(a);
		output(a);
		printf("input the number of datas: ");
	}
	return 1;
}
