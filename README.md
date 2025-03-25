Airline Reservation System

AIM:

To develop a C program to perform Airline Ticket Booking System using structure.

ABSRACT:

•	The Airline Reservations System (ARS) is a software application designed to streamline and optimize the process of airline ticket booking. 
•	Developed using the C programming language, this system is user-friendly for passengers and airline staff, enhancing the efficiency of booking, seat availability, flight details and ticket management tasks.
•	Passengers can choose their desired flights based on their preferences and easily secure seats on their selected flights.
•	Personnel can access the system to update flight status, add new flights, and monitor seat occupancy.
•	In conclusion, the Airline Reservations System implemented in C language offers a reliable and efficient for managing airline ticket bookings and reservations. The ARS contributes to a seamless and satisfying experience for both passengers and airline operators.

ALGORITHM:

•	Start the program by including the necessary header files. (stdio.h, conio.h)
•	Define maximum number of flights, seats and name of the flights[length] inside a structure using ‘typedef’ keyword.( Flights )
•	Get flight number, destination, departure and number of seats using the structure name Flights.
•	Define flight number, passport number and passenger name inside a structure using ‘typedef’. ( Reservation )
•	Get flight number, passport number and passenger name using structure named Reservations.
•	Declare structure variables.
•	Add function calls for functions for adding a flight, displaying the flight details, making reservation, and an logout or exit function.
•	Create a welcome page and thankyou page using functions.
•	Main program: ‘int main()’.
•	Inside the main program get the user’s choice whether to add flight, book tickets, or display flights or exit.
•	Use ‘SWITCH’ case for choice, and inside each case give or call the corresponding function.
•	Run the program.
•	Give the necessary details to add flight and  book the ticket.
•	Finally, after booking ticket logout using corresponding function call.
•	Print the results.
•	Stop the program. 

FUNCTIONS:

1.	void welcome();
Shows the welcome page of the airline.
2.	void addFlight();
This function adds a new flight to the system. It gets the flight number, destination, departure and seats availability.
3.	void displayFlights();
Display the details of the flights which were given during addFlight() process.
4.	void makeReservation();
This function is used to make reservation or book the ticket by providing flight number and passengers details.
5.	void thank();
This function holds the thank you page of the airline system.

STRUCTURE:

1.	struct Flights –   Holds variables flight number, destination, departure and seats availability. This is used for adding flights.
2.	Struct Reservation –   Holds variables like flight number, passport number and passenger name. this is used for making reservations.
