
/*
    String s1, s2, both of them are binary strings, both are of same length.. length<=10^5
    s1 are immutable
    we can reorder s2
    XOR of s1 and reordered s2 is maximum

    s1 = "1010"
    s2 = "1110"

    ans = max(1010 ^ 1110, 1010 ^ 0111, 1010 ^ 1011, 1010 ^ 1101) = 1101
 */
static String maxRes = "";
public static void main(String[] args){
    String s1 = "1010";
    String s2 = "1010";
    char[] s = s2.toCharArray();

    int [][] memo = new int[s2.length()][s2.length()];
    maxXor(s1, s, 0);
//    String xor = calculateXor(s1,s2);
//    System.out.println(xor);
    System.out.println(maxRes);
    String ans = optimized(s1,s2);
    System.out.println(ans);
}

private static String optimized(String s1, String s2) {
    int n = s1.length();
    int m = s2.length();
    int ones = 0;
    int zeros = 0;
    for(char c: s2.toCharArray()){
        if(c=='1') ones++;
    }
    zeros = n-ones;
    String ans = "";

    for(int i=0; i<n; i++){
        char c = s1.charAt(i);
        if(c=='1'){
            if(zeros > 0){
                ans = ans + '1';
                zeros--;
            }
            else{
                ans = ans + '0';
                ones--;
            }
        }
        else{
            if(ones > 0){
                ans = ans + '1';
                ones--;
            }
            else{
                ans = ans + '0';
                zeros--;
            }
        }
    }
    return ans;
}

private static String calculateXor(String s1, String s2){
    StringBuilder s = new StringBuilder();
    int n = s1.length();
    for(int i = 0; i < n; i++){
        s.append(s1.charAt(i) == s2.charAt(i)?0:1);
    }
    return s.toString();
}

private static void maxXor(String s1, char[] s2, int i) {
    if(i==s2.length){
        String currentXor = calculateXor(s1,new String(s2));
        if(currentXor.compareTo(maxRes) > 0){
            maxRes = currentXor;
        }
    }

    for(int j= i; j<s2.length; j++){
        swap(s2, j, i);
        maxXor(s1, s2, j+1);
        swap(s2, j, i);
    }

}

private static void swap(char[] arr, int i, int j){
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}






