#include<iostream>
#include<vector>

using namespace std;

int main () {
    int n; // lab size
    cin >> n;
    vector<vector<int> > lab(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> lab[i][j];
        }
    }
    
    bool result = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (lab[i][j] != 1) {
                // search for s and t
                bool intermediate_result = false;
                for (int s = 0; s < n; ++s) {
                    for (int t = 0; t < n; ++t) {
                        if (lab[i][j] == lab[i][s] + lab[t][j]) {
                            intermediate_result = true;
                        }
                    }
                }
                if (!intermediate_result) {
                    result = false;
                    break;
                }
            }
        }
        if (!result) {
            break;
        }
    }
    
    cout << (result ? "Yes" : "No") << endl;
    
    return 0;
}
