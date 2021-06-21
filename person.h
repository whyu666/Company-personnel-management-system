#ifndef PERSON_H
#define PERSON_H

#include <QString>


class Person {
public:
    static void newPerson();
    static int showPerson();
    static void deletePerson();
    //virtual void setname(QString a) = 0;
protected:
    int id;
private:
    static int number;
};

#endif // PERSON_H
