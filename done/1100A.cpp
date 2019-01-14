// Solution to 1100 A on codeforces

#include<iostream>
#include<vector>

using namespace std;

int main() {
    // not the best solution, quadratic time;
    int n, k;
    cin >> n >> k;
    vector<int> tabs(n);
    int S = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tabs[i];
        S += tabs[i];
    }
    
    int maximum = 0;
    for (int b = 0; b < k; ++b) {
        int partial_sum = S;
        for (int i = b; i < n; i += k) {
            partial_sum -= tabs[i];
        }
        if (partial_sum >= 0 && partial_sum > maximum) {
            maximum = partial_sum;
        } else if (partial_sum < 0 && -partial_sum > maximum) {
            maximum = -partial_sum;
        }
    }
    
    cout << maximum;
    
    
    return 0;
}
