#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char name[50];
    char destination[30];
    char seatClass[10];
} Ticket;

Ticket tickets[MAX];
int count = 0;

void bookTicket() {
    if (count >= MAX) {
        printf("All seats booked!\n");
        return;
    }
    tickets[count].id = count + 1;
    printf("Enter passenger name: ");
    scanf("%s", tickets[count].name);
    printf("Enter destination: ");
    scanf("%s", tickets[count].destination);
    printf("Enter seat class (Economy/Business): ");
    scanf("%s", tickets[count].seatClass);
    printf("Ticket booked! Ticket ID: %d\n", tickets[count].id);
    count++;
}

void viewTickets() {
    if (count == 0) {
        printf("No tickets booked yet.\n");
        return;
    }
    printf("Booked Tickets:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Destination: %s, Class: %s\n",
            tickets[i].id, tickets[i].name, tickets[i].destination, tickets[i].seatClass);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Airplane Ticket Reservation ---\n");
        printf("1. Book Ticket\n2. View Tickets\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: bookTicket(); break;
            case 2: viewTickets(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
