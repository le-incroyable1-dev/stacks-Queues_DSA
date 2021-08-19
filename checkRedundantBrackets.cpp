/*
Check redundant brackets

For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given 
that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.

Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.

Note:
You will not get a partial score for this problem. You will get marks only if all the test cases are passed.

Input Format :
The first and the only line of input contains a string expression, without any spaces in between.

Output Format :
The first and the only line of output will print either 'true' or 'false'(without the quotes) denoting whether the input expression contains redundant brackets or not.
Note:
You are not required to print the expected result. It has already been taken care of.

Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1 second
*/

#include <stack>

bool checkRedundantBrackets(string expression) {
    
    int len = expression.length();
    
    if(len == 0)
        return false;
    
    stack <char> myStack;
    bool closed = true;
    
    for(int i = 0; i < len; i++)
    {
        myStack.push(expression[i]);;
        
        if(expression[i] == '(' && (expression[i+1] == ')' || expression[i+2] == ')'))
            return true;
        
        if(expression[i] == ')' )
        {
            closed = false;
            myStack.pop();
    
            if(myStack.top() == '(' )
                return true;
            
            while(!myStack.empty())
            {
                if(myStack.top() == '(')
                {
                    myStack.pop();
                    closed = true;
                    break;
                }
                
                myStack.pop();
            }
        }
            
    }
    
    return !closed;
}
