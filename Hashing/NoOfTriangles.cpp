#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size){
    cout<<"Output Array: ";
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

void printVector(vector<pair<int, int>>arr){
    for(auto x : arr){
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;
}

/* Get All the Triplets and check if it's forming 
    a Right-Angle-Triangle or not
*/
int NumberOfRectanglesNaive(vector<pair<int, int>>arr){
    int N = arr.size();
    int ans = 0;
    for(int i=0; i<N; i++){
        pair<int, int>p1 = arr[i];
        int x1 = p1.first, y1=p1.second;
        for(int j=i+1; j<N; j++){
            pair<int, int>p2 = arr[j];
            int x2 = p2.first, y2=p2.second;
            for(int k=j+1; k<N; k++){
                pair<int, int>p3 = arr[k];
                int x3 = p3.first, y3=p3.second;
                if((x1==x2 || x2==x3 || x1==x3) && 
                    (y1==y2 || y2==y3 || y1==y3)){
                    ans++;
                }
            }
        }
    }
    return ans;
}
//Method 1: count same X&Y for every point assuming as right angle vertex
int NumberOfRectanglesOptimized1(vector<pair<int, int>>arr){
    int N = arr.size();
    int ans = 0;
    for(int i=0; i<N; i++){
        pair<int, int>p1 = arr[i];
        int x = p1.first, y=p1.second;
        int sameX = 0, sameY=0;
        for(int j=0; j<N; j++){
            pair<int, int>p2 = arr[j];
            int x1 = p2.first, y1=p2.second;
            if(x1==x) sameX++;
            if(y1==y) sameY++;
        }
        ans+=(sameX-1)*(sameY-1);
    }
    return ans;
}
 
//Method2: store counts of X&Y in Map
int NumberOfRectanglesOptimized2(vector<pair<int, int>>arr){
    int N = arr.size();
    int ans = 0;
    unordered_map<int,int> Xhm;
    unordered_map<int,int> Yhm;
    for(auto point: arr){
        Xhm[point.first]++;
        Yhm[point.second]++;
    }
    for(int i=0; i<N; i++){
        pair<int, int>p1 = arr[i];
        int x = p1.first, y=p1.second;
        ans+=(Xhm[x]-1)*(Yhm[y]-1);
    }
    return ans;
}

int main(){
    vector<pair<int,int>> points = { 
        {1,5}, {1,3}, {1,1}, {3,1},
        {5,1}, {5,3}, {5,5} 
        };
    cout<<"Number Of Rectangles Form with the given points are: "
    <<NumberOfRectanglesNaive(points)<<endl;
    cout<<"Optimized 1 O(N^2): "<<NumberOfRectanglesOptimized1(points)<<endl;
    cout<<"Optimized 1 O(N): "<<NumberOfRectanglesOptimized2(points);

    return 0;
}