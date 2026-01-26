/*  0-1 knapsack
    Given two arrays, profit[] and weight[], where each element represents the profit and
    weight of an item respectively, also given an integer W representing the maximum capacity
    of the knapsack (the total weight it can hold).

    Input:  W = 4, profit[] = [1, 2, 3], weight[] = [4, 5, 1]
    Output: 3
    Explanation: There are two items which have weight less than or equal to 4. If we select the
    item with weight 4, the possible profit is 1. And if we select the item with weight 1, the possible
    profit is 3. So the maximum possible profit is 3. Note that we cannot put both the items with weight
    4 and 1 together as the capacity of the bag is 4.

    Dp[N,W] -> N items within weight <= W
    KnapSack DP[i,j] = Max value which can be obtained using first 'i' items,
    Within Knapsack weight <= W

    dp[i,j] = max(dp(i-1,j), dp(i-1, j-w[i]) + value[i])
             (Not picking)        (Picking) (j>=w[i])
 */
public static void main() {
    int W = 4;
    int[] value = {1,2,3};
    int[] weight = {4,5,1};
    System.out.println("Recursion: " + knapSack(W, value, weight));
    System.out.println("DP: " + knapSackDP(W, value, weight));

}

private static int knapSack(int W, int[] value, int[] weight) {
    int n = value.length;
    return knapSackRec(W, value, weight, n);

//    // Memoization table to store the results
//    int[][] memo = new int[n + 1][W + 1];
//
//    // Initialize memoization table with -1
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= W; j++)
//            memo[i][j] = -1;
//    }
}

private static int knapSackRec(int W, int[] value, int[] weight, int n) {
    if(n==0 || W==0) return 0;
    int pick = 0;

    // Check if we have previously calculated the same subproblem
//    if (memo[n][W] != -1)
//        return memo[n][W];

    // Pick nth item if it does not exceed the capacity of knapsack
    if(weight[n-1] <= W){
        pick = value[n-1] + knapSackRec(W-weight[n-1], value, weight, n-1);
    }
    int notPick = knapSackRec(W, value, weight, n-1);

    return Math.max(pick, notPick);
    // Store the result in memo[n][W] and return it
//    return memo[n][W] = Math.max(pick, notPick);
}


private static int knapSackDP(int W, int[] value, int[] weight) {
    int n = weight.length;
    int [][] dp = new int[n+1][W+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            if(i==0 || j==0) dp[i][j] = 0;  // If there is no item or the knapsack's capacity is 0
            else{
                int pick = 0;
                if(weight[i-1] <= j)  pick = value[i-1] + dp[i-1][j-weight[i-1]];
                int notPick = dp[i-1][j];
                dp[i][j] = Math.max(pick, notPick);
            }
        }
    }
    return dp[n][W];


    // Initializing dp array
//    int[] dp = new int[W + 1];
//
//    // Taking first i elements
//    for (int i = 1; i <= wt.length; i++) {
//
//        // Starting from back, so that we also have data of
//        // previous computation of i-1 items
//        for (int j = W; j >= wt[i - 1]; j--) {
//            dp[j] = Math.max(dp[j], dp[j - wt[i - 1]] + val[i - 1]);
//        }
//    }
//    return dp[W];
}








