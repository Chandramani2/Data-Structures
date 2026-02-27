private int maxFruitIntoBasket(int[] arr, int n, int k) {
    int l = 0;
    int ans = Integer.MIN_VALUE;
    int numberOfFruits = 0;
    HashMap<Integer, Integer> hm = new HashMap<>();
    for(int r=0; r<n; r++) {
        hm.put(arr[r], hm.getOrDefault(arr[r], 0) + 1);
        if(hm.size() <= k) {
            numberOfFruits++;
            if(numberOfFruits <= k) {
               ans = Math.max(ans, r-l+1);
            }
            else{
                l++;
            }
        }
        else{
            hm.put(arr[r], hm.getOrDefault(arr[r], 0) - 1);
            if(hm.get(arr[r]) == 0) {
                hm.remove(arr[r]);
            }
        }
    }
    return ans;

