#include "bits/stdc++.h"
using namespace std;

/* so much wastage of Space in this Q, that's why
	we'll move to Circular Queue 
*/
template<typename T, int MAX_SIZE = 100>
class Queue{
	private:
		int f, r;
		T arr[MAX_SIZE];
	public:
		Queue(): f(0), r(-1) {}

		void enqueue(int x){  // Insertion
			arr[++r] = x;
		}
		T rear() const{ // element recently inserted
			return arr[r];
		}
		void dequeue(){ // deletion
			f++; 
		}
		T front() const{ // element about to get deleted
			return arr[f];
		}
		T size() const{
			return r-f+1;
		}
		bool isEmpty() const{
			return size()==0;
		}

};
int main()
{
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	cout<<q.rear()<<"\n";
	cout<<"Size: "<<q.size()<<"\n";
	q.dequeue();
	cout<<"Size: "<<q.size()<<"\n";
	cout<<q.front()<<"\n";

	return 0;
}
