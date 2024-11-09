 /*
    Priority Queue Using LinkedList
 */
#include <bits/stdc++.h>
using namespace std;
class Node
{
    int data;
    int prior;
    Node *next;

public:
    Node(int val, int pval)
    {
        data = val;
        prior = pval;
        next = 0;
    }
    friend class pc;
};
class pc
{
    Node *head;

public:
    pc()
    {
        head = 0;
    }
    void enque(int val, int pval)
    {
        Node *newnode = new Node(val, pval);
        newnode->next = 0;
        if (head == 0)
        {
            head = newnode;
            head->next = 0;
        }
        else if (head->prior < newnode->prior)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            Node *tmp = head;
            while (tmp->next != 0 && tmp->next->prior > newnode->prior)
            {
                tmp = tmp->next;
            }
            newnode->next = tmp->next;
            tmp->next = newnode;
        }
    }
    // void display()
    // {
    //     Node *tmp = head;
    //     while (tmp != 0)
    //     {
    //         cout << tmp->data << " ";
    //         tmp = tmp->next;
    //     }
    // }
    void deque()
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
    int front()
    {
        return head->data;
    }
    bool isempty()
    {
        return head == 0;
    }
};
int main()
{

    pc a;
    a.enque(10, 6);
    a.enque(15, 5);
    a.enque(16, 3);
    a.enque(9, 4);

    // a.display();
    while (!a.isempty())
    {
        cout << a.front() << " ";
        a.deque();
    }
}