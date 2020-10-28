// Name: David Nguyen
// File: p8bOverloadingOperators.cpp
// Date: 03/16/20 - 05/22/20
// Description: Type up the given example and then overload the following
//  operators
//  1) Relational Operators         (>, <=, >=)
//  2) Multiplication Operator      (*)
//  3) Division Operator            (/)
//  4) Subtraction Operator         (-)

#include <iostream>
using namespace std;

class Distance
{
private:
    int meter;
public:

    // constructor
    Distance(int m)      {meter = m;}
    // overload <
    bool operator <  (const Distance d)     {return meter < d.meter;}
    // overload ==
    bool operator == (const Distance &d)    { return meter == d.meter; }
    // overload !=
    bool operator != (const Distance &d)    { return meter != d.meter; }
    // overload =
    void operator = (const Distance &d)     {  meter = d.meter; }
    // overload +
    Distance operator + (const Distance &d)
    {
        Distance dist(0);
        dist.meter = this->meter + d.meter; // "this" = d1; d = d2
        return dist;
    }

    // overload <<
    friend ostream &operator << ( ostream &output, const Distance &D)
    {
        output << D.meter << "m " << endl;
        return output;
    }

    // overload >>
    friend istream &operator >> (istream &input, Distance &D)
    {
        input >> D.meter;
        return input;
    }




    // overload >
    bool operator >  (const Distance d)     {return meter > d.meter;}
    // overload <=
    bool operator <=  (const Distance d)     {return meter <= d.meter;}
    // overload >=
    bool operator >=  (const Distance d)     {return meter >= d.meter;}

    // overload -
    Distance operator - (const Distance &d)
    {
        Distance a(0);
        a.meter = this->meter - d.meter;
        return a;
    }

    // overload *
    Distance operator * (const Distance &d)
    {
        Distance a(0);
        a.meter = this->meter * d.meter;
        return a;
    }

    // overload /
    Distance operator / (const Distance &d)
    {
        Distance a(0);
        a.meter = this->meter / d.meter;
        return a;
    }




};


int main()
{
    Distance d1(4), d2(2), d3(0), d4(4), d5(4);
    cout << boolalpha;

    // overload << for d1, d2, d3. d4
    cout << "d1 = " << d1;
    cout << "d2 = " << d2;
    cout << "d3 = " << d3;
    cout << "d4 = " << d4;

    cout << "Value of d4 is now d1+d2" << endl;
    d4 = d1+d2;

    cout << "d1 + d2 = d4 =  " << d1 + d2;           // overload +
    cout << "(d1 < d2) is  " << (d1 < d2) << endl;   // overload <
    cout << "(d3 < d1) is  " << (d3 < d1) << endl;
    cout << "(d4 == d1) is  " << (d4 == d1) << endl; // overload ==
    cout << "(d4 != d1) is  " << (d1 != d4) << endl; // overload !=
    cout << "Enter d4: ";
    cin >> d4;                                  // overload >>
    cout << "d4 = " << d4;                      // overload <<

    cout << "(d1 > d2) is  " << (d1 > d2) << endl;   // overload >
    cout << "(d1 <= d2) is  " << (d1 <= d2) << endl;   // overload <=
    cout << "(d1 <= d5) is  " << (d1 <= d5) << endl;   // overload <=
    cout << "(d1 >= d2) is  " << (d1 >= d2) << endl;   // overload >=
    cout << "(d1 >= d5) is  " << (d1 >= d5) << endl;   // overload >=


    cout << "d1 - d2 = " << d1 - d2;        // overload -
    cout << "d1 * d2 = " << d1 * d2;        // overload *
    cout << "d1 / d2 = " << d1 / d2;        // overload /





}




/* === OUTPUT ===
Final Run:
/Users/davidnguyen/CLionProjects/random/cmake-build-debug/random
d1 = 4m 
d2 = 2m 
d3 = 0m 
d4 = 4m 
Value of d4 is now d1+d2
d1 + d2 = d4 =  6m 
(d1 < d2) is  false
(d3 < d1) is  true
(d4 == d1) is  false
(d4 != d1) is  true
Enter d4: 44
d4 = 44m 
(d1 > d2) is  true
(d1 <= d2) is  false
(d1 <= d5) is  true
(d1 >= d2) is  true
(d1 >= d5) is  true
d1 - d2 = 2m 
d1 * d2 = 8m 
d1 / d2 = 2m 

Process finished with exit code 0


Test Run 1:
/Users/davidnguyen/CLionProjects/random/cmake-build-debug/random
d1 = 4m
d2 = 2m
d3 = 0m
d4 = 4m
d1 + d2 = d4 =  6m
(d1 < d2) is  false
(d3 < d1) is  true
(d4 == d1) is  false
(d4 != d1) is  true
Enter d4: 20
d4 = 20m

Process finished with exit code 0




 */