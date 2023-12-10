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


		Node * reverseFirstKNode(Node *h1, int k){

			Node *tmp1 = h1;
			while(k>0 && tmp1!=NULL){
				tmp1 = tmp1->next;
				k--;
			}
			Node *h2 = NULL;
			Node *tmp = h1;
			Node *tail = h1;
			while(h1!=tmp1){
				h1=h1->next;
				tmp->next = h2;
				h2=tmp;
				tmp = h1;
			}
			tail->next = tmp1;

			return h2;

		}

		Node * reverseInKGroups(Node *h1, int k){
			if(h1==NULL) return h1;

			Node * h2 = reverseFirstKNode(h1,k);
			h1->next = reverseInKGroups(h1->next,k);
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
	 Node *head = new Node(7);
	 LinkedList ll;
	 head = ll.insertNode(head, 6);
	 head = ll.insertNode(head, 5);
	 head = ll.insertNode(head, 4);
	 head = ll.insertNode(head, 3);
	 head = ll.insertNode(head, 2);
	 head = ll.insertNode(head, 1);

	 ll.printLinkedList(head);

	 int k = 4;
	 cout<<"First K Reversed Linked List: "<<endl;
	 Node *reverseList = ll.reverseInKGroups(head,k);
	 ll.printLinkedList(reverseList);
	return 0;
}