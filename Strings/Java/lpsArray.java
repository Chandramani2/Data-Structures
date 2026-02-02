
private static void LPS(String s) {
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
    System.out.println("LPS: " + Arrays.toString(LPS));
}


public static void main(String[] args) {
    String s = "cacxcacabcacxcacx";
    longestPrefixSuffix(s); // generate all prefix and suffix and then compare
    LPS(s);
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

