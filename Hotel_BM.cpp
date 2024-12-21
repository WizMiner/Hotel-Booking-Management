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
/**
 *Function to add a room to the hotel database
 */
void addRoom()
{
    Room newRoom;
    cout << "Enter Room Number: ";
    cin >> newRoom.roomNumber;
    cout << "Enter Room Type (Single/Double/Suite): ";
    cin >> newRoom.roomType;
    newRoom.isAvailable = true; // Room is available by default
    rooms.push_back(newRoom);
    cout << "Room added successfully!" << endl;
}

/**
 *Function to book a room in the hotel database
 */
void bookRoom()
{
    Booking newBooking;
    cout << "Enter Booking ID: ";
    cin >> newBooking.bookingID;
    cout << "Enter Customer Name: ";
    cin >> newBooking.customerName;
    cout << "Enter Room Number: ";
    cin >> newBooking.roomNumber;
    cout << "Enter Check-in Date (YYYY-MM-DD): ";
    cin >> newBooking.checkInDate;
    cout << "Enter Check-out Date (YYYY-MM-DD): ";
    cin >> newBooking.checkOutDate;

    // Check Room Availability
    for (auto &room : rooms)
    {
        if (room.roomNumber == newBooking.roomNumber)
        {
            if (room.isAvailable)
            {
                room.isAvailable = false; // Mark room as booked
                bookings.push_back(newBooking);
                cout << "Room booked successfully!" << endl;
                return;
            }
            else
            {
                cout << "Room is not available!" << endl;
                return;
            }
        }
    }
    cout << "Room not found!" << endl;
}

/**
 *Function to cancel a booking in the hotel database
 */
void cancelBooking()
{
    int bookingID;
    cout << "Enter Booking ID to cancel: ";
    cin >> bookingID;

    // Find the booking to cancel
    for (size_t i = 0; i < bookings.size(); i++)
    {
        if (bookings[i].bookingID == bookingID)
        {

            // Mark Room as Available
            for (auto &room : rooms)
            {
                if (room.roomNumber == bookings[i].roomNumber)
                {
                    room.isAvailable = true;
                }
            }

            // Remove booking
            bookings.erase(bookings.begin() + i);
            cout << "Booking cancelled successfully!" << endl;
            return;
        }
    }

    // Booking ID not found
    cout << "Booking ID not found!" << endl;
}
/**
 *Function to check if a room is available
 */
void viewBookings()
{
    if (bookings.empty())
    {
        cout << "No bookings available!" << endl;
        return;
    }

    cout << "\n--- Current Bookings ---" << endl;
    for (const auto &booking : bookings)
    {
        cout << "Booking ID: " << booking.bookingID << ", Customer: " << booking.customerName
             << ", Check-out: " << booking.checkOutDate << endl;
    }
}

/**
 *Function to manage notifications in the hotel database
 *Implement Stack and Queue Functions
 *For storing and handling notifications.
 */
stack<string> notifications;

void manageNotifications()
{
    int choice;
    cout << "\n1. Add Notification\n2. View and Remove Notification\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        // Add a new notification
        string notification;
        cout << "Enter notification: ";
        cin.ignore();
        getline(cin, notification);
        notifications.push(notification);
        cout << "Notification added!" << endl;
    }
    else if (choice == 2)
    {
        if (notifications.empty())
        {
            // No notifications to display
            cout << "No notifications to display!" << endl;
        }
        else
        {
            // View and remove the top notification
            cout << "Notification: " << notifications.top() << endl;
            notifications.pop();
            cout << "Notification removed!" << endl;
        }
    }
    else
    {
        // Invalid choice
        cout << "Invalid choice!" << endl;
    }
}


/**
 *Function to manage requests in the hotel database
 *Implement Stack and Queue Functions
 *For storing and handling requests.
 */
queue<string> requests;

void manageRequests()
{
    int choice;
    cout << "\n1. Add Request\n2. Process Request\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        string request;
        cout << "Enter request: ";
        cin.ignore();
        getline(cin, request);
        requests.push(request);
        cout << "Request added!" << endl;
    }
    else if (choice == 2)
    {
        if (requests.empty())
        {
            cout << "No requests to process!" << endl;
        }
        else
        {
            // Process the request
            cout << "Processing request: " << requests.front() << endl;
            requests.pop();
            cout << "Request processed!" << endl;
        }
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }
}
