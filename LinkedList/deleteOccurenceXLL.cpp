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

		//Q. Delete All the Occurence of X
		Node *deleteOccurenceXLL(Node *head, int X){
			if(head==NULL) return head;
			Node *tmp = head;
			while(tmp->next!=NULL){
				if((tmp->next!=NULL) && (tmp->next->data==X)){
					tmp->next = tmp->next->next;
				}
				else
					tmp = tmp->next;
			}
			if(head->data==X) return head->next; //Edge case for 1st element is X
			return head;
		}

		// Method 2: Recursion
		Node *deleteOccurenceXLLRecursion(Node *head, int X){
			if(head == NULL) return NULL;
			if(head->data == X){
				return deleteOccurenceXLLRecursion(head->next, X);
			}
			else{
				head->next = deleteOccurenceXLLRecursion(head->next, X);
				return head;
			}
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
	head = ll.insertNodeAtLast(head, 1);
	head = ll.insertNodeAtLast(head, 1);
	head = ll.insertNodeAtLast(head, 10);
	head = ll.insertNodeAtLast(head, 14);
	head = ll.insertNodeAtLast(head, 14);
	head = ll.insertNodeAtLast(head, 8);
	head = ll.insertNodeAtLast(head, 14);
	head = ll.insertNodeAtLast(head, 15);
	cout<<"Given Linked List:\n";
	ll.printLinkedList(head);
	/* Now we have to insert X so that the 
	entire Linked List will remain sorted
	*/
	int x = 1;
	head = ll.deleteOccurenceXLL(head, x);
	cout<<"\nIterator method:\n";
	ll.printLinkedList(head);

	head = ll.deleteOccurenceXLLRecursion(head, x);
	cout<<"\nRecursion method:\n";
	ll.printLinkedList(head);
	return 0;
}