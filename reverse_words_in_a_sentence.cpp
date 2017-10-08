#include <string>
#include <iostream>

using namespace std;

void reverse(string& str, int low, int high)
{
    while(low < high)
    {
        char temp = str[low];
        str[low] = str[high];
        str[high] = temp;
        low++;
        high--;
    }
}

int main(){
    // 以空格或者换行符为分隔
    string str1;
    //cin >> str1 >> str2;
    //cout << "str1 = " << str1 <<"\t"<< "str2 = " << str2<<endl;

    // 以换行符为分隔，也就是说读一行
    getline(cin, str1);
    cout << "str1 = " << str1 <<endl;

    int low = 0;
    int high = str1.length()-1;
    reverse(str1, low, high);
    low = high = 0;
    while(low < str1.length())
    {
        if(str1[low] == ' ')//处理连续出现的空格
        {
            low++, high++;
        }
        else if(str1[high]==' ' || high == str1.length())
        {
            reverse(str1, low, high-1);
            low = ++high;
        }
        else
        {
            high++;
        }

    }

    cout << "reversed str1 = " << str1 <<endl;

    for (int i = 0; i < str1.length(); ++i)
        cout << str1[i] << endl;

    return 0;
}
