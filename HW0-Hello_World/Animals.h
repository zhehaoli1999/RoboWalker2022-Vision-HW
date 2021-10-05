
#include<string>
using namespace std; 

class Animal
{
public:
    Animal(string name, int age, string furColor);
    
    virtual string getSound() const; // 虚函数

    string getName() const;
    int getAge() const;
    string getFurColor() const; 
private:
    string name;
    int age; 
    string furColor;
};

class Dog: public Animal{
public:
    Dog(string name, int age, string furColor); 
    string getSound() const; // 覆盖父类的getSound()方法
};

class Cat: public Animal{
public:
    Cat(string name, int age, string furColor);
    string getSound() const;
};

class Fox: public Animal{
public:
    Fox(string name, int age, string furColor);
    string getSound() const;
};

class Cow: public Animal{
public:
    Cow(string name, int age, string furColor);
    string getSound() const;
};

class Sheep: public Animal{
public:
    Sheep(string name, int age, string furColor);
    string getSound() const;
};

