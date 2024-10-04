#include <iostream>
#include <vector>

using namespace std;

// Fast input/output
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();  // Enable fast I/O

    vector <int> food_val, prefix_or, suffix_or;
    int t;
    int n;
    int max_or;
    int current_or;

    cin >> t;
    // Pre-allocate vectors with sufficient capacity to avoid frequent resizing
    food_val.reserve(200000);  // Reserve space for up to 200,000 elements
    prefix_or.reserve(200000);
    suffix_or.reserve(200000);

    while (t--) 
	{
        cin >> n;

        // Assign size for the current test case
        food_val.assign(n, 0);
        prefix_or.assign(n, 0);
        suffix_or.assign(n, 0);

        for (int i = 0; i < n; i++)
            cin >> food_val[i];

        // Build prefix OR array
        prefix_or[0] = food_val[0];
        for (int i = 1; i < n; i++)
            prefix_or[i] = (prefix_or[i - 1] | food_val[i]);

        // Build suffix OR array
        suffix_or[n - 1] = food_val[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix_or[i] = suffix_or[i + 1] | food_val[i];

        // Calculate the maximum OR when excluding one element
        max_or = 0;
        for (int i = 0; i < n; i++)
		{
            current_or = 0;
            if (i > 0) 
                current_or |= prefix_or[i - 1]; // Prefix OR excluding i-th element
            if (i < n - 1) 
                current_or |= suffix_or[i + 1]; // Suffix OR excluding i-th element
            max_or = max(max_or, current_or);
        }
        cout << max_or << '\n';  // Use '\n' instead of endl for faster output
    }
    return 0;
}