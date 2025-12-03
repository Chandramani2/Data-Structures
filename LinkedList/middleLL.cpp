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

		Node *middleLL(Node *head, bool check){
			if(head==NULL) return NULL;
			Node *slow = head;
			Node *fast = head;
			while(fast->next!=NULL && fast->next->next!=NULL){
				slow = slow->next;
				fast = fast->next->next;
			}
			if(fast->next == NULL){
				//Length is odd
				return slow;
			}
			else{
				// Length is even
				if(check) return slow;
				else return slow->next;
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
	 Node *head = new Node(8);
	 LinkedList ll;
	 head = ll.insertNode(head, 7);
	 head = ll.insertNode(head, 6);
	 head = ll.insertNode(head, 5);
	 head = ll.insertNode(head, 4);
	 head = ll.insertNode(head, 3);
	 head = ll.insertNode(head, 2);
	 head = ll.insertNode(head, 1);
	  cout<<"Given Linked List: \n";
	 ll.printLinkedList(head);

	/* 	check = true -> 1st mid
		check = false -> 2nd mid
 	*/
	 bool check = false;
	 cout<<"\nMiddle Node Value: "<<ll.middleLL(head, check)->data;

	return 0;
}