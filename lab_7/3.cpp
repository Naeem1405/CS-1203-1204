#include<bits/stdc++.h>
using namespace std;

int main(){
    array<int, 6> ax{10,60,30,70,20};
    cout << "at_2: " << ax.at(2) << endl;
    cout << "at_front: " << ax.front() << endl;
    cout << "at_back: " << ax.back() << endl;
    ax.fill(14);
    for(auto i:ax){
        cout << i << " ";
    }
    cout << endl;
    cout << "is_empty: " << ax.empty() << endl;
    cout << "size: " << ax.size() << endl;
    cout << "max_size " << ax.max_size() << endl;
    cout << "address_first: " << ax.begin() << endl;
    cout << "address_last: " << ax.end() << endl;
}