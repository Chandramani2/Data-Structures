/* Best Time to Buy & sell Stock - can be done only once */

import java.util.*;
import java.util.stream.Collectors;

public class Main{

    private static void maxProfit(int[] arr, int n) {
        int minimumOnLeft = arr[0];
        int profit = 0;
        for(int i=1; i<n; i++){
            int cost = arr[i] - minimumOnLeft;
            profit = Math.max(profit, cost);
            minimumOnLeft = Math.min(minimumOnLeft, arr[i]);
        }

        System.out.println("Maximum Profit: " + profit);
    }

    public static void main(String[] args) {
        int[] arr = {7,1,5,3,6,4};
        int n = arr.length;
        maxProfit(arr, n);
    }


}



