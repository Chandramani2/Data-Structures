/*
    Subset Sum equal to target - Generate all Subsequences and check if any of them gives a sum of k
    1. Express(ind, target)
    2. Explore Possibilities of that index -> arr[ind] part of the subsequence || arr[ind] not part of the subsequence
    3. return True|False
 */

private static boolean isSubsetPresent(int[] nums, int n, int ind, int target) {
    if(target == 0) return true;
    if(ind==0) return (nums[0] == target);

    boolean notTake = isSubsetPresent(nums, n, ind-1, target);
    boolean take = false;
    if(target>=nums[ind])
            take = isSubsetPresent(nums, n, ind-1, target-nums[ind]);

    return notTake || take;
}

/*
-1 → uncomputed
0 → false
1 → true
 */
private static boolean isSubsetPresentMemo(int[] nums, int n, int ind, int target, int[][] dp) {
    if(target == 0) return true;
    if(ind==0) return (nums[0] == target);

    if(dp[ind][target]!=-1) return dp[ind][target]==1;

    boolean notTake = isSubsetPresentMemo(nums, n, ind-1, target, dp);
    boolean take = false;
    if(target>=nums[ind])
        take = isSubsetPresentMemo(nums, n, ind-1, target-nums[ind], dp);

    boolean res = take || notTake;
    dp[ind][target] = res ? 1 : 0;
    return res;
}

public static void main(String[] args){
    int[] nums = {1,2,3,4};
    int target = 5;
    int n = nums.length;

    System.out.println("Is Subset present: " + isSubsetPresent(nums,n,n-1, target));

    int[][] dp = new int[n+1][target+1];

    for(int i=0;i<=n;i++)
        for(int j=0;j<=target;j++)
            dp[i][j] = -1;

    System.out.println("Is SubsetMemo present: " + isSubsetPresentMemo(nums,n,n-1, target, dp));
}




