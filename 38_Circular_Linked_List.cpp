#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    
    // constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    // destructor
    ~Node() {
        int value = this -> data;
        // memory free
        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertNode(Node* &tail, int element, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        temp -> next = temp;
        tail = temp;
    } else {
        // non empty list
        // assuming that the element is present in the list

        Node* curr = tail;

        while(curr -> data != element) {
            curr = curr -> next;
        }

        // element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void deleteNode(Node* &tail, int value) {
    // empty list
    if(tail == NULL) {
        cout << "List is empty, please check again" << endl;
        return;
    } else {
        // non empty

        // assuming that "value" is present in the linked list
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        // 1 node linked list
        if(curr == prev) {
            tail = NULL;
        }
        // >=2 node linked list
        if(tail == curr) {
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* tail) {
    Node* temp = tail;

    if(tail == NULL) {
        cout << "List is empty" << endl;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    }  while(tail != temp);
    cout << endl;
}

bool isCircularList(Node* head) {
    // empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head){
        temp = temp -> next;
    }

    if(temp == head) {
        return true;
    }

    return false;
}

int main() {

    Node* tail = NULL;

    // empty list me insert krre hai
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 7);
    print(tail);

    insertNode(tail, 7, 12);
    print(tail);

    // insertNode(tail, 3, 5);
    // print(tail);

    // insertNode(tail, 5, 7);
    // print(tail);

    // insertNode(tail, 7, 9);
    // print(tail);

    // insertNode(tail, 5, 6);
    // print(tail);

    // insertNode(tail, 9, 10);
    // print(tail);

    // insertNode(tail, 3, 4);
    // print(tail);

    // deleteNode(tail, 3);
    // print(tail);

    // deleteNode(tail, 10);
    // print(tail);

    // deleteNode(tail, 3);
    // print(tail);

    if(isCircularList(tail)){
        cout << "Linked List is Circular in nature" << endl;
    } else {
        cout << "Linked List is not circular in nature" << endl;
    }

    return 0;
}