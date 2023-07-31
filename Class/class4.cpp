#include<bits/stdc++.h>
using namespace std;


class A{
    private:
        int x = 10;
    protected:
        int y = 20;
    public:
        int z = 30;
};


class B: protected A{
    public:
        void Display(){

            // cout << "X = " << x << "\n"; 
            cout << "Y = " << y << "\n"; 
            cout << "Z = " << z << "\n"; 
        }
};

int main(){
    A a;
    B b;
    b.Display();
}