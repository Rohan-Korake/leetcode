class MyStack {
public:
queue<int> myQueue;

    MyStack() {
        
    }
    
    void push(int x) {
        myQueue.push(x);
        int size=myQueue.size();

        for (int i = 0; i < size - 1; ++i) {
            myQueue.push(myQueue.front());
            myQueue.pop();
        }
    }
    
    int pop() {
        int topElement=myQueue.front();
        myQueue.pop();
        return topElement;
    }
    
    int top() {
        return myQueue.front();
    }
    
    bool empty() {
        return myQueue.empty();
    }
};
