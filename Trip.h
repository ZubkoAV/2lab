#pragma once
#ifndef TRIP_H
#define TRIP_H

#include <string>
#include <iostream>

// ������� ���� ��� ������� ���������
class Trip {
public:
    // ����������� � �'����� ����������� ��� ������������ �������� ��������� �������� ����� (����� 5)
    Trip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type, const std::string& transport_type);

    // ³��������� ���������� ��� ���������� ������ � ����� (����� 8)
    virtual ~Trip();

    // ������ �������� �����
    virtual double CalculateTotalCost() const;
    void DisplayTripDetails() const;

protected: // ��������� ������ �� ���� ����� �������� ����� (����� 2)
    std::string destination_;
    double base_cost_;
    bool insurance_;
    std::string accommodation_type_;
    std::string transport_type_;
};

// �������� ���� StudentTrip ��� ��������� �������� ��������
class StudentTrip : public Trip {
public:
    // ����������� ��� ����� StudentTrip
    StudentTrip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type,
        const std::string& transport_type, int student_id, double group_discount);

    // �������������� ������ ��� ��������� ������
    double CalculateTotalCost() const override;

private:
    int student_id_;
    double group_discount_;
};

// ���� GroupTrip ��� �������� ������ �������� (����� 3)
class GroupTrip : private StudentTrip {
public:
    GroupTrip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type,
        const std::string& transport_type, int group_size, double group_discount);

    void DisplayGroupDetails() const;

private:
    int group_size_;
};

// �������� ���� � ������������� ��������� ������������
class InsuredTrip : public Trip {
public:
    InsuredTrip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type,
        const std::string& transport_type, double insurance_fee);

    double CalculateTotalCost() const override;

private:
    double insurance_fee_;
};

// �������� ������������: ���� LongDistanceTrip � ������� StudentTrip �� InsuredTrip (����� 4)
class LongDistanceTrip : public StudentTrip, public InsuredTrip {
public:
    LongDistanceTrip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type,
        const std::string& transport_type, int student_id, double group_discount, double insurance_fee);

    void DisplayCompleteTripDetails() const;
};

#endif // TRIP_H
