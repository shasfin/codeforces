// Solution to 1100 B on codeforces

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

void set_missing (const vector<int>& counts, unordered_set<int>* missing) {
    for (int i = 0; i < counts.size(); ++i) {
        if (counts[i] == 0) {
            missing->emplace(i);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    unordered_set<int> missing;
    vector<int> counts(n, 0);
    set_missing(counts, &missing);
    while(m--) {
        int a;
        cin >>a;
        counts[--a]++;
        auto iter = missing.find(a);
        if (iter != missing.end()) {
            missing.erase(iter);
            if (missing.empty()) {
                cout << 1;
                for (int i = 0; i < n; ++i) {
                    --counts[i];
                }
                set_missing(counts, &missing);
            } else {
                cout << 0;
            }
        } else {
            cout << 0;
        }
    }
    
    cout << endl;
    return 0;
}
