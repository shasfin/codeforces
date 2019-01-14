#include<iostream>
#include<vector>

using namespace std;

int main () {
    // y = -x/m + b
    // number of bananas in point (x,y) = x+y
    int m;
    cin >> m;
    int b;
    cin >> b;
    
    // count number of bananas in a rectangle:
    // rc(r+c-2)/2, where r is the number of points rowwise, c number of point columnwise
    
    // 1. Observation: all optimal rectangles start in (0,0)
    
    // Brute force approach:
    // for every (integral) point on the line y = -x/m+b, compute the number of bananas for that rectangle. Choose the maximum and output.
    
    long long bananas = 0;
    for (long y = b; y >= 0; --y) {
        long x = m * (b - y);
        long r = x+1;
        long c = y+1;
        long long current_bananas = ((long long) r)*c*(r+c-2)/2;
        bananas = max (bananas, current_bananas);
    }
    
    cout << bananas << endl;
    
    
    return 0;
}
