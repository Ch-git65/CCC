#define _CRT_SECURE_NO_WARNINGS 1

//ģ��ʵ��stract
//#include<stdio.h>
//char* my_stract(char* dst, const char* src)
//{
//	if (NULL == dst || NULL == src)
//	{
//		return NULL;
//	}
//	char* temp = dst;
//	while (*temp != '\0')
//	{
//		temp++;
//	}
//	while ((*temp++ = *src++) != '\0');
//	return dst;
//}
//int main()
//{
//	char arr1[] = "world";
//	char arr2[] = "hello";
//	printf("%s\n", my_stract(arr2, arr1));
//	return 0;
//}

//ģ��ʵ��strcpy
//#include<stdio.h>
//void my_strcpy(char arr[], char brr[], int n)
//{
//	for (int i = 0; i <= n; i++)
//	{
//		arr[i] = brr[i];
//	}
//}
//int main()
//{
//	char arr[100];
//	char brr[] = "hello";
//	int n = strlen(brr);
//	my_strcpy(arr, brr, n);
//	printf("%s\n", arr);
//	return 0;
//}

//ģ��ʵ��strlen
//#include<stdio.h>
//#include<assert.h>
//int my_strlen(const char* str)
//{
//	int count = 0;
//	assert(str != NULL);
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	int ret = 0;
//	char arr[10] = "hello";
//	ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}


//memmoveģ��ʵ��
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char str[] = "memmove can be very useful......";
//	memmove(str + 15, str + 20, 11);
//	puts(str); 
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//void* my_memmove(void* dest, const void* src, size_t n)
//{
//	char* d = (char*)dest;
//	const char* s = (char*)src;
//	if (s > d)
//	{
//		while (n--)
//		{
//			*d++ = *s++;
//		}
//	}
//	else if (s < d)
//	{
//		d = d + n - 1;
//		s = s + n - 1;
//		while (n--)
//		{
//			*d-- = *s--;
//		}
//	}
//	return dest;
//}
//int main()
//{
//	char str[] = "memmove can be very useful......";
//	my_memmove(str + 20, str + 15, 11);
//	puts(str); 
//	return 0;
//}

//memcpyģ��ʵ��
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//void* my_memcpy(void* dest, void* src, size_t num)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* d = (char*)dest;
//	char* s = (char*)src;
//	while (num)
//	{
//		*d++ = *s++;
//		--num;
//	}
//	return dest;
//}
//
//struct {
//	char name[40];
//	int age;
//}person,person_cpy;
//
//int main()
//{
//	char str[] = "my name is sock";
//	my_memcpy(person.name, str, strlen(str) + 1);
//	person.age = 20;
//	my_memcpy(&person_cpy, &person, sizeof(person));
//	printf("%s     %d\n", person_cpy.name, person_cpy.age);
//	return 0;
//}


//#include <stdio.h>
//#include <string.h> 
//int main () 
//{ 
//	char str[] ="This is a simple string"; 
//	char * pch;
//	pch = strstr (str,"simple");
//	//strncpy (pch,"sample",6);
//	puts (pch); 
//	return 0; 
//}

//strstrģ��ʵ��
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//char* my_strstr(const char* dest, const char* src)
//{
//	char* start = (char*)dest;//��������Ҫǿ������ת����char*
//	char* substart = (char*)src;
//	char* cp = (char*)dest;//cp�������������׵�ַ��
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*cp)
//	{
//		start = cp;
//		while (*start != '\0' && *substart != '\0' && *start == *substart)
//		{
//			start++;
//			substart++;
//		}
//		if (*substart == '\0')
//		{
//			return cp;
//		}
//		substart = (char*)src;
//		cp++;//cp++���Եõ�ԭ��ʼλ�õ���һ��λ��
//	}
//	return NULL;
//}
//int main()
//{
//	char a[20] = "abbbcdef";
//	char b[10] = "bbcde";
//	printf("%s\n", my_strstr(a, b));
//	system("pause");
//	return 0;
//}

//strcmpģ��ʵ��
#include<stdio.h>
#include<string.h>
#include<assert.h>
int my_strcmp(const char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	int ret = 0;
	while (!(ret = *(unsigned char*)dest - *(unsigned char*)src) && *src)
	{
		++dest;
		++src;
	}
	if (ret < 0) {
		ret = -1;
	}
	else if (ret > 0) {
		ret = 1;
	}
	return  ret;
}
int main() {
	char str1[1024] = { 1,2,3,4,5 };
	char str2[1024] = { 1,2,3,4 };
	int ret = my_strcmp(str1, str2);
	printf("%d\n", ret);
	return 0;
}