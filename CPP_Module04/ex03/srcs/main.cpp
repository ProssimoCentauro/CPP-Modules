/*#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}
*/

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "\033[1;36m🌱 Creating a MateriaSource...\033[0m" << std::endl;
    IMateriaSource* src = new MateriaSource();
    Ice *_ice = new Ice();
    Cure *_cure = new Cure();
    src->learnMateria(_ice);
    src->learnMateria(_cure);
    //sleep(1);

    std::cout << "\n\033[1;36m🧍 Creating characters...\033[0m" << std::endl;
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
   // sleep(1);

    std::cout << "\n\033[1;33m⚔️ Equipping Materias to 'me'...\033[0m" << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice"); me->equip(tmp);
    tmp = src->createMateria("cure"); me->equip(tmp);
    tmp = src->createMateria("ice"); me->equip(tmp);
    tmp = src->createMateria("cure"); me->equip(tmp);

    std::cout << "\033[1;33mTrying to equip a 5th materia (should do nothing)...\033[0m" << std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp); // inventario pieno
    // sleep(1);

    std::cout << "\n\033[1;36m✨ Using Materias...\033[0m" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);

    std::cout << "\033[1;33mTrying to use slot 4 (invalid, should do nothing)...\033[0m" << std::endl;
    me->use(4, *bob);
   // sleep(1);

    std::cout << "\n\033[1;36m🗑️ Testing unequip...\033[0m" << std::endl;
    me->unequip(1);
    me->use(1, *bob);
   // sleep(1);

    std::cout << "\n\033[1;36m📋 Testing deep copy of Character...\033[0m" << std::endl;
    Character original("Hero");
    tmp = src->createMateria("ice");
    original.equip(tmp);

    std::cout << "\033[1;33mCopy constructing 'copyCat' from 'Hero'...\033[0m" << std::endl;
    Character copyCat(original);
    copyCat.use(0, *bob);
   // sleep(1);

    std::cout << "\033[1;33mAssigning 'copyCat2' from 'Hero'...\033[0m" << std::endl;
    Character copyCat2("temp");
    copyCat2 = original;
    copyCat2.use(0, *bob);
   // sleep(1);

    std::cout << "\n\033[1;36m🧹 Cleaning up...\033[0m" << std::endl;
    delete bob;
    delete me;
    delete src;
    delete  _ice;
    delete _cure;

    std::cout << "\033[1;32m✔️ End of program, destructors called.\033[0m" << std::endl;
    return 0;
}

