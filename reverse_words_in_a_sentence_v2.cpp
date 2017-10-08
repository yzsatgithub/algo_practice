#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    string str;
    getline(cin, str); 
    cout << str <<endl;
    stack<string> st_str;
    istringstream ss(str);
    while(ss>>str)
    {
        st_str.push(str);
    }

    stack<string> st_str_cp(st_str);
    int num = st_str_cp.size();
    for (int i = 0; i < num; ++i)
    {
        cout << st_str_cp.top() << endl;
        st_str_cp.pop();
    }


    string result;
    while(!st_str.empty())
    {
        result += st_str.top();
        result += ' ';
        st_str.pop();
    }
    result = result.substr(0, result.length()-2);
    cout << result <<endl;

    return 0;
}
