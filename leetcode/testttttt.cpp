//
// Created by 徐浩闻 on 2023/12/8.
//
#include "bits/stdc++.h"

using namespace std;



//void n34(Node *head) {
//    int x = 5;
//    // 1-2-3-4-8-10
//    while(head->next->val < x) {
//        head = head->next;// 遍历链表 找到x的插入位置
//    }
//    Node *xx;
////head 4
////head->next
////xx 5
//    xx->val = x;// 1
//    xx->next = head->next;//2
//    head->next = xx;//3
//    struct stack{
//        int top;//栈顶的下标
//        int elem[100];
//    };
//    stack s;
//}

struct Node {
    int val;//数据yu
    Node *next;//指针yu
};

void changeList(Node *head) {
    Node *headLeft;
    Node *headRight;
    Node *mid = head;//用头节点作为基
    /*链表的遍历
//    while(head->next!=NULL) {
//        head = head->next;
//    }
     */
    while (head->next != NULL) {
        if (head->next->val <= mid->val) {
            Node *temp = head->next;
            head->next = head->next->next;

            Node *temp2 = headLeft->next;//插入左边链表
            headLeft->next = temp;
            temp->next = temp2;
        }
        if (head->next->val > mid->val) {
            Node *temp = head->next;
            head->next = head->next->next;

            Node *temp2 = headRight->next;//插入右边链表
            headRight->next = temp;
            temp->next = temp2;
        }
        head = head->next;
    }
    Node *endLeft = headLeft;
    while (endLeft->next != NULL) endLeft = endLeft->next;
    endLeft->next = mid;//链接比基准小链表
    mid->next = headRight->next;//链接比基准大链表
}

//
//struct Node {
//    int val;//数据yu
//    Node *next;//指针yu
//};
void SelectionSort(Node *head) {
    Node *start = head;
    while (start != NULL) {
        //选择排序 每次从待排序列中选择一个最小的（最大的）放入已排队列
        Node *min = start;
        Node *current = start->next;

        while (current != NULL) {
            if (current->val < min->val) min = current;
            current = current->next;
        }

        swap(start, min);//使用swap函数将start节点和最小的min节点交换位置到达将最小的放入已排前列

        start = start->next;
    }
}

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isBSTUtil(TreeNode *node, int min, int max) {
    if (node == NULL) return true;//递归程序出口（终止递归的边界）

    if (node->val <= min || node->val >= max) return false;//检查是否合法

    // 递归检查左子树和右子树
    return isBSTUtil(node->left, min, node->val);
    return isBSTUtil(node->right, node->val, max);

}

bool isBST(TreeNode *root) {
    return isBSTUtil(root, -1000000, 1000000);//程序的入口
}

//递归的函数
//1.递归出口
//2.调用自己实现迭代
struct twoTreeNode {
    int val;//数据yu
    twoTreeNode *left;//指向做孩子
    twoTreeNode *right;//指向右孩子
};

void swapSubsTree(twoTreeNode *treeNode) {
    if (treeNode == NULL) return;//如果节点为空，直接返回，不做任何操作

    //交换当前节点的左右子🌲
    twoTreeNode *temp = treeNode->left;
    treeNode->left = treeNode->right;
    treeNode->right = temp;

    //递归调用左子树进行交换操作
    swapSubsTree(treeNode->left);
    //递归调用右子树进行交换操作
    swapSubsTree(treeNode->right);
}



int main() {
    //一张图里面有n个节点
    int visited[10000] = {0};
    int map[10000] ;
    int count = 0;
    for(int i = 1; i< map.size(); i++) {

    }
}


