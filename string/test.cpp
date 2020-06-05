#include<string>
#include<iostream>
using namespace std;

void test()
{
	string s;
	s.push_back('a'); //a
	s.append(2, 'b'); //abb
	s.append("cde");  //abbcde
	string s2;
	s2.append(s);
	string s3;
	s3.append(s, 3, 2); //cd
	char strArr[] = "1234";
	s3.append(strArr, strArr + 2); //cd12
	s3.append(s2.begin(), s2.end()); //cd12abbcde
	string s4;
	//operator+=使用最多
	s4 += '1'; //1
	s4 += "234"; //1234
	s4 += s; //1234abbcde

}