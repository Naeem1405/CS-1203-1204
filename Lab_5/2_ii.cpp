#include <bits/stdc++.h>
using namespace std;

class A{
    private:
        int x = 1;

    protected:
        int y = 2;

    public:
        int z = 3;
        int getX(){
            return x;
        }
};

class B: public A{

};

class C : public B{
    public:
        void display(){
            cout << "X: " << getX() << endl;
            cout << "Y: " << y << endl;
            cout << "Z: " << z << endl;

        }

};

main()
{
    C c;
    c.display();
}