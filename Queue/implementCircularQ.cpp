#include "bits/stdc++.h"
using namespace std;

template<typename T, int MAX_SIZE = 5>
class Queue{
	private:
		int f, r;
		T arr[MAX_SIZE];
	public:
		Queue(): f(0), r(-1) {}

		void enqueue(int x){  // Insertion
			if(size()==MAX_SIZE){
				cout<<"Q is Full "<<endl;
				return;
			} 
			r++;
			arr[r%MAX_SIZE] = x;
		}

		void dequeue(){ // deletion
			if(size()==0){
				cout<<"Q is Empty "<<endl;
				return;
			}
			f++;
		}

		T rear() const{ // element recently inserted
			return arr[r%MAX_SIZE];
		}
		
		T front() const{ // element about to get deleted
			return arr[f%MAX_SIZE];
		}
		T size() const{
			return (r-f)%MAX_SIZE+1;
		}
		
		bool isEmpty() const{
			return size()==0;
		}

};
int main()
{
	Queue<int> q;
	q.enqueue(12);
	q.enqueue(7);
	q.enqueue(9);
	q.enqueue(25);
	q.enqueue(5);
	cout<<"\nRear: "<<q.rear()<<"\n";
	cout<<"Size: "<<q.size()<<"\n";
	q.dequeue();
	cout<<"Size After DeQueue: "<<q.size()<<"\n";
	cout<<"Front: "<<q.front()<<"\n\n";
	q.enqueue(26);
	q.enqueue(17);
	q.enqueue(38);
	cout<<"\nRear: "<<q.rear()<<"\n";
	cout<<"Size: "<<q.size()<<"\n";
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	cout<<"Size After DeQueue: "<<q.size()<<"\n";
	cout<<"Front: "<<q.front()<<"\n";

	return 0;
}
