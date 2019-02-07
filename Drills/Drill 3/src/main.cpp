#include "std_lib_facilities.h"

int main()
{
    string first_name, best_friend, other_friend;
    char friend_sex = 0;
    int age;

    string intro = "How are you? I am doing well, we are having lovely weather over here.";

    // introduction
    cout << "Enter your name: " << endl;
    cin >> first_name;

    // Best friend
    cout << "What's the name of your best friend?" << endl;
    cin >> best_friend;

    cout << "What's the name of another friend?" << endl;
    cin >> other_friend;

    cout << "Is your other friend male or female? (enter m or f)" << endl;
    cin >> friend_sex;

    // Age

    cout << "How old is your friend?" << endl;
    cin >> age;

    if (age >= 110 or age <= 0){
        simple_error("You're kidding!");
    }

    // Letter

    cout << "Dear " << best_friend << "," << endl;
    cout << intro << endl;

    if (friend_sex == 'm'){
        cout << "If you see " << best_friend << " please ask him to call me." << endl;
    } else if (friend_sex == 'f') {
        cout << "If you see " << best_friend << " please ask her to call me." << endl;
    }

    cout << "I heard you had a birthday and are " << age << " years old." << endl;

    if (age < 12){
        cout << "Next year you will be " << age + 1 << "." << endl;
    } else if(age == 17){
        cout << "Next year you will be able to vote." << endl;
    } else if(age > 70){
        cout << "I hope you are enjoying retirement." << endl;
    }

    cout << endl << "Yours sincerely,"<< endl << endl << first_name << endl;

    keep_window_open();
    return 0;
}
