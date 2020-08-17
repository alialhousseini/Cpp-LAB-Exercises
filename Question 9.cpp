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

int maxx(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}

int countListNodes(ListNode *head)
{
    int count = 0;
    ListNode *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

Node* ListToBST(ListNode **head, int n)
{
    if (n <= 0)
        return NULL;
    Node *left = ListToBST(head, n/2);
    Node *root = newNode((*head)->data);
    root->left = left;
    *head = (*head)->next;
    root->right = ListToBST(head, n - n / 2 - 1);
    return root;
}


Node* sortedLtoBST(ListNode *head)
{
    int n = countListNodes(head);
    return ListToBST(&head, n);
}

void push(ListNode** head, int new_data)
{
    ListNode* new_node = new ListNode();
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void printList(ListNode *node)
{
    while(node!=NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int height(Node* node)
{
    if (node == NULL)
        return 0;
    return 1 + maxx(height(node->left),
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

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
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

int main()
{
    Node* root1 = newNode(42);
    root1->left = newNode(25);
    root1->right = newNode(68);
    root1->left->left = newNode(1);
    root1->left->right = newNode(35);
    root1->right->left= newNode(63);
    root1->right->right= newNode(70);
    root1->right->left->left = newNode(59);
    root1->right->left->right = newNode(65);
    root1->right->right->right = newNode(79);

    if (isBalanced(root1))
        cout << "Tree is balanced\n";
    else
        cout << "Tree is not balanced\n";

    root1 = buildTree(root1);

    cout << "Preorder of balanced BST: \n";
    preOrder(root1);
    cout<<"\n";
    cout << "Postorder of balanced BST: \n";
    printPostorder(root1);
    cout<<"\n";
    cout << "Inorder of balanced BST: \n";
    printInorder(root1);

    Node* root2 = newNode(42);
    root2->left = newNode(35);
    root2->right = newNode(68);
    root2->left->left = newNode(1);
    root2->right->left= newNode(59);
    root2->right->right= newNode(70);
    root2->left->left->right = newNode(25);
    root2->right->left->right = newNode(63);
    root2->right->right->right = newNode(79);
    root2->right->right->right->left = newNode(65);

    cout<<"\n";
    if (isBalanced(root2))
        cout << "Tree is balanced\n";
    else
        cout << "Tree is not balanced\n";

    root2 = buildTree(root2);

    cout << "Preorder of balanced BST: \n";
    preOrder(root2);
    cout<<"\n";
    cout << "Postorder of balanced BST: \n";
    printPostorder(root2);
    cout<<"\n";
    cout << "Inorder of balanced BST: \n";
    printInorder(root2);

    ListNode* head = NULL;
    push(&head, 1);
    push(&head, 25);
    push(&head, 35);
    push(&head, 42);
    push(&head, 59);
    push(&head, 63);
    push(&head, 65);
    push(&head, 68);
    push(&head, 70);
    push(&head, 79);

    cout<<"Given Linked List \n";
    printList(head);

    Node *root3 = sortedLtoBST(head);
    cout<<"\n";
    cout<<"\nPreorder of balanced BST: \n";
    preOrder(root3);
    cout<<"\n";
    cout << "Postorder of balanced BST: \n";
    printPostorder(root3);
    cout<<"\n";
    cout << "Inorder of balanced BST: \n";
    printInorder(root3);

    return 0;
}
