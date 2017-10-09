#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

// the index starts from 1.
const int MAXSIZE=10000;  // 写成1000000000会段错误，写到不可写的内存区域

void Test(char* testName, int* pData, int nlength);
void Test1();
void Test2();
void Test3();
void MergeSort(int* a, int length);
void mSort(int* from, int* to, int begin, int end);
void merge(int* from , int* to, int begin , int middle, int end);
void MergeSort2();


// ======================测试代码=======================
void Test(char* testName, int* pData, int nlength)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);
    for(int i=1;i<=nlength;++i)
        printf("%d\t", pData[i]);
    cout << endl;
    MergeSort(pData, nlength);
    for(int i=1;i<=nlength;++i)
        printf("%d\t", pData[i]);
	cout << endl;
}

//The index starts from 1. puts -1 on the 0st place.
void Test1()
{
    int data[10] = {-1, 2, 8, 1, 5, 9, 3, 7, 4, 6};
    Test("Test1 random", data, sizeof(data)/sizeof(int)-1);
}

// almost sorted
void Test2()
{
    int data[15] = {-1, 1, 2, 3, 5, 4, 6, 7, 8, 9, 10, 12, 13, 14};
    Test("Test2 almost sorted", data, sizeof(data)/sizeof(int)-1);
}

// inverted
void Test3()
{
    int data[13] = {-1, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    Test("Test3 inverted array", data, sizeof(data)/sizeof(int)-1);
}

// ======================算法===========================

// Recursive Implementation.  The index starts from 1.
void MergeSort(int* a, int length)
{
     mSort(a, a, 1, length);
}

// 把from[begin .. end]归并排序为to[begin .. end]
void mSort(int* from, int* to, int begin, int end)
{
   int temp[MAXSIZE]; 
   int middle;     // pointer to the middle
   if(begin==end)  
       to[begin]=from[begin];    
   else
   {
        middle= (begin+end)/2;            //将from[begin .. end]平分为from[begin..middle]和to[middle+1..to]
        mSort(from, temp, begin, middle);   // 递归地把from[begin..middle]归并为temp[begin..middle]
        mSort(from, temp, middle+1, end);   // 递归地把from[middle+1..end]归并为temp[middle+1..end]
        merge(temp, to, begin, middle, end); // 将temp[begin..middle]和temp[middle+1..end]合并为to[begin..end]
   }
}



void merge(int* from, int* to, int begin, int middle, int end)
{
    int p1=begin, p2=middle+1;
    int pOut=begin;
    for(; p1<=middle && p2<=end; ++pOut)
    {
        if(from[p1]<=from[p2])
            to[pOut]=from[p1++]; 
        else
            to[pOut]=from[p2++];
    }
    if(p1<=middle)
    {
//        for(int i = 0; i <= middle-p1; ++i)
//            to[pOut+i] = from[p1 + i];
        for(; p1<=middle;)
            to[pOut++] = from[p1++];
    }
    if(p2<=end)
    {
//        for(int i = 0; i <= end-p2; ++i)
//            to[pOut+i] = from[p2 + i];
        for (;p2<=end; )
            to[pOut++] = from[p2++];
    }
}

void MergeSort2()
{
// Non-recursive Implementation.  The index starts from 0.
    
}

int main()
{
    Test1();
    Test2();
    Test3();
	return 0;
}
