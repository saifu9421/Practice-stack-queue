#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};
class myStack
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void push(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        };
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    };

    void pop()
    {
        if (head->next == NULL)
        {
            Node *deleteNode = head;
            head = head->next;
            delete deleteNode;
        }
        else
        {
            Node *deleteNode = tail;
            tail = tail->prev;
            delete deleteNode;
            tail->next = NULL;
        };
    };

    int top()
    {
        return tail->val;
    };

    int size()
    {
        int count = 0;
        Node *tmp = head;
        while (tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        };
        return count;
    };
    bool empty()
    {
        if (size() == 0)
            return true;
        else
            return false;
    };
};

class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void push(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        };
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    };

    void pop()
    {
        if (head->next == NULL)
        {
            Node *deleteNode = head;
            head = head->next;
            delete deleteNode;
        }
        else
        {
            Node *deleteNode = head;
            head = head->next;
            head->prev = NULL;
            delete deleteNode;
        };
    };

    int top()
    {
        return head->val;
    };

    int size()
    {
        int count = 0;
        Node *tmp = head;
        while (tmp != NULL)
        {
            /* code */
            count++;
            tmp = tmp->next;
        };
        return count;
    };

    bool empty()
    {
        if (size() == 0)
            return true;
        else
            return false;
    };
};

int main()
{
    myStack st;
    myQueue qu;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    };
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        qu.push(val);
    }

    bool flag = true;
    if (st.size() != qu.size())
    {
        flag = false;
    }
    else
    {
        while (st.empty() == false && qu.empty() == false)
        {
            if (st.top() != qu.top())
            {
                flag = false;
                break;
            };
            st.pop();
            qu.pop();
        }
    };

    if (flag == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}