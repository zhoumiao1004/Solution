#include "A.h"

A::A()
{
    cout << "A constructor" << endl;
    s = "A";
}

A::~A()
{
    cout << "A destructor" << endl;
}


void A::disp()
{
    cout << "A::disp" << endl;
}

void A::disp2()
{
    cout << "A::disp2" << endl;
}
