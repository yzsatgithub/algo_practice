#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
/*
 * 题目：
 * 给定一棵二叉树，假设每个节点都用唯一的字符来表示，具体结构见下方结构体。
 * 假设已经有了前序遍历和中序遍历的结果，希望通过一个算法重建这棵树
 * 给定函数的定义如下：
 * void Rebuild(char* pPreOrder, char* pInOrder, int nTreeLen, NODE** pRoot)
 * 
 * 参数:
 *      pPreOrder: 以null为结尾的前序遍历结果的字符串数组
 *      pInOrder: 以null为结尾的中序遍历结果的字符串数组
 *      nTreeLen: 树的长度
 *      pRoot: 返回node**类型，根据谦虚和中序遍历结果重建新构建树的根节点
 *
 *  例如
 *  前序遍历结果：a b d c e f
 *  中序遍历结果：d b a e c f 
 *  重建树为：
 *          a
 *      b       c      
 *    d        e f
*/

using namespace std;

#define TREELEN 6

struct NODE{
    NODE* pLeft;  // 左节点
    NODE* pRight; // 右节点
    char chValue; // 节点值
};


void Rebuild(char* pPreOrder,   // 前序遍历结果（字符数组）
            char* pInOrder,    // 中序遍历结果（字符数组）
            int nTreeLen,   // 树长度
            NODE** pRoot)   // 根节点
{
    // 检查边界条件
    if(pPreOrder==NULL || pInOrder==NULL)
        return;
    
    // 获得前序遍历的第一个节点
    NODE* pTemp = new NODE;
    pTemp->chValue = *pPreOrder;
    pTemp->pLeft = NULL;
    pTemp->pRight = NULL;

    //如果节点为空，把当前节点复制到根节点
    if(*pRoot==NULL)
        *pRoot = pTemp;

    // 如果当前树长度为1，那么已经是最后一个节点
    if(nTreeLen==1)
        return;

    //寻找子树长度
    char* pOrgInOrder=pInOrder;
    char* pLeftEnd=pInOrder;
    int nTempLen=0;

    // 找到左子树的结尾
    while(*pPreOrder != *pLeftEnd)
    {
        if(pPreOrder==NULL || pLeftEnd==NULL) //检查是否到了叶节点？  这里不用再检查了吧？
            return;

        nTempLen++;

        //记录临时长度，避免溢出
        if(nTempLen>nTreeLen)
            break;
        pLeftEnd++;
    }

    //寻找左子树长度
    int nLeftLen=0;
    nLeftLen= (int)(pLeftEnd - pOrgInOrder);   //（int）

    //寻找右子树长度
    int nRightLen=0;
    nRightLen= nTreeLen - nLeftLen - 1;   // 1是代表根节点

    // 重建左子树
    if(nLeftLen>0)
    {
        Rebuild(pPreOrder+1, pInOrder, nLeftLen, &( (*pRoot)->pLeft ) );
    }

    // 重建右子树
    if(nRightLen>0)
    {
        Rebuild(pPreOrder+nLeftLen+1, pInOrder+nLeftLen+1, nRightLen, &( (*pRoot)->pRight ) );
    }

}


void PostOrderPrintTree(const NODE* pRoot)
{
    if(pRoot != NULL)
    {
        if(pRoot->pLeft != NULL)
            PostOrderPrintTree(pRoot->pLeft);

        if(pRoot->pRight != NULL)
            PostOrderPrintTree(pRoot->pRight);
            
        cout << pRoot->chValue;
    }
    cout<<endl;
}

int main()
{
    char szPreOrder[TREELEN]={'a','b','c','d','e','f'};
    char szInOrder[TREELEN]={'d','b','a','e','c','f'};

    NODE* pRoot = NULL;
    Rebuild(szPreOrder, szInOrder, TREELEN, &pRoot);  // 建树
    PostOrderPrintTree(pRoot);  // 后序遍历
	return 0;
}
