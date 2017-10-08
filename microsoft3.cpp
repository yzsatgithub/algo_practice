#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

int getID(int N, int numActions, int querypos, int** actions)
{
    vector<int> soldiers;
    for(int i = 0; i < N; ++i)
        soldiers.push_back(i+1);
    cout << "SOLDIERS BEFORE ACTIONS"<<endl; // debug
    for(int i=0;i<soldiers.size();++i)
        cout << soldiers[i] <<"\t";
    cout<<endl;
    int m = 0; 
    int n = 0;
    for(int i = 0; i < numActions; ++i)
    {
        m = actions[i][0];
        n = actions[i][1];
        while(m<n)
        {
            swap(soldiers[m-1], soldiers[n-1]);
            m++;
            n--;
        }
    }
    cout << "SOLDIERS AFTER ACTIONS"<<endl; // debug
    for(int i=0;i<soldiers.size();++i)
        cout << soldiers[i] <<"\t";
    cout<<endl;
    return soldiers[querypos-1];
}

int main()
{
    cout << "number of soldiers; number of actions; the position to query after the actions: ";
    int n;// number of soldiers
    int numactions;// number of actions
    int query;// the position of which the ID is needed after the actions
    cin >> n >> numactions >> query;
    cout << "the actions: ";
    int** acts = new int*[numactions];// actually actions
    for (int i = 0; i < numactions;++i)
        acts[i] = new int[2];
    for(int i=0;i<numactions;++i)
    {
        for (int j=0;j<2;++j)
            cin >> acts[i][j];
    }
    
    cout << getID(n, numactions, query, acts) <<endl;
	return 0;
}
