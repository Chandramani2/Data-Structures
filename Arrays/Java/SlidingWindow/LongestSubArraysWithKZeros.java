/*
    Longest Subarray with at most k zeros
 */
private int longestSubarrayWithKZeros(int[] nums, int k) {
    int n = nums.length;
    int l = 0;
    int ans = Integer.MIN_VALUE;
    int numberOfZeros = 0;
    for(int r = 0; r < n; r++) {
        if(nums[r] == 0) {
            numberOfZeros++;
        }
        while(numberOfZeros > k) {
            if(nums[l] == 0) {
                numberOfZeros--;
            }
            l++;
        }
        ans = Math.max(ans, r-l+1);
    }
    return ans;
}

void main() {
    int[] nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int ans = longestSubarrayWithKZerosNaive(nums,k);
    System.out.println("Naive: " + ans);
    ans = longestSubarrayWithKZeros(nums,k);
    System.out.println("SLidingWindow: " + ans);
}


private int longestSubarrayWithKZerosNaive(int[] nums, int k) {
    int n = nums.length;
    int ans = Integer.MIN_VALUE;
    int p1=-1, p2=-1;
    for(int i=0; i<n; i++){
        int numberOfZeros = 0;
        for(int j=i; j<n; j++){
            int currLength = j-i+1;
            if(nums[j]==0){
                numberOfZeros++;
                if(numberOfZeros <= k){
                    if(currLength > ans){
                        ans = currLength;
                        p1 = i;
                        p2 = j;
                    }

                }
            }
        }

    }
    // Printing the subarray
    if (p1 != -1) {
        System.out.print("Longest Subarray: ");
        for (int i = p1; i <= p2; i++) {
            System.out.print(nums[i] + (i == p2 ? "" : ", "));
        }
        System.out.println();
    } else {
        System.out.println("No valid subarray found.");
    }
    return ans;
}

