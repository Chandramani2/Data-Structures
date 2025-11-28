#include "bits/stdc++.h"
using namespace std;
/* Given N cows & M stalls(X-axis), place all N cows in such a way that
	Minm distance b/w any 2 cows is maximized

	e.g: stalls[] = 1,2,4,8,9 and numberOfCows = 3
	we can place cow C1 at 1, C2 at at 4 & C3 at 9
	so minm distance b/w any 2 cows here is 3 i.e. (4-1) b/w C1 and C2
	and we can't maximize it much further.
*/ 

bool isPlacingCowsPossible(int stalls[], int size, int numberOfCows, int dist){
	int cowsPlaced = 1;
	int lastPlaced = stalls[0];
	for(int i=1; i<size; i++){
		if((stalls[i] - lastPlaced) >= dist){
			cowsPlaced++;
			lastPlaced = stalls[i];
		}
	}
	if(cowsPlaced<numberOfCows) return false;
	return true;
}

/* TTTTTTFFFFFF pattern*/
int maximizeMinmDistance(int stalls[], int size, int numberOfCows){
	int low = 1, high = stalls[size-1] - stalls[0];
	int ans = INT_MAX;
	while(low<=high){
		/* if at mid we can place cows then 
		mid-1, mid-2....1 all will be True */
		int mid = (low+high)/2; // mid -> distance
		if(isPlacingCowsPossible(stalls, size, numberOfCows, mid)){
			ans = mid;
			low = mid+1;
		}
		else high = mid-1;
	}
	return ans;
}


int main()
{
	int stalls[] = {2,6,11,14,19,25,30,39,43};
	int size = sizeof(stalls)/sizeof(stalls[0]);
	int numberOfCows = 4;
	cout<<"Maximum Distance: "<<maximizeMinmDistance(stalls,size,numberOfCows);
	return 0;
}
