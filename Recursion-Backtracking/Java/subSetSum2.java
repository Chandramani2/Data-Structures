private static void getSubsetSums(int[] arr, int n) {
    List<Integer> list = new ArrayList<>();
    List<List<Integer>> subsets = new ArrayList<>();
    Arrays.sort(arr);
    getSubsetSumRec(0,arr,list,subsets, n);
    System.out.println("Recursive Sum: " + subsets);
}

private static void getSubsetSumRec(int i, int[] arr, List<Integer> list, List<List<Integer>> subsets, int n) {
    subsets.add(new ArrayList<>(list));

    for(int j=i; j<n; j++){
        if(j !=i && arr[j] == arr[j-1]) continue;

        list.add(arr[j]);
        getSubsetSumRec(j+1,arr,list, subsets, n);
        list.remove(list.size()-1);
    }

}

public static void main(String[] args) {
    int[] arr = {1,2,2,3,3}; // Remove Duplicate Subsets
    getSubsetSums(arr,arr.length);

    HashSet<List<Integer>> list = getAllSubsets(arr, arr.length); // Power Set
    getSubsetSumFromList(list);
}

private static void getSubsetSumFromList(HashSet<List<Integer>> powerSet) {
    List<Integer> list1 = new ArrayList<>();
   for(List<Integer> subList : powerSet){
       int currentSum = subList.stream().mapToInt(Integer::intValue).sum();
       list1.add(currentSum);
   }
    System.out.println("Power Set Sum: " + list1);
}

private static HashSet<List<Integer>> getAllSubsets(int[] arr, int n) {
   HashSet<List<Integer>> setArray = new HashSet<>();

    // Number of subsets: 1<<n = 2^n
    //  Bitset 0 -> don't pick, 1 -> pick
    int noOfSubsets = 1<<n;
    for(int i=0; i < noOfSubsets; i++){  // iterating on every subset's bits value (0,0,0) (0,0,1), (0,1,0), (0,1,1)....
        List<Integer> subset = new ArrayList<>();
        for(int j=0; j<n; j++){   // iterating on n bits
            if((i & (1<<j)) > 0)
                subset.add(arr[j]);
        }
        setArray.add(subset);
    }
    System.out.println("Power Sets: " + setArray);
    return setArray;
}


