#include<bits/stdc++.h>
using namespace std;

template<typename T1, typename T2, typename T> class A{
    private:
        T1 x;
        T2 y;
    public:
        void setData(T1 x, T2 y){
            this->x = x;
            this->y = y;
        }

        T sum(){
            T s;
            s = x+y;
            return s;
        }
};

int main(){
    A<int, int, int> a_int_int;
    A<int, double, double> a_int_double;
    A<double, int, double> a_double_int;
    A<double, double,double> a_double_double;
    
    a_int_int.setData(5,6);
    cout << a_int_int.sum() << endl;

    a_int_double.setData(5,6.51);
    cout << a_int_double.sum() << endl;

    a_double_int.setData(5.13,6);
    cout << a_double_int.sum() << endl;

    a_double_double.setData(1.123,1241.124);
    cout << a_double_double.sum() << endl; 
    
}