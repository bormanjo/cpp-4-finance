#include "Matrix.h"
#include "std_lib_facilities.h"

int main()
{
    cout << "Task 2:" << '\n';

    vector<vector<int>> A = {
        { 1, 5, 9, 4, 12 },
        { 7, 12, 3, 5, 8 },
        { 8, 4, 15, 9, 5 },
        { 6, 3, 12, 8, 1 }
    };

    vector<vector<int>> B = {
        { 3, 2, 9, 8 },
        { 1, 2, 3, 4 },
        { 9, 8, 7, 6 },
        { 2, 3, 4, 5 },
        { 9, 7, 5, 3 }
    };

    vector<vector<int>> A2 = {
            { 1, 5, 9, 4, 12 },
            { 7, 12, 3, 5, 8 },
            { 8, 4, 15, 9, 5 },
            { 6, 3, 12, 8, 1 }
    };

    vector<vector<int>> B2 = {
            { 3, 2, 9, 8 },
            { 1, 2, 3, 4 },
            { 9, 8, 7, 6 },
            { 2, 3, 4, 5 },
            { 9, 7, 5, 3 }
    };

    Matrix MA{ A };
    Matrix MB{ B };

    Matrix MA2{A2}, MB2{B2};
    try {
        Matrix result1 = MA2 + MA;
        Matrix result2 = MB2 + MB;

        cout << MA << '\n';
        cout << MB << '\n';

        cout << "Addition of MA2 + MA = " << endl << result1 << endl;

        cout << "Addition of MB2 + MB = " << endl << result2 << endl;

    } catch (exception &e) {
        cerr << e.what() << endl;
    }

    vector<vector<int>> X = {
            {2, 2, 2},
            {4, 4, 4},
            {8, 8, 8}
    };

    vector<vector<int>> Y = {
            {2, 2},
            {4, 4},
            {8, 8}
    };

    Matrix MX{X}, MY{Y};

    try{
        cout << "Matrix MX: " << endl << MX << endl;
        cout << "Matrix MY: " << endl << MY << endl;

        Matrix Mult_XY = MX * MY;
        cout << "Multiplication of MX * MY = " << endl << Mult_XY << endl;
    } catch (exception &e){
        cerr << e.what() << endl;
    }

    keep_window_open();

    return 0;
}
