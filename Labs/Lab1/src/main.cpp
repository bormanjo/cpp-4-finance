#include "std_lib_facilities.h"

int get_coin_count(const *char coin){
    int qty = 0;
    cout << "How many " << coin << " do you have?\n\t:";
    cin >> qty;

    return qty
}


int main()
{
    int pennies , nickels, dimes, quarters, hdollars, dollars, cents;
    pennies = nickels = dimes = quarters = hdollars = dollars = cents = 0;

    // Query for pennies
    pennies = get_coin_count("pennies");
    nickels = get_coin_count("nickels");
    dimes = get_coin_count("dimes");
    quarters = get_coin_count("quarters");
    hdollars = get_coin_count("half-dollars");
    dollars = get_coin_count("dollars");

    // Calculate cents
    cents = pennies +
            (nickels * 5) +
            (dimes * 10) +
            (quarters * 25) +
            (hdollars * 50) +
            (dollars * 100)

    cout << "You have:" << endl;
    cout << "\t" << pennies << " pennies" << endl;
    cout << "\t" << nickels << " nickels" << endl;
    cout << "\t" << dimes << " dimes" << endl;
    cout << "\t" << quarters << " pennies" << endl;
    cout << "\t" << hdollars << " quarters" << endl;
    cout << "\t" << dollars << " dollars" << endl;
    cout << "The value of all your coins is " << cents << endl

    keep_window_open();
    return 0;
}
