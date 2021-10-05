#include <iostream>
#include <vector>
#include "./Animals.h"
using namespace std; 

class Zoo
{
public:
    Zoo():members(){};
    Zoo& add(Animal* a){
        members.push_back(dynamic_cast<Animal*>(a));  // 可以自行搜索C++ dynamic_cast 
        return *this;
    }
    void listen() const{
        for(auto it = members.begin(); it < members.end(); it++)
        {
            // 会根据具体动物的类型来输出不同的叫声：运行时多态
            cout << (*it)->getName() << " says: " << (*it)->getSound() << endl;
        }
    };
private:
    vector<Animal*> members; // 为什么是指针数组？因为想利用虚函数的多态
};

int main()
{
    auto zoo = Zoo(); // 初始化动物园

    auto Amy = Cat("Amy", 3, "White");
    auto Bob = Dog("Bob", 5, "Yellow");
    auto Tom = Sheep("Tom", 2, "Brown");
    auto Mary = Cow("Mary", 6, "White-and-Black");
    auto Nick = Fox("Nick", 5, "Orange");

    zoo.add(&Amy).add(&Bob).add(&Tom).add(&Mary).add(&Nick); // 增加成员的指针

    zoo.listen();    

    return 0;
}