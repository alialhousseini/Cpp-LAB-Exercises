#include <iostream>
using namespace std;

typedef struct Node {
	int data;
	struct Node* next;
}Node;

void push(Node** root, int new_data)
{
	Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*root);
	(*root) = new_node;
}

bool isPresent(Node* head, int data)
{
	struct Node* t = head;
	while (t != NULL) {
		if (t->data == data)
			return 1;
		t = t->next;
	}
	return 0;
}

struct Node* getIntersection(Node* head1,Node* head2)
{
    Node* result = NULL;
    Node* t1 = head1;
	while (t1 != NULL)
    {
		if (isPresent(head2, t1->data))
			push(&result, t1->data);
		t1 = t1->next;
	}

	return result;
}

bool disjoint(Node* X)
{
    if(X==NULL)
        return true;
    else return false;
}

void printList(Node* node)
{
	while (node != NULL) {
		cout<<node->data<<"\t";
		node = node->next;
	}
}


int main()
{
	Node* head1 = NULL;
	Node* head2 = NULL;
	Node* intersecn = NULL;
	Node* unin = NULL;


	push(&head1, 20);
	push(&head1, 4);
	push(&head1, 15);
	push(&head1, 10);


	push(&head2, 1);
	push(&head2, 2);
	push(&head2, 3);
	push(&head2, 8);

	intersecn = getIntersection(head1, head2);

	cout<<"\nFirst list is: \n";
	printList(head1);

	cout<<"\nSecond list is: \n";
	printList(head2);

	cout<<"\nIntersection list is: \n";
	printList(intersecn);

	cout<<"\nThe two lists are:\t";
	if (disjoint(intersecn) == true)
        cout<<"Disjoint\n";
    else
        cout<<"NON DISJOINT";
	return 0;
}
