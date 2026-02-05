public static void main(String[] args) {
    int[] arr = {4,5,6,1,2};
    int n = arr.length;
    System.out.println(MinrotatedArray(arr,n));
}

private static int MinrotatedArray(int[] arr, int n) {

    int l = 0;
    int h = n-1;
    if(arr[l] <= arr[h]) return arr[l];
    while(l<=h){
        int mid = (l + h)/2;
        if(mid > 0 && arr[mid]<arr[mid-1]){
            return arr[mid];
        }
        if(arr[mid] < arr[h]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return arr[l];
}
