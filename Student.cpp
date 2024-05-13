// Student.cpp

#include "Student.h"
#include <iostream> // Включення простору імен std

// Конструктор за замовчуванням
Student::Student() : birthYear(0) {}

// Конструктор ініціалізації
Student::Student(std::string surname, std::string name, std::string patronymic, int birthYear, std::string specialty, std::string university)
    : surname(surname), name(name), patronymic(patronymic), birthYear(birthYear), specialty(specialty), university(university) {}

// Оператор () для встановлення значень полів
void Student::operator()(std::string surname, std::string name, std::string patronymic, int birthYear, std::string specialty, std::string university) {
    this->surname = surname;
    this->name = name;
    this->patronymic = patronymic;
    this->birthYear = birthYear;
    this->specialty = specialty;
    this->university = university;
}

// Оператор присвоєння
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        surname = other.surname;
        name = other.name;
        patronymic = other.patronymic;
        birthYear = other.birthYear;
        specialty = other.specialty;
        university = other.university;
    }
    return *this;
}

// Оператор переміщення
Student& Student::operator=(Student&& other) noexcept {
    if (this != &other) {
        surname = std::move(other.surname);
        name = std::move(other.name);
        patronymic = std::move(other.patronymic);
        birthYear = other.birthYear;
        specialty = std::move(other.specialty);
        university = std::move(other.university);
    }
    return *this;
}

// Конструктор копіювання
Student::Student(const Student& other)
    : surname(other.surname), name(other.name), patronymic(other.patronymic), birthYear(other.birthYear), specialty(other.specialty), university(other.university) {}

// Конструктор переміщення
Student::Student(Student&& other) noexcept
    : surname(std::move(other.surname)), name(std::move(other.name)), patronymic(std::move(other.patronymic)),
    birthYear(other.birthYear), specialty(std::move(other.specialty)), university(std::move(other.university)) {}

// Деструктор
Student::~Student() {}

// Методи для зміни значень полів
void Student::setSurname(std::string surname) {
    this->surname = surname;
}

void Student::setName(std::string name) {
    this->name = name;
}

void Student::setPatronymic(std::string patronymic) {
    this->patronymic = patronymic;
}

void Student::setBirthYear(int birthYear) {
    this->birthYear = birthYear;
}

void Student::setSpecialty(std::string specialty) {
    this->specialty = specialty;
}

void Student::setUniversity(std::string university) {
    this->university = university;
}

// Методи для читання значень полів
std::string Student::getSurname() const {
    return surname;
}

std::string Student::getName() const {
    return name;
}

std::string Student::getPatronymic() const {
    return patronymic;
}

int Student::getBirthYear() const {
    return birthYear;
}

std::string Student::getSpecialty() const {
    return specialty;
}

std::string Student::getUniversity() const {
    return university;
}

// Перевизначення оператора виведення для потокового виведення
std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << "Surname: " << student.surname << "\n";
    out << "Name: " << student.name << "\n";
    out << "Patronymic: " << student.patronymic << "\n";
    out << "Birth Year: " << student.birthYear << "\n";
    out << "Specialty: " << student.specialty << "\n";
    out << "University: " << student.university << "\n";
    return out;
}

// Перевизначення оператора введення для потокового введення
std::istream& operator>>(std::istream& in, Student& student) {
    std::string surname, name, patronymic, specialty, university;
    int birthYear;
    std::cout << "Enter Surname: ";
    in >> surname;
    std::cout << "Enter Name: ";
    in >> name;
    std::cout << "Enter Patronymic: ";
    in >> patronymic;
    std::cout << "Enter Birth Year: ";
    in >> birthYear;
    std::cout << "Enter Specialty: ";
    in >> specialty;
    std::cout << "Enter University: ";
    in >> university;
    student(surname, name, patronymic, birthYear, specialty, university);
    return in;
}

void Student::print() const {
    std::cout << "Surname: " << surname << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Patronymic: " << patronymic << "\n";
    std::cout << "Birth Year: " << birthYear << "\n";
    std::cout << "Specialty: " << specialty << "\n";
    std::cout << "University: " << university << "\n";
}