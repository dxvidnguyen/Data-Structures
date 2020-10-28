// Name: David Nguyen
// File: p6b.cpp
// Date: 03/02/20 - 03/15/20
// Description: Dequeue Program
// Implement a double ended queue (dequeue) with the following functions
//  •	insertLeft (int value)
//  •	insertRight (int value)
//  •	removeLeft
//  •	removeRight

#include <iostream>
using namespace std;

class Queue
{
    private:
        int size, front, rear, number_items;
        int *queueArray;


    public:
        Queue(int newSize) // constructor
        {
            size = newSize;
            queueArray = new int[size];
            number_items = 0; // number of items is 0 at beginning
            front = 0; // front moves forward (+) upon remove
            rear = -1; // nothing there yet, rear moves forward (+) upon insert

        }

        // designate left side as front and right side as rear

        // inserting from the front, changes the rear
        void insertLeft(int value)
        {
            // deal with wrap around
            if (rear == size - 1) // reached the far right
                rear = -1; // move to the far left

            rear++; // increment the rear
            queueArray[rear] = value; // insert item
            number_items++; // one item added
        }

        // inserting from the rear, changing the front
        void insertRight(int value)
        {
            // deal with the wrap around
            if(front == 0)
                front = size;

            front--; // decrement the front
            queueArray[front] = value; // insert item
            number_items++; // one item added
        }

        // removing from the front, changing the front
        int removeLeft()
        {
            // post increment (front)
            int temp = queueArray[front];
            front++;

            if(front == size) // all the way at the right side
                front = 0; // move back to left side

            number_items--; // one less item
            return temp;
        }

        // removing from the rear, changes the rear
        int removeRight()
        {
            // post increment (rear)
            int temp = queueArray[rear];
            rear--;

            if(rear == -1) // all the way on the left side
                rear = size - 1; // move back to the right side

            number_items--; // one less item
            return temp;
        }

        int peekFront() { return queueArray[front];      }
        int peekRear()  { return queueArray[rear];       }
        bool isEmpty()  { return (number_items == 0);    }
        bool isFull()	 { return (number_items == size); }
        int qsize()	 { return number_items; 		  }

        void showQueue()
        {
            cout << "Queue = {";
            for (int i = 0; i < number_items; i++)
            {
                if (i < number_items-1)
                    cout << queueArray[i] << ", ";

                if (i == number_items - 1)
                    cout << queueArray[i];
            }
            cout << "}";
        }


    /* NOTE TO SELF
    ideally, we would want to check if the array is full or not
    - add an if statement to the insert function/method

    if(number_items == size - 1)
        return; // get out of insert function
    */
};

int main()
{
    Queue q(10); // size of queue is 10 elements

    cout << "Inserting 5 items (10, 20, 30, 40, 50) from the left:" << endl;
    q.insertLeft(10); // {10}
    q.insertLeft(20); // {10, 20}
    q.insertLeft(30); // {10, 20, 30}
    q.insertLeft(40); // {10, 20, 30, 40}
    q.insertLeft(50); // {10, 20, 30, 40, 50}
    q.showQueue(); // queue = {10, 20, 30, 40, 50}
    cout << endl;

    cout << "Inserting 5 items (100, 90, 80, 70, 60) from the right: " << endl;
    q.insertRight(100); // {10, 20, 30, 40, 50, xx, xx, xx, xx, 100}
    q.insertRight(90);  // {10, 20, 30, 40, 50, xx, xx, xx, 90, 100}
    q.insertRight(80);  // {10, 20, 30, 40, 50, xx, xx, 80, 90, 100}
    q.insertRight(70);  // {10, 20, 30, 40, 50, xx, 70, 80, 90, 100}
    q.insertRight(60);  // {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}
    q.showQueue(); // queue = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}
    cout << endl;

    // note: if array is not full and you have items inserted from the right,
    //  the showQueue function will show garbage numbers

    // rear is currently at index 4 (50)
    cout << "Removing from Right (removing current rear)" << endl;
    cout << "New Rear: ";
    q.removeRight();
    cout << q.peekRear() << endl;
    // want to remove rear as 50 and then have the new rear be 40



    // front is currently at index 5 (60)
    cout << "Removing current front (removing current front)" << endl;
    cout << "New Front: ";
    q.removeLeft();
    cout << q.peekFront();
    // want to remove front of 60 and have new front be 70
    



}

/* === OUTPUT ===
 
Inserting 5 items (10, 20, 30, 40, 50) from the left:
Queue = {10, 20, 30, 40, 50}
Inserting 5 items (100, 90, 80, 70, 60) from the right: 
Queue = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}
Removing from Right (removing current rear)
New Rear: 40
Removing current front (removing current front)
New Front: 70
Process finished with exit code 0


 */