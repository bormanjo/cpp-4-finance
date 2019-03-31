#include "std_lib_facilities.h"

// Read TSV ------------------------------------------------------------------------

const string in_filename = "../../input/options-data.txt";
const string out_filename = "../../output/option-prices.txt";

int row_idx = 0;        // Tracks num rows in .TSV
const vector<string> expected_names = {"Type", "Price", "Strike", "r", "sigma", "days"};
unsigned int debug_level = 0;

vector<string> type;
vector<double> price, strike, ir, sigma, t;


bool check_columns(vector<string> &colnames){

    for(unsigned int i = 0; i < colnames.size(); i++){
        if (debug_level >= 2) cout << "'" << colnames[i] << "' vs. '" << expected_names[i] << "'" << endl;
        if (colnames[i] != expected_names[i]){
            return false;
        }
    }

    return true;
}

void parse_tsv(){

    ifstream infile(in_filename);   // the file to be read

    // parse the file
    string _type, _price, _strike, _ir, _sigma, _t;

    while (infile >> _type >> _price >> _strike >> _ir >> _sigma >> _t) {

        vector<string> row_items = {_type, _price, _strike, _ir, _sigma, _t};       // The vector of row items

        if (debug_level >= 1){
            cout << "[row " << row_idx << "] - ";
            for (auto &s : row_items) {
                cout << "'" << s << "'\t\t";
            }
            cout << endl;
        }

        if (row_idx == 0) {
            // If this is the first row read, check the columns

            // Check num columns
            if (row_items.size() != expected_names.size()) {
                cout << row_items.size() << " vs." << expected_names.size() << endl;
                error("Invalid number of columns in tsv");
            }

            // Check column names
            if (!check_columns(row_items)) {
                error("Invalid column names in tsv");
            }
        } else {
            // Not first row, parse data

            type.push_back(row_items[0]);
            price.push_back(stod(row_items[1]));
            strike.push_back(stod(row_items[2]));
            ir.push_back(stod(row_items[3]));
            sigma.push_back(stod(row_items[4]));
            t.push_back(stod(row_items[5]));
        }

        row_idx++;
    }

    row_idx--; // subtract one as the previous counter will always overstep by 1
    // Done
}

// Option Class ---------------------------------------------------------------------

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

// Main -----------------------------------------------------------------------

int main()
{
    try{
        parse_tsv();
    } catch (exception &e){
        cout << "Encountered an error reading the .tsv: " << e.what() << endl;
        return 1; // failure
    }

    if (debug_level >= 1) cout << "Building Options vector" << endl;

    vector<EuropeanOption> option_data;

    for(int i = 0; i < row_idx; i++){
        if(debug_level >= 1) cout << "Building option #" << i + 1 << endl;

        if(debug_level >= 2){
            cout << type[i] << "\t"
                 << price[i] << "\t"
                 << strike[i] << "\t"
                 << ir[i] << "\t"
                 << sigma[i] << "\t"
                 << t[i] << endl;
        }

        EuropeanOption tmp(type[i], price[i], strike[i], ir[i], sigma[i], t[i]);

        if(debug_level >= 2) tmp.check_components();

        option_data.push_back(tmp);
    }

    // Write out option data
    ofstream outfile(out_filename);

    for (unsigned int j = 0; j < expected_names.size(); j++){
        outfile << expected_names[j] << "\t";
    }

    outfile << "Option_Value" << "\n";

    for(int i = 0; i < row_idx; i++){
        if(debug_level >= 1) cout << "Writing row: " << i << "\t";

        outfile << type[i] << "\t"
                << price[i] << "\t"
                << strike[i] << "\t"
                << ir[i] << "\t"
                << sigma[i] << "\t"
                << t[i] << "\t"
                << option_data[i].getPrice() << "\n";

        if(debug_level >= 1) cout << "Wrote." << endl;
    }

    outfile.close();

    keep_window_open();
    return 0;
}
