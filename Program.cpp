#include <iostream>
#include <limits> // Для очищення буфера вводу
#include "GraduateStudentContainer.h" // Включаємо клас контейнера студентів

int main() {
    GraduateStudentContainer container; // Створюємо об'єкт контейнера

    GraduateStudent student1("Doe", "John", "Smith", 1995, "Computer Science", "ABC University",
        "Advanced Algorithms", "6 months", "2024-12-01", State::InProgres); // Змінено "In Progress" на State::InProgres
    container.addStudent(student1);

    GraduateStudent student2("Smith", "Jane", "Doe", 1997, "Data Science", "XYZ University",
        "Big Data Analytics", "4 months", "2024-11-15", State::InProgres); // Змінено "In Progress" на State::InProgres
    container.addStudent(student2);

    int choice;
    do {
        std::cout << "\n========== Console Menu ==========\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display Students\n";
        std::cout << "3. Sort Students by Name\n";
        std::cout << "4. Sort Students by Birth Year\n";
        std::cout << "5. Filter Students by Progress Status\n";
        std::cout << "6. Exit\n";
        std::cout << "\n==================================\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Очищення буфера вводу
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            // Додавання студента
            std::string surname, name, patronymic, specialty, university, thesisTopic;
            int birthYear;
            std::string internshipPeriod, defenseDate;
            State progressStatus; // Додано State progressStatus

            std::cout << "Enter Surname: ";
            std::getline(std::cin, surname);
            std::cout << "Enter Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter Patronymic: ";
            std::getline(std::cin, patronymic);
            do {
                std::cout << "Enter Birth Year: ";
                std::cin >> birthYear;
                if (std::cin.fail() || birthYear >= 2024) {
                    std::cin.clear(); // Скидаємо флаг помилки вводу
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищуємо буфер вводу
                    std::cout << "Invalid input. Please enter a valid birth year less than or equal to 2024.\n";
                }
            } while (std::cin.fail() || birthYear >= 2024);
            std::cin.ignore(); // Очищення буфера вводу
            std::cout << "Enter Specialty: ";
            std::getline(std::cin, specialty);
            std::cout << "Enter University: ";
            std::getline(std::cin, university);
            std::cout << "Enter Thesis Topic: ";
            std::getline(std::cin, thesisTopic);
            std::cout << "Enter Internship Period: ";
            std::getline(std::cin, internshipPeriod);
            std::cout << "Enter Defense Date: ";
            std::getline(std::cin, defenseDate);
            std::cout << "Enter Progress Status (Agreement, InProgres, Review, Admitted, Protected): "; // Змінено "In Progress" на InProgres
            std::string status;
            std::getline(std::cin, status);
            if (status == "Agreement")
                progressStatus = State::Agreement;
            else if (status == "InProgres") 
                progressStatus = State::InProgres;
            else if (status == "Review")
                progressStatus = State::Review;
            else if (status == "Admitted")
                progressStatus = State::Admitted;
            else if (status == "Protected")
                progressStatus = State::Protected;
            else {
                std::cout << "Invalid progress status. Student not added.\n";
                break;
            }

            // Створення об'єкта студента та додавання його до контейнера
            GraduateStudent student(surname, name, patronymic, birthYear, specialty, university,
                thesisTopic, internshipPeriod, defenseDate, progressStatus);
            container.addStudent(student);
            break;
        }
        case 2: {
            // Виведення інформації про всіх студентів
            container.displayStudents();
            break;
        }
        case 3: {
            // Сортування студентів за ім'ям
            container.sortByName();
            std::cout << "Students sorted by name.\n";
            break;
        }
        case 4: {
            // Сортування студентів за роком народження
            container.sortByBirthYear();
            std::cout << "Students sorted by birth year.\n";
            break;
        }
        case 5: {
            // Фільтрація студентів за статусом виконання дипломної роботи
            std::string status;
            std::cout << "Enter progress status to filter by: ";
            std::getline(std::cin, status);
            State progressStatus;
            if (status == "Agreement")
                progressStatus = State::Agreement;
            else if (status == "InProgres") 
                progressStatus = State::InProgres;
            else if (status == "Review")
                progressStatus = State::Review;
            else if (status == "Admitted")
                progressStatus = State::Admitted;
            else if (status == "Protected")
                progressStatus = State::Protected;
            else {
                std::cout << "Invalid progress status. No filter applied.\n";
                break;
            }
            container.filterByProgressStatus(progressStatus);
            std::cout << "Students filtered by progress status.\n";
            break;
        }
        case 6: {
            std::cout << "Exiting the program.\n";
            break;
        }
        default: {
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    } while (choice != 6);

    return 0;
}
