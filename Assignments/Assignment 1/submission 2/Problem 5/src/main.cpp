#include "std_lib_facilities.h"
#include <cmath>

bool debug = true;

template <typename T> bool is_positive(T num){
    return num >= 0;
}

class EuropeanOption {
public:
    bool call;
    double price, strike, interest_rate, sigma, time_to_maturity;

    EuropeanOption(string &type, double c, double k, double r, double v, double t){

        if (! (type == "put" || type == "call")){
            error("Type must equal either 'call' or 'put'");
        }

        if(type == "call"){
            this->call = true;
        } else {
            this->call = false;
        }

        if (! is_positive(c)){
            error("Price cannot be negative");
        }

        this->price = c;

        if (! is_positive(k)){
            error("Strike price cannot be negative");
        }

        this->strike = k;

        if (! is_positive(r)){
            error("Interest Rate cannot be negative");
        }

        this->interest_rate = r;

        if (! is_positive(v)){
            error("sigma cannot be negative");
        }

        this->sigma = sqrt(v);

        if (! is_positive(t)){
            error("Time until maturity cannot be negative");
        }

        this->time_to_maturity = t / 365.0;
    }

    double getPrice(){
        if (call){
            return C();
        } else {
            return P();
        }
    }

    double d1(){
        double scalar, term1, term2, term3;

        scalar = 1 / (sigma * sqrt(time_to_maturity));

        term1 = log(price / strike);

        term2 = interest_rate * time_to_maturity;

        term3 = pow(sigma, 2) * time_to_maturity / 2.0;

        return scalar * (term1 + term2 + term3);
    }

    double d2(){
        double term2 = sigma * sqrt(time_to_maturity);

        return this->d1() - term2;
    }

    double N(double d){
        return (1 + erf(d/sqrt(2))) / 2.0;
    }

    double KerT(){
        return strike * exp(-1.0 * interest_rate * time_to_maturity);
    }

    double C(){
        double term1, term2;

        term1 = N(d1()) * price;

        term2 = N(d2()) * KerT();

        return term1 - term2;
    }

    double P(){

        double term1, term2;

        term1 = N( - d2()) * strike * exp(- interest_rate * time_to_maturity);

        term2 = N( - d1()) * price;

        return term1 - term2;
    }

    void check_components(){
        cout << "Parameters: " << endl;
        cout << "S: " << price << endl;
        cout << "K: " << strike << endl;
        cout << "r: " << interest_rate << endl;
        cout << "sigma: " << sigma << endl;
        cout << "t: " << time_to_maturity << endl;

        cout << "Calculations: " << endl;
        cout << "d1: " << d1() << endl;
        cout << "d2: " << d2() << endl;
        cout << "N(d1): " << N(d1()) << endl;
        cout << "N(d2): " << N(d2()) << endl;
        cout << "KerT: "  << KerT() << endl;
    }
};


int main()
{
    string call = "call", put = "put";

    EuropeanOption eur1(call, 100.0, 100.0, 0.05, 0.25, 30.0);
    cout << "Call 1: " << eur1.getPrice() << endl;

    EuropeanOption eur2(call, 100.0, 100.0, 0.05, 0.25, 1.0);
    cout << "Call 2: " << eur2.getPrice() << endl;

    EuropeanOption eur3(call, 100.0, 100.0, 0.05, 0.01, 30.0);
    cout << "Call 3: " << eur3.getPrice() << endl;

    EuropeanOption eur4(call, 100.0, 100.0, 0.01, 0.25, 30.0);
    cout << "Call 4: " << eur4.getPrice() << endl;

    EuropeanOption eur5(call, 100.0, 1.0, 0.05, 0.25, 30.0);
    cout << "Call 5: " << eur5.getPrice() << endl;

    EuropeanOption eur6(call, 1.0, 100.0, 0.05, 0.25, 30.0);
    cout << "Call 6: " << eur6.getPrice() << endl;

    EuropeanOption eur7(put, 100.0, 100.0, 0.05, 0.25, 30.0);
    cout << "Call 7: " << eur7.getPrice() << endl;

    EuropeanOption eur8(put, 100.0, 100.0, 0.05, 0.25, 1.0);
    cout << "Call 8: " << eur8.getPrice() << endl;

    EuropeanOption eur9(put, 100.0, 100.0, 0.05, 0.01, 30.0);
    cout << "Call 9: " << eur9.getPrice() << endl;

    EuropeanOption eur10(put, 100.0, 100.0, 0.01, 0.25, 30.0);
    cout << "Call 10: " << eur10.getPrice() << endl;

    EuropeanOption eur11(put, 100.0, 1.0, 0.05, 0.25, 30.0);
    cout << "Call 11: " << eur11.getPrice() << endl;

    EuropeanOption eur12(put, 1.0, 100.0, 0.05, 0.25, 30.0);
    cout << "Call 12: " << eur12.getPrice() << endl;

    return 0;
}
