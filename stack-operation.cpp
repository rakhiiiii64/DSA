//stack operation
#include <iostream>
using namespace std;
class Stack
{
    int n;
    int *arr;
    int top;
    
    public:
    Stack(int m)
    {
        n=m;
        top=-1;
        arr = new int[n];
    }
    ~Stack()
    {
        delete[] arr;
    }
    void push(int x)
    {
        if(top==n-1)
        {
            cout << endl << "stack overflow" << endl << endl;
        }
        else
        {
            arr[++top]=x;
            cout << x << " pushed into stack" << endl;
        }
    }
    void pop()
    {
        if(top==-1)
        {
            cout << endl << "stack underflow" << endl << endl;
        }
        else
        {
            cout << arr[top--] << " poped from stack" << endl;
        }
    }
    
    void peek()
    {
        if(top==-1)
        {
            cout << endl << "stack is empty" << endl;
        }
        else
        {
            cout << arr[top] << " is the top element " << endl;
        }
    }
    void display()
    {
        if(top==-1)
        {
            cout << endl << "stack is empty" << endl << endl;
        }
        else
        {
            cout << "stack element" << endl;
            for(int i=top;i>=0;i--)
            {
                cout << arr[i] << endl;
            }
        }
    }

    int isEmpty()
    {
        return top==-1;
    }

    int isFull()
    {
        return top==n-1;
    }

};

int main()
{
    int a;
    cout << "enter the size of stack: ";
    cin >> a;
    Stack s1(a);
    s1.push(4);
    s1.push(9);
    
    s1.display();
    
    s1.peek();
    s1.pop();
    s1.peek();
    s1.pop();

    s1.isFull();
    s1.isEmpty();

    return 0;
}