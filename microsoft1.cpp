#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

/*
 * 题目：在第一个字符串（text）中找出第二个字符串（name）出现的个数。（可能连续出现。）
 * 
 * e.g.
 *
 * input:
 * TimsdjfkjasdklfjlaTim
 * Tim
 *
 * output:
 * 2
 */


int getNumber(const char* text, const char* name)
{
    if(!text)
        return 0;
    const char* p;
    long long result = 0;
    p = text;
    while(p)
    {
        p = strstr(p, name);
        if(p)
        {
            p++;
            result++;
        }
    }
    return result;
}


int main()
{
    string s1;
    string s2;
    while(1){
        cin >> s1;
        cin >> s2;
        cout << getNumber(s1.c_str(), s2.c_str())<<endl;
    }
	return 0;
}
