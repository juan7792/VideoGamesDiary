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
		void selectData(const char*, string query); //Select data from tables - data comes from different tables, therefore use of subclass SqlSelectData
		// retrieve contents of database used by selectData()
		/* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array */
		static int callback(void* NotUsed, int argc, char** argv, char** azColName);
};
//Subclass to create necessary tables
class SqlCreateTables : public SqlQuery
{
	public:
		SqlCreateTables(); //Constructor
		~SqlCreateTables(); //Destructor
		/*----- TABLES USING METHOD OF SUPERCLASS -----*/
		//Tables for entities
		void createUsersTable(const char*); //users
		void createVideoGamesTable(const char*); //video games
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
		/*----- TABLES USING METHOD OF SUPERCLASS -----*/
		//Tables for entities
		void insertDataUsersTable(const char*); //users
		void insertDataVideoGamesTable(const char*); //video games
		//Tables for actions (relational)
		void insertDataOwnedGamesTable(const char*);
		void insertDataPlayedGamesTable(const char*);
		void insertDataStillPlayingGamesTable(const char*);
		void insertDataWantToPlayGamesTable(const char*);
};
//Subclass to retrieve data from tables
class SqlSelectData : public SqlQuery
{
public:
	SqlSelectData(); //Constructor
	~SqlSelectData(); //Destructor
	/*----- TABLES USING METHOD OF SUPERCLASS -----*/
	//Tables for entities
	void selectDataUsersTable(const char*); //users
	void selectDataVideoGamesTable(const char*); //video games
	//Tables for actions (relational)
	void selectDataOwnedGamesTable(const char*);
	void selectDataPlayedGamesTable(const char*);
	void selectDataStillPlayingGamesTable(const char*);
	void selectDataWantToPlayGamesTable(const char*);
};
#endif // QUERIES_H_INCLUDED