#ifndef B_H
#define B_H

#include "A.h"
#include <iostream>
using namespace std;

class B : public A
{
public:
    B();
    ~B();

    void disp();
    void disp2();
    void f() {cout << s << endl;}
private:
    string s;
};

#endif // B_H
