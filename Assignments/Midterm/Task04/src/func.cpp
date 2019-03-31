//
// Created by J-C Borman on 3/27/2019.
//

#include "func.h"

double E(vector<double> X){
    double sum = 0;

    for(auto &x : X){
        sum += x;
    }

    return sum / X.size();
}

double median(vector<double> X){

    sort(X.begin(), X.end());
    unsigned long n = X.size();
    if(n % 2 == 0){
        return (X[n / 2] + X[(n / 2) - 1]) / 2;
    } else {

        return X[(n / 2)];
    }
}

