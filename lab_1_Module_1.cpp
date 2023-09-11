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
    cout << "      Enter Your option(0-8):_ ";
    cin >> op;
    return op;
}

int searchMember(int id){
    for(int i = 0; i <= total; i++){
        if(mx[i].id == id){
            return i;
        }
    }
    return -1;

}
void addMember(){
    cout << "Enter Member ID: ";
    int id;
    cin >> id;
    int idx = searchMember(id);
    if(idx == -1){
        total++;
        mx[total].id = id;
    }
    else{
        cout << "Duplicate id detected.Enter different ID.\n";
        return;
    }

    cout << "Height: ";
    cin >>mx[total].height;
    cout << "Weight: ";
    cin >>mx[total].weight;
    mx[total].exist = true;
    return;
}

void updateMember(){
    int id;
    cout << "Enter Member ID: ";
    cin>> id;
    int idx = searchMember(id);
    if( idx == -1){
        cout << "Member Doesn't exist.\n";
    }
    else{
        cout << "Height: ";
        cin >>mx[idx].height;
        cout << "Weight: ";
        cin >>mx[idx].weight;
        cout << "Updated successfully.\n";
    }
    return;
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
    return;

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
    float max_h = 0;
    float max_w = 0;
    for(int i = 0; i <= total; i++){
        if( mx[i].exist == true){
            max_h = max(max_h,mx[i].height);
            max_w = max(max_w,mx[i].weight);
        }
    }
    cout << "Max Height: " << max_h << "\n";
    cout << "Max Weight: " << max_w << "\n";
    return;
}
void minHeightWeight(){
    float min_h = 10000;
    float min_w = 10000;
    for(int i = 0; i <= total; i++){
        if( mx[i].exist == true){
            min_h = min(min_h,mx[i].height);
            min_w = min(min_w,mx[i].weight);
        }
    }
    cout << "Min Height: " << min_h << "\n";
    cout << "Min Weight: " << min_w << "\n";
    return;
}
void avgHeightWeight(){
    float avg_h = 0;
    float avg_w = 0;
    int count  = 0;
    for(int i = 0; i <= total; i++){
        if(mx[i].exist == true){
            count++;
            avg_h += mx[i].height;
            avg_w += mx[i].weight;
        }
    }
    cout << "Average Height: " << avg_h / count << "\n";
    cout << "Average Weight: " << avg_w / count << "\n";
    return;
}

void bmiClass(){
    int id;
    cout << "Member ID: ";
    cin >> id;
    int idx = searchMember(id);
    if( idx == -1){
        cout << "No member found\n";
    }
    else{
        float BMI = mx[idx].weight / (mx[idx].height * mx[idx].height);
        cout << "BMI: " << BMI << endl;
        if (BMI < 16)
            cout << "Classification: Severe Thinness" << endl;
        else if (BMI >= 16 && BMI < 17)
            cout << "Classification: Moderate Thinness" << endl;
        else if (BMI >= 17 && BMI < 18.5)
            cout << "Classification: Mild Thinness" << endl;
        else if (BMI >= 18.5 && BMI < 25)
            cout << "Classification: Normal" << endl;
        else if (BMI >= 25 && BMI < 30)
            cout << "Classification: Overweight" << endl;
        else if (BMI >= 30 && BMI < 35)
            cout << "Classification: Obese Class I" << endl;
        else if (BMI >= 35 && BMI < 40)
            cout << "Classification: Obese Class II" << endl;
        else if (BMI >= 40)
            cout << "Classification: Obese Class III" << endl;
    }
    return;
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
