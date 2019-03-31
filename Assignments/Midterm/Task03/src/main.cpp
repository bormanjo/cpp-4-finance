#include "std_lib_facilities.h"

#include <chrono>

void swapMethod01(vector<double> A, vector<double> B)
{
    vector<double> tmp = A;
    A = B;
    B = tmp;
}

// You should modify this one:
void swapMethod02(vector<double>& A, vector<double>& B) //Swap the addresses instead of the values themselves
{
    vector<double> tmp = A;
    A = B;
    B = tmp;
}

int main()
{
    string outfile_name = "../../output/results.txt";
    ofstream outfile(outfile_name);

    cout << "Task 3:" << '\n';

    vector<double> data_set_A(10000000);
    vector<double> data_set_B(10000000);

    fill(data_set_A.begin(), data_set_A.end(), 1.0); // fill A with 1.0's
    fill(data_set_B.begin(), data_set_B.end(), 2.0); // fill B with 2.0's

    // Calculate & output the time used to run swapMethod01
    auto start = chrono::system_clock::now();
    for (int i = 0; i < 50; i++) {
        swapMethod01(data_set_A, data_set_B);
    }
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    outfile << "Time used by swapMethod01: " << elapsed_seconds.count() << "s" << endl;

    // Calculate & output the time used to run swapMethod02
    start = chrono::system_clock::now();
    for (int i = 0; i < 50; i++) {
        swapMethod02(data_set_A, data_set_B);
    }
    end = chrono::system_clock::now();
    elapsed_seconds = end - start;
    outfile << "Time used by swapMethod02: " << elapsed_seconds.count() << "s" << endl;

    outfile.close();

    keep_window_open();

    return 0;
}
