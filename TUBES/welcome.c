#include <stdio.h>
#include "welcome.h"


void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
} 
void welcome(){

    printf("                                                                |>>>\n");
    printf("                                                                |\n");
    printf("                                                                |\n");
    printf("                                                                |\n");
    printf("                                                            _  _|_  _\n");
    printf("                                                           |;|_|;|_|;|\n");
    printf("                                                           \\\\.    .  /\n");
    printf("                                                            \\\\:  .  /\n");
    printf("                                                             ||:   |\n");
    printf("                                          \\\\,//              ||:.  |\n");
    printf("                                                             ||:  .|\n");
    printf("                                                             ||:   |\n");
    printf("                             //`\\\\                           ||: , |\n");
    printf("                                                             ||:   |\n");
    printf("                                                             ||:   |\n");
    printf("                                                             ||: . |\n");
    printf("                              __                            _||_   |\n");
    printf("     ___             ____--`~    '--~~__            __ ----~    ~`---,\n");
    printf("__-~'   `~----~~-~--~                   ~---__ ,--~'                  ~~----___\n");
    delay(3);
    //system("cls");

    printf("                                                                |>>>\n");
    printf("                                                                |\n");
    printf("                                                                |\n");
    printf("                                                                |\n");
    printf("                                                            _  _|_  _\n");
    printf("                                                           |;|_|;|_|;|\n");
    printf("                                                           \\\\.    .  /\n");
    printf("                                                            \\\\:  .  /\n");
    printf("                                                             ||:   |\n");
    printf("                 \\\\,//                                       ||:.  |\n");
    printf("                                                             ||:  .|\n");
    printf("                                                             ||:   |\n");
    printf("                             //`\\\\                           ||: , |\n");
    printf("                                                             ||:   |\n");
    printf("                                                             ||:   |\n");
    printf("                                                             ||: . |\n");
    printf("                              __                            _||_   |\n");
    printf("     ___             ____--`~    '--~~__            __ ----~    ~`---,\n");
    printf("__-~'   `~----~~-~--~                   ~---__ ,--~'                  ~~----___\n");
    delay(3);
    //system("cls");
}