//GraduateStudent.h
#ifndef GRADUATESTUDENT_H
#define GRADUATESTUDENT_H

#include "Student.h"
#include <string>

enum class State {
    Agreement,
    InProgres,
    Review,
    Admitted,
    Protected
};


class GraduateStudent : public Student {
private:
    std::string thesisTopic;
    std::string internshipPeriod;
    std::string defenseDate;
    State progressStatus;

public:
    // Оголошення віртуального методу для виведення полів класу
    void print() const override;

    // Конструктор за замовчуванням
    GraduateStudent();

    // Конструктор ініціалізації
    GraduateStudent(std::string surname, std::string name, std::string patronymic, int birthYear, std::string specialty, std::string university,
        std::string thesisTopic, std::string internshipPeriod, std::string defenseDate, State progressStatus);

    // Оператор () для встановлення значень полів
    void operator()(std::string surname, std::string name, std::string patronymic, int birthYear, std::string specialty, std::string university,
        std::string thesisTopic, std::string internshipPeriod, std::string defenseDate, State progressStatus);

    // Конструктор копіювання
    GraduateStudent(const GraduateStudent& other);

    // Конструктор переміщення
    GraduateStudent(GraduateStudent&& other) noexcept;

    // Деструктор
    ~GraduateStudent();

    // Методи для зміни значень полів
    void setThesisTopic(std::string thesisTopic);
    void setInternshipPeriod(std::string internshipPeriod);
    void setDefenseDate(std::string defenseDate);
    void setProgressStatus(State progressStatus);

    // Методи для читання значень полів
    std::string getThesisTopic() const;
    std::string getInternshipPeriod() const;
    std::string getDefenseDate() const;
    State getProgressStatus() const;

    // Перевизначення операторів виведення та введення
    friend std::ostream& operator<<(std::ostream& out, const GraduateStudent& gradStudent);
    friend std::istream& operator>>(std::istream& in, GraduateStudent& gradStudent);

    // Перевизначення оператора присвоєння
    GraduateStudent& operator=(const GraduateStudent& other) = default;
};

#endif
