#include <bits/stdc++.h>
using namespace std;

struct Member
{
    int id;
    float height;
    float weight;
};

int main()
{

    vector<struct Member> users;
    int member_count = 0;

    // Menu
    cout << "********** Main Menu ********\n";
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

    if (input == 1)
    {
        cout << "Member ID: ";
        cin >> users[member_count].id;
        cout << "\nHeight: ";
        cin >> users[member_count].height;
        cout << "\nWeight: ";
        cin >> users[member_count].weight;
        cout << "\n";
        member_count++;
    }

    if (input == 2)
    {
        cout << "Member ID: ";
        int id;
        cin >> id;
        for (int i = 0; i < member_count; i++)
        {
            if (users[i].id == id)
            {
                cout << "\nHeight: ";
                cin >> users[i].height;
                cout << "\nWeight: ";
                cin >> users[i].weight;
                cout << "\n";
            }
        }
    }

    if (input == 3)
    {
        cout << "Member ID: ";
        int id;
        cin >> id;
        for (int i = 0; i < member_count; i++)
        {
            if (users[i].id == id)
            {
                for (int j = i; j < member_count; j++)
                {
                    users[i].id = users[j].id;
                    users[i].weight = users[j].weight;
                    users[i].height = users[j].height;
                }
                member_count--;
                cout << "Member Removed.";
                break;
            }
        }
    }

    if (input == 4)
    {
        float max_height = INT_MIN;
        float max_weight = INT_MIN;
        for (int i = 0; i < member_count; i++)
        {
            if (users[i].height > max_height)
            {
                max_height = users[i].height;
            }
            if (users[i].weight > max_weight)
            {
                max_weight = users[i].weight;
            }
        }
        cout << "Max Height: " << max_height << endl;
        cout << "Max Weight: " << max_weight << endl;
    }

    if (input == 5)
    {
        float min_height = INT_MAX;
        float min_weight = INT_MAX;
        for (int i = 0; i < member_count; i++)
        {
            if (users[i].height < min_height)
            {
                min_height = users[i].height;
            }
            if (users[i].weight < min_weight)
            {
                min_weight = users[i].weight;
            }
        }
        cout << "Min Height: " << min_height << endl;
        cout << "Min Weight: " << min_weight << endl;
    }

    if (input == 6)
    {
        float height_sum = 0;
        float weight_sum = 0;
        for (int i = 0; i < member_count; i++)
        {
            height_sum += users[i].height;
            weight_sum += users[i].weight;
        }
        if (member_count == 0)
        {
            cout << "There are no member.";
        }
        else
        {
            cout << "Average Height: " << height_sum / member_count << endl;
            cout << "Average Weight: " << weight_sum / member_count;
        }
    }

    if (input == 7)
    {
        int id;
        cout << "Member ID: ";
        cin >> id;
        for (int i = 0; i < member_count; i++)
        {
            if (users[i].id == id)
            {
                float BMI = users[i].weight / (users[i].height * users[i].height);
                cout << "BMI: " << BMI << endl;
                if (BMI < 16)
                {
                    cout << "Classification: Severe Thinness" << endl;
                }

                if (BMI <= 16 && BMI < 17)
                {
                    cout << "Classification: Moderate Thinness" << endl;
                }
                if (BMI <= 17 && BMI < 18.5)
                {
                    cout << "Classification: Mild Thinness" << endl;
                }

                if (BMI <= 18.5 && BMI < 25)
                {
                    cout << "Classification: Normal" << endl;
                }
                if (BMI <= 25 && BMI < 30)
                {
                    cout << "Classification: Overweight" << endl;
                }
                if (BMI <= 30 && BMI < 35)
                {
                    cout << "Classification: Obese Class I" << endl;
                }
                if (BMI <= 35 && BMI < 40)
                {
                    cout << "Classification: Obese Class II" << endl;
                }
                if (BMI >= 40)
                {
                    cout << "Classification: Obese Class III" << endl;
                }
            }
        }
    }
}