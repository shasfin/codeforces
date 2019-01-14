// Solution to the codeforces challenge 1032A (https://codeforces.com/problemset/problem/1032/A)

#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

void update_counts(map<int, int>* counts, int value) {
    auto iter = counts->find(value);
    if (iter != counts->end()) {
        ++(iter->second);
    } else {
        counts->emplace(value, 1);
    }
}

int find_max_count(map<int, int>& counts) {
    int maximum = 0;
    for (const auto& pair : counts) {
        maximum = max(maximum, pair.second);
    }
    return maximum;
}

int main() {
    int n, k;
    cin >> n >> k;
    // mapping number of gadget to count
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int g;
        cin >> g;
        update_counts(&counts, g);
    }
    
    // find out number of utensil sets
    int max_count = find_max_count(counts);
    int nof_sets = (max_count / k + (max_count % k > 0)) * k;
    
    // sum up the differences nof_sets - counts for every utensil in the map
    int sum = 0;
    for (const auto& pair : counts) {
        sum += nof_sets - pair.second;
    }
    
    cout << sum;
    return 0;
}
