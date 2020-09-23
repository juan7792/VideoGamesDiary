#include <iostream>
#include "queries.h"
#include <stdio.h>
#include <sqlite3.h>

using namespace std;

/*----- SUPERCLASS SqlQuery -----*/
//Constructor
SqlQuery::SqlQuery()
{
	
}
//Destructor
SqlQuery::~SqlQuery()
{
	
}
//Create DB method - input pointer to variable that stores directory
void SqlQuery::createDB(const char* s)
{
	sqlite3* DB;
	int exit = 0; //declare and initialize instance exit = 0 and will change if there is an error in SQL

	exit = sqlite3_open(s, &DB); //open/create DB using address of directory and pointer DB address

	sqlite3_close(DB); //close DB

}
//Create tables method - input pointer to variable that stores directory and string with query to create table
void SqlQuery::createTables(const char* s, string query)
{
	sqlite3* DB;

	try
	{
		int exit = 0; //declare and initialize instance exit = 0 and will change if there is an error in SQL
		exit = sqlite3_open(s, &DB); //open DB

		char* messageError;
		exit = sqlite3_exec(DB, query.c_str(), NULL, 0, &messageError);
		//if error in query, exit != 0
		if (exit != SQLITE_OK)
		{
			cerr << "Error Create Table" << endl;
			sqlite3_free(messageError);
		}
		sqlite3_close(DB);
	}
	catch (const exception & e)
	{
		cerr << e.what();
	}
}
//Insert data method - input pointer to variable that stores directory and string with query to create table
void SqlQuery::insertData(const char* s, string query)
{
	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open(s, &DB);

	exit = sqlite3_exec(DB, query.c_str(), NULL, 0, &messageError);

	if (exit != SQLITE_OK)
	{
		cerr << "Error Insert" << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records created successfully!" << endl;
}

/*----- SUBCLASS SqlCreateTables -----*/
//Constructor
SqlCreateTables::SqlCreateTables() : SqlQuery() //call constructor of superclass, Maigualida
{

}
//Destructor
SqlCreateTables::~SqlCreateTables()
{

}
//Create "users" table
void SqlCreateTables::createUsersTable(const char* s)
{
	string sql = "CREATE TABLE IF NOT EXISTS users("
		"id INTEGER PRIMARY KEY, "
		"username TEXT NOT NULL); ";

	createTables(s, sql);

}
//Create "video_games" table
void SqlCreateTables::createVideoGamesTable(const char* s)
{
	string sql = "CREATE TABLE IF NOT EXISTS video_games("
		"id INTEGER PRIMARY KEY, "
		"video_game_name TEXT NOT NULL, "
		"release_date TEXT NOT NULL, "
		"console TEXT NOT NULL); ";

	createTables(s, sql);

}
//Create "owned_games" table
void SqlCreateTables::createOwnedGamesTable(const char* s)
{
	string sql = "CREATE TABLE IF NOT EXISTS owned_games("
		"user_id INTEGER, "
		"video_game_id INTEGER, "
		"video_game_name TEXT, "  //to avoid using a JOIN when retrieving table (simple laziness in the cunt)
		"observations TEXT NOT NULL, "
		"FOREIGN KEY(user_id) REFERENCES users(id), "
		"FOREIGN KEY(video_game_id) REFERENCES video_games(id)); ";

	createTables(s, sql);

}
//Create "played_games" table
void SqlCreateTables::createPlayedGamesTable(const char* s)
{
	string sql = "CREATE TABLE IF NOT EXISTS played_games("
		"user_id INTEGER, "
		"video_game_id INTEGER, "
		"video_game_name TEXT, "  //to avoid using a JOIN when retrieving table (simple laziness in the cunt)
		"end_date TEXT NOT NULL, "
		"rating INTEGER, "
		"observations TEXT NOT NULL, "
		"FOREIGN KEY(user_id) REFERENCES users(id), "
		"FOREIGN KEY(video_game_id) REFERENCES video_games(id)); ";

	createTables(s, sql);

}
//Create "still_playing_games" table
void SqlCreateTables::createStillPlayingGamesTable(const char* s)
{
	string sql = "CREATE TABLE IF NOT EXISTS still_playing_games("
		"user_id INTEGER, "
		"video_game_id INTEGER, "
		"video_game_name TEXT, "  //to avoid using a JOIN when retrieving table (simple laziness in the cunt)
		"last_played_date TEXT NOT NULL, "
		"FOREIGN KEY(user_id) REFERENCES users(id), "
		"FOREIGN KEY(video_game_id) REFERENCES video_games(id)); ";

	createTables(s, sql);

}
//Create "want_to_play_games" table
void SqlCreateTables::createWantToPlayGamesTable(const char* s)
{
	string sql = "CREATE TABLE IF NOT EXISTS want_to_play_games("
		"user_id INTEGER, "
		"video_game_id INTEGER, "
		"video_game_name TEXT, "  //to avoid using a JOIN when retrieving table (simple laziness in the cunt)
		"rating_interest INTEGER, "
		"observations TEXT NOT NULL, "
		"FOREIGN KEY(user_id) REFERENCES users(id), "
		"FOREIGN KEY(video_game_id) REFERENCES video_games(id)); ";

	createTables(s, sql);

}
/*----- SUBCLASS SqlInsertData -----*/
//Constructor
SqlInsertData::SqlInsertData() : SqlQuery() //call constructor of superclass, Maigualida
{

}
//Destructor
SqlInsertData::~SqlInsertData()
{

}

