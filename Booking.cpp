#include "Booking.h"
#include "Ticket.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

Booking::Booking() {
    bookingNumber = generateBookingNumber();
}

int Booking::generateBookingNumber() const {
    srand(time(0));
    return rand() % (9999 - 1000 + 1) + 1000;
}

void Booking::askTicketDetails(int& ticketType, int& numTickets, bool& isTwoDay) {
   
    while (true) {
        cout << "Enter the ticket type (1-5, enter 0 to see ticket options again): ";
        cin >> ticketType;
        if (ticketType == 0) {
            Ticket ticket;
            ticket.displayOptions(false); 
        } else if (ticketType < 1 || ticketType > 5) {
            cout << "Error: Invalid ticket type. Please enter a value between 1 and 5." << endl;
        } else {
            break; 
        }
    }

    cout << "Enter the number of tickets: ";
    cin >> numTickets;

    while (true) {
        cout << "Is it a two-day visit? (0 for No / 1 for Yes): ";
        cin >> isTwoDay;
        if (isTwoDay != 0 && isTwoDay != 1) {
            cout << "Error: Invalid input for visit duration. Please enter 0 for No or 1 for Yes." << endl;
        } else {
            break; 
        }
    }
}

int Booking::askAttractionChoice() {
    int attractionChoice;
    cout << "Select an attraction:\n";
    cout << "1. Lion Feeding\n";
    cout << "2. Penguin Feeding\n";
    cout << "3. Evening Barbecue\n";
    cout << "Enter the attraction number (1-3): ";
    cin >> attractionChoice;
    if (attractionChoice < 1 || attractionChoice > 3) {
        cout << "Error: Invalid attraction choice. Please enter a value between 1 and 3." << endl;
        askAttractionChoice();
    }

    return attractionChoice;
}

bool Booking::askIncludeAttraction() {
    char choice;
    cout << "Do you want to include any attractions? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}



void Booking::processBooking() {
    Ticket ticket;
    int ticketType, numTickets, numAttractions;
    bool isTwoDay, includeAttraction;
    int groupSize = 0; 
    askTicketDetails(ticketType, numTickets, isTwoDay);

    if (ticketType == 5) {
        do {
            cout << "Enter the number of people in the group (minimum 6): ";
            cin >> groupSize;
            if (groupSize < 6) {
                cout << "Error: Group size must be at least 6. Please try again." << endl;
            }
        } while (groupSize < 6);
    }

    includeAttraction = askIncludeAttraction();

    if (includeAttraction) {

        if (isTwoDay || numAttractions < 3) {
            cout << "Select an attraction:\n";
            cout << "1. Lion Feeding\n";
            cout << "2. Penguin Feeding\n";
            if (isTwoDay) {
                cout << "3. Evening Barbecue\n";
            }
            cout << "Enter the attraction number (1-";
            if (isTwoDay) {
                cout << "3";
            } else {
                cout << "2";
            }
            cout << "): ";
            cin >> numAttractions;

            if ((isTwoDay && (numAttractions < 1 || numAttractions > 3)) ||
                (!isTwoDay && (numAttractions < 1 || numAttractions > 2))) {
                cerr << "Error: Invalid attraction selection. ";
                if (isTwoDay) {
                    cerr << "Please enter a value between 1 and 3." << endl;
                } else {
                    cerr << "For one-day visits, please enter a value between 1 and 2." << endl;
                }
                return; 
            }
        }
    }

    double totalCost = calculateTotalCost(ticketType, numTickets, isTwoDay, includeAttraction, numAttractions, groupSize);

    cout << "\nBooking Details\n";
    cout << "----------------\n";
    cout << "Booking Number: " << bookingNumber << endl;
    cout << "Ticket Type: " << ticket.getTicketType(ticketType - 1) << endl;
    cout << "Number of Tickets: " << numTickets << endl;
    if (ticketType == 5) {
        cout << "Group Size: " << groupSize << endl;
    }
    cout << "Visit Duration: " << (isTwoDay ? "Two days" : "One day") << endl;
    if (includeAttraction) {
        cout << "Attractions Included: Yes" << endl;
        cout << "Selected Attraction: ";
        if (numAttractions == 1) {
            cout << "Lion Feeding";
        } else if (numAttractions == 2) {
            cout << "Penguin Feeding";
        } else if (numAttractions == 3) {
            cout << "Evening Barbecue";
        }
        cout << endl;
    } else {
        cout << "Attractions Included: No" << endl;
    }
    cout << "Total Cost: $" << fixed << setprecision(2) << totalCost << endl;
    cout << "----------------\n";
}
double Booking::calculateTotalCost(int ticketType, int numTickets, bool isTwoDay, bool includeAttraction, int attractionChoice, int groupSize) const {
    Ticket ticket;
    double totalCost = 0.0;

    if (ticketType != 5) {
        totalCost = ticket.calculateCost(ticketType, numTickets, isTwoDay);
    } else {
        double baseCost = ticket.calculateCost(ticketType, 1, isTwoDay);
        totalCost = baseCost * numTickets * groupSize;
    }

    if (includeAttraction) {
        switch (attractionChoice) {
            case 1:
                totalCost += ticket.getAttractionPrice(0);
                break;
            case 2:
                totalCost += ticket.getAttractionPrice(1);
                break;
            case 3:
                totalCost += ticket.getAttractionPrice(2); 
                break;
            default:
                cerr << "Error: Invalid attraction choice." << endl;
        }
    }

    return totalCost;
}

