#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList{
	public:
		Node *insertNodeBeginning(Node *head, int val){
			Node *newNode = new Node(val);
			newNode->next = head;
			return newNode;
		}
		
		Node *insertNodeAtLast(Node *head, int val){
			Node *newNode = new Node(val);
			if(head==NULL){
				head = newNode; return head;
			}
			Node *tmpHead = head;
			while(tmpHead->next!=NULL) 
				tmpHead = tmpHead->next;
			tmpHead->next = newNode;
			return head;
		}

		// Method 1
		Node *reverseLinkedList(Node *h1){
			Node *tmp = h1;
			Node *h2 = NULL;
			while(h1!=NULL){
				h1=h1->next;
				tmp->next = h2;
				h2=tmp;
				tmp = h1;
			}
			
			return h2;
		}

		//Method 2: Recursion print
		void printReverseLLRecursive(Node *h){
			if(h==NULL) return;
			printReverseLLRecursive(h->next);
			cout<<h->data<<" -> ";
		}

		//Method 3: Recursion return Head Node
		Node *reverseLLRecursive(Node *h){
			if(h==NULL || h->next == NULL) return h;
			Node *h2 = reverseLLRecursive(h->next);
			h->next->next = h;
			h->next = NULL;
			return h2;
		}

		void printLinkedList(Node *head){
			Node *temp = head;
			while(temp!=NULL){
				cout<<temp->data<<" -> ";
				temp = temp->next;
			}
			cout<<"NULL";
			cout<<endl;
		}
};

int main(){
	Node *head = new Node(5);
	LinkedList ll;
	head = ll.insertNodeBeginning(head, 4);
	head = ll.insertNodeBeginning(head, 3);
	head = ll.insertNodeBeginning(head, 2);
	head = ll.insertNodeBeginning(head, 1);

	ll.printLinkedList(head);

	cout<<"\nRecursion Print ReversedLL: "<<endl;
	ll.printReverseLLRecursive(head);
	cout<<"NULL";

	cout<<"\nRecursion return Head Node: "<<endl;
	head = ll.reverseLLRecursive(head);
	ll.printLinkedList(head);

	cout<<"\nReversed Linked List: "<<endl;
	Node *reverseList = ll.reverseLinkedList(head);
	ll.printLinkedList(reverseList);

	return 0;
}