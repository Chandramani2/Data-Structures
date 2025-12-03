#include<bits/stdc++.h>
using namespace std;
/* lexiographical - Dictionary order */
 
 void print2DVector(vector<vector<int>> result){
        for(const auto& subset : result) {
        cout << "{ ";
        for(int num : subset) cout << num << " ";
        cout << "}" << endl;
    }
 }

// Method 1
void genLexiographical(int i, vector<int> &current, 
    vector<vector<int>> &result, vector<int> &arr){  

    result.push_back(current);
    for(int j=i; j<arr.size(); j++){
        current.push_back(arr[j]);
        genLexiographical(j+1,current,result,arr);
        current.pop_back();
    }
   
}

// Method 2
// void genLexiographical(int i, vector<int> &current, 
//     vector<vector<int>> &result, vector<int> &arr){  
//     if(i==arr.size()){
//         result.push_back(current);
//         return;
//     }
//     current.push_back(arr[i]);
//     genLexiographical(i+1,current,result,arr);
//     current.pop_back();
//     genLexiographical(i+1,current,result,arr);   
// }

void lexiographicalSubset(vector<int> arr){
    vector<vector<int>>result;
    vector<int> current;
    genLexiographical(0,current,result,arr);
    // sort(result.begin(), result.end()); // Method 2 only
    print2DVector(result);
}

int main(){
   vector<int> arr = {3, 7, 6}; // example input
    sort(arr.begin(), arr.end()); // Ensure lex order
    lexiographicalSubset(arr);
    return 0;
}