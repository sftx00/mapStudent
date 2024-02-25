#include <iostream>
#include <map>
#include <string>

using namespace std;

class Student {
    // класс студеньа
private:
    string name;
    string surname;
    int age;

public:
    Student() : name(""), surname(""), age(-1) {}

    Student(string name, string surname, int age) : name(name), surname(surname), age(age) {}

    string getFullName() const {
        return name + " " + surname;
    }

    int getAge() const {
        return age;
    }
};

class MAPS {
    // класс map
private:
    map<string, map<string, map<string, map<string, Student>>>> studentsMap;

public:
    void addStudent(const string& firstName, const string& lastName, const string& middleName, const string& group, const Student& student) {
        studentsMap[firstName][lastName][middleName][group] = student;
    }

    Student findStudent(const string& firstName, const string& lastName, const string& middleName, const string& group) const {
        auto itFirstName = studentsMap.find(firstName);
        if (itFirstName != studentsMap.end()) {
            auto itLastName = itFirstName->second.find(lastName);
            if (itLastName != itFirstName->second.end()) {
                auto itMiddleName = itLastName->second.find(middleName);
                if (itMiddleName != itLastName->second.end()) {
                    auto itGroup = itMiddleName->second.find(group);
                    if (itGroup != itMiddleName->second.end()) {
                        return itGroup->second;
                    }
                }
            }
        }
        return Student("", "", -1);
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    MAPS mapStud;

    Student student1("Иван", "Иванов", 20);
    Student student2("Никита", "Задворных", 22);
    Student student3("Сидор", "Сидоров", 21);

    mapStud.addStudent("Иван", "Иванов", "Иванович", "Группа1", student1);
    mapStud.addStudent("Никита", "Задворных", "Васильевич", "Группа1", student2);
    mapStud.addStudent("Сидор", "Сидоров", "Сидорович", "Группа2", student3);

    Student foundStudent1 = mapStud.findStudent("Иван", "Иванов", "Иванович", "Группа1");
    Student foundStudent2 = mapStud.findStudent("Никита", "Задворных", "Васильевич", "Группа1");
    Student foundStudent3 = mapStud.findStudent("Сидор", "Сидоров", "Сидорович", "Группа2");

    cout << "Студент 1: " << foundStudent1.getFullName() << ", возраст: " << foundStudent1.getAge() << endl;
    cout << "Студент 2: " << foundStudent2.getFullName() << ", возраст: " << foundStudent2.getAge() << endl;
    cout << "Студент 3: " << foundStudent3.getFullName() << ", возраст: " << foundStudent3.getAge() << endl;

    return 0;
}
