// Name: David Nguyen
// File: p6a.cpp
// Date: 03/02/20 - 03/15/20
// Description: Stack Program
//  Create the character stack, CharStack
//  Push the characters of array a[] into CharStack
//  Pop the characters of a[] from CharStack to show "hello world!" in reverse

#include <iostream>
using namespace std;

class CharStack
{
    private:
        int size; // size of stackArray
        int top;  // top of stackArray
        char *stackArray;

    public:
    CharStack(int newSize) // constructor
        {
            size = newSize; // set array size
            stackArray = new char[size]; // make a new dynamic array
            top = -1; // no items yet
        }

        // put item on top of stack
        void push(char newValue)
        {
            stackArray[++top] = newValue;
            // increment top, insert item
        }

        // take item from top of stack
        char pop()
        {
            return stackArray[top--];
            // access item, decrement top
        }

        // look at item on top of stack
        char peek()
        {
            return stackArray[top];
            // access item
        }

        bool isEmpty()
        {
            return (top == -1);
        }

        bool isFull()
        {
            return (top == size - 1);
        }

};

int main()
{
    // character array with hello world!
    char a[] = {'h','e','l','l','o',' ','w','o','r','l','d','!'};

    // push all the characters of array a[] into CharStack
    CharStack helloWorld(12);

    for (int i = 0; i < 12; i++) // for loop to push character stack
        helloWorld.push(a[i]);

    // pop characters of a[] from CharStack to show "hello world!" in reverse

    while(!helloWorld.isEmpty())
        cout << helloWorld.pop();
}

/* === OUTPUT ===

!dlrow olleh
Process finished with exit code 0

 */