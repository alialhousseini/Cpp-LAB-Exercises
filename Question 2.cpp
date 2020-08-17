#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* left, *right;
};

struct ListNode
{
    int data;
    ListNode* next;
};

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    cout<<node->data<<"\t";
    preOrder(node->left);
    preOrder(node->right);
}

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int height(Node* node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left),
                   height(node->right));
}

bool isBalanced(Node* root)
{
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */

    /* If tree is empty then return true */
    if (root == NULL)
        return 1;

    /* Get the height of left and right sub trees */
    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    /* If we reach here then
    tree is not height-balanced */
    return 0;
}

void storeBSNodes(Node* root, vector<Node*> &nodes)
{

    if (root==NULL)
        return;
    storeBSNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSNodes(root->right, nodes);
}

Node* buildTreeUtil(vector<Node*> &nodes, int start,int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end)/2;
    Node *root = nodes[mid];
    root->left  = buildTreeUtil(nodes, start, mid-1);
    root->right = buildTreeUtil(nodes, mid+1, end);

    return root;
}

Node* buildTree(Node* root)
{
    vector<Node *> nodes;
    storeBSNodes(root, nodes);
    int n = nodes.size();
    return buildTreeUtil(nodes, 0, n-1);
}


void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    cout << node->data << " ";
}

void printInorder(struct Node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    printInorder(node->right);
}

class NodeOfLL {
public:
    int data;
    NodeOfLL* next;
    NodeOfLL(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// A binary tree node
class treeNode {
public:
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


// Function to create Linked list from given binary tree
NodeOfLL* sortedList(NodeOfLL* head, Node* root)
{
    // return head if root is null
    if (root == NULL) {
        return head;
    }

    // First make the sorted linked list
    // of the left sub-tree
    head = sortedList(head, root->left);
    NodeOfLL* newNode = new NodeOfLL(root->data);
    NodeOfLL* temp = head;
    NodeOfLL* prev = NULL;

    // If linked list is empty add the
    // node to the head
    if (temp == NULL) {
        head = newNode;
    }
    else {

        // Find the correct position of the node
        // in the given linked list
        while (temp != NULL) {
            if (temp->data > root->data) {
                break;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }

        // Given node is to be attached
        // at the end of the list
        if (temp == NULL) {
            prev->next = newNode;
        }
        else {

            // Given node is to be attached
            // at the head of the list
            if (prev == NULL) {
                newNode->next = temp;
                head = newNode;
            }
            else {

                // Insertion in between the list
                newNode->next = temp;
                prev->next = newNode;
            }
        }
    }

    // Now add the nodes of the right sub-tree
    // to the sorted linked list
    head = sortedList(head, root->right);
    return head;
}

void print(NodeOfLL* head)
{
    if (head == NULL) {
        return;
    }
    NodeOfLL* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* root = newNode(1);
    root->right = newNode(9);
    root->right->left= newNode(6);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(5);

    if (isBalanced(root))
        cout << "Tree is balanced\n";
    else
        cout << "Tree is not balanced\n";

    cout << "\nPreorder of OLD BST: \n";
    preOrder(root);
    cout << "\nPostorder of OLD BST: \n";
    printPostorder(root);

    root = buildTree(root);

    cout << "\nPreorder of NEW BALANCED BST: \n";
    preOrder(root);
    cout << "\nPostorder of NEW BALANCED BST: \n";
    printPostorder(root);
    cout<<"\n";
    cout<<"Linked List of this BST:\n";

    Node* rootX = newNode(1);
    rootX->right = newNode(9);
    rootX->right->left= newNode(6);
    rootX->right->left->left = newNode(4);
    rootX->right->left->right = newNode(5);

    NodeOfLL* head = sortedList(NULL, rootX);
    print(head);

    return 0;
}
