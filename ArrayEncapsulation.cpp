// Name: David Nguyen
// File: p3.cpp
// Date: 02/10/20 - 02/23/20
// Description: Array Encapsulation
//  Type up the program below and get it working.
//  Then add the following functions/methods/actions:
//  void insertFirst(int number_to_add)  - assumes array is big enough, inserts element at index 0, and then shifts all others to the right.
//  void deleteNumber(int number_to_delete) - If a number is found, delete that element and shifts all others to the left (deletes 1 number max).
//  void sort() - sorts the array using bubble sort that we learned in CSIS45
//  Call each function from the main, and test your program.

#include <iostream>
using namespace std;

// Encapsulated array means an array is inside a class
class EncapsulatedArray
{
private:
    int *array; // dynamically allocated array
    int number_of_elements;
public:
    EncapsulatedArray(int size); // explicit constructor
    void add(int number_to_add);
    void show();

    void insertFirst(int number_to_add);
    void deleteNumber(int number_to_delete);
    void sort();

    void append(int number_to_add);
};
// remember to put a semicolon after the class


EncapsulatedArray::EncapsulatedArray(int size)
{
    array = new int[size]; // dynamically allocated array
    number_of_elements = 0;
}

void EncapsulatedArray::add(int number_to_add)
{
    array[number_of_elements] = number_to_add;
    number_of_elements++;
}

// show arrays as {9, 101, 9}
void EncapsulatedArray::show()
{
    if (number_of_elements == 1)
    {
        cout << "array = {" << array[0] << "}\n";
        return;
    }


    int i = 0;
    cout << "array = {";
    for (i = 0; i < number_of_elements - 1; i++)
        cout << array[i] << " , " ;
    cout << array[i] << "}\n";

}

void EncapsulatedArray::insertFirst(int number_to_add)
{
    // shift all the elements one index to the right
    for (int a = number_of_elements; a >= 0; a--)
    {
        array[a] = array[a - 1];
        if (a == 0)
            array[0] = number_to_add;
    }

    number_of_elements++; // resize the array
}


void EncapsulatedArray::deleteNumber(int number_to_delete)
{
    // for loop to go through the elements
    for (int b = 0; b < number_of_elements; b++)

        if (array[b] == number_to_delete) // if statement to check for the array is equal to number_to_delete
        {
            for (int c = b; c < number_of_elements; c++) // for loop to move all elements into new spaces
                array[c] = array[c+1];

            number_of_elements--; // delete the space the deleted number took
        }

}


void EncapsulatedArray::sort()
{
    int temp = 88;

    for (int j = 0; j < number_of_elements - 1; j++)
    {
        for (int i = 0; i < number_of_elements-1; i++)
        {
            if (array[i] > array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1]  = temp;
            }
        }
    }

}

void EncapsulatedArray::append(int number_to_add)
{
   cout << size << endl;
   cout << number_of_elements << endl;

}


int main()
{
    EncapsulatedArray anArray(5);
    anArray.add(9);
    anArray.show();
    anArray.add(101);
    anArray.add(9);
    anArray.show();
    cout << endl;

    cout << "Array we have from template:" << endl;
    anArray.show();
    cout << endl;

    cout << "Array after inserting numbers 3 and 88:" << endl;
    anArray.insertFirst(3);
    anArray.insertFirst(88);
    anArray.show();
    cout << endl;

    cout << "Array after deleting number 9: " << endl;
    anArray.deleteNumber(9);
    anArray.show();
    cout << endl;

    cout << "Array after adding numbers 6 and 25: " << endl;
    anArray.insertFirst(6);
    anArray.insertFirst(25);
    anArray.show();
    cout << endl;

    cout << "Array after bubble sort:" << endl;
    anArray.sort();
    anArray.show();
    cout << endl;

    anArray.append(8);
    anArray.show();


}

/* === OUTPUT ===
 
array = {9}
array = {9 , 101 , 9}

Array we have from template:
array = {9 , 101 , 9}

Array after inserting numbers 3 and 88:
array = {88 , 3 , 9 , 101 , 9}

Array after deleting number 9: 
array = {88 , 3 , 101}

Array after adding numbers 6 and 25: 
array = {25 , 6 , 88 , 3 , 101}

Array after bubble sort:
array = {3 , 6 , 25 , 88 , 101}

array = {2 , 3 , 6 , 25 , 88 , 101}
array = {2 , 3 , 6 , 25 , 88 , 101}
array = {2 , 3 , 6 , 25 , 88 , 101}

Process finished with exit code 0
 
*/

