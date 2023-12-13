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

struct user* userList = NULL;

struct user userSentinel;

/*
 THE CURRENT FILE CONTAINS ALL METHODS ASSOCIATED WITH USERS, MOST HEADERS HAVE BEEN INITIALISED IN THE .h
                                 FILE AND THEY ARE INITIALISED ELSEWHERE
*/

/**
 * @param uuid Checks If This User Id Already Exists In The Users' List
*/
int uniqueUserId(int uuid){

    int count = 0,tempid;
    
    struct user *uniqueUser = userList;

    while(uniqueUser != NULL){
        if(uniqueUser->uid == uuid){
            count++;
            tempid = uniqueUser->uid;
        }
        uniqueUser = uniqueUser->next;
    }

    if(count >= 1){
        printf("ERROR: USER WITH ID %d ALREADY EXISTS\n",tempid);
        free(uniqueUser);
        return FAILURE;
    }

    return SUCCESS;
}

/*[______________________________________________________________________________________]*/

/**
 * Intialises The Sentinel
*/
void init_sentinel(void){

    userSentinel.uid = -1; 
    userSentinel.suggestedHead = NULL; 
    userSentinel.suggestedTail = NULL;
    userSentinel.watchHistory = NULL; 

    userList = &userSentinel; 

    return;
}

/*[______________________________________________________________________________________]*/

/**
 * @param uid User Id To Be Inserted To The Users' List
*/
int register_user(int uid){

    if(uniqueUserId(uid) == -1) return -1;

    struct user* newUser = (struct user*)malloc(sizeof(struct user));

    if(newUser == NULL) {
        printf("ERROR: Memory allocation failed for new user\n");
        return FAILURE;
    }

    newUser->uid = uid;
    newUser->suggestedHead = NULL; 
    newUser->suggestedTail = NULL;
    newUser->watchHistory = NULL; 

    newUser->next = userList;
    userList = newUser;       

    /*[______________________________________________________________________________________]*/    

    printf("R <%d>\n Users = ",uid);

    struct user* uprint = userList;

    while(uprint != NULL){
        printf("<uid_%d> ",uprint->uid);
        uprint = uprint->next;
    }

    printf("\nDONE\n");
           
    return SUCCESS; 
   /*NON SORTED LIST METHOD*/
}

/**
 * @param uid User's Id To Be Removed
*/
void unregister_user(int uid){

    struct user* current = userList;
    struct user* previous = NULL;

    while(current->uid != -1){ 
        if(current->uid == uid){
            
            if(previous == NULL){
                userList = userList->next;
            }else{
                previous->next = current->next; 
            }

            printf("  U <%d>\n Users = ",uid);

            struct user* uprint = userList;

            while(uprint != NULL){
                printf("<uid_%d> ",uprint->uid);
                uprint = uprint->next;
            }

            printf("\nDONE\n");

            free(current);
            return; 
        }
        previous = current; 
        current = current->next;
    }

    printf("ERROR: USER WITH ID %d NOT FOUND\n", uid);
    return;
}

/**
 * @param uid User To Watch The Movie
 * @param mid Movie Id That Was Watched
 * 
 * @return -1 On Failure
 * @return 0 On Success
*/
int watch_movie(int uid,unsigned mid){

    struct movie_info info;
    struct user* currentUser = userList; 

    int movieFound = 0;

    int userFound = 0;

    struct user* NoUserFound = userList;

    /*[______________________________________________________________________________________]*/

    /*NO MOVIE EXCEPTION*/

    int j = 0 ;

    for(j = 0 ; j <= 5 ; j++){
        
        struct new_movie *currentMovie = movieCategories[j];

        while(currentMovie){
            if(currentMovie->info.mid == mid){
                movieFound++;
                break;
            }
            currentMovie = currentMovie->next;
        }
    }  

    if (!movieFound){
        return FAILURE;
    }

    /*[______________________________________________________________________________________]*/

    /*NO USER EXCEPTION*/

    while(NoUserFound->uid != -1){
        if(NoUserFound->uid == uid){
            userFound++;
            break;
        }
        NoUserFound = NoUserFound->next;
    }

    if (userFound == 0){
        return FAILURE; 
    }

    /*[______________________________________________________________________________________]*/

    while(currentUser->uid != -1){
        if(currentUser->uid == uid){
            break; 
        }
        currentUser = currentUser->next;
    }

    int i = 0 ;

    for(i = 0 ; i <= 5 ; i++){
        
        struct new_movie *currentMovie = movieCategories[i]; 

        while(currentMovie != NULL){
            if(currentMovie->info.mid == mid){
                info = currentMovie->info; 
                break;
            }
            currentMovie = currentMovie->next;
        }
    }  

    push(&(currentUser->watchHistory),mid,info.year); 

    /*WE PUSHED TO THE WATCH HISTORY OF THE CURRENT USER THE MOVIE ID AND THE INFO YEAR*/

    printf("W <%d><%d>\n",uid,mid);

    printf("   User<%d> Watch History=",uid);

    struct user* current = userList;

    while(current->uid != -1){
        if(current->uid == uid){
            break; 
        }
        current = current->next;
    }

    struct movie* watched = current->watchHistory;

    while(watched != NULL){
        printf("<mid_%d>,",watched->info.mid);
        watched = watched->next;
    }
    printf("\nDONE\n");

    return SUCCESS;
}

/**
 * Creates The Suggested Movies Double Linked List
 * 
 * @param uid Suggested Movies From User
 * 
 * @return -1 For Failure
 * @return 0 For Success
*/
int suggest_movies(int uid){

    struct user* current = userList; 

    struct suggested_movie* currentFront = NULL;
    struct suggested_movie* currentBack = NULL;   

    struct movie* movie_data = NULL;

    while (current->uid != -1){
        if (current->uid == uid) {
            break; 
        }
        current = current->next;
        if(current->uid == -1){
            printf("USER WITH ID %d NOT FOUND\n",uid);
            return FAILURE;
        }
    }    

    struct user* userToSuggest = current;

    current = userList; 

    int counter = 1;

    while(current->uid != -1){

        if (current->uid != uid) {
            struct movie** movie = &(current->watchHistory); 

            struct suggested_movie* suggestedMovie = (struct suggested_movie*)malloc(sizeof(struct suggested_movie));

            /*[______________________________________________________________________________________]*/

                                          /*USER EMPTY STACK HANLDING*/

            if(*movie != NULL){
                movie_data = pop(movie);
            }else{
                current = current->next; 
                continue; 
            }

            /*[______________________________________________________________________________________]*/


            suggestedMovie->info.mid = movie_data->info.mid;
            suggestedMovie->info.year = movie_data->info.year;

            /*[______________________________________________________________________________________]*/

            if(counter % 2 != 0){

                if(currentFront == NULL){ 
                    userToSuggest->suggestedHead = suggestedMovie; 
                    userToSuggest->suggestedHead->next = suggestedMovie; 
                    suggestedMovie->next= NULL; 
                    currentFront = suggestedMovie; 
                }else{
                    suggestedMovie->prev = currentFront; 
                    currentFront->next = suggestedMovie; 
                    suggestedMovie->next = NULL; 
                    currentFront = suggestedMovie; 
                }
                
            }else{ /*[______________________________________________________________________________________]*/

                if(currentBack == NULL){
                    userToSuggest->suggestedTail = suggestedMovie; 
                    userToSuggest->suggestedTail->prev = suggestedMovie; 
                    suggestedMovie->prev= NULL; 
                    currentBack = suggestedMovie; 
                
                }else{
                    suggestedMovie->next = currentBack;
                    currentBack->prev = suggestedMovie;
                    suggestedMovie->prev = NULL; 
                    currentBack = suggestedMovie; 
                }
            }
            counter++; 
        }
        current = current->next;
    }

    if(currentFront->next == NULL && currentBack->prev == NULL){
        currentFront->next = currentBack;
        currentBack->prev = currentFront;
    }

    printf("S<%d>\n    User <%d> Suggested Movies=",uid,uid);

    suggestion_prints(uid);

    return SUCCESS;
}
