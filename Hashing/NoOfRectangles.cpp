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

// Fix diagonal and find other 2 points from the set
int NumberOfRectangles(vector<pair<int, int>>arr){
    int N = arr.size();
    int ans = 0;

    //store pairs in set, we have to find whole pair this time
    set<pair<int,int>> hs;
    for(auto x: arr){
        hs.insert(x);
    }

    for(int i=0; i<N; i++){
        pair<int, int>p1 = arr[i];
        int x1 = p1.first, y1=p1.second;
        for(int j= i+1; j<N; j++){
            pair<int, int>p2 = arr[j];
            int x2 = p2.first, y2=p2.second;
            if((x1==x2) || (y1==y2)) continue; //Not a diagonal element
            if(hs.find({x1,y2})!=hs.end() && hs.find({x2,y1})!=hs.end()){
                ans++;
            }
        }
    }
    return ans/2;
}

int main(){
    vector<pair<int,int>> points = { 
        {1,5}, {1,3}, {1,1}, {3,1},
        {5,1}, {5,3}, {5,5} 
        };
    cout<<"Number Of Rectangles Form with the given points are: "
    <<NumberOfRectangles(points)<<endl;
   
    return 0;
}