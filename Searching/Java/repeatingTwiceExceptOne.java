private static int uniqueElement(int[] arr, int n) {
    int l = 0;
    int h = n - 1;
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[h]!=arr[n-2]) return arr[h];

    while (l <= h) {
        int mid = l + (h - l) / 2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) {
            return arr[mid];
        }
        if(arr[mid] == arr[mid-1]){ // mid is landing on the 2nd occurrence
            mid = mid-1;
        }
        if(arr[mid]%2==0){
            l = mid+2;
        }
        else{
            h = mid-1;
        }
    }
    return -1;
}

public static void main(String[] args) {
    int[] arr = {1,1,3,3,4,4,5,5,8,8,12,12,19,21,21,22,22,25,25};
    int n = arr.length;
    System.out.println("Unique Element: " + uniqueElement(arr,n));
}





