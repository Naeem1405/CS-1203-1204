#include<bits/stdc++.h>
using namespace std;

class Add{
    int x = 5, y = 20;
    public:
    virtual void d(){
        cout << "BASE " << x + y<< endl;
    }
    void s(){
        cout << "show base\n";
    }
};

class sub:public Add{
    int y = 10, z = 30;
    public:
    void d(){
        cout << "derived " << y-z<< endl;
    }
    void s(){
        cout << "show derived\n";
    }
};



int main(){
    Add *m;
    sub s;
    m =&s;
    m->d();
    m->s();
}