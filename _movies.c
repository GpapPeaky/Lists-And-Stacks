#include "streaming_service.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @author Peaky
 * 
 * @version 19.11.23
 * 
 * 
 * 
*/

/*
THIS .C FILE CONTAINS ALL METHODS REGARDING THE NEW MOVIE CATEGORY ARRAYS AND THE NEW MOVIE INITIAL LIST 
                        BOTH THE LIST ARRAY AND LIST ARE SORTED ACCORDINGLY
*/

/*[______________________________________________________________________________________]*/

struct new_movie *movieCategories[6] = {NULL}; 

/*
INITIALISING MOVIE TAILS AS NULL SINCE WE START WITH EMPTY CATEGORY LISTS 
WE ARE REQUIRED TO HAVE A TAIL SINCE WE ARE GONNA ADD ELEMENTS FROM BEHIND
                        TO KEEP THE ARRAY SORTED
*/

struct new_movie* HORROR_TAIL = NULL;
struct new_movie* SCIFI_TAIL = NULL;
struct new_movie* DRAMA_TAIL = NULL;
struct new_movie* ROMANCE_TAIL = NULL;
struct new_movie* DOCUMENTARY_TAIL = NULL;
struct new_movie* COMEDY_TAIL = NULL;

/*
new_movie -> info -> mid AND year | MOVIE ID AND YEAR OF RELEASE
new_movie -> category | MOVIE CATEGORY TYPE
*/

struct new_movie *newMoviesList = NULL; 
struct new_movie *newMoviesTail = NULL; 

/**
 * @param umid Checks If This Unique Movie Id Is Truly Unique
*/
int uniqueMovieId(unsigned umid){

    int count = 1;
    unsigned tempid;
    
    struct new_movie *uniqueMovie = newMoviesList; 

    while(uniqueMovie != NULL){
        if(uniqueMovie->info.mid == umid){
            count++; 
            tempid = uniqueMovie->info.mid;
        }
        uniqueMovie = uniqueMovie->next;
    }

    if(count > 1){
        printf("ERROR: MOVIE WITH ID %d ALREADY EXISTS\n",tempid);
        return FAILURE;
    }

    return SUCCESS;
}

/***
 * @param mid Movie ID
 * @param category Movie Category
 * @param year Movie Release Year
*/
int add_new_movie(unsigned mid, movieCategory_t category, unsigned year){

    printf("A <%d><%s><%d>\n",mid,categoryNames[category],year);

    if(uniqueMovieId(mid) == FAILURE) return FAILURE; 

    struct new_movie *movieAdded = (struct new_movie*) malloc(sizeof(struct new_movie)); 

    movieAdded->category = category;
    movieAdded->info.mid = mid;
    movieAdded->info.year = year;   

    if(newMoviesList == NULL || mid < newMoviesList->info.mid){
        movieAdded->next = newMoviesList; 
        newMoviesList = movieAdded; 
    }else{

        struct new_movie* current = newMoviesList; 
        while(current->next != NULL && mid > current->next->info.mid){ 
            current = current->next; 
        }

        movieAdded->next = current->next; 
        current->next = movieAdded; 
    }

    struct new_movie* printPtr = newMoviesList;

    printf("    New movies=");

    while(printPtr != NULL){
        printf("<mid_%d,category_%s,year_%d>,",printPtr->info.mid,categoryNames[printPtr->category],printPtr->info.year);
        printPtr = printPtr->next;
    }
    printf("\nDONE\n");

    return SUCCESS;
}

/*[______________________________________________________________________________________]*/


/**
 * Distributes All Movies To The Corresponding Array Category List Header
*/
void distribute_new_movies(void){

    printf("D\n");

    struct new_movie* newMoviePtr = newMoviesList;

    newMoviePtr = newMoviesList;  

    while(newMoviePtr != NULL){ 

        struct new_movie* distributor =(struct new_movie*) malloc(sizeof(struct new_movie)); 

        distributor->next = NULL; 

        distributor->info = newMoviePtr->info;
        distributor->category = newMoviePtr->category;

        switch (distributor->category){

            case HORROR:    
                if(movieCategories[HORROR] == NULL){
                    movieCategories[HORROR] = distributor;
                    HORROR_TAIL = distributor;
                }else{
                    HORROR_TAIL->next = distributor;
                    HORROR_TAIL = distributor;
                    distributor->next = NULL;
                }
                break;

            case SCIFI:    
                if(movieCategories[SCIFI] == NULL){
                    movieCategories[SCIFI] = distributor;
                    SCIFI_TAIL = distributor;
                }else{
                    SCIFI_TAIL->next = distributor;
                    SCIFI_TAIL = distributor;
                    distributor->next = NULL;
                }
                break;

            case DRAMA:     
                if(movieCategories[DRAMA] == NULL){
                    movieCategories[DRAMA] = distributor;
                    DRAMA_TAIL = distributor;
                }else{
                    DRAMA_TAIL->next = distributor;
                    DRAMA_TAIL = distributor;
                    distributor->next = NULL;
                }
                break;

            case ROMANCE:     
                if(movieCategories[ROMANCE] == NULL){
                    movieCategories[ROMANCE] = distributor;
                    ROMANCE_TAIL = distributor;
                }else{
                    ROMANCE_TAIL->next = distributor;
                    ROMANCE_TAIL = distributor;
                    distributor->next = NULL;
                }
                break;

            case DOCUMENTARY:     
                if(movieCategories[DOCUMENTARY] == NULL){
                    movieCategories[DOCUMENTARY] = distributor;
                    DOCUMENTARY_TAIL = distributor;
                }else{
                    DOCUMENTARY_TAIL->next = distributor;
                    DOCUMENTARY_TAIL = distributor;
                    distributor->next = NULL;
                }
                break;

            case COMEDY:     
                if(movieCategories[COMEDY] == NULL){
                    movieCategories[COMEDY] = distributor;
                    COMEDY_TAIL = distributor;
                }else{
                    COMEDY_TAIL->next = distributor;
                    COMEDY_TAIL = distributor;
                    distributor->next = NULL;
                }
                break;   

            default:
                printf("ERROR: INVALID CATEGORY");
                break;
        }
        newMoviePtr = newMoviePtr->next; 
    }

    print_movies_category(); 

    return;
}

/*[______________________________________________________________________________________]*//*[______________________________________________________________________________________]*/

void take_off_movie(unsigned mid){

    struct new_movie* tmp = NULL;

    printf("T <%d>\n",mid);

    int i = 0;

    for(i = 0; i < 5 ; i++){

        struct new_movie* removable = movieCategories[i];
        struct new_movie* previous = NULL;

        while(removable != NULL){
            if(removable->info.mid == mid){
                if(previous == NULL){
                    movieCategories[i] = removable->next; 
                    printf("    <%d> removed from categories list\n",mid);
                }else{
                    previous->next = removable->next; 
                    printf("    <%d> removed from categories list\n",mid);
                }
            }
            previous = removable;
            removable = removable->next;
        }
    }

    struct user* current = userList;

    while(current->uid != -1){

        struct suggested_movie* s_removable = current->suggestedHead;
        struct suggested_movie* s_previous = NULL;

        while(s_removable != NULL){
            if(s_removable->info.mid == mid){
                if(s_previous == NULL){
                   current->suggestedHead = s_removable->next; 
                   printf("    <%d> removed from <%d> suggested list\n",mid,current->uid);
                }else{
                    s_previous->next = s_removable->next; 
                    printf("    <%d> removed from <%d> suggested list\n",mid,current->uid);
                }
            }
            s_previous = s_removable;
            s_removable = s_removable->next;
        }
        current = current->next;
    }

    printf("DONE\n");

    return;
}