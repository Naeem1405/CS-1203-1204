#include<bits/stdc++.h>
using namespace std;


class Member{
    private:
        string phone;
        string name;
        string pin;
        double balance;
    
    public:
        bool logged_in = false;
        string getPhone(){
            return phone;
        }
        string getPin(){
            return pin;
        }
        void setMember(string _phone, string _name,string _pin){
            phone = _phone;
            name = _name;
            pin = _pin;
            balance = 0;
        }

        void printMember(){
            cout << "Phone: " << phone << "\n";
            cout << "Name: " << name << "\n";
            cout << "PIN: " << pin << "\n";
            cout << "Balance : " << balance << "\n";
        }

        
};

int user_count = -1;
Member users[1000];
int current_user_idx = -1;

void login();

int searchMember(string phone){
    for(int i = 0; i <= user_count; i++){
        if(users[i].getPhone() == phone ){
            return i;
        }

    }
    return -1;
}

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
    users[current_user_idx].logged_in = false;
    current_user_idx = -1;
    cout << "Successfully Logged out.\n";
    login();


}

bool verifyOTP(){
    srand(time(0));
    int lb = 1000;
    int ub = 10000;
    int otp = rand() % (ub - lb + 1) + lb;
    cout << "myCash OTP: "<< otp << "\n";
    cout << "Enter OTP: ";
    int otp2;
    cin >> otp2;
    if( otp == otp2){
        return true;
    }

    return false;
}

int getPin(){
    string pass = "";
    char ch;
    ch = getchar();
    while(ch != 13){
        // getchar => getch
        pass.push_back(ch);
        cout << "*";
        ch = getchar();
    }
    cout << "\n";
    return (stoi(pass));
}


void Register(){
    // cout << "\nregister here\n";
    string phone, pin, pin2, name;
    cout << "Phone: ";
    cin >> phone;
    int idx = searchMember(phone);
    if( idx == -1){
        cout << "Enter name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        cout << "Enter pin: ";
        cin >> pin;
        cout << "Reconfirm pin: ";
        cin >> pin2;
        if(pin == pin2){
            bool otp_verity = verifyOTP();
            if(otp_verity == true){
                user_count++;
                users[user_count].setMember(phone, name, pin);
                cout << "Registration completed.\n";

            }
            else{
                cout << "OTP doesn't match. Try Again.\n";
                Register();
            }
        }
        else{
            cout << "Pin doesn't match. Try again.\n";
            Register();
        }

    }
    else{
        cout << "Another user with this phone number exists. User another phone number or log in . \n";
        login();
    }

    
}

// MENU
void mainMenu(){
    // cout << "\nMENU HERE\n";
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
        return;
    }
    else{
        cout << "Enter valid option.\n";
    }
    mainMenu();
    return;
}


void loginMenu(){
    string phone, pin;
    cout << "Phone: ";
    cin >> phone;
    int idx = searchMember(phone);
    if( idx == -1){
        cout << "No user found\n";
        login();
    }
    else{
        string pin;
        cout << "Enter pin for account: " << phone << ":\n";
        cin >> pin;
        if( pin == users[idx].getPin()){
            users[idx].logged_in = true;
            current_user_idx = idx;
            mainMenu();
        }
        else{
            cout << "Wrong pin\n. Try again.\n";
            loginMenu();
        }
    }

    return;


}


void login(){
    cout << "1. Login\n";
    cout << "2. Regiser\n";
    cout << "3. Exit\n";
    cout << "   Enter your opiton:_ ";
    int op;
    cin >> op;
    if( op == 1){
        loginMenu();
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
    return;

}

// end of MENU
int main(){

    login();
    for(int i = 0; i <= user_count ;i++){
        users[i].printMember();
    }
}