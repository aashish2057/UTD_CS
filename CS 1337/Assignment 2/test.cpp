// testing pointers

#include <iostream>

using namespace std;

int main()
{
    int vals[] = {4,7,11}, *valptr;
    valptr = vals;
    valptr++;
    cout << valptr-vals;
}

