class MinStack {
public:
    stack<int>st,minst;
    MinStack() {
       
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minst.push(val);
            return;
        }
        st.push(val);
        if(val<minst.top()){
            minst.push(val);
        }else{
            minst.push(minst.top());
        }
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        int ele=st.top();
        return ele;
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */