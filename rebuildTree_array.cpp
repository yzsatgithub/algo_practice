#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>

/*
 * 题目：输入一棵二叉树的先序遍历和中序遍历，输出它的后序遍历序列
 * 样例输入：
 * DBACEGF ABCDEFG
 * BCAD CBAD
 * 样例输出：
 * ACBFGED
 * CDAB
 * /

using namespace std;

const int MAX=1000;

/*
 * parameters:
 *      n = （子）树大小
 *      s1 = 先序序列起始指针
 *      s2 = 中序序列起始指针
 *      s = 后序序列起始指针
 *
 */
void build(int n, char* s1, char* s2, char* s)
{
    if(n<=0) return; // notice it is <=0
    int p = strchr(s2, s1[0]) - s2;   // 找到根节点在中序遍历中的位置      strchr(str, character)找到character在str中第一次出现的位置
    build(p, s1+1, s2, s);     // 递归构造左子树的后序遍历
    build(n-1-p, s1+p+1, s2+p+1, s+p);  // 递归构造右子树的后序遍历
    s[n-1] = s1[0];   //把根节点添加到最后
}

int main()
{
    char s1[MAX], s2[MAX];
    char ans[MAX];
    while(true)
    {
        cout<<"输入（“前序遍历 空格 中序遍历”）：";
        scanf("%s%s", s1, s2);
        int n=strlen(s1);
        if (n!=strlen(s2))
            return 1;
        build(n, s1, s2, ans);
        ans[n] = '\0';     // 别忘了加上字符串结束标志
        printf("后序遍历：%s\n", ans);
    }
	return 0;
}
