# PROJECT PHASE 1 CONTENTS

## __v19.11.23__ __|__  __Gpap Peaky__

__.C FILES:__ NAMES ARE THIS WAY IN ORDER TO KEEP THEM FROM BEING SEPERATED IN FILE FROM BEING INDISTINGUISHABLE FROM THE OTHER FILES

__.C MAINS:__ MAIN FUNCTIONS IN THE .C FILES ARE ONLY FOR TESTS WILL BE REMOVED ONCE THE METHODS ARE COMPLETE

___STACK.C:__  IT CONTAINS ALL METHODS ASSOCIATED WITH STACKS

___ERROR.C:__ SIMPLE ERROR PRINTS FOR MANUAL DEBUGGING

___USERS.C:__    CONTAINS ALL METHODS ASSOCIATED WITH USER DATA

___MOVIES.C:__   CONTAINS ALL METHODS ASSOCIATED WITH MOVIE DATA

___FILTERED.C:__ CONTAINS ALL METHODS FOR THE FILTER COMMAND

___PRINTS.C:__ CONTAINS ALL PRINT FUNCTIONS

---

|USERS ATTRIBUTES|MOVIES ATTRIBUTES|
|-----|------|
|User Id|Movie Id|
|User Suggestions|Movie year|
|User Watchlist|
---

## Notes

> *Some Variables And Headers Have Been Initialised As **external** In The Header File. It Has Become Appearent That It Is Not Required And ,Frankly ,The Program Will Not Run If These Variables Are Declared As **external**.*

> *All List (& Stack) Headers And Tails Are Intialised As **NULL** .Later They Are Initialised As Something Else If It Is Required To Do So.*

> *It Is Required To **Compile All .c Files At The Same Time** (In The Same Command), In Order For The Program To Work *(Else It Hits Undefined Refrence Errors)*.*

> *AUXILARY DEFINITIONS: In Order To Avoid Mistakes And Arithemetic Conflict, Values For **SUCCESS (0)** And **FAILURE (-1)** Have Been Defined In `streaming_service.h`*.
---
## Methods

|_prints.c | Variables | Description |
|-|-|-|
|`print_users()`| **void** |Prints All Users Registered|
|`print_movies()`| **void** | Prints All Movies In The New Movies' List|

|_error.c| Variables | Description |
|--|--|--|
`error()` | **void** |Prints A Debug Message (Used To Check Where The Compiler Stops) |
|`newBlock()`| **void** | Prints A Debug Message (Use To Seperate New Blcoks Of Code)|

---

|_users.c| Variables | Description|
|-|-|-|
`register_user()` | **int uid**  | Registers A New User To The Users' List|
`unregister_user()`|**int uid** | Removes An Already Existing User From The| Users' List
`init_Sentinel()`| **void** | Initialises The Sentinel Node Of The Users' List|
|`uniqueUserId()`| **int uuid** | Checkes If The User Id Is Unique In The List|
|`watch_movie()`| **int uid** , **unsigned mid**| User Watches A Movie (Added to The Watch History Stack)|
---

|_movies.c| Variables| Description|
|-|-|-|
|`add_new_movie()`| **unsigned mid** | Adds A New Movie To The Movies' List
|`distribute_new_movies()`| **void** | Distributes The New Movies To A Category Array|
|`uniqueMovieId()`| **unsigned umid** | Checks If The Movie Id Is Unique|

|_stack.c| Variables | Description |
|-|-|-|
|`pop()`| **struct movie ** stack** | Deletes The Top Element Of The Stack And Returns it|
|`top()`| **struct movie ** stack** | Returns The Top Element Of The Stack |
|`push()`| **struct movie ** stack** , **unsigned int mid** , **unsigned int year**| Pushes To The WatchList Stack The Specified Movie To The Specified User |
---

## Data Structures

###  `userList` - Linked List That Includes The Users (Unsorted)

### `newMoviesList` - Linked List That Includes The New Movies (Sorted)

### `movieCategories[6]` - Array Of Linked Lists That Includes The Movies And       Their                     Category (Sorted)

### `watchHistory` - Stack With All Watched Movies (Unsorted)

### `suggestedHead` - Double Linked List That Includes User Suggested Movies (Special Sorted)

### `categoryNames[6]` - Constant Character * Array That Contains Category Names For Prints
⠀
___

___TODO: Update readme.md___

# Summary

## Languages
| language | files | code | comment | blank | total |
| :--- | ---: | ---: | ---: | ---: | ---: |
| C | 7 | 860 | 558 | 348 | 1,766 |
| Markdown | 1 | 80 | 0 | 40 | 120 |
| C++ | 1 | 70 | 175 | 44 | 289 |
| Makefile | 1 | 7 | 0 | 4 | 11 |

## Directories
| path | files | code | comment | blank | total |
| :--- | ---: | ---: | ---: | ---: | ---: |
|  | 10 | 1,017 | 733 | 436 | 2,186 |