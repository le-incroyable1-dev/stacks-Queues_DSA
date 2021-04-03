#include <stack>
#include <iostream>

void reverseStack(stack<int> &input, stack<int> &extra) {
    
    int element;
    //Write your code here
    while(! input.empty())
    {
        element = input.top();
        extra.push(element);
        input.pop();
    }
    
    input = extra;
    
}
