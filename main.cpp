#include "Trip.h"

int main() {
    // Створення об’єктів для демонстрації конструктора з параметрами (пункт 5)
    Trip basicTrip("Kyiv", 200, true, "hostel", "bus");
    basicTrip.DisplayTripDetails();

    // Створення об’єкта StudentTrip
    StudentTrip studentTrip("Odessa", 300, false, "hotel", "train", 12345, 0.1);
    studentTrip.DisplayTripDetails();

    // Створення об’єкта GroupTrip для демонстрації закритого наслідування (пункт 3)
    GroupTrip groupTrip("Lviv", 400, true, "hotel", "bus", 5, 0.15);
    groupTrip.DisplayGroupDetails();

    // Використання InsuredTrip для додаткового страхування
    InsuredTrip insuredTrip("Kharkiv", 250, true, "hostel", "bus", 30);
    insuredTrip.DisplayTripDetails();

    // Множинне наслідування з LongDistanceTrip (пункт 4)
    LongDistanceTrip longTrip("Poltava", 350, true, "hotel", "train", 67890, 0.2, 30);
    longTrip.DisplayCompleteTripDetails();
    std::cin.get();
    return 0;
}
