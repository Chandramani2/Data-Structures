#include<bits/stdc++.h>
using namespace std;
/*  Given any Pair is Length and Breadth of a Rectangle 
    Pair(i,j) = Pair(j,i)
    Find No. Of Rectangles whose Area < B 
*/

int rectangleAreaLessThanB(int arr[], int size, int B){
    int p1 = 0, p2 = size-1, cnt = 0;
    while(p1<=p2){
        int area = arr[p1] * arr[p2];
        if(area < B){ 
            /* arr[p1] is min and arr[p2] is max, so if area<B it means
            from p1 to p2 every area will be < B, becuz this will be max area we're getting with keeping p1 as minimum */
            cnt += p2-p1+1;
            p1 ++;
            /* cnt = (p2-p1+1)*2 - 1 if Pair(i,j) != Pair(j,i) */
        }
        else p2--;  
    }
    return cnt;
}

int main(){
    int arr[] = {2,3,4,7,8,10,12,14,15,16,19,20};
    int B = 85;
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Number Of Rectangles Whose Area is less than B:"<<B<<" is = "
        <<rectangleAreaLessThanB(arr, size, B);
  
       return 0;
}