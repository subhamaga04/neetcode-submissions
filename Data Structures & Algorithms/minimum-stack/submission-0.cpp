class MinStack {
public:
    stack<int> min; 
    stack<int> normal; 

    MinStack() {
        
    }
    
    void push(int val) {
        if(min.empty() || val <= min.top()) min.push(val); 
        normal.push(val); 
    }
    
    void pop() {
        if(normal.top() == min.top()) min.pop(); 
        normal.pop(); 
    }
    
    int top() {
        return normal.top(); 
    }
    
    int getMin() {
        return min.top(); 
    }
};
