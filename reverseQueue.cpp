#include <queue>
#include <stack>

void reverseQueue(queue<int> &input) {
	// Write your code here
    stack <int> tempStack;
    int element;
    
    while(!input.empty())
    {
        element = input.front();
        input.pop();
        // First we free the space to avoid unnecessary usage of memory
        tempStack.push(element);
    }
    
    while(!tempStack.empty())
    {
        element = tempStack.top();
        tempStack.pop();
        input.push(element);
    }
}
