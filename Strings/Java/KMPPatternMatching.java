
private static int[] constructLPS(String s) {
    int[] LPS = new int[s.length()];
    Arrays.fill(LPS, 0);
    int x = 0;
    for (int i = 1; i < s.length(); i++) {
        x = LPS[i-1];
        while( x > 0 && s.charAt(i) != s.charAt(x)) {
            x = LPS[x-1];
        }
        if(s.charAt(i) == s.charAt(x)) {
            LPS[i] = x + 1;
        }
    }
   return LPS;
}

private static void constructLPSWithPattern(String text, String pattern, int M, int N) {
    int [] LPS = new int[N];
    int p1 = -1, p2 = -1;
    int cnt = 0;
    int prev = 0; // Length of previous longest prefix suffix
    for(int i=0; i<N; i++) {
        // While characters don't match, jump back using the pattern's LPS
        // Note: You need the pattern's pre-computed LPS array here!
        while (prev > 0 && pattern.charAt(prev) != text.charAt(i)) {
            // This is where you'd typically use lpsPattern[prev - 1]
            // For simplicity in this fix, I'll assume standard KMP logic:
            prev = LPS[prev-1];
        }
        if(pattern.charAt(prev) == text.charAt(i)) {
            prev++;
        }
        LPS[i] = prev; // Update the array!

        if (prev == M) {
            cnt++;
            // To find overlapping matches, reset prev using pattern's LPS
            // prev = lpsPattern[prev - 1];
            p2 = i;
            p1 = i - M + 1;
        }
    }

    System.out.println("TEXT LPS Array: " + Arrays.toString(LPS));
    System.out.println("Match Found: " + cnt);
    System.out.println("P1: " + p1);
    System.out.println("P2: " + p2);
}

public static void main(String[] args) {
    String TEXT = "bcabacababcab";
    int N = TEXT.length();

    String PATTERN = "abab";
    int M = PATTERN.length();

    PATTERN = PATTERN + "$";
    int[] lpsPattern = constructLPS(PATTERN);
    System.out.println("Pattern LPS Array: " + Arrays.toString(lpsPattern));

    constructLPSWithPattern(TEXT, PATTERN, M, N);
    longestPrefixSuffix(TEXT); // generate all prefix and suffix and then compare
}



private static void longestPrefixSuffix(String s) {
    List<String> prefix = new ArrayList<>();
    List<String> suffix = new ArrayList<>();
    String curr = "";
    for(int i = 0; i < s.length(); i++) {
        curr += s.charAt(i);
        prefix.add(curr);
    }
    curr = "";
    for(int i = s.length() - 1; i >= 0; i--) {
        curr = s.charAt(i) + curr;
        suffix.add(curr);
    }
    System.out.println("Given String: " + s);
    System.out.println("Prefixes: " + prefix);
    System.out.println("Suffixes: " + suffix);

    int maxLength = Integer.MIN_VALUE;
    String longest = "";
    for(int i = 0; i < prefix.size()-1; i++) { // ignore the last as it contains all the characters
        if(prefix.get(i).equalsIgnoreCase(suffix.get(i))) {
            if(maxLength < prefix.get(i).length()) {
                maxLength = prefix.get(i).length();
                longest = prefix.get(i);
            }
//            maxLength = Math.max(maxLength, prefix.get(i).length());
        }
    }
    System.out.println("LPS: " + longest);
}

