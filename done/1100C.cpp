// Solution to C in contest number 1100 on Codeforces
#include<iostream>
#include<math.h>
#include <iomanip>

#define PI 3.14159265

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    double angle = PI / n;
    double sine = sin(angle);
    double R = sine * (double) r / (1.0 - sine);
    
    cout << setprecision(15) << R << endl;

    return 0;
}
