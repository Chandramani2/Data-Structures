
public static int[] nextSmallerIndex(int [] arr){
    int n = arr.length;
    int[] res = new int[n];
    Arrays.fill(res,n); //  for next smaller it should be 'n' instead of '-1'
    Stack<Integer> st = new Stack<>();
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[i] < arr[st.peek()]){
            int a = st.pop();
            res[a] = i; // taking index instead of value
        }
        st.push(i);
    }
    return res;
}


private static int[] prevSmallerIndex(int[] arr) {
    int n = arr.length;
    int[] res = new int[n];
    Arrays.fill(res,-1);
    Stack<Integer> st = new Stack<>();
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[i] < arr[st.peek()]){
            int a = st.pop();
            res[a] = i; // taking index instead of value
        }
        st.push(i);
    }
    return res;
}

private static int maxHistogramArea(int[] nextSmaller, int[] previousSmaller, int[] arr) {
    int n = arr.length;
    int ans = Integer.MIN_VALUE;

    for(int i = 0; i < n; i++){
        ans = Math.max(ans, (nextSmaller[i] - previousSmaller[i] - 1) * arr[i]);
    }
    return ans;
}

public static void main() {
    int [] arr = {2,1,4,7,5,2,1,3,4,5,6,4,3,2,3,1,6,7,5,2};
    System.out.println("Given Array: " + Arrays.toString(arr));

    int [] nextSmaller = nextSmallerIndex(arr);
    System.out.println("Next Smaller Index: " + Arrays.toString(nextSmaller));

    int [] previousSmaller = prevSmallerIndex(arr);
    System.out.println("Previous Smaller Index: " + Arrays.toString(previousSmaller));

    int histogramArea = maxHistogramArea(nextSmaller, previousSmaller, arr);
    System.out.println("Histogram Area: " + histogramArea);
}




