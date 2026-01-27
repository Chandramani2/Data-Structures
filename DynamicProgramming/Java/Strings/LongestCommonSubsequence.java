


public static int lcsRecursive(String s1, String s2, int m, int n) {
    // Base case: if either string is exhausted
    if (m == 0 || n == 0) return 0;

    // If characters match, add 1 and recurse for the rest
    if (s1.charAt(m - 1) == s2.charAt(n - 1)) {
        return 1 + lcsRecursive(s1, s2, m - 1, n - 1);
    } else {
        // If they don't match, take the maximum of two choices
        return Math.max(lcsRecursive(s1, s2, m, n - 1),
                lcsRecursive(s1, s2, m - 1, n));
    }
}

public static int lcsMemo(String s1, String s2, int m, int n, int[][] memo) {
    if (m == 0 || n == 0) return 0;

    // If we've already solved this sub-problem, return it
    if (memo[m][n] != -1) return memo[m][n];

    if (s1.charAt(m - 1) == s2.charAt(n - 1)) {
        return memo[m][n] = 1 + lcsMemo(s1, s2, m - 1, n - 1, memo);
    } else {
        return memo[m][n] = Math.max(lcsMemo(s1, s2, m, n - 1, memo),
                lcsMemo(s1, s2, m - 1, n, memo));
    }
}

public static int lcsTabulation(String s1, String s2) {
    int m = s1.length();
    int n = s2.length();
    int[][] dp = new int[m + 1][n + 1];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                // Diagonal move: Match found
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // Max of top or left neighbor
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

public static void main() {
    String s1 = "ABCDGH";
    String s2 = "AEDFHR";
    longestCommonSubsequenceNaive(s1, s2);

    int m = s1.length();
    int n = s2.length();

    int ans = lcsRecursive(s1,s2, m, n);
    System.out.println("lcsRecursive: " + ans);

    int [][] memo = new int[m+1][n+1];
    for (int[] row : memo) {
        Arrays.fill(row, -1);
    }
    ans = lcsMemo(s1,s2, m, n, memo);
    System.out.println("lcsMemo: " + ans);

    ans = lcsTabulation(s1, s2);
    System.out.println("lcsTabulation: " + ans);
}


private static void longestCommonSubsequenceNaive(String s1, String s2) {
    List<String> subsequenceS1 = new ArrayList<>();
    List<String> subsequenceS2 = new ArrayList<>();
    printAllSubsequence(s1, subsequenceS1, "");
    System.out.println(subsequenceS1);
    printAllSubsequence(s2, subsequenceS2, "");
    System.out.println(subsequenceS2);

    int ans = Integer.MIN_VALUE;
    String ansLCS = "";
    HashSet<String> hashSet = new HashSet<>();
    hashSet.addAll(subsequenceS1);
    for(String s: subsequenceS2) {
        if(hashSet.contains(s)) {
            if(s.length() > ans) {
                ans = s.length();
                ansLCS = s;
            }
        }
    }

    System.out.println("LCS Naive: " + ans + " String is: " + ansLCS);
}

private static void printAllSubsequence(String s, List<String> ans, String curr) {
    if(s.isEmpty()) {
        ans.add(curr);
        return;
    }
    // Include the first character
    printAllSubsequence(s.substring(1), ans, curr+s.charAt(0));
    // Exclude the first character
    printAllSubsequence(s.substring(1), ans, curr);
}












