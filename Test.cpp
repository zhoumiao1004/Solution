#include <iostream>
#include "Solution.h"
using namespace std;

Solution s;

void TestPushPop()
{
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.pop();
    s.push(4);
    s.pop();
    s.push(5);
    s.pop();
    s.pop();
}

void TestMinNumberInRotateNumber()
{
    int a[5] = {4,5,1,2,3};
    vector<int> vec(a,a+5);
    Solution s;
    cout << s.minNumberInRotateArray(vec) << endl;
}

void TestFibonacci()
{
    Solution s;
    for (int i = 0; i<10; i++)
    {
        cout << "Fibonacci(" << i << ") = " << s.Fibonacci(i) << endl;
    }
}

void TestJumpFloor()
{
    for(int i = 1; i<8; i++)
    {
        cout << "jumpFloor(" << i << ")=" << s.jumpFloor(i) << endl;
    }
}

void TestJumpFloorII()
{
    for(int i = 1; i<8; i++)
    {
        cout << "jumpFloorII(" << i << ")=" << s.jumpFloorII(i) << endl;
    }
}

void TestNumberOf1()
{
    int n = 0x1110;
    cout << n << " Number Of 1 is:" << s.NumberOf1(n) << endl;
}

void TestPower()
{
    int n = 2;
    int m = -3;
    cout << m << " power of " << n << " is " << s.Power(n, m) << endl;
}

void TestReOrderArray()
{
    int a[7] = {3,4,2,5,8,9,7};
    vector<int> array(a, a+7);
    //s.PrintArray(array);
    s.reOrderArray(array);
    //s.PrintArray(array);
}

void TestFindKthToTail()
{
    ListNode *head = s.CreateList(5);
    s.PrintList(head);
    ListNode *pNode = s.FindKthToTail(head, 5);
    cout << "Kth node to tail, val = " << pNode->val << endl;
    s.PrintList(pNode);
}

void TestReverseList()
{
    ListNode *pHead = s.CreateList(8);
    s.PrintList(pHead);
    ListNode *pNewHead = s.ReverseList(pHead);
    s.PrintList(pNewHead);
}

void TestMergeList()
{
    ListNode *pHead1 = s.CreateRandedList(10);
    s.PrintList(pHead1);
    ListNode *pHead2 = s.CreateRandedList(10);
    s.PrintList(pHead2);
    pHead1 = s.Merge(pHead1, pHead2);
    s.PrintList(pHead1);
}

void TestReConstructBinaryTree()
{
    int a[8] = {1,2,4,7,3,5,6,8};
    int b[8] = {4,7,2,1,5,3,8,6};
    vector<int> pre(a,a+8);
    vector<int> vin(b,b+8);
    TreeNode *pRoot = s.reConstructBinaryTree(pre, vin);
    s.PrintBinaryTree(pRoot);
}

void TestHasSubtree()
{
    int a[8] = {1,2,4,7,3,5,6,8};
    int b[8] = {4,7,2,1,5,3,8,6};
    vector<int> pre(a,a+8);
    vector<int> vin(b,b+8);
    TreeNode *pRoot = s.reConstructBinaryTree(pre, vin);
    TreeNode *pRoot2 = new TreeNode(3);
    pRoot2->left = new TreeNode(5);
    pRoot2->right = new TreeNode(6);
    cout << s.HasSubtree(pRoot, pRoot2) << endl;
}

void TestMirror()
{
    TreeNode *pRoot = s.CreateBinaryTree();
    s.PrintBinaryTree(pRoot);
    s.Mirror(pRoot);
    s.PrintBinaryTree(pRoot);
}

void TestPrintMatrixInCircle()
{
    int i, j, n=0;
    int rows = 5;
    int cols = 5;
//    int a[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
//    int a[5][1] = {{1},{2},{3},{4},{5}};
    vector<vector<int> > matrix(rows, vector<int>(cols));

    for (i = 0; i<rows; i++)
    {
        for (j = 0; j<cols; j++)
        {
            matrix[i][j] = ++n;
        }
    }
    /* 打印二维数组 */
    for (i = 0; i<rows; i++)
    {
        for (j = 0; j<cols; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    vector<int> vec = s.printMatrix(matrix);
    s.PrintArray(vec);
}

void TestStackMin()
{
    s.minPush(5);
    s.minPush(3);
    s.minPush(4);
    s.minPush(7);
    s.minPush(2);

    cout << s.min() << endl;
    s.minPop();
    cout << s.min() << endl;
}

void TestIsPopOrder()
{
    int a[5] = {1,2,3,4,5};
    int b[5] = {4,3,5,2,1};
    vector<int> pushV(a, a+5);
    vector<int> popV(b, b+5);
    cout << s.IsPopOrder(pushV, popV) << endl;
}

void TestPrintFromTopToBottom()
{
    TreeNode *pRoot = s.CreateBinaryTree();
    vector<int> vec = s.PrintFromTopToBottom(pRoot);
    s.PrintArray(vec);
}

void TestVerifySquenceOfBST()
{
    int a[7] = {5,7,6,9,11,8,10};
    vector<int> vec(a, a+7);
    cout << "VerifySquenceOfBST=" << s.VerifySquenceOfBST(vec) << endl;
}

void TestPath()
{
    TreeNode *pRoot = s.CreateBinaryTree2();
    vector<vector<int> > pVec = s.FindPath(pRoot, 15);
    cout << pVec.size() << endl;
    for(vector<vector<int> >::iterator it = pVec.begin(); it != pVec.end(); it++)
    {
        s.PrintArray(*it);
    }
}

void TestConvert()
{
    TreeNode *pRoot = s.CreateBinaryTree();
    pRoot = s.Convert(pRoot);
    s.PrintDbLinkList(pRoot);
}

void TestPermutation()
{
    string str = string("abc");
    vector<string> vec = s.Permutation(str);
    for(vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << endl;
    }
}

void TestGetLeastKNumbers()
{
    int a[8] = {4,5,1,6,2,7,3,8};
    vector<int> data(a, a+8);
    vector<int> vec = s.GetLeastKNumbers(data, 4);
    for(int i =0; i<vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

void TestFindNumsAppearOnce()
{
    int a[10] = {9,12,23,24,21,12,9,24,23,7};
    vector<int> data(a, a+10);
    vector<int> vec = s.FindNumsAppearOnce(data);
    for(int i = 0; i<vec.size(); i++)
        cout << vec[i] << endl;
}

void TestFindGreatestSumOfSubArray()
{
    int a[8] = {1, -2, 3, 10, -4, 7, 2, -5};
    vector<int> data(a, a+8);
    int result = s.FindGreatestSumOfSubArray(data);
    cout << result << endl;
}

void TestFindNumbersWithSum()
{
    int a[8] = {1,4,5,7,10,12,17,18};
    vector<int> array(a, a+8);
    vector<int> res;
    res = s.FindNumbersWithSum(array, 17);
    for(int i = 0; i<res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}

void TestLeftRotateString()
{
    string str = "abcXYZdef";
    string res = s.LeftRotateString(str, 3);
}

void TestReverseSentence()
{
//    string str = "student. a am I";
    string str = "I am a student.";
    cout << str << endl;
    string res = s.ReverseSentence(str);
    cout << res << endl;
}

void TestStrToInt()
{
    string str = "-123456";
    cout << s.StrToInt(str) << endl;
}

void Testduplicate()
{
    int arr[] = {2,3,1,0,2,5,3};
    int val = 0;
    bool bRes = s.duplicate(arr, sizeof(arr)/sizeof(int), &val);
    cout << bRes << " " << val << endl;
}

void Testmatch()
{
    char *pStr = "abdbc";
    char *pattern = "ab*c";
    cout << s.match(pStr, pattern) << endl;
}

void TestInsert()
{
    s.Insert('g');
    cout << s.FirstAppearingOnce();
    s.Insert('o');
    cout << s.FirstAppearingOnce();
    s.Insert('o');
    cout << s.FirstAppearingOnce();
    s.Insert('g');
    cout << s.FirstAppearingOnce();
    s.Insert('l');
    cout << s.FirstAppearingOnce();
    s.Insert('e');
    cout << s.FirstAppearingOnce();
//    cout << endl;
}

void TestDeleteDuplication()
{
    //链表1->2->3->3->4->4->5 处理后为 1->2->5
    ListNode *pHead = new ListNode(1);
    ListNode *pNode1 = new ListNode(2);
    ListNode *pNode2 = new ListNode(3);
    ListNode *pNode3 = new ListNode(3);
    ListNode *pNode4 = new ListNode(4);
    ListNode *pNode5 = new ListNode(4);
    ListNode *pNode6 = new ListNode(5);
//    ListNode *pNode7 = new ListNode(1);
//    ListNode *pNode8 = new ListNode(9);
    pHead->next = pNode1;
    pNode1->next = pNode2;
    pNode2->next = pNode3;
    pNode3->next = pNode4;
    pNode4->next = pNode5;
    pNode5->next = pNode6;
//    pNode6->next = pNode7;
//    pNode7->next = pNode8;
    ListNode *head = s.deleteDuplication(pHead);
    s.PrintList(head);
}

void TestIsSymmetrical()
{
    TreeNode *pRoot = new TreeNode(8);
    TreeNode *pNode1 = new TreeNode(6);
    TreeNode *pNode2 = new TreeNode(6);
    TreeNode *pNode3 = new TreeNode(5);
    TreeNode *pNode4 = new TreeNode(7);
    TreeNode *pNode5 = new TreeNode(7);
    TreeNode *pNode6 = new TreeNode(5);
    pRoot->left = pNode1;
    pRoot->right = pNode2;
    pNode1->left = pNode3;
    pNode1->right = pNode4;
    pNode2->left = pNode5;
    pNode2->right = pNode6;
    cout << "result=" << s.isSymmetrical(pRoot) << endl;
}

void TestPrint()
{
    TreeNode *pRoot = new TreeNode(1);
    TreeNode *pNode1 = new TreeNode(2);
    TreeNode *pNode2 = new TreeNode(3);
    TreeNode *pNode3 = new TreeNode(7);
    TreeNode *pNode4 = new TreeNode(6);
    TreeNode *pNode5 = new TreeNode(5);
    TreeNode *pNode6 = new TreeNode(4);
    pRoot->left = pNode1;
    pRoot->right = pNode2;
    pNode1->left = pNode3;
    pNode1->right = pNode4;
    pNode2->left = pNode5;
    pNode2->right = pNode6;
    vector<vector<int> >vec = s.Print(pRoot);

    for(int i = 0; i<vec.size(); i++)
    {
        for(int j = 0; j<vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }

}

void TestPrintTreeByLayer()
{
    TreeNode *pRoot = new TreeNode(1);
    TreeNode *pNode1 = new TreeNode(2);
    TreeNode *pNode2 = new TreeNode(3);
    TreeNode *pNode3 = new TreeNode(4);
    TreeNode *pNode4 = new TreeNode(5);
    TreeNode *pNode5 = new TreeNode(6);
    TreeNode *pNode6 = new TreeNode(7);
    pRoot->left = pNode1;
    pRoot->right = pNode2;
    pNode1->left = pNode3;
    pNode1->right = pNode4;
    pNode2->left = pNode5;
    pNode2->right = pNode6;
    vector<vector<int> >vec = s.PrintTreeByLayer(pRoot);
    for(int i = 0; i<vec.size(); i++)
    {
        for(int j = 0; j<vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}

void TestHeapSort()
{
    int arr[] = {10,60,12,40,30,8};
//    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    s.HeapSort(arr, size);
    s.PrintArray(arr,size);
}

void Test()
{
    //1、使用动态数组，多维数组需要一个一个new
    int row_num = 4;
    int col_num = 5;
    int i = 0 ,j;
    int **ary1 = new int*[row_num];
    for(int i = 0; i<row_num; i++)
        ary1[i] = new int[col_num];

    //2、使用vector，一行搞定
    vector<vector<int> > ary(row_num, vector<int>(col_num, i));//所有元素初始化为i


    for(i = 0; i<row_num; i++)
    {
        for(j = 0; j<col_num; j++)
            cout << ary[i][j] << " ";
        cout << endl;
    }
    int a[] = {1,1,1,2,2,3,4};
    cout << s.removeDuplicates(a, sizeof(a)/sizeof(int)) << endl;
    cout << s.removeDuplicatesUsingSTL(a, sizeof(a)/sizeof(int)) << endl;
}
