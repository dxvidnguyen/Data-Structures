// Name: David Nguyen
// File: p8aCircularList.cpp
// Date: 03/16/20 - 05/22/20
// Description: Use the LinkList class as a starting point to make a class
//	CircList. The only access to the list is a single reference, current, that
//  can point to any link on the list.
//  The reference can move around the list as needed
//  The CircList class should have the following methods:
//  1) bool search(int valueToFind)
//  --> Return true if any Link has iData == valueToFind
//  2) void insertInitialLink(int newValue)
//  --> Inserts a new Link that has iData = newValue
//  3) void insertAfterValueFound(int newValue, int valueToFind)
//  --> Inserts a new Link that has iData = newValue
//  --> Inserts After the first Link which has valueToFind
//  --> Does not insert if valueToFind is not found
//  4) bool deleteLink(int valueToFind)
//  --> Deletes the first Link which has iData == valueToFind
//  --> Returns true upon successful deletion, false otherwise
//  5) void displayList( )
//  --> Displays the list
//  --> You’ll need to break the circle at some arbitrary point to print it on
// 	   the screen.

#include <iostream>
using namespace std;

class Link
{
    public:
        int data;
        Link *next;
        Link (int newData)  { data = newData; next = NULL; }
        void show()         { cout << "{" << data << "}" ; }
};

class CircList
{
     private:
        Link *current;
        int numLinks;

    public:
        CircList()
        {
            current = NULL;
            numLinks = 0;
        }

        bool empty()
        {
            return (numLinks == 0);
        }

        bool search(int valueToFind)
        {
            if (!empty())
                for (int i = 0; i < numLinks; i++)
                {
                    if (current->data == valueToFind)
                        return true;
                     current = current->next;
                }

            return false;
        }


        void insertInitialLink(int newValue)
        {
            Link *newLink = new Link (newValue);
            current = newLink;
            current->next = newLink;
            numLinks++;
        }

        void insertAfterValue(int newValue, int value)
        {
            if ( search(value) ) // search stops at current at link with value
            {
                Link *newLink = new Link(newValue);
                newLink->next = current->next;
                current->next = newLink;
                numLinks++;
            }

            else
                cout << value << " was not found. Nothing inserted." << endl;
        }

        bool deleteLink (int valueToFind)
        {
            if ( !empty() )
                for (int i = 0; i < numLinks; i++)
                {
                    if (current->next->data == valueToFind)
                    {
                        Link *toDelete = current->next;
                        current->next = toDelete->next;
                        delete toDelete;
                        numLinks--;
                        return true;
                    }
                    current = current->next;
                }

            return false;
        }

        void displayList()
        {
            cout << "The list:";
            if ( !empty() )
                for (int i = 0; i < numLinks; i++)
                {
                    current->show();
                    current = current->next;
                }
            else
                cout << " is empty" << endl;
        }

};

int main()
{
    cout << boolalpha; // prints out true and false instead of 1 and 0

    CircList circ;

    cout << "Created a new circular list" << endl;
    cout << "Test to see if the list is empty: " << endl;
    cout << "The is list empty? " << circ.empty() << endl;

    cout << "Testing displayList() below: " << endl;
    circ.displayList(); // The list: is empty

    cout << "Testing search() method" << endl;
    cout << "Note that the list is empty so value is should be false" << endl;
    cout << "Testing search(10) " << circ.search(10) << endl;

    cout << "Inserting the first link (10): " << endl;
    circ.insertInitialLink(10);
    cout << "displayList(): " ;
    circ.displayList();
    cout << endl << "Testing search(10) " << circ.search(10) << endl;

    cout << "Inserting 40 after 10" << endl;
    circ.insertAfterValue(40,10);
    cout << "Displaying the list "  << endl;
    circ.displayList();

    cout << endl << "Inserting 20 after 10" << endl;
    circ.insertAfterValue(20,10);
    cout << "Displaying the list "  << endl;
    circ.displayList();

    cout << endl <<  "Inserting 30 after 20" << endl;
    circ.insertAfterValue(30,20);
    cout << "Displaying the list "  << endl;
    circ.displayList();

    cout << endl << "Inserting 15 after 50, note link 50 does not exist " << endl;
    circ.insertAfterValue(15,50);
    cout << "Displaying the list "  << endl;
    circ.displayList();

    cout << endl << "Trying to delete link 30" << endl;
    circ.deleteLink(30);
    cout << "Displaying the list "  << endl;
    circ.displayList();

    cout << endl << "Trying to delete link 50, note link 50 does not exist" << endl;
    cout << circ.deleteLink(50) << endl;
    cout << "Displaying the list "  << endl;
    circ.displayList();

    cout << endl << "Trying to delete link 20" << endl;
    circ.deleteLink(20);
    cout << "Displaying the list "  << endl;
    circ.displayList();

    cout << endl << "Trying to delete link 10" << endl;
    circ.deleteLink(10);
    cout << "Displaying the list "  << endl;
    circ.displayList();
    
    cout << endl << "Trying to delete link 40" << endl;
    circ.deleteLink(40);
    cout << "Displaying the list "  << endl;
    circ.displayList();
    

    return 0;
}




/* === OUTPUT ===

/Users/davidnguyen/CLionProjects/untitled4/cmake-build-debug/untitled4
Created a new circular list
Test to see if the list is empty: 
The is list empty? true
Testing displayList() below: 
The list: is empty
Testing search() method
Note that the list is empty so value is should be false
Testing search(10) false
Inserting the first link (10): 
displayList(): The list:{10}
Testing search(10) true
Inserting 40 after 10
Displaying the list 
The list:{10}{40}
Inserting 20 after 10
Displaying the list 
The list:{10}{20}{40}
Inserting 30 after 20
Displaying the list 
The list:{20}{30}{40}{10}
Inserting 15 after 50, note link 50 does not exist 
50 was not found. Nothing inserted.
Displaying the list 
The list:{20}{30}{40}{10}
Trying to delete link 30
Displaying the list 
The list:{20}{40}{10}
Trying to delete link 50, note link 50 does not exist
false
Displaying the list 
The list:{20}{40}{10}
Trying to delete link 20
Displaying the list 
The list:{10}{40}
Trying to delete link 10
Displaying the list 
The list:{40}
Trying to delete link 40
Displaying the list 
The list: is empty

Process finished with exit code 0




 */






