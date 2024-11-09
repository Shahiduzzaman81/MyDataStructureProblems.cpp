#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *link;

    Node(int val)
    {
        data = val;
        link = 0;
    }
};
// Add a node at the first
void InsertatFirst(Node *&head, int val)
{
    Node *new_node = new Node(val);
    new_node->link = head;
    head = new_node;
}
// Insert at last in the node
void InsertatLast(Node *&head, int val)
{
    Node *new_node = new Node(val);
    Node *tmp = head;
    while (tmp->link != 0)
    {
        tmp = tmp->link;
    }
    tmp->link = new_node;
    // return;
}
// Insert node at any position
void InsertatPosition(Node *&head, int val, int pos)
{
    if (head == 0)
    {
        InsertatFirst(head, val);
        return;
    }
    Node *new_node = new Node(val);
    Node *tmp = head;
    int cur_node = 0;
    while (cur_node != pos - 1)
    {
        tmp = tmp->link;
        cur_node++;
    }
    new_node->link = tmp->link;
    tmp->link = new_node;
}
// Update the value in certain position
void UpdateValue(Node *head, int k, int val)
{
    Node *tmp = head;
    int cur_pos = 0;
    while (cur_pos != k)
    {
        tmp = tmp->link;
        cur_pos++;
    }
    tmp->data = val;
}
// Delete the first node
void DeleteatFirst(Node *&head)
{
    Node *tmp = head;
    head = head->link;
    delete tmp;
}
int sizeoflist(Node *head)
{
    Node *tmp = head;
    int cnt = 0;
    while (tmp != 0)
    {
        tmp = tmp->link;
        cnt++;
    }
    return cnt;
}
// Delete a node from end of the list
void DeleteatLast(Node *&head)
{
    Node *tmp = head;
    Node *prev;
    while (tmp->link != 0)
    {
        prev = tmp;
        tmp = tmp->link;
    }
    Node *x = prev->link;
    prev->link = 0;
    delete x;
}
void Deleteatcertain(Node *&head, int pos)
{
    if (pos == 0)
    {
        Node *tmp = head;
        head = head->link;
        delete tmp;
        return;
    }
    Node *tmp = head;
    Node *prev;
    int c = 0;
    while (c < pos)
    {
        prev = tmp;
        tmp = tmp->link;
        c++;
    }
    Node *x = prev->link;
    prev->link = tmp->link;
    delete x;
}

// Print the linkedlist
void Print(Node *head)
{
    Node *tmp = head;
    while (tmp)
    {
        cout << tmp->data << " ";
        tmp = tmp->link;
    }
}
int main()
{
    Node *head = 0;
    InsertatFirst(head, 2);
    Print(head);
    cout << endl;
    cout << "Insert at first node" << endl;
    InsertatFirst(head, 1);
    Print(head);
    cout << endl;
    cout << "Insert at Last" << endl;
    InsertatLast(head, 3);
    Print(head);
    cout << endl;
    cout << "Insert at any Position" << endl;
    InsertatPosition(head, 4, 2);
    Print(head);
    cout << endl
         << "Update the k^th position value" << endl;
    UpdateValue(head, 2, 5);
    Print(head);
    cout << endl
         << "Delete at the first node" << endl;
    DeleteatFirst(head);
    Print(head);
    cout << endl
         << "The size of the linkedlist" << endl;
    int x = sizeoflist(head);
    cout << x << endl
         << "Delete the last node" << endl;
    DeleteatLast(head);
    Print(head);
    cout << endl
         << "Delete at a certain position in the linkedlist" << endl;
    InsertatPosition(head, 4, 2);
    InsertatPosition(head, 6, 3);
    Print(head);
    cout << endl
         << "Delete at certain position" << endl;
    Deleteatcertain(head, 0);
    Print(head);
    cout << endl;
    return 0;
}