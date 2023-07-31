#include<bits/stdc++.h>
using namespace std;

struct Member{
    int id;
    float height;
    float weight;
    bool exist;
};

struct Member mx[10000];
int total = -1;

int menu (){
    int op;
    cout << "\n********** Main Menu ********\n";
    cout << "   1. Add Member\n";
    cout << "   2. Update Member\n";
    cout << "   3. Remove Member\n";
    cout << "   4. Max Height & Weight\n";
    cout << "   5. Min Height and Weight\n";
    cout << "   6. Average Height and Weight\n";
    cout << "   7. BMI Classification\n";
    cout << "   8. Display all members\n";
    cout << "   0. Exit\n";
    cout << "      Enter Your option(1-8):_ ";
    cin >> op;
    return op;
}

int searchMember(int id){
    for(int i = 0; i < total; i++){
        if(mx[i].id == id){
            return i;
        }
    }
    return -1;

}
void addMember(){
    total++;
    cout << "Enter Member ID: ";
    int id;
    cin >> id;
    int idx = searchMember(id);
    if(idx == -1){
        mx[total].id = id;
    }
    else{
        cout << "Duplicate id detected.Enter different ID: ";
        addMember();
        return;
    }

    cout << "Height: ";
    cin >>mx[total].height;
    cout << "Weight: ";
    cin >>mx[total].weight;
    mx[total].exist = true;



}
void updateMember(){
    

}
void deleteMember(){
    int id;
    cout << "Member id: ";
    cin >> id;
    int index = searchMember(id);
    if( index == -1){
        cout << "No member with id " << id << "\n";
    }
    else{
        mx[index].exist = false;
        cout << "Member Deleted.\n";
    }

}
void displayMember(){
        cout << "SL\tID\tHeight\tWeight\n";
    for(int i = 0; i <= total; i++){
        if(mx[i].exist == true){
            cout << i + 1 << "\t" << mx[i].id << "\t" << mx[i].height << "\t" << mx[i].weight << "\n";
        }
    }

}
void maxHeightWeight(){

}
void minHeightWeight(){

}
void avgHeightWeight(){

}
void bmiClass(){

}






int main(){
    
    int option;
    while(1){
        option = menu();
        if(option == 0){
            cout << "End of program run....\n";
            break;
        }
        switch(option){
            case 1: addMember();break;
            case 2: updateMember();break;
            case 3: deleteMember();break;
            case 4: maxHeightWeight();break;
            case 5: minHeightWeight();break;
            case 6: avgHeightWeight();break;
            case 7: bmiClass(); break;
            case 8: displayMember();break;
        }
    }
}