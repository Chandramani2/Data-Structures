#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ROWS 5
#define COLS 5


void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        cout<<"{";
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j];
            if(j!=COLS-1) cout<<",";
        }
        cout<<"}";
        if(i!=ROWS-1) cout<<",";
        cout<< endl;
    }
}

int countPathsMatrix(int matrix[ROWS][COLS], int R, int C){
    int dp[R][C];
    // Initialize all cells to 0
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill 0th row: set 1 until first 0, then 0 for rest
    for (int j = 0; j < C; j++) {
        if (matrix[0][j] == 0) break;
        dp[0][j] = 1;
    }

    // Fill 0th column: set 1 until first 0, then 0 for rest
    for (int i = 0; i < R; i++) {
        if (matrix[i][0] == 0) break;
        dp[i][0] = 1;
    }

  // Fill DP table
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {
            if (matrix[i][j] == 0) {
                dp[i][j] = 0; // Blocked cell
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

   cout << "\nDP Table:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    if(matrix[R-1][C-1] == 0) return max(dp[R-2][C-1], dp[R-1][C-2]);
    return dp[R-1][C-1];
}


void fillRandomMatrix(int matrix[ROWS][COLS]) {
    srand(time(0)); // Seed for random number generation
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if(i==0 && j==0) continue;
            if(i==1 || j==1) continue;
            matrix[i][j] = rand() % 2; // Randomly assign 0 or 1
        }
    }
}


int main() {
    int matrix[ROWS][COLS] = {{1,1,1,1},
                              {1,0,1,1},
                              {0,1,1,1},
                              {0,0,1,1},
                              {1,1,1,1},};
    fillRandomMatrix(matrix);
    cout << "Matrix:" << endl;
    printMatrix(matrix);
   cout<<"Number of paths: "<<countPathsMatrix(matrix, ROWS, COLS);
    return 0;
}
