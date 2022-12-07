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
    if (top = size - 1)
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
    for (int i = 0; i <= top; i++)
    {
        cout << narray[i] << "  ";
    }
    cout << endl;
}
