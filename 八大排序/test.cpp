#include<iostream>
using namespace std;


void Swap(int* array, int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

// 1.直接插入排序
// 在已经有序的数据中给待定的数据找到一个合适的位置
// 排序开始之前；假设第一个数据是有序的
// 排序的过程：将待插入的数据从后向前依次和有序的数据进行比较

// 时间复杂度： 最坏0(n^2)  平均O(n^2)  最好O(n)
// 空间复杂度： O（1）
// 稳定， 敏感

void insertSort(int* array, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i; //有序序列的最后一个位置
		int key = array[end + 1]; //待插入的一个数据

		while (end >= 0 && array[end] > key)
		{
			array[end + 1] = array[end]; //找到第一个小于等于key的位置
			--end; //将当前数据向后移动
		}
		array[end + 1] = key; //将key数据存放在当前位置
	}
}



// 希尔排序
// 先选定一个整数，把待排序的文件中所有记录分成多个组，
// 所有距离为gap的记为一组，并对每一组内数据进行排序，然后重复进行
// 直到gap达到1时，所有记录的数据都排好序了。
// 进行多轮的预排序， 最后再执行普通的插入排序
// 预排序：组内元素进行插入排序


// 时间复杂度： 最坏0(n^1.3）  平均O(n^1.3)  最好O(n)
// 空间复杂度： O（1）
// 不稳定， 敏感

void shellSort(int* array, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		// 步长缩减，通过不同的gap来进行逻辑分组
		// 在组内进行插入排序， 不同组的元素交替进行排序

		for (int i = 0; i < n - gap; i++)
		{
			//一轮插入排序
			int end = i;
			//排序的最后一个位置
			int key = array[end + gap];
			//同分组之中第一个要插入的数据
			while (end >= 0 && array[end] > key)
			{
				//找到第一个小于等于的数据
				array[end + gap] = array[end];
				//将数据向后瞬移
				end -= gap;
				// end重新赋值
			}
			array[end + gap] = key;
			//将所需待插入的数据插入到新的位置
		}
	}
}


//选择排序

// 111111
//每一次从待排序的数据元素之中选择出最小（大）的一个元素，
//存放在序列的起始位置，直到全部待排序的数据排列完毕。

// 时间复杂度： 最坏0(n^2）  平均O(n^2)  最好O(n^2)
// 空间复杂度： O（1）
// 稳定， 不敏感

void selectSort(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		int start = i;
		int min = start;

		for (int j = start + 1; j < n; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		Swap(array, start, min);
	}
}



//22222222222
//从两边开始进行选择排序
void selectSort(int* array, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)   //左边小于右边
	{
		int min = begin, max = begin;
		//初始化min和max位置全部指向开始
		for (int i = begin + 1; i <= end; i++)
		{
			if (array[i] >= array[max])
				//找到最大值
				max = i;

			if (array[i] < array[min])
				min = i;
		}

		Swap(array, begin, min); //将最小的位置和最左边的数据交换
		if (max == begin) //若最大的等于左边的数据时， 则表示数据发生了变化
			max = min;//将min位置赋值给max

		Swap(array, end, max); //最大值交换
		begin++;
		end--;
	}
}



//堆排序
// 时间复杂度： O(nlogn)
// 空间复杂度： O（1）
// 不稳定， 不敏感

//建大堆  升序序列
void ShiftDown(int* array, int n, int parent)
{
	int child = 2 * parent + 1;

	while (child < n)
	{

		//判断在满足条件的情况下，左右孩子两者的较大值
		if (child + 1 < n && array[child + 1] > array[child])
			//若右边孩子比左边孩子大，则将child位置加1
			child++;

		if (array[child] > array[parent])
		{
			//若孩子比父亲的值大，则交换位置
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break; //若孩子值小于父亲，则跳出
	}
}

void SortHeap(int* array, int n)
{
	//建堆
	for (int i = (n - 2) / 2; i >= 0; i--)
		ShiftDown(array, n, i);

	while (n)
	{
		Swap(array, 0, n - 1);
		n--;
		ShiftDown(array, n, 0);
	}
}


//冒泡排序
//相邻元素之间进行比较，大的开始向后移动

// 时间复杂度： 最坏0(n^2）  平均O(n^2)  最好O(n)
// 空间复杂度： O（1）
// 稳定， 敏感

void bubbleSort(int* array, int n)
{
	while (n)
	{
		int flag = 1;
		int end = n;

		for (int i = 1; i < end; i++)
		{
			if (array[i - 1] > array[i])
			{
				Swap(array, i, i - 1);
				flag = 0;
			}
		}
		if (flag)
			break;
		n--;
	}
}