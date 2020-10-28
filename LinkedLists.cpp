// Name: David Nguyen
// File: p7.cpp
// Date: 03/09/20 - 05/22/20
// Description: Type up the Link Lis program and add the following 3 methods
//  1) int sumData() – returns the sum of iData of all links
//  2) int min() – returns the smallest iData of all links
//  3) int numLinks() – returns the total number of links in the list 


#include <iostream>
using namespace std;

class Link
{
    public:
        int iData;      // data
        double dData;   // data
        Link *pNext;    // pointer to next link

        Link (int id, double dd) // constructor
        {
            iData = id;
            dData = dd;
            pNext = NULL;  // refer to nothing
            // until connected to other Link

        }

        void displayLink()
        {
            cout << "{" << iData << ", ";
            cout << dData << "} ";
        }
};

class LinkList
{
    private:
        Link *pFirst; // pointer(ptr) to first link on list

    public:
        LinkList()
        {
            pFirst = NULL; // no links on list yet
        }

        bool isEmpty()
        {
            return pFirst == NULL; // true if list is empty
        }

        // other methods go here
        void insertFirst (int id, double dd)
        {
            Link *pNewLink = new Link (id, dd); // make new link
            pNewLink->pNext = pFirst; // newLink --> old first (1)
            pFirst = pNewLink; // first --> newLink

        }

        Link *getFirst ()  { return pFirst; }

        void removeFirst()         // delete the first link
        {                           // assumes list is not empty
            Link *pTemp = pFirst;   // save first
            pFirst = pFirst->pNext; // unlink it: first --> old next
            delete pTemp;           // delete old first
        }

        void displayList()
        {
            cout << "List (first-->last): ";
            Link *pCurrent = pFirst;            // start at the beginning of the list
            while (pCurrent != NULL)            // until the end of the list
            {
                pCurrent->displayLink();        // show the link
                pCurrent = pCurrent->pNext;     // move to the next link
            }
            cout << endl;

        }

        Link *find(int key)                     // find link given key
        {                                       // assume non empty list
            Link *pCurrent = pFirst;            // start at 'first'
            while (pCurrent->iData != key)      // while no match
            {
                if (pCurrent->pNext == NULL)    // if end of list
                    return NULL;                // didn't find
                else
                    pCurrent = pCurrent->pNext;
            }
            return pCurrent;
        }

        bool remove(int key)                    // remove link given key
        {                                       // assumes non empty list
            Link *pCurrent = pFirst;
            Link *pPrevious = pFirst;
            while (pCurrent->iData != key)      // search for link
            {
                if (pCurrent->pNext == NULL)
                    return false;               // didn't find it
                else
                {
                    pPrevious = pCurrent;       // go to the next link
                    pCurrent = pCurrent->pNext;
                }
            }

            // key was found
            if(pCurrent == pFirst)                  // if first link
                pFirst = pFirst->pNext;             // - change first
            else                                    // otherwise
                pPrevious->pNext = pCurrent->pNext; // - bypass current link

            delete pCurrent;

            return true;

        }

        // to return the sum of iData of all links
        int sumIdata()
        {
            int sum = 0;
            Link *pCurrent = pFirst;
            while (!(pCurrent == NULL)) // goes through list
            {
                sum += pCurrent->iData;
                pCurrent = pCurrent->pNext;
            }

            return sum; // returns sum
        }

        // to return the smallest iData
        int min()
        {
            Link *pCurrent = pFirst;
            int min = pFirst->iData;
            while ( !(pCurrent==NULL) )
            {
                if (pCurrent->iData < min)
                    min = pCurrent -> iData;
                pCurrent = pCurrent->pNext;
            }
            return min;
        }

        // to return the total number of links
        int numLinks()
        {
            Link *pCurrent = pFirst;
            int a = 0;
            while ( !(pCurrent == NULL) )
            {
                a++;
                pCurrent = pCurrent->pNext;
            }

            return a;

        }

};

int main()
{
    LinkList theList;   // make new list
    theList.insertFirst(22, 2.99);  // insert 4 items
    theList.insertFirst(44, 4.99);
    theList.insertFirst(66, 6.99);
    theList.insertFirst(88, 8.99);

    theList.displayList();  // show the list
    // List (first--> last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}

    while ( !theList.isEmpty() )
    {
        Link *pTemp = theList.getFirst();   // get first link
        cout << "\nRemoving link with data ";
        pTemp->displayLink();   // display links data
        theList.removeFirst(); // remove it
    }

    cout << endl << "Empty list: ";
    theList.displayList(); // List (first-->last):

    theList.insertFirst(22, 2.99);  // reinsert 4 items
    theList.insertFirst(44, 4.99);
    theList.insertFirst(66, 6.99);
    theList.insertFirst(88, 8.99);
    cout << "\nReinserting the links back" << endl;
    theList.displayList();

    int findKey = 44;
    Link *pFind = theList.find(findKey);
    if (pFind != NULL)
        cout << "Found link with key: " << pFind->iData << endl;
    else
        cout << "Can't find link with key " << findKey << endl;

    if (theList.remove(findKey))
        cout << "Deleted " << findKey << " from the list. \n";
    else
        cout << "Did not delete " << findKey << "from the list. \n";

    cout << "Link list after deletion \n";
    theList.displayList();


    cout << "\nThe sum of all links is: " << theList.sumIdata() << endl;
    cout << "The smallest link is: " << theList.min() << endl;
    cout << "The number of links is: " << theList.numLinks() << endl;

    return 0;
}


/* === OUTPUT ===

 Final Test Run:
/Users/davidnguyen/CLionProjects/untitled4/cmake-build-debug/untitled4
List (first-->last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}

Removing link with data {88, 8.99}
Removing link with data {66, 6.99}
Removing link with data {44, 4.99}
Removing link with data {22, 2.99}
Empty list: List (first-->last):

Reinserting the links back
List (first-->last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}
Found link with key: 44
Deleted 44 from the list.
Link list after deletion
List (first-->last): {88, 8.99} {66, 6.99} {22, 2.99}

The sum of all links is: 176
The smallest link is: 22
The number of links is: 3

Process finished with exit code 0

 Test Run Part 2:
/Users/davidnguyen/CLionProjects/untitled4/cmake-build-debug/untitled4
List (first-->last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}

Removing link with data {88, 8.99}
Removing link with data {66, 6.99}
Removing link with data {44, 4.99}
Removing link with data {22, 2.99}
Empty list: List (first-->last):

Reinserting the links back
List (first-->last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}
Found link with key: 44
Deleted 44 from the list.
Link list after deletion
List (first-->last): {88, 8.99} {66, 6.99} {22, 2.99}

Process finished with exit code 0



 */










