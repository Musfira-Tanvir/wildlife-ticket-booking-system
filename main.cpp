#include "Ticket.h"
#include "Booking.h"
#include <iostream>
using namespace std;

int main() {
    Ticket ticket;
    Booking booking;

    int choice;
    do {
        cout << "1. Display ticket options and attractions\n";
        cout << "2. Process a booking\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bool isTwoDay;
                cout << "Is it a two-day visit? (1 for Yes / 0 for No): ";
                cin >> isTwoDay;
                cout<<"Tickets are available on all 7 days"<<endl;
                ticket.displayOptions(isTwoDay);
                break;
            case 2:
                booking.processBooking();
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
