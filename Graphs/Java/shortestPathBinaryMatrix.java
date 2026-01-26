import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    private static class Triplet{
        int x;
        int y;
        int dist;
        Triplet(int x, int y, int dist){
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }
    public static void main() {
        int [][] grid = {
                {0, 1, 0, 0, 0},
                {1, 0, 0, 1, 0},
                {0, 1, 1, 1, 0},
                {0, 1, 0, 0, 1},
                {0, 0, 0, 0, 0}
        };

        Solution solution = new Solution();
        System.out.println( solution.shortestPathBinaryMatrix(grid));
    }

    public boolean checkBoundary(int n, int m, int newX, int newY){
        return newX >= 0 && newX < n && newY >= 0 && newY < m;
    }
    public int shortestPathBinaryMatrix(int[][] grid) {

        int n = grid.length;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        int[] rows = {0,1,1,1,0,-1,-1,-1};
        int[] cols = {1,1,0,-1,-1,-1,0,1};

        boolean[][] visited = new boolean[n][n];
        visited[0][0] = true;

        Queue<Triplet> queue = new LinkedList<>();
        queue.offer(new Triplet(0,0,1));

        while(!queue.isEmpty()){
            Triplet curr = queue.poll();
            int r = curr.x;
            int c = curr.y;
            int d = curr.dist;

            if(r == n-1 && c == n-1) return d;

            for(int i=0; i<8; i++){
                int newX = r + rows[i];
                int newY = c + cols[i];

                if(checkBoundary(n,n,newX,newY) && grid[newX][newY]==0 &&
                        !visited[newX][newY]){
                    visited[newX][newY] = true;
                    queue.offer(new Triplet(newX,newY,d+1));
                }
            }
        }

        return -1;
    }
}












