#include<bits/stdc++.h>
using namespace std;

class A{
    private:
        int x;
    protected:
        int y;
    public:
        int z;
};

class B: public A{
    public:
    void display(){
        // cout << "X " << x << endl;
        cout << "Y " << y << endl;
        cout << "Z " << z << endl;
    }
};

class C:public A{
    public:
        void display(){
            // cout << "X " << x << endl;
            cout << "Y " << y << endl;
            cout << "Z " << z << endl;
        }
};



int main(){
    B b;
    C c;
    b.display();
    c.display();
    
}