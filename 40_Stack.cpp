#include<iostream>
#include<stack>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};


class Stack {

    /* 
    // *****ARRAY*****

    // properties
    public:
        int *arr;
        int top;
        int size;

    // behaviour
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push (int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        } else {
            cout << "Stack underflow" << endl;
        }
    }

    int peek() {
        if(top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        } else {
            return false;
        }
    }

    */

    // *****LINKED LIST*****

    // properties
    public:
        Node* top;
    

    // behaviour
    Stack() {
        top = NULL;
    }
    
    void push(int element) {
        Node* newNode = new Node(element);
        newNode -> next = top;
        top = newNode;
    }

    void pop() {
        if(top==NULL) {
            cout << "Stack Underflow" << endl;
        }
        Node* temp = top;
        top = top -> next;
        delete temp;
    }

    int peek() {
        if(top==NULL) {
            cout << "Stack Underflow" << endl;
            return -1;
        } else {
            return top -> data;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }
    
};

int main () {
    /*
    // creation of stack 
    stack<int> s;

    // push operation 
    s.push(2);
    s.push(3);

    // pop operation
    s.pop();

    cout << "Printing top element " << s.top() << endl;

    if(s.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    cout << "Size of stack " << s.size() << endl;
    */

    Stack st;

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(66);

    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    if(st.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}