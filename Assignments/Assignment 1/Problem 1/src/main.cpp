#include "std_lib_facilities.h"
#include <math.h>

bool debug = false;

double sum_of_squares(int exp){
    if(exp == 0){
        return 1;
    } else {
        return pow(2, exp) + sum_of_squares(exp - 1);
    }
}

int num_squares(double grains){

    int count = 1;

    while(true){

        if(debug) printf("%d - %f </= %f\n", count, grains, sum_of_squares(count - 1));

        if(grains <= sum_of_squares(count - 1)){
            return count;
        } else {
            count += 1;
        }
    }
}

int num_grains_int(int squares){
    return int(sum_of_squares(squares));
}

double num_grains_dbl(int squares){
    return sum_of_squares(squares);
}

int main()
{
    string input;
    double g;

    cout << "The inventor of chess asked for 2^(64-1) grains for 64 squares." << endl
    << "\tAs an integer: " << num_grains_int(63) << endl
    << "\tAs a double: " << num_grains_dbl(63) << endl;

    while(true){

        cout << "Enter some whole number of grains (enter \"q\" to exit)" << endl;
        cout << "# of Grains: ";
        cin >> input;

        if (input == "q"){
            break;
        }

        try{
            g = stod(input);

            if (debug) cout << "\tentered: " << g << endl;

            if(g < 0){
                cout << "\tPlease enter a positive whole number" << endl;
            } else {
                cout << "\tNumber of squares: " << num_squares(g) << endl;
            }

        } catch (const invalid_argument & ia){
            cerr << "Invalid argument: '" << input << "'. Please enter a positive whole number." << endl;
        }
    }

    keep_window_open();
    return 0;
}
