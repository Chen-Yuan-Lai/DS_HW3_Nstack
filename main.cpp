#include <iostream>
#include "Nstack.h"
using namespace std;

int main()
{
    int input;
    Nstack n;
    while (1)
    {
        cout << "Input a positive integer (-1 to end): ";
        cin >> input;
        if (input == -1)
            break;

        n.Push(input);
    }
    int option;
    Nstack temp;
    while (1)
    {
        cout << "Option: 1) Output. 2) Remove. 3) Sort. 4) Quit: ";
        cin >> option;
        if (option == 1)
        {
            n.Output(temp);
        }
        else if (option == 2)
        {
            int re;
            cout << "Number to remove: ";
            cin >> re;
            if (!n.Remove(temp, re))
            {
                cout << "Not found!" << endl;
                continue;
            }
            cout << re << " is deleted!" << endl;
            n.Output(temp);
        }
        else if (option == 3)
        {
            n.Sort(temp);
            n.Output(temp);
        }
        else if (option == 4)
        {
            cout << "Exit program!" << endl;
            break;
        }
    }
    return 0;
}