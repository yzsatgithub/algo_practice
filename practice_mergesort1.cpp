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
const int MAXSIZE=1000000;

void Test()
{

}

void Test1()
{
}

void Test2()
{
}

void Test3()
{
}

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
        mSort(to, temp, begin, middle);   // 递归地把from[begin..middle]归并为temp[begin..middle]
        mSort(to, temp, middle+1, end);   // 递归地把from[middle+1..end]归并为temp[middle+1..end]
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
            to[pOut]=from[p1]; p1++;
        else
            to[pOut]=from[p2]; p2++;
    }
    if(p1<=middle)
    {
        //for(int i = 0; i <= middle-p1; ++i)
        //    to[pOut+i] = from[p1 + i];
        for(; p1<=middel; ++p1)
            to[pOut++] = from[p1++];
    }
    if(p2<=end)
    {
        for(int i = 0; i <= end-p2; ++i)
            to[pOut+i] = from[p2 + i]; 
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
