//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
static int[] x = {-1,0,1,0};
static int[] y = {0,1,0,-1};

public static boolean checkBoundary(int n, int m, int newX, int newY) {
    return newX >= 0 && newX < n && newY >= 0 && newY < m;
}

public static void dfs(int[][] grid, int n, int m, int a, int b){
    if(grid[a][b]==0) return;
    grid[a][b] = 0; // marked visited
    for(int i=0; i<4; i++){
        int newX = a + x[i];
        int newY = b + y[i];
        if(checkBoundary(n,m,newX, newY)){
            dfs(grid,n,m,newX,newY);
        }
    }
}

public static int numberOfIslands(int[][] grid){
    if (grid == null || grid.length == 0) return 0;
    int n = grid.length;
    int m = grid[0].length;
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1){
                dfs(grid, n, m, i, j);
                ans++;
            }
        }
    }
    return ans;
}

public static void main() {
    int[][] matrix = {{1,0,1,1},
                      {1,1,0,0},
                      {0,0,1,0},
                      {0,1,0,1},
                      {1,1,0,1}};
    Arrays.stream(matrix).forEach(row -> System.out.println(Arrays.toString(row)));
    System.out.println("Row: " + matrix.length + " Col: " + matrix[0].length);
    System.out.println("Number of islands: " + numberOfIslands(matrix));

    Arrays.stream(matrix).forEach(row -> System.out.println(Arrays.toString(row)));

//    List<List<Integer>> matrixList = new ArrayList<>(Arrays.asList(
//            new ArrayList<>(Arrays.asList(0, 1, 1, 0)),
//            new ArrayList<>(Arrays.asList(0, 1, 1, 0)),
//            new ArrayList<>(Arrays.asList(0, 0, 1, 0)),
//            new ArrayList<>(Arrays.asList(0, 0, 0, 0)),
//            new ArrayList<>(Arrays.asList(1, 1, 0, 1))
//    ));
//    System.out.println(matrixList.get(1));
//    System.out.println("Row: " + matrixList.size() + " Col: " + matrixList.get(0).size());

//    List<List<Integer>> matrixList = List.of(
//            List.of(0, 1, 1, 0),
//            List.of(0, 1, 1, 0),
//            List.of(0, 0, 1, 0),
//            List.of(0, 0, 0, 0),
//            List.of(1, 1, 0, 1)
//    );
//    ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
//
//// You have to initialize each row manually
//    list.add(new ArrayList<>(Arrays.asList(0, 1, 1, 0)));
//    list.add(new ArrayList<>(Arrays.asList(0, 1, 1, 0)));
//// ... and so on
}

