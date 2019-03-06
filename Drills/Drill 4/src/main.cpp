#include "std_lib_facilities.h"

double parse_measurement(string measure){
    // Parses a measurement into a centimeters
    vector<string> units =  {"cm", "m", "in", "ft"};
    vector<double> conv = {1.0, 100.0, 2.54, 12 * 2.54}; // conversion factor to cm

    string unit = "", number = "";
    double num;
    bool matched = false;

    // parse the measure into number and unit
    for(char& c : measure){
        if(c == '-'){
            throw "Negative measurements are invalid";
        }
        if(isdigit(c) || c == '.') {
            number += c;
        }
        if(isalpha(c)){
            unit += c;
        }
    }

    if(number == ""){
        throw "No numeric value provided.";
    }

    if(unit == ""){
        throw "No unit provided. Valid units are 'cm', 'm ', 'in', 'ft'";
    }

    num = stod(number);

    // match the corresponding unit and convert to cm
    for(int i = 0; i != units.size(); i++){
        if(unit == units[i]){
            num = num * conv[i];
            matched = true;
        }
    }

    if(!matched){
        throw "Invalid unit.  Valid units are 'cm', 'm ', 'in', 'ft'";
    } else {
        return num;
    }

}


int main()
{
    string input;
    vector<double> history;
    double num, large, small, sum = 0;
    int count;
    bool valid, first;
    first = true;

    while (true){
        valid = true;

        cout << "Enter a measurement: ";
        getline(cin, input);

        if(input == "|") {
            break;
        }

        try {
            num = parse_measurement(input);
        } catch(char const* e) {
            cout << "The provided measurement could not be parsed. Received error: " << e << endl;
            valid = false;
        }

        if(valid) {

            history.push_back(num);

            if (first) {
                large = small = num;
                first = false;
            } else {
                if (num >= large) {
                    large = num;
                }

                if (num <= small) {
                    small = num;
                }
            }

            sum += num;
            count++;

            cout << "\tSmallest measurement thus far: " << small << " cm" << endl;
            cout << "\tLargest measurement thus far: " << large << " cm" << endl;
        }
    }


    cout << "\tSmallest measurement: " << small/100 << " m" << endl;
    cout << "\tLargest measurement: " << large/100 << " m" << endl;
    cout << "\tNumber of measurements: " << count << endl;
    cout << "\tSum of measurements: " << sum/100 << " m" << endl;

    sort(history.begin(), history.end());

    cout << "\tList of measures:" << endl;

    for(int i = 0; i != history.size(); i++){
        cout << "\t\t" << i+1 << ": " << history[i]/100 << " m" << endl;
    }

    keep_window_open();
    return 0;
}
