#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int d){
    // base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root){
    if(root == NULL) return;
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node* root) {
    // base case
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    // base case
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    // base case
    if(root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root -> data << " ";
}

Node* minVal(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }

    return temp;
}

Node* rightMost(Node* node) {
    if (!node) return NULL;
    while (node->right) {
        node = node->right;
    }
    return node;
}

Node* leftMost(Node* node) {
    if (!node) return NULL;
    while (node->left) {
        node = node->left;
    }
    return node;
}

void findPreSuc(Node* root, int x, Node* &pre, Node* &suc) {
    pre = NULL;
    suc = NULL;
    Node* temp = root;

    while (temp) {
        if (temp->data == x) {
            // Node found, compute predecessor and successor
            if(temp->left)
                pre = rightMost(temp->left);

            if(temp->right)
                suc = leftMost(temp->right);

            break;
        }

        if (temp->data > x) {
            // Move left, update successor
            suc = temp;
            temp = temp->left;
        } else {
            // Move right, update predecessor
            pre = temp;
            temp = temp->right;
        }
    }
}

Node* deleteFromBST(Node* root, int val) {
    // base case
    if(root == NULL){
        return root;
    }

    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child

        // left child
        if(root->left && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if(root->right && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left && root->right){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
        return root;
    } else {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST: ";
    takeInput(root);
    
    // level order traversal
    cout <<  "Printing the BST" << endl;
    levelOrderTraversal(root);

    cout << "Printing Inorder: " << endl;
    inorder(root);
    cout << endl;

    cout << "Printing Preorder: " << endl;
    preorder(root);
    cout << endl;
    
    cout << "Printing Postorder: " << endl;
    postorder(root);
    cout << endl;

    cout << "Min value is: " << minVal(root)->data << endl;
    cout << "Max value is: " << maxVal(root)->data << endl;

    Node* pre = NULL;
    Node* suc = NULL;

    findPreSuc(root, 80, pre, suc);
    cout << "Predecessor of 80: " << (pre ? pre->data : -1) << endl;
    cout << "Successor of 80: " << (suc ? suc->data : -1) << endl;

    // DELETING
    root = deleteFromBST(root, 50);

    // level order traversal
    cout <<  "Printing the BST" << endl;
    levelOrderTraversal(root);

    cout << "Printing Inorder: " << endl;
    inorder(root);
    cout << endl;

    cout << "Printing Preorder: " << endl;
    preorder(root);
    cout << endl;
    
    cout << "Printing Postorder: " << endl;
    postorder(root);
    cout << endl;

    return 0;
}