#include <iostream>
#include <vector>
 
using namespace std;
 
// Struct to store ID and Color as a pair
struct Item {
    int id;
    int color;
};
 
// Function to calculate the maximum subsequence starting from each fixed item
int calculate_max_subsequence(const vector<Item>& items, int n) {
    int max_len = 0;  // Variable to store the maximum subsequence length
	 int adjusted_len ;
int current_len ;
int penalty ;
    // Loop over each item to fix it as the start of the subsequence
    for (int i = 0; i < n; ++i) {
        current_len = 1;  // Each subsequence starts with the fixed item
        penalty = 0;      // Initialize the penalty for adjacent colors
        
        // Traverse the rest of the array to find strictly increasing subsequences
        for (int j = i + 1; j < n; ++j) {
            if (items[j].id > items[i].id ) {
                current_len++;  // Extend the subsequence
 
                // Check if adjacent colors are the same and apply penalty
                if (items[j].color == items[j - 1].color) {
                    penalty++;
                }
            }
        }

		// Subtract the total penalty from the current subsequence length
		 adjusted_len = current_len - penalty;

		// Update the maximum subsequence length if needed
        max_len = max(max_len, adjusted_len);
    }
 
    return max_len;
}
 
void ft_fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
int main() {
    ft_fast_io();
 	int result ;
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<Item> items(n);
        for (int i = 0; i < n; ++i) {
            cin >> items[i].id;  // Read ID
        }
        for (int i = 0; i < n; ++i) {
            cin >> items[i].color;  // Read color
        }
 
        // Find the best subsequence length using the helper function
        int result = calculate_max_subsequence(items, n);
 
        // Output the result for the current test case
        cout << result << '\n';
    }
 
    return 0;
}