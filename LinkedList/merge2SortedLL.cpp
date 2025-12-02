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

Node *merge2SortedLinkedList(Node *head1, Node *head2){
	Node *head3 = new Node(-1); // dummy Node to avoid Edge cases
	Node *tmp = head3; //Answer
	while(head1!=NULL && head2!=NULL){
		if(head1->data > head2->data){
			// add head2 at back of head3
			head3->next = head2;
			head2 = head2->next;
			head3 = head3->next;
		}
		else{
			head3->next = head1;
			head1 = head1->next;
			head3 = head3->next;
		}
	}
	if(head1!=NULL){
		head3->next = head1;
	}
	if(head2!=NULL){
		head3->next = head2;
	}
	//delete dummy Node
	Node *tmp2 = tmp;
	tmp = tmp->next;
	free(tmp2);
	
	return tmp;
}

void printLinkedList(Node *head){
	while(head!=NULL){
		cout<<head->data<<" -> ";
		head = head->next;
	}
	cout<<"NULL";
	cout<<endl;
}

int main(){
	Node *head1 = new Node(8);
	LinkedList ll1;
	head1 = ll1.insertNode(head1, 7);
	head1 = ll1.insertNode(head1, 6);
	head1 = ll1.insertNode(head1, 5);
	cout<<"Linked List 1: \n";
	printLinkedList(head1);

	Node *head2 = new Node(5);
	LinkedList ll2;
	head2 = ll1.insertNode(head2, 4);
	head2 = ll2.insertNode(head2, 3);
	head2 = ll2.insertNode(head2, 2);
	head2 = ll2.insertNode(head2, 1);
	cout<<"Linked List 2: \n";
	printLinkedList(head2);

	cout<<"\nMerged Linked List: \n";
	Node *mergedLL = merge2SortedLinkedList(head1, head2);
	printLinkedList(mergedLL);

	return 0;
}