
public static int[] nextSmaller(int [] arr){
    int n = arr.length;
    int[] res = new int[n];
    Arrays.fill(res,-1);
    Stack<Integer> st = new Stack<>();
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[i] < arr[st.peek()]){
            int a = st.pop();
            res[a] = arr[i];
        }
        st.push(i);
    }
    return res;
}

public static int[] nextGreater(int [] arr){
    int n = arr.length;
    int[] res = new int[n];
    Arrays.fill(res,-1);
    Stack<Integer> st = new Stack<>();
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[i] > arr[st.peek()]){
            int a = st.pop();
            res[a] = arr[i];
        }
        st.push(i);
    }
    return res;
}

private static int[] prevGreater(int[] arr) {
    int n = arr.length;
    int[] res = new int[n];
    Arrays.fill(res,-1);
    Stack<Integer> st = new Stack<>();
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[i] > arr[st.peek()]){
            int a = st.pop();
            res[a] = arr[i];
        }
        st.push(i);
    }
    return res;
}

private static int[] prevSmaller(int[] arr) {
    int n = arr.length;
    int[] res = new int[n];
    Arrays.fill(res,-1);
    Stack<Integer> st = new Stack<>();
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[i] < arr[st.peek()]){
            int a = st.pop();
            res[a] = arr[i];
        }
        st.push(i);
    }
    return res;
}

public static void main() {
    int [] arr = {10,13,18,15,20,18,25,12,15,6,10,8};
    System.out.println("Given Array: " + Arrays.toString(arr));

    int [] smaller = nextSmaller(arr);
    System.out.println("Next Smaller: " + Arrays.toString(smaller));

    int [] greater = nextGreater(arr);
    System.out.println("Next Greater: " + Arrays.toString(greater));

    int [] previousSmaller = prevSmaller(arr);
    System.out.println("Previous Smaller: " + Arrays.toString(previousSmaller));

    int [] previousGreater = prevGreater(arr);
    System.out.println("Previous Greater: " + Arrays.toString(previousGreater));
}


