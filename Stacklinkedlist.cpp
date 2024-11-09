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
class Stack
{
    Node *head;
    int capacity;
    int cursize;

public:
    Stack(int c)
    {
        capacity = c;
        cursize = 0;
        head = 0;
    }

    void push(int val)
    {
        if (capacity == cursize)
        {
            cout << "Overflow" << endl;
            return;
        }
        Node *new_node = new Node(val);
        new_node->next = head;
        head = new_node;
        cursize++;
    }
    void pop()
    {
        if (head == 0)
        {
            cout << "Undeflow" << endl;
            return;
        }
        Node *tmp = head;
        head = head->next;
        tmp->next = 0; // Good practise
        delete tmp;
        cursize--;
    }
    int getTop()
    {
        if (head == 0)
        {
            cout << "Underflow" << endl;
            return -1;
        }
        return head->data;
    }
    int size()
    {
        return cursize;
    }
    bool isEmpty(){
        return head == 0;
    }
    bool isFull(){
        return cursize==capacity;
    }
};
int main()
{
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(10);
    cout << st.getTop() << endl;
    st.push(4);
    st.push(5);
    // cout<<st.getTop()<<endl;
    st.pop();
    st.pop();
    cout << st.getTop() << endl;
    // st.pop();
    st.pop();
    cout << st.getTop() << endl;
    cout << st.size() << endl;
    cout<<st.isEmpty()<<endl;
    cout<<st.isEmpty()<<endl;
}