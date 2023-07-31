#include<bits/stdc++.h>
using namespace std;

class circle{
    private:
        int radius ;
    public:
        int test;
        void setRadius(int r){
            radius = r;
        }
        int getRadius(){
            return(radius);
        }
        float getArea(){
            return ( 3.1416 * radius * radius);
        }

};

int main(){
    circle c;
    int x;
    cin >> x;
    c.setRadius(x);

    cout <<"radius: " << c.getRadius() << "\n";
    cin >> c.test;
    cout << "t " << c.test << "\n";
    cout << "area: " << c.getArea() << "\n";
    

}