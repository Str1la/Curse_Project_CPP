#include <vector>
#include <algorithm> // Для використання функції сортування
#include "GraduateStudent.h" // Включаємо клас GraduateStudent
#include <iostream>

class GraduateStudentContainer {
private:
    std::vector<GraduateStudent> students; // Вектор для зберігання об'єктів GraduateStudent

public:
    // Клас-ітератор для класу GraduateStudentContainer
    class Iterator {
    private:
        std::vector<GraduateStudent>::iterator iter; // Ітератор для вектора студентів

    public:
        // Конструктор ітератора
        Iterator(std::vector<GraduateStudent>::iterator it) : iter(it) {}

        // Оператори для роботи з ітератором
        Iterator& operator++() {
            ++iter;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++iter;
            return temp;
        }

        bool operator==(const Iterator& other) const {
            return iter == other.iter;
        }

        bool operator!=(const Iterator& other) const {
            return iter != other.iter;
        }

        GraduateStudent& operator*() {
            return *iter;
        }
    };

    // Додавання нового студента до контейнера
    void addStudent(const GraduateStudent& student) {
        students.push_back(student);
    }

    // Методи для отримання початкового та кінцевого ітераторів контейнера
    Iterator begin() {
        return Iterator(students.begin());
    }

    Iterator end() {
        return Iterator(students.end());
    }

    // Виведення інформації про всіх студентів у контейнері
    void displayStudents() const {
        for (const auto& student : students) {
            std::cout << student << "\n";
        }
    }

    // Метод для сортування студентів за ім'ям
    void sortByName() {
        std::sort(students.begin(), students.end(), [](const GraduateStudent& a, const GraduateStudent& b) {
            return a.getSurname() < b.getSurname();
            });
    }

    // Метод для сортування студентів за роком народження
    void sortByBirthYear() {
        std::sort(students.begin(), students.end(), [](const GraduateStudent& a, const GraduateStudent& b) {
            return a.getBirthYear() < b.getBirthYear();
            });
    }

    // Метод для фільтрування студентів за статусом виконання дипломної роботи
    void filterByProgressStatus(State status) {
        students.erase(std::remove_if(students.begin(), students.end(), [&status](const GraduateStudent& student) {
            return student.getProgressStatus() != status;
            }), students.end());
    }
};
