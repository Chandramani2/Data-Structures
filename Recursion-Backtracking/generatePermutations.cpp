#include<bits/stdc++.h>
using namespace std;
 
 void print2DVector(vector<vector<int>> result){
        for(const auto& subset : result) {
        cout << "{ ";
        for(int num : subset) cout << num << " ";
        cout << "}" << endl;
    }
 }
/*      { 3 6 7 }
        { 3 7 6 }
        { 6 3 7 }
        { 7 3 6 }
        { 6 7 3 }
        { 7 6 3 }
*/
void printPermutations(int i, vector<int> &current, 
    vector<vector<int>> &result, vector<int> &arr){  

    if(i==arr.size()){
        result.push_back(current);
        return;
    }
    // we place ith arr value, whichever position is empty place there
    for(int j=0;j<arr.size();j++){
        if(current[j]==-1){
            current[j] = arr[i];
            printPermutations(i+1,current,result,arr);
            current[j] = -1;
        }
    }    
}

void generatePermutations(vector<int> arr){
    vector<vector<int>>result;
    vector<int> current(arr.size(),-1);
    printPermutations(0,current,result,arr);
    print2DVector(result);
}

int main(){
   vector<int> arr = {3, 7, 6}; // example input
    sort(arr.begin(), arr.end()); // Ensure lex order
    generatePermutations(arr);
    return 0;
}