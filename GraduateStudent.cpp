// GraduateStudent.cpp

#include "GraduateStudent.h"
#include <iostream> // Для потокового вводу та виводу

// Конструктор за замовчуванням
GraduateStudent::GraduateStudent() {}

// Конструктор ініціалізації
GraduateStudent::GraduateStudent(std::string surname, std::string name, std::string patronymic, int birthYear, std::string specialty, std::string university,
    std::string thesisTopic, std::string internshipPeriod, std::string defenseDate, State progressStatus)
    : Student(surname, name, patronymic, birthYear, specialty, university),
    thesisTopic(thesisTopic),
    internshipPeriod(internshipPeriod),
    defenseDate(defenseDate),
    progressStatus(progressStatus) {}

// Оператор () для встановлення значень полів
void GraduateStudent::operator()(std::string surname, std::string name, std::string patronymic, int birthYear, std::string specialty, std::string university,
    std::string thesisTopic, std::string internshipPeriod, std::string defenseDate, State progressStatus) {
    Student::operator()(surname, name, patronymic, birthYear, specialty, university);
    this->thesisTopic = thesisTopic;
    this->internshipPeriod = internshipPeriod;
    this->defenseDate = defenseDate;
    this->progressStatus = progressStatus;
}

// Конструктор копіювання
GraduateStudent::GraduateStudent(const GraduateStudent& other)
    : Student(other),
    thesisTopic(other.thesisTopic),
    internshipPeriod(other.internshipPeriod),
    defenseDate(other.defenseDate),
    progressStatus(other.progressStatus) {}

// Конструктор переміщення
GraduateStudent::GraduateStudent(GraduateStudent&& other) noexcept
    : Student(std::move(other)),
    thesisTopic(std::move(other.thesisTopic)),
    internshipPeriod(std::move(other.internshipPeriod)),
    defenseDate(std::move(other.defenseDate)),
    progressStatus(std::move(other.progressStatus)) {}


// Деструктор
GraduateStudent::~GraduateStudent() {}

// Методи для зміни значень полів
void GraduateStudent::setThesisTopic(std::string thesisTopic) {
    this->thesisTopic = thesisTopic;
}

void GraduateStudent::setInternshipPeriod(std::string internshipPeriod) {
    this->internshipPeriod = internshipPeriod;
}

void GraduateStudent::setDefenseDate(std::string defenseDate) {
    this->defenseDate = defenseDate;
}

void GraduateStudent::setProgressStatus(State progressStatus) {
    this->progressStatus = progressStatus;
}

// Методи для читання значень полів
std::string GraduateStudent::getThesisTopic() const {
    return thesisTopic;
}

std::string GraduateStudent::getInternshipPeriod() const {
    return internshipPeriod;
}

std::string GraduateStudent::getDefenseDate() const {
    return defenseDate;
}

State GraduateStudent::getProgressStatus() const {
    return progressStatus;
}

std::ostream& operator<<(std::ostream& out, const State& state) {
    switch (state) {
    case State::Agreement:
        out << "Agreement";
        break;
    case State::InProgres:
        out << "In Progress";
        break;
    case State::Review:
        out << "Review";
        break;
    case State::Admitted:
        out << "Admitted";
        break;
    case State::Protected:
        out << "Protected";
        break;
    }
    return out;
}

std::istream& operator>>(std::istream& in, State& state) {
    std::string input;
    bool validInput = false;
    do {
        std::cout << "Enter Progress Status (Agreement(1), In Progress(2), Review(3), Admitted(4), Protected(5)): ";
        in >> input;
        if (input == "1") {
            state = State::Agreement;
            validInput = true;
        }
        else if (input == "2") {
            state = State::InProgres;
            validInput = true;
        }
        else if (input == "3") {
            state = State::Review;
            validInput = true;
        }
        else if (input == "4") {
            state = State::Admitted;
            validInput = true;
        }
        else if (input == "5") {
            state = State::Protected;
            validInput = true;
        }
        else {
            std::cout << "Invalid input. Please enter a valid progress status.\n";
        }
    } while (!validInput);
    return in;
}

// Перевизначення операторів виведення та введення
std::ostream& operator<<(std::ostream& out, const GraduateStudent& gradStudent) {
    out << static_cast<const Student&>(gradStudent); // Виводимо дані про студента
    out << "Thesis Topic: " << gradStudent.thesisTopic << "\n";
    out << "Internship Period: " << gradStudent.internshipPeriod << "\n";
    out << "Defense Date: " << gradStudent.defenseDate << "\n";
    out << "Progress Status: " << gradStudent.progressStatus << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, GraduateStudent& gradStudent) {
    Student& student = gradStudent; // Переведення до класу Student для зручності введення
    in >> student; // Введення даних про студента
    std::cout << "Enter Thesis Topic: ";
    in >> gradStudent.thesisTopic;
    std::cout << "Enter Internship Period: ";
    in >> gradStudent.internshipPeriod;
    std::cout << "Enter Defense Date: ";
    in >> gradStudent.defenseDate;
    std::cout << "Enter Progress Status: ";
    in >> gradStudent.progressStatus;
    return in;
}

void GraduateStudent::print() const {
    Student::print(); // Виклик методу базового класу
    std::cout << "Thesis Topic: " << thesisTopic << "\n";
    std::cout << "Internship Period: " << internshipPeriod << "\n";
    std::cout << "Defense Date: " << defenseDate << "\n";
    std::cout << "Progress Status: " << progressStatus << "\n";
}

