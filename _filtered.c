#include "streaming_service.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @author Peaky
 * 
 * @version 19.11.23
 * 
 * 
 * 
*/

/**
 * 
 * @param uid User To Filter moviesto
 * @param category1 Category 1
 * @param category2 Category 2
 * @param year Year Forward
 * 
 * @returns -1 Failure
 * @returns 0 Success
 * 
*/
int filtered_movie_search(int uid, movieCategory_t category1,movieCategory_t category2, unsigned year){

    struct user* current = userList; 

    struct new_movie* categoryOne; 
    struct new_movie* categoryTwo; 
    
    struct suggested_movie* filteredMovie = NULL;    
    struct suggested_movie* tmpFilteredMovie = NULL; 

    categoryOne = movieCategories[category1]; 
    categoryTwo = movieCategories[category2]; 

    /*[______________________________________________________________________________________]*/    

    if(categoryTwo == NULL){ 

        while(categoryOne != NULL){
            if(categoryOne->info.year >= year){

                struct suggested_movie* info = (struct suggested_movie*)malloc(sizeof(struct suggested_movie)); 

                info->info.mid = categoryOne->info.mid;
                info->info.year = categoryOne->info.year;
                
                if(filteredMovie == NULL){ 
                    filteredMovie = info;
                    filteredMovie->next = NULL;
                    filteredMovie->prev = NULL;
                    tmpFilteredMovie = info;
                }else{      
                    info->next = NULL;
                    info->prev = tmpFilteredMovie;
                    tmpFilteredMovie->next = info;
                    tmpFilteredMovie = info;
                }
            }
            categoryOne = categoryOne->next;
        }

    }else if(categoryOne == NULL){ 

            while(categoryTwo != NULL){

                if(categoryTwo->info.year >= year){

                    struct suggested_movie* info = (struct suggested_movie*)malloc(sizeof(struct suggested_movie));

                    info->info.mid = categoryTwo->info.mid;
                    info->info.year = categoryTwo->info.year; 
                    
                if(filteredMovie == NULL){
                    filteredMovie = info;
                    filteredMovie->next = NULL;
                    filteredMovie->prev = NULL;
                    tmpFilteredMovie = info;
                }else{      
                    info->next = NULL;
                    info->prev = tmpFilteredMovie;
                    tmpFilteredMovie->next = info;
                    tmpFilteredMovie = info;
                }
            }
            categoryTwo = categoryTwo->next;
        }

    }else if(categoryOne != NULL && categoryTwo != NULL){ 

        while(categoryOne != NULL || categoryTwo != NULL){

            struct suggested_movie* info = (struct suggested_movie*)malloc(sizeof(struct suggested_movie)); 

            if(categoryOne != NULL && categoryTwo != NULL){
                if(categoryOne->info.mid >= categoryTwo->info.mid){
                    info->info.mid = categoryTwo->info.mid;
                    info->info.year = categoryTwo->info.year;
                    categoryTwo = categoryTwo->next;
                } else {
                    info->info.mid = categoryOne->info.mid;
                    info->info.year = categoryOne->info.year;
                    categoryOne = categoryOne->next;
                }

            }else if(categoryOne != NULL){
                info->info.mid = categoryOne->info.mid;
                info->info.year = categoryOne->info.year;
                categoryOne = categoryOne->next;

            }else if(categoryTwo != NULL){
                info->info.mid = categoryTwo->info.mid;
                info->info.year = categoryTwo->info.year;
                categoryTwo = categoryTwo->next;
            }

            if(info->info.year >= year){
                if(filteredMovie == NULL){
                    info->next = NULL;
                    info->prev = NULL;
                    tmpFilteredMovie = info;
                    filteredMovie = info;

                }else{
                    info->next = NULL;
                    info->prev = tmpFilteredMovie;
                    tmpFilteredMovie->next = info;
                    tmpFilteredMovie = info;
                }
            }
        }

        if(categoryTwo != NULL && categoryOne != NULL){

            if(categoryOne != NULL){
                while(categoryOne != NULL){
                    struct suggested_movie* newInfo = (struct suggested_movie*) malloc(sizeof(struct suggested_movie));

                    newInfo->info.mid = categoryOne->info.mid;
                    newInfo->info.year = categoryOne->info.year;

                    newInfo->next = NULL;
                    newInfo->prev = tmpFilteredMovie;
                    tmpFilteredMovie->next = newInfo;
                    tmpFilteredMovie = newInfo;

                    categoryOne = categoryOne->next;
                }
            }else if(categoryTwo != NULL){
                while(categoryTwo != NULL){
                    struct suggested_movie* newInfo = (struct suggested_movie*) malloc(sizeof(struct suggested_movie));

                    newInfo->info.mid = categoryTwo->info.mid;
                    newInfo->info.year = categoryTwo->info.year;

                    newInfo->next = NULL;
                    newInfo->prev = tmpFilteredMovie;
                    tmpFilteredMovie->next = newInfo;
                    tmpFilteredMovie = newInfo;

                    categoryTwo = categoryTwo->next;
                }
            }
        }
    }

    int userFound = 0;

    while(current->uid != -1){
        if(current->uid = uid){
            userFound++;
            break;
        }
        current = current->next;
    }    

    if(userFound == 0){
        printf("USER %d ,NOT FOUND",uid);
        return FAILURE;
    }

    /*[______________________________________________________________________________________]*/
    
    if(filteredMovie != NULL){
        if(current->suggestedHead == NULL){
            current->suggestedHead = filteredMovie;
        }else{
            current->suggestedTail->next = filteredMovie;
            filteredMovie->prev = current->suggestedTail;
        }

        current->suggestedTail = tmpFilteredMovie;
    }

    printf("F<%d><%s><%s><%d>\n     User<%d> Suggested Movies=",uid,categoryNames[category1],categoryNames[category2],year,uid);
    suggestion_prints(uid);

    return SUCCESS;
}
