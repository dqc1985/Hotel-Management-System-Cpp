#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Hotel {
private:
    vector<string> bookedRooms;

public:
    void bookRoom() {
        string guestName;
        cout << "Enter guest name: ";
        cin.ignore();  // Clear input buffer
        getline(cin, guestName);

        bookedRooms.push_back(guestName);
        cout << "Room successfully booked for " << guestName << "!" << endl;
    }

    void viewBookings() {
        cout << "\nBooked Rooms:" << endl;
        if (bookedRooms.empty()) {
            cout << "No rooms have been booked yet." << endl;
        } else {
            for (size_t i = 0; i < bookedRooms.size(); ++i) {
                cout << i + 1 << ". " << bookedRooms[i] << endl;
            }
        }
    }
};

int main() {
    Hotel hotel;
    int choice;

    do {
        cout << "\n--- Hotel Management System ---" << endl;
        cout << "1. Book a Room" << endl;
        cout << "2. View Booked Rooms" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.bookRoom();
            break;
            case 2:
                hotel.viewBookings();
            break;
            case 3:
                cout << "Thank you for using the Hotel Management System!" << endl;
            break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
