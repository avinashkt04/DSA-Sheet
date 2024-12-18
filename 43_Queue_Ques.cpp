#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Interleaving the first half of queue in second half


// solution using new queue
/*
void interLeaveQueue(queue<int>& q) {
    int n = q.size();
    
    queue<int> newQ;

    for(int i=0; i<n/2; i++){
        int val = q.front();
        q.pop();
        newQ.push(val);
    }

    while(!newQ.empty()) {
        int val1 = newQ.front();
        newQ.pop();
        q.push(val1);
        int val2 = q.front();
        q.pop();
        q.push(val2);
    }

}
*/

// solution using stack
void interLeaveQueue(queue<int> &q) {
    int n = q.size();

    stack<int> s;

    for(int i=0; i<n/2; i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    for(int i=0; i<n/2; i++){
        q.push(q.front());
        q.pop();
    }

    for(int i=0; i<n/2; i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }



}

int main() {
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
