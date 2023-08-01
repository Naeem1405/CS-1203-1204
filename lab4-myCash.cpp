#include<bits/stdc++.h>
using namespace std;

void update(){
    cout << "update menu\n";
}
void remove(){
    cout << "remove\n";
}
void sendMoney(){
    cout << "send money" << "\n";
}
void cashIn(){
    cout << "cash in \n";
}
void cashOut(){
    cout << "cash out" << "\n";
}
void payBill(){
    cout << "pay bill" << "\n";
}
void checkBalance(){
    cout << "check balance " << "\n";
}
void history(){
    cout << "history" << "\n";
}
void logout(){
    cout << "logout" << "\n";
}

void Register(){
    cout << "\nregister here\n";
}


void mainMenu(){
    cout << "\nMENU HERE\n";
    cout << "********** MyCash Menu ********" << "\n";
    cout << "1. Update Me" << "\n";
    cout << "2. Remove Me" << "\n";
    cout << "3. Send Money" << "\n";
    cout << "4. Cash-in" << "\n";
    cout << "5. Cash-out" << "\n";
    cout << "6. Pay Bill" << "\n";
    cout << "7. Check Balance" << "\n";
    cout << "8. History" << "\n";
    cout << "9. Logout" << "\n";
    cout << "Enter Your Option (1-9):_" << "\n"; 
    int op;
    cin >> op;
    if( op == 1){
        update();
    }
    else if ( op == 2){
        remove();
    }
    else if ( op == 3){
        sendMoney();
    }
    else if (op == 4){
        cashIn();
    }
    else if ( op == 5){
        cashOut();
    }
    else if ( op == 6){
        payBill();
    }
    else if (op == 7){
        checkBalance();
    }
    else if ( op == 8){
        history();
    }
    else if ( op == 9){
        logout();
    }
    else{
        cout << "Enter valid option.\n";
    }
    mainMenu();
}

void login(){
    cout << "1. Login\n";
    cout << "2. Regiser\n";
    cout << "3. Exit\n";
    cout << "   Enter your opiton:_ ";
    int op;
    cin >> op;
    if( op == 1){
        mainMenu();
    }
    else if( op == 2){
        Register();
    }
    else if ( op == 3){
        return;
    }
    else{
        cout << "Enter valid option.\n";
    }
        login();
    // return;

}

int main(){
    login();
}