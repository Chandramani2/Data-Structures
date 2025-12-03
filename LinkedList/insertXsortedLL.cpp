#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int data){
		this -> data = data;
		this -> next = NULL;
	}
};

class LinkedList{
	public:
		
		// Insert New Node at Beginning
		Node *insertNodeBeginning(Node *head, int val){
			Node *newNode = new Node(val);
			newNode->next = head;
			return newNode;
		}
		// Insert New Node at Lat
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

		//Q. Insert X in sorted LL
		Node *insertXSortedLL(Node *head, int X){
			Node *newNode = new Node(X);
			if(head==NULL || X<head->data){ // Edge Case
				newNode->next = head;
				return newNode;
			}
			Node *tmp = head;
			//Edge Case
			while((tmp->next!=NULL) && tmp->next->data < X){
				tmp = tmp->next;
			}
			newNode->next = tmp->next;
			tmp->next = newNode;
			return head;
		}

		void printLinkedList(Node *head){
			while(head!=NULL){
				cout<<head->data<<" -> ";
				head = head->next;
			}
			cout<<"NULL";
			cout<<endl;
		}
};

int main(){
	Node *head = new Node(1);
	LinkedList ll;
	head = ll.insertNodeAtLast(head, 4);
	head = ll.insertNodeAtLast(head, 8);
	head = ll.insertNodeAtLast(head, 10);
	head = ll.insertNodeAtLast(head, 14);
	ll.printLinkedList(head);
	/* Now we have to insert X so that the 
	entire Linked List will remain sorted
	*/
	int x = 19;
	head = ll.insertXSortedLL(head, x);
	ll.printLinkedList(head);
	return 0;
}