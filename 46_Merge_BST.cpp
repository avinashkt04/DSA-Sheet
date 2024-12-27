#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return root;
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void convertIntoSortedDLL(Node* root, Node*& head) {
    if (root == NULL)
        return;

    convertIntoSortedDLL(root->right, head);

    root->right = head;

    if (head)
        head->left = root;

    head = root;

    convertIntoSortedDLL(root->left, head);
}

Node* mergeLinkedList(Node* head1, Node* head2) {
    Node* head = NULL;
    Node* tail = NULL;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            if (head == NULL) {
                head = head1;
                tail = head1;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
            }
            head1 = head1->right;
        } else {
            if (head == NULL) {
                head = head2;
                tail = head2;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
            }
            head2 = head2->right;
        }
    }

    while (head1) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while (temp) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node* sortedLLToBST(Node*& head, int n) {
    if (n <= 0 || head == NULL) {
        return NULL;
    }

    Node* left = sortedLLToBST(head, n / 2);

    Node* root = head;
    root->left = left;
    head = head->right;

    root->right = sortedLLToBST(head, n - n / 2 - 1);
    return root;
}

Node* mergeBST(Node* root1, Node* root2) {
    Node* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    Node* mergedHead = mergeLinkedList(head1, head2);

    return sortedLLToBST(mergedHead, countNodes(mergedHead));
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;

    cout << "Enter data to create BST-1: ";
    takeInput(root1);

    cout << "Enter data to create BST-2: ";
    takeInput(root2);

    cout << "Printing the BST-1: " << endl;
    levelOrderTraversal(root1);

    cout << "Printing the BST-2: " << endl;
    levelOrderTraversal(root2);

    Node* newRoot = mergeBST(root1, root2);
    cout << "After merging 2 BSTs: " << endl;
    levelOrderTraversal(newRoot);

    return 0;
}
