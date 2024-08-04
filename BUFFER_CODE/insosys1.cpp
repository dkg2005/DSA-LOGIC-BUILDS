#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubsequencesWithT(string S, string T, int K) {
    int N = S.length();
    int M = T.length();
    int count = 0;
    
    // Iterate over all possible starting points of subsequences in S
    for (int i = 0; i <= N - M; i++) {
        int changes_needed = 0;
        int s_index = i, t_index = 0;
        
        // Try to match T as a subsequence within the allowed changes
        while (s_index < N && t_index < M) {
            if (S[s_index] != T[t_index]) {
                changes_needed++;
            } else {
                t_index++;
            }
            s_index++;
        }
        
        // Check if we have matched the entire T
        if (t_index == M && changes_needed <= K) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int N, M, K;
    string S, T;
    
    // Input format as given in the problem
    cin >> N >> M >> K;
    cin >> S >> T;
    
    int result = maxSubsequencesWithT(S, T, K);
    cout << result << endl;
    
    return 0;
}
