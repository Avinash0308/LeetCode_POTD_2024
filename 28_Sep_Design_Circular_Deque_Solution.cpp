#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int v)
    {
        data = v;
        next = prev = NULL;
    }
};
class MyCircularDeque
{
    Node *f, *l;
    int cap, len;

public:
    MyCircularDeque(int k)
    {
        cap = 0;
        len = k;
        f = l = NULL;
    }

    bool insertFront(int value)
    {
        if (cap == len)
            return false;
        Node *t = new Node(value);
        t->next = f;
        t->prev = NULL;
        if (!cap)
        {
            f = l = t;
        }
        else
        {
            t->next->prev = t;
            f = t;
        }
        cap++;
        return true;
    }

    bool insertLast(int value)
    {
        if (cap == len)
            return false;
        Node *t = new Node(value);
        if (l)
        {
            l->next = t;
            t->prev = l;
            l = t;
        }
        else
        {
            f = l = t;
        }
        cap++;
        return true;
    }

    bool deleteFront()
    {
        if (cap == 0)
            return false;
        f = f->next;
        cap--;
        if (cap == 0)
            f = l = NULL;
        else
            f->prev = NULL;
        return true;
    }

    bool deleteLast()
    {
        if (cap == 0)
            return false;
        l = l->prev;
        cap--;
        if (cap)
        {
            l->next = NULL;
        }
        else
        {
            f = l = NULL;
        }
        return true;
    }

    int getFront()
    {
        if (cap == 0)
            return -1;
        return f->data;
    }

    int getRear()
    {
        if (cap == 0)
            return -1;
        return l->data;
    }

    bool isEmpty()
    {
        return cap == 0;
    }

    bool isFull()
    {
        return cap == len;
    }
};

int main()
{
    return 0;
}