private static void getSubsetSums(int[] arr, int n) {
    List<Integer> list = new ArrayList<>();
    getSubsetSumRec(0,arr,list,n, 0);
    System.out.println("Recursive Sum: " + list);
}

private static void getSubsetSumRec(int i, int[] arr, List<Integer> list, int n, int sum) {
    if(i>=n){
        list.add(sum);
        return;
    }
    getSubsetSumRec(i+1,arr,list,n,sum+arr[i]);
    getSubsetSumRec(i+1,arr,list,n,sum);
}

public static void main(String[] args) {
    int[] arr = {3,1,2};
    getSubsetSums(arr,arr.length);

    List<List<Integer>> list = getAllSubsets(arr, arr.length); // Power Set
    getSubsetSumFromList(list);
}

private static void getSubsetSumFromList(List<List<Integer>> list) {
    List<Integer> list1 = new ArrayList<>();
    for(int i=0;i<list.size();i++){
        list1.add(list.get(i).stream().mapToInt(Integer::intValue).sum());
    }
    System.out.println("Power Set Sum: " + list1);
}

private static List<List<Integer>> getAllSubsets(int[] arr, int n) {
   List<List<Integer>> list = new ArrayList<>();

    // Number of subsets: 1<<n = 2^n
    //  Bitset 0 -> don't pick, 1 -> pick
    int noOfSubsets = 1<<n;
    for(int i=0; i < noOfSubsets; i++){  // iterating on every subset's bits value (0,0,0) (0,0,1), (0,1,0), (0,1,1)....
        List<Integer> subset = new ArrayList<>();
        for(int j=0; j<n; j++){   // iterating on n bits
            if((i & (1<<j)) > 0)
                subset.add(arr[j]);
        }
        list.add(subset);
    }
    System.out.println("Power Sets: " + list);
    return list;
}


