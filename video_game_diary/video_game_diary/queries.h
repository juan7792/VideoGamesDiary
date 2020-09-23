#ifndef QUERIES_H_INCLUDED
#define QUERIES_H_INCLUDED

using namespace std;
//Superclass with SQL queries
class SqlQuery
{
	public:
		SqlQuery();  //Constructor
		~SqlQuery(); //Pussy destroyer
		void createDB(const char*);
		void createTables(const char*, string query); //Create tables in DB - different tables created with subclass SqlCreateTables
		void insertData(const char*, string query); //Insert data into DB - data goes to different tables, therefore use of subclass SqlInsertData
};
//Subclass to create necessary tables
class SqlCreateTables : public SqlQuery
{
	public:
		SqlCreateTables(); //Constructor
		~SqlCreateTables(); //Destructor
		//Tables for entities
		void createUsersTable(const char*);
		void createVideoGamesTable(const char*);
		//Tables for actions (relational)
		void createOwnedGamesTable(const char*);
		void createPlayedGamesTable(const char*);
		void createStillPlayingGamesTable(const char*);
		void createWantToPlayGamesTable(const char*);
};
//Subclass to insert data into tables
class SqlInsertData : public SqlQuery
{
	public:
		SqlInsertData(); //Constructor
		~SqlInsertData(); //Destructor
};

#endif // QUERIES_H_INCLUDED