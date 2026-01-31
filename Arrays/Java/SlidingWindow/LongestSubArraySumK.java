/* Longest SubArray Sum with sum<=K */


public static void main(String[] args) {
  int[] arr = {1,2,5,7,3,8,12,3};
  int k = 14;
  longestSubArraySumLengthLessThanK(arr, arr.length, k);
  longestSubArraySumLengthCloserToK(arr, arr.length, k);
}

private static void longestSubArraySumLengthLessThanK(int[] arr, int n, int k) {
  int maxLen = 0;
  int l = 0;
  int p1 = -1, p2 = -1;
  int currentSum = 0;

  // Use for loop for the right pointer
  for (int r = 0; r < n; r++) {
    currentSum += arr[r];

    // Shrink window if sum exceeds k
    while (currentSum > k && l <= r) {
      currentSum -= arr[l];
      l++;
    }

    // Check if this is the longest window we've seen
    int currentWindowSize = r - l + 1;
    if (currentSum <= k && currentWindowSize > maxLen) {
      maxLen = currentWindowSize;
      p1 = l;
      p2 = r;
    }
  }

  if (p1 == -1) {
    System.out.println("No subarray found with sum <= " + k);
  } else {
    System.out.println("Longest Subarray Length: " + maxLen);
    System.out.println("Indices: P1: " + p1 + " P2: " + p2);
  }
}

private static void longestSubArraySumLengthCloserToK(int[] arr, int n, int k) {
  int maxLen = 0;
  int maxSum = -1; // Track the sum closest to K
  int l = 0;
  int p1 = -1, p2 = -1;
  int currentSum = 0;

  for (int r = 0; r < n; r++) {
    currentSum += arr[r];

    while (currentSum > k && l <= r) {
      currentSum -= arr[l];
      l++;
    }

    // Only process if the window is valid
    if (currentSum <= k) {
      int currentLen = r - l + 1;

      // Case 1: Found a strictly longer subarray
      // Case 2: Same length, but the sum is closer to K
      if (currentLen > maxLen || (currentLen == maxLen && currentSum > maxSum)) {
        maxLen = currentLen;
        maxSum = currentSum;
        p1 = l;
        p2 = r;
      }
    }
  }

  if (p1 == -1) {
    System.out.println("No subarray found.");
  } else {
    System.out.println("Length: " + maxLen + " | Sum: " + maxSum);
    System.out.println("Indices: P1: " + p1 + " P2: " + p2);
  }
}

