//
// Created by Саша Головин on 07.03.2021.
//

/**
 *
 * Additional header including main class Rooms
 * almost every one has its room number and number of seats (except of cabinets)
 *
 * All the access markers and levels enumerators are depicted in "User.h" header
 *
 *
 * Every subclass includes tryToOpen void function that checks whethter this person is able to open the door
 * and nothing additional, the neccessary criteria are fully followed
 *
 */

#ifndef IU_ROOMS_ASSIGNMENT2_ROOMS_H
#define IU_ROOMS_ASSIGNMENT2_ROOMS_H

#include "User.h"

class Rooms {
protected:
    int roomNumber;
    int seats = 1; // for cabinets default
    Levels level;
public:
    int getRoomNumber() {
        return roomNumber;
    }
    int getSeatsNum() {
        return seats;
    }

    Rooms(int num, int seats) {
        this->roomNumber = num;
        this->seats = seats;
    }

    Rooms(int num) {
        this->roomNumber = num;
    }
};

class classRoom : public Rooms {
private:
    Levels level = NO_LEVEL;
    int seats = 18;  //default num of seats
public:
    classRoom(int num, int seats) : Rooms(num, seats) {
        this->roomNumber = num;
        this->seats = seats;
    }
    void tryToOpen(User user) {
        if (user.getAccessLevel() >= level || user.getPersonType() == ADMIN) {
            cout << "The classroom #" << roomNumber << " is opened by " << user.getName() << " successfully!" << endl;
        }
        else {
            cout << "It's not allowed! Please, try again!" << endl;
        }
    }
};

class lectureRoom : public Rooms {
private:
    Levels level = GREEN;
    int seats = 180;  //default num of seats
public:
    lectureRoom(int num, int seats) : Rooms(num, seats) {
        this->roomNumber = num;
        this->seats = seats;
    }
    void tryToOpen(User user) {
        if (user.getAccessLevel() >= level || user.getPersonType() == ADMIN) {
            cout << "The classroom #" << roomNumber << " is opened by " << user.getName() << " successfully!" << endl;
        }
        else {
            cout << "It's not allowed! Please, try again!" << endl;
        }
    }
};

class conferenceRoom : public Rooms {
private:
    Levels level = YELLOW;
    int seats = 300;  //default num of seats
public:
    conferenceRoom(int num, int seats) : Rooms(num, seats) {
        this->roomNumber = num;
        this->seats = seats;
    }
    void tryToOpen(User user) {
        if (user.getAccessLevel() >= level || user.getPersonType() == ADMIN) {
            cout << "The classroom #" << roomNumber << " is opened by " << user.getName() << " successfully!" << endl;
        }
        else {
            cout << "It's not allowed! Please, try again!" << endl;
        }
    }
};

class labCabinet : public Rooms {
private:
    Levels level = GREEN;
public:
    labCabinet(int num) : Rooms(num) {
        this->roomNumber = num;
    }
    void tryToOpen(User user) {
        if (user.getPersonType() == ADMIN || user.getPersonType() == LAB) {
            cout << "The classroom #" << roomNumber << " is opened by " << user.getName() << " successfully!" << endl;
        }
        else {
            cout << "It's not allowed! Please, try again!" << endl;
        }
    }
};

class profCabinet : public Rooms {
private:
    Levels level = YELLOW;
public:
    profCabinet(int num) : Rooms(num) {
        this->roomNumber = num;
    }
    void tryToOpen(User user) {
        if (user.getPersonType() == ADMIN || user.getPersonType() == PROF) {
            cout << "The classroom #" << roomNumber << " is opened by " << user.getName() << " successfully!" << endl;
        }
        else {
            cout << "It's not allowed! Please, try again!" << endl;
        }
    }
};

class dirCabinet : public Rooms {
private:
    Levels level = YELLOW;
public:
    dirCabinet(int num) : Rooms(num) {
        this->roomNumber = num;
    }
    void tryToOpen(User user) {
        if (user.getPersonType() == ADMIN || user.getPersonType() == DIR) {
            cout << "The classroom #" << roomNumber << " is opened by " << user.getName() << " successfully!" << endl;
        }
        else {
            cout << "It's not allowed! Please, try again!" << endl;
        }
    }
};

#endif //IU_ROOMS_ASSIGNMENT2_ROOMS_H
