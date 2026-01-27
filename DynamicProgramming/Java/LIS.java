private static int LISDP(int[] arr) {
    if (arr == null || arr.length == 0) return 0;
    int[] dp = new int[arr.length];
    Arrays.fill(dp, 1);

    int maxLIS = 1;
    for (int i = 1; i < arr.length; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
        maxLIS = Math.max(maxLIS, dp[i]);
    }
    return maxLIS;
}


public static void main() {
    int[] arr = {4,10,6,5,8,11,2,20};
    LISNaive(arr);
    System.out.println("LISDP: " + LISDP(arr));
}


private static void LISNaive(int[] arr) {
    List<Integer> list = new ArrayList<>();
    int n = arr.length;
    List<List<Integer>> subsequences = new ArrayList<>();
    generateAllSubsequence(0,arr,list,n,subsequences);
    System.out.println(subsequences);

    int ans = longestIncreasingSubsequenceNaive(subsequences);
    System.out.println("LIS Naive: " + ans);
}

private static int longestIncreasingSubsequenceNaive(List<List<Integer>> subsequences) {
    int m = subsequences.size();
    int ans = Integer.MIN_VALUE;
    for(List<Integer> subsequence : subsequences){
        if(isSubsequenceIncreasing(subsequence)){
            ans = Math.max(ans,subsequence.size());
        }
    }
    return ans;
}

private static boolean isSubsequenceIncreasing(List<Integer> subsequence) {

    for(int i=0; i<subsequence.size()-1; i++){
        if(subsequence.get(i)>subsequence.get(i+1)){
            return false;
        }
    }
    return true;
}

private static void generateAllSubsequence(int i, int[] arr, List<Integer> list, int n, List<List<Integer>> subsequences) {
    if(i>=n){
//        System.out.println(String.join(",", list));
        subsequences.add(new ArrayList<>(list));
        return;
    }

  // Choice 1: Pick the current element
    list.add(arr[i]);
    generateAllSubsequence(i + 1, arr, list, n, subsequences);

    // Backtrack: Remove the element to try the other path
    list.remove(list.size() - 1);

    // Choice 2: Don't pick the current element
    generateAllSubsequence(i + 1, arr, list, n, subsequences);
}









