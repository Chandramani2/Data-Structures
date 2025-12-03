#include<bits/stdc++.h>
using namespace std;
/* 	1. Move All Discs from A->C
	2. Move 1 disc at a time
	3. smaller ddisc can only be placed on a larger disc
*/
 
// N-> No. of Discs 
void towerOfHanoi(int N, char source, char auxiliary, char destination){
    // if (N == 1) {
    // 	cout << "Move Disc 1"  << " from " << source << " -> " << destination << endl;
    // 	return;
	// }
	if(N==0) return;
    towerOfHanoi(N - 1, source, destination, auxiliary);
    cout << "Move Disc " << N << " from " << source << " -> " << destination << endl;
    towerOfHanoi(N - 1, auxiliary, source, destination);
}

int main(){	
	towerOfHanoi(3,'A','B','C');
	return 0;
}