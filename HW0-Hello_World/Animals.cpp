#include "Animals.h"

Animal::Animal(string name, int age, string furColor)
: name(name), age(age), furColor(furColor)
{}

string Animal::getName() const 
{
    return name;
}

string Animal::getFurColor() const 
{
    return furColor; 
}

int Animal::getAge() const 
{
    return age;
}

string Animal::getSound() const
{
    return ""; // nothing 
}

Dog::Dog(string name, int age, string furColor): Animal(name, age, furColor){}

Cat::Cat(string name, int age, string furColor): Animal(name, age, furColor){}

Sheep::Sheep(string name, int age, string furColor): Animal(name, age, furColor){}

Cow::Cow(string name, int age, string furColor): Animal(name, age, furColor){}

Fox::Fox(string name, int age, string furColor): Animal(name, age, furColor){}

/* Reference: 
 * http://www.ruanyifeng.com/blog/2007/01/sounds_of_animals_in_english.html
 * http://www.eleceng.adelaide.edu.au/personal/dabbott/animal.html
 */
string Dog::getSound() const 
{
    return "vov! vov!\n";
}

string Cat::getSound() const 
{
    return "meow~\n";
}
 
string Cow::getSound() const 
{
    return "moo~~~\n";
}

string Sheep::getSound() const 
{
    return "baa~~~\n";
}

string Fox::getSound() const 
{
    // Reference song: The Fox (What Does the Fox Say?)
    return " Ring-ding-ding-ding-dingeringeding!\n\
            Gering-ding-ding-ding-dingeringeding!\n\
            Wa-pa-pa-pa-pa-pa-pow!\n\
            Hatee-hatee-hatee-ho!\n\
            Joff-tchoff-tchoffo-tchoffo-tchoff!\n\
            Jacha-chacha-chacha-chow!\n\
            Fraka-kaka-kaka-kaka-kow!\n\
            A-hee-ahee ha-hee!\n\
            A-oo-oo-oo-ooo!\n";
}
