// Solution to the problem 1032C (https://codeforces.com/problemset/problem/1032/C)

#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }    

    // position×finger |-> from which finger in the last position in can come (vector<bool> of size 5)
    // [position][finger][fingers in the previous position that can lead here]
    vector<vector<vector<bool>>> table(n, vector<vector<bool>>(5, vector<bool>(6, false)));
    // table[position][finger][0] says if there are any parents
    // at position 0 false vectors for every finger
    for (int j = 0; j < 5; ++j) {
        table[0][j][0] = true;
    }
    for (int i = 1; i < n; ++i) {
        // position index i
        // if a[i-1], a[i] is descendent, fill every finger in table[i] with descendent fingers
        if (a[i] < a[i-1]) {
            for (int j = 0; j < 5; ++j) {
                bool all_false = true;
                for (int k = j+2; k < 6; ++k) {
                    table[i][j][k] = table[i-1][k-1][0];
                    if (table[i][j][k]) {
                        all_false = false;
                    }
                }
                table[i][j][0] = !all_false;
            }
        } else if (a[i] > a[i-1]) {
            for (int j = 0; j < 5; ++j) {
                bool all_false = true;
                for (int k = 1; k < j+1; ++k) {
                    table[i][j][k] = table[i-1][k-1][0];
                    if (table[i][j][k]) {
                        all_false = false;
                    }
                }
                table[i][j][0] = !all_false;
            }
        } else if (a[i] == a[i-1]) {
            for (int j = 0; j < 5; ++j) {
                bool all_false = true;
                for (int k = 1; k < 6; ++k) {
                    if (j != k-1) {
                        table[i][j][k] = table[i-1][k-1][0];
                    }
                    if (table[i][j][k]) {
                        all_false = false;
                    }
                }
                table[i][j][0] = !all_false;
            }
        }
        
    }
    
    /*for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < 6; ++k) {
                cout << table[i][j][k];
            }
            cout << "    ";
        }
        cout << endl;
    }*/
    // backtracking
    // find start: greatest j with table[n-1][j][0] == true
    vector<int> digits(n);
    int j;
    for (j = 4; j >=0; --j) {
        if (table[n-1][j][0]) {
            break;
        }
    }
    if (!table[n-1][j][0]) {
        cout << -1;
    } else {
        digits[n-1] = j+1;
        for (int i = n-1; i >= 1; i--) {
            // find greatest k so that table[i][j][k] == true
            int k;
            for (k = 5; k >= 1; --k) {
                if (table[i][j][k]) {
                    break;
                }
            }
            digits[i-1] = k;
            j = k-1;
        }
    
    
     for (const auto digit : digits) {
            cout << digit << " ";
        }
    }
    cout << endl;
    
    return 0;
}
