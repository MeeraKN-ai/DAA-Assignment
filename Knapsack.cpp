#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    if (n < 0) {
        cout << "Invalid number of items";
        return 0;
    }
    vector<int> value(n + 1), weight(n + 1);
    for (int i = 1; i <= n; i++) {
        cout << "Enter value and weight of item " << i << ": ";
        cin >> value[i] >> weight[i];
        if (value[i] < 0 || weight[i] < 0) {
            cout << "Invalid value or weight";
            return 0;
        }
    }
    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;
    if (W < 0) {
        cout << "Invalid knapsack capacity";
        return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weight[i] <= w)
                dp[i][w] = max(dp[i][w],
                    dp[i - 1][w - weight[i]] + value[i]);
        }
    }
    vector<int> chosen;
    int w = W;
    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            chosen.push_back(i);
            w -= weight[i];
        }
    }
    reverse(chosen.begin(), chosen.end());
    cout << "\nMaximum value: " << dp[n][W] << "\n";
    cout << "Items selected (item numbers): ";
    for (int x : chosen)
        cout << x << " ";
    cout << "\n";
    return 0;
}
