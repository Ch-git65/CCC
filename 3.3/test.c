//#include<stdio.h>
//int main()
//{
	//һ������
	//int arr[] = {1,2,3,4};
	//printf("%d\n", sizeof(arr));      // 16
	//printf("%d\n", sizeof(arr+0));    // 4  int*    arr�Ѿ���ʽת��Ϊָ��
	//printf("%d\n", sizeof(*arr));     // 4  �Ѿ���ʽת��λint* �ڽ����ã��õ�int
	//printf("%d\n", sizeof(arr+1));    // 4   arr�Ѿ���ʽת���� int*
	//printf("%d\n", sizeof(arr[1]));   // 4  int
	//printf("%d\n", sizeof(&arr));     // 4  &arr��һ��int(*)[4],ָ��
	//printf("%d\n", sizeof(*&arr));    // 16 &arr������ָ�룬��*�������ַ��ʼȡint(*)[4]���Ͷ�Ӧ���ֽ���
	//printf("%d\n", sizeof(&arr+1));   // 4  &arr�õ�һ��int(*)[4]�ټ�1����int(*)[4], ָ��
	//printf("%d\n", sizeof(&arr[0]));  // 4  �õ�int*
//printf("%d\n", sizeof(&arr[0]+1));// 4  ͬ��

//�ַ�����
//char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
//printf("%d\n", sizeof(arr));       // 6  
//printf("%d\n", sizeof(arr+0));     // 4  arr+0�õ�����һ��char*,ָ��
//printf("%d\n", sizeof(*arr));      // 1  *arr�õ�����һ��char
//printf("%d\n", sizeof(arr[1]));    // 1  ͬ��
//printf("%d\n", sizeof(&arr));      // 4  &arr�õ�����һ������ָ��char(*)[6]
//printf("%d\n", sizeof(&arr+1));    // 4   
//printf("%d\n", sizeof(&arr[0]+1)); // 4  &arr[0]�õ�char*,+1����char*
	//strlen     UB��Ӧ�Ŵ������
//printf("%d\n", strlen(arr));       // UB
//printf("%d\n", strlen(arr+0));     // UB
//printf("%d\n", strlen(*arr));      // UB
//printf("%d\n", strlen(arr[1]));    // 
//printf("%d\n", strlen(&arr));      // 
//printf("%d\n", strlen(&arr+1));    // 
//printf("%d\n", strlen(arr[0]+1));  //

//char arr[] = "abcdef";
//printf("%d\n", sizeof(arr));         // 7  sizeof�����ڴ�Ĵ�С������\0  
//printf("%d\n", sizeof(arr+0));       // 4  arr+0 => char*
//printf("%d\n", sizeof(*arr));        // 1  *arr => char
//printf("%d\n", sizeof(arr[1]));      // 1  arr[1] => char
//printf("%d\n", sizeof(&arr));        // 4  &arr => char(*)[7]
//printf("%d\n", sizeof(&arr+1));      // 4  &arr+1 => char(*)[7]
//printf("%d\n", sizeof(&arr[0] + 1)); // 4  &arr[0]+1 => char*

//printf("%d\n", strlen(arr));        // 6 �˴��Ǽ����ַ������ȣ�����\0
//printf("%d\n", strlen(arr+0));      // 6
//printf("%d\n", strlen(*arr));       // UB *arr�õ��ַ��� char��char*��ƥ��
//printf("%d\n", strlen(arr[1]));     // UB
//printf("%d\n", strlen(&arr));       // 6  &arr char(*)[7]��char*��ƥ�䣬������˵��Ҫ����ʧ�ܵ�
									  // &arr���ɺ�arr�õ��ĵ�ֵַ��ͬ,�ⴿ���ɺ�
//printf("%d\n", strlen(&arr+1));     // UB &arr+1�����������飬�����������Ŀռ䣬�Ƿ��ڴ�
//printf("%d\n", strlen(&arr[0]+1));  // 5 &arr[0] => char* char*+1����һ��Ԫ��

//char* p = "abcdef";
//printf("%d\n", sizeof(p));       // 4  p��char*
//printf("%d\n", sizeof(p+1));     // 4  char*
//printf("%d\n", sizeof(*p));      // 1  *p �� char
//printf("%d\n", sizeof(p[0]));    // 1  char
//printf("%d\n", sizeof(&p));      // 4  p char*, &p => char**
//printf("%d\n", sizeof(&p+1));    // 4  char**
//printf("%d\n", sizeof(&p[0]+1)); // 4 &p[0]��char*  ��+1Ҳ��char*

//printf("%d\n", strlen(p));       // 6 �ַ���
//printf("%d\n", strlen(p+1));     // 5 ��p+1��λ�ÿ�ʼ��\0
//printf("%d\n", strlen(*p));      // UB *p char strlenҪ��Ĳ�����char*,���Ͳ�ƥ��
//printf("%d\n", strlen(p[0]));    // UB
//printf("%d\n", strlen(&p));      // UB &p�õ�char**��char*����ͬ���ͣ�ԭ����Ҫ����ʧ��
								   // ��ʱ��char**ǿת�ɵ�char*������һ�������ַ���
//printf("%d\n", strlen(&p+1));    // UB
//printf("%d\n", strlen(&p[0]+1)); // 5 &p[0]�õ�����a�ĵ�ַ��+1�õ�b�ģ���b��ʼ��\0

//��ά����
//int a[3][4] = {
//{ 1, 2, 3, 4},
//{ 5, 6, 7, 8},
//{ 9, 10,11,12}
//};
//printf("%d\n", sizeof(a));          // 48 12��Ԫ�أ�ÿ��Ԫ��4���ֽ�
//printf("%d\n", sizeof(a[0][0]));    // 4  a[0][0] => int 
//printf("%d\n", sizeof(a[0]));       // 16 a[0] => int[4]����
//printf("%d\n", sizeof(a[0]+1));     // 4  a[0] => int[4]����,��+1������ʽת����ָ��int*
//printf("%d\n", sizeof(*(a[0]+1)));  // 4  int
//printf("%d\n", sizeof(a+1));        // 4  
//printf("%d\n", sizeof(*(a+1)));     // 16 
//printf("%d\n", sizeof(&a[0]+1));    // 4  a[0] => int[4],&a[0] => int(*)[4],+1��������ָ��
//printf("%d\n", sizeof(*(&a[0]+1))); // 16 int[4]
//printf("%d\n", sizeof(*a));         // 16 int[4]
//printf("%d\n", sizeof(a[3]));       // 16
//return 0;
//}
//qsort����
//ð������
//#include<stdio.h>
//int int_cmp(const void* p1, const void* p2)
//{
//	return (*(int*)p1 > * (int*)p2);
//}
//void _swap(void* p1, void* p2, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		char temp = *((char*)p1 + i);
//		*((char*)p1 + i) = *((char*)p2 + i);
//		*((char*)p2 + i) = temp;
//	}
//}
//void bubble(void* base, int count, int size, int(*cmp)(void*, void*))
//{
//	int i = 0, j = 0;
//	for (i = 0; i < count - 1; i++)
//	{
//		for (j = 0; j < count - 1; j++)
//		{
//			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
//			{
//				_swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = {1,3,5,7,9,2,4,6,8,0};
//	int i = 0;
//	bubble(arr, sizeof(arr)/sizeof(arr[0]), sizeof(int), int_cmp);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}