#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
	
};

class LinkedList{
	public:
		Node *insertNode(Node *head, int val){
			Node *temp = new Node(val);
			temp->next = head;
			head = temp;
			return head;
		}
}; //End of the Class 

int lengthOfLinkedList(Node *h){
	int len=0;
	while(h!=NULL){
		h=h->next;
		len++;
	}
	return len;
}
//method 1: length difference
Node *intersectingNode(Node *h1, Node *h2){
	//calculate length of Linked List 1
	int l1 = lengthOfLinkedList(h1);
	int l2 = lengthOfLinkedList(h2); 
	int diff = abs(l1-l2);
	if(l1>l2){
		while(diff>0){
			h1 = h1->next;
			diff--;
		}
	}
	else{
		while(diff>0){
			h2 = h2->next;
			diff--;
		}
	}
	while(h1!=NULL || h2!=NULL){
		if(h1==h2) return h1;
		else{
			h1 = h1->next;
			h2 = h2->next;
		}
	}
	return NULL;
}

/* 	method2: make cycle by pointing Linked List 
 	last node to first Node of other Linked List
 	them take slow and fast pointer
 		- find the intersection point
 		- break the link -> method1 or,
 		- take slow pointer at intersection point and one at starting of the LL
 		- move both the slow pointer they'll meet at intersecting Node
*/

void printLinkedList(Node *head){
	while(head!=NULL){
		cout<<head->data<<" -> ";
		head = head->next;
	}
	cout<<"NULL";
	cout<<endl;
}

int main(){
	Node *head = new Node(3);
	LinkedList ll1;
	head = ll1.insertNode(head, 17);
	head = ll1.insertNode(head, 6);
	head = ll1.insertNode(head, 25);
	head = ll1.insertNode(head, 4);
	Node *commonNode = head;
	head = ll1.insertNode(head, 13);
	head = ll1.insertNode(head, 2);
	head = ll1.insertNode(head, 1);
	cout<<"Linked List1: \n";
	printLinkedList(head);

	LinkedList ll2;
	Node *head2 = new Node(10);
	Node *pointingCommonNode = head2;
	head2 = ll1.insertNode(head2, 17);
	head2 = ll1.insertNode(head2, 6);
	head2 = ll1.insertNode(head2, 25);
	head2 = ll1.insertNode(head2, 15);
	pointingCommonNode->next = commonNode;
	cout<<"\nLinked List2: \n";
	printLinkedList(head2);

	Node *ansNode = intersectingNode(head, head2);
	if(ansNode == NULL) cout<<"\nNo Intersecting Node Found";
	else cout<<"\nIntersecting Node: "<< ansNode->data;

	return 0;
}