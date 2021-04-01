/*
Code : Balanced Parenthesis
Send Feedback
For a given a string expression containing only round brackets or parentheses, check if 
they are balanced or not. Brackets are said to be balanced if the bracket which opens 
last, closes first.
*/

#include <stack>

bool isBalanced(string expression) 
{
    // Write your code here
    int i = 0;
    stack <char> p;
    
    while(expression[i])
    {
        char cur = expression[i];
        
        if(cur == '(')
            p.push(cur);
        else
        {
            if(!p.empty())
            {
                p.pop();
            }
            else
                return false;
        }
        
        i++;
    }
    
    if(p.size() == 0)
        return true;
    else
        return false;
    
}
            
