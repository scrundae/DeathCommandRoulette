#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

char dir[10000];

int main() {
    srand(time(NULL));
    cls();
    printf("+------------------------+");
    printf("\n| Death Command Roulette |");
    printf("\n+------------------------+");
    //printf("\a");
    printair();
    printf("\nSign the waiver> ");
    fgets(dir, sizeof(dir), stdin);
    dir[strcspn(dir, "\n")] = '\0';
    cls();
    printf("YOU SIGNED THE WAIVER.");
    _sleep(1000);
    printf("\nNOW. PLAY.");
    _sleep(1000);
    cls();
    printf("+----------------------+");
    printf("\n| It's time to play... |");
    printf("\n+----------------------+");
    printair();
    printf("\nEnter the name of the file you want to put on the line> ");
    fgets(dir, sizeof(dir), stdin);
    dir[strcspn(dir, "\n")] = '\0';
    while (true) {
        printf("\nPress the ENTER key to spin.");
        getchar();
        int spin = (rand() % 6) + 1;
        if (spin != 6) {
            printf("\nSafe...");
        }
        else {
            printf("\nGame over.");
            remove(dir);
            #ifdef _WIN32
                system("color c0");
                _sleep(100);
                system("color 07");
                _sleep(100);
                break;
            #else
                _sleep(1000);
                break;
            #endif
        }
    }
    return 0;
}

int cls() {
    #ifdef _WIN32
        system("cls");
    #elif __APPLE__
        system("clear");
    #elif __linux__
        system("clear");
    #else
        printf("Unknown operating system. Could not proceed.");
        return 1;
    #endif
}

int printair() {
    printf("\n");
}
