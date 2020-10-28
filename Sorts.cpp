// Name: David Nguyen
// File: p5.cpp
// Date: 02/24/20 - 03/08/20
// Description: p5: Sorts (bubble, selection, insertion)
//  Use Bubble, Selection, and Insertion Sorts.docxPreview the document to add (and test!) the following methods (functions) to your EncapsulatedArray class
//  - void swap (int index1, int index2) { swaps two elements of the same array provided index1 and index2}
//  - void bubbleSort ( ) { uses the bubble sort algorithm implementation to sort the encapsulated array}
//  - void selectSort ( ) { uses the select sort algorithm implementation to sort the encapsulated array}
//  - void insertSort ( ) { uses the insert sort algorithm implementation to sort the encapsulated array}
//  - void deleteIndex (int index_to_delete) { deletes an element at index_to_delete, shifts-left elements on top of deleted element }
//  - void noDups ( ) { removes all duplicates from a sorted array, shifts-left elements on top of deleted elements }
//  - void  insert_in_order ( int number_to_insert ) { insert a number in the correct order, in an already sorted array }

#include <iostream>
using namespace std;

// Encapsulated array means an array is inside a class
class EncapsulatedArray
{
private:
    int *array; // dynamically allocated array
    int number_of_elements;
    int number_to_add;
    int index_to_delete;
public:
    // "max" sets the inital "size" of the array
    // number_of_elements starts at 0

    EncapsulatedArray(int max)
    {
        array = new int[max]; // dynamically allocated array
        number_of_elements = 0;
    }

    // appends number_to_add at the end of the array
    void append(int number_to_add)
    {
        array[number_of_elements] = number_to_add;
        number_of_elements++;
    }

    // shows the array
    void show()
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

    // deletes the first occurence of number_to_delete
    // {101, 99, 33, 9} -> deleteNumber(99); --> {101, 33, 9}
    void deleteNumber(int number_to_delete)
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

    // insert at the beginning of the array, assume it isn't full
    // {101, 9, 99} -> insertFirst(33) -> {33, 101, 9, 99}}
    void insertFirst(int number_to_insert)
    {
        // shift all elements on index to the right
        for (int a = number_of_elements; a >= 0; a--)
        {
            array[a] = array[a-1];
            if (a == 0)
                array[0] = number_to_insert;
        }

        number_of_elements++; // resize the array

    }

    // slow 0^2 run time, most swaps of all sorts
    void bubbleSort()
    {
        for(int i = 0; i < number_of_elements - 1; i++)
            for (int j = 0; j < number_of_elements - 1; j++)
                if (array[j] > array[j+1])
                    swap(j, j+1);

    }

    // find min, swap a[0] with it
    // find 2nd min, swap a[1] with it
    // find 3rd min, swap a[2] with it ... etc
    void selectionSort()	// slow 0^2 run time, but less swaps than bubbleSort
    {
        int min, min_index;

        for(int current_index = 0; current_index < number_of_elements - 1; current_index++)
        {
            min_index = current_index;

            for (int i = current_index+1; i < number_of_elements; i++)
                if (array[i] < array[min_index])
                    min_index = i;

            swap(current_index, min_index); // swap is outside of the loop
        }

    }

    // repeatedly insert in order into a partially sorted array
    void insertion_sort() // best of 3 sorts (for partially assorted array)
    {
        int in, out, temp;

        for(out = 1; out < number_of_elements; out++)
        {
            in = out;
            temp = array[in];
            while (in > 0 && array[in - 1] > temp)
            {
                array[in] = array[in -1];
                in--;
            }

            array[in] = temp;
        }
    }

    // swaps 2 elements of the array
    void swap(int index1, int index2)
    {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    // inserts number in the correct order in an already sorted (ascending) array
    void insertInOrder(int number_to_insert)
    {
        // Note: array is already assorted

        // goes through the whole array
        for (int a = 0; a < number_of_elements; a++)
            if(number_to_insert < array[a]) // if loop to find place to insert value
            {
                // when place to insert value is found, shift all values to the right
                for (int b = a; b < number_of_elements; b++)
                    array[b+1] = array[b];
                array[a] = number_to_insert; // insert the value into correct spot
            }

        number_of_elements++; // resize the array

    }

    void deleteIndex (int index_to_delete)
    {
        // start at index to delete, move everything above it one spot down
        // shifts a+1 into a's spot
        for (int a = index_to_delete; a < number_of_elements; a++ )
            array[a] = array[a+1];

        number_of_elements--; // resize the array
    }

    void noDups()
    {
        int check; // value to check for duplicates

        // go through the whole loop
        for(int a = 0; a < number_of_elements; a++)
        {
            check = array[a]; // current value of loop to check

            // checking all values past the current value to keep the original but delete duplicates
            for (int b = a+1; b < number_of_elements; b++)
                while(array[b] == check)
                    deleteIndex(b);
        }

    }

};


int main()
{
    EncapsulatedArray anArray(5);
    anArray.append(101);
    anArray.append(9);
    anArray.show();  // array = {101, 9}
    anArray.append(99);
    anArray.show();  // array = {101, 9, 99}
    anArray.bubbleSort();
    anArray.show();  // array = {9, 99, 101}
    anArray.insertFirst(33);
    anArray.show();  // array = {33, 9, 99, 101}
    anArray.selectionSort();
    anArray.show();  // array = {9, 33, 99, 101}
    anArray.insertFirst(300);
    anArray.show();  // array = {300, 9, 33, 99, 101}
    anArray.insertion_sort();
    anArray.show();  // array = {9, 33, 99, 101, 300}
    anArray.deleteIndex(2);
    anArray.show();  // array = {9, 33, 101, 300}
    anArray.deleteIndex(2);
    anArray.show();  // array = {9, 33, 300}
    anArray.deleteIndex(2);
    anArray.show();  // array = {9, 33}
    anArray.insertInOrder(10);
    anArray.insertInOrder(10);
    anArray.insertInOrder(10);
    anArray.show(); // array = {9, 10, 10, 10, 33}
    anArray.noDups();
    anArray.show(); // array = {3, 10, 33}


}

/* === OUTPUT ===

array = {101 , 9}
array = {101 , 9 , 99}
array = {9 , 99 , 101}
array = {33 , 9 , 99 , 101}
array = {9 , 33 , 99 , 101}
array = {300 , 9 , 33 , 99 , 101}
array = {9 , 33 , 99 , 101 , 300}
array = {9 , 33 , 101 , 300}
array = {9 , 33 , 300}
array = {9 , 33}
array = {9 , 10 , 10 , 10 , 33}
array = {9 , 10 , 33}

Process finished with exit code 0


 */