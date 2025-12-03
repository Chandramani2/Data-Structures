#include<bits/stdc++.h>
using namespace std;
/* Given a Matrix which contain only 1's and 0's, find max rectangular area
	Which contain all 1's.
	Hint: Prefix sum and Histogram Area(prev smaller and next smaller)
*/

void print2DVector(vector<vector<int>> mat){
	for(auto x: mat){
		for(auto y : x){
			cout<<y<<" "; 
		}
		cout<<endl;
	}
}

void printArray(vector<int> &arr){
	cout<<endl;
	for(auto x: arr){
		cout<<x<<" ";
	}
	cout<<endl;
}
/* 	1 1 0 1 0 1 	1 1 0 1 0 1 
	0 1 1 1 1 1 	0 2 1 2 1 2 
	1 1 1 1 1 0 	1 3 2 3 2 0 
	1 0 1 0 0 1 	2 0 3 0 0 1
	1 1 0 0 1 1 	3 1 0 0 1 2 	
*/
void prefixSumMatrix(vector<vector<int>> &mat){
	for(int j=0; j<mat[0].size(); j++){ //fixing column
		for(int i=1; i<mat.size(); i++){ // iterating on rows
			if(mat[i][j]==0) continue;
			mat[i][j]+=mat[i-1][j];
		}
	}
}
// calculate histogram area for every row
void fillNextSmaller(vector<int> &p2, vector<int> &arr, int n){
	stack<pair<int,int>> st;
	st.push({arr[0],0});
	for(int i=1;i<n;i++){
		pair<int,int> tmp = st.top();
		int data = tmp.first;
		int ind = tmp.second;
		
		if(arr[i] > data){
			st.push({arr[i],i});
		}
		else{
			while(!st.empty() && st.top().first > arr[i]){
				p2[st.top().second] = i;
				st.pop();
			}
		}
		st.push({arr[i],i});
	}

}
void fillPreviousSmaller(vector<int> &p2, vector<int> &arr, int n){
	stack<pair<int,int>> st;
	st.push({arr[n-1],n-1});
	for(int i=n-2;i>=0;i--){
		pair<int,int> tmp = st.top();
		int data = tmp.first;
		int ind = tmp.second;
		
		if(arr[i] > data){
			st.push({arr[i],i});
		}
		else{
			while(!st.empty() && st.top().first > arr[i]){
				p2[st.top().second] = i;
				st.pop();
			}
		}
		st.push({arr[i],i});
	}
}

int maxHistogramAreaStack(vector<int> &arr){
	int n = arr.size();
	vector<int> p1(n,-1); // previous smaller
	vector<int> p2(n,n);  // next smaller
	int ans = -1;
	fillNextSmaller(p2,arr,n);
	fillPreviousSmaller(p1, arr,n);

	for(int i=0;i<n;i++){
		int area = (p2[i] - p1[i] - 1) * arr[i];
		ans = max(ans,area);
	}
	return ans;
}

int maxRectangularArea(vector<vector<int>> mat){
	int ans = INT_MIN;
	for(int i=0; i<mat.size(); i++){
		ans = max(ans, maxHistogramAreaStack(mat[i]));
	}
	// printArray(mat[1]);
	return ans;
}

int main()
{	
	vector<vector<int>> mat =	{{1,1,0,1,0,1}, 
								{0,1,1,1,1,1},
								{1,1,1,1,1,0},
								{1,0,1,0,0,1},
								{1,1,0,0,1,1}};

	prefixSumMatrix(mat);
	print2DVector(mat);
	cout<<"\n max Rectangular Area: " << maxRectangularArea(mat);
	return 0;
}
