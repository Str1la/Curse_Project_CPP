#include <vector>
#include <algorithm> // ��� ������������ ������� ����������
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
};
