#include<bits/stdc++.h>
using namespace std;

template<typename T>
class MinStack{
	stack<T> mainStack;
	stack<T> minStack;

	public:
		void push(const T& value){
			mainStack.push(value);
			if(minStack.empty() || value<=minStack.top()){
				minStack.push(value);
			}
		}

		void pop() {
	        if (mainStack.empty()) {
            	throw out_of_range("Stack is empty");
        	}
        	if(mainStack.top() == minStack.top()){
        		minStack.pop();
        	}
        	mainStack.pop();
		}

	    T top() const {
	        if (mainStack.empty()) {
	            throw out_of_range("Stack is empty");
	        }
	        return mainStack.top();
	    }

	    T getMinimum() const {
	        if (minStack.empty()) {
	            throw out_of_range("Stack is empty");
	        }
	        return minStack.top();
	    }

	    bool isEmpty() const {
	        return mainStack.empty();
	    }
};

int main(){
 	MinStack<int> s;
    s.push(10);
    s.push(5);
    s.push(8);
    cout << "Minimum: " << s.getMinimum() << endl; // Output: 5
    s.pop();
    cout << "Minimum after pop: " << s.getMinimum() << endl; // Output: 5
    s.pop();
    cout << "Minimum after another pop: " << s.getMinimum() << endl; // Output: 10
    return 0;
	
}