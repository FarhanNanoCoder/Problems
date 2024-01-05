#include<bits/stdc++.h>
using namespace std;
class MinStack {
    stack<int> a;
    stack<int> b;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        a.push(val);
        if(b.empty()) {b.push(val);}
        else {
            b.push(min(b.top(),val));
        }
    }
    
    void pop() {
        a.pop();
        b.pop();
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return b.top();
    }
};

int main(){
    MinStack* obj = new MinStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);

    cout<<obj->getMin()<<endl;
    obj->pop();
    cout<<obj->getMin()<<endl;
    obj->pop();
    cout<<obj->getMin()<<endl;
}