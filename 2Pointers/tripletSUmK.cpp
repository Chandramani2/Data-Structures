#include<bits/stdc++.h>
using namespace std;

int pairSumKRepeating(int arr[], int size, int p1, int p2, int k){
    int cnt=0;
    while(p1<p2){
        int sum = arr[p1] + arr[p2];
        if(sum>k)  p2--; // to find K we have to decrease the sum    
        else if(sum<k) p1++;
        else{
            if(arr[p1]!=arr[p2]){
                // Iterate and count how many arr[p1] & arr[p2] are
                int c1=0, j=p1;
                while(arr[j] == arr[p1]){
                    c1++;p1++;
                }
                j = p2; 
                int c2=0;
                while(arr[j] == arr[p2]){
                    c2++; p2--;
                }
                cnt += c1*c2;
            }
            else{
                //arr[p1] = arr[p2] all elements from p1 to p2 are same as array is sorted
                int c = p2-p1+1;
                cnt += (c*(c-1))/2;
                return cnt; // as all p1 to p2 are same so we can return here
            }
        }
    }
    return cnt;
}

int tripletSumK(int arr[], int size, int B){
    int res = 0;
    for(int i=0; i<size; i++){
        int sum = -arr[i];
        int p1 = i+1, p2 = size-1;   

        //Now apply 2 pointer Pair Sum Logic
        res+=pairSumKRepeating(arr,size,p1,p2,B);
    }
   return res;
}

int main(){
    int arr[] = {-8,-7,-4,-1,2,3,5,7,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int B=0;
    cout<<"Total Number of Triplet sum Present is: " <<tripletSumK(arr, size, B);
 
    return 0;
}