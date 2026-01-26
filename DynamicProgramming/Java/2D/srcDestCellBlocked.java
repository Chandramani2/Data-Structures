
public static void main() {
    int[][] grid = {
            {1, 1, 0, 1, 1},
            {1, 1, 1, 1, 1},
            {0, 1, 0, 1, 1},
            {1, 1, 1, 0, 1},
            {1, 1, 1, 1, 1}
    };

    System.out.println("Total ways: " + countWays(grid));
    System.out.println("Total ways: " + countWaysSpaceOptimized(grid));

}

private static int countWays(int[][] grid) {
    int row = grid.length;
    int col = grid[0].length;

    // If the start or end is blocked, there are 0 ways
    if (grid[0][0] == 0 || grid[row - 1][col - 1] == 0) {
        return 0;
    }

    int[][] dp = new int[row][col];

    // initialize the starting point
    dp[0][0] = 1;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            // If the current cell is an obstacle, skip it (it remains 0)
            if(grid[i][j] == 0){
                dp[i][j] = 0;
                continue;
            }

            if(i>0) dp[i][j] += dp[i-1][j];
            if(j>0) dp[i][j] += dp[i][j-1];
        }
    }
    return dp[row - 1][col - 1];
}

public static int countWaysSpaceOptimized(int[][] grid) {
    int rows = grid.length;
    int cols = grid[0].length;

    // Base case: check if start or end is blocked
    if (grid[0][0] == 0 || grid[rows - 1][cols - 1] == 0) return 0;

    // dp[j] will store the number of ways to reach the current cell in column j
    int[] dp = new int[cols];
    dp[0] = 1; // Starting point

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 0) {
                dp[j] = 0; // Obstacle: no ways to reach this cell
            } else if (j > 0) {
                // Current ways = ways from above (already in dp[j])
                // + ways from left (dp[j-1])
                dp[j] += dp[j - 1];
            }
        }
    }

    return dp[cols - 1];
}











