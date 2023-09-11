#include<bits/stdc++.h>
using namespace std;

int main(){
    string w;
    cin >> w;
    cin.ignore();
    vector<string> t;
    string s;
    int count = 0;
    while(cin >> s && s != "END_OF_TEXT"){
        t.push_back(s);
    }
    for(string a:t){
        for(int i = 0; i < a.size(); i++){
            a[i] = tolower(a[i]);
        }
        if( a == w){
            count++;
        }
    }
    cout << count << "\n";
}