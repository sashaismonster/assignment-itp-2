/**
 *
 * ITP Assignment 2 by Alexander Golovin, B20-02 (04 probably)
 * Here, as supposed, some users are already generated (at least 1 director, 2 admins, 4 professors, 8 employ-
 * ees, 16 students)
 *
 * The program depicts the different behavour when different persons are trying to get access to different rooms
 *
 * Main classes Rooms and Users (and their subclasses, inherited from them) are stored in different files
 * "Rooms.h" and "User.h", please, refer to them for the additional info
 *
 * C++14 standard was used
 * There are no any additional custom libraries and source files
 */

#include <iostream>
#include "Rooms.h"
#include "User.h"

using namespace std;

int main() {
    Professor Shilov(506, "Nikolay", "Shilov", 63),
                Succi(457, "Giancarlo", "Succi", 50),
                Konykhov(403, "Ivan", "Konykhov", 33),
                Carvalho(438, "Daniel", "De Carvalho", 40);

    Director Sem(450, "Kirill", "Semenekhin", 53);

    Admin admin1("Evgenii", "Serov"),
          admin2("Sergey", "Gromov");

    labEmployee emp1(474, "Alexander", "Murashko", 34, "arch_lab"),
                emp2(474, "Kamilla", "Khusnutdinova", 28, "arch_lab"),
                emp3(470, "Alexey", "Kanatov", 52, "Robotics"),
                emp4(458, "Boris", "Bobrov", 43, "AI"),
                emp5(458, "Aliya", "Gazizova", 34, "AI"),
                emp6(458, "Olga", "Khamatova", 43, "AI"),
                emp7(467, "Mirko", "Farina", 54, "Theoretical Sciences"),
                emp8(467, "Veronika", "Skvortsova", 34, "Theoretical Sciences");

    Student stud1("Alexander", "Golovin", 19, 4.3),
            stud2("Karina", "Golovina", 18, 4.5),
            stud3("Alina", "Safina", 20, 4.6),
            stud4("Alexey", "Batalin", 18, 5.0),
            stud5("Marina", "Abramova", 21, 3.65),
            stud6("Irina", "Sokolova", 18, 3.46),
            stud7("Robert", "Chen", 18, 4.23),
            stud8("Alekbek", "Nursultanuly", 17, 5.0),
            stud9("Konstantin", "Smirnov", 21, 3.4),
            stud10("Diana", "Yagafarova", 22, 4.0),
            stud11("Natalya", "Shultz", 22, 4.78),
            stud12("Azalya", "Muratova", 20, 4.98),
            stud13("Anton", "Kirillin", 19, 5.0),
            stud14("Artem", "Batalov", 18, 3.91),
            stud15("Alexander", "Kedalo", 19, 4.2),
            stud16("Ivan", "Abramov", 20, 4.3);


    classRoom study(303, 30);
    study.tryToOpen(Shilov);   //Prof. Shilov is conducting lab at 303th

    Shilov.setCommonPhrase("BUT NEVERTHELESS!");
    Shilov.Speak();

    dirCabinet cab(457);
    cab.tryToOpen(Sem);  //accessed by director and he's working at this
    Sem.signPapers();

    cab.tryToOpen(stud1); //errorr - the student can't open the director's cabinet and stole the papers
    study.tryToOpen(stud1); //he goes to the classess instead

    cab.tryToOpen(admin1); //but admin do whatever
    admin1.makeReboot(); //he restarting the whole system



    return 0;
}
