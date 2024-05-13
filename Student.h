// Student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string surname;
    std::string name;
    std::string patronymic;
    int birthYear;
    std::string specialty;
    std::string university;

public:
    // Оголошення віртуального методу для виведення полів класу
    virtual void print() const;

    // Конструктор за замовчуванням
    Student();

    // Конструктор ініціалізації
    Student(std::string surname, std::string name, std::string patronymic, int birthYear, std::string specialty, std::string university);

    // Оператор () для встановлення значень полів
    void operator()(std::string surname, std::string name, std::string patronymic, int birthYear, std::string specialty, std::string university);

    // Оператор присвоєння
    Student& operator=(const Student& other);

    // Оператор переміщення
    Student& operator=(Student&& other) noexcept;

    // Перевизначення оператора виведення для потокового виведення
    friend std::ostream& operator<<(std::ostream& out, const Student& student);

    // Перевизначення оператора введення для потокового введення
    friend std::istream& operator>>(std::istream& in, Student& student);

    // Конструктор копіювання
    Student(const Student& other);

    // Конструктор переміщення
    Student(Student&& other) noexcept;

    // Деструктор
    ~Student();

    // Методи для зміни значень полів
    void setSurname(std::string surname);
    void setName(std::string name);
    void setPatronymic(std::string patronymic);
    void setBirthYear(int birthYear);
    void setSpecialty(std::string specialty);
    void setUniversity(std::string university);

    // Методи для читання значень полів
    std::string getSurname() const;
    std::string getName() const;
    std::string getPatronymic() const;
    int getBirthYear() const;
    std::string getSpecialty() const;
    std::string getUniversity() const;
};


#endif