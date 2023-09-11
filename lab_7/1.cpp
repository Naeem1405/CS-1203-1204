#include<bits/stdc++.h>
using namespace std;

int main(){
    int i;
    int ax[5] = {10,20,60,40,30};
    cout << "Enter index: ";
    cin >> i;
    try{
        if(i > 4 || i < 0){
            string s =  "out of bound";
            throw s;
        }
        cout << "ax[" << i <<"]=" << ax[i] << endl;

    }

    catch(int i){
        cout << "Index error. Index is: " << i << endl;
    }
    catch(string s){
        cout << s << endl;
    }
    catch(...){
        cout << "Default Exception";
    }
}