

public static void main() {
    int[] stalls = {2,6,11,14,19,25,30,39,43};
    int numberOfCows  = 4;
    System.out.println("Maximize Minimum Distance between cows: " + aggressiveCows(stalls, numberOfCows));
}

//TTTTTTTTTFFFFFFFFF pattern
private static int aggressiveCows(int[] stalls, int numberOfCows) {
    int n = stalls.length;
    int l = stalls[0];
    int h = stalls[n-1] - stalls[0];
    int ans = Integer.MIN_VALUE;
    while(l<=h) {
        int mid = l+(h-l)/2;
        if(canPlaceCow(mid, stalls, numberOfCows)){
            ans = mid;
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    return ans;
}

private static boolean canPlaceCow(int mid, int[] stalls, int numberOfCows) {
    int cowsPlaced = 1;
    int lastCowsPlaced = stalls[0];
    for(int i=1; i<stalls.length; i++) {
        if((stalls[i]-lastCowsPlaced) >= mid) {
            cowsPlaced++;
            lastCowsPlaced = stalls[i];
        }
    }
    return cowsPlaced >= numberOfCows;
}







