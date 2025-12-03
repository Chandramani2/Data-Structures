#include<bits/stdc++.h>
using namespace std;
/* Given sorted SLL delete repeated elements */
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

		//Q. Delete All the Repeated Elements
		Node *deleteRepeated(Node *head){
			if(head==NULL) return head;
			Node *tmp = head;
			while(tmp->next!=NULL){
				if(tmp->next->data==tmp->data){
					tmp->next = tmp->next->next;
				}
				else
					tmp = tmp->next;
			}
			return head;
		}

		// Method 2: Recursion
		Node *deleteRepeatedRecursion(Node *head){
			if(head == NULL) return NULL;
			if(head->next!=NULL && head->data == head->next->data){
				return deleteRepeatedRecursion(head->next);
			}
			else{
				head->next = deleteRepeatedRecursion(head->next);
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
	head = ll.insertNodeAtLast(head, 8);
	head = ll.insertNodeAtLast(head, 8);
	head = ll.insertNodeAtLast(head, 10);
	head = ll.insertNodeAtLast(head, 14);
	head = ll.insertNodeAtLast(head, 14);
	head = ll.insertNodeAtLast(head, 14);
	cout<<"Given Linked List:\n";
	ll.printLinkedList(head);
	/* Now we have to insert X so that the 
	entire Linked List will remain sorted
	*/
	
	head = ll.deleteRepeated(head);
	cout<<"\nIterator method:\n";
	ll.printLinkedList(head);

	head = ll.deleteRepeatedRecursion(head);
	cout<<"\nRecursion method:\n";
	ll.printLinkedList(head);
	return 0;
}