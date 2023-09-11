#include<bits/stdc++.h>
using namespace std;

class A
{
protected:
    int ax;

public:
    void setA(int x) { ax = x; }
};
class B : virtual public A
{
protected:
    int bx;

public:
    void setB(int x) { bx = x; }
};
class C : virtual public A
{
protected:
    int cx;

public:
    void setC(int x) { cx = x; }
};
class P : public C, public B
{
public:
    int volume() { return ax * bx * cx; }
};
int main(void)
{
    P p;
    p.setA(2);
    p.setB(3);
    p.setC(4);
    cout <<"volume = "<<p.volume()<<" \n";
}