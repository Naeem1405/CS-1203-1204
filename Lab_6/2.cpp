#include<bits/stdc++.h>
using namespace std;

class Circuit{
    private:
        int real;
        int img;
    public:
        Circuit(){
            real = 0;
            img = 0;
        }
        Circuit(int r, int i){
            real = r;
            img = i;
        }
        Circuit operator+(Circuit const &c){
            Circuit result;
            result.img = img + c.img;
            result.real = real + c.real;
            return result;
        }
        Circuit reci(Circuit c){
            int d = (c.img * c.img) + (c.real * c.real);
            c.img = c.img / d;
            c.real = c.real/d;
            return c;
            
        }
        Circuit operator*(Circuit const &c){
            Circuit r;
            r.real = (real*c.real) - (img * c.img);
            r.img = (img * c.real) + (real * c.img);
            return r;
        }
        Circuit operator/(Circuit const &c){
            Circuit result, a,b;
            a = reci()

        }
        void show(){
            cout << real << " i" << img << "\n";
        }

};

int main(){
    Circuit z1(3,4), z2(4,-3) , z3(0,6);
    Circuit V(100,50);
    Circuit z = z1 + z2 + z3;
    Circuit I = V/z;
    I.show();


    
}