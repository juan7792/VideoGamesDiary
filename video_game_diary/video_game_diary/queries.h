#ifndef QUERIES_H_INCLUDED
#define QUERIES_H_INCLUDED

using namespace std;
//Superclass with SQL queries
class SqlQuery
{
	private:
		//static int userID; //ID that will be selected in first menu and will then be used in second menu
	public:
		SqlQuery();  //Constructor
		~SqlQuery(); //Pussy destroyer
		void createDB(const char*);
		void createTables(const char*, string); //Create tables in DB - different tables created with subclass SqlCreateTables
		void insertData(const char*, string); //Insert data into DB - data goes to different tables, therefore use of subclass SqlInsertData
		void selectData(const char*, string); //Select data from tables - data comes from different tables, therefore use of subclass SqlSelectData
		/* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array */
		static int callback(void* NotUsed, int argc, char** argv, char** azColName);
		static string userID; //ID that will be selected in first menu and will then be used in second menu
		static string getID();
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
	static int counterSelectData; //used to break first loop - NOT USED, JUST A POSSIBILITY
};
#endif // QUERIES_H_INCLUDED