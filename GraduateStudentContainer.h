#include <vector>
#include <algorithm> // Для використання функції сортування
#include <fstream>   // Для використання класів ifstream та ofstream
#include <sstream>   // Для використання класу stringstream
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

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& student : students) {
                file << student.getSurname() << ',' << student.getName() << ',' << student.getPatronymic() << ','
                    << student.getBirthYear() << ',' << student.getSpecialty() << ',' << student.getUniversity() << ','
                    << student.getThesisTopic() << ',' << student.getInternshipPeriod() << ',' << student.getDefenseDate() << ','
                    << static_cast<int>(student.getProgressStatus()) << '\n';
            }
            file.close();
            std::cout << "Student list successfully saved to file.\n";
        }
        else {
            std::cerr << "Error: Unable to open file for writing.\n";
        }
    }

    void loadFromFile(const std::string& filename) {
        students.clear(); // Очищуємо поточний список студентів перед завантаженням з файлу
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string surname, name, patronymic, specialty, university, thesisTopic, internshipPeriod, defenseDate, statusStr;
                int birthYear;
                State progressStatus;
                std::getline(ss, surname, ',');
                std::getline(ss, name, ',');
                std::getline(ss, patronymic, ',');
                ss >> birthYear;
                ss.ignore();
                std::getline(ss, specialty, ',');
                std::getline(ss, university, ',');
                std::getline(ss, thesisTopic, ',');
                std::getline(ss, internshipPeriod, ',');
                std::getline(ss, defenseDate, ',');
                std::getline(ss, statusStr, ',');
                progressStatus = static_cast<State>(std::stoi(statusStr));
                students.emplace_back(surname, name, patronymic, birthYear, specialty, university,
                    thesisTopic, internshipPeriod, defenseDate, progressStatus);
            }
            file.close();
            std::cout << "Student list successfully loaded from file.\n";
        }
        else {
            std::cerr << "Error: Unable to open file for reading.\n";
        }
    }

};
