#include "bits/stdc++.h"
using namespace std;
/* Given N Houses and (R,G,B) paints with some costs associated
	- find min cost to paint all houses
	- 2 adjacent houses cannot have same colour
*/

/* DP
	- Min cost to paint first i-1 houses, 
	- such that no 2 adjacent houses have same color and
	dpR[i] - i'th house color is Red
	dpG[i] - i'th house color is Green
	dpB[i] - i'th house color is Blue
*/

int minCostPaintHouses(int N, int R[], int G[], int B[]) {
    // Use 0-indexed arrays
    int dpR[N], dpG[N], dpB[N];
    dpR[0] = R[0];
    dpG[0] = G[0];
    dpB[0] = B[0];

    for (int i = 1; i < N; i++) {
        dpR[i] = R[i] + min(dpG[i-1], dpB[i-1]);
        dpG[i] = G[i] + min(dpR[i-1], dpB[i-1]);
        dpB[i] = B[i] + min(dpR[i-1], dpG[i-1]);
    }
    return min({dpR[N-1], dpG[N-1], dpB[N-1]});
}

int main()
{	int N = 6;
	int R[] = {5, 8, 3,10, 2, 15};
	int G[] = {9, 4, 1, 3, 6,  2};
	int B[] = {12,5, 2, 8, 7,  5};
	cout<<minCostPaintHouses(N,R,G,B);
	return 0;
}
