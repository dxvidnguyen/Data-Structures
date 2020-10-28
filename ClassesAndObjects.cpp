// Name: David Nguyen
// File: p2.cpp
// Date: 02/10/20 - 02/23/20
// Description: Classes and Objects
//  Type up the sample program and get it to work, then:
//  add the private Property weight (decimal number)
//  add the public Actions that change and show the property: showWeight and changeWeight
//  Test the actions from the actions from the main() and show your program test run.

#include <iostream>
using namespace std;

class Person
{
private:	 // age is private, so we can't access age via "alex.age"
    int age;
    float weight;

public: 	// provides ways to access(show/change) the private age
    void showAge();					// function
    void changeAge(int newAge);		// function

    void showWeight();
    void changeWeight(float newWeight);

    Person(); 				// Default Constructor
    Person(int newAge, float weight); 	// Explicit Constructor
};

// function prototypes in the class
// function definitions defined below

void Person::showAge()
{
    cout << age << endl;
}

void Person::changeAge(int newAge)
{
    age = newAge;
}

Person::Person()	// default constructor
{
    age = 101;
    weight = 100.0;
}

Person::Person(int newAge, float weight) // explicit constructor
{
    age = newAge;
}

void Person::showWeight()
{
    cout << weight << endl;
}

void Person::changeWeight(float newWeight)
{
    weight = newWeight;
}



int main()
{
    Person alex; 		// Use default constructor
    alex.showAge(); 	// garbage w/o the default constructor, 101 with
    alex.changeAge(36); // changes the value of age to 36
    alex.showAge();		// shows the afe which is now 36

    Person child(8, 50);	// Uses explicit constructor
    child.showAge();

    cout << endl;

    Person tommy;     // using the default constructor
    cout << "Name of Object: tommy" << endl;

    cout << "Object's default weight: ";
    tommy.showWeight();

    // change the weight
    tommy.changeWeight(140.75);

    cout << "Object's new weight: ";
    tommy.showWeight();

}

/* === OUTPUT ===

101
36
8

Name of Object: tommy
Object's default weight: 100
Object's new weight: 140.75

 */