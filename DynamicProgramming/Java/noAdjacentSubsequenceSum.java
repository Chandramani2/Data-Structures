/* Max Subsequence sum such that no 2 adjacent elements are picked */

private static int maxSubsequenceSumWithNoAdjacentElement(int[] arr, int n) {
    int [] dp = new int[n+1];
    dp[0] = 0;
    dp[1] = arr[0];
    for(int i=2; i<=n; i++){
        dp[i] = Math.max(dp[i-1], dp[i-2] + arr[i-1]);
    }
    return dp[n];
}

// Function to calculate the maximum Sum value
static int maxSum(int[] arr, int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];

    // Set previous 2 values
    int secondLast = 0, last = arr[0];

    // Compute current value using previous
    // two values. The final current value
    // would be our result
    int res = 0;
    for (int i = 1; i < n; i++) {
        res = Math.max(arr[i] + secondLast, last);
        secondLast = last;
        last = res;
    }

    return res;
}

public static void main() {

    int [] arr = {3,5,2,8,-3,18,4,10,6,12,-5,2,4};
    System.out.println(maxSubsequenceSumWithNoAdjacentElement(arr, arr.length));
    System.out.println(maxSum(arr, arr.length));

}








