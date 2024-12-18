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

// k queue in an array

class kQueue {
    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freespot;
        int *next;

    public:
        kQueue(int n, int k) {
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];

            for(int i=0; i<k; i++) {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i<n; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;

            arr = new int[n];
            freespot = 0;
        }

        void enqueue(int data, int qn) {
            // overflow
            if(freespot == -1) {
                cout << "No empty space is present" << endl;
            }

            // find first free index
            int index = freespot;

            // update freespot
            freespot = next[index];

            // check whether first element
            if(front[qn-1] == -1) {
                front[qn-1] = index;
            } else {
                // link new element to the prev element
                next[rear[qn-1]] = index;
            }

            // update next
            next[index] = -1;

            // update rear
            rear[qn-1] = index;

            // push element
            arr[index] = data;
        }

        int deque(int qn) {
            // underflow
            if(front[qn-1] == -1){
                cout << "Queue underflow" << endl;
                return -1;
            }

            // find index to pop
            int index = front[qn-1];

            // front ko aage badhao
            front[qn-1] = next[index];

            // freeSlots ko manage karo
            next[index] = freespot;
            freespot = index;

            return arr[index];
        }
};

// sum of max and min
int solve(int *arr, int n, int k) {

    deque<int> maxi(k);
    deque<int> mini(k);

    //Addition of first k size window

    for(int i=0; i<k; i++) {

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;

    ans += arr[maxi.front()] + arr[mini.front()];

    //remaining windows ko process karlo
    for(int i=k; i<n; i++) {

        

        //next window

        //removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }

        //addition

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);    

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
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
    cout << endl;

    kQueue kq(10, 3);

    kq.enqueue(10, 1);
    kq.enqueue(15,1);
    kq.enqueue(20, 2);
    kq.enqueue(25, 1);

    cout << kq.deque(1) << endl;
    cout << kq.deque(2) << endl;
    cout << kq.deque(1) << endl;
    cout << kq.deque(1) << endl;

    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;

    return 0;
}
