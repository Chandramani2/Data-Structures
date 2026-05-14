// Using Tabulation (Bottom-Up DP):
class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] newNums = new int[n + 2];
        newNums[0] = 1;
        newNums[n + 1] = 1;

        int[][] dp = new int[n + 2][n + 2];

        for (int i = 0; i < n; i++) newNums[i + 1] = nums[i];

        // i = left boundary of current interval, iterate from right to left
        // so that smaller subproblems (dp[i][k-1], dp[k+1][j]) are already filled
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= n; j++) {
                if (i > j) continue;
                int max = Integer.MIN_VALUE;

                // k = the LAST balloon burst in range [i, j]
                for (int k = i; k <= j; k++) {
                    int cost = newNums[i - 1] * newNums[k] * newNums[j + 1]
                             + dp[i][k - 1]
                             + dp[k + 1][j];
                    max = Math.max(max, cost);
                }
                dp[i][j] = max;
            }
        }

        return dp[1][n];
    }
}

/*
// Using Memoization (Top-Down DP):
class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] newNums = new int[n + 2];
        newNums[0] = 1;
        newNums[n + 1] = 1;

        int[][] dp = new int[n + 1][n + 1];
        for (int[] row : dp) Arrays.fill(row, -1);

        for (int i = 0; i < n; i++) newNums[i + 1] = nums[i];

        return func(dp, 1, n, newNums);
    }

    private int func(int[][] dp, int i, int j, int[] newNums) {
        // Base case: empty range yields 0 coins
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int max = Integer.MIN_VALUE;
        // Try every balloon k as the last one burst in [i, j]
        for (int k = i; k <= j; k++) {
            int cost = newNums[i - 1] * newNums[k] * newNums[j + 1]
                     + func(dp, i, k - 1, newNums)
                     + func(dp, k + 1, j, newNums);
            max = Math.max(max, cost);
        }

        return dp[i][j] = max;
    }
}
*/

/*
// Using Recursion (Pure, gives TLE @ testcase 31):
// Without memoization, the same subproblems are recomputed exponentially.
class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] newNums = new int[n + 2];
        newNums[0] = 1;
        newNums[n + 1] = 1;

        for (int i = 0; i < n; i++) newNums[i + 1] = nums[i];

        return func(1, n, newNums);
    }

    private int func(int i, int j, int[] newNums) {
        // Base case: empty range
        if (i > j) return 0;

        int max = Integer.MIN_VALUE;
        // Try every balloon k as the last one burst in [i, j]
        for (int k = i; k <= j; k++) {
            int cost = newNums[i - 1] * newNums[k] * newNums[j + 1]
                     + func(i, k - 1, newNums)
                     + func(k + 1, j, newNums);
            max = Math.max(max, cost);
        }

        return max;
    }
}
*/
