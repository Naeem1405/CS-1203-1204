#include<bits/stdc++.h>
using namespace std;

class Father{
    private:
        int money = 1 ;
    protected:
        int gold = 2 ;
    public:
        int land = 3;
};

class Son:protected Father{
    public:
        void display(){
            // cout <<"Son: "<< money << endl;
            cout <<"Son: "<< gold << endl;
            cout <<"Son: "<< land << endl;
            
        }

};

class GrandSon:private Son{
    public:
        void display(){
            // cout <<"Grand Son: "<<  money << endl;
            cout <<"Grand Son: "<< gold << endl;
            cout <<"Grand Son: "<< land << endl;
            
        }
};

int main(){
    Father f;
    Son s;
    GrandSon g;
    s.display();
    g.display();

    
}