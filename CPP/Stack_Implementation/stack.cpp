#include <iostream>
#include <queue>
template <class T>
class Stack{
private: 
    std::queue<T> q1;
    std::queue<T> q2;

public:
    void push(T number) {
          
        if(q1.empty())
	{
	    q1.push(number);
	}
	else
        {
	    q2.push(number);
            while(!q1.empty())
	    {
	        q2.push(q1.front());
		q1.pop();
	    }
	    q1 = q2;
	    while(!q2.empty())
	    {
		q2.pop();
	    }
	}	
    }
    
    void pop() {
	q1.pop();
    }
    
    auto top() {
        return q1.front();	
    }

    bool empty() {
	if(q1.empty())
	    return true;
    }
    
    int size() {
	return q1.size();
    }
};

int main()
{

    Stack<float> stack1;
    Stack<int> stack2; 

    stack1.push(1);
    stack1.push(2);
    stack1.push(3.4);
    stack1.push(4);
    stack1.pop();

    stack2.push(1);
    stack2.push(2);

    std::cout << "top after pop: " << stack1.top() << std::endl;
    std::cout << "stack size: " << stack1.size() << std::endl;
    
    
    return 0;
}
