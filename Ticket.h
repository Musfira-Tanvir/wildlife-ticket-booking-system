
#include <string>
using namespace std;
class Ticket {
    double ticketPrices[5][2];
    string ticketTypes[5];
    string attractions[3];
    double attractionPrices[3];

public:
    Ticket();
    void displayOptions(bool isTwoDay) const;
    double calculateCost(int ticketType, int numTickets, bool isTwoDay) const;
    string getTicketType(int index) const;
    string getAttraction(int index) const;
    double getAttractionPrice(int index) const;
};