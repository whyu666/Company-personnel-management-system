#include "person.h"

int Person::number = 0;
void Person::newPerson() {
    number++;
}
int Person::showPerson() {
    return number;
}
void Person::deletePerson() {
    number--;
}
