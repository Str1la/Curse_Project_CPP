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
    // ���������� ����������� ������ ��� ��������� ���� �����
    virtual void print() const;

    // ����������� �� �������������
    Student();

    // ����������� �����������
    Student(std::string surname, std::string name, std::string patronymic, int birthYear, std::string specialty, std::string university);

    // �������� () ��� ������������ ������� ����
    void operator()(std::string surname, std::string name, std::string patronymic, int birthYear, std::string specialty, std::string university);

    // �������� ���������
    Student& operator=(const Student& other);

    // �������� ����������
    Student& operator=(Student&& other) noexcept;

    // �������������� ��������� ��������� ��� ���������� ���������
    friend std::ostream& operator<<(std::ostream& out, const Student& student);

    // �������������� ��������� �������� ��� ���������� ��������
    friend std::istream& operator>>(std::istream& in, Student& student);

    // ����������� ���������
    Student(const Student& other);

    // ����������� ����������
    Student(Student&& other) noexcept;

    // ����������
    ~Student();

    // ������ ��� ���� ������� ����
    void setSurname(std::string surname);
    void setName(std::string name);
    void setPatronymic(std::string patronymic);
    void setBirthYear(int birthYear);
    void setSpecialty(std::string specialty);
    void setUniversity(std::string university);

    // ������ ��� ������� ������� ����
    std::string getSurname() const;
    std::string getName() const;
    std::string getPatronymic() const;
    int getBirthYear() const;
    std::string getSpecialty() const;
    std::string getUniversity() const;
};


#endif