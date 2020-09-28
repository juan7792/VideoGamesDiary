# VideoGamesDiary

This program was written in C++ with the help of the sqlite3-C++ package and sqlite3.h. Using object oriented programming in C++, with help the sqlite3 package, this program stores in a DB the name and details of the user's video games using an console interface. The flowchart of the program is available in __VideoGameDiaryFlowchart.pdf__.

## Summary

### 1) Queries

The queries are modified using the method sprintf_s() to allow the user to insert data. The queries are executed using methods from superclasses and subclasses.

### 2) Classes

#### Superclasses
Parent classes were used to section the methods to operate the database with the commands of sqlite3. Furthermore, it contains the static variables necessary to operate the menus showed in the console interface of the program.

#### Subclasses
Children classes contain the queries to be built up using sprintf_s() and user inputs. The methods of the subclasses called the inherited instances and methods.

### 1) Tables

#### users
This table contains the usernames added to the database, using an user ID as a primary key.

#### video_games
Tables users and video_games hold a relationship using the user ID as a foreign key. A video games pool is stored table "video_games", which will be called in the functions to add entries to the futher tables.

#### owned_games
The video games that the user owns can be added to this table by entering the user ID (with the use of a static variable) and video game ID (from table video_games).

#### played_games
Once a video game has been completed, user can add an entry to this table and the data will be identified using the user ID and video game ID.

#### want_to_play_games
Upcoming or not-owned games can be stored in this table, with the use of the user ID and video game ID to identify each entry. Common entries between this table and owned_games are deleted from this table to keep consistency (if one owns a game, one no longer wants to have it, right?).

## Main functions

#### Add user
Input data stored in table "users".
#### Select user
Retrieve data from table "users".
#### Add video game to pool
Input data stored in table "video_games".
#### Add owned game
Input data stored in table "owned_games". This section of the code also deletes any common entry between table "owned_games" and "want_to_play_games" in the latter table.
#### Add played game
Input data stored in table "played_games".
#### Add video game to wanted list
Input data stored in table "want_to_play_games".
#### View video games pool
Retrieve data from table "video_games".
#### View owned games
Retrieve data from table "owned_games".
#### View played games
Retrieve data from table "played_games".
#### View games from wanted list
Retrieve data from table "want_to_play_games".
