#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 200
#define MAX_STRING_LENGTH 50

// Structure to represent a date
typedef struct {
    int day;
    int month;
    int year;
} TDate;

// Structure to represent an address
typedef struct {
    int number;
    char street[MAX_STRING_LENGTH];
    char city[MAX_STRING_LENGTH];
    char province[MAX_STRING_LENGTH];
    int provinceCode;
} TAddress;

// Structure to represent a person
typedef struct {
    char firstName[25];
    char lastName[25];
    TDate birthDate;
    TAddress residence;
} TPerson;

// Function to display people born before a certain year
void displayPeopleBornBefore(TPerson people[], int M, int year) {
    printf("\nPeople born before the year %d:\n", year);
    for (int i = 0; i < M; i++) {
        if (people[i].birthDate.year < year) {
            printf("Name: %s %s, Birth Date: %02d/%02d/%d\n", 
                   people[i].firstName, people[i].lastName,
                   people[i].birthDate.day, people[i].birthDate.month, people[i].birthDate.year);
        }
    }
}

// Function to display names and birthdates of people living in "Paris"
void displayPeopleInParis(TPerson people[], int M) {
    printf("\nPeople living in the 'Paris' province:\n");
    for (int i = 0; i < M; i++) {
        if (strcmp(people[i].residence.province, "Paris") == 0) {
            printf("Name: %s %s, Birth Date: %02d/%02d/%d\n", 
                   people[i].firstName, people[i].lastName,
                   people[i].birthDate.day, people[i].birthDate.month, people[i].birthDate.year);
        }
    }
}

// Function to count and display the number of people in each province
void countPeopleByProvince(TPerson people[], int M) {
    int provinceCount[100] = {0}; // Assuming there are 100 provinces with codes 1-99
    char provinces[100][MAX_STRING_LENGTH]; // Store province names
    int provinceIndex = 0;
    
    printf("\nNumber of people residing in each province:\n");

    // Count number of people in each province
    for (int i = 0; i < M; i++) {
        int found = 0;
        for (int j = 0; j < provinceIndex; j++) {
            if (strcmp(people[i].residence.province, provinces[j]) == 0) {
                provinceCount[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            // Add new province to the list
            strcpy(provinces[provinceIndex], people[i].residence.province);
            provinceCount[provinceIndex] = 1;
            provinceIndex++;
        }
    }

    // Display the province counts
    for (int i = 0; i < provinceIndex; i++) {
        printf("Province: %s, Number of people: %d\n", provinces[i], provinceCount[i]);
    }
}

int main() {
    int M; // Number of people
    TPerson people[MAX_PEOPLE];

    // Input number of people
    
    do
    {
        printf("Enter the number of people (<= 200): ");
        scanf("%d", &M);
    } while (M<0 || M>200);
    
    

    // Input details for each person
    for (int i = 0; i < M; i++) {
        printf("\nEnter details for person %d\n", i + 1);
        
        // Input name
        printf("First Name: ");
        scanf("%s", people[i].firstName);
        printf("Last Name: ");
        scanf("%s", people[i].lastName);

        // Input birth date
        printf("Birth Date (DD MM YYYY): ");
        scanf("%d %d %d", &people[i].birthDate.day, &people[i].birthDate.month, &people[i].birthDate.year);

        // Input address
        printf("Address Number: ");
        scanf("%d", &people[i].residence.number);
        printf("Street: ");
        scanf(" %s", people[i].residence.street); 
        printf("City: ");
        scanf("%s", people[i].residence.city);
        printf("Province: ");
        scanf("%s", people[i].residence.province);
        printf("Province Code: ");
        scanf("%d", &people[i].residence.provinceCode);
    }

    
    displayPeopleInParis(people, M); // Display people in "Paris"
    
    int year;
    printf("\nEnter a year to see people born before it: ");
    scanf("%d", &year);
    displayPeopleBornBefore(people, M, year); // Display people born before the entered year
    
    countPeopleByProvince(people, M); // Count people by province

    return 0;
}
