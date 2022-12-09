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
    while (isEmpty())
    {
        s.Push(Pop());
    }
    // pop elements from *this and push into s
    for (int i = s.Pop(); i != 1; i = s.Pop())
    {
        cout << i << " ";
        Push(i);
    }
}

bool Nstack::Remove(Nstack &s, int num)
{
    bool output = false;
    while (isEmpty())
    {
        int temp = Pop();
        if (temp == num)
        {
            output = true;
            break;
        }
        s.Push(Pop());
    }
    for (int i = s.Pop(); i != 1; i = s.Pop())
    {
        Push(i);
    }
    return output;
}

void Nstack::Sort(Nstack &s)
{ // using selection sort
    while (isEmpty())
    {
        for (int i = 0; i < top; i++)
        {
            if (narray[top] > narray[i])
            {
                int temp = narray[top];
                narray[top] = narray[i];
                narray[i] = temp;
            }
        }
        s.Push(Pop());
    }
    for (int i = s.Pop(); i != 1; i = s.Pop())
    {
        Push(i);
    }
}
