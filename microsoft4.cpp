#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>

using namespace std;

/*
 *题目：我要查一下题目内容

 大致是，取得一个集合的所有子集，子集中的最大值和最小值做位与运算X_i，返回所有子集里最大的这个位与运算结果。
 *
 *
 */ 

vector<vector<int> > getSubsets(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int> > subs(1, vector<int>());
    for (int i=0;i<nums.size();++i)
    {
        int n = subs.size();  // without this line -- dead loop
        for(int j=0;j<n;++j)
        {
            vector<int> tmp = subs[j];
            tmp.push_back(nums[i]);
            subs.push_back(tmp);
        }
    }
    return subs;
}


int getKAND(int N, int K, int* values)
{
    /*set<int> tmp;*/
    //for(int i=0;i<N;++i)
    //{
        //tmp.insert(values[i]);
    //}
    //set<int>::iterator ibegin = tmp.begin();
    //vector<int> deduped; // 去重之后的candy值vector
    //while(ibegin != tmp.end())
    //{
        //deduped.push_back(*ibegin);
        //ibegin++;
    /*}*/

    vector<int> deduped;
    int v;
    for(int i=0;i<N;++i)
    {
        v = values[i];
        if(find(deduped.begin(), deduped.end(), v) == deduped.end())
            deduped.push_back(v);
    }
    vector<vector<int> > subsets = getSubsets(deduped);
    vector<int> cands;
    for(int i=0;i<subsets.size();++i)
    {
        if (subsets[i].size()==K)
        {
            long long a=subsets[i][0];
            for(int j=1;j<K;++j)
                a = a & subsets[i][j];
            cands.push_back(a);
        }
    }
    int max=-999;
    for(int i=0;i<cands.size();++i)
    {
        if (cands[i]>max)
            max = cands[i];
    }

    return max;
}


int main()
{
    int numCandies;
    int sizeSubsets;
    //int* candyValue = new int[numCandies];

    cout<<"number of candies = ";
    cin >> numCandies;
    cout<<"the size of the subsets = ";
    cin >> sizeSubsets;

    int candyValue[numCandies];// 最好在主函数外分配一个很大的数组，否则在主函数内容易爆栈。
    cout << "candy values are:";
    for(int i=0;i<numCandies;++i)
        cin >> candyValue[i];

    cout << getKAND(numCandies, sizeSubsets, candyValue) << endl;
    //delete[] candyValue;
	return 0;
}
