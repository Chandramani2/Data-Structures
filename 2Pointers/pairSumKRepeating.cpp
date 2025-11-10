#include<bits/stdc++.h>
using namespace std;

bool pairSumK(int arr[], int size, int k){
    int p1 = 0, p2 = size-1;
    while(p1<p2){
        int sum = arr[p1] + arr[p2];
        if(sum>k)  p2--; // to find K we have to decrease the sum    
        else if(sum<k) p1++;
        else return true;
    }
    return false;
}

int pairSumKRepeating(int arr[], int size, int k){
    int p1 = 0, p2 = size-1, cnt=0;
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

int main(){
    int arr[] = {-3,0,1,3,6,7,11,14,18,25};
    int k = 17;
    int size = sizeof(arr)/sizeof(arr[0]);
    if(pairSumK(arr, size, k)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    cout<<endl;
    int arrRepeating[] = {1,4,4,5,5,5,5,6,6,11};
    size = sizeof(arrRepeating)/sizeof(arrRepeating[0]);
    k = 10;
    cout<<"No. of sum K in the Array: "<< pairSumKRepeating(arrRepeating,size,k);
    return 0;
}