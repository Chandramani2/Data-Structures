
public static void main(String[] args) {
    int[] nums = {1,1,2};
    int n = nums.length;
    int[] result = new int[n];
    Arrays.fill(result, -1);
    permutation(nums,n, 0, result);
}

private static void permutation(int[] nums, int n, int i, int[] result) {
    if (i == n) {
        System.out.println(Arrays.toString(result));
        return;
    }
    for(int j=0;j<n;j++){
        if(result[j]==-1){
            result[j] = nums[i];
            permutation(nums, n, i+1, result);
            result[j] = -1;
        }
    }

}
