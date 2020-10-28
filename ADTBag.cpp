// Name: David Nguyen
// File: p4.cpp
// Date: 02/17/20 - 03/01/20
// Description: ADT Bag Array Implementation
//  === WRITE and TEST the Functions below:
//  void most_expensive ( ) (shows the most expensive item)
//  void show_reverse ( ) (shows everything in the bag in reverse order of showItems() )
//  void get_frequency (Item item) (show how many times an Item (the name) appears in the bag)
//  bool delete_item (Item item) (delete 1 item (based on the name), shift array elements to the left, return true if successful
//  int get_index_of (Item item) (returns the index of an item (based on the name) )
//  double sum_of_all ( ) (returns the sum of all Items)

#include <iostream>

using namespace std;

class Item
{
    private:
        string name;  // two different private variables
        double cost;

    public:
         // constructor: same name as the class
        Item()	// default constructor
        {
           name = "";
           cost = 0.0;
        }

        Item (string newName, double newCost) // explicit constructor
        {
            name = newName;
            cost = newCost;
        }

        void show () // showing the name and cost
        {
            cout << "- " << name << " $" << cost << endl;
        }

        string get_name() { return name; }
        double get_cost() { return cost; }

        // to modify the existing obeject
        void set_item(string newName, double newCost)
        {
            name = newName;
            cost = newCost;
        }

        // allows you to get one item, create another item, set the other item to the item
        // the item you are setting is going to become equal to another item
        void setItem(Item item)
        {
            name = item.get_name();
            cost = item.get_cost();
        }
};
// reminder to include semicolon after a class!!
// do not need a semi colon after a function

/*
bare minimum you need for a class
- some constructors
- a way to show the properties
- a way to return the properties
- ways to change the properties
*/


class Bag
{
    private:
        Item *items;
        int number_items;
        int max;

    public:
        Bag(int Max)
        {
            items = new Item[Max]; // an array of items
            number_items = 0; // this is the current index of item
            max = Max; // size of the bag/array
        }

        // to insert a brand new item
        void insert_item(string name, double cost)
        {
            items[number_items].set_item(name, cost);
            number_items++;
        }

        // to insert an already existing item into the bag
        void insertItem(Item item)
        {
            //items[number_items].set_item( item.get_name(), item.get_cost() );
            items[number_items].setItem(item);
            number_items++;
        }

        int size() { return max; }

        void showItems()    // shows all items in the bag
        {
            for (int i = 0; i < number_items; i++)
                items[i].show();
        }

        void delete_first()
        {
            // shift all the elements one to the left
            for (int i = 0; i < number_items - 1; i++)
                items[i] = items[i + 1];
            number_items--;
        }

        bool contains(string name_to_find)
        {
            for (int i = 0; i < number_items; i++)
                if (name_to_find == items[i].get_name())
                    return true;
            return false;
        }

        void sort_by_cost_ascending() // bubble sort
        {
            for (int i = 0; i < number_items - 1; i++)
                for (int j = 0; j < number_items - 1; j++)
                    if (items[j].get_cost() > items[j + 1].get_cost())
                        swap(j, j + 1);
        }

        void swap(int index1, int index2)
        {
            Item temp = items[index1];
            items[index1] = items[index2];
            items[index2] = temp;
        }

        void most_expensive()
        {
            double mostPrice = items[0].get_cost(); // set starting price to compare as 1st item
            Item highPrice; // item to show with the highest price
            for (int i = 0; i < number_items - 1; i++)  // check for highest price
            {
                if (items[i].get_cost() > mostPrice)
                    highPrice = items[i];
            }
            highPrice.show();  // the item with the highest price

        }

        void show_reverse()
        {
            for (int i = number_items - 1 ; i >=  0; i--)
                items[i].show();
        }

        int get_index_of(Item item)
        {
           for (int i = 0; i < number_items; i++)
               if (items[i].get_name() == item.get_name() )
                   return i;
        }


        double sum_of_all()
        {
            double sumPrice = 0;
            for (int i = 0; i < number_items; i++)
                sumPrice = sumPrice + items[i].get_cost();
            return sumPrice;
        }

        void get_frequency (Item item)
        {
            int count = 0; // count will show the frequency
            for (int i = 0; i < number_items; i++)
                if (items[i].get_name() == item.get_name())
                    count++;

            cout << item.get_name() << " appears " << count << " times in the bag.";
        }

        bool deleteItem (Item item)
        {
            int indexDelete; // find the index to delete
            for (indexDelete = 0; indexDelete < number_items; indexDelete++)
                if (items[indexDelete].get_name() == item.get_name())
                    break; // if we find item we break the loop
            // item does not exist
            if (indexDelete == number_items)
                return false;
            // item exists, shift all elements and return true
            for (int i = indexDelete; i < number_items; i++)
                items[i] = items[i+1];
            number_items--; // resize the bag
            return true;
        }

};


int main()
{
    // test to see if item works
    cout << "Testing Item: ";
    Item fujiApple("Fuji Apple", 4.99);
    // "fuji apple" is the name, 4.99 is the cost
    fujiApple.show();

    // deciding number of items to be in the bag
    int max_items_in_bag = 4;
    Bag bag(max_items_in_bag);

    // adding items
    cout << "\nAdded the follow items to the bag: \n";
    bag.insert_item("Oranges", 5.99);
    bag.insertItem(fujiApple);

    // creating an Item cheese and then adding it  - cheese is its own object 
    Item cheese("Cheese", 6.79);
    bag.insertItem(cheese);
    bag.insert_item("Olives", 4.49);
    bag.insert_item("Bananas", 0.79);
    bag.showItems();

    cout << endl << "Show bag in reverse: " << endl;
    bag.show_reverse();
    cout << endl;

    cout << "The most expensive item in the bag is: " << endl;
    bag.most_expensive();
    cout << endl;

    bag.get_frequency(cheese);
    cout << endl;

    cout << endl;
    cout << "The sum of all items in the bag is: $" << bag.sum_of_all() << endl;

    cout << endl;
    int aa = bag.get_index_of(fujiApple);
    cout << "The index of the item Fuji Apple is: " << aa << "." << endl;

    cout << endl;
    int x = bag.deleteItem(cheese);
    if (x == 1)
        cout << "The item cheese was taken out of the bag." << endl;
    else if (x == 0)
        cout << "The item cheese does not exist in the bag." << endl;

    cout << endl << "The new list of items is: " << endl;
    bag.showItems();
    cout << endl;

    cout << "The new sum of all items is: $" << bag.sum_of_all() << "." << endl;


    return 0;
}


/* === OUTPUT ===

Testing Item: - Fuji Apple $4.99

Added the follow items to the bag: 
- Oranges $5.99
- Fuji Apple $4.99
- Cheese $6.79
- Olives $4.49
- Bananas $0.79

Show bag in reverse: 
- Bananas $0.79
- Olives $4.49
- Cheese $6.79
- Fuji Apple $4.99
- Oranges $5.99

The most expensive item in the bag is: 
- Cheese $6.79

Cheese appears 1 times in the bag.

The sum of all items in the bag is: $23.05

The index of the item Fuji Apple is: 1.

The item cheese was taken out of the bag.

The new list of items is: 
- Oranges $5.99
- Fuji Apple $4.99
- Olives $4.49
- Bananas $0.79

The new sum of all items is: $16.26.

Process finished with exit code 0
 
 */
