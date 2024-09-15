// Standard template library
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    // Array
    /*
    array<int, 4> a = {1, 2, 3, 4};
    int size = a.size();
    for(int i=0; i<size; i++){
        cout << a[i] << endl;
    }
    cout << "Element at 2nd Index-> " << a.at(2) << endl;
    cout << "Empty or not-> " << a.empty() << endl;
    cout << "Front Element-> " << a.front() << endl;
    cout << "Last Element-> " << a.back() << endl;
    */

    // Vector - Dynamic array
    /*
    vector<int> v;
    vector<int> a(5,1);
    vector<int> last(a);
    for(int i:a){
        cout << i << " ";
    }cout << endl;

    cout << "Capacity-> " << v.capacity() << endl;

    v.push_back(1);
    cout << "Capacity-> " << v.capacity() << endl;

    v.push_back(2);
    cout << "Capacity-> " << v.capacity() << endl;

    v.push_back(3);
    cout << "Capacity-> " << v.capacity() << endl;
    cout << "Size-> " << v.size() << endl;

    cout << "Element at 2nd Index: " << v.at(2) << endl;

    cout << "Front: " << v.front() << endl;
    cout << "Back: " << v.back() << endl;

    cout << "Before pop: " << endl;
    for(int i:v) {
        cout << i << " ";
    }cout << endl;

    v.pop_back();

    cout << "After pop: " << endl;
    for(int i:v) {
        cout << i << " ";
    }cout << endl;

    cout << "Before clear size: " << v.size() << endl;
    v.clear();
    cout << "After clear size: " << v.size() << endl;
    */

    // Deque
    /*
    deque<int> d;

    d.push_back(1);
    d.push_front(2);

    for(int i:d){
        cout << i << " ";
    }cout<<endl;

    // d.pop_back();
    // d.pop_front();
    for(int i:d){
        cout << i << " ";
    }cout<<endl;

    cout << "Print First Index Element: " << d.at(1) << endl;

    cout << "front: " << d.front() << endl;
    cout << "back: " << d.back() << endl;

    cout << "Empty or not: " << d.empty() << endl;

    cout << "Before erase: " << d.size() << endl;
    d.erase(d.begin(), d.begin()+1);
    cout << "After erase: " << d.size() << endl;
    */

    // List
    /*
    list<int> l;
    list<int> m(l);
    list<int> n(5, 100);

    for(int i:n){
        cout << i << " ";
    }cout << endl;

    l.push_back(1);
    l.push_front(2);

    for(int i:l){
        cout << i << " ";
    }cout << endl;

    l.erase(l.begin());
    cout << "After erase: " << endl;
    for(int i:l){
        cout << i << " ";
    }cout << endl;

    cout << "Size of list: " << l.size() << endl;
    */

    // Stack
    /*
    stack<string> s;
    s.push("Avinash");
    s.push("Kumar");
    s.push("Thakur");

    cout << "Top Element: " << s.top() << endl;

    s.pop();
    cout << "Top Element: " << s.top() << endl;

    cout << "Size of stack: " << s.size() << endl;

    cout << "Empty or not: " << s.empty() << endl;
    */

    // Queue
    /*
    queue<string> q;
    q.push("Avinash");
    q.push("Kumar");
    q.push("Thakur");

    cout << "Top Element: " << q.front() << endl;

    q.pop();
    cout << "Top Element: " << q.front() << endl;
    */

    // Priority Queue
    /*
    //max heap
    priority_queue<int> maxi;

    //min heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);

    cout << "Size-> " << maxi.size() << endl;

    int n = maxi.size();
    for(int i=0; i<n; i++) {
        cout << maxi.top() << " ";
        maxi.pop();
    }cout << endl;

    mini.push(5);
    mini.push(1);
    mini.push(0);
    mini.push(4);
    mini.push(3);

    int m = mini.size();
    for(int i=0; i<m; i++) {
        cout << mini.top() << " ";
        mini.pop();
    }cout << endl;
    */

    // Set
    /*
    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);

    for(auto i:s){
        cout << i << endl;
    }cout << endl;

    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    for(auto i:s){
        cout << i << endl;
    }cout << endl;

    cout << "5 is present or not: " << s.count(5) << endl;

    set<int>::iterator itr = s.find(5);

    for(auto it=itr; it!=s.end(); it++){
        cout << *it << " ";
    }cout << endl;
    */

    // Map
    /*
    map<int, string> m;
    m[1] = "Avinash";
    m[13] = "Thakur";
    m[2] = "Kumar";

    m.insert({5, "bheem"});

    cout<<"Before erase: "<<endl;
    for(auto i:m){
        cout<<i.first << " " << i.second <<endl;
    }

    cout<<"finding -13-> "<<m.count(-13)<<endl;

    m.erase(13);
    cout<<"After erase: "<<endl;
    for(auto i:m){
        cout<<i.first << " " << i.second <<endl;
    }

    auto it = m.find(5);

    for(auto i=it; i!=m.end();i++){
        cout<<(*i).first<<endl;
    }
    */

    // STL Algorithm
    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"Finding 6: "<<binary_search(v.begin(), v.end(), 6)<<endl;

    cout<<"Lower Bound: "<<lower_bound(v.begin(), v.end(), 6)-v.begin()<<endl;

    cout<<"Upper Bound: "<<upper_bound(v.begin(), v.end(), 6)-v.begin()<<endl;

    int a = 3;
    int b = 5;

    cout << "max-> " << max(a,b);

    cout << "min-> " << min(a,b);

    swap(a,b);
    cout<<"a-> "<<a<<endl;
    
    string s="abcd";
    reverse(s.begin(), s.end());
    cout << "String: "<<s<<endl;

    rotate(v.begin(), v.begin()+1, v.end());
    cout<<"After rotate: "<<endl;
    for(int i:v){
        cout<<i<<endl;
    }

    sort(v.begin(), v.end());
    cout<<"After sort: "<<endl;
    for(int i:v){
        cout<<i<<endl;
    }

    return 0;
}