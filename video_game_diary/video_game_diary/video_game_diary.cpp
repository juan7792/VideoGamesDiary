// video_game_diary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>  //standard input/output stream objects
#include <stdio.h>
#include <sqlite3.h> //declaration of sqlite3 functions
#include "queries.h" //header file with declaration of classes and instances

using namespace std;

void createAllTables(const char*);

int main()
{
	//directory address pointer
	const char* dir = "C:\\Users\\Juan\\Desktop\\video_game_diary\\video_games.db";
	//class object
	SqlQuery sqldb;

	//class methods
	sqldb.createDB(dir);
	createAllTables(dir);

	return 0;
}

void createAllTables(const char* directory)
{
	SqlCreateTables sqltables;

	sqltables.createUsersTable(directory);
	sqltables.createVideoGamesTable(directory);
	sqltables.createOwnedGamesTable(directory);
	sqltables.createPlayedGamesTable(directory);
	sqltables.createStillPlayingGamesTable(directory);
	sqltables.createWantToPlayGamesTable(directory);
}