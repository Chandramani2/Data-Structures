/* Best Time to Buy & sell Stock
    - Buy as many times and sell
    - Only one stock can hold
*/


import java.util.*;

public class Main{

    private static long dpMemoization(int ind, boolean canBuy, int[] arr, int n, List<List<Long>> dp){
        if(ind==n) return 0;
        int index = 1; // 1st index - cannot buy
        if(canBuy) index = 0;  // 0th index - can buy
        if(dp.get(ind).get(index)!=-1) return dp.get(ind).get(index);

        long profit = 0;
        if(canBuy){
            profit = Math.max(-arr[ind] + dpMemoization(ind+1, false, arr, n, dp),
                    0 + dpMemoization(ind + 1, true, arr, n, dp));
        }
        else{
            profit  = Math.max(arr[ind] + dpMemoization(ind+1, true, arr, n, dp),
                    0 + dpMemoization(ind + 1, false, arr, n, dp));
        }

        dp.get(ind).set(index, profit);
        return profit;
    }

    private static long dpTabulation(int[] arr, int n){

        List<List<Long>> dp = new ArrayList<>();
        for (int i=0; i<=n; i++){
            List<Long> row = new ArrayList<>(Collections.nCopies(2,0L));
            dp.add(row);
        }
        // dp[n][0] = dp[n][1] = 0
        dp.get(n).set(0, 0L);
        dp.get(n).set(1,0L);
        boolean canBuy = false;
        for(int ind = n-1; ind>=0; ind--){
            for(int buy =0; buy<=1; buy++){
                long profit = 0;
                if(buy==0) canBuy = false;
                if(buy==1) canBuy = true;

                if(canBuy){
                    profit = Math.max(-arr[ind] + dp.get(ind+1).get(0),
                            0 + dp.get(ind+1).get(1));
                }
                else{
                    profit  = Math.max(arr[ind] +dp.get(ind+1).get(1),
                            0 + dp.get(ind+1).get(0));
                }

                dp.get(ind).set(buy,profit);
            }
        }
      return dp.get(0).get(1);
    }

    private static long recursion(int ind, boolean canBuy, int[] arr, int n){
        if(ind==n) return 0;

        long profit = 0;
        if(canBuy){
            profit = Math.max(-arr[ind] + recursion(ind+1, false, arr, n),
                            0 + recursion(ind + 1, true, arr, n));
        }
        else{
            profit  = Math.max(arr[ind] + recursion(ind+1, true, arr, n),
                    0 + recursion(ind + 1, false, arr, n));
        }

        return profit;
    }


    private static void maxProfit(int[] arr, int n) {
        long ans = recursion(0, true, arr, n);
        System.out.println("Recursion: " + ans);

        //DP Method - Memoization
        List<List<Long>> dp = new ArrayList<>();
        for (int i=0; i<n; i++){
            List<Long> row = new ArrayList<>(Collections.nCopies(2,-1L));
            dp.add(row);
        }
        System.out.println(dp);
        ans = dpMemoization(0,true,arr,n,dp);
        System.out.println("DP Memoization: " + ans);

        // DP Method - Tabulation
        ans = dpTabulation(arr,n);
        System.out.println("Dp Tabulation: " + ans);
    }

    public static void main(String[] args) {
        int[] arr = {7,1,5,3,6,4};
        int n = arr.length;
        maxProfit(arr, n);
    }


}


