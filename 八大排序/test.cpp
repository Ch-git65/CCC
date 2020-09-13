#include<iostream>
using namespace std;


void Swap(int* array, int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

// 1.ֱ�Ӳ�������
// ���Ѿ�����������и������������ҵ�һ�����ʵ�λ��
// ����ʼ֮ǰ�������һ�������������
// ����Ĺ��̣�������������ݴӺ���ǰ���κ���������ݽ��бȽ�

// ʱ�临�Ӷȣ� �0(n^2)  ƽ��O(n^2)  ���O(n)
// �ռ临�Ӷȣ� O��1��
// �ȶ��� ����

void insertSort(int* array, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i; //�������е����һ��λ��
		int key = array[end + 1]; //�������һ������

		while (end >= 0 && array[end] > key)
		{
			array[end + 1] = array[end]; //�ҵ���һ��С�ڵ���key��λ��
			--end; //����ǰ��������ƶ�
		}
		array[end + 1] = key; //��key���ݴ���ڵ�ǰλ��
	}
}



// ϣ������
// ��ѡ��һ���������Ѵ�������ļ������м�¼�ֳɶ���飬
// ���о���Ϊgap�ļ�Ϊһ�飬����ÿһ�������ݽ�������Ȼ���ظ�����
// ֱ��gap�ﵽ1ʱ�����м�¼�����ݶ��ź����ˡ�
// ���ж��ֵ�Ԥ���� �����ִ����ͨ�Ĳ�������
// Ԥ��������Ԫ�ؽ��в�������


// ʱ�临�Ӷȣ� �0(n^1.3��  ƽ��O(n^1.3)  ���O(n)
// �ռ临�Ӷȣ� O��1��
// ���ȶ��� ����

void shellSort(int* array, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		// ����������ͨ����ͬ��gap�������߼�����
		// �����ڽ��в������� ��ͬ���Ԫ�ؽ����������

		for (int i = 0; i < n - gap; i++)
		{
			//һ�ֲ�������
			int end = i;
			//��������һ��λ��
			int key = array[end + gap];
			//ͬ����֮�е�һ��Ҫ���������
			while (end >= 0 && array[end] > key)
			{
				//�ҵ���һ��С�ڵ��ڵ�����
				array[end + gap] = array[end];
				//���������˲��
				end -= gap;
				// end���¸�ֵ
			}
			array[end + gap] = key;
			//���������������ݲ��뵽�µ�λ��
		}
	}
}


//ѡ������

// 111111
//ÿһ�δӴ����������Ԫ��֮��ѡ�����С���󣩵�һ��Ԫ�أ�
//��������е���ʼλ�ã�ֱ��ȫ�������������������ϡ�

// ʱ�临�Ӷȣ� �0(n^2��  ƽ��O(n^2)  ���O(n^2)
// �ռ临�Ӷȣ� O��1��
// �ȶ��� ������

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
//�����߿�ʼ����ѡ������
void selectSort(int* array, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)   //���С���ұ�
	{
		int min = begin, max = begin;
		//��ʼ��min��maxλ��ȫ��ָ��ʼ
		for (int i = begin + 1; i <= end; i++)
		{
			if (array[i] >= array[max])
				//�ҵ����ֵ
				max = i;

			if (array[i] < array[min])
				min = i;
		}

		Swap(array, begin, min); //����С��λ�ú�����ߵ����ݽ���
		if (max == begin) //�����ĵ�����ߵ�����ʱ�� ���ʾ���ݷ����˱仯
			max = min;//��minλ�ø�ֵ��max

		Swap(array, end, max); //���ֵ����
		begin++;
		end--;
	}
}



//������
// ʱ�临�Ӷȣ� O(nlogn)
// �ռ临�Ӷȣ� O��1��
// ���ȶ��� ������

//�����  ��������
void ShiftDown(int* array, int n, int parent)
{
	int child = 2 * parent + 1;

	while (child < n)
	{

		//�ж�����������������£����Һ������ߵĽϴ�ֵ
		if (child + 1 < n && array[child + 1] > array[child])
			//���ұߺ��ӱ���ߺ��Ӵ���childλ�ü�1
			child++;

		if (array[child] > array[parent])
		{
			//�����ӱȸ��׵�ֵ���򽻻�λ��
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break; //������ֵС�ڸ��ף�������
	}
}

void SortHeap(int* array, int n)
{
	//����
	for (int i = (n - 2) / 2; i >= 0; i--)
		ShiftDown(array, n, i);

	while (n)
	{
		Swap(array, 0, n - 1);
		n--;
		ShiftDown(array, n, 0);
	}
}


//ð������
//����Ԫ��֮����бȽϣ���Ŀ�ʼ����ƶ�

// ʱ�临�Ӷȣ� �0(n^2��  ƽ��O(n^2)  ���O(n)
// �ռ临�Ӷȣ� O��1��
// �ȶ��� ����

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