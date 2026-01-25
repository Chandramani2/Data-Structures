private static int maxSubArraySum1(int[] arr) { // O(N^3)
    int n = arr.length;
    int ans = Integer.MIN_VALUE;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum+=arr[k];
                ans = Math.max(ans,sum);
            }
        }
    }
    return ans;
}

private static int maxSubArraySum2(int[] arr) { // O(N^3)
    int n = arr.length;
    int ans = Integer.MIN_VALUE;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
           sum+=arr[j];
           ans = Math.max(ans,sum);
        }
    }
    return ans;
}

private static int maxSubArraySumDP(int[] arr) { // O(N^3)
    int n = arr.length;
    int [] dp = new int[n];

    // dp_state: max SubArray Sum ending at i
    dp[0] = arr[0];
    for(int i=1; i<n; i++){
        dp[i] = Math.max(dp[i], arr[i] + dp[i-1]);
    }

    // get the result as an int
    int res = Arrays.stream(dp).reduce(Math::max).getAsInt();
    System.out.println("Max DP: " + res);

    return Arrays.stream(dp).max().getAsInt();
}

private static int maxSubArraySumDPOptimized(int[] arr) { // O(N^3)
    int n = arr.length;
   int prev = arr[0], ans = arr[0];
    for(int i=1; i<n; i++){
        int curr = Math.max(arr[i], prev+arr[i]);
        prev = curr;
        ans = Math.max(ans, prev);
    }
    return ans;
}

public static void main() {
    int arr[] = {3,-1,8,-12,10,-4,3,9,-2,8,-40,7};
//    int arr[] = {3,-1,-8,-12,-10,-4,-3,-9,-2,-8,-40,-7};

    System.out.println(maxSubArraySum1(arr));
    System.out.println(maxSubArraySum2(arr));
    System.out.println(maxSubArraySumDP(arr));
    System.out.println("Max DP Optimized: " + maxSubArraySumDPOptimized(arr));

}






