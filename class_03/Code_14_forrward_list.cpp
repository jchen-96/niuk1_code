// 单链表问题的极致

// 给定两个链表，如果连个链表香蕉，返回第一个节点，如果不相交，返回null即可

// 如果链表1的长度为N,链表2的长度为M,时间复杂度O(N+M)

// 单链表可能有环，也可能无环

#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
  public:
    int value;
    Node *next;

    Node(int v)
    {
        this->value = v;
        this->next = NULL;
    }
};

class Code_14_list{
    static Node getFistNode(Node *head1,Node *head2){
        return NULL;
    }


// 判断一个链表是否有环，如果有的话返回链表的第一个入环节点
    static Node getLoopNode(Node *head){

    }

    
};