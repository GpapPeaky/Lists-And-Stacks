#include "streaming_service.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @author Peaky
 * 
 * @version 7.11.23
 * 
 * 
 * 
*/

/*
THIS .C FILE CONTAINS ALL METHODS REGARDING ALL DATA STRUCTURES ASSOCIATED WITH THE WATCHED MOVIE STACK 
                        IT CONTAINS ALL BASIC METHODS OF A TYPICAL STACK
                        THE WATCHED MOVIE STACKS ARE ALREADY EMPTY SINCE
                     THEY HAVE BEEN INITIALISED AS NULL IN THE _users.c FILE
*/

/**
 * CALCULATES THE STACKS' LENGTH
 * 
 * @param S The Stack
 * 
 * @return The Size Of The Stack
*/
int stackSize(struct movie** S){
    int counter = 0;

    if(S == NULL){
        return 0;
    }

    struct movie* current = *S;

    while(current != NULL){
        counter++;
        current = current->next;
    }

    return counter;
}

/**
 * Returns The Top Element Of The Stack
 * 
 * @param S The Stack
 * 
 * @return Top Stack Element
*/
struct movie* top(struct movie** S){
    if(S == NULL){
        return NULL;
    }else{
        return *S;
    }
}

/**
 * Deletes The Top Element And Returns it
 * 
 * @param S The Stack 
 * 
 * @return Top Stack Element
*/
struct movie* pop(struct movie** S){

    struct movie* popElement;

    if(*S == NULL){
        return popElement;
    }

    popElement = *S;
    *S = (*S)->next;
    popElement->next = NULL;

    return popElement;
}

/**
 * Inserts A New Element In The Stack
 * 
 * @param S The Stack
 * @param mid Movie ID
 * @param year Movie Release Year
 * 
 * @return S The New Stack
*/
struct movie* push(struct movie** S,unsigned mid,unsigned year){

    struct movie* watched = (struct movie*) malloc(sizeof(struct movie));

    watched->info.mid = mid;
    watched->info.year = year;

    watched->next = *S;
    *S = watched;

    return *S;
}

