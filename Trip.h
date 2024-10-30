#pragma once
#ifndef TRIP_H
#define TRIP_H

#include <string>
#include <iostream>

// Базовий клас для Системи Профспілка
class Trip {
public:
    // Конструктор з п'ятьма параметрами для демонстрації передачі параметрів базовому класу (пункт 5)
    Trip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type, const std::string& transport_type);

    // Віртуальний деструктор для відстеження виходу з блоку (пункт 8)
    virtual ~Trip();

    // Методи базового класу
    virtual double CalculateTotalCost() const;
    void DisplayTripDetails() const;

protected: // Захищений доступ до полів даних базового класу (пункт 2)
    std::string destination_;
    double base_cost_;
    bool insurance_;
    std::string accommodation_type_;
    std::string transport_type_;
};

// Похідний клас StudentTrip для управління поїздками студентів
class StudentTrip : public Trip {
public:
    // Конструктор для класу StudentTrip
    StudentTrip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type,
        const std::string& transport_type, int student_id, double group_discount);

    // Перевизначення методу для додавання знижки
    double CalculateTotalCost() const override;

private:
    int student_id_;
    double group_discount_;
};

// Клас GroupTrip для групових поїздок студентів (пункт 3)
class GroupTrip : private StudentTrip {
public:
    GroupTrip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type,
        const std::string& transport_type, int group_size, double group_discount);

    void DisplayGroupDetails() const;

private:
    int group_size_;
};

// Похідний клас з використанням закритого успадкування
class InsuredTrip : public Trip {
public:
    InsuredTrip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type,
        const std::string& transport_type, double insurance_fee);

    double CalculateTotalCost() const override;

private:
    double insurance_fee_;
};

// Множинне успадкування: Клас LongDistanceTrip з класами StudentTrip та InsuredTrip (пункт 4)
class LongDistanceTrip : public StudentTrip, public InsuredTrip {
public:
    LongDistanceTrip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type,
        const std::string& transport_type, int student_id, double group_discount, double insurance_fee);

    void DisplayCompleteTripDetails() const;
};

#endif // TRIP_H
