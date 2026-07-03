class MyStack {
private: 
    queue<int> q1; 
    queue<int> q2;     
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x); 
        while(!q1.empty()){
            int a = q1.front(); 
            q1.pop(); 
            q2.push(a); 
        }
        queue<int> temp = q1; 
        q1 = q2; 
        q2 = temp; 
    }
    
    int pop() {
        int a = q1.front(); 
        q1.pop();
        return a;  

    }
    
    int top() {
        return q1.front(); 
    }
    
    bool empty() {
        return q1.empty(); 
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