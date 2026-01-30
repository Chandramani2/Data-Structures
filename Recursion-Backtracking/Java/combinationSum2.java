/* cannot pick same element more than once -> no duplicate combination */
private static void solution2(int[] arr, int sum) {
    Arrays.sort(arr); // we have to sort to avoid duplicate combination
    List<List<Integer>> subsequences = new ArrayList<>();
    List<Integer> current = new ArrayList<>();
    getSumRec2(arr, current, subsequences, 0, sum);
    System.out.println("Rec: " + subsequences);
}

private static void getSumRec2(int[] arr, List<Integer> current, List<List<Integer>> subsequences, int index, int sum) {
    if (sum == 0) {
        subsequences.add(new ArrayList<>(current));
        return;
    }

    for (int j = index; j < arr.length; j++) {
        // 1. Skip duplicates: Only skip if it's NOT the first time we are looking at this index in this loop
        if (j > index && arr[j] == arr[j - 1]) {
            continue;
        }

        // 2. Optimization: If the number is already bigger than the remaining sum,
        // since the array is sorted, all numbers after it will also be too big.
        if (arr[j] > sum) {
            break;
        }

        // 3. Include the current element j
        current.add(arr[j]);

        // 4. Move to j + 1 for the next level of recursion
        getSumRec2(arr, current, subsequences, j + 1, sum - arr[j]);

        // 5. Backtrack: Remove the element to try the next j in the loop
        current.remove(current.size() - 1);
    }
}

public static void main() {
    int[] arr = {10,1,2,7,6,1,5};
    int sum = 8;
    solution1UsingHashSet(arr, sum);
    solution2(arr,sum);
}



private static void solution1UsingHashSet(int[] arr, int sum) {
    Arrays.sort(arr); // we have to sort to avoid duplicate combination
    HashSet<List<Integer>> subsequences = new HashSet<>();
    List<Integer> current = new ArrayList<>();
    getSumRec(arr, current, subsequences, 0, sum);
    List<List<Integer>> list = subsequences.stream().toList();
    System.out.println("Rec: " + list);
}

private static void getSumRec(int[] arr, List<Integer> current, HashSet<List<Integer>> subsequences, int i, int sum) {

    if (sum==0) {
        subsequences.add(new ArrayList<>(current));
        return;
    }

    // Base Case 2: Failure (Out of bounds or exceeded the sum)
    if (i == arr.length || sum < 0 || arr[i]>sum) {
        return;
    }

    // Choice 1: Include arr[i].
    // Notice we stay at index 'i' so it can be picked again in the next call.
    current.add(arr[i]);
    getSumRec(arr, current, subsequences, i+1, sum - arr[i]);

    // Choice 2: Exclude arr[i] and move to the next element.
    current.remove(current.size() - 1);
    getSumRec(arr, current, subsequences, i + 1, sum);

}


