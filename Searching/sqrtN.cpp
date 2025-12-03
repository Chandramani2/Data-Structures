#include "bits/stdc++.h"
using namespace std;

long long getSqrt(long long N) {
    long long low = 1, high = min(N, (long long)1e9);
    long long ans = -1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid * mid <= N) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
	long long N = 64;
	cout<<"Sqrt of "+ to_string(N) + ": "<<getSqrt(N);
	return 0;
}
