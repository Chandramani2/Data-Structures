import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Main {
    private static int maximumPointsRecursive(int[][] activity, int day, int last) {
        if(day == 0){
            int max = 0;
            for(int task = 0; task < activity.length; task++){
                if(task!=last){
                    max = Math.max(max, activity[0][task]);
                }
            }
            return max;
        }

        int max = 0;
        for(int task = 0; task < activity.length; task++){
            if(task!=last){
                int points = activity[day][task] + maximumPointsRecursive(activity, day-1, task);
                max = Math.max(max, points);
            }
        }
        return max;
    }

    private static int maximumPointsDPMemoization(int[][] activity, int day, int last, List<List<Integer>> dp) {
        if(day == 0){
            int max = 0;
            for(int task = 0; task < activity[0].length; task++){
                if(task!=last){
                    max = Math.max(max, activity[0][task]);
                }
            }
            return max;
        }

        if(dp.get(day).get(last)!=-1) return dp.get(day).get(last);
        int max = 0;
        for(int task = 0; task < activity[0].length; task++){
            if(task!=last){
                int points = activity[day][task] + maximumPointsDPMemoization(activity, day-1, task, dp);
                max = Math.max(max, points);
            }
        }
       dp.get(day).set(last, max);
        return max;
    }

    public static void main(String[] args) {
        int[][] activity = {{10, 40, 70},
                {20, 50, 80},
                {30, 60, 90}};
        int days = activity.length;
        maximumPoints(activity, days);
        int ans = maximumPointsRecursive(activity, days-1, days);
        System.out.println("Recursive Solution: " + ans);

        List<List<Integer>> dp = new ArrayList<>();
        for(int i = 0; i < days; i++){
            List<Integer> row = new ArrayList<>(Collections.nCopies(4, -1));
            dp.add(row);
        }
         ans = maximumPointsDPMemoization(activity, days-1, days, dp);
        System.out.println("DP Memoization Solution: " + ans);
    }



    private static void maximumPoints(int[][] activity, int days) {
        // dp[day][last_activity]
        int[][] dp = new int[days][3];

        // Base case: Day 0
        dp[0][0] = activity[0][0];
        dp[0][1] = activity[0][1];
        dp[0][2] = activity[0][2];

        // Fill the DP table for subsequent days
        for (int i = 1; i < days; i++) {
            dp[i][0] = activity[i][0] + Math.max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = activity[i][1] + Math.max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = activity[i][2] + Math.max(dp[i - 1][0], dp[i - 1][1]);
        }

//        int ans = Arrays.stream(dp[days-1]).max().getAsInt();
//        System.out.println("Answer: " + ans);
        // The answer is the max value in the last row
        int maxPoints = Math.max(dp[days - 1][0], Math.max(dp[days - 1][1], dp[days - 1][2]));
        System.out.println("Maximum Points: " + maxPoints);
    }
}
