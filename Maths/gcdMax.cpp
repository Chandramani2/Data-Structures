#include<bits/stdc++.h>
using namespace std;
/* Given an array of N elements, 
	Delete 1 element to make GCD max
*/
void printArray(int arr[], int size){
    cout<<"Output Array: ";
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int gcdMaxBruteForce(int arr[], int size){
	/* Delete(ignore) element at ith index and take gcd from
		(0,i-1) and (i+1, size-1) and then take gcd for both
	*/
	int g, ans=INT_MIN;
	for(int i=0; i<size; i++){
		if(i==0) g=arr[1];
		else g=arr[0];
		for(int j=0;j<i;j++){
			g = gcd(g,arr[j]);
		}
		for(int j=i+1; j<size; j++){
			g = gcd(g,arr[j]);
		}
		ans = max(ans,g);
	}
	return ans;
}
void prefixGCD(int gcdp[], int arr[], int size){
	gcdp[0] = arr[0];
	for(int i=1; i<size; i++){
		gcdp[i] = gcd(arr[i], gcdp[i-1]);
	}
}

void suffixGCD(int gcds[], int arr[], int size){
	gcds[size-1] = arr[size-1];
	for(int i=size-2; i>=0; i--){
		gcds[i] = gcd(arr[i], gcds[i+1]);
	}
}

int gcdMax(int arr[], int size){
	/* (0,i-1) gcd will store in gcd prefix array
		(i+1, size) gcd will store in gcd suffix array
	*/
	int gcdp[size], gcds[size];
	prefixGCD(gcdp, arr, size);
	suffixGCD(gcds, arr, size);
	
	int g, ans=0;
	for(int i=0; i<size; i++){
		if(i==0){
			ans = max(ans, gcds[1]);
		}
		else if(i==size-1){
			ans = max(ans, gcdp[size-2]);
		}
		else{
			ans = max(ans, gcd(gcdp[i-1], gcds[i+1]));
		}
	}
	return ans;
}
int main(){
	int arr[] = {24,20,32,40,120};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<"BruteForce approach: "<<gcdMaxBruteForce(arr, size)<<endl;
	cout<<"Optimized approach: "<<gcdMax(arr, size);
	return 0;
}