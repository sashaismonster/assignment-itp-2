//
// Created by Alexander Golovin on 07.03.2021.
//

/**
 *
 * The description includes the "description" of abstract class User with main variables and common functions
 *
 * Levels of access and kind of users are depicted in enumerators to distinguish easily and used in checkers
 *
 * Every subclass like student, profs, lab employee and others include some specific features & functions
 * (at least one per each class, as it was required in TA) to make the system somehow to be real
 *
 *
 */

#ifndef IU_ROOMS_ASSIGNMENT2_USER_H
#define IU_ROOMS_ASSIGNMENT2_USER_H

using namespace std;

enum Levels {
    NO_LEVEL,
    GREEN,
    YELLOW,
    RED
};

enum Type {
    STUDENT,
    LAB,
    PROF,
    DIR,
    ADMIN
};

class User {
protected:
    string name;
    string surname;
    int age;
    Levels level;
    Type type;
public:
    Levels getAccessLevel() {
        return level;
    }
    Type getPersonType() {
        return type;
    }
    string getName() {
        return name;
    }
};

class Student : public User {
private:
    Levels level = NO_LEVEL;
    float avgGrade;
    Type type = STUDENT;
public:
    Student(string name, string surname, int age, float avgGrade) {
        this->name = name;
        this->surname = surname;
        this->age = age;
        this->avgGrade = avgGrade;
    }
    float getAvgGrade() {
        return avgGrade;
    }
};

class labEmployee: public User {
private:
    Levels level = GREEN;
    int cabNumber;
    Type type = LAB;
    string nameLab;
public:
    labEmployee(int cabinet, string sName, string sSurname, int age, string lab_name) {
        this->cabNumber = cabinet;
        this->name = sName;
        this->surname = sSurname;
        this->age = age;
        this->nameLab = lab_name;
    }
    string getLabName() {
        return nameLab;
    }
};

class Professor : public User {
private:
    Levels level = YELLOW;
    int cabNumber;
    Type type = PROF;
    string commonPhrase;
public:
    Professor(int cabinet, string sName, string sSurname, int age) {
        this->cabNumber = cabinet;
        this->name = sName;
        this->surname = sSurname;
        this->age = age;
    }
    void setCommonPhrase(string s) {
        commonPhrase = s;
    }
    void Speak() {
        cout << name << " speaks: " << commonPhrase << endl;
    }
};

class Director : public User {
private:
    Levels level = YELLOW;
    int cabNumber;
    Type type = DIR;
public:
    Director(int cabinet, string sName, string sSurname, int age) {
        this->cabNumber = cabinet;
        this->name = sName;
        this->surname = sSurname;
        this->age = age;
    }
    void signPapers() {
        cout << "A lot of documents were signed withing an e-signature!";
    }
};

class Admin: public User {
private:
    Levels level = RED;
    Type type = ADMIN;
public:
    Admin(string sName, string sSurname) {
        this->name = sName;
        this->surname = sSurname;
    }
    void makeReboot() {
        cout << "Rebooted successfully! Errors had been distructed" << endl;
    }
};


#endif //IU_ROOMS_ASSIGNMENT2_USER_H
