/*
Stock Span

Afzal has been working with an organization called 'Money Traders' for the past few years. The organization is into the money trading business.
His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which 
the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].
*/

// O(N^2)

int* stockSpan(int *price, int size)  {
	// Write your code here
    int *ss  = new int[size];
    
    if(size == 1)
    {
        ss[0] = 1;
        return ss;
    }
    else
    {
        int i = 0;
        
        while(i < size)
        {
            if(i == 0)
                ss[i] = 1;
            else
            {
                int cur = price[i];
                int count = 0;
                
                for(int j = i-1 ; j>=0 ; j--)
                {
                    if(price[j] < cur)
                        count++;
                    else
                        break;
                }
                count++;
                ss[i] = count;
            }
            
            i++;
        }
        
        return ss;
    }
        
}


//O(N)

One reason why the time complexity is quadratic is because we are redoing work which
has been done before. Let’s take a look at the sample input. When we reverse-iterated
for element ‘70’ and got 2 for that position, we knew that 70 is the largest element in the
array till its index. So for the next iteration when we encounter 80, we know that 80 is
larger than 70 and 70 was the largest element in its prefix (the part of the array from
index 0 to the current index), so we automatically can conclude that 80 is the largest
element in its prefix and directly put 3 for that position. Same for position of element
100.

To avoid the extra comparisons, we can use a stack to keep track of elements that
we’ve encountered so far and remove elements that have a higher element after them.
Let’s do a dry run on the sample input which is:
60 70 80 100 90 75 80 120
0 1 2 3 4 5 6 7
	
	
Let’s also maintain a stack which is going to store the indices of the concerned
elements, not the elements themselves.
	
Let’s iterate through the array using the variable i and maintain an array called ‘span’
which will store the span values for each element.
1. (i = 0) The stack is empty right now. So span[i] will be directly equal to i+1. No
need to do any other work. Remember, an empty stack denotes that the current
element is the largest in its prefix. After we set the value of span[i], we’ll push the
index (which is 0) into the stack. Note, that we push ‘0’, not ‘60’.
2. (i = 1) The stack is not empty. This denotes that the current element may or may
not be the largest in its prefix. We can’t be sure just yet. So let’s iterate through
the stack and remove those indices from stack’s top for which the current
element is larger than the element at stack’s top’s index. So in our case the stack
had 0. Since arr[1] > arr[stack-top], we can pop the top element from stack. Now,
the stack is empty and this means arr[i] is the largest in its prefix so span[i] can
be directly assigned the value of i+1 and then we push ‘i’ to the stack. If you
notice, there will be similar cases for i=2 and i=3. So let’s move on to...
3. (i = 4) The stack is not empty. The only value it contains is ‘3’, the index of 100.
This case is different because arr[i] is less than arr[stack-top]. This signifies that
the nearest element to ‘90’ which is larger than it and to its left is at index ‘3’. In
this case, we don’t pop stack’s top. Instead, we find the distance between the
current element and stack’s top which will be i - stacktop or 4 - 3 or 1.
So we put span[i] = 1 and push ‘i’ to stack. Continuing on in this way we can fill
the span array completely.
	
The pseudo-code for this approach :


function stockSpan(arr,n):
span <- array of size n
stk <- stack of integers
for(i = 0; i < n; ++i):
while(stk is not empty and arr[stk.top()] < arr[i]):
stk.pop()
if(stk is empty):
span[i] <- i + 1
else:
span[i] <- i - stk.top()
stk.push(i)
return span
