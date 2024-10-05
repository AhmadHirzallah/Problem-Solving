#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void ft_fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    ft_fast_io();

    int tests;
    cin >> tests;

    while (tests--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        // Sort the array to maximize differences
        sort(a.begin(), a.end());

        // Vector to store differences between adjacent elements
        vector<int> differences;
        
        // Calculate differences between all pairs (a[j] - a[i] for j > i)
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                differences.push_back(a[j] - a[i]);
            }
        }

        // Sort the differences in descending order to extract the largest ones
        sort(differences.rbegin(), differences.rend());

        // Sum up the largest m differences
        long long sum_largest_diff = 0;
        for (int i = 0; i < m; ++i)
        {
            sum_largest_diff += differences[i];
        }

        cout << sum_largest_diff << '\n';
    }

    return 0;
}