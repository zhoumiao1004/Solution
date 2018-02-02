#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
    Solution();
    void removeDuplicates(char *str);
    void replaceSpace(char *str);
    char *strFind(char *str, char *subStr);
    vector<int> printListFromTailToHead(ListNode* head);
    ListNode *CreateList(int len);
    void PrintList(ListNode *head);
    TreeNode *DFS(vector<int> pre, vector<int> vin, int begin1, int end1, int begin2, int end2);
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin);
    void PrintBinaryTreePostOrder(TreeNode *root);
    void push(int node);
    int pop();
    int minNumberInRotateArray(vector<int> rotateArray);
    int Fibonacci(int n);
    int jumpFloor(int number);
    int jumpFloorII(int number);
    int NumberOf1(int n);
    double Power(double base, int exponent);
    void PrintArray(vector<int> &array);
    void reOrderArray(vector<int> &array);
    int GetListLength(ListNode *head);
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);
    ListNode* ReverseList(ListNode* pHead);
    ListNode *CreateRandedList(int len);
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2);
    bool isSubTree(TreeNode *pRoot1, TreeNode *pRoot2);
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
    TreeNode *CreateBinaryTree();
    TreeNode *CreateBinaryTree2();
    void PrintBinaryTree(TreeNode *pRoot);
    void Mirror(TreeNode *pRoot);
    void printMatrixInCircle(vector<vector<int> >matrix, vector<int> &vec, int start);
    vector<int> printMatrix(vector<vector<int> > matrix);
    void minPush(int value);
    void minPop();
    int minTop();
    int min();
    bool IsPopOrder(vector<int> pushV, vector<int> popV);
    vector<int> PrintFromTopToBottom(TreeNode* root);/* 22.从上往下打印二叉树，同层结点从左至右打印 */
    bool VerifySquenceOfBST(vector<int> sequence);
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber);
    void PrintDbLinkList(TreeNode* pRootOfTree);
    TreeNode* Convert(TreeNode* pRootOfTree);
    void Perm(string str, int begin, int end);
    vector<string> Permutation(string str);
    vector<int> GetLeastKNumbers(vector<int> input, int k);
    vector<int> FindNumsAppearOnce(vector<int> data);
    int FindGreatestSumOfSubArray(vector<int> array);/* 连续子数组的最大和 */
    vector<int> FindNumbersWithSum(vector<int> array, int sum);
    string LeftRotateString(string str, int n);
    void ReverseString(string str, int begin, int end);
    string ReverseSentence(string str);
    int Sum_Solution(int n);
    int StrToInt(string str);
    bool duplicate(int numbers[], int length, int* duplication);
    bool matchCore(char* str, char* pattern);/* 正则表达式匹配 */
    bool match(char* str, char* pattern);/* 正则表达式匹配 */
    void Insert(char ch);//Insert one char from stringstream
    char FirstAppearingOnce();//return the first appearence once char in current stringstream
    ListNode* deleteDuplication(ListNode* pHead);/* 删除链表中重复的节点 */
    TreeLinkNode* GetNext(TreeLinkNode* pNode);/* 57.找到中序遍历的下一个结点 */
    bool isSymmetrical(TreeNode *pRoot);/* 58.判断一个二叉树是不是对称的 */
    bool isMirror(TreeNode *pLeft, TreeNode *pRight);
    vector<vector<int> > Print(TreeNode *pRoot);/* 59.按之字形打印二叉树 */
    vector<vector<int> > PrintTreeByLayer(TreeNode* pRoot);/* 60.把二叉树打印成多行，注意与22的区别 */
    char* Serialize(TreeNode *root);/* 61.实现两个函数，分别用来序列化和反序列化二叉树 */
    TreeNode* Deserialize(char *str);
    void PrintArray(int *arr, int len);
    void HeapSort(int *arr, int size);/*堆排序*/
    void AdjustHeap(int *arr, int root, int end);/*调整前length个元素，构成最大堆*/
    int removeDuplicates(int a[], int n);//Remove Duplicates from Sorted Array
private:
    stack<int> stack1;
    stack<int> stack2;
    vector<string> vec;
    string str;
    int hash[256] = {0};/* 哈希表 */
public:
    vector<vector<int> > resAll;
    vector<int> res;
    int SumOfNode;
};

#endif // SOLUTION_H
