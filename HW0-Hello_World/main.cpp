#include <iostream>
#include "./Animals.h"
using namespace std; 

int main()
{
    Cat Amy("Amy", 3, "White");
    Dog Bob("Bob", 5, "Yellow");
    Sheep Tom("Tom", 2, "Brown");
    Cow Mary("Mary", 6, "White-and-Black");
    Fox Nick("Nick", 5, "Orange");

    cout << "Amy says: " << Amy.getSound() << endl;
    cout << "Bob says: " << Bob.getSound() << endl;
    cout << "Tom says: " << Tom.getSound() << endl;
    cout << "Mary says: " << Mary.getSound() << endl;
    cout << "Nick says: " << Nick.getSound() << endl;
    return 0;
}

