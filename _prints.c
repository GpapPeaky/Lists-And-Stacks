#include "streaming_service.h"
#include <stdio.h>
#include <stdlib.h>

const char *categoryNames[6] = {"HORROR","SCIFI","DRAMA","ROMANCE","DOCUMENTARY","COMEDY"};

/**
 * @author Peaky
 * 
 * @version 19.11.23
 * 
 * 
 * 
*/

/**
 * Prints All Users FIXME TODO DEBUG IDEA
*/
void print_users(void){

    struct user* current = userList;

    printf("P\n");

    while(current != NULL){
        printf("<u_%d> ",current->uid);
        current = current->next;
        if(!current){
            break;
        }
    }
    printf("\n");

    return;
}

/**
 * Prints All Movies
*/
void print_movies(void){

    printf("M\n");

    printf("Categorized Movies:\n");

    int i = 0;

    for(i = 0; i < 6 ;i++){

        struct new_movie* current = movieCategories[i];

        printf("   %s: ",categoryNames[i]);

        while(current != NULL){

            switch (current->category){

                case HORROR:     
                    printf("<mid_%d,%d> ",current->category + 1,current->info.mid);
                    break;

                case SCIFI:     
                    printf("<mid_%d,%d> ",current->category + 1,current->info.mid);
                    break;

                case DRAMA:     
                    printf("<mid_%d,%d> ",current->category + 1,current->info.mid);
                    break;

                case ROMANCE:     
                    printf("<mid_%d,%d> ",current->category + 1,current->info.mid);
                    break;

                case DOCUMENTARY:     
                    printf("<mid_%d,%d> ",current->category + 1,current->info.mid);
                    break;

                case COMEDY:     
                    printf("<mid_%d,%d> ",current->category + 1,current->info.mid);
                    break;   

                default:
                    break;
            }

            current = current->next;
        }
        printf("\n");
    }

    printf("DONE\n");
    return;
}

/**
 * Prints All Movies For The Category Distribution Print
*/
void print_movies_category(void){

    printf("Categorized Movies:\n");

    int i = 0;

    for(i = 0; i < 6 ;i++){

        struct new_movie* current = movieCategories[i];

        printf("   %s: ",categoryNames[i]);

        while(current != NULL){

            switch (current->category){

                case HORROR:     
                    printf("<mid_%d,%d> ",current->category + 1,current->info.mid);
                    break;

                case SCIFI:     
                    printf("<mid_%d,%d> ",current->category + 1,current->info.mid);
                    break;

                case DRAMA:     
                    printf("<mid_%d,%d> ",current->category + 1,current->info.mid);
                    break;

                case ROMANCE:     
                    printf("<mid_%d,%d> ",current->category + 1,current->info.mid);
                    break;

                case DOCUMENTARY:     
                    printf("<mid_%d,%d> ",current->category + 1,current->info.mid);
                    break;

                case COMEDY:     
                    printf("<mid_%d,%d> ",current->category + 1,current->info.mid);
                    break;   

                default:
                    break;
            }

            current = current->next;
        }
        printf("\n");
    }

    printf("DONE\n");
    return;
}

/**
 * Suggestion Printing
 * 
 * @param uid User For The Suggestions
*/
void suggestion_prints(int uid){

    struct user* search = userList;

    while(search->uid != -1){
        if(search->uid == uid){
            break;
        }
        search = search->next;
    }

    struct suggested_movie* sug = search->suggestedHead;

    while(sug != NULL){
        printf("<mid_%d>",sug->info.mid);
        sug = sug->next;
    }

    printf("\nDONE\n");
}
