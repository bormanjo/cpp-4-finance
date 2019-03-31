#include "std_lib_facilities.h"
#include "Point.h"

int main()
{
    vector<Point> original_points, processed_points;
    int x, y;
    bool flag = false;
    Point p;
    string filename = "../../output/mydata.txt";

    cout << "Enter 3 Points: " << endl;

    for(int i = 0; i < 3; ++i){
        cout << "Point " << i + 1 << endl << "x = ";
        cin >> x;
        cout << "y = ";
        cin >> y;

        original_points.push_back(Point(x, y));
    }

    ofstream outfile(filename);

    for(auto pt : original_points){
        outfile << pt << endl;
    }

    outfile.close();

    ifstream infile(filename);

    while(infile >> p){
        processed_points.push_back(p);
    }

    infile.close();

    for(auto pt : processed_points){
        cout << pt << endl;
    }

    if(original_points.size() != processed_points.size()){
        cout << "Vector Sizes do not match" << endl;
    } else {
        cout << "Vector sizes match" << endl;

        for(int i = 0; i < processed_points.size(); i++){
            if(processed_points[i] != original_points[i]){
                flag = true;
                cout << "Point @ i = " << i << ": " << processed_points[i] << " != " << original_points[i] <<  endl;
            }
        }

        if(!flag){
            cout << "All points match" << endl;
        }

    }

    keep_window_open();
    return 0;
}
