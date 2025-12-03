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

//get middle Node of the LinkedList
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
// Merge 2 LinkedList Sorted Recursive
Node *merge2SortedLLRecursive(Node *head1, Node *head2){
	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;

	if(head1->data < head2->data){
		head1->next = merge2SortedLLRecursive(head1->next, head2);
		return head1;
	}
	else{
		head2->next = merge2SortedLLRecursive(head1, head2->next);
		return head2;
	}
}

// Merge 2 LinkedList Sorted Iterative
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

Node *mergeSortLL(Node *head){
	if(head==NULL || head->next == NULL) return head;
	// Break LinkedList into 2 parts from the mid
	Node *mid = middleLL(head, true); //get 1st mid
	Node *head2 = mid->next;
	mid->next = NULL;

 	head = mergeSortLL(head);
    head2 = mergeSortLL(head2);
    // return merge2SortedLinkedList(head, head2);
    return merge2SortedLLRecursive(head, head2);

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
	Node *head = new Node(3);
	LinkedList ll1;
	head = ll1.insertNode(head, 17);
	head = ll1.insertNode(head, 6);
	head = ll1.insertNode(head, 25);
	head = ll1.insertNode(head, 4);
	head = ll1.insertNode(head, 13);
	head = ll1.insertNode(head, 2);
	head = ll1.insertNode(head, 1);
	cout<<"Linked List: \n";
	printLinkedList(head);

	Node *sortedHead = mergeSortLL(head);
	cout<<"\nSorted Linked List: \n";
	printLinkedList(sortedHead);

	return 0;
}