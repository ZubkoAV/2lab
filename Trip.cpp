#include "Trip.h"

// Ініціалізація конструктора базового класу (пункт 5)
Trip::Trip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type, const std::string& transport_type)
    : destination_(destination), base_cost_(base_cost), insurance_(insurance), accommodation_type_(accommodation_type), transport_type_(transport_type) {
    std::cout << "Trip constructed\n";
}

Trip::~Trip() {
    std::cout << "Trip destroyed\n";
}

double Trip::CalculateTotalCost() const {
    return base_cost_ + (insurance_ ? 50 : 0);
}

void Trip::DisplayTripDetails() const {
    std::cout << "Destination: " << destination_ << ", Cost: $" << CalculateTotalCost() << "\n";
}

// Реалізація StudentTrip
StudentTrip::StudentTrip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type,
    const std::string& transport_type, int student_id, double group_discount)
    : Trip(destination, base_cost, insurance, accommodation_type, transport_type), student_id_(student_id), group_discount_(group_discount) {
    std::cout << "StudentTrip constructed\n";
}

double StudentTrip::CalculateTotalCost() const {
    double cost = Trip::CalculateTotalCost();
    return cost * (1 - group_discount_);
}

// Реалізація GroupTrip з закритим успадкуванням (пункт 3)
GroupTrip::GroupTrip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type,
    const std::string& transport_type, int group_size, double group_discount)
    : StudentTrip(destination, base_cost, insurance, accommodation_type, transport_type, 0, group_discount), group_size_(group_size) {
    std::cout << "GroupTrip constructed\n";
}

void GroupTrip::DisplayGroupDetails() const {
    DisplayTripDetails();  // Використання методу базового класу
    std::cout << "Group Size: " << group_size_ << "\n";
}

// Реалізація InsuredTrip для додаткового страхування
InsuredTrip::InsuredTrip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type,
    const std::string& transport_type, double insurance_fee)
    : Trip(destination, base_cost, insurance, accommodation_type, transport_type), insurance_fee_(insurance_fee) {
    std::cout << "InsuredTrip constructed\n";
}

double InsuredTrip::CalculateTotalCost() const {
    return Trip::CalculateTotalCost() + insurance_fee_;
}

// Реалізація LongDistanceTrip з множинним успадкуванням (пункт 4)
LongDistanceTrip::LongDistanceTrip(const std::string& destination, double base_cost, bool insurance, const std::string& accommodation_type,
    const std::string& transport_type, int student_id, double group_discount, double insurance_fee)
    : StudentTrip(destination, base_cost, insurance, accommodation_type, transport_type, student_id, group_discount),
    InsuredTrip(destination, base_cost, insurance, accommodation_type, transport_type, insurance_fee) {
    std::cout << "LongDistanceTrip constructed\n";
}

void LongDistanceTrip::DisplayCompleteTripDetails() const {
    Trip::DisplayTripDetails();  // Виклик методу базового класу
    std::cout << "Complete trip with insurance fee: $" << InsuredTrip::CalculateTotalCost() << "\n";
}
