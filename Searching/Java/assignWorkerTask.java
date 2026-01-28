

public static void main() {
    int[] tasks = {3,5,1,7,8,2,5,3,10,1,4,7,5,4,6};
    int numberOfWorkers = 3;
    System.out.println("Minimize Time Taken by Workers: "+ taskWorkers(tasks, numberOfWorkers));
}

//FFFFFFFTTTTTTTT pattern
private static int taskWorkers(int[] tasks, int numberOfWorkers) {
    int l = Arrays.stream(tasks).max().getAsInt();
    int h = Arrays.stream(tasks).sum();

    int n = tasks.length;
    int ans = Integer.MAX_VALUE;
    while(l<=h) {
        int mid = (l+h)/2;
        if(canWorkerMinimizeTime(mid,tasks,numberOfWorkers)){
            ans = mid;
            h = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}

private static boolean canWorkerMinimizeTime(int mid, int[] tasks, int numberOfWorkers) {
    int workerAssigned = 0;
    int sum = 0;
    for(int i = 0; i < tasks.length; i++) {
        sum +=tasks[i];
        if(sum > mid) {
            workerAssigned++;
            sum = tasks[i];
        }
    }
    if(sum>0) workerAssigned++; // Last Task
    return workerAssigned <= numberOfWorkers;
}





