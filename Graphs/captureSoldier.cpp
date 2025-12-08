#include "bits/stdc++.h"
using namespace std;
/* if surrounded by 'X' then 'O' is captured
- Given 2-D Matrix , capture all regions surrounded by 'X'
*/
/* 	Method 1: 	- Get all the componenets
		 		- if any Node in the componenet is surrounded by 'X', 
		 			whole componenet will get captured
	 			- if the single node in the component on boundary, 
	 				entire componenet not be surrounded
 	Method 2:	- apply DFS on the boundary and mark 'O' with 'N'
 					as they cannot be captured
*/


// Directions arrays for moving Up, Down, Left, Right
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void printMatrix(const vector<vector<char>>& matrix) {
    for (const auto& row : matrix) {
        cout << "{ ";
        for (char c : row) {
            cout << c << " ";
        }
        cout << "}\n";
    }
}

bool isValid(int r, int c, int rows, int cols) {
    return (r >= 0 && r < rows && c >= 0 && c < cols);
}

// DFS to mark 'O's connected to the boundary as Safe ('N')
void dfs(vector<vector<char>> &board, int r, int c, int rows, int cols) {
    // Mark current cell as Safe
    board[r][c] = 'N';

    // Traverse 4 directions
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        // If neighbor is valid and is an 'O', continue DFS
        if (isValid(nr, nc, rows, cols) && board[nr][nc] == 'O') {
            dfs(board, nr, nc, rows, cols);
        }
    }
}

void solve(vector<vector<char>> &board) {
    int n = board.size();
    if (n == 0) return;
    int m = board[0].size();

    // 1. Traverse Boundaries:
    // If 'O' is on boundary, it cannot be captured. 
    // Start DFS from there to mark the entire connected component as 'N' (Not Captured).
    
    // Check First and Last Row
    for (int j = 0; j < m; j++) {
        if (board[0][j] == 'O') dfs(board, 0, j, n, m);       // First Row
        if (board[n - 1][j] == 'O') dfs(board, n - 1, j, n, m); // Last Row
    }

    // Check First and Last Column
    for (int i = 0; i < n; i++) {
        if (board[i][0] == 'O') dfs(board, i, 0, n, m);       // First Column
        if (board[i][m - 1] == 'O') dfs(board, i, m - 1, n, m); // Last Column
    }

    // 2. Post-Process the Board
    // - If cell is 'O': It was NOT reached from boundary -> Capture it ('X')
    // - If cell is 'N': It WAS reached from boundary -> Restore it ('O')
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X'; // Capture
            } else if (board[i][j] == 'N') {
                board[i][j] = 'O'; // Restore Safe
            }
        }
    }
}

// Method 1 Helper: DFS to collect component and check boundary
void getComponentDFS(vector<vector<char>> &board, int r, int c, int n, int m, 
                     vector<vector<bool>> &visited, vector<pair<int,int>> &component, bool &hasBoundary) {
    
    visited[r][c] = true;
    component.push_back({r, c});

    // Check if current cell is on the boundary
    if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
        hasBoundary = true;
    }

    // Traverse 4 directions
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        // If neighbor is valid, is an 'O', and not visited yet
        if (isValid(nr, nc, n, m) && board[nr][nc] == 'O' && !visited[nr][nc]) {
            getComponentDFS(board, nr, nc, n, m, visited, component, hasBoundary);
        }
    }
}

void solveMethod1(vector<vector<char>> &board) {
    int n = board.size();
    if (n == 0) return;
    int m = board[0].size();
    
    // Visited array to keep track of processed 'O's
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Iterate over every cell in the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            // If we find an unvisited 'O', it's a new component
            if (board[i][j] == 'O' && !visited[i][j]) {
                vector<pair<int, int>> component;
                bool hasBoundary = false;
                
                // Get all 'O's in this group and check if any touch the border
                getComponentDFS(board, i, j, n, m, visited, component, hasBoundary);
                
                // If the component does NOT touch the boundary, capture it
                if (!hasBoundary) {
                    for (auto p : component) {
                        board[p.first][p.second] = 'X';
                    }
                }
            }
        }
    }
}

int main() {
    vector<vector<char>> matrix = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X', 'X'}, // 'O' here is captured
        {'X', 'X', 'O', 'X', 'X'}, // 'O' here is captured
        {'X', 'O', 'X', 'X', 'X'}, // 'O' here is captured
        {'X', 'O', 'X', 'O', 'O'}, // 'O' connected to boundary (safe)
        {'X', 'X', 'X', 'O', 'O'}  // 'O' on boundary (safe)
    };

    cout << "Original Board:\n";
    printMatrix(matrix);

    solve(matrix);

    cout << "\nCaptured Board:\n";
    printMatrix(matrix);

    matrix = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X', 'X'}, // 'O' here is captured
        {'X', 'X', 'O', 'X', 'X'}, // 'O' here is captured
        {'X', 'O', 'X', 'X', 'X'}, // 'O' here is captured
        {'X', 'O', 'X', 'O', 'O'}, // 'O' connected to boundary (safe)
        {'X', 'X', 'X', 'O', 'O'}  // 'O' on boundary (safe)
    };

    solveMethod1(matrix);

    cout << "\nCaptured Board get all components:\n";
    printMatrix(matrix);

    return 0;
}