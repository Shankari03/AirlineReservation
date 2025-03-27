#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS 100
#define MAX_CUSTOMERS 100

typedef struct {
    int flight_id;
    char destination[50];
    char departure[50];
    char time[10];
    float price;
} Flight;

typedef struct {
    int booking_id;
    int flight_id;
    char customer_name[50];
    int paid;
} Reservation;

Flight flights[MAX_FLIGHTS];
Reservation reservations[MAX_CUSTOMERS];
int flight_count = 0, reservation_count = 0;

void addFlight() {
    if (flight_count < MAX_FLIGHTS) {
        printf("Enter Flight ID: ");
        scanf("%d", &flights[flight_count].flight_id);
        printf("Enter Departure: ");
        scanf("%s", flights[flight_count].departure);
        printf("Enter Destination: ");
        scanf("%s", flights[flight_count].destination);
        printf("Enter Time: ");
        scanf("%s", flights[flight_count].time);
        printf("Enter Price: ");
        scanf("%f", &flights[flight_count].price);
        flight_count++;
        printf("Flight added successfully!\n");
    } else {
        printf("Flight list is full!\n");
    }
}

void deleteFlight() {
    int id, i, found = 0;
    printf("Enter Flight ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < flight_count; i++) {
        if (flights[i].flight_id == id) {
            found = 1;
            for (int j = i; j < flight_count - 1; j++) {
                flights[j] = flights[j + 1];
            }
            flight_count--;
            printf("Flight deleted successfully!\n");
            break;
        }
    }
    if (!found) printf("Flight not found!\n");
}

void modifyFlight() {
    int id, i, found = 0;
    printf("Enter Flight ID to modify time: ");
    scanf("%d", &id);
    for (i = 0; i < flight_count; i++) {
        if (flights[i].flight_id == id) {
            found = 1;
            printf("Enter new time: ");
            scanf("%s", flights[i].time);
            printf("Flight time updated successfully!\n");
            break;
        }
    }
    if (!found) printf("Flight not found!\n");
}

void viewFlights() {
    printf("\nAvailable Flights:\n");
    printf("------------------------------------------------------------\n");
    printf("| ID  | Departure  | Destination  | Time    | Price       |\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < flight_count; i++) {
        printf("| %-3d | %-10s | %-12s | %-7s | %-10.2f |\n",
               flights[i].flight_id, flights[i].departure, flights[i].destination, flights[i].time, flights[i].price);
    }
    printf("------------------------------------------------------------\n");
}

void bookTicket() {
    if (reservation_count < MAX_CUSTOMERS) {
        printf("Enter Flight ID: ");
        scanf("%d", &reservations[reservation_count].flight_id);
        printf("Enter Your Name: ");
        scanf("%s", reservations[reservation_count].customer_name);
        reservations[reservation_count].booking_id = reservation_count + 1;
        reservations[reservation_count].paid = 0;
        reservation_count++;
        printf("Booking successful! Your Booking ID: %d\n", reservation_count);
    } else {
        printf("No more reservations can be made!\n");
    }
}

void cancelReservation() {
    int id, i, found = 0;
    printf("Enter Booking ID to cancel: ");
    scanf("%d", &id);
    for (i = 0; i < reservation_count; i++) {
        if (reservations[i].booking_id == id) {
            found = 1;
            for (int j = i; j < reservation_count - 1; j++) {
                reservations[j] = reservations[j + 1];
            }
            reservation_count--;
            printf("Reservation cancelled successfully!\n");
            break;
        }
    }
    if (!found) printf("Reservation not found!\n");
}

void payForTicket() {
    int id, i, found = 0;
    printf("Enter Booking ID to pay: ");
    scanf("%d", &id);
    for (i = 0; i < reservation_count; i++) {
        if (reservations[i].booking_id == id) {
            found = 1;
            reservations[i].paid = 1;
            printf("Payment successful!\n");
            break;
        }
    }
    if (!found) printf("Booking ID not found!\n");
}

int main() {
    int choice, role;
    while (1) {
        printf("\nChoose Role: 1. Admin 2. Customer 3. Exit\n");
        scanf("%d", &role);
        if (role == 3) break;
        
        if (role == 1) { // Admin
            while (1) {
                printf("\nAdmin Menu:\n1. Add Flight\n2. Delete Flight\n3. Modify Flight Time\n4. View Flights\n5. Logout\n");
                scanf("%d", &choice);
                if (choice == 5) break;
                switch (choice) {
                    case 1: addFlight(); break;
                    case 2: deleteFlight(); break;
                    case 3: modifyFlight(); break;
                    case 4: viewFlights(); break;
                    default: printf("Invalid choice!\n");
                }
            }
        } else if (role == 2) { // Customer
            while (1) {
                printf("\nCustomer Menu:\n1. Book Ticket\n2. Cancel Reservation\n3. Pay for Ticket\n4. View Flights\n5. Logout\n");
                scanf("%d", &choice);
                if (choice == 5) break;
                switch (choice) {
                    case 1: bookTicket(); break;
                    case 2: cancelReservation(); break;
                    case 3: payForTicket(); break;
                    case 4: viewFlights(); break;
                    default: printf("Invalid choice!\n");
                }
            }
        } else {
            printf("Invalid role!\n");
        }
    }
    return 0;
}