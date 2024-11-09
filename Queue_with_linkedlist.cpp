#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = 0;
    }
};
class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = 0;
        tail = 0;
    }
    void Enque(int val)
    {
        int size = 0;
        Node *newnode = new Node(val);
        if (head == 0)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        size++;
    }
    void Deque()
    {
        if (head == 0)
        {
            cout << "Underflow" << endl;
            return;
        }
        Node *tmp = head;
        head = head->next;
        tmp->next = 0;
        delete tmp;
    }
    bool isEmpty()
    {
        return head == 0;
    }
    // Print the last element
    int front()
    {
        if (head == 0)
            return -1;
        return head->data;
    }
    int Rear()
    {
        if (head == 0)
            return -1;
        return tail->data;
    }
};
int main()
{
    Queue s;
    s.Enque(1);
    s.Enque(3);
    s.Enque(4);
    s.Enque(5);
    cout << s.Rear() << endl; // Print the last element
    s.Deque();
    s.Enque(13);
    while (!s.isEmpty())
    {
        cout << s.front() << endl;
        s.Deque();
    }
    //  cout<<"the size of the queue is "<<x;
}