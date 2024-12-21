#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// Structure for Room
struct Room
{
    int roomNumber;
    string roomType;
    bool isAvailable;
};

// Structure for Customer
struct Customer
{
    string name;
    string contactNumber;
};

// Structure for Booking
struct Booking
{
    int bookingID;
    string customerName;
    int roomNumber;
    string checkInDate;
    string checkOutDate;
};

// Global Vectors for Storage
vector<Room> rooms;
vector<Customer> customers;
vector<Booking> bookings;

// Main Menu Function
void displayMenu()
{
    cout << "\n--- Hotel Booking System ---" << endl;
    cout << "1. Add Room" << endl;
    cout << "2. Book Room" << endl;
    cout << "3. Cancel Booking" << endl;
    cout << "4. View Bookings" << endl;
    cout << "5. Manage Notifications (Stack)" << endl;
    cout << "6. Manage Requests (Queue)" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function Prototypes
void addRoom();
void bookRoom();
void cancelBooking();
void viewBookings();
void manageNotifications();
void manageRequests();

// Main Function
int main()
{
    int choice;
    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            addRoom();
            break;
        case 2:
            bookRoom();
            break;
        case 3:
            cancelBooking();
            break;
        case 4:
            viewBookings();
            break;
        case 5:
            manageNotifications();
            break;
        case 6:
            manageRequests();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again!" << endl;
        }
    } while (choice != 0);

    return 0;
}
