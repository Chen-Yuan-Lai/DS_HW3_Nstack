#ifndef NSTACK_H
#define NSTACK_H

class Nstack
{
public:
    Nstack(int = 10);
    ~Nstack();
    void Push(int d);
    int Pop();
    bool isEmpty();
    void Output(Nstack &s);
    // print all the element in s
    bool Remove(Nstack &s, int num);
    // remove the element which is eaqual to num,
    // if not return false and print "not found"

    void Sort(Nstack &s);

private:
    void Resize();
    int top, size;
    int *narray;
};
#endif