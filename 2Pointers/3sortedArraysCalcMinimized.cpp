#include<bits/stdc++.h>
using namespace std;
/*  Given 3 Sorted Arrays, find(i,j,k) such that
    max(A[i], B[j], C[k]) - min(A[i], B[j], C[k])
    Entire Value is minimized
    i,j,k is the pointer on each array
*/
int calculateNaive(int A[], int B[], int C[], int Asize, int Bsize, int Csize){
    int minimizeDifference = INT_MAX;
    for(int i=0; i<Asize; i++){
        for(int j=0; j<Bsize; j++){
            for(int k=0; k<Csize; k++){
                int maxEle = max({A[i], B[j], C[k]});
                int minEle = min({A[i], B[j], C[k]});
                int result = maxEle - minEle;
                minimizeDifference = min(minimizeDifference, result);
            }
        }
    }
    return minimizeDifference;
}

int calcOptimized(int A[], int B[], int C[], int Asize, int Bsize, int Csize){
    int p1=0, p2=0, p3=0;
    int minimizeDifference = INT_MAX;
  // move minimum pointer value
  while(p1<Asize && p2<Bsize && p3<Csize){
     int maxEle = max(A[p1], max(B[p2], C[p3]));
     int minEle = min(A[p1], min(B[p2], C[p3]));
     int result = maxEle - minEle;
     minimizeDifference = min(minimizeDifference, result);
     if(minEle==A[p1]) p1++;
     else if(minEle==B[p2]) p2++;
     else p3++;
  }
  return minimizeDifference;
}

int main(){
    int A[] = {3,14,16,20,29,40,55};
    int B[] = {-6,23,24,30,35,50};
    int C[] = {-15,15,26,29,31,39,42};
    int Asize = sizeof(A)/sizeof(A[0]);
    int Bsize = sizeof(B)/sizeof(B[0]);
    int Csize = sizeof(C)/sizeof(C[0]);
    cout<<"NaiveResult: " <<calculateNaive(A,B,C,Asize,Bsize,Csize )<<endl;
    cout<<"OptimizedResult: " <<calcOptimized(A,B,C,Asize,Bsize,Csize );
 
    return 0;
}