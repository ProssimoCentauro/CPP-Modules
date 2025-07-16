#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    // 🐱 Creating the cat
    std::cout << "\033[1;36mCreating a cat...\033[0m" << std::endl;
    Cat cat;
    cat.makeSound(); // 🐾 Meow!

    // 🧠 Set cat's ideas
    cat.getBrain()->setIdea("Sleep on the couch");
    cat.getBrain()->setIdea("Chase the mouse");

    std::cout << "\033[1;33mCat's ideas:\033[0m" << std::endl;
    std::cout << "🐾 - " << cat.getBrain()->getIdea(0) << std::endl;
    std::cout << "🐾 - " << cat.getBrain()->getIdea(1) << std::endl;

    // 🐶 Creating the dog
    std::cout << "\n\033[1;36mCreating a dog...\033[0m" << std::endl;
    Dog dog;
    dog.makeSound(); // 🐾 Woof!

    // 🧠 Set dog's ideas
    dog.getBrain()->setIdea("Bark at the mailman");
    dog.getBrain()->setIdea("Dig a hole");

    std::cout << "\033[1;33mDog's ideas:\033[0m" << std::endl;
    std::cout << "🐾 - " << dog.getBrain()->getIdea(0) << std::endl;
    std::cout << "🐾 - " << dog.getBrain()->getIdea(1) << std::endl;

    // 🐱➡️🐱 Copy the cat
    std::cout << "\n\033[1;36mCopying the cat to another one...\033[0m" << std::endl;
    Cat anotherCat(cat); // deep copy
    anotherCat.getBrain()->setIdea("Eat fish");

    std::cout << "\033[1;33mOriginal cat idea 0:\033[0m " << cat.getBrain()->getIdea(0) << std::endl;
    std::cout << "\033[1;33mCopied cat idea 0:\033[0m " << anotherCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "\033[1;33mCopied cat idea 2:\033[0m " << anotherCat.getBrain()->getIdea(2) << std::endl;

    // 🧹 End of program
    std::cout << "\n\033[1;32mEnd of main, destructors will be called now.\033[0m" << std::endl;
    return 0;
}
