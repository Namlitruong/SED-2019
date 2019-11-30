
#define MAX 1000
//////////////////////////--Stack--/////////////////////////////
class Stack {
    int *arr;
    int top;
    int capacity;
public:
    Stack(int size = MAX);     // constructor
    ~Stack();                   // destructor
 
    void push(int);
    int pop();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

Stack::Stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}

// Destructor to free memory allocated to the stack
Stack::~Stack()
{
    delete arr;
}

void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack Overflow!!!";
    }
 
    cout << "Inserting " << x << endl;
    arr[++top] = x;
}

//removes or pops elements out of the stack
int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow!!";
		return 0;
    }
 
    cout << "Removing " << peek() << endl;
 
    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}

int Stack::size()
{
    return top + 1;
}

int Stack::peek()
{
    if (!isEmpty()){
        return arr[top];
	}
}
//check if stack is empty
bool Stack::isEmpty()
{
    return top == -1;    // or return size() == 0;
}
bool Stack::isFull()
{
    return top == capacity - 1;    // or return size() == capacity;
}
