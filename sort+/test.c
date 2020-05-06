#include"sort.h"

void printArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void test()
{
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);
	/*int* copy = (int*)malloc(sizeof(int) * size);
	memcpy(copy, array, sizeof(int) * size);*/

	printArray(array, size);
	insertSort(array, size);
	printf("insertSort:\n");
	printArray(array, size);
}

int main()
{
	test();
	return 0;
}