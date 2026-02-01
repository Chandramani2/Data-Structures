/* Longest Substring Without Repeating Character */

private static void longestSubstringWithoutRepeatingCharacter(String s) {
    int n = s.length();
    int l=0, p1=-1, p2=-1;
    int maxLen = Integer.MIN_VALUE;
    int[] count = new int[256];
    Arrays.fill(count, -1);
    for(int r=0; r<n; r++){
        if(count[s.charAt(r)] != -1){ // in the map
            if(count[s.charAt(r)] >= l){
                l = count[s.charAt(r)] + 1;
            }
        }
        int currentLength = r-l+1;
        if(currentLength > maxLen){
            maxLen = currentLength;
            p1 = l;
            p2 = r;
        }
        count[s.charAt(r)] = r;
    }
    if (p1 == -1) {
        System.out.println("No subarray found.");
    } else {
        System.out.println("maxLength Optimized: " + maxLen);
        System.out.println("Indices: P1: " + p1 + " P2: " + p2);
    }
}
public static void main(String[] args) {
    String s = "cadbzabcd";
    naive(s);
    longestSubstringWithoutRepeatingCharacter(s);
}

private static void naive(String s) {
    int n = s.length();
    int maxLen = Integer.MIN_VALUE;
    int p1=-1, p2=-1;
    for(int i=0; i<n; i++){
        int[] count = new int[256];
        Arrays.fill(count, 0);
        for(int j=i; j<n; j++){
            int currLength = j-i+1;
            if(count[s.charAt(j)] == 0){
                count[s.charAt(j)]++;
                if(currLength > maxLen){
                    maxLen = currLength;
                    p1 = i;
                    p2 = j;
                }
            }
            else break;
        }
    }
    if (p1 == -1) {
        System.out.println("No subarray found.");
    } else {
        System.out.println("maxLength: " + maxLen);
        System.out.println("Indices: P1: " + p1 + " P2: " + p2);
    }
}

