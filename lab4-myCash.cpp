#include<bits/stdc++.h>
using namespace std;

int user_count = -1;
int current_user_idx = -1;


bool verifyOTP();

class Member{
    private:
        string phone;
        string name;
        string pin;
        double balance;
        bool is_active;
    
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
            is_active = true;
        }
        
        bool checkStatus(){
            return is_active;
        }

        void printMember(){
            cout << "Phone: " << phone << "\n";
            cout << "Name: " << name << "\n";
            cout << "PIN: " << pin << "\n";
            cout << "Balance : " << balance << "\n";
            cout << "status : " << is_active << "\n";
        }

        void checkBalance(){
            cout << "Current Balance: " << balance << "\n";
        }

        void logout(){
            // cout << "logout" << "\n";
            logged_in = false;
            current_user_idx = -1;
            cout << "Successfully Logged out.\n";

        }

        void update(){
            char op;
            cout << "Do you want to update name? :_ ";
            cin >> op;
            if( op == 'y'){
                cout << "Name: ";
                cin >> name;
                cout << "Name successfully changed.\n";
            }
            cout << "Do you want to update pin? :_ ";
            cin >> op;
            if( op == 'y'){
                string npin, npin2;
                cout << "New pin: ";
                cin >> npin;
                cout << "Retype new pin: ";
                cin >> npin2;
                if( npin == npin2 ){
                    bool otp_verify = verifyOTP();
                    if( otp_verify){
                        pin = npin;
                        cout << "Pin successfully updated.\n";
                    }
                    else{
                        cout << "Incorrect OTP.\n";
                    }
                }
                else{
                    cout << "Pin doesn't match.\n";
                }
                
            }


        }

        bool remove(){
            string upin;
            cout << "Enter your pin: ";
            cin >> upin;
            if( pin == upin){
                bool otp_verify = verifyOTP();
                if(otp_verify){
                    is_active = false;
                    return true;
                }
                else{
                    cout << "OTP doesn't match.\n";
                }
            }
            else{
                cout << "Pin doesn't match.\n";
            }

            return false;

        }
        
};


Member users[1000];


int searchMember(string phone){
    for(int i = 0; i <= user_count; i++){
        if(users[i].getPhone() == phone && users[i].checkStatus()){
            return i;
        }

    }
    return -1;
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
void history(){
    cout << "history" << "\n";
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
        users[current_user_idx].update();
    }
    else if ( op == 2){
        bool removed = users[current_user_idx].remove();
        if (removed){
            users[current_user_idx].logout();
            return;
        }
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
        users[current_user_idx].checkBalance();
    }
    else if ( op == 8){
        history();
    }
    else if ( op == 9){
        users[current_user_idx].logout();
        return;
    }
    else{
        cout << "Enter valid option.\n";
    }
    mainMenu();
    return;
}


bool loginMenu(){
    string phone, pin;
    cout << "Phone: ";
    cin >> phone;
    int idx = searchMember(phone);
    if( idx == -1){
        cout << "No user found\n";
    }
    else{
        string pin;
        cout << "Enter pin for account: " << phone << ":\n";
        cin >> pin;
        if( pin == users[idx].getPin()){
            users[idx].logged_in = true;
            current_user_idx = idx;
            return true;
        }
        else{
            cout << "Wrong pin. Try again.\n";
        }
    }

    return false;
}


int login(){
    cout << "1. Login\n";
    cout << "2. Regiser\n";
    cout << "3. Exit\n";
    cout << "   Enter your opiton:_ ";
    int op;
    cin >> op;
    return op;
}

// end of MENU
int main(){

    while(1){
        int op = login();
        if( op == 1){
            bool logged_in = loginMenu();
            if( logged_in ){
                mainMenu();
            }
            else{
                
            }
        }
        else if( op == 2){
            Register();
        }
        else if ( op == 3){
            break;
        }
        else{
            cout << "Enter valid option.\n";
        }
    
    }

    for(int i = 0; i <= user_count ;i++){
        users[i].printMember();
    }
}