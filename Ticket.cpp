#include "Ticket.h"
#include <iostream> // Add this line to include the iostream header

using namespace std;
Ticket::Ticket() {
    ticketPrices[0][0] = 20.00; ticketPrices[0][1] = 30.00;
    ticketPrices[1][0] = 12.00; ticketPrices[1][1] = 18.00;
    ticketPrices[2][0] = 16.00; ticketPrices[2][1] = 24.00;
    ticketPrices[3][0] = 60.00; ticketPrices[3][1] = 90.00;
    ticketPrices[4][0] = 15.00; ticketPrices[4][1] = 22.50;

    ticketTypes[0] = "Adult";
    ticketTypes[1] = "Child";
    ticketTypes[2] = "Senior";
    ticketTypes[3] = "Family";
    ticketTypes[4] = "Group";

    attractions[0] = "Lion Feeding";
    attractions[1] = "Penguin Feeding";
    attractions[2] = "Evening Barbecue (two-day tickets only)";

    attractionPrices[0] = 2.50;
    attractionPrices[1] = 2.00;
    attractionPrices[2] = 5.00;
}

void Ticket::displayOptions(bool isTwoDay) const {
    cout << "Ticket Options:\n";
    cout << "----------------\n";

    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << ". " << ticketTypes[i] << " - $" << (isTwoDay ? ticketPrices[i][1] : ticketPrices[i][0]);
        if (isTwoDay) {
            cout << " (Two days)";
        }
        cout << endl;
    }

    cout << "\nExtra Attractions:\n";
    cout << "----------------\n";
    
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << ". " << attractions[i] << " - $" << attractionPrices[i] << endl;
    }

    cout << "----------------\n";
}

double Ticket::calculateCost(int ticketType, int numTickets, bool isTwoDay) const {
    if (ticketType >= 1 && ticketType <= 5) {
        int index = ticketType - 1;
        double price = isTwoDay ? ticketPrices[index][1] : ticketPrices[index][0];
        return price * numTickets;
    }
    return 0.0; 
}

string Ticket::getTicketType(int index) const {
    if (index >= 0 && index < 5) {
        return ticketTypes[index];
    }
    return "Invalid index";
}

string Ticket::getAttraction(int index) const {
    if (index >= 0 && index < 3) {
        return attractions[index];
    }
    return "Invalid index";
}

double Ticket::getAttractionPrice(int index) const {
    if (index >= 0 && index < 3) {
        return attractionPrices[index];
    }
    return 0.0; 
    
}
