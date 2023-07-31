#include<bits/stdc++.h>
using namespace std;

struct Member
{
    int id;
    float height;
    float weight;
};

void add_member(vector<Member> &users,int &member_count){
    struct Member temp;
    while(1){
        bool dup_id = false;
        cout << "Member ID: ";
        cin >> temp.id;
        for(int i = 0; i < member_count ; i++){
            if(users[i].id == temp.id){
                cout << "Enter different ID.\n";
                dup_id = true;
                break;
            }
        }
        if(dup_id == false){
            break;
        }
    }

    cout << "\nHeight: ";
    cin >> temp.height;
    cout << "\nWeight: ";
    cin >> temp.weight;
    cout<< "\n";
    users.push_back(temp);
    cout << "member added ";
    cout << users[member_count].id;
    member_count++; 
}

void update_member(vector<Member> &users,int &member_count){
    cout << "Member ID: ";
    int id ;
    cin >> id;
    for(int i = 0; i < member_count; i++){
        if(users[i].id == id){
            cout << "\nHeight: ";
            cin >> users[i].height;
            cout << "\nWeight: ";
            cin >> users[i].weight;
            cout<< "\n";
            break;
        }
    }
}

void remove_member(vector<Member> &users,int &member_count){
    cout << "Member ID: ";
    int id;
    cin >> id;
    for(int i = 0; i < member_count; i++){
        if(users[i].id == id){
            users.erase(users.begin() + i);
            member_count--;
            cout << "Member Removed.\n";
            break;

        }
    }
}

void max_h_w(vector<Member> &users,int &member_count){
    float max_height =  INT_MIN;
    float max_weight = INT_MIN;
    for(int i = 0; i < member_count; i++){
        if( users[i].height > max_height){
            max_height = users[i].height;
        }
        if(users[i].weight > max_weight){
            max_weight = users[i].weight;
        }
    }
    if(member_count == 0){
        cout << "No data available\n";
    }
    else{
        cout << "Max Height: " <<  max_height << endl;
        cout << "Max Weight: " <<  max_weight << endl;
    }
    
}

void min_h_w(vector<Member> &users,int &member_count){
    float min_height =  INT_MAX;
    float min_weight = INT_MAX;
    for(int i = 0; i < member_count; i++){
        if( users[i].height < min_height){
            min_height = users[i].height;
        }
        if(users[i].weight < min_weight){
            min_weight = users[i].weight;
        }
    }
    if(member_count == 0){
        cout << "No data available\n";
    }
    else{
     
        cout << "Min Height: " <<  min_height << endl;
        cout << "Min Weight: " <<  min_weight << endl;
    }
}
void avg_h_w(vector<Member> &users,int &member_count){
    float height_total = 0;
    float weight_total = 0;
    for(int i = 0; i < member_count; i++){
        height_total += users[i].height;
        weight_total += users[i].weight;
    }
    if(member_count == 0){
        cout << "No data available\n";
    }
    else{
        cout << "Avg Height: " <<  height_total/member_count << endl;
        cout << "Avg Weight: " <<  weight_total/member_count << endl;
    }
}

void bmi_class(vector<Member> &users,int &member_count){
    int id;
    cout << "Member ID: ";
    cin >> id;
    bool mem_found = false;
    for(int i = 0; i < member_count; i++){
        if(users[i].id == id){
            float BMI = users[i].weight / ( users[i].height * users[i].height);
            cout << "BMI: " << BMI<< endl;

            if(BMI < 16){
                cout << "Classification: Severe Thinness" << endl;
                mem_found = true;
            }

            else if(BMI < 17){
                cout << "Classification: Moderate Thinness" << endl;
                mem_found = true;
            }
            else if(BMI < 18.5){
                cout << "Classification: Mild Thinness" << endl;
                mem_found = true;
            }

            else if(BMI <25){
                cout << "Classification: Normal" << endl;
                mem_found = true;
            }
            else if(BMI < 30){
                cout << "Classification: Overweight" << endl;
                mem_found = true;
            }
            else if( BMI < 35){
                cout << "Classification: Obese Class I" << endl;
                mem_found = true;
            }
            else if( BMI < 40){
                cout << "Classification: Obese Class II" << endl;
                mem_found = true;
            }
            else if(BMI >= 40){
                cout << "Classification: Obese Class III" << endl;
                mem_found = true;
            }

            break;
        }
        if(mem_found == false){
            cout << "No member with id : " << id << endl;
        }
    }
}
int main(){
    vector<struct Member> users;
    int member_count = 0;

    while(1){
        // Menu
        cout << "\n********** Main Menu ********\n";
        cout << "   1. Add Member\n";
        cout << "   2. Update Member\n";
        cout << "   3. Remove Member\n";
        cout << "   4. Max Height & Weight\n";
        cout << "   5. Min Height and Weight\n";
        cout << "   6. Average Height and Weight\n";
        cout << "   7. BMI Classification\n";
        cout << "   8. Exit\n";
        cout << "      Enter Your option(1-8):_ ";
        int input;
        cin >> input;

        if( input == 1){
            add_member(users, member_count);
        }

        else if( input == 2){
            update_member(users, member_count);
        }
        else if( input == 3){
            remove_member(users, member_count);
        }
        else if( input == 4){
            max_h_w(users, member_count);
        }
        else if( input == 5){
            min_h_w(users, member_count);
        }
        else if( input == 6){
            avg_h_w(users, member_count);
        }
        else if(input == 7){
            bmi_class(users, member_count);
        }
        else if(input = 8){
            break;
        }
        else{
            cout << "Enter valid option\n";
        }

    }

}