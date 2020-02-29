//#include<stdio.h>
//int main()
//{
//    int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//    int* ptr1 = (int*)(&aa + 1);
//    int* ptr2 = (int*)(*(aa + 1));
//    printf("%d,%d", *(ptr1-1), *(ptr2 - 1));
//    //printf("%d ",(int*)(&aa+1));
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int* p = NULL;
//    int arr[10] = { 0 };
//    //p = &arr[0];
//    int(*ptr)[10] = &arr;
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int a[5] = { 5, 4, 3, 2, 1 };
//    int* ptr = (int*)(&a + 1);
//    printf("%d,%d", *(a + 1), *(ptr - 1));
//    return 0;
//}
#include<stdio.h>
int cmp(const void* x, const void* y) { //按字节来比较两个元素
    return (*(char*)x) - (*(char*)y);
}
void Swap(void* p1, void* p2, int size) { //将元素按字节交换
    for (int i = 0; i < size; ++i) {
        char tmp = *((char*)p1 + i);
        *((char*)p1 + i) = *((char*)p2 + i);
        *((char*)p2 + i) = tmp;
    }
}
//模仿qsort写一个冒泡排序
void bubble_sort(void* base, int num, int size, int(*cmp)(const void*, const void*)) {
    for (int i = 0; i < num - 1; ++i) {
        for (int j = 0; j < num - i - 1; ++j) {
            int ret = cmp((char*)base + j * size, (char*)base + (j + 1) * size);
            // 按升序来进行排列
            if (ret > 0) {
                Swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
            }
        }
    }
}
int main()
{
    char arr2[] = {'f','a','k','e','r'};
    bubble_sort(arr2, sizeof(arr2) / sizeof(arr2[0]), sizeof(arr2[0]), cmp);
    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
    {
        printf("%c ", arr2[i]);
    }
    printf("\n");
    return 0;
}
//int main() {
//    int i = 0;
//    int arr1[] = { 9, 5, 2, 7 };
//    bubble_sort(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr1[0]), cmp);
//    for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
//        printf("%d ", arr1[i]);
//    }
//    printf("\n");
//    return 0;
//}
