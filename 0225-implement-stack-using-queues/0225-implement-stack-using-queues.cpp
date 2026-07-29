class MyStack {
public:
queue<int>q;
int length =0;

    MyStack() {
 
    }
    
    void push(int x) {
        length++;
        q.push(x);
        for(int i=0;i<length-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int b=q.front();
        q.pop();
        length--;
        return b;
    }
    
    int top() {
        int a= q.front();
return a;
    }
    
    bool empty() {
        return length==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */