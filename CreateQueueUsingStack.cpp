#include <bits/stdc++.h>
using namespace std;
class Queue
{
    stack<int> st;

public:
    Queue() {}
    void Push(int x)
    {
        /*
            Time Complexity -> O(1)
        */
        st.push(x);
    }
    void Pop()
    {
        /*
            Time Complexity -> O(n)
        */
        if (st.empty())
            return;
        stack<int> tmp;
        while (st.size() > 1)
        {
            tmp.push(st.top());
            st.pop();
        }
        st.pop();
        while (!tmp.empty())
        {
            st.push(tmp.top());
            tmp.pop();
        }
    }
    int Front()
    {
        /*
            Time Complexity -> O(n)
        */
        int result;
        if (st.empty())
            return -1;
        stack<int> tmp;
        while (st.size() > 1)
        {
            tmp.push(st.top());
            st.pop();
        }
        result = st.top();
        while (!tmp.empty())
        {
            st.push(tmp.top());
            tmp.pop();
        }
        return result;
    }
    bool empty()
    {
        return st.empty();
    }
};
int main()
{
    Queue x;
    x.Push(10);
    x.Push(20);
    x.Push(30);
    x.Push(40);
    x.Push(50);
    x.Pop();
    x.Pop();
    while (not x.empty())
    {
        cout << x.Front() << endl;
        x.Pop();
    }

    return 0;
}