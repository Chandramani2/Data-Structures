#include<bits/stdc++.h>
using namespace std;

template<typename T, int MAX_SIZE = 100> 
class StackArray{
	private:
		T arr[MAX_SIZE];
		int topIndex;
	public:
		StackArray(): topIndex(-1) {}

		bool isEmpty() const {
			return topIndex==-1;
		}

		bool isFull() const {
			return topIndex == MAX_SIZE-1;
		}

		void push(const T& value){
			if(isFull()){
				cout<<"Stack Overflow! cannot push "<<value<<endl;
				return;
			}
			arr[++topIndex] = value;
		}

		void pop(){
	 		if (isEmpty()) {
	        	cout << "Stack Underflow! Cannot pop." << endl;
	        	return;
	    	}
	    	topIndex--;
		}

		T top() const{
			if (isEmpty()) {
	        	throw out_of_range("Stack is empty");
        	}
        	return arr[topIndex];
		}

		int size() const {
        	return topIndex + 1;
    	}
}; // End of class

int main(){
    StackArray<int> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Top element: " << intStack.top() << endl;
    intStack.pop();
    cout << "Top element after pop: " << intStack.top() << endl;

    StackArray<string> stringStack;
    stringStack.push("hello");
    stringStack.push("world");

    cout << "Top string: " << stringStack.top() << endl;

    return 0;
}