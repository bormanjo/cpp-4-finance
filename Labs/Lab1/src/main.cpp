#include "std_lib_facilities.h"

int get_coin_count(const char* coin){
    /*
     * Asks the user for the quantity of coins
     */

    string qty_str = "";
    int qty;

    do {
        cout << "How many " << coin << " do you have?\n\t:";
        cin >> qty_str;

        try {
            qty = stoi(qty_str);

            if(qty >= 0){
                return qty;
            } else {
                cout << "The quantity entered: '" << qty << "' is invalid." << endl;
            }

        } catch (invalid_argument& ia) {
            cout << "The quantity entered: '" << qty_str << "' is invalid." << endl;
        }

    } while (true);
}

bool is_plural(int qty){
    if(qty == 1){
        return false;
    } else {
        return true;
    }
}

void print_summary(int p, int n, int d, int q, int hc, int dc){
    /*
     * Calculates the total value in cents of all the coins. Prints the summary.
     */
    int cents = 0;

    string p_str, n_str, d_str, q_str, hc_str, dc_str;

    // Calculate cents
    cents = p +
            (n * 5) +
            (d * 10) +
            (q * 25) +
            (hc * 50) +
            (dc * 100);

    cout << "You have:" << endl;

    if(is_plural(p)){
        p_str = "pennies";
    } else {
        p_str = "penny";
    }

    if(is_plural(n)){
        n_str = "nickels";
    } else {
        n_str = "nickel";
    }

    if(is_plural(d)){
        d_str = "dimes";
    } else {
        d_str = "dime";
    }

    if(is_plural(q)){
        q_str = "quarters";
    } else {
        q_str = "quarter";
    }

    if(is_plural(hc)){
        hc_str = "half-dollars";
    } else {
        hc_str = "half-dollar";
    }

    if(is_plural(dc)){
        dc_str = "dollars";
    } else {
        dc_str = "dollar";
    }

    cout << "\t" << p << " " << p_str << endl;
    cout << "\t" << n << " " << n_str << endl;
    cout << "\t" << d << " " << d_str << endl;
    cout << "\t" << q << " " << q_str << endl;
    cout << "\t" << hc << " " << hc_str << endl;
    cout << "\t" << dc << " " << dc_str << endl;
    cout << "The value of all your coins is " << cents << endl;
}

int main()
{
    int pennies , nickels, dimes, quarters, hdollars, dollars;
    pennies = nickels = dimes = quarters = hdollars = dollars = 0;

    // Query for coins
    pennies = get_coin_count("pennies");
    nickels = get_coin_count("nickels");
    dimes = get_coin_count("dimes");
    quarters = get_coin_count("quarters");
    hdollars = get_coin_count("half-dollars");
    dollars = get_coin_count("dollars");

    print_summary(pennies,
            nickels,
            dimes,
            quarters,
            hdollars,
            dollars);

    keep_window_open();
    return 0;
}
