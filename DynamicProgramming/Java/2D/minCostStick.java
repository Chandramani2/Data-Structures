/* Minimum Cost to cut the Stick
    int[] cuts = {1,3,4,5}; // we make a cut at this positions , // sorting is important
    initial length of stick = 7
    now make a cut at 1: stick1(0,1), stick2(1,7)   ---> COST = 7
    MAKE A CUT AT 3: Stick1(0,1), Stick2(1,3), stick3(3,7) ----> COST = 7 + 6(Max stick length (7-1)) = 13
    Make a cut at 4: Stick1(0,1), Stick2(1,3), Stick3(3,4), Stick4(4,7) ---> COST = 13 + 4 = 17
    Make a cut at 5: Stick1(0,1), Stick2(1,3), Stick3(3,4), Stick4(4,5), Stick5(5,7) ----> COST = 17 + 3 = 20
    ... Now we have to minimize this cost by re-arranging the array
    int k = 7; // length of the stick
* */


import java.util.*;
import java.util.stream.Collectors;

public class Main{
    private static int recursion(int i, int j, List<Integer> cuts) {
        if(i>j) return 0;

        int mini = Integer.MAX_VALUE;
        for(int ind = i; ind<=j; ind++){
            int cost = cuts.get(j+1) - cuts.get(i-1) + recursion(i, ind-1, cuts) + recursion(ind+1, j, cuts);
            mini = Math.min(mini,cost);
        }
        return mini;
    }

    private static int cost(int n,   int[] cuts) {
        List<Integer> arr = Arrays.stream(cuts)
                .boxed()
                .collect(Collectors.toList());

        arr.add(0,0);
        arr.add(n);
        arr.sort(null);   // Important to sort
        int ans  = recursion(1, cuts.length, arr);
        System.out.println("Recursion: " + ans);

        // Method DP
        int c = cuts.length;
        List<List<Integer>> dp = new ArrayList<>();
        for(int i = 0; i <= c; i++){
            List<Integer> row = new ArrayList<>(Collections.nCopies(c+1, -1));
            dp.add(row);
        }

        ans  = dpMemoization(1, cuts.length, arr, dp);
        System.out.println("DP Memoization: " + ans);
        return ans;
    }

    private static int dpMemoization(int i, int j, List<Integer> cuts, List<List<Integer>> dp) {
        if(i>j) return 0;
        if(dp.get(i).get(j)!=-1) return dp.get(i).get(j);
        int mini = Integer.MAX_VALUE;
        for(int ind = i; ind<=j; ind++){
            int cost = cuts.get(j+1) - cuts.get(i-1) + recursion(i, ind-1, cuts) + recursion(ind+1, j, cuts);
            mini = Math.min(mini,cost);
        }
        dp.get(i).set(j, mini);
        return mini;
    }


    public static void main(String[] args) {

        int[] cuts = {1,3,4,5};
        int n = 7; // length of the stick
        int ans = cost(n, cuts);
        System.out.println("Min Cost: " + ans);

//        List<Integer> arr = new ArrayList<>();
//        for (int cut : cuts) {
//            arr.add(cut);
//        }

//        List<Integer> arr = Arrays.stream(cuts).boxed().toList(); // Immutable can't modify

    }


}


