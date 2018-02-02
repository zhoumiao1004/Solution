#ifndef A_H
#define A_H

#include <iostream>
using namespace std;

class A
{
public:
    A();
    virtual ~A();

    virtual void disp();
    virtual void disp2();
    virtual void f() {cout << s << endl;}
private:
    string s;
};

#endif // A_H
