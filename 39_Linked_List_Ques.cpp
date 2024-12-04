#include<iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;
    
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail, int d) {
    // New node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void loopReverseLinkedList(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = head;

    while(curr != NULL) {
        forward = forward -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev; 
}

void reverse1(Node* &head, Node* &curr, Node* prev){
    if(curr == NULL) {
        head = prev;
        return;
    }

    Node* forward = curr -> next;
    reverse1(head, forward, curr);
    curr -> next = prev;
}

Node* reverse2(Node* &head) {
    // base case
    if(head==NULL || head->next == NULL) {
        return head;
    }

    Node* chhotaHead = reverse2(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return chhotaHead;
}

Node* recursiveReverse2LinkedList(Node* &head) {
    return reverse2(head);
}

void recursiveReverse1LinkedList(Node* &head) {
    Node* curr = head;
    Node* prev = NULL;
    reverse1(head, curr, prev);
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtTail(tail, 19);
    insertAtTail(tail, 20);

    cout << "Linked List: ";
    print(head);

    // loopReverseLinkedList(head);

    // recursiveReverse1LinkedList(head);
    // cout << "Reversed Linked List using recursion 1: ";
    // print(head);

    head = recursiveReverse2LinkedList(head);
    cout << "Reversed Linked List using recursion 2: ";
    print(head);

    return 0;
}