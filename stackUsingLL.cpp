/************************************************************
 
    Following is the structure of the node class 
 
    class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

**************************************************************/


class Stack {
	// Define the data members
	
    private:
    
	Node *head;
    int size;
    
   public:
    Stack() {
        // Implement the Constructor
        head == NULL;
        size = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return size == 0 ;
    }

    void push(int element) {
        // Implement the push() function
        Node *newNode = new Node(element);
        size++;
        newNode -> next = head;
        head = newNode;
    }

    int pop() {
        // Implement the pop() function
        if(size == 0)
            return -1;
        else
        {
        Node *h = head;
        int val = h -> data;
        size--;
    	head = head -> next;
        
        delete h;
        return val;
        }
    }

    int top() {
        // Implement the top() function
        if(size == 0)
            return -1;
        else
            return head -> data ;
    }
};
