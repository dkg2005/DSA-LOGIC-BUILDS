#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    // Compute the prefix sum array
    vector<vector<int>> prefix(N + 1, vector<int>(N + 1, 0));
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            prefix[i][j] = A[i - 1][j - 1] +
                           prefix[i - 1][j] +
                           prefix[i][j - 1] -
                           prefix[i - 1][j - 1];
        }
    }

    vector<int> subGridSums;

    // Calculate sums for all possible sub-grids
    for (int x1 = 1; x1 <= N; ++x1) {
        for (int y1 = 1; y1 <= N; ++y1) {
            for (int x2 = x1; x2 <= N; ++x2) {
                for (int y2 = y1; y2 <= N; ++y2) {
                    // Calculate the sum of the sub-grid (x1, y1) to (x2, y2)
                    int sum = prefix[x2][y2] -
                              prefix[x1 - 1][y2] -
                              prefix[x2][y1 - 1] +
                              prefix[x1 - 1][y1 - 1];
                    subGridSums.push_back(sum);
                }
            }
        }
    }

    // Sort the sums in descending order
    sort(subGridSums.rbegin(), subGridSums.rend());

    // Get the maximum sum of K sub-grids
    int maxBeauty = 0;
    for (int i = 0; i < K && i < subGridSums.size(); ++i) {
        maxBeauty += subGridSums[i];
    }

    // If maxBeauty is negative, add 10^6
    if (maxBeauty < 0) {
        maxBeauty += 1000000;
    }

    cout << maxBeauty << endl;

    return 0;
}