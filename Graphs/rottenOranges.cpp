#include<bits/stdc++.h>
using namespace std;
/*	Every minute any Fresh orange adjacent to rotten orange becomes rotten,
	- Find minimum time when all oranges becomes rotten
	- if not possible return -1
	0 - Empty
	1 - Fresh Orange
	2 - Rotten Orange

*/
#define ROWS 5
#define COLS 5

// // 8- directions
// int row[] = {-1,-1,-1,0,0,1,1,1};
// int col[] = {1,0,-1,1,-1,1,0,-1};


// 4-directions (Up, Down, Left, Right)
int row[] = {-1, 1, 0, 0};
int col[] = {0, 0, -1, 1};

void printMatrix(vector<vector<int>> matrix) {
    for (int i = 0; i < ROWS; i++) {
        cout<<"{";
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j];
            if(j!=COLS-1) cout<<",";
        }
        cout<<"}";
        if(i!=ROWS-1) cout<<",";
        cout<< endl;
    }
}

bool checkBoundary(int x, int y){
	if(x>=0 && x<ROWS && y >=0 && y <COLS) return true;
	return false;
}

int rottenOranges(vector<vector<int>> arr){
	queue<pair<int,int>>q;
	vector<vector<int>> time(ROWS, vector<int>(COLS,0));
	//push all rotten oranges into the Queue and time = 0;
	for(int i=0; i < ROWS; i++){
		for(int j=0; j < COLS; j++){
			if(arr[i][j] == 2){
				q.push({i,j});
			}
		}
	}

	while(q.size()>0){
		pair<int,int> ele = q.front();
		q.pop();
		int i =ele.first, j = ele.second;
		for(int x = 0; x < 4; x++){
			int newX = i + row[x];
			int newY = j + col[x];
			if(!checkBoundary(newX, newY) || 
				arr[newX][newY] == 0 ||
				arr[newX][newY] == 2) 
				continue;
			if(arr[newX][newY] == 1){
				time[newX][newY] = time[i][j] + 1;
				arr[newX][newY] = 2;
				q.push({newX, newY});
			}
		}
	}
	cout<<"\n__________TIME_____________\n";
	printMatrix(time);
	cout<<"\n___________ARRAY____________\n";
	printMatrix(arr);

	//Iterate on Matrix if Fresh Orange still present return -1
	// else return max in time array
	int ans = -1;
	for(int i=0; i < ROWS; i++){
		for(int j=0; j < COLS; j++){
			if(arr[i][j] == 1){
				return -1;
			}
			ans = max(ans, time[i][j]);
		}
	}
	return ans;
}

// Optimized Space
int rottenOrangesSpaceOpt(vector<vector<int>> &arr) { // Pass by reference to modify in-place
    queue<pair<int, int>> q;
    int freshOranges = 0;

    // 1. Initialization
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == 2) {
                q.push({i, j});
            } else if (arr[i][j] == 1) {
                freshOranges++;
            }
        }
    }

    // Optimization: If no fresh oranges, 0 minutes required
    if (freshOranges == 0) return 0;

    int minutes = 0;

    // 2. BFS (Level by Level)
    while (!q.empty()) {
        int size = q.size(); 
        bool rottedSomething = false; // Track if we infect anyone this minute

        // Process exactly one "minute" worth of oranges
        for (int i = 0; i < size; i++) {
            pair<int, int> curr = q.front();
            q.pop();

            for (int x = 0; x < 4; x++) {
                int newRow = curr.first + row[x];
                int newCol = curr.second + col[x];

                // If valid and fresh
                if (checkBoundary(newRow, newCol) && arr[newRow][newCol] == 1) {
                    // Make it rotten in the ORIGINAL array
                    arr[newRow][newCol] = 2; 
                    q.push({newRow, newCol});
                    freshOranges--; 
                    rottedSomething = true;
                }
            }
        }

        // Only increment time if we actually rotted a new orange 
        // and pushed items for the next level
        if (rottedSomething) {
            minutes++;
        }
    }

    // 3. Final Check
    if (freshOranges > 0) return -1;
    
    return minutes;
}


void fillRandomMatrix(vector<vector<int>> &matrix ) {
    srand(time(0)); // Seed for random number generation
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if(i==0 && j==0) continue;
            if(i==1 || j==1) continue;
            matrix[i][j] = rand() % 3; // Randomly assign 0,1,2
        }
    }
}

int main(){
	vector<vector<int>> arr(ROWS, vector<int>(COLS,1)); 
										  // = {{1,1,2,0,0},
										// 	 {1,1,1,1,1},
										// 	 {0,1,1,2,2},
										// 	 {0,1,1,2,0},
										// 	 {1,1,0,2,0}};
	// vector<vector<int>> arr =  {{1,1,0,1,2},
	// 							{1,1,1,1,1},
	// 							{1,1,2,0,0},
	// 							{2,1,0,0,0},
	// 							{2,1,1,2,1}};
	fillRandomMatrix(arr);
	cout<<"\n___________ARRAY____________\n";
	printMatrix(arr);
	cout<<"\nBFS Time: "<<rottenOranges(arr)<<endl;
	cout<<"BFS Time Space Optimized: "<<rottenOrangesSpaceOpt(arr)<<endl;

	return 0;
}
