

public static void main() {
    int[] arr = {1,2,1};
    int sum = 2;
    List<List<Integer>> subsequences = new ArrayList<>();
    List<Integer> current = new ArrayList<>();
    generateSubsequences(arr, current, subsequences, 0);
    System.out.println(subsequences);
    getSum(subsequences, sum);
    subsequences.clear();
    current.clear();
    getSumRec(arr, current, subsequences, 0, 0, sum);
    System.out.println("Rec: " + subsequences);
}

private static void getSumRec(int[] arr, List<Integer> current, List<List<Integer>> subsequences, int i, int currSum, int sum) {
    if (i == arr.length) {
        if (currSum == sum) {
            subsequences.add(new ArrayList<>(current));
        }
        return;
    }

    current.add(arr[i]);
    getSumRec(arr, current, subsequences, i + 1, currSum + arr[i], sum);
    current.remove(current.size() - 1);
    getSumRec(arr, current, subsequences, i + 1, currSum, sum);

}

private static void getSum(List<List<Integer>> subsequences, int sum) {
    List<List<Integer>> result = subsequences.stream().filter(sub -> sub.stream().mapToInt(x -> x).sum() == sum)
            .toList();
    System.out.println(result);
}

private static void generateSubsequences(int[] arr, List<Integer> current, List<List<Integer>> subsequences, int i) {
    if(i>=arr.length) {
        subsequences.add(new ArrayList<>(current));
        return;
    }
    current.add(arr[i]);
    generateSubsequences(arr, current, subsequences, i+1);
    current.remove(current.size()-1);
    generateSubsequences(arr, current, subsequences, i+1);
}


