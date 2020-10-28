// Name: David Nguyen
// File: p9DoubleLinkedEndedPriorityQueue.cpp
// Date: 03/23/20 - 05/22/20
// Description: Implement (using a List) the methods shown below for a “Double-Ended, Double-Linked, Priority-Queue” .
//  1) We can remove the first , last or, any link
//  2) Each Link has a pNext and pPrevious
//  3) Links are always Inserted in Order
//  4) Show the list forward (front to end)
//  5) Show the list backward (end to front).
//  6) Link with a given value can be removed.

#include <iostream>
#include <iomanip>
using namespace std;

class Link
{
public:
    int data;
    Link *pNext, *pPrev;
    Link (int newData)
    {
        data = newData;
        pNext = NULL;
        pPrev = NULL;
    }

    void display()
    {
        // show memory address of previous and next pointers
        // as well as the link itself
        cout << "{"  << setw(3) << data << "\t:\t" << setw(14)
             << pPrev << "\t:\t\t" << &data << "\t:\t" << setw(14)
             << pNext << "}\n";
    }

};


class DoubleEndedList
{
private:
    Link *pFirst, *pLast; // ptr to first link on list
public:
    DoubleEndedList()   { pFirst = NULL; pLast = NULL; }    // no links on this list yet
    void displayFirst() { cout << "First:"; pFirst->display(); }
    void displayLast()  { cout << "Last:";  pLast-> display(); }

    // display list front --> end
    void displayList()
    {
        Link *current = pFirst;
        cout << "Start of List: " << endl;
        while(current != NULL)
        {
            current->display();
            current = current->pNext;
        }
        cout << "End of List";
    }

    // display list end --> front
    void displayBackward()
    {
        Link *current = pLast;
        cout << "End of List:";
        while (current != NULL)
        {
            current->display();
            current = current->pPrev;
        }
        cout << "Start of List";

    }

    // inserts in order(ascending)
    void insert(int newValue)
    {
        // make a new link
        Link *newLink = new Link(newValue);

        // case: no links
        if(pFirst == NULL)
        {
            newLink->display();
            cout << endl;
            newLink->pNext = NULL;  // no next
            newLink->pPrev = NULL;  // no previous
            pFirst = newLink;
            pLast = newLink;
            return;
        }

        // case: newValue < pFirst, becomes first link
        if (newValue < pFirst->data)
        {
            pFirst->pPrev= newLink;
            newLink->pPrev = NULL;
            newLink->pNext = pFirst;
            pFirst = newLink;
            return;
        }

        // case: newLink > pLast, becomes last link
        if(newValue > pLast->data)
        {
            pLast->pNext = newLink;
            newLink->pPrev = pLast;
            newLink->pNext = NULL;
            pLast = newLink;
            return;
        }

        // case: pFirst < newValue < pLast, goes in the middle
        Link *value = pFirst;
        while (value != pLast)
        {
            if (newValue < value->data)
                break;
            value = value->pNext;
        }
        newLink->pNext = value;
        newLink->pPrev = value->pPrev;
        value->pPrev->pNext = newLink;
        value->pPrev = newLink;

    }

    // removes first link
    void removeFirst()
    {
        Link *toDelete = pFirst;
        pFirst = pFirst->pNext;
        pFirst->pPrev =NULL;
        delete toDelete;
    }


    // removes last link
    void removeLast()
    {
        Link *toDelete = pLast;
        pLast = pLast->pPrev;
        pLast->pNext = NULL;
        delete toDelete;
    }

    // removes link with given value
    void removeValue(int value)
    {
        // case: removing first value
        if (pFirst->data == value)
        {
            removeFirst();
            return;
        }

        // case: removing last value
        if (pLast->data == value)
        {
            removeLast();
            return;
        }

        // case: removing value in between first and last
        Link *toDelete = pFirst;
        while (toDelete != NULL)
        {
            if (toDelete->data == value)
            {
                toDelete->display();
                toDelete->pNext->pPrev = toDelete->pPrev;
                toDelete->pPrev->pNext = toDelete->pNext;
                delete toDelete;
                return;
            }
            toDelete = toDelete->pNext;
        }

        // case: link not found
        cout << "Link with value " << value << " was not found." << endl;


    }
};





int main()
{
    DoubleEndedList *list = new DoubleEndedList();
    // starting the list
    cout << "Inserting the first link of value 5:" << endl;
    list->insert(5);

    // inserting values 0, 7, 4
    // entering a value < pFirst
    cout << "Inserting a link with value 0:" << endl;
    list->insert(0);
    list->displayList();
    //entering a value > pLast
    cout << "\n\nInserting a link with value 7:" << endl;
    list->insert(7);
    list->displayList();
    // entering a value in b/t pFirst and pLast
    cout << "\n\nInserting a link with value 4:" << endl;
    list->insert(4);
    list->displayList();

    // inserting values to make list go from 0 to 9
    cout << "\n\n Inserting links so list will range from 0 to 9:";
    list->insert(1);
    list->insert(2);
    list->insert(3);
    list->insert(6);
    list->insert(8);
    list->insert(9);
    list->displayList();

    // testing displayFirst() and displayLast()
    cout << "\n\nDisplaying the First link of the list:" << endl;
    list->displayFirst();
    cout << "Displaying the Last link of the list: " << endl;
    list->displayLast();

    // testing displayBackward()
    cout << "\nDisplaying the list regularly: " << endl;
    list->displayList();
    cout << "\n\nDisplaying the list in reverse:" << endl;
    list->displayBackward();

    // setup to show how we can remove first, last, or any link
    cout << "\n\nDisplaying the list:" << endl;
    list->displayList();
    cout << "\nDisplaying the current first link:" << endl;
    list->displayFirst();
    cout << "Displaying the current last link:" << endl;
    list->displayLast();
    // removing first link
    cout << "\nRemoving the first link (0): " << endl;
    list->removeFirst();
    cout << "List with link 0 removed: " << endl;
    list->displayList();
    cout << "\nDisplaying the current first link:" << endl;
    list->displayFirst();
    // removing last link
    cout << "\nRemoving the last link (9): " << endl;
    list->removeLast();
    cout << "List with link 9 removed: " << endl;
    list->displayList();
    cout << "Displaying the current last link:" << endl;
    list->displayLast();
    // removing link with any value (in list)
    cout << "\nRemoving link 6:" << endl;
    list->removeValue(6);
    list->displayList();
    // removing link not in list
    cout << "\nRemoving link 10:" << endl;
    list->removeValue(10);
    list->displayList();

    return 0;
}

/* === OUTPUT ===
/Users/davidnguyen/CLionProjects/generalPrograms/cmake-build-debug/generalPrograms
Inserting the first link of value 5:
{  5	:	           0x0	:		0x7fb4684029e0	:	           0x0}

Inserting a link with value 0:
Start of List: 
{  0	:	           0x0	:		0x7fb468402a00	:	0x7fb4684029e0}
{  5	:	0x7fb468402a00	:		0x7fb4684029e0	:	           0x0}
End of List

Inserting a link with value 7:
Start of List: 
{  0	:	           0x0	:		0x7fb468402a00	:	0x7fb4684029e0}
{  5	:	0x7fb468402a00	:		0x7fb4684029e0	:	0x7fb468402a20}
{  7	:	0x7fb4684029e0	:		0x7fb468402a20	:	           0x0}
End of List

Inserting a link with value 4:
Start of List: 
{  0	:	           0x0	:		0x7fb468402a00	:	0x7fb468402a40}
{  4	:	0x7fb468402a00	:		0x7fb468402a40	:	0x7fb4684029e0}
{  5	:	0x7fb468402a40	:		0x7fb4684029e0	:	0x7fb468402a20}
{  7	:	0x7fb4684029e0	:		0x7fb468402a20	:	           0x0}
End of List

 Inserting links so list will range from 0 to 9:Start of List: 
{  0	:	           0x0	:		0x7fb468402a00	:	0x7fb468402a60}
{  1	:	0x7fb468402a00	:		0x7fb468402a60	:	0x7fb468402a80}
{  2	:	0x7fb468402a60	:		0x7fb468402a80	:	0x7fb468402aa0}
{  3	:	0x7fb468402a80	:		0x7fb468402aa0	:	0x7fb468402a40}
{  4	:	0x7fb468402aa0	:		0x7fb468402a40	:	0x7fb4684029e0}
{  5	:	0x7fb468402a40	:		0x7fb4684029e0	:	0x7fb468402ac0}
{  6	:	0x7fb4684029e0	:		0x7fb468402ac0	:	0x7fb468402a20}
{  7	:	0x7fb468402ac0	:		0x7fb468402a20	:	0x7fb468402ae0}
{  8	:	0x7fb468402a20	:		0x7fb468402ae0	:	0x7fb468402b00}
{  9	:	0x7fb468402ae0	:		0x7fb468402b00	:	           0x0}
End of List

Displaying the First link of the list:
First:{  0	:	           0x0	:		0x7fb468402a00	:	0x7fb468402a60}
Displaying the Last link of the list: 
Last:{  9	:	0x7fb468402ae0	:		0x7fb468402b00	:	           0x0}

Displaying the list regularly: 
Start of List: 
{  0	:	           0x0	:		0x7fb468402a00	:	0x7fb468402a60}
{  1	:	0x7fb468402a00	:		0x7fb468402a60	:	0x7fb468402a80}
{  2	:	0x7fb468402a60	:		0x7fb468402a80	:	0x7fb468402aa0}
{  3	:	0x7fb468402a80	:		0x7fb468402aa0	:	0x7fb468402a40}
{  4	:	0x7fb468402aa0	:		0x7fb468402a40	:	0x7fb4684029e0}
{  5	:	0x7fb468402a40	:		0x7fb4684029e0	:	0x7fb468402ac0}
{  6	:	0x7fb4684029e0	:		0x7fb468402ac0	:	0x7fb468402a20}
{  7	:	0x7fb468402ac0	:		0x7fb468402a20	:	0x7fb468402ae0}
{  8	:	0x7fb468402a20	:		0x7fb468402ae0	:	0x7fb468402b00}
{  9	:	0x7fb468402ae0	:		0x7fb468402b00	:	           0x0}
End of List

Displaying the list in reverse:
End of List:{  9	:	0x7fb468402ae0	:		0x7fb468402b00	:	           0x0}
{  8	:	0x7fb468402a20	:		0x7fb468402ae0	:	0x7fb468402b00}
{  7	:	0x7fb468402ac0	:		0x7fb468402a20	:	0x7fb468402ae0}
{  6	:	0x7fb4684029e0	:		0x7fb468402ac0	:	0x7fb468402a20}
{  5	:	0x7fb468402a40	:		0x7fb4684029e0	:	0x7fb468402ac0}
{  4	:	0x7fb468402aa0	:		0x7fb468402a40	:	0x7fb4684029e0}
{  3	:	0x7fb468402a80	:		0x7fb468402aa0	:	0x7fb468402a40}
{  2	:	0x7fb468402a60	:		0x7fb468402a80	:	0x7fb468402aa0}
{  1	:	0x7fb468402a00	:		0x7fb468402a60	:	0x7fb468402a80}
{  0	:	           0x0	:		0x7fb468402a00	:	0x7fb468402a60}
Start of List

Displaying the list:
Start of List: 
{  0	:	           0x0	:		0x7fb468402a00	:	0x7fb468402a60}
{  1	:	0x7fb468402a00	:		0x7fb468402a60	:	0x7fb468402a80}
{  2	:	0x7fb468402a60	:		0x7fb468402a80	:	0x7fb468402aa0}
{  3	:	0x7fb468402a80	:		0x7fb468402aa0	:	0x7fb468402a40}
{  4	:	0x7fb468402aa0	:		0x7fb468402a40	:	0x7fb4684029e0}
{  5	:	0x7fb468402a40	:		0x7fb4684029e0	:	0x7fb468402ac0}
{  6	:	0x7fb4684029e0	:		0x7fb468402ac0	:	0x7fb468402a20}
{  7	:	0x7fb468402ac0	:		0x7fb468402a20	:	0x7fb468402ae0}
{  8	:	0x7fb468402a20	:		0x7fb468402ae0	:	0x7fb468402b00}
{  9	:	0x7fb468402ae0	:		0x7fb468402b00	:	           0x0}
End of List
Displaying the current first link:
First:{  0	:	           0x0	:		0x7fb468402a00	:	0x7fb468402a60}
Displaying the current last link:
Last:{  9	:	0x7fb468402ae0	:		0x7fb468402b00	:	           0x0}

Removing the first link (0): 
List with link 0 removed: 
Start of List: 
{  1	:	           0x0	:		0x7fb468402a60	:	0x7fb468402a80}
{  2	:	0x7fb468402a60	:		0x7fb468402a80	:	0x7fb468402aa0}
{  3	:	0x7fb468402a80	:		0x7fb468402aa0	:	0x7fb468402a40}
{  4	:	0x7fb468402aa0	:		0x7fb468402a40	:	0x7fb4684029e0}
{  5	:	0x7fb468402a40	:		0x7fb4684029e0	:	0x7fb468402ac0}
{  6	:	0x7fb4684029e0	:		0x7fb468402ac0	:	0x7fb468402a20}
{  7	:	0x7fb468402ac0	:		0x7fb468402a20	:	0x7fb468402ae0}
{  8	:	0x7fb468402a20	:		0x7fb468402ae0	:	0x7fb468402b00}
{  9	:	0x7fb468402ae0	:		0x7fb468402b00	:	           0x0}
End of List
Displaying the current first link:
First:{  1	:	           0x0	:		0x7fb468402a60	:	0x7fb468402a80}

Removing the last link (9): 
List with link 9 removed: 
Start of List: 
{  1	:	           0x0	:		0x7fb468402a60	:	0x7fb468402a80}
{  2	:	0x7fb468402a60	:		0x7fb468402a80	:	0x7fb468402aa0}
{  3	:	0x7fb468402a80	:		0x7fb468402aa0	:	0x7fb468402a40}
{  4	:	0x7fb468402aa0	:		0x7fb468402a40	:	0x7fb4684029e0}
{  5	:	0x7fb468402a40	:		0x7fb4684029e0	:	0x7fb468402ac0}
{  6	:	0x7fb4684029e0	:		0x7fb468402ac0	:	0x7fb468402a20}
{  7	:	0x7fb468402ac0	:		0x7fb468402a20	:	0x7fb468402ae0}
{  8	:	0x7fb468402a20	:		0x7fb468402ae0	:	           0x0}
End of ListDisplaying the current last link:
Last:{  8	:	0x7fb468402a20	:		0x7fb468402ae0	:	           0x0}

Removing link 6:
{  6	:	0x7fb4684029e0	:		0x7fb468402ac0	:	0x7fb468402a20}
Start of List: 
{  1	:	           0x0	:		0x7fb468402a60	:	0x7fb468402a80}
{  2	:	0x7fb468402a60	:		0x7fb468402a80	:	0x7fb468402aa0}
{  3	:	0x7fb468402a80	:		0x7fb468402aa0	:	0x7fb468402a40}
{  4	:	0x7fb468402aa0	:		0x7fb468402a40	:	0x7fb4684029e0}
{  5	:	0x7fb468402a40	:		0x7fb4684029e0	:	0x7fb468402a20}
{  7	:	0x7fb4684029e0	:		0x7fb468402a20	:	0x7fb468402ae0}
{  8	:	0x7fb468402a20	:		0x7fb468402ae0	:	           0x0}
End of List
Removing link 10:
Link with value 10 was not found.
Start of List: 
{  1	:	           0x0	:		0x7fb468402a60	:	0x7fb468402a80}
{  2	:	0x7fb468402a60	:		0x7fb468402a80	:	0x7fb468402aa0}
{  3	:	0x7fb468402a80	:		0x7fb468402aa0	:	0x7fb468402a40}
{  4	:	0x7fb468402aa0	:		0x7fb468402a40	:	0x7fb4684029e0}
{  5	:	0x7fb468402a40	:		0x7fb4684029e0	:	0x7fb468402a20}
{  7	:	0x7fb4684029e0	:		0x7fb468402a20	:	0x7fb468402ae0}
{  8	:	0x7fb468402a20	:		0x7fb468402ae0	:	           0x0}
End of List
Process finished with exit code 0


*/
