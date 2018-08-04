// 单链表问题的极致

// 给定两个链表，如果连个链表香蕉，返回第一个节点，如果不相交，返回null即可

// 如果链表1的长度为N,链表2的长度为M,时间复杂度O(N+M)

// 单链表可能有环，也可能无环

#include <iostream>
#include <algorithm>
#include <cmath>
#include<cstdio>

using namespace std;

class Node
{
  public:
    int value;
    Node *next;

    Node(int v) : value(v), next(NULL)
    {
    }
};

class Code_14_list
{
  public:
    static Node* getFistNode(Node *head1, Node *head2)
    {
        if (head1 == NULL || head2 == NULL)
        {
            return NULL;
        }
        Node *loop1 = getLoopNode(head1);
        Node *loop2 = getLoopNode(head2);
        if (loop1 == NULL && loop2 == NULL)
        {
            return bothNoCicle(head1, head2);
        }
        if (loop1 != NULL && loop2 != NULL)
        {
            return bothCircle(head1, loop1, head2, loop2);
        }
        return NULL;
    }

    // 判断一个链表是否有环，如果有的话返回链表的第一个入环节点
    static Node* getLoopNode(Node *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return NULL;
        }

        Node *slow = head->next;
        Node *fast = head->next->next;
        while (fast != slow)
        {
            if (fast->next == NULL || fast->next->next == NULL)
            {
                return NULL;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
    // 都是无环链表，判断是否会相交

    static Node* bothNoCicle(Node *head1, Node *head2)
    {
        int l1 = 1;
        int l2 = 1;
        Node *h1 = head1;
        Node *h2 = head2;
        while (h1->next != NULL)
        {
            l1++;
            h1 = h1->next;
        }
        while (h2->next != NULL)
        {
            l2++;
            h2 = h2->next;
        }
        if (h1 != h2)
        {
            return NULL;
        }
        if (l1 > l2)
        {
            int dif = l1 - l2;
            while (dif != 0)
            {
                dif--;
                head1 = head1->next;
            }
        }
        if (l2 > l1)
        {
            int dif = l2 - l1;
            while (dif != 0)
            {
                dif--;
                head2 = head2->next;
            }
        }
        while (head1 != head2)
        {
            head1 = head1->next;
            head2 = head2->next;
        }

        return head1;
    }
    // 都是有环链表，判断是否会相交
    static Node* bothCircle(Node *head1, Node *loop1, Node *head2, Node *loop2)
    {
        Node *cur1 = NULL;
        Node *cur2 = NULL;
        if (loop1 == loop2)
        {
            cur1 = head1;
            cur2 = head2;
            int n = 0;
            while (cur1 != loop1)
            {
                cur1 = cur1->next;
                n++;
            }
            while (cur2 != loop1)
            {
                cur2 = cur2->next;
                n--;
            }
            cur1 = n > 0 ? head1 : head2;
            cur2 = cur1 == head1 ? head2 : head1;
            n = abs(n);
            while (n != 0)
            {
                n--;
                cur1 = cur1->next;
            }
            while (cur1 != cur2)
            {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return cur1;
        }
        else
        {
            cur1 = loop1->next;
            while (cur1 != loop1)
            {
                if (cur1 == loop2)
                {
                    return loop1;
                }
                cur1 = cur1->next;
            }
            return NULL;
        }
    }
};

int main(int argc, char const *argv[])
{
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);
    head1->next->next->next->next->next->next = new Node(7);

    // 0->9->8->6->7->null
    Node *head2 = new Node(0);
    head2->next = new Node(9);
    head2->next->next = new Node(8);
    head2->next->next->next = head1->next->next->next->next->next; // 8->6
    cout<<Code_14_list::getFistNode(head1, head2)->value<<endl;

    // 1->2->3->4->5->6->7->4...
    head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);
    head1->next->next->next->next->next->next = new Node(7);
    head1->next->next->next->next->next->next = head1->next->next->next; // 7->4

    // 0->9->8->2...
    head2 = new Node(0);
    head2->next = new Node(9);
    head2->next->next = new Node(8);
    head2->next->next->next = head1->next; // 8->2
    cout<<Code_14_list::getFistNode(head1, head2)->value<<endl;

    // 0->9->8->6->4->5->6..
    head2 = new Node(0);
    head2->next = new Node(9);
    head2->next->next = new Node(8);
    head2->next->next->next = head1->next->next->next->next->next; // 8->6
    cout<<Code_14_list::getFistNode(head1, head2)->value<<endl;
    getchar();
    return 0;
}
