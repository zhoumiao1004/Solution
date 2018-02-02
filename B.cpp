#include "B.h"

B::B()
{
    cout << "B constructor" << endl;
    s = "B";
}

B::~B()
{
    cout << "B desstructor" << endl;
}


void B::disp()
{
    cout << "B::disp" << endl;
}

void B::disp2()
{
    cout << "B::disp2" << endl;
}
