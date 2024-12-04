#include <iostream>
#include <string>

class Zombie {
public:
    std::string name;
    
    Zombie(std::string n) : name(n) {
        std::cout << "Zombie created: " << name << std::endl;
    }

    ~Zombie() {
        std::cout << "Zombie destroyed: " << name << std::endl;
    }
};

void createZombieOnStack() {
    Zombie newZombie = Zombie("StackZombie"); // Created on the stack
    std::cout << "Inside createZombieOnStack function." << std::endl;
} // newZombie goes out of scope and is destroyed here

void createZombieOnHeap() {
    Zombie *zombiePtr = new Zombie("HeapZombie"); // Created on the heap
    std::cout << "Inside createZombieOnHeap function." << std::endl;
    delete zombiePtr; // Manually deleting the zombie to free memory
}

int main() {
    createZombieOnStack();
    createZombieOnHeap();
    return 0;
}
