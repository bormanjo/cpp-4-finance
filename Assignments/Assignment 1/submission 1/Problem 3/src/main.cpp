#include "std_lib_facilities.h"
#include <random>
#include <math.h>
#include <ctime>
#include <iostream>
#include <fstream>

random_device r;
default_random_engine generator(r());
//-----------------------------------------------------------------

template <class T>
class RandomVector {
    vector<T> x;
public:
    explicit RandomVector(vector<T> a){
        x = a;
    }
    float expected_value(){
        float sum = 0;

        for(unsigned int i = 0; i < x.size(); i++){
            sum += x[i];
        }

        return sum / x.size();
    }

    float variance(){
        float mu = expected_value();
        float sum = 0;

        for(unsigned int i = 0; i < x.size(); i++){
            sum += pow(x[i] - mu, 2);
        }

        return sum / (x.size() - 1);
    }

    void print(){
        for(unsigned int i = 0; i < x.size(); i++){
            cout << x[i];
            if(i != x.size() - 1) {
                cout << ", ";
            } else {
                cout << endl;
            }
        }
    }
};

//-----------------------------------------------------------------

template<class T, class Dist>
vector<T> sample_dist(Dist d, unsigned int n) {
    vector<T> obs = {};

    for (unsigned int i = 0; i < n; i++) {
        obs.push_back(d(generator));
    }

    return obs;
}

//-----------------------------------------------------------------

vector<int> sample_uniform(int low, int high, unsigned int n){
    // Generate a uniform random integer vector

    uniform_int_distribution<int> distribution(low, high);

    return sample_dist<int>(distribution, n);
}

//-----------------------------------------------------------------

vector<int> sample_coin(unsigned int n){
    // Generate a vector of random coin flips
    return sample_uniform(0, 1, n);
}

vector<int> sample_coin_biased(float p, unsigned int n){
    // Generate a vector of biased random coin flips
    bernoulli_distribution distribution(p);

    return sample_dist<int>(distribution, n);
}

vector<int> sample_die(unsigned int n){
    // Generate a vector of random die rolls
    return sample_uniform(1, 6, n);
}

//-----------------------------------------------------------------

vector<double> sample_evd(float a, float b, unsigned int n){
    // Generate a real random vector from an extreme value distribution

    extreme_value_distribution<double> distribution(a, b);

    return sample_dist<double>(distribution, n);
}

vector<double> sample_normal(float mu, double sigma, unsigned int n){
    // Generate a real random vector from a normal distribution

    normal_distribution<double> distribution(mu, sigma);

    return sample_dist<double>(distribution, n);
}

vector<double> sample_student_t(unsigned int t, unsigned int n){
    // Generate a real random vector from a normal distribution

    student_t_distribution<double> distribution(t);

    return sample_dist<double>(distribution, n);
}

//-----------------------------------------------------------------

int main()
{
    unsigned int nsamples = 1000;
    vector<vector<float>> moments;
    ofstream outfile;

    cout << "Sampling Distributions" << endl;

    vector<string> rv_name = {"Coin", "6-Sided Die", "Biased Coin", "Extreme Value Dist", "Normal", "Student-t"};
    RandomVector<int>
            x1 (sample_coin(nsamples)),
            x2 (sample_die(nsamples)),
            x3 (sample_coin_biased(0.75, nsamples));
    RandomVector<double>
            x4 (sample_evd(1, 1, nsamples)),
            x5 (sample_normal(0, 1, nsamples)),
            x6 (sample_student_t(10, nsamples));

    cout << "Calculating moments" << endl;

    moments.push_back({x1.expected_value(), x1.variance()});
    moments.push_back({x2.expected_value(), x2.variance()});
    moments.push_back({x3.expected_value(), x3.variance()});
    moments.push_back({x4.expected_value(), x4.variance()});
    moments.push_back({x5.expected_value(), x5.variance()});
    moments.push_back({x6.expected_value(), x6.variance()});

    cout << "Writing to file" << endl;

    outfile.open("../../output/dist-moments.csv");

    outfile << "Distribution,Expected Value,Variance\n";

    for(unsigned int i = 0; i < moments.size(); i++){
        outfile << rv_name[i] << "," << moments[i][0] << "," << moments[i][1] << "\n";
    }

    outfile.close();

    cout << "Done." << endl;

    keep_window_open();
    return 0;
}
