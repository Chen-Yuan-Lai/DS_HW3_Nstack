#include <iostream>
#include "Nstack.h"
using namespace std;

Nstack::Nstack(int capacity) : size(capacity), top(-1)
{
    narray = new int[size];
}

Nstack::~Nstack()
{
    delete[] narray;
}

void Nstack::Resize()
{
    int *temp = new int[size * 2];
    copy(narray, narray + size, temp);
    size *= 2;
    delete[] narray;
    temp = narray;
}

bool Nstack::isEmpty()
{
    return top == -1;
}

void Nstack::Push(int d)
{
    if (top == size - 1)
    {
        Resize();
    }
    narray[++top] = d;
}

int Nstack::Pop()
{
    if (isEmpty())
        throw "Nstack is empty";
    return narray[top--];
}

void Nstack::Output(Nstack &s)
{
    // pop elements from *this and push into s
    while (!isEmpty())
    {
        s.Push(Pop());
    }
    // pop elements from s and push into *this
    while (!s.isEmpty())
    {
        int temp = s.Pop();
        cout << temp << " ";
        Push(temp);
    }
    cout << endl;
}

bool Nstack::Remove(Nstack &s, int num)
{
    bool output = false;
    // pop elements from *this and push into s
    // until find num in narray
    while (!isEmpty())
    {
        int temp = Pop();
        if (temp == num)
        {
            output = true;
            break;
        }
        s.Push(temp);
    }
    // pop elements from s and push into *this
    while (!s.isEmpty())
    {
        Push(s.Pop());
    }
    return output;
}

void Nstack::Sort(Nstack &s)
{ // sort *this
    while (!isEmpty())
    {
        for (int i = 0; i < top; i++)
        { // compare narray[top] and nrraay[i]
          // is nrray[i] is bigger, swap them
            if (narray[top] < narray[i])
            {
                int temp = narray[top];
                narray[top] = narray[i];
                narray[i] = temp;
            }
        }
        // pop elements from *this and push into s
        s.Push(Pop());
    }
    while (!s.isEmpty())
    { // pop elements from s and push into *this
        Push(s.Pop());
    }
}
