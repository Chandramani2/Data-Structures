/* Minimum Window Substring */

private static void minmWindowSubstring(String s, String t) {
    int m = s.length();
    int n = t.length();
    HashMap<Character, Integer> map = new HashMap<>();
    for(int i = 0; i < n; i++) {
        map.put(t.charAt(i), map.getOrDefault(t.charAt(i),0)+1);
    }

    int l=0;
    int cnt=0;
    int minWindow = Integer.MAX_VALUE;
    int p1=-1,p2=-1;
    for(int r=0; r<m; r++) {
        char rightChar = s.charAt(r);
        // If this character is needed, increment our satisfied count
        if (map.containsKey(rightChar)) {
            if (map.get(rightChar) > 0) cnt++;
            map.put(rightChar, map.get(rightChar) - 1);
        }
        // When we have a valid window, try to shrink it from the left
        while (cnt == n) {
            int currLength = r - l + 1;
            if (currLength < minWindow) {
                minWindow = currLength;
                p1 = l;
                p2 = r;
            }
            char leftChar = s.charAt(l);
            if (map.containsKey(leftChar)) {
                map.put(leftChar, map.get(leftChar) + 1);
                // If the character is now missing from our window, decrement cnt
                if (map.get(leftChar) > 0) cnt--;
            }
            l++;
        }
    }
    if (p1 == -1) {
        System.out.println("No subarray found.");
    } else {
        System.out.println("minimum window Optimized: " + minWindow);
        System.out.println("Indices: P1: " + p1 + " P2: " + p2);
    }
}

public static void main(String[] args) {
    String s = "ddaaabbca";
    String t = "abc";
    naive(s,t);
    minmWindowSubstring(s,t);
}


private static void naive(String s, String t) {
    int minWindow = Integer.MAX_VALUE;
    int m = s.length();
    int n = t.length();
    int[] targetCount = new int[256];
    for(int i = 0; i < n; i++) {
        targetCount[t.charAt(i)]++;
    }

    int p1=-1, p2=-1;
    for(int i = 0; i < m; i++) {
       int[] currCount = new int[256];
        for(int j = i; j < m; j++) {
            currCount[s.charAt(j)]++;
            int currLength = j-i+1;
            // Fixed: Check if currCount satisfies targetCount
            if(isSatisfied(currCount, targetCount)) {
                if(currLength < minWindow) {
                    minWindow = currLength;
                    p1= i;
                    p2=j;
                }
                break; // Small optimization: no need to make the window larger
            }
        }
    }
    if (p1 == -1) {
        System.out.println("No subarray found.");
    } else {
        System.out.println("minimum window: " + minWindow);
        System.out.println("Indices: P1: " + p1 + " P2: " + p2);
    }
}

private static boolean isSatisfied(int[] curr, int[] target) {
    for(int i = 0; i < 256; i++) {
        if(curr[i] < target[i]) return false;
    }
    return true;
}
