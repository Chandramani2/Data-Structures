#include "bits/stdc++.h"
using namespace std;
/* Given N tasks & K Workers, time taken to complete each task.
	find min time in which we can complete all tasks.
	A single worker can only do a continuous set of tasks
*/ 

bool isTimePossible(int tasks[], int size, int numberOfWorkers, int times){
	int sumTime = 0;
	int worker = 0;
	for(int i=0; i<size; i++){
		sumTime+=tasks[i];
		if(sumTime>times){
			worker++;
			sumTime = tasks[i];
		}
	}
	if(sumTime>0) worker++; //last task
	if(worker > numberOfWorkers) return false;
	return true;
}

/* FFFFFFTTTTTT pattern*/
int minimizeMaxmTime(int tasks[], int size, int numberOfWorkers){
	int low = *max_element(tasks, tasks+size); 
	int high = accumulate(tasks, tasks+size, 0);
	int ans = INT_MAX;
	while(low<=high){
		/* if any worker can complete task in 'mid' time
		then for mid+1, mid+2.... is True */
		int mid = (low+high)/2; // mid -> time
		if(isTimePossible(tasks, size, numberOfWorkers, mid)){
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}
	return ans;
}


int main()
{
	int tasks[] = {3,5,1,7,8,2,5,3,10,1,4,7,5,4,6};
	int size = sizeof(tasks)/sizeof(tasks[0]);
	int numberOfWorkers = 3;
	cout<<"Minimum Time: "<<minimizeMaxmTime(tasks,size,numberOfWorkers);
	return 0;
}
