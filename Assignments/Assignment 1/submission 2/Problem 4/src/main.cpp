#include "std_lib_facilities.h"
#include <iostream>
#include <math.h>

bool debug = false;

long dollars_to_cents(double dollars){
    long cents;

    cents = (long) round(dollars * 100.0);

    return cents;
}

double cents_to_dollars(long cents){
    double dollars, d_cents;

    dollars = floor(cents / 100.0);
    d_cents = (cents / 100.0) - dollars;

    if (debug) cout << "Dollars: " << dollars << "\tCents: " << d_cents << endl;

    // Return dollars + d_cents
    return dollars + d_cents;
}


class Money
{
public:
    long value; // Value recorded in cents
    string currency;

    // Constructor ----------------------------------------------------------

    Money (){
        this->currency = "$";
        this->value = 0;
    }

    explicit Money (const string &crncy){
        this->currency = crncy;
        this->value = 0;
    }

    Money (const string &crncy, double val){
        this->currency = crncy;
        set_value(val);
    }

    // Member Functions -----------------------------------------------------

    void set_value(double cents){
        // Save value in cents (round)
        this->value = dollars_to_cents(cents);

        if (debug) cout << "New value (cents) is: " << this->value << endl;
    }

    bool check_currency(const Money &M){
        return this->currency == M.currency;
    }

    // Arithmetic -----------------------------------------------------------

    // Overload + addition operator
    Money operator+(const Money &M){

        if(!this->check_currency(M)){
            error("Cannot add different currencies.");
        }

        Money money;
        money.value = this->value + M.value;

        return money;
    }

    // Overload - subtraction operator
    Money operator-(const Money &M){
        if(!this->check_currency(M)){
            error("Cannot subtract different currencies.");
        }

        Money money;
        money.value = this->value - M.value;

        return money;
    }

    // Overload * multiplication operator
    Money operator*(const int scalar){
        Money money;
        money.value = this->value * scalar;

        return money;
    }

    Money operator*(const double scalar){
        Money money;
        money.value = (long) round(this->value * scalar);

        return money;
    }

    // Overload / division operator
    Money operator/(const int scalar){
        Money money;
        money.value = this->value / scalar;

        return money;
    }

    Money operator/(const double scalar){
        Money money;
        money.value = (long) round(this->value / scalar);

        return money;
    }

    // Input/Output ---------------------------------------------------------

    // Overload << output operator
    friend ostream &operator << (ostream &output, const Money &M){
        // Outputs as a currency
        output << M.currency << " " << cents_to_dollars(M.value);
        return output;
    }

    // Overload >> input operator
    friend istream &operator >> (istream &input, Money &M){
        // Read in a dollar value
        string crncy;
        double val;
        input >> crncy >> val;

        M.currency = crncy;
        M.set_value(val);

        return input;
    }
};


int main()
{
    Money d1, d2;

    cout << "Enter a currency and amount (ex. USD 100.045): [1] ";
    cin >> d1;

    cout << "Enter another currency and amount (ex. EUR 42.549): [2] ";
    cin >> d2;

    // Create a common Money object
    Money d3(d1.currency, 9.99);
    cout << endl << "I have created a third currency: [3] " << d3 << endl << endl;

    cout << "Adding [1] and [3]: " << d1 << " + " << d3 << " = " << d1 + d3 << endl;

    cout << "Subtracting [1] and [3]: " << d1 << " - " << d3 << " = " << d1 - d3 << endl;

    cout << "Multiplying [1] by 2 (int): " << d1 << " * 2 " << " = " << d1 * 2 << endl;

    cout << "Multiplying [1] by 2.5 (double): " << d1 << " * 2.5 " << " = " << d1 * 2.5 << endl;

    cout << "Dividing [1] by 2 (int): " << d1 << " / 2 " << " = " << d1 / 2 << endl;

    cout << "Dividing [1] by 2.5 (double): " << d1 << " / 2.5 " << " = " << d1 / 2.5 << endl;

    try{
        cout << "Trying to add each of the user's moniesq"
                ": " << d1 << " + " << d2 << " = " << endl;
        cout << d1 + d2 << endl;
    } catch (exception &e){
        cout << "Received error: " << e.what() << endl;
    }

    try{
        cout << "Trying to subtract each of the user's monies: " << d1 << " - " << d2 << " = " << endl;
        cout << d1 - d2 << endl;
    } catch (exception &e){
        cout << "Received error: " << e.what() << endl;
    }

    keep_window_open();
    return 0;
}
