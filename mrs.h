#ifndef MRS_H
#define MRS_H
#include<cstring>
using namespace std;
const int STRING_SIZE = 40;
const std::string MOVIES_FILE = "Movies.txt";
const std::string USERS_FILE = "Users.txt";
const std::string RATINGS_FILE = "ratings.txt";

struct Movie
{
	int movieID;
	char movieName[STRING_SIZE];
	char genre[STRING_SIZE];
	float imbdRating;
	Movie* lchild;
	Movie* rchild;
	
	Movie(int ID, char* name, char* gen, float rat)
	{
		movieID= ID;
		strncpy(movieName, name, STRING_SIZE - 1);
			movieName [STRING_SIZE - 1] = '\0';
		strncpy(genre, gen, STRING_SIZE - 1);
			genre [STRING_SIZE - 1] = '\0';
		movieID = ID;
		imbdRating = rat;
		lchild = NULL;
		rchild = NULL; 
	}
	Movie() : movieID(0), imbdRating(0.0f), lchild(NULL), rchild(NULL) {
        movieName[0] = '\0';
        genre[0] = '\0';
    }
};
struct User
{
	int userID;
	char userName[STRING_SIZE];
	char password[STRING_SIZE];
	User* lchild;
	User* rchild;
	
	User(int ID, char* name, char* pass)
	{
		userID = ID;
		
		strncpy(userName, name, STRING_SIZE - 1);
		userName [STRING_SIZE - 1] = '\0';
		
		strncpy(password, pass, STRING_SIZE - 1);
		password [STRING_SIZE - 1] = '\0';
		
		rchild = NULL;
		lchild = NULL;
	}
	User(): userID(0),lchild(NULL), rchild(NULL){
		userName[0] = '\0';
		password[0] = '\0';
		}
};

struct Rating
{
	int rating;
	int mID;
	int uID;
	Rating* lchild;
	Rating* rchild;
	
	Rating(int rat, int mId, int uId)
	{
		rating = rat;
		mID = mId;
		uID = uId;
		lchild = NULL;
		rchild = NULL;
	}
	Rating(): rating(0), mID(0), uID(0), lchild(NULL), rchild(NULL){}
	
};

struct MovieRecommendationSystem
{
	Movie *mroot ;
	User* uroot ;
	Rating* rroot ;
	int uID;
	
	void find(int, Movie*&, Movie*&);
	void find(int, User*&, User*&);
	void find(int, Rating*&, Rating*&);
	
	void addMovie();
	void deleteMovie(int);
	void case_a(Movie*par, Movie*loc);
	void case_b(Movie*par, Movie*loc);
	void case_c(Movie*par, Movie*loc);
	
	void addUser();
	bool userTraversal(User*, int, int&, int&);
	int userLogin(int&);
	
	void doRating(int, int, int);
	void deleteRating(Rating*, int);
	void deleteRating(int);
	void case_a(Rating*par, Rating*loc);
	void case_b(Rating*par, Rating*loc);
	void case_c(Rating*par, Rating*loc);
	
	void ratingTraversal(Rating*, int, int, int&, Rating*&);
	
	void display(Movie*, int, bool&);
	void display(User*);
	void display(Rating*);
	
	//File Haandling Functions
	void writeMovieToFile(Movie*);
	void readMoviesFromFile();
	void deleteMovieFromFile(Movie*);
	
	void writeUserToFile(User*);
	void readUsersFromFile();
	
	void writeRatingToFile(Rating*);
	void readRatingFromFile();
	void deleteRatingFromFile(Rating*);
	
	void movieRecommendation(int);
	void findRatings(Rating *ptr, Rating*& tmpListStart, int mId, int, bool&);
	void displaySelectedMovies(Movie*, int, Rating*);
	void clearList(Rating*);
	
	void  displayMoviesTree();
	
	//Frequently used functions
	void  loginScreen();
	bool checkFileExist(string fileName);
	int invalidIntegerInputCheck();
	void displayInterface();
	void displayTitle();
	void clearScreen();
	void pressKey(); 
	
} ;
#endif
