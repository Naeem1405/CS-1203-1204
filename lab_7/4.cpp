#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<int, string>ax;
    ax = make_pair(10, "Rajshahi");
    cout << "first: " << ax.first << endl;
    cout << "second: " << ax.second << endl;
    get<0>(ax) = 20;
    cout << "modified_first: " << ax.first << endl;
    pair<int, string>bx;
    bx = make_pair(50, "Dhaka");
    ax.swap(bx);
    cout << ax.first << " " << ax.second << endl;
}