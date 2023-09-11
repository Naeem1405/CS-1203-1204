#include<bits/stdc++.h>
using namespace std;

// Primary template for A
template<typename T1, typename T2>
class A {
private:
    T1 x;
    T2 y;

public:
    void setData(T1 x, T2 y) {
        this->x = x;
        this->y = y;
    }

    T2 sum() {
        T2 s;
        s = x + y;
        return s;
    }
};

// Partial specialization for A when T1 and T2 are both int
template<>
class A<int, int> {
private:
    int x;
    int y;

public:
    void setData(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int sum() {
        int s;
        s = x + y;
        return s;
    }
};

int main() {
    A<int, int> a_int_int;
    A<int, double> a_int_double;
    A<double, int> a_double_int;
    A<double, double> a_double_double;

    a_int_int.setData(5, 6);
    cout << a_int_int.sum() << endl;

    a_int_double.setData(5, 6.51);
    cout << a_int_double.sum() << endl;

    a_double_int.setData(5.13, 6);
    cout << a_double_int.sum() << endl;

    a_double_double.setData(1.123, 1241.124);
    cout << a_double_double.sum() << endl;

    return 0;
}
