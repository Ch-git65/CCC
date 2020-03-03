//#include<stdio.h>
//int main()
//{
	//一堆数组
	//int arr[] = {1,2,3,4};
	//printf("%d\n", sizeof(arr));      // 16
	//printf("%d\n", sizeof(arr+0));    // 4  int*    arr已经隐式转换为指针
	//printf("%d\n", sizeof(*arr));     // 4  已经隐式转换位int* 在解引用，得到int
	//printf("%d\n", sizeof(arr+1));    // 4   arr已经隐式转换成 int*
	//printf("%d\n", sizeof(arr[1]));   // 4  int
	//printf("%d\n", sizeof(&arr));     // 4  &arr是一个int(*)[4],指针
	//printf("%d\n", sizeof(*&arr));    // 16 &arr是数组指针，再*从这个地址开始取int(*)[4]类型对应的字节数
	//printf("%d\n", sizeof(&arr+1));   // 4  &arr得到一个int(*)[4]再加1还是int(*)[4], 指针
	//printf("%d\n", sizeof(&arr[0]));  // 4  得到int*
//printf("%d\n", sizeof(&arr[0]+1));// 4  同上

//字符数组
//char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
//printf("%d\n", sizeof(arr));       // 6  
//printf("%d\n", sizeof(arr+0));     // 4  arr+0得到的是一个char*,指针
//printf("%d\n", sizeof(*arr));      // 1  *arr得到的是一个char
//printf("%d\n", sizeof(arr[1]));    // 1  同上
//printf("%d\n", sizeof(&arr));      // 4  &arr得到的是一个数组指针char(*)[6]
//printf("%d\n", sizeof(&arr+1));    // 4   
//printf("%d\n", sizeof(&arr[0]+1)); // 4  &arr[0]得到char*,+1还是char*
	//strlen     UB对应着错误代码
//printf("%d\n", strlen(arr));       // UB
//printf("%d\n", strlen(arr+0));     // UB
//printf("%d\n", strlen(*arr));      // UB
//printf("%d\n", strlen(arr[1]));    // 
//printf("%d\n", strlen(&arr));      // 
//printf("%d\n", strlen(&arr+1));    // 
//printf("%d\n", strlen(arr[0]+1));  //

//char arr[] = "abcdef";
//printf("%d\n", sizeof(arr));         // 7  sizeof是求内存的大小，包含\0  
//printf("%d\n", sizeof(arr+0));       // 4  arr+0 => char*
//printf("%d\n", sizeof(*arr));        // 1  *arr => char
//printf("%d\n", sizeof(arr[1]));      // 1  arr[1] => char
//printf("%d\n", sizeof(&arr));        // 4  &arr => char(*)[7]
//printf("%d\n", sizeof(&arr+1));      // 4  &arr+1 => char(*)[7]
//printf("%d\n", sizeof(&arr[0] + 1)); // 4  &arr[0]+1 => char*

//printf("%d\n", strlen(arr));        // 6 此处是计算字符串长度，不算\0
//printf("%d\n", strlen(arr+0));      // 6
//printf("%d\n", strlen(*arr));       // UB *arr得到字符， char和char*不匹配
//printf("%d\n", strlen(arr[1]));     // UB
//printf("%d\n", strlen(&arr));       // 6  &arr char(*)[7]和char*不匹配，按理来说是要编译失败的
									  // &arr碰巧和arr得到的地址值相同,这纯属巧合
//printf("%d\n", strlen(&arr+1));     // UB &arr+1跳过整个数组，访问数组后面的空间，非法内存
//printf("%d\n", strlen(&arr[0]+1));  // 5 &arr[0] => char* char*+1跳过一个元素

//char* p = "abcdef";
//printf("%d\n", sizeof(p));       // 4  p是char*
//printf("%d\n", sizeof(p+1));     // 4  char*
//printf("%d\n", sizeof(*p));      // 1  *p 是 char
//printf("%d\n", sizeof(p[0]));    // 1  char
//printf("%d\n", sizeof(&p));      // 4  p char*, &p => char**
//printf("%d\n", sizeof(&p+1));    // 4  char**
//printf("%d\n", sizeof(&p[0]+1)); // 4 &p[0]是char*  再+1也是char*

//printf("%d\n", strlen(p));       // 6 字符串
//printf("%d\n", strlen(p+1));     // 5 从p+1的位置开始找\0
//printf("%d\n", strlen(*p));      // UB *p char strlen要求的参数是char*,类型不匹配
//printf("%d\n", strlen(p[0]));    // UB
//printf("%d\n", strlen(&p));      // UB &p得到char**和char*不是同类型，原则上要编译失败
								   // 此时把char**强转成的char*并不是一个真正字符串
//printf("%d\n", strlen(&p+1));    // UB
//printf("%d\n", strlen(&p[0]+1)); // 5 &p[0]得到的是a的地址，+1得到b的，从b开始找\0

//二维数组
//int a[3][4] = {
//{ 1, 2, 3, 4},
//{ 5, 6, 7, 8},
//{ 9, 10,11,12}
//};
//printf("%d\n", sizeof(a));          // 48 12个元素，每个元素4个字节
//printf("%d\n", sizeof(a[0][0]));    // 4  a[0][0] => int 
//printf("%d\n", sizeof(a[0]));       // 16 a[0] => int[4]类型
//printf("%d\n", sizeof(a[0]+1));     // 4  a[0] => int[4]类型,再+1，就隐式转换成指针int*
//printf("%d\n", sizeof(*(a[0]+1)));  // 4  int
//printf("%d\n", sizeof(a+1));        // 4  
//printf("%d\n", sizeof(*(a+1)));     // 16 
//printf("%d\n", sizeof(&a[0]+1));    // 4  a[0] => int[4],&a[0] => int(*)[4],+1还是数组指针
//printf("%d\n", sizeof(*(&a[0]+1))); // 16 int[4]
//printf("%d\n", sizeof(*a));         // 16 int[4]
//printf("%d\n", sizeof(a[3]));       // 16
//return 0;
//}
//qsort函数
//冒泡排序
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