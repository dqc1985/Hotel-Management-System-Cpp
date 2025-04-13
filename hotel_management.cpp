#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Enum for menu options
enum MenuOption { BOOK = 1, VIEW, CANCEL, EXIT };

class Hotel {
private:
    vector<string> bookedRooms;

public:
    void bookRoom() {
        string guestName;
        cout << "Enter guest name: ";
        cin.ignore();
        getline(cin, guestName);
        bookedRooms.push_back(guestName);
        cout << "Room successfully booked for " << guestName << "!\n";
    }

    void viewBookings() {
        cout << "\nBooked Rooms:\n";
        if (bookedRooms.empty()) {
            cout << "No rooms have been booked yet.\n";
        } else {
            for (size_t i = 0; i < bookedRooms.size(); ++i) {
                cout << i + 1 << ". " << bookedRooms[i] << endl;
            }
        }
    }

    void cancelBooking() {
        if (bookedRooms.empty()) {
            cout << "No bookings to cancel.\n";
            return;
        }

        string name;
        cout << "Enter guest name to cancel: ";
        cin.ignore();
        getline(cin, name);

        bool found = false;
        for (auto it = bookedRooms.begin(); it != bookedRooms.end(); ++it) {
            if (*it == name) {
                bookedRooms.erase(it);
                cout << "Booking canceled for " << name << ".\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No booking found under the name: " << name << ".\n";
        }
    }
};

int main() {
    Hotel hotel;
    int choice;

    do {
        cout << "\n--- Hotel Management System ---\n";
        cout << "1. Book a Room\n";
        cout << "2. View Booked Rooms\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case BOOK:
                hotel.bookRoom();
                break;
            case VIEW:
                hotel.viewBookings();
                break;
            case CANCEL:
                hotel.cancelBooking();
                break;
            case EXIT:
                cout << "Thank you for using the Hotel Management System!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != EXIT);

    return 0;
}
