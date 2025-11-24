#include<bits/stdc++.h>
using namespace std;

template<typename T, int MAX_SIZE = 10>
class Stack2Array{
	private:
		T arr[MAX_SIZE];
		int top1;
		int top2;
	public:
		Stack2Array(): top1(-1), top2(MAX_SIZE) {}

		bool isEmpty() const {
			return (top1==-1) && (top2==MAX_SIZE);
		}

		bool isFull() const {
			return (top1+1) == top2;
		}

		//Stack 1
		void push1(const T& value){
			if(isFull()){
				cout<<"Stack Overflow! cannot push "<<value<<endl;
				return;
			}
			arr[++top1] = value;
		}

		void pop1(){
	 		if (isEmpty()) {
	        	cout << "Stack Underflow! Cannot pop." << endl;
	        	return;
	    	}
	    	top1--;
		}

		T top1Value() const{
			if (isEmpty()) {
	        	throw out_of_range("Stack is empty");
        	}
        	return arr[top1];
		}

		int size1() const {
        	return top1 + 1;
    	}

    	//Stack2
    	void push2(const T& value){
			if(isFull()){
				cout<<"Stack Overflow! cannot push "<<value<<endl;
				return;
			}
			arr[--top2] = value;
		}

		void pop2(){
	 		if (isEmpty()) {
	        	cout << "Stack Underflow! Cannot pop." << endl;
	        	return;
	    	}
	    	top2++;
		}

		T top2Value() const{
			if (isEmpty()) {
	        	throw out_of_range("Stack is empty");
        	}
        	return arr[top2];
		}

		int size2() const {
        	return MAX_SIZE - top2;
    	}
};
int main(){
	Stack2Array<int> st;

	st.push1(1);
	st.push1(2);
	st.push1(3);
	st.push1(4);
	
	st.push2(5);
	st.push2(6);
	st.push2(7);
	st.push2(8);
	st.push2(9);
	st.push2(10);

	cout<<"Stack1 size: "<<st.size1()<<endl;
	cout<<"Stack2 size: "<<st.size2()<<endl;
	cout<<"\nStack1 top: "<<st.top1Value()<<endl;
	cout<<"Stack2 top: "<<st.top2Value()<<endl;

}