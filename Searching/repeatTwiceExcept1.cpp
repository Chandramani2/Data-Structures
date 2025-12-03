#include "bits/stdc++.h"
using namespace std;
/* Observations:
	- Before Unique Element all First occurences are at even index
	- After Unique Element all First occurences are at odd index
*/
int uniqueElement(int arr[], int size){
	int low = 0, high = size-1;
	int mid = INT_MIN;
	if(size==1) return arr[0];
	if(arr[0]!=arr[1]) return arr[0];
	if(arr[size-1]!=arr[size-2]) return arr[size-1];

	while(low<=high){
		mid = (low+high)/2;	

		 // Check if mid is the unique element
		if(arr[mid-1]!=arr[mid] && arr[mid+1]!=arr[mid]){
			return arr[mid];
		}
		/* Edge Case: mid can fall on 2nd occurence, 
			bring mid on the 1st occurence */
		if(arr[mid] == arr[mid-1]) mid=mid-1;
		/* low will be on 2nd occurence if'll do mid+1, 
			so mid+2 will go to new element 1st occurence
		*/
		if(mid%2==0) low = mid+2; 		
		else high=mid-1;
	}
	return arr[mid];
}

int main()
{
	int arr[] = {3,3,1,1,8,8,10,10,19,6,6,2,2,4,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<"Unique Element: "<<uniqueElement(arr,size);
	return 0;
}
