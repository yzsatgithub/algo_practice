#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;
/*
 * 题目：
 *
 * n间屋子，每间屋子都有人，先要重新分配某一个房间的人。具体办法是，把第i间屋子的a个人，放一个到i+1屋子，再放一个到i+2屋子...直到这a个人都分配完
 * 最后一间屋子的下一间是第一间。
 *
 * 输入第一行两个数n, x。n代表房间数，x代表最后一个放人的屋子编号；第二行为n个空格分隔的整数，代表最后放完时各屋子人数情况
 *
 * 输出为，初始状态下各屋子人数情况。
 *
 * 思路：
 * 倒着思考，找规律。
 *
 * 测试数据：
 * input: 
 * 3 1
 * 6 5 1
 *
 * output:
 * 4 4 4
 *
 *
 */
int main()
{
	int n, x;
	cin>>n>>x;
	long long int a[n];
	for(int i=0;i<n;++i)
		cin>>a[i];
	
	int newvalue=0;
	int newpos=0;
	int i=(x>=1)?(x-1):(n-1);
	while(a[i]>=0)
	{
		--a[i];
		if(a[i]==0) newpos=i;
		else if(a[i]<0) break;
		++newvalue;
		i = (i==0)?(n-1):(i-1);
	}
	a[newpos]=newvalue;
//	cout<<"newpos=="<<newpos<<endl;
	for(int i=0; i<n;++i)
	{
		cout<<a[i];
		if(i==n-1)
			cout<<endl;
		else
			cout<<" ";
	}
	return 0;
}
