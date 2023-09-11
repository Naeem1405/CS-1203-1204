#include <bits/stdc++.h>
using namespace std;

class A{
    private:
        int x;

    protected:
        int y;

    public:
        int z;
};

class B{
    private:
        int p;
    protected:
        int q;
    public:
        int r;
};


class C : public B, public A{
    public:
        void display(){
            // cout << "X: " << x << endl;
            cout << "Y: " << y << endl;
            cout << "Z: " << z << endl;
            // cout << "P: " << p << endl;
            cout << "Q: " << q << endl;
            cout << "R: " << r << endl;

        }

};

main()
{
    C c;
    c.display();
}