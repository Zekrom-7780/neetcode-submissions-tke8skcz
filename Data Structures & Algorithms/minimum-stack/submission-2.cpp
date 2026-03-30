

class MinStack {
public:
        stack<int> s;
        stack<int> minStack;
        
    MinStack() {
        
            }
    
    void push(int val) {
        s.push(val);
        if (minStack.empty() || val<=minStack.top()){
            minStack.push(val);
        }
    }
    
    void pop() {
        if (s.top()==minStack.top()){
            minStack.pop();
        }
        s.pop();
    }
    
    int top() {
        int ans=s.top();
        return ans;

    }
    
    int getMin() {
        return minStack.top();
    }
};
