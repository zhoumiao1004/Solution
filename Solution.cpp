#include "Solution.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <assert.h>
#include <algorithm>
using namespace std;

Solution::Solution()
{
}

void Solution:: removeDuplicates(char *str)
{
    int i=0;
    int j=0;
    int tail=1;

    if(str == NULL)
        return;
    int len = strlen(str);
    if (len < 2)
        return;

    for (i = 1; i<len; ++i)
    {
        /*这一层扫描已发现的不重复字符*/
        for(j = 0; j<tail; ++j)
        {
            if(str[i] == str[j])//str[tail]中存储已经检查过的不重复的字符
                break;
        }
        /*没有找到，则加入到已发现字符集中*/
        if(j == tail)
        {
            str[tail++] = str[i];
        }
    }
    str[tail]='\0';
}

char *Solution::strFind(char *str, char *subStr)
{
    char *p = str;
    char *q = subStr;
    int m = strlen(str);
    int n = strlen(subStr);
    assert(m>=n);

    for (int i =0; i <= m-n; i++)
    {
//        for ()
//        while (*p++ == *q++)
//        {
//            break;
//        }
        if (0 == strncmp(p+i, q, strlen(q)))
        {
            return p+i;
        }
    }
    return NULL;
}

void Solution::replaceSpace(char *str)
{
    if (str == NULL)
        return;

    int numOfBlank = 0;
    int i = 0;
    int j = 0;

    int originLength = strlen(str);
    while(str[i] != '\0')
    {
        if(str[i] == ' ')
            numOfBlank++;
        i++;
    }
    int newLength = originLength + 2*numOfBlank;

    i = newLength;
    j = originLength;

    while(i>=0)
    {
        if(str[j] == ' ')
        {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
            j--;
        }
        else
        {
           str[i--] = str[j--];
        }
    }
}

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
vector<int> Solution::printListFromTailToHead(ListNode* head)
{
    vector<int> vec;
    stack<int> s;

    ListNode *pNode = head;
    while (pNode != NULL)
    {
        //vec.push_back(pNode->val);
        s.push(pNode->val);
        pNode = pNode->next;
    }
    while(!s.empty())
    {
        cout << s.top() << " ";
        vec.push_back(s.top());
        s.pop();
    }
    cout << endl;
    return vec;
}

ListNode *Solution::CreateList(int len)
{
    int val = 0;
    int i = 0;
//    srand(10);
    ListNode *pHead = NULL;

//    ListNode *pTail = NULL;

    for (i = 0; i<len; i++)
    {
        val = rand() % 100;
//        cout << "val = " << val << endl;
        ListNode *pNew = new ListNode(val);
        if (i == 0)
        {
            pHead = pNew;
//            pTail = pNew;
        }
        else
        {
            /* 从头开始遍历链表，找到尾节点 */
            ListNode *pNode = pHead;
            while(pNode->next != NULL)
            {
                pNode = pNode->next;
            }
            /* 将新节点插到末尾 */
            pNode->next = pNew;
        }
    }
    return pHead;
}

void Solution::PrintList(ListNode *head)
{
    ListNode *pNode = head;

    while(pNode != NULL)
    {
        if(pNode->next == NULL)
        {
            cout << pNode->val << endl;
        }
        else
        {
            cout << pNode->val << "-->";
        }
        pNode = pNode->next;
    }
}

TreeNode *Solution::DFS(vector<int> pre, vector<int> vin, int begin1, int end1, int begin2, int end2)
{
    int j = 0;

    if (begin1 > end1 || begin2 > end2)
        return NULL;

    int rootVal = pre[begin1];
//    cout << rootVal << endl;
    TreeNode *pRoot = new TreeNode(rootVal);

    /* 找到根在中序中的位置 */
    j = begin2;
    while(j <= end2 && vin[j] != rootVal)
    {
        j++;
    }
//    cout << "j = " << j << endl;

    /* 计算左子树长度 */
    int leftLen = j - begin2;

    /* 对左子树DFS */
    pRoot->left = DFS(pre, vin, begin1+1, begin1+leftLen, begin2, j-1);

    /* 对右子树DFS */
    pRoot->right = DFS(pre, vin, begin1+leftLen+1, end1, j+1, end2);

    return pRoot;
}

TreeNode *Solution::reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    if (pre.empty() || vin.empty())
        return NULL;

    return DFS(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
}

void Solution::PrintBinaryTreePostOrder(TreeNode *root)
{
    /* 打印左子树 */
    if (root->left != NULL)
        PrintBinaryTreePostOrder(root->left);

    /* 打印右子树 */
    if (root->right != NULL)
        PrintBinaryTreePostOrder(root->right);

    /* 打印子树根节点 */
    if (root != NULL)
        cout << root->val << endl;
}

void Solution::push(int node)
{
    /* 向stack1中入栈 */
    stack1.push(node);
    cout << "push node val=" << node << endl;
}

int Solution::pop()
{
    int val = 0;

    /* 若2中不为空，则从2中出栈 */
    if (stack2.empty())
    {
        /* 若2中已空，先将stack1中的元素入栈，再pop栈顶元素 */
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    val = stack2.top();
    cout << "pop node val=" << val << endl;
    stack2.pop();
    return val;
}

int Solution::minNumberInRotateArray(vector<int> rotateArray)
{
    for (vector<int>::iterator it = rotateArray.begin(); it < rotateArray.end(); it++)
    {
        if (*it > *(it+1))
        {
            return *(it+1);
        }
    }
    return 0;
}

int Solution::Fibonacci(int n)
{
    int result[2] = {0, 1};
    int res;

    if (n < 2)
        return result[n];

    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;

    for (int i = 2; i <= n; i++)
    {
        res = fibNMinusOne + fibNMinusTwo;
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = res;
    }
    return res;
//    long long res;
//    /* 采用循环，如果最后只剩一步，则只有一种方法
//        若最后还剩两步，则有两种方法*/
//    if (number <= 0)
//    {
//        return 0;
//    }

//    if (number == 1)
//    {
//        return 1;
//    } else if(number == 2)
//    {
//        return 2;
//    }
//    long long fibNMinusOne = 2;
//    long long fibNMinusTwo = 1;

//    for (int i = 3; i <= number; i++)
//    {
//        res = fibNMinusOne + fibNMinusTwo;
//        fibNMinusTwo = fibNMinusOne;
//        fibNMinusOne = res;
//    }
//    return res;
}

int Solution::jumpFloor(int number)
{
    /* 采用递归，如果最后只剩一步，则只有一种方法
        若最后还剩两步，则有两种方法*/
    if (number <= 0)
    {
        return 0;
    }

    if (number == 1)
    {
        return 1;
    } else if(number == 2)
    {
        return 2;
    }
    /* 如果第一次跳了1步，后面需要跳jumpFloor(number-1)
        如果第一次跳了2步，后面需要跳jumpFloor(number-2)*/
    return jumpFloor(number-1) + jumpFloor(number-2);
}

int Solution::jumpFloorII(int number)
{
    /* 1次可以跳1、2...n格 */
    /* 采用循环，如果最后只剩一步，则只有一种方法
        若最后还剩两步，则有两种方法*/
    if (number < 0)
    {
        return 0;
    }

    if (number == 1 || number == 0)
    {
        return 1;
    } else if(number == 2)
    {
        return 2;
    }

    return 2*jumpFloorII(number-1);
}

int Solution::NumberOf1(int n)
{
    int count = 1;

    if (n == 0)
        return 0;

    while(n)
    {
        count++;
        n = n&(n-1);
    }
    return count;
}

double Solution::Power(double base, int exponent)
{
    double res = 1.0;

    int flag = exponent > 0 ? 1 : -1;
    exponent = flag * exponent;//转成正数

    for(int i = 0; i<exponent; i++)
    {
        res *= base;
    }

    if (flag < 0)
    {
        res = 1.0/res;
    }

    return res;
}

void Solution::PrintArray(vector<int> &array)
{
    for(vector<int>::iterator it=array.begin(); it<array.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void Solution::reOrderArray(vector<int> &array)
{
    queue<int> que1, que2;
    vector<int>::iterator it;

    for(it = array.begin(); it < array.end(); it++)
    {
        /* i从头遍历 */
        if((*it)%2)
            que1.push(*it);
        else
            que2.push(*it);
    }

    it = array.begin();
    while(!que1.empty())
    {
        *it++ = que1.front();
        que1.pop();
    }
    while(!que2.empty())
    {
        *it++ = que2.front();
        que2.pop();
    }
}

int Solution::GetListLength(ListNode *head)
{
    int len = 0;
    ListNode *pNode = head;
    while(pNode)
    {
        len++;
        pNode = pNode->next;
    }
    return len;
}

ListNode *Solution::FindKthToTail(ListNode *pListHead, unsigned int k)
{
    ListNode *pNode = pListHead;
    ListNode *pLeft = pListHead;
    ListNode *pRight = pListHead;

    unsigned int len = 0;
    while(pNode)
    {
        len++;
        pNode = pNode->next;
    }

    if(len < k)
    {
        return NULL;
    }

    while(k)
    {
        pRight = pRight->next;
        k--;
    }

    while(pRight)
    {
        pLeft = pLeft->next;
        pRight = pRight->next;
    }
    return pLeft;
}

ListNode *Solution::ReverseList(ListNode *pHead)
{
    ListNode *pNode = NULL;
    ListNode *pNewHead = NULL;
    ListNode *pNext = NULL;
    ListNode *pPre = NULL;

    if (pHead == NULL || pHead->next == NULL)
        return pHead;

    pPre = pHead; 
    pNode = pHead->next;

    pPre->next = NULL;//第一个结点next指向空

    while(pNode)
    {
        pNext = pNode->next;

        pNode->next = pPre;//修改指针方向

        if(pNext == NULL)
        {
            pNewHead = pNode;
            break;
        }

        pPre = pNode;
        pNode = pNext;
    }

    return pNewHead;
}

ListNode *Solution::CreateRandedList(int len)
{
    if(len <=0)
        return NULL;

    ListNode *pHead = Solution::CreateList(len);

    if(pHead == NULL)
        return pHead;

    ListNode *pNode1 = pHead;
    ListNode *pNode2 = pNode1->next;
    while(pNode1)
    {
        pNode2 = pNode1->next;
        while(pNode2)
        {
            if(pNode1->val > pNode2->val)
            {
                /* 交换两个结点的val */
                swap(pNode1->val, pNode2->val);
            }
            pNode2 = pNode2->next;
        }
        pNode1 = pNode1->next;
    }
    return pHead;
}

ListNode *Solution::Merge(ListNode *pHead1, ListNode *pHead2)
{
    ListNode *p1 = pHead1;
    ListNode *p2 = pHead2;
//    ListNode *p1Next = NULL;
    ListNode *p2Next = NULL;
    ListNode *pMergeHead = NULL;
    ListNode *pCurLastNode = NULL;

    if(pHead1 == NULL)
        return pHead2;

    if(pHead2 == NULL)
        return pHead1;

    /* 比较两个list的头结点 */
    if(p1->val <= p2->val)
    {
        pMergeHead = p1;
        p1 = p1->next;
        pCurLastNode = pMergeHead;
    }else
    {
        pMergeHead = p2;
        p2 = p2->next;
        pCurLastNode = pMergeHead;
    }

    while(p1 != NULL && p2 != NULL)
    {
        if (p1->val > p2->val)
        {
            /* 把p2插在pCurLastNode和p1之间 */
            p2Next = p2->next;
            p2->next = p1;
            pCurLastNode->next = p2;

            pCurLastNode = p2;
            p2 = p2Next;
        }
        else/* 如果p1一直比p2结点小，则一直往后移 */
        {
            pCurLastNode = p1;
            p1 = p1->next;
        }
    }

    if(p1 == NULL)
    {
        pCurLastNode->next = p2;
    }

    return pMergeHead;
}

bool Solution::isSubTree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if(pRoot2 == NULL)
        return true;
    if(pRoot1 == NULL && pRoot2 != NULL)
        return false;

    //若两者相等，就继续判断子节点是否一致。
    cout << pRoot1->val << " " << pRoot2->val << endl;
    if(pRoot1->val == pRoot2->val)
    {
        return isSubTree(pRoot1->left, pRoot2->left) && isSubTree(pRoot1->right, pRoot2->right);
    }
    else
    {
        return false;
    }
}

bool Solution::HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if(pRoot2 == NULL)
        return false;
    if(pRoot1 == NULL && pRoot2 != NULL)
        return false;

    //判断从pRoot1和pRoot2开始子树是否完全相同，若相同就结束程序。
    return isSubTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2)
            || HasSubtree(pRoot1->right, pRoot2);
}

TreeNode *Solution::CreateBinaryTree()
{
    TreeNode *pNode1 = new TreeNode(8);
    TreeNode *pNode2 = new TreeNode(6);
    TreeNode *pNode3 = new TreeNode(10);
    TreeNode *pNode4 = new TreeNode(5);
    TreeNode *pNode5 = new TreeNode(7);
    TreeNode *pNode6 = new TreeNode(9);
    TreeNode *pNode7 = new TreeNode(11);
    pNode1->left = pNode2;
    pNode1->right = pNode3;
    pNode2->left = pNode4;
    pNode2->right = pNode5;
    pNode3->left = pNode6;
    pNode3->right = pNode7;
    return pNode1;
}

TreeNode *Solution::CreateBinaryTree2()
{
    TreeNode *pNode1 = new TreeNode(10);
    TreeNode *pNode2 = new TreeNode(5);
    TreeNode *pNode3 = new TreeNode(7);
    TreeNode *pNode4 = new TreeNode(4);
    TreeNode *pNode5 = new TreeNode(12);

    pNode1->left = pNode2;
    pNode1->right = pNode3;
    pNode2->left = pNode4;
    pNode2->right = pNode5;
    return pNode1;
}

void Solution::PrintBinaryTree(TreeNode *pRoot)
{
    if(pRoot != NULL)
    {
        cout << "val=" << pRoot->val;
        if(pRoot->left)
            cout << ", left=" << pRoot->left->val;
        if(pRoot->right)
            cout << ", right=" << pRoot->right->val;
        cout << endl;
    }

    if(pRoot->left)
        PrintBinaryTree(pRoot->left);

    if(pRoot->right)
        PrintBinaryTree(pRoot->right);
}

void Solution::Mirror(TreeNode *pRoot)
{
    /* 从根节点开始遍历，交换left和right */
    if(pRoot == NULL)
        return;
    /* 若左右子树存在，交换 */
    swap(pRoot->left, pRoot->right);

    if(pRoot->left)
        Mirror(pRoot->left);
    if(pRoot->right)
        Mirror(pRoot->right);
}

void Solution::printMatrixInCircle(vector<vector<int> > matrix, vector<int> &vec, int start)
{
    int cols = matrix[0].size();
    int rows = matrix.size();
    int i, j;
    int endX = rows-1-start;
    int endY = cols-1-start;/* 列数 */
    cout << "endX=" << endX << ",endY=" << endY << endl;

    /*左向右打印*/
    for(j = start; j<=endY; j++)
    {
        vec.push_back(matrix[start][j]);
//        cout << matrix[start][j] << " ";
    }

    /*上向下打印, 行数大于0才打印*/
    for(i = start+1; i<=endX; i++)
    {
        vec.push_back(matrix[i][endY]);
//        cout << matrix[i][endY] << " ";
    }


    /*右向左打印*/
    if(start < endX && start < endY)
    {
        for(j = endY-1; j>=start; j--)
        {
            vec.push_back(matrix[endX][j]);
    //        cout << matrix[endX][j] << " ";
        }
    }

    /*下向上打印*/
    if(start < endY)
    {
        for(i = endX-1; i>=start+1; i--)
        {
            vec.push_back(matrix[i][start]);
    //        cout << matrix[i][start] << " ";
        }
    }
}

vector<int> Solution::printMatrix(vector<vector<int> > matrix)
{
    int cols, rows, i, circles;
    cols = matrix[0].size();
    rows = matrix.size();
    int dimention = rows <= cols ? rows : cols;
    if(dimention % 2)
        circles = (dimention+1)/2;
    else
        circles = dimention/2;

    cout << "rows=" << rows << ",cols=" << cols << ",circles=" << circles << endl;

    vector<int> vec;
//    vec.resize(rows*cols);

    if(matrix.empty())
        return vec;

    /* 一圈一圈的打印4*4矩阵最后一圈只有一个元素[2,2],5*5矩阵最后一圈有4个元素[2,2][2,3][3,3][3,2] */
    /* 打印的圈数等于维数/2+1,起始打印位置为[0,0][1,1][2,2]=i */
    for (i=0; i<circles; i++)
    {
        printMatrixInCircle(matrix, vec, i);
    }

    return vec;
}

void Solution::minPush(int value)
{
    /* stack2栈顶总是存最小值 */
    if(!stack2.empty())
    {
        /* 若比最小值小才push进stack2 */
        if(value < stack2.top())
        {
            stack2.push(value);
        }
    }
    else
    {
        stack2.push(value);
    }
    stack1.push(value);
}

void Solution::minPop()
{
    int num = stack1.top();
    stack1.pop();
    /* 若pop的是最小值，stack2中也要将其弹出 */
    if(num == stack2.top())
        stack2.pop();
}

int Solution::minTop()
{
    return stack2.top();
}

int Solution::min()
{
    return stack2.top();
}

bool Solution::IsPopOrder(vector<int> pushV, vector<int> popV)
{
    stack<int> st;
    vector<int>::iterator it1 = pushV.begin();
    vector<int>::iterator it2 = popV.begin();

    /* 遍历一遍pushV，碰到不等就push，碰到相等就跳过 */
    while(it1 != pushV.end())
    {
//        cout << *it1 << endl;
        if(*it1 != *it2)
        {
            st.push(*it1);
        }
        else
        {
            /* 若相等，比较一下top和popV中下个元素是否相等，相等就pop */
            while(!st.empty())
            {
                if(st.top() == *(++it2))
                    st.pop();
                else
                    break;
            }
        }
        it1++;
    }
    /* 当pushV遍历完后，看栈顶元素是否和popV中元素相等 */
    while(!st.empty())
    {
        if(*it2 == st.top())
        {
            st.pop();
            it2++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

/* 22.二叉树分层打印（从上到打印二叉树的每个结点，同层结点从左至右打印）
 * 思路：队列 */
vector<int> Solution::PrintFromTopToBottom(TreeNode *root)
{
    queue<TreeNode *> que;
    TreeNode *pNode = NULL;
    vector<int> res;

    if(NULL == root)
        return res;

    que.push(root);
    while(!que.empty())/* 当队列不为空时，将下一层的结点入队 */
    {
        pNode = que.front();

        if(pNode->left)
            que.push(pNode->left);

        if(pNode->right)
            que.push(pNode->right);

        res.push_back(pNode->val);
        que.pop();
    }
    return res;
}

bool Solution::VerifySquenceOfBST(vector<int> sequence)
{
    if (sequence.empty())
        return false;

    vector<int> left;
    vector<int> right;
    vector<int>::iterator it = sequence.begin();
    int rootVal = sequence.back();

    while(*it < rootVal)
    {
        left.push_back(*it);
        it++;
    }
    PrintArray(left);

    while(*it != rootVal)
    {
        if(*it < rootVal)
            return false;
        right.push_back(*it);
        it++;
    }
    PrintArray(right);

    if(!left.empty())
    {
        if (false == VerifySquenceOfBST(left))
            return false;
    }

    if(!right.empty())
    {
        if (false == VerifySquenceOfBST(right))
            return false;
    }

    return true;
}

vector<vector<int> > Solution::FindPath(TreeNode *root, int expectNumber)
{
    if (root == NULL)
        return resAll;

    /* 根节点 */
    res.push_back(root->val);
    cout << root->val << endl;
    SumOfNode+=root->val;

    /* 若为叶子节点 */
    if(root->left == NULL && root->right == NULL)
    {
        cout << "SumOfNode=" << SumOfNode << endl;
        if(SumOfNode == expectNumber)
        {
            resAll.push_back(res);
        }
    }

    /* 遍历左子树 */
    if(root->left)
        FindPath(root->left, expectNumber);

    /* 遍历右子树 */
    if(root->right)
        FindPath(root->right, expectNumber);

    res.pop_back();
    SumOfNode-=root->val;

    return resAll;
}

void Solution::PrintDbLinkList(TreeNode *pRootOfTree)
{
    TreeNode *pNode = pRootOfTree;
    while(pNode)
    {
        if(pNode->right == NULL)
            cout << pNode->val << endl;
        else
            cout << pNode->val << "<-->";
        pNode = pNode->right;
    }
}

TreeNode *Solution::Convert(TreeNode *pRootOfTree)
{
    TreeNode *pLeft = NULL;
    TreeNode *pRight = NULL;
    TreeNode *pNode = NULL;

    if(pRootOfTree == NULL)
        return NULL;
    if(pRootOfTree->left == NULL && pRootOfTree->right == NULL)
        return pRootOfTree;

    /* 将左子树转化成双向链表，返回值为头结点 */
    pLeft = Convert(pRootOfTree->left);
    if(pLeft)
    {
        pLeft->left = NULL;

        /* 遍历到左子树最后一个结点 */
        pNode = pRootOfTree->left;
        while(pNode->right)
        {
            pNode = pNode->right;
        }
        pNode->right = pRootOfTree;
        pRootOfTree->left = pNode;
    }
    /* 将右子树转化成双向链表，返回值为头结点 */
    pRight = Convert(pRootOfTree->right);
    if(pRight)
    {
        pRight->left = pRootOfTree;
        pRootOfTree->right = pRight;
        /* 遍历到右子树最后一个结点 */
        pNode = pRootOfTree->right;
        while(pNode->right)
        {
            pNode = pNode->right;
        }
        pNode->right = NULL;
    }


    return pLeft == NULL ? pRootOfTree:pLeft;
}

void Solution::Perm(string str, int begin, int end)
{
    if(begin == end)
    {
        vec.push_back(str);
    }
    else
    {
        for(int i = begin; i<end; i++)
        {
            if(i!=begin && str[i]==str[begin])
                continue;
            swap(str[i], str[begin]);
            Perm(str, begin+1, end);
            swap(str[i], str[begin]);
        }
    }
}

vector<string> Solution::Permutation(string str)
{
    if(str.empty())
        return vec;

    Perm(str, 0, str.size());
    sort(vec.begin(), vec.end());

    return vec;
}

vector<int> Solution::GetLeastKNumbers(vector<int> input, int k)
{
    vector<int> vec;

    if(input.size() < k)
        return vec;

    partial_sort(input.begin(), input.begin()+k, input.end());
    for(int i = 0; i<k; i++)
        vec.push_back(input[i]);

    return vec;
}

vector<int> Solution::FindNumsAppearOnce(vector<int> data)
{
    int size = data.size();
    int res = 0;
    int i, j;
    vector<int> vec;
    vector<int> vec1;
    vector<int> vec2;

    if(size < 2)
        return vec;
    /* 从头到尾异或一遍，结果为不相同的两个数异或的结果 */
    for(i = 0; i<size; i++)
        res = res^data[i];
    cout << "res=" << res << endl;

    if(res == 0)
        return vec;

    /* 异或结果为两个不同数不同的位，获取第一个不同的位 */
    j=1;
    while(0 != res&j)
        j = j<<1;
//    cout << "j=" << j << endl;

    /* 把data分为两组，一组这一位为1，另一组这一位为0 */
    for(i = 0; i<size; i++)
    {
//        cout << "data[" << i << "]=" << data[i] << endl;
        if(0 != (data[i]&0x2))
        {
            vec1.push_back(data[i]);
            cout << "vec1:" << data[i] << endl;
        }
        else
        {
            vec2.push_back(data[i]);
            cout << "vec2:" << data[i] << endl;
        }
    }

    /* 找出两组中只出现一次的那个数 */
    for(i = 0, res=0; i<vec1.size(); i++)
        res = res^vec1[i];
    vec.push_back(res);

    for(i = 0, res=0; i<vec2.size(); i++)
        res = res^vec2[i];
    vec.push_back(res);

    return vec;
}

/* 这道题的思路是扫描到当前第n个值时，假设前面n-1个值算出来的最大和sum(n-1)

*/
int Solution::FindGreatestSumOfSubArray(vector<int> array)
{
    if(array.empty())
        return 0;

    int result = array[0];
    int sum = array[0];

    /* 动态划归 */
    for (int i = 1; i<array.size(); i++)
    {
        /* sum(n-1) + array[i] 和 array[i] 比较，只需要看sum(n-1)是否大于0
           sum中存储到目前为止最大的和 */
        if(sum > 0)
            sum += array[i];
        else/* 如果当前是负数，sum加上这个数肯定比原来小，则放弃前面的sum(n-1),到目前n为止，最大和为array[n] */
            sum = array[i];

        /* 当前结果 比较 前面最大的结果 */
        if (sum > result)
            result = sum;
        cout << "result=" << result << endl;
    }
    return result;
}

/*输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。*/
vector<int> Solution::FindNumbersWithSum(vector<int> array, int sum)
{
    int i = 0;
    int j = array.size()-1;
    vector<int> vec;

    if(array.empty())
        return vec;

    while(i<j)
    {
        j = array.size()-1;
        while(i<j && array[i]+array[j] >= sum)
        {
            cout << "i = " << i << ", j = " << j << endl;
            if(array[i]+array[j] == sum)
            {
                vec.push_back(array[i]);
                vec.push_back(array[j]);
                return vec;
            }
            j--;
        }
        i++;
    }

    return vec;
}

/* 左旋转字符串
 * 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”
 * 经典的三次翻转：
 * 1.先翻转字符串前n个字符；
 * 2.再翻转后面的字符；
 * 3.翻转整个字符串；*/
string Solution::LeftRotateString(string str, int n)
{
    if (str.empty() || n < 0)
        return str;

    reverse(str.begin(), str.begin()+n);

    reverse(str.begin()+n, str.end());

    reverse(str.begin(), str.end());

    return str;
}

/* 翻转单词顺序列
 * 例如，字符序列S=“student. a am I”,要求逆序输出每个单词，即“I am a student.”
 * 1.先翻转整个字符串；
 * 2.再翻转每个单词 */
string Solution::ReverseSentence(string str)
{
    if (str.empty())
        return str;

    reverse(str.begin(), str.end());
    cout << str << endl;

    string::iterator itBegin = str.begin();

    for(string::iterator it = str.begin(); it <= str.end(); it++)
    {
        if(*it == ' ' || it == str.end())
        {
            cout << it-str.begin() << endl;
            reverse(itBegin, it);/* 翻转每一个单词 */
            itBegin = it+1;
        }
    }

    return str;
}

int Solution::Sum_Solution(int n)
{
    if(n == 1)
        return 1;

    return Sum_Solution(n-1)+n;
}

/* 把字符串转换成整数
 *
 */
int Solution::StrToInt(string str)
{
    if(str.empty())
        return 0;

    int flag = 1;
    int i = 0;
    int num = 0;
    string::iterator it;

    if(str[i] == '-')
    {
        flag = -1;
        i++;
    }
    else if(str[i] == '+')
    {
        i++;
    }
    for( ; i < str.size(); i++)
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;

        num = num*10+str[i]-'0';
    }
    return flag*num;
}

/* 数组中重复的数字
 *
 */
bool Solution::duplicate(int numbers[], int length, int *duplication)
{
    if(numbers == NULL || length <= 0 || duplication == NULL)
        return false;

    for(int i = 0; i<length; i++)
    {
        for(int j = i+1; j<length; j++)
        {
            if(numbers[i] == numbers[j])
            {
                *duplication = numbers[i];
                return true;
            }
        }
    }
    return false;
}

bool Solution::matchCore(char *str, char *pattern)
{
    if(*str == '\0' && *pattern == '\0')
        return true;
    if(*str != '\0' && *pattern == '\0')
        return false;

    /* 考虑后面是否有* */
    if(*(pattern+1) == '*')
    {
        if(*str == *pattern || (*pattern == '.' && *str != '\0'))
            return matchCore(str+1, pattern) || matchCore(str, pattern+2);
        else
            return matchCore(str, pattern+2);
    }
    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str+1, pattern+1);

    return false;
}

/* 正则表达式匹配（递归）
 * 1.下一位不是*的情况比较简单
 * matchCore(str+1, pattern + 1)
 * 2.对应为不匹配，返回false
 * 3.下一位是*，分三种情况:
 * 3.1 matchCore(str+1,pattern) 模式串匹配成功，并尝试匹配下一字符
 * 3.2 matchCore(str+1,pattern) 模式串匹配不成功，如abbc和ab*c，需要跳过b*，匹配matchCore(str,pattern+2)
 * 3.3 matchCore(str,pattern+2) 模式串未匹配

 */
bool Solution::match(char *str, char *pattern)
{
    if(str == NULL || pattern == NULL)
        return false;
    return matchCore(str, pattern);
}

void Solution::Insert(char ch)
{
    str+=ch;
    hash[ch]++;
}

char Solution::FirstAppearingOnce()
{
    if(str.empty())
        return '#';

    /* 从头扫描str字符串 */
    for(int j = 0; j<str.size(); j++)
    {
        if(hash[str[j]] == 1)
            return str[j];
    }
    return '#';
}

/* 56.删除链表中重复的结点
 * 思路:
 * 1、需要两个指针，一个指向前一个节点preNode，另一个指向当前节点node
 * 如果遇到相等的节点，node向后移动，preNode不动，存下node.val方便后面的比较，直到遇到node和node.next不相等，preNode就可以指向node.next
 * 注意：链表开头可能就开始有重复的节点，所以默认preNode=null，在后面的给preNode赋值的时候，若preNode为null，那就把pHead设置为node.next
 * 1、建立指针pNode，用于遍历链表；
 * 2、建立指针pNext，遍历pNode后面的结点，并与Node数值比较；
 * 3、建立指针pRemovedNode，保存需要删掉的结点，再把需要删掉的结点的前后结点相接。由此去掉重复值。
 */
ListNode *Solution::deleteDuplication(ListNode *pHead)
{
    if(pHead == NULL)
        return pHead;

    ListNode *head = pHead;
    ListNode *pPre = NULL;/* 由于重复的结点不保留，因此需要保留前一个结点。pPre指向的是不重复的结点 */
    ListNode *pCur = pHead;

    while(pCur != NULL)
    {
        if(pCur->next != NULL && pCur->val == pCur->next->val)
        {
            int val = pCur->val;
            while(pCur->next != NULL && pCur->next->val == val)
            {
                /* 删除值相等的结点 */
                pCur = pCur->next;//往后移
            }

            //此时pCur指向最后一个需要删除的结点，后一个结点要么为空，要么val和前面值不同
            if(pPre == NULL)//为空说明头结点还没确定
                head = pCur->next;
            else//不为空说明需要连上后面的结点
                pPre->next = pCur->next;//删除后，连上结点
        }
        else
        {
            /* pCur此时是不重复的结点：既不和后一结点相等，且后一结点不为NULL */
            pPre = pCur;

        }
        pCur = pCur->next;
    }
    //此时pCur指向链表末尾NULL
    return head;
}
/* 57.二叉树的下一个结点
 * 找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 * 1.右子树存在，返回右子树最左叶子结点
 * 2.右子树不存在，看是否是根的左孩子，是则返回根，否则返回NULL
 */
TreeLinkNode *Solution::GetNext(TreeLinkNode *pNode)
{
    if(pNode == NULL)
        return NULL;

    /* 右子树存在 */
    if(pNode->right != NULL)
    {
        TreeLinkNode *pTreeNode = pNode->right;
        while(pTreeNode->left != NULL)
            pTreeNode = pTreeNode->left;
        return pTreeNode;
    }
    /* 右子树不存在 */
    if(pNode->next != NULL)
    {
        TreeLinkNode *pRoot = pNode->next;
        /* 若结点不是父结点的左孩子，则继续往上,直到是左孩子 */
        while(pRoot != NULL && pRoot->left != pNode)
        {
            pNode = pRoot;
            pRoot = pRoot->next;
        }
        return pRoot;
    }

    return NULL;
}

/* 58.二叉树的下一个结点
 *
 */
bool Solution::isSymmetrical(TreeNode *pRoot)
{
    if(pRoot == NULL)
        return true;

    return isMirror(pRoot->left, pRoot->right);
}

bool Solution::isMirror(TreeNode *pLeft, TreeNode *pRight)
{
    if(pLeft == NULL && pRight == NULL)
        return true;
    if((pLeft == NULL && pRight != NULL) || (pLeft != NULL && pRight == NULL))
        return false;
    cout << "left=" << pLeft->val << ", right=" << pRight->val << endl;
    if(pLeft->val != pRight->val)
        return false;

    return isMirror(pLeft->left, pRight->right) && isMirror(pLeft->right, pRight->left);
}
/* 59.按之字形打印二叉树
 * 思路：两个栈
 */
vector<vector<int> > Solution::Print(TreeNode *pRoot)
{
    vector<vector<int> >res;
    vector<int> vec;
    stack<TreeNode *> sta[2];
    int cur = 0;/*需要打印结点的栈*/
    int next = 1;
    TreeNode *pNode = NULL;

    if(pRoot == NULL)
        return res;

    sta[cur].push(pRoot);//根结点入栈
    while(!sta[cur].empty() || !sta[next].empty())
    {
        pNode = sta[cur].top();
        vec.push_back(pNode->val);
        sta[cur].pop();

        if(cur == 0)
        {
            if(pNode->left)
                sta[next].push(pNode->left);
            if(pNode->right)
                sta[next].push(pNode->right);
        }
        else
        {
            if(pNode->right)
                sta[next].push(pNode->right);
            if(pNode->left)
                sta[next].push(pNode->left);
        }

        if(sta[cur].empty())
        {
            res.push_back(vec);
            vec.clear();
            cur = 1-cur;
            next = 1-next;
        }
    }

    return res;
}

/* 60.把二叉树打印成多行
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
 * 思路：队列+记录每层的个数，与22.从上往下打印二叉树类似
 * 出列时，将左右孩子入列*/
vector<vector<int> > Solution::PrintTreeByLayer(TreeNode *pRoot)
{
    vector<vector<int> >res;
    queue<TreeNode*> que;

    if(pRoot == NULL)
        return res;

    que.push(pRoot);
    while(!que.empty())
    {
        vector<int> vec;
        int size = que.size();
        for(int i = 0; i<size; i++)
        {
            TreeNode *pNode = que.front();
            vec.push_back(pNode->val);
            que.pop();
            if(pNode->left)
                que.push(pNode->left);
            if(pNode->right)
                que.push(pNode->right);
        }
        res.push_back(vec);
    }
    return res;
}

char *Solution::Serialize(TreeNode *root)
{
    if(root == NULL)
        return "$";

    return Serialize(root->left);
}

void Solution::PrintArray(int *arr, int len)
{
    for(int i = 0; i<len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* 堆排序的过程是：
(1)建立一个堆H[0..n-1]。
(2)把堆首（最大值）和堆尾互换。
(3)把堆的尺寸缩小1，然后调整堆，目的构成新的堆。
(4)重复步骤2，直到堆的尺寸为1。
 */
void Solution::HeapSort(int *arr, int size)
{
    /*1.build heap 最后一个非叶子结点开始，从下至上，从右至左构建最大堆，最后一个非叶子结点下标：size/2-1*/
    for(int root = size/2-1; root>=0; root--)
        AdjustHeap(arr, root, size);
    PrintArray(arr, size);

    /* 2.swap and adjust heap */
    for(int i = size-1; i>0; i--)//i指向末尾元素
    {
        cout << "before swap 0 and " << i << ": ";
        PrintArray(arr, size);

        swap(arr[0], arr[i]);

        cout << "after swap 0 and " << i << ": ";
        PrintArray(arr, size);

        AdjustHeap(arr, 0, i-1);//调整前面的堆
    }
}

/* 调整大顶堆（仅是调整过程，建立在大顶堆已构建的基础上）
 * 使数组0-length的元素构成最大堆*/
void Solution::AdjustHeap(int *arr, int root, int end)
{
    int son = 2*root+1;
    int max = root;/*最大子结点下标*/

    /*对每个子树的根结点，从i结点的左结点开始，2i+1*/
    if(root<end/2)
    {
        /*若有右结点，选择左右两个结点中较大的值和父结点交换，max记录较大子结点的数组下标*/
        if(son+1<=end)
            max = arr[son]>arr[son+1]?son:son+1;

        if(max!=root && arr[max] > arr[root])
        {
            swap(arr[max], arr[root]);
            AdjustHeap(arr, max, end);
        }
    }
}

int Solution::removeDuplicates(int a[], int n)
{
    if(n==0)
        return 0;
    int index = 0;
    for(int i = 1; i<n; i++){
        if(a[index] != a[i])
            a[++index] = a[i];
    }
    for(int i = 0; i<index+1; i++)
    {
        cout <<a[i] << " ";
    }
    cout << endl;
    return index+1;
}
