#include <bits/stdc++.h>

using namespace std;

// Function to print the matrix (helper)
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        cout << "{";
        for (size_t j = 0; j < row.size(); j++) {
            cout << row[j];
            if (j != row.size() - 1) cout << ",";
        }
        cout << "}" << endl;
    }
}

long long countPathsExactJump(const vector<vector<int>>& matrix) {
    int R = matrix.size();
    if (R == 0) return 0;
    int C = matrix[0].size();

    // dp[i][j] stores the number of ways to reach cell (i, j)
    vector<vector<long long>> dp(R, vector<long long>(C, 0));

    // Base case: 1 way to be at the starting cell
    dp[0][0] = 1;

    // Iterate through every cell in the grid
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // If this cell is unreachable (0 ways to get here), we can't jump from it.
            if (dp[i][j] == 0) continue;

            // If this is the destination, we stop processing (optional, but logical)
            if (i == R - 1 && j == C - 1) continue;

            int jump = matrix[i][j];

            // If jump value is 0, we are stuck and cannot move further
            if (jump == 0) continue;

            // --- OPTION 1: Move Down ---
            // Check if jumping 'jump' steps down stays within bounds
            if (i + jump < R) {
                dp[i + jump][j] += dp[i][j];
            }

            // --- OPTION 2: Move Right ---
            // Check if jumping 'jump' steps right stays within bounds
            if (j + jump < C) {
                dp[i][j + jump] += dp[i][j];
            }
        }
    }

    // Print the DP table for debugging/visualization
    cout << "\nDP Table (Ways to reach each cell):" << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << dp[i][j] << "\t"; // Use tab for better spacing
        }
        cout << endl;
    }

    // The result is the number of ways to reach the bottom-right cell
    return dp[R - 1][C - 1];
}

int main() {
    // Example Matrix
    vector<vector<int>> matrix = {
        {1, 2, 0, 2, 0, 4},
        {1, 1, 2, 2, 1, 3},
        {2, 2, 3, 1, 1, 3},
        {1, 3, 1, 1, 1, 1},
        {1, 1, 2, 2, 1, 2}
    };

    cout << "Game Board (Jump Values):" << endl;
    printMatrix(matrix);

    long long totalPaths = countPathsExactJump(matrix);
    
    cout << "\nTotal paths to reach the end: " << totalPaths << endl;

    return 0;
}