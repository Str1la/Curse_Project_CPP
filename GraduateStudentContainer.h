#include <vector>
#include <algorithm> // ��� ������������ ������� ����������
#include <fstream>   // ��� ������������ ����� ifstream �� ofstream
#include <sstream>   // ��� ������������ ����� stringstream
#include "GraduateStudent.h" // �������� ���� GraduateStudent
#include <iostream>

class GraduateStudentContainer {
private:
    std::vector<GraduateStudent> students; // ������ ��� ��������� ��'���� GraduateStudent

public:
    // ����-�������� ��� ����� GraduateStudentContainer
    class Iterator {
    private:
        std::vector<GraduateStudent>::iterator iter; // �������� ��� ������� ��������

    public:
        // ����������� ���������
        Iterator(std::vector<GraduateStudent>::iterator it) : iter(it) {}

        // ��������� ��� ������ � ����������
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

    // ��������� ������ �������� �� ����������
    void addStudent(const GraduateStudent& student) {
        students.push_back(student);
    }

    // ������ ��� ��������� ����������� �� �������� ��������� ����������
    Iterator begin() {
        return Iterator(students.begin());
    }

    Iterator end() {
        return Iterator(students.end());
    }

    // ��������� ���������� ��� ��� �������� � ���������
    void displayStudents() const {
        for (const auto& student : students) {
            std::cout << student << "\n";
        }
    }

    // ����� ��� ���������� �������� �� ��'��
    void sortByName() {
        std::sort(students.begin(), students.end(), [](const GraduateStudent& a, const GraduateStudent& b) {
            return a.getSurname() < b.getSurname();
            });
    }

    // ����� ��� ���������� �������� �� ����� ����������
    void sortByBirthYear() {
        std::sort(students.begin(), students.end(), [](const GraduateStudent& a, const GraduateStudent& b) {
            return a.getBirthYear() < b.getBirthYear();
            });
    }

    // ����� ��� ������������ �������� �� �������� ��������� �������� ������
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
        students.clear(); // ������� �������� ������ �������� ����� ������������� � �����
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
