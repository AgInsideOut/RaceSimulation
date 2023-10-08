#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures section

struct Race {
    int numberOfLaps;
    int currentLap;
    char firstPlaceDriverName[20];
    char firstPlaceRaceCarColor[20];
};

struct RaceCar {
    char driverName[20];
    char raceCarColor[20];
    int totalLapTime;
};

// Function prototypes

void printIntro() {
    printf("Welcome to our main event digital race fans!\nI hope everybody has their snacks because we are about to begin!\n\n");
};

void printCountDown() {
    printf("Racers Ready! In...\n");
    printf("5\n");
    printf("4\n");
    printf("3\n");
    printf("2\n");
    printf("1\n");
    printf("Race!\n\n");
};

void printFirstPlaceAfterLap(struct Race race) {
    printf("After lap number %d\n", race.currentLap);
    printf("First Place Is: %s in the %s race car!\n\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
};

void printCongratulation(struct Race race) {
    printf("Let's all congratulate %s in the %s race car for an amazing performance.\nIt truly was a great race and everybody have a goodnight!", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
};

// Logic functions section

int calculateTimeToCompleteLap() {
    int speed = rand() % 3 + 1;
    int acceleration = rand() % 3 + 1;
    int nerves = rand() % 3 + 1;
    
    int totalTime = speed + acceleration + nerves;
    return totalTime;
};

void updateRaceCar(struct RaceCar* raceCar) {
    int lapTime = calculateTimeToCompleteLap();
    raceCar->totalLapTime += lapTime;
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
    // Get random factors for both race cars
    int randomFactor1 = rand() % 10; // Generate a random number between 0 and 9 for raceCar1
    int randomFactor2 = rand() % 10; // Generate a random number between 0 and 9 for raceCar2

    // Compare total lap times to determine the first place
    if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
        // If raceCar1 has equal or smaller totalLapTime, update first place details
        strcpy(race->firstPlaceDriverName, raceCar1->driverName);
        strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
        // Add random factor to the total lap time of raceCar1
        raceCar1->totalLapTime += randomFactor1;
    } else {
        // If raceCar2 has smaller totalLapTime, update first place details
        strcpy(race->firstPlaceDriverName, raceCar2->driverName);
        strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
        // Add random factor to the total lap time of raceCar2
        raceCar2->totalLapTime += randomFactor2;
    }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
    struct Race race = {
        .numberOfLaps = 5,
        .currentLap = 1,
    };

    for (int lap = 1; lap <= race.numberOfLaps; lap++) {
        // Update race car's total lap time for each lap
        updateRaceCar(raceCar1);
        updateRaceCar(raceCar2);
        // Update first place details after each lap
        updateFirstPlace(&race, raceCar1, raceCar2);
        // Print first place after each lap
        printFirstPlaceAfterLap(race);
        // Move to the next lap
        race.currentLap++;
    }

    // Print congratulatory message at the end of the race
    printCongratulation(race);
}

int main() {
    srand(time(0));
    
    // Initialize the race structure
    struct Race race = {
        .numberOfLaps = 5, // Set the number of laps (or any other value you want)
        .currentLap = 1, // Start from the first lap
        .firstPlaceDriverName = "Aiden",
        .firstPlaceRaceCarColor = "Blue"
    };

    // Initialize the race car 1
    struct RaceCar raceCar1 = {
        .driverName = "Aiden",
        .raceCarColor = "Blue",
        .totalLapTime = 0
    };

    // Initialize the race car 2
    struct RaceCar raceCar2 = {
        .driverName = "Ethan",
        .raceCarColor = "Orange",
        .totalLapTime = 0
    };

    printIntro();
    printCountDown();

    // Perform the race laps
    for (int lap = 1; lap <= race.numberOfLaps; lap++) {
        // Update race car's total lap time for each lap
        updateRaceCar(&raceCar1);
        // Update first place details after each lap
        updateFirstPlace(&race, &raceCar1, &raceCar2);
        // Print first place after each lap
        printFirstPlaceAfterLap(race);
        // Move to the next lap
        race.currentLap++;
    }

    // Start the race by calling startRace() function
    startRace(&raceCar1, &raceCar2);

    return 0;
}