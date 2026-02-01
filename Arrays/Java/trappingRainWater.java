private static void rightMax(int[] rMax, int[] height) {
    rMax[height.length - 1] = height[height.length - 1];
    int maxTillNow = rMax[height.length - 1];
    for (int i = height.length - 2; i >= 0; i--) {
        if (height[i] > maxTillNow) {
            maxTillNow = height[i];
        }
        rMax[i] = maxTillNow;
    }
}

private static void leftMax(int[] lMax, int[] height) {
    lMax[0] = height[0];
    int maxTillNow = lMax[0];
    for (int i = 1; i < height.length; i++) {
        if (height[i] > maxTillNow) {
            maxTillNow = height[i];
        }
        lMax[i] = maxTillNow;
    }
}

public static void main(String[] args) {
    int[] height = {0,1,0,2,1,0,1,3,2,1,2,1};
    trap(height);
}

private static void trap(int[] height) {
    int n = height.length;
    int[] lMax = new int[n];
    int[] rMax = new int[n];
    leftMax(lMax, height);
    rightMax(rMax, height);
    System.out.println("LMax: " + Arrays.toString(lMax));
    System.out.println("RMax: " + Arrays.toString(rMax));

    int totalTrappedWater = 0;
    for(int i = 0; i < n; i++) {
        totalTrappedWater += Math.min(lMax[i], rMax[i]) - height[i];
    }
    System.out.println("Total Trapped Water: " + totalTrappedWater);
}



