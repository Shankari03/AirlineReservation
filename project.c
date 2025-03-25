#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_FLIGHTS 10
#define MAX_SEATS 200
#define MAX_NAME_LENGTH 50

typedef struct {
    int flightNumber;
    char destination[MAX_NAME_LENGTH];
    char departure[MAX_NAME_LENGTH];
    int totalSeats;
    int availableSeats;
} Flight;

typedef struct {
    int flightNumber;
    long int passportNumber;
    char passengerName[MAX_NAME_LENGTH];
} Reservation;

// Arrays to store flights and reservations
Flight flights[MAX_FLIGHTS];
Reservation reservations[MAX_SEATS];

int numFlights = 0;
int numReservations = 0;

// Function prototypes
void addFlight();
void displayFlights();
void makeReservation();
void welcome();
void thank();

int main() {
    int choice;

    welcome();

    do {
        printf("\n\nAirline Ticket Booking System\n");
        printf("1. Add Flight\n");
        printf("2. Display Flights\n");
        printf("3. Make Reservation\n");
        printf("4. LOG OUT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf

        switch (choice) {
            case 1:
                system("cls");  // Use "clear" for Linux/Mac
                addFlight();
                break;
            case 2:
                system("cls");
                displayFlights();
                break;
            case 3:
                system("cls");
                makeReservation();
                break;
            case 4:
                system("cls");
                thank();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addFlight() {
    if (numFlights >= MAX_FLIGHTS) {
        printf("\nMaximum number of flights reached.\n");
        return;
    }

    Flight newFlight;

    printf("\nEnter Flight Number: ");
    scanf("%d", &newFlight.flightNumber);
    getchar();

    printf("Enter Destination: ");
    scanf("%49s", newFlight.destination);

    printf("Enter Departure: ");
    scanf("%49s", newFlight.departure);

    printf("Enter Total Seats: ");
    scanf("%d", &newFlight.totalSeats);

    newFlight.availableSeats = newFlight.totalSeats;
    flights[numFlights++] = newFlight;

    printf("Flight added successfully!\n");
}

void displayFlights() {
    system("cls");

    if (numFlights == 0) {
        printf("No flights found.\n");
        return;
    }

    printf("\nFlight List:\n");
    printf("---------------------------------------------------------\n");
    printf("Flight\tDestination\tDeparture\tAvailable Seats\n");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < numFlights; i++) {
        printf("%d\t%s\t\t%s\t\t%d/%d\n",
               flights[i].flightNumber, flights[i].destination,
               flights[i].departure, flights[i].availableSeats,
               flights[i].totalSeats);
    }

    printf("---------------------------------------------------------\n");
}

void makeReservation() {
    int flightNumber;
    int flightIndex = -1;

    system("cls");
    displayFlights();

    if (numFlights == 0) {
        printf("No flights available for reservation.\n");
        return;
    }

    printf("\nEnter Flight Number for Reservation: ");
    scanf("%d", &flightNumber);

    for (int i = 0; i < numFlights; i++) {
        if (flights[i].flightNumber == flightNumber) {
            flightIndex = i;
            break;
        }
    }

    if (flightIndex == -1) {
        printf("Flight with number %d not found.\n", flightNumber);
        return;
    }

    if (flights[flightIndex].availableSeats <= 0) {
        printf("Sorry, no available seats for this flight.\n");
        return;
    }

    if (numReservations >= MAX_SEATS) {
        printf("Maximum number of reservations reached.\n");
        return;
    }

    Reservation newReservation;
    newReservation.flightNumber = flightNumber;

    printf("\nEnter Passport Number: ");
    scanf("%ld", &newReservation.passportNumber);

    printf("Enter Passenger Name: ");
    scanf("%49s", newReservation.passengerName);

    flights[flightIndex].availableSeats--;
    reservations[numReservations++] = newReservation;

    printf("Reservation made successfully!\n");
}

void welcome() {
    printf("\n\n\n\n");
    printf("\n\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
    printf("\n\t  **    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=  **");
    printf("\n\t  **    =                                           =  **");
    printf("\n\t  **    =                WELCOME                   =  **");
    printf("\n\t  **    =                   TO                     =  **");
    printf("\n\t  **    =         AIRLINE TICKET SYSTEM            =  **");
    printf("\n\t  **    =                                           =  **");
    printf("\n\t  **    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=  **");
    printf("\n\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
}

void thank() {
    printf("\n\n\n\n\n\n");
    printf("\n\t\t******************************************");
    printf("\n\t\t**                                      **");
    printf("\n\t\t**           THANK YOU...!              **");
    printf("\n\t\t**                                      **");
    printf("\n\t\t**  EVERY TAKEOFF IS OPTIONAL...        **");
    printf("\n\t\t**  EVERY LANDING IS MANDATORY..!       **");
    printf("\n\t\t**                                      **");
    printf("\n\t\t******************************************\n");
}
