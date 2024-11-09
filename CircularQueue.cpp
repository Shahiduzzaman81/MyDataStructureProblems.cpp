// Circular Queue
#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int data;
    int front;
    int back;
    int ts;
    int cs;
    vector<int> v;
    // int n;
public:
    Queue(int n)
    {
        v.resize(n);
        front = 0;
        back = n - 1;
        cs = 0;
        ts = n;
    }
    void Enque(int val)
    {
        if (isFull())
            return;
        back = (back + 1) % ts;
        v[back] = val;
        //  back++;
        cs++;
    }
    void Deque()
    {
        if (isEmpty())
            return;
        front = (front + 1) % ts;
        cs--;
    }
    int getFront()
    {
        if (isEmpty())
            return -1;
        return v[front];
    }
    bool isFull()
    {
        return cs == ts;
    }
    bool isEmpty()
    {
        return cs == 0;
    }
};
int main()
{
    Queue qu(4);
    qu.Enque(10);
    qu.Enque(20);
    qu.Enque(30);
    qu.Enque(40);
    qu.Deque();
    qu.Deque();
    qu.Enque(60);
    qu.Enque(70);
    qu.Enque(80); // Out of Size
    // qu.Enque(400);
    while (!qu.isEmpty())
    {
        cout << qu.getFront() << endl;
        qu.Deque();
    }

    return 0;
}