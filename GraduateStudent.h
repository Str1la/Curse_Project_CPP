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
    // ���������� ����������� ������ ��� ��������� ���� �����
    void print() const override;

    // ����������� �� �������������
    GraduateStudent();

    // ����������� �����������
    GraduateStudent(std::string surname, std::string name, std::string patronymic, int birthYear, std::string specialty, std::string university,
        std::string thesisTopic, std::string internshipPeriod, std::string defenseDate, State progressStatus);

    // �������� () ��� ������������ ������� ����
    void operator()(std::string surname, std::string name, std::string patronymic, int birthYear, std::string specialty, std::string university,
        std::string thesisTopic, std::string internshipPeriod, std::string defenseDate, State progressStatus);

    // ����������� ���������
    GraduateStudent(const GraduateStudent& other);

    // ����������� ����������
    GraduateStudent(GraduateStudent&& other) noexcept;

    // ����������
    ~GraduateStudent();

    // ������ ��� ���� ������� ����
    void setThesisTopic(std::string thesisTopic);
    void setInternshipPeriod(std::string internshipPeriod);
    void setDefenseDate(std::string defenseDate);
    void setProgressStatus(State progressStatus);

    // ������ ��� ������� ������� ����
    std::string getThesisTopic() const;
    std::string getInternshipPeriod() const;
    std::string getDefenseDate() const;
    State getProgressStatus() const;

    // �������������� ��������� ��������� �� ��������
    friend std::ostream& operator<<(std::ostream& out, const GraduateStudent& gradStudent);
    friend std::istream& operator>>(std::istream& in, GraduateStudent& gradStudent);

    // �������������� ��������� ���������
    GraduateStudent& operator=(const GraduateStudent& other) = default;
};

#endif
