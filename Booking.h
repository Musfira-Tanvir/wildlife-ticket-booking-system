class Booking {
public:
    Booking();
    void processBooking();
private:
    void askTicketDetails(int& ticketType, int& numTickets, bool& isTwoDay);
    int generateBookingNumber() const;
    bool askIncludeAttraction();
    int askAttractionChoice();
    int findBestValueOption(int ticketType, bool isTwoDay, bool includeAttraction, int numAttractions, int groupSize) const;
    double calculateTotalCost(int ticketType, int numTickets, bool isTwoDay, bool includeAttraction, int attractionChoice, int groupSize) const;
    int bookingNumber;
};