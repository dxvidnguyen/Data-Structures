// Name: David Nguyen
// File: p12HashTables.cpp
// Date: 04/20/20 - 05/22/20
// Description: Type up and get the hash table to work
//  Demonstrates hash table with linear probing

#include <iostream>
#include <iomanip>
#include <vector>


#include <stack>
#include <cstdlib>          // for random numbers
#include <ctime>            // for random numbers

using namespace std;

class DataItem
{
public:
    int data;           // data item (key)

    DataItem (int newData) // constructor
    {
        data = newData;
    }
};  // end of class DataItem

class HashTable
{
private:
    vector <DataItem*> hashArray;   // vector holds hash table
    int arraySize;
    DataItem* pNonItem;         // for deleted items

public:
    HashTable(int size) // constructor
    {
        arraySize = size;
        hashArray.resize(arraySize);    // size the vector
        for (int i = 0; i < arraySize; i++)
            hashArray[i] = NULL;
        pNonItem = new DataItem(-1);    // deleted item key is -1
    }

    void displayTable()
    {
        cout << "Table: ";
        for (int i = 0; i < arraySize; i++)
        {
            if (hashArray[i] != NULL)
                cout << hashArray[i]->data << " ";
            else
                cout << "** ";
        }
        cout << endl;
    }
    int hashFunc (int key)
    {
        return key % arraySize; // hash function
    }

    void insert (DataItem* pItem)   // insert a DataItem
    {   // assumes table not full
        int key = pItem->data; // extract key
        int hashVal = hashFunc(key); // hash the key until empty cell or -1

        while (hashArray[hashVal] != NULL && hashArray[hashVal]->data != -1)
        {
            ++hashVal; // go to next cell
            hashVal %= arraySize; // wraparound if necessary
        }

        hashArray[hashVal] = pItem; // insert item
    }   // end insert()

    DataItem* remove(int key) // remove a DataItem
    {
        int hashVal = hashFunc(key);                // hash the key until
        while (hashArray[hashVal] != NULL)          // empty cell
        {
            if (hashArray[hashVal]->data == key)        // found the key?
            {
                DataItem* pTemp = hashArray[hashVal]; // save item
                hashArray[hashVal] = pNonItem;        // delete item
                return pTemp;
            }
            ++hashVal;              // go to next cell
            hashVal %= arraySize;   // wraparound if necessary
        }
        return NULL;
    }   // end remove()

    DataItem* find(int key)     // find item with key
    {
        int hashVal = hashFunc(key);        // hash the key
        while (hashArray[hashVal] != NULL)  // until empty cell
        {
            if (hashArray[hashVal]->data == key)    // found the key?
                return hashArray[hashVal];          // yes, return item
            ++hashVal;  // go to next cell
            hashVal %= arraySize;           // wraparound if necessary
        }

        return NULL;            // can't find item
    } // end of find()

};  // end of class Hashtable


int main()
{
    DataItem* pDataItem;
    int aKey, size, n, keysPerCell;
    time_t aTime;
    char choice = 'b';

    // get sizes;
    cout << "Enter size of hash table: ";
    cin >> size;
    cout << "Enter initial number of items: ";
    cin >> n;
    keysPerCell = 10;

    HashTable theHashTable(size); // make table
    srand( static_cast<unsigned>(time(&aTime)) ); // make a random list of numbers
    for (int i = 0; i < n; i++)
    {
        aKey = rand() %  (keysPerCell*size); // r
        pDataItem = new DataItem(aKey);
        theHashTable.insert(pDataItem);
    }
    while (choice != 'x') // interact with user
    {
        cout << "Enter first letter of show, insert, delete, find, or x to end: ";
        char choice;
        cin >> choice;
        switch(choice)
        {
            case 's':
                theHashTable.displayTable();
                break;
            case 'i':
                cout << "Enter key value to insert: ";
                cin >> aKey;
                pDataItem = new DataItem(aKey);
                theHashTable.insert(pDataItem);
                break;
            case'd':
                cout << "Enter key value to delete: ";
                cin >> aKey;
                theHashTable.remove(aKey);
                break;
            case 'f':
                cout << "Enter key value to find: ";
                cin >> aKey;
                pDataItem = theHashTable.find(aKey);
                if (pDataItem != NULL)
                    cout << "Found " << aKey << endl;
                else
                    cout << "Could not find " << aKey << endl;
                break;
            case 'x':
                return 0; 

                default:
                    cout << "Invalid entry \n";


        }   // end switch
    } // end while



    
} // end main()






/* === OUTPUT ===

/Users/davidnguyen/CLionProjects/generalPrograms/cmake-build-debug/generalPrograms
Enter size of hash table: 12
Enter initial number of items: 8
Enter first letter of show, insert, delete, find, or x to end: s
Table: 48 ** ** 99 75 89 29 115 32 68 ** ** 
Enter first letter of show, insert, delete, find, or x to end: f
Enter key value to find: 66
Could not find 66
Enter first letter of show, insert, delete, find, or x to end: f
Enter key value to find: 48
Found 48
Enter first letter of show, insert, delete, find, or x to end: f
Enter key value to find: 99
Found 99
Enter first letter of show, insert, delete, find, or x to end: d
Enter key value to delete: 99
Enter first letter of show, insert, delete, find, or x to end: s
Table: 48 ** ** -1 75 89 29 115 32 68 ** ** 
Enter first letter of show, insert, delete, find, or x to end: i
Enter key value to insert: 1
Enter first letter of show, insert, delete, find, or x to end: s
Table: 48 1 ** -1 75 89 29 115 32 68 ** ** 
Enter first letter of show, insert, delete, find, or x to end: x

Process finished with exit code 0 

*/