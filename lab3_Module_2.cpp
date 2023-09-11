#include<bits/stdc++.h>
using namespace std;

class Bank{
    private:
        int id;
        float amount;
        static int n;
        static double total;
    public:
        Bank(){
            id = 0;
            amount = 0;
            n++;
        }
        Bank(int _id, float _amount){
            id = _id;
            amount = _amount;
            total += _amount;
            n++;
        }
        Bank(Bank &b){
            id = b.id;
            amount = b.amount;
            total +=b.amount;
            n++;
        }
        void setID_Amount(int _id, float _amount){
            id = _id;
            amount = _amount;
            total += _amount;
        }
        void setID(int _id){
            id = _id;
        }
        void changeAmount(float _amount){
            total-=amount;
            amount = _amount;
            total += _amount;

        }
        void display_n(){
            cout <<"N: " << n << "\n";
        }
        void display_all()const{
            cout << "ID: " << id <<"\n";
            cout << "Amount: " << amount << "\n";
            cout << "N: " << n << "\n"; 
        }
        int getID(){
            return id;
        }
        float getAmount(){
            return amount;
        }
        int get_n(){
            return n;
        }
        
};

int Bank::n = 0;
double Bank::total = 0;


int main(){
    Bank client_1;
    Bank client_2( 2,341.4);
    Bank client_3(client_2);
    Bank client_4(4,4114.1);
    Bank client_5(5,5000);
    client_3.setID(3);
    client_2.changeAmount(241.4);
    
    cout << "Total client: " << client_1.get_n() << "\n";
    cout << "Total amount: " << client_1.getAmount() + client_2.getAmount() + client_3.getAmount() + client_4.getAmount() + client_5.getAmount() << "\n";
    

}