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
	 Node *head = new Node(5);
	 LinkedList ll;
	 head = ll.insertNode(head, 4);
	 head = ll.insertNode(head, 3);
	 head = ll.insertNode(head, 2);
	 head = ll.insertNode(head, 1);

	 ll.printLinkedList(head);

	 cout<<"Reversed Linked List: "<<endl;
	 Node *reverseList = ll.reverseLinkedList(head);
	 ll.printLinkedList(reverseList);
	return 0;
}