class MyStack {
public:
    queue<int> q;
    int size;
    MyStack() {
        size = 0;
    }
    
    void push(int x) {
        q.push(x);
        for(int i = 0;i<size;i++){
            q.push(q.front());
            q.pop();
        }
        size++;
    }
    
    int pop() {
        if(q.empty())return -1;
        int value = q.front();
        q.pop();
        size--;
        return value;
        
    }
    
    int top() {
        if(q.empty())return -1;
        return q.front();
        
    }
    
    bool empty() {
        if(size == 0)return true;
        else
        return false;
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