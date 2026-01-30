

public static void main() {
    int[] arr = {2,3,6,7};
    int sum = 7;
    List<List<Integer>> subsequences = new ArrayList<>();
    List<Integer> current = new ArrayList<>();
    getSumRec(arr, current, subsequences, 0, sum);
    System.out.println("Rec: " + subsequences);
}

private static void getSumRec(int[] arr, List<Integer> current, List<List<Integer>> subsequences, int i, int sum) {

    if (sum==0) {
        subsequences.add(new ArrayList<>(current));
        return;
    }

    // Base Case 2: Failure (Out of bounds or exceeded the sum)
    if (i == arr.length || sum < 0) {
        return;
    }
    // Choice 1: Include arr[i].
    // Notice we stay at index 'i' so it can be picked again in the next call.
    current.add(arr[i]);
    getSumRec(arr, current, subsequences, i, sum - arr[i]);

    // Choice 2: Exclude arr[i] and move to the next element.
    current.remove(current.size() - 1);
    getSumRec(arr, current, subsequences, i + 1, sum);

}


