#include<bits/stdc++.h>
using namespace std;

int row[] = {-1,-1,-1,0,0,1,1,1};
int col[] = {1,0,-1,1,-1,1,0,-1};

bool checkBoundary(int n, int m, int x, int y){
	if(x>=0 && x<n && y >=0 && y <m) return true;
	return false;
}

void bfs(vector<vector<int>> &arr, vector<vector<int>> &vis, int n, int m, int a, int b){
	
	queue<pair<int,int>> q;
	q.push({a,b});
	while(!q.empty()){
		pair<int,int> tmp = q.front();
		q.pop();
		int x = tmp.first;
		int y = tmp.second;
		vis[x][y]=1;
		for(int i=0;i<8;i++){
			int newX = x+row[i];
			int newY = y + col[i];
			if( checkBoundary(n,m,newX, newY) && arr[newX][newY] && !vis[newX][newY]){
				q.push({newX, newY});
			}
		}
	}
	
}

void dfs(vector<vector<int>> &arr, vector<vector<int>> &vis, int n, int m, int a, int b){
	if(!arr[a][b]) return;
	vis[a][b] = 1;
	for(int i=0;i<8;i++){
			int newX = a+row[i];
			int newY = b + col[i];
			if( checkBoundary(n,m,newX, newY) && arr[newX][newY] && !vis[newX][newY]){
				dfs(arr,vis,n,m,newX, newY);
			}
		}
}
pair<int,int> numberOfIsland(vector<vector<int>> &arr){
	int n = arr.size();
	int m  = arr[0].size();
	vector<vector<int>>vis(n,vector<int>(m,0));
	int countBFS = 0;
	int countDFS = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j] && arr[i][j]){
				vis[i][j]=1;
				bfs(arr,vis, n , m, i, j);
				countBFS++;
			}
		}
	}

	//DFS SOlution
	for (auto &i : vis)
    	fill(i.begin(), i.end(), 0);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j] && arr[i][j]){
				vis[i][j]=1;
				dfs(arr,vis, n , m, i, j);
				countDFS++;
			}
		}
	}
	return {countBFS,countDFS};
}

int main(){
	vector<vector<int>> arr = {{0,1,1,0},
								{0,1,1,0},
								{0,0,1,0},
								{0,0,0,0},
								{1,1,0,1}};
	pair<int,int> ans = numberOfIsland(arr);
	cout<<"BFS: "<<ans.first<<endl<< "DFS: "<<ans.second;
	return 0;
}