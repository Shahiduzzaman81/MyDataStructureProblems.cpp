#include <bits/stdc++.h>
using namespace std;
class Node
{
    int data;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        next = 0;
    }
    friend class Cq;
};
class Cq
{
    int cnt;
    Node *front;
    Node *rear;

public:
    Cq()
    {
        cnt = 0;
        front = 0;
        rear = 0;
    }
    void enque(int val)
    {
        Node *newnode = new Node(val);
        if (front == nullptr)
        { 
            front = rear = newnode;
            rear->next = front; 
        }
        else
        {
            rear->next = newnode; 
            rear = newnode;      
            rear->next = front;   
        }
        cnt++;
    }
    void deque()
    {
        if (front == 0 && rear == 0)
            cout << "Underflow" << endl;
        else if (front == rear)
        {
            front = 0;
            rear = 0;
           // delete front;
            cnt--;
        }
        else
        {
            Node *tmp = front;
            front = front->next;
            tmp->next = 0;
            rear->next = front;
            delete tmp;
            cnt--;
        }
    }
    void display()
    {
        Node *tmp = front;
        if (front == NULL)
            cout << "Empty Queue" << endl;
        for (int i = 0; i < cnt; i++)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
};
int main()
{
    Cq ll;
    ll.enque(10);
    ll.enque(20);
    ll.enque(30);
    ll.enque(40);
    ll.deque();
    ll.display();
    return 0;
}