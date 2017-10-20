#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>

/* 题目：字符串移位包含问题      （《编程之美》3.1）
 *
 * 给定两个字符串s1和s2，要求判定s2是否能被s1做循环移位（rotate）得到的字符串包含。例如，给定s1=AABCD和s2=CDAA，返回true；
 * 给定s1=ABCD和s2=ACBD，返回false
 *
 * 思路：
 * 方法一，暴力解  O(n^2)
 * 方法二，把字符串拼接到后边，用空间换时间，   O(n)
 */



using namespace std;
//=====方法1====暴力解===O(n^2)
bool rotate_contain(char src[], char des[])
{
    int len = strlen(src);
    for (int i =0; i<len; ++i)
    {
    	char temp = src[len-1];
    	for(int j=len-1;j>0;--j)
    	{
    		src[j] = src[j-1];
    	}
    	src[0] = temp;
    	if(strstr(src, des) != NULL )
    		return true;
    }
	return false;
}


//=====方法2====拼接字符串，空间换时间====O(n)
bool rotate_contain2(char src[], char des[])
{
	int len = strlen(src);
	char temp[len*2];
	for(int i=0; i<len*2; ++i)
	{
		temp[i] = src[i%len];
	}
	if(strstr(temp, des) != NULL)
		return true;
    return false;
}

int main()
{
	char src[] = "AABBCD";
	char des[] = "CDAA";
	
	cout << rotate_contain(src, des) << endl;  
	cout << rotate_contain2(src, des) << endl;
	return 0;
}
