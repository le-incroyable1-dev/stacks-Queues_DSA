/*
Stock Span

Afzal has been working with an organization called 'Money Traders' for the past few years. The organization is into the money trading business.
His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which 
the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].
*/


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
