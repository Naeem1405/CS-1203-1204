#include <bits/stdc++.h>
using namespace std;

class Test
{
    private:
        int n = 5;

    public:
        Test()
        {
            cout << "construct\n";
        }
        void show()
        {
            cout << "n: " << n << endl; 
        }
        ~Test(){
            cout << "Destruct\n";
        }
};


int main(){
    Test t;
    t.show();
}