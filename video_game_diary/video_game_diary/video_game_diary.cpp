// video_game_diary.cpp : This file contains the 'main' function. Program execution begins and ends there.
// QLO

#include <iostream>  //standard input/output stream objects
#include <stdio.h>
#include <sqlite3.h> //declaration of sqlite3 functions
#include "queries.h" //header file with declaration of classes and instances

using namespace std;
//methods to avoid unnecessary use of space by class instances
void methodCreateDB(const char*);
void createAllTables(const char*);

int main()
{
	//directory address pointer
	const char* dir = "C:\\Users\\Juan\\Desktop\\video_game_diary\\video_games.db";
	
	//functions calling class methods
	methodCreateDB(dir);
	createAllTables(dir);

	SqlInsertData sqlInsertData;
	//sqlInsertData.insertDataUsersTable(dir);
	//sqlInsertData.insertDataVideoGamesTable(dir);
	//sqlInsertData.insertDataOwnedGamesTable(dir);
	//sqlInsertData.insertDataPlayedGamesTable(dir);
	//sqlInsertData.insertDataStillPlayingGamesTable(dir);
	sqlInsertData.insertDataWantToPlayGamesTable(dir);

	SqlSelectData sqlSelectData;
	//sqlSelectData.selectDataUsersTable(dir);
	//sqlSelectData.selectDataVideoGamesTable(dir);
	//sqlSelectData.selectDataOwnedGamesTable(dir);
	//sqlSelectData.selectDataPlayedGamesTable(dir);
	//sqlSelectData.selectDataStillPlayingGamesTable(dir);
	sqlSelectData.selectDataWantToPlayGamesTable(dir);

	return 0;
}

void methodCreateDB(const char* directory)
{
	SqlQuery sqldb;

	sqldb.createDB(directory);
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