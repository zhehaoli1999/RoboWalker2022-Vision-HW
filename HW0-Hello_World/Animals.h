
#include<string>
using namespace std; 

class Animals
{
public:
    Animals(string name, int age, string furColor);
    string sound();
private:
    string name;
    int age; 
    string furColor;
};
