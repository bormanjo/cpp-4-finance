#include "std_lib_facilities.h"

/*
 * John-Craig Borman - "I pledge my honor that I have abided by the Stevens Honor System"
 *
 * The purpose of this code is to read (day-of-week, value) pairs and produce a summary of
 * values summed by the day-of-week.
 *
 */


vector<string> monday = {"monday", "mon"};
vector<string> tuesday = {"tuesday", "tues"};
vector<string> wednesday = {"wednesday", "wed"};
vector<string> thursday = {"thursday", "thurs"};
vector<string> friday = {"friday", "fri"};
vector<string> saturday = {"saturday", "sat"};
vector<string> sunday = {"sunday", "sun"};

vector<vector <string> > days_of_week = {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

vector<vector<int> > day_of_week_vals = {{}, {}, {}, {}, {}, {}, {}};
vector<int> day_of_week_sum = {0, 0, 0, 0, 0, 0, 0};

vector<string> day_of_week = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

vector<string> rejected = {};

bool debug = false; // Change to true if desired

int get_day_of_week(string day){
    // Returns an integer representing 0 - monday, 1 - tuesday, ..., 5 - saturday, 6 - sunday

    int loc = 0;

    // Transform day, inplace, to lowercase
    transform(day.begin(), day.end(), day.begin(), ::tolower);

    // For each valid day-of-the-week string in days-of-week
    for (auto &d : days_of_week) {

        // search for matching day
        if(find(d.begin(), d.end(), day) != d.end()){
            // found matching day, return the index
            return loc;
        } else {
            // no matching day for current day, increment index to next day
            loc++;
        }
    }

    // no days matched, failed.
    return -1;
}


int main()
{
    string input, day, day_lower;
    vector<string> entered_days;
    vector<int> entered_values;
    int value, day_idx, cur_val_idx = 0;

    cout << "Enter (day-of-the-week, value) pairs like 'monday 25 friday 22 q 1' (enter \"q\" to quit):" << endl;

    // Get successive (day, value) pairs
    while(cin >> day >> value){
        if(day == "q"){
            break;
        }

        if(debug) cout << "(" << day << ", " << value << ")" << endl;

        entered_days.push_back(day);
        entered_values.push_back(value);
    }

    // For each day entered
    for(auto day : entered_days){
        // Get the idx for day of the week
        day_idx = get_day_of_week(day);

        if(debug) cout << "(" << day << ") corresponds to: " << day_idx << endl;

        // Get the current day, value pair
        value = entered_values[cur_val_idx];
        day = entered_days[cur_val_idx];

        if(debug) cout << "Adding " << value << " to " << day << endl;

        // If valid day of the week
        if(day_idx != -1){
            // Add the accepted values to the corresponding day of the week
            day_of_week_vals[day_idx].push_back(value);
            day_of_week_sum[day_idx] += value;
        } else {
            // Not a valid day, add the day to the rejected vector
            rejected.push_back(day);
        }

        // Increment the current value index to the next element in the vector
        cur_val_idx++;
    }

    cout << endl << "Results:" << endl;

    // Summarize
    for(int i = 0; i < 7; i++){
        cout << "\t" << day_of_week[i] << ": " << day_of_week_sum[i] << endl;
    }

    // Show the rejected days
    cout << endl << "Rejected Days (Count = " << rejected.size() << "):" << endl;

    for(auto day : rejected){
        cout << "\t" << day << endl;
    }

    cout << endl;

    keep_window_open();
    return 0;
}
