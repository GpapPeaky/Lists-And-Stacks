#include <stdio.h>
#include "streaming_service.h"

/**
 * @author Peaky
 * 
 * @version 10.11.23
 * 
 * 
 * 
*/

 /*
  IN ORDER TO KEEP THE CODE CLEAN IN BOTH THE HEADER AND THE OTHER .C FILES I HAVE CREATED THIS
FILE ONLY FOR ERROR PRINTS IN ORDER TO DEBUG AND CHECK WHAT LINE THE CODE REACHES BEFORE IT STOPS
*/

/**
 * Constant Character For Prints
*/
const char errb = 219; /*Error Block*/
  
/**
 * Error Message Function
 * 
 * @param msg (-1) For Failure (0) For Success
*/
void error(int msg){

  if(msg == 0){
    printf("\n");
    printf("%c%c%c%c%c%c%c%c%c%c%c\n",errb,errb,errb,errb,errb,errb,errb,errb,errb,errb,errb);
    printf("%c-SUCCESS-%c\n",219,219);
    printf("%c%c%c%c%c%c%c%c%c%c%c\n",errb,errb,errb,errb,errb,errb,errb,errb,errb,errb,errb);
    printf("\n");
  }else if(msg == -1){
    printf("\n");
    printf("%c%c%c%c%c%c%c%c%c%c%c\n",errb,errb,errb,errb,errb,errb,errb,errb,errb,errb,errb);
    printf("%c-FAILURE-%c\n",219,219);
    printf("%c%c%c%c%c%c%c%c%c%c%c\n",errb,errb,errb,errb,errb,errb,errb,errb,errb,errb,errb);
    printf("\n");
  }else{
    printf("\n");
    printf("%c%c%c%c%c%c%c%c%c%c%c\n",errb,errb,errb,errb,errb,errb,errb,errb,errb,errb,errb);
    printf("%c-_______-%c\n",219,219);
    printf("%c%c%c%c%c%c%c%c%c%c%c\n",errb,errb,errb,errb,errb,errb,errb,errb,errb,errb,errb);
    printf("\n");
  }

  return;
}

/**
 *Error Function For Tests And Error Handling 
*/
void newBlock(void){

  int i = 0 ;

  for(i = 0 ; i < 45 ; i++){
    printf("%c",205);
  }
  printf("\n");

  return;
}

/*COMPILE MULTIPLE .C FILES IN ORDER TO MAKE IT WORK (OR ELSE IT WONT)*/


/*

(note todo fixme debug ΤΣΙΡΙΜΠΊΜ ΤΣΙΡΙΜΠΌΜ)

*/
