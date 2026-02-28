private static void permutation(int[] nums, int n, List<Integer> result, boolean[] visited, List<List<Integer>> ans) {
    if (result.size() == n) {
        ans.add(new ArrayList<>(result));
        return;
    }

    for(int j=0;j<n;j++){
        if(visited[j]){
            continue;
        }
        if(j>0 && nums[j]==nums[j-1] && !visited[j-1]){
            continue;
        }
        visited[j] = true;
        result.add(nums[j]);
        permutation(nums, n, result, visited, ans);

        visited[j] = false;
        result.removeLast();

    }
}

public static void main(String[] args) {
    int[] nums = {1,1,2};
    int n = nums.length;
    Arrays.sort(nums);  //Sorting important

    List<List<Integer>> ans = new ArrayList<>();
    boolean[] visited = new boolean[n];
    Arrays.fill(visited, false);
    permutation(nums,n, new ArrayList<>(), visited, ans);
    System.out.println(ans);
}


