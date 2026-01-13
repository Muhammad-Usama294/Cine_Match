#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include <windows.h>
#include<graphics.h>
#include "mrs.h"
using namespace std;

//-----------------------------------------Movie Related functions-------------------------------------------
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void MovieRecommendationSystem::find(int id, Movie*&par, Movie*&loc)
{
	if(mroot == NULL)
	{
		loc = NULL;
		par = NULL;
		return;
	}
	if(id == mroot->movieID)
	{
		loc = mroot;
		par = NULL;
		return;
	}
	
	Movie *ptr, *ptrsave;
	
	if(id < mroot->movieID)
		ptr = mroot->lchild;
	else
		ptr = mroot->rchild;
	
	ptrsave = mroot;
	while(ptr!=NULL)
	{
		if(id == ptr->movieID)
		{
			loc = ptr;
			par = ptrsave;
			return;
		}
		ptrsave = ptr;
		if(id<ptr->movieID)
			ptr = ptr->lchild;
		else
			ptr = ptr->rchild;
	}
	loc = NULL;
	par = ptrsave;
}

void MovieRecommendationSystem::addMovie()
{
	Movie* parent, *location;
	char name[STRING_SIZE], genre[STRING_SIZE];
	int id;
	float rating;
	
	cout<<"\nEnter ID of Movie : ";
	id = invalidIntegerInputCheck(); cin.ignore();
	
	find(id, parent, location);
	if(location != NULL)
	{
		cout<<"\nMovie ID Already Exists\n";
		pressKey(); clearScreen();
		return;
	}
	
	cout<<"Enter name of Movie : ";
	cin.getline(name, STRING_SIZE);
	cout<<"Enter Genre : ";
	cin.getline(genre, STRING_SIZE);
	cout<<"Enter imbd rating of Movie : ";
	cin>>rating;
	Movie* movie = new Movie(id, name, genre, rating);
	
	//Adding to treee
	
	
	if(parent == NULL)
		mroot = movie;
	else
	{
		if(id<parent->movieID)
			parent->lchild = movie;
		else
			parent->rchild = movie;
	}
	writeMovieToFile(movie);
	cout<<"\nMovie Added Successfully\n"; pressKey(); clearScreen();
	
}



void MovieRecommendationSystem::display(Movie* ptr, int id, bool& check)
{
	if(mroot == NULL)
	{
		cout<<"No Movies Added\n";
		return;
	}
	if(ptr!=NULL )
	{
		if(id == -1)
		{
			cout<<"\t\t"<<ptr->movieID<<"\t"<<ptr->movieName<<"\t\t"<<ptr->genre<<"\t"<<ptr->imbdRating<<endl;
		}
		if(id != -1)
		{
			if(ptr->movieID == id)
			{
				check = true;
				return;
			}
				
		}
		display(ptr->lchild, id, check);
		display(ptr->rchild, id, check);
	}
}


void MovieRecommendationSystem::writeMovieToFile(Movie* tmpmov)
{
	fstream movieFileHandler;
    movieFileHandler.open(MOVIES_FILE.c_str(), ios::out | ios::app | ios::binary);
    if (!movieFileHandler.is_open())
    {
        cout << "Movie file wasn't opened\n";
        return;
    }

    movieFileHandler.write(reinterpret_cast<char*>(tmpmov), offsetof(Movie, lchild)); // Only write
	 //data up to imbdRating cuz reamining are pointers
    movieFileHandler.close();
}
void MovieRecommendationSystem::readMoviesFromFile()
{
    fstream movieFileHandler(MOVIES_FILE.c_str(), ios::in | ios::binary);
    if (!movieFileHandler.is_open())
    {
        cout << "Movie file wasn't opened\n";
        return;
    }

    while (true)
    {
		Movie* newMovie = new Movie;
		newMovie->lchild=NULL;
		newMovie->rchild=NULL;

        movieFileHandler.read(reinterpret_cast<char*>(newMovie), offsetof(Movie, lchild));

        if (movieFileHandler.eof()) 
            break;
		
        // Insert into the binary tree
        Movie* parent = NULL;
        Movie* location = NULL;
        find(newMovie->movieID, parent, location);

        if (parent == NULL) 
        {
            mroot = newMovie;
        }
        else
        {
            if (newMovie->movieID < parent->movieID)
                parent->lchild = newMovie;
            else
                parent->rchild = newMovie;
        }
    }

    movieFileHandler.close();
}
char nm[40];
void MovieRecommendationSystem::deleteMovie(int id)
{
	Movie *parent, *location;
	if(mroot == NULL)
	{
		cout<<"No Movies to Delete\n";
		return;
	}
	find(id, parent, location);
	
	if(location == NULL)
	{
		cout<<"\nWrong ID... \n"; pressKey(); clearScreen();
		return;
	}
	if(location->lchild == NULL && location->rchild == NULL )
		case_a(parent, location);
	else if(location->lchild != NULL && location->rchild == NULL)
		case_b(parent, location);
	else if(location->lchild == NULL && location->rchild != NULL)
		case_b(parent, location);
	else if(location->lchild != NULL && location->rchild != NULL)
		case_c(parent, location);
	delete(location);
	fstream movieFileHandler(MOVIES_FILE.c_str(), ios::in |ios::out |ios::binary|ios::trunc);
	deleteMovieFromFile(mroot);
	movieFileHandler.close();
}
void MovieRecommendationSystem::case_a(Movie*par, Movie*loc)
{
	if(par == NULL)
		mroot = NULL;
	else
	{
		if(loc == par->lchild)
			par->lchild = NULL;
		else
			par->rchild = NULL;
	}
}
void MovieRecommendationSystem::case_b(Movie*par, Movie*loc)
{
	Movie* child;
	if(loc->lchild != NULL)
		child = loc->lchild;
	else
		child = loc->rchild;
		
	if(par == NULL)
		mroot = child;
	else
	{
		if(loc == par->lchild)
			par->lchild = child;
		else
			par->rchild = child;
	}

}
void MovieRecommendationSystem::case_c(Movie*par, Movie*loc)
{
	Movie* ptr, *ptrsave, *suc, *parsuc;
	ptrsave = loc;
	ptr= loc->rchild;
	while(ptr->lchild != NULL)
	{
		ptrsave = ptr;
		ptr = ptr->lchild;
	}
	suc = ptr;
	parsuc = ptrsave;
	if(suc->lchild == NULL && suc->rchild == NULL)
		case_a(parsuc,suc);
	else
		case_b(parsuc,suc);
	
	if (par == NULL)
		mroot =suc;
	else
	{
		if(loc == par->lchild)
			par->lchild = suc;
		else
			par->rchild = suc;
	}
	
	suc->lchild = loc->lchild;
	suc->rchild = loc->rchild;	
}
void MovieRecommendationSystem::deleteMovieFromFile(Movie *ptr)
{
	if(ptr!=NULL)
	{
		writeMovieToFile(ptr);
		deleteMovieFromFile(ptr->lchild);
		deleteMovieFromFile(ptr->rchild);
	}
	
}
//-----------------------------------------User Related functions-------------------------------------------
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


void MovieRecommendationSystem::find(int id, User*&par, User*&loc)
{
	if(uroot == NULL)
	{
		loc = NULL;
		par = NULL;
		return;
	}
	if(id == uroot->userID)
	{
		loc = uroot;
		par = NULL;
		return;
	}
	
	User *ptr, *ptrsave;
	
	if(id < uroot->userID)
		ptr = uroot->lchild;
	else
		ptr = uroot->rchild;
	
	ptrsave = uroot;
	while(ptr!=NULL)
	{
		if(id == ptr->userID)
		{
			loc = ptr;
			par = ptrsave;
			return;
		}
		ptrsave = ptr;
		if(id<ptr->userID)
			ptr = ptr->lchild;
		else
			ptr = ptr->rchild;
	}
	loc = NULL;
	par = ptrsave;
}
void MovieRecommendationSystem::addUser()
{
	User* parent, *location;
	char name[STRING_SIZE], password[STRING_SIZE];
	int id;
	
	cout<<"\nEnter ID of User : ";
	id = invalidIntegerInputCheck(); cin.ignore();
	
	find(id, parent, location);
	if(location != NULL)
	{
		cout<<"\nUser ID Already Exists\n";
		pressKey(); clearScreen();
		return;
	}
	
	cout<<"Enter name of User : ";
	cin.getline(name, STRING_SIZE);
	cout<<"Enter Password : ";
	cin.getline(password, STRING_SIZE);
	User* user = new User(id,name, password);
	//Adding to treee
	
	
	if(parent == NULL)
		uroot = user;
	else
	{
		if(id<parent->userID)
			parent->lchild = user;
		else
			parent->rchild = user;
	}
	writeUserToFile(user);
	cout<<"\nUser Added Successfully\n"; pressKey(); clearScreen();
}

void MovieRecommendationSystem::display(User* ptr)
{
	if(uroot == NULL)
	{
		cout<<"No Users Entered\n";
		return;
	}
	if(ptr!=NULL)
	{
		display(ptr->lchild);
		cout<<ptr->userID<<"\t"<<ptr->userName<<"\t"<<ptr->password<<endl;
		display(ptr->rchild);
	}
}

bool MovieRecommendationSystem::userTraversal(User* ptr, int Id, int& chkID, int& chkpass)
{
	
	if(ptr!=NULL)
	{
		if(ptr->userID == Id)
		{
			chkID++;
			char pass[STRING_SIZE];
			cout<<"Enter Your Password : ";
			cin.getline(pass, STRING_SIZE);
			if(strcmp(ptr->password, pass)==0 )
			{
				strcpy(nm,ptr->userName);
				chkpass++;
				return true;
			}
			else
			{
				return false;
			}
				
		}
			
		userTraversal(ptr->lchild, Id, chkID,chkpass);
		userTraversal(ptr->rchild, Id, chkID,chkpass);
	}
	return false;
}
int MovieRecommendationSystem::userLogin(int& id)
{
	int ID, chkID = 0, chkpass = 0;
	bool ret;
	cout<<"\n\nEnter your Id : ";
	ID = invalidIntegerInputCheck();
	cin.ignore();
	ret = userTraversal(uroot, ID, chkID,chkpass);
	if(ret == false && chkID == 0)
	{
		cout<<"\nInvalid ID\n"; pressKey(); clearScreen();
		return 0;
	}
	else if(ret == false && chkID == 1 && chkpass == 0)
	{
		cout<<"\nInvalid Password\n";pressKey(); clearScreen();
		return 0; 
	}
	cout<<"\n\n\n\t\t\t\t\tWelcome : "<<nm<<"\t\t\t" << "ID: " <<ID;
	loginScreen();
	id = ID;
	return 1;
}

void MovieRecommendationSystem::writeUserToFile(User* tmpus)
{
	fstream userFileHandler(USERS_FILE.c_str(), ios::out | ios::app | ios::binary);
    if (!userFileHandler.is_open())
    {
        cout << "Users file wasn't opened\n";
        return;
    }

    // Write the data excluding pointers
    userFileHandler.write(reinterpret_cast<char*>(tmpus), offsetof(User, lchild)); // Only write
	 //data up to imbdRating cuz reamining are pointers
    userFileHandler.close();
}


void MovieRecommendationSystem::readUsersFromFile()
{
    fstream userFileHandler(USERS_FILE.c_str(), ios::in | ios::binary);
    if (!userFileHandler.is_open())
    {
        cout << "Users file wasn't opened\n";
        return;
    }

    while (true)
    {
        User* newUser = new User;

        // Read data from the file
        userFileHandler.read(reinterpret_cast<char*>(newUser), offsetof(User, lchild));

        if (userFileHandler.eof())
        {
            delete newUser; 
            break;
        }

        // Insert into the binary tree
        User* parent = NULL;
        User* location = NULL;
        find(newUser->userID, parent, location);

        if (parent == NULL)
        {
            uroot = newUser;
        }
        else
        {
            if (newUser->userID < parent->userID)
                parent->lchild = newUser;
            else
                parent->rchild = newUser;
        }
    }

    userFileHandler.close();
}

//----------------------------------Rating related functions-----------------------------------------------
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void MovieRecommendationSystem::find(int id, Rating*&par, Rating*&loc)
{
	if(rroot == NULL)
	{
		loc = NULL;
		par = NULL;
		return;
	}
	if(id == rroot->uID+rroot->mID)
	{
		loc = rroot;
		par = NULL;
		return;
	}
	
	Rating *ptr, *ptrsave;
	
	if(id < rroot-> uID + rroot->mID)
		ptr = rroot->lchild;
	else
		ptr = rroot->rchild;
	
	ptrsave = rroot;
	while(ptr!= NULL)
	{
		if(id == ptr->uID + ptr->mID)
		{
			loc = ptr;
			par = ptrsave;
			return;
		}
		ptrsave = ptr;
		if(id < ptr->uID + ptr->mID)
			ptr = ptr->lchild;
		else
			ptr = ptr->rchild;
	}
	loc = NULL;
	par = ptrsave;
}

void MovieRecommendationSystem::doRating(int uId, int mId, int rat)
{
	Rating* parent, *location;
	find(uId+mId, parent, location);
	if(location != NULL)
	{
		cout<<"\nYou have already rated this movie\n";
		return;
	}
	Rating* rating = new Rating(rat,mId, uId);
	if(parent == NULL)
		rroot = rating;
	else
	{
		if(uId+mId < parent->uID+parent->mID)
			parent->lchild = rating;
		else
			parent->rchild = rating;
	}
	writeRatingToFile(rating);
	cout<<"\nRating Added Successfully\n"; pressKey(); clearScreen();
}
void MovieRecommendationSystem::display(Rating* ptr)
{
	if(rroot == NULL)
	{
		cout<<"No Ratings Entered\n";
		return;
	}
	if(ptr!=NULL)
	{
		display(ptr->lchild);
		cout<<ptr->mID<<"\t"<<ptr->uID<<"\t"<<ptr->rating<<endl;
		display(ptr->rchild);
	}
}
void MovieRecommendationSystem::ratingTraversal(Rating* ptr, int uid, int mid, int& check, Rating*& tmpListStart)
{
	if(ptr!=NULL)
	{
		if(ptr->uID == uid && (mid == 0 || ptr->mID == mid || mid == -1))
		{
			if(mid == 0)
			{
				cout<<"\t\t\t"<<ptr->mID<<"\t\t"<<ptr->uID<<"\t\t\t"<<ptr->rating<<endl;
				check++;
			}
			else if(mid == -1 && ptr->rating >= 4)
			{
				Rating* tmp = new Rating(ptr->rating, ptr->mID, ptr->uID);
				if(tmpListStart == NULL)
					tmpListStart = tmp;
				else
				{
					Rating*listPtr = tmpListStart;
					while(listPtr->rchild != NULL)
						listPtr = listPtr->rchild;
					listPtr->rchild = tmp;
				}
				check++;
			}
			else
				check++;
		}
		ratingTraversal(ptr->lchild, uid, mid, check, tmpListStart);
		ratingTraversal(ptr->rchild, uid, mid, check, tmpListStart);
	}
}
void MovieRecommendationSystem::deleteRating(Rating* ptr,int id)
{
	int check = 0, movId;
	ratingTraversal(ptr, id, 0, check, ptr);
	if(check == 0)
	{
		cout<<"\nYou have not rated any Movie yet\n"; pressKey(); clearScreen();
		return;
	}
	cout<<"\nEnter Id of the movie to Delete Rating : ";
	movId = invalidIntegerInputCheck();
	check = 0;
	ratingTraversal(rroot, id, movId, check,ptr);
	if(check == 0)
	{
		cout<<"\nWrong Id Entered\n"; pressKey(); clearScreen();
		return;
	}
	deleteRating(id+movId);
	deleteRatingFromFile(ptr);
	cout<<"\nRating Deleted successfully\n"; pressKey(); clearScreen();
}
void MovieRecommendationSystem::deleteRating(int id)
{
	Rating *parent, *location;
	
	find(id, parent, location);
	
	if(location == NULL)
	{
		cout<<"\nWrong ID... \n";
		return;
	}
	if(location->lchild == NULL && location->rchild == NULL )
		case_a(parent, location);
	else if(location->lchild != NULL && location->rchild == NULL)
		case_b(parent, location);
	else if(location->lchild == NULL && location->rchild != NULL)
		case_b(parent, location);
	else if(location->lchild != NULL && location->rchild != NULL)
		case_c(parent, location);
	delete(location);
	fstream ratingFileHandler(RATINGS_FILE.c_str(), ios::in |ios::out |ios::binary|ios::trunc);
	deleteRatingFromFile(rroot);
	ratingFileHandler.close();
}

void MovieRecommendationSystem::case_a(Rating*par, Rating*loc)
{
	if(par == NULL)
		rroot = NULL;
	else
	{
		if(loc == par->lchild)
			par->lchild = NULL;
		else
			par->rchild = NULL;
	}
}
void MovieRecommendationSystem::case_b(Rating*par, Rating*loc)
{
	Rating* child;
	if(loc->lchild != NULL)
		child = loc->lchild;
	else
		child = loc->rchild;
		
	if(par == NULL)
		rroot = child;
	else
	{
		if(loc == par->lchild)
			par->lchild = child;
		else
			par->rchild = child;
	}

}
void MovieRecommendationSystem::case_c(Rating*par, Rating*loc)
{
	Rating* ptr, *ptrsave, *suc, *parsuc;
	ptrsave = loc;
	ptr= loc->rchild;
	while(ptr->lchild != NULL)
	{
		ptrsave = ptr;
		ptr = ptr->lchild;
	}
	suc = ptr;
	parsuc = ptrsave;
	if(suc->lchild == NULL && suc->rchild == NULL)
		case_a(parsuc,suc);
	else
		case_b(parsuc,suc);
	
	if (par == NULL)
		rroot =suc;
	else
	{
		if(loc == par->lchild)
			par->lchild = suc;
		else
			par->rchild = suc;
	}
	
	suc->lchild = loc->lchild;
	suc->rchild = loc->rchild;	
}
void MovieRecommendationSystem::deleteRatingFromFile(Rating *ptr)
{
	if(ptr!=NULL)
	{
		writeRatingToFile(ptr);
		deleteRatingFromFile(ptr->lchild);
		deleteRatingFromFile(ptr->rchild);
	}
	
}

void MovieRecommendationSystem::writeRatingToFile(Rating* tmprat)
{
	fstream ratingFileHandler(RATINGS_FILE.c_str(), ios::out | ios::app | ios::binary);
    if (!ratingFileHandler.is_open())
    {
        cout << "\nRatings file wasn't opened\n";
        return;
    }

    // Write the data excluding pointers
    ratingFileHandler.write(reinterpret_cast<char*>(tmprat), offsetof(Rating, lchild)); // Only write
	 //data up to imbdRating cuz reamining are pointers
    ratingFileHandler.close();
}


void MovieRecommendationSystem::readRatingFromFile()
{
    fstream ratingFileHandler(RATINGS_FILE.c_str(), ios::in | ios::binary);
    if (!ratingFileHandler.is_open())
    {
        cout << "\nRatings file wasn't opened\n";
        return;
    }

    while (true)
    {
        Rating* newRating = new Rating;

        ratingFileHandler.read(reinterpret_cast<char*>(newRating), offsetof(Rating, lchild));

        if (ratingFileHandler.eof()) 
        {
            delete newRating; 
            break;
        }

        // insert in binary tree
        Rating* parent = NULL;
        Rating* location = NULL;
        find(newRating->mID + newRating->uID, parent, location);

        if (parent == NULL) 
        {
            rroot = newRating;
        }
        else
        {
            if (newRating->mID + newRating->uID < parent->mID + parent->uID)
                parent->lchild = newRating;
            else
                parent->rchild = newRating;
        }
    }

    ratingFileHandler.close(); 
}

void MovieRecommendationSystem::movieRecommendation(int uid)
{
	bool check1 = false; 
	Rating* tmpStart = NULL, *tmpStartSimilarUsers = NULL; //have to del this list at end
	int check =0;
	ratingTraversal(rroot, uid, -1,check , tmpStart);
	//we have collected all the movies target user has rated >=4
	if(check == 0)
	{
		//no movie rated... display top imbd
		displaySelectedMovies(mroot, -1, NULL);
		return;
	}
	
	
	
	//Now finding other users who have rated same movies using Rating Tree
	check1 = false;
	Rating* ptr = tmpStart, *q ;
	
	while(ptr != NULL)
	{
		findRatings(rroot, tmpStartSimilarUsers, ptr->mID,0, check1);
		ptr = ptr->rchild;
	}
	if(check1 == false)
	{
		//no similar users... display top imbd
		clearList(tmpStart);
		displaySelectedMovies(mroot, -1,NULL);
		return;
	}
	// now similar Ratings/users are in list starting with tmpStartSimilarUsers	
	
	
	//finding all the other rated movies of selected users
	ptr = tmpStartSimilarUsers;
	tmpStartSimilarUsers = NULL;
	while(ptr != NULL)
	{
		Rating* q = ptr;
		findRatings(rroot,tmpStartSimilarUsers, ptr->uID,1, check1);
		ptr = ptr->rchild;
		delete q;
	}
	
	
	//finally displaying all the other rated movies of selected users
	check = 0;
	check1 = false;
	ptr  = tmpStartSimilarUsers;
	while(ptr != NULL)
	{
		bool check2 = true;
		q = tmpStart;
		while(q!= NULL)
		{
			if(ptr->mID == q->mID)
			{
				check2 = false;
				break;
			}
			q= q->rchild;
		}
		if(check2 == true)
		{
			displaySelectedMovies(mroot,ptr->mID,NULL);
			check++;
			check1 = true;
		}
		ptr = ptr->rchild;
	}
	if(check1 == false || check <=4)
	{
		//selected users have no other movie rated than target user... or 
		// there were less than 5 movies selected.... display top imdb
		displaySelectedMovies(mroot, -1, tmpStartSimilarUsers);
		
		clearList(tmpStart);
		clearList(tmpStartSimilarUsers);
		return;
	}
	// clearing memory from both temporary lists
	clearList(tmpStart);
	clearList(tmpStartSimilarUsers);
}
void MovieRecommendationSystem::findRatings(Rating *ptr, Rating*& tmpListStart, int mId, int scenario, bool& check1)
{
	if(ptr != NULL)
	{
		if(ptr->mID == mId && ptr->rating >=4 && scenario == 0 && ptr->uID != uID)
		{
			bool check = true;
			Rating* q = tmpListStart;
			while(q!= NULL)
			{
				if(ptr->uID == q->uID)
				{
					check = false;
					break;
				}
				q = q->rchild;	
			}
			if(check)
			{
				Rating* tmp = new Rating(ptr->rating, ptr->mID, ptr->uID);
				if(tmpListStart == NULL)
					tmpListStart = tmp;
				else
				{
					Rating*listPtr = tmpListStart;
					while(listPtr->rchild != NULL)
						listPtr = listPtr->rchild;
					listPtr->rchild = tmp;
				}
				check1 = true;
			}
		}
		else if(ptr->uID == mId && ptr->rating >=4 && scenario == 1 && ptr->uID != uID)
		{
			Rating* tmp = new Rating(ptr->rating, ptr->mID, ptr->uID);
			if(tmpListStart == NULL)
				tmpListStart = tmp;
			else
			{
				Rating*listPtr = tmpListStart;
				while(listPtr->rchild != NULL)
					listPtr = listPtr->rchild;
				listPtr->rchild = tmp;
			}
			
		}
		findRatings(ptr->lchild, tmpListStart, mId, scenario, check1);
		findRatings(ptr->rchild, tmpListStart, mId, scenario, check1);
	}
}

void MovieRecommendationSystem::displaySelectedMovies(Movie* ptr, int mId, Rating* list)
{
	if(ptr != NULL)
	{
		if(mId == ptr->movieID)
		{
			cout<<"\t\t"<<ptr->movieID<<"\t"<<ptr->movieName<<"\t\t"<<ptr->genre<<"\t"<<ptr->imbdRating<<endl;
			return;
		}
		if(ptr->imbdRating >= 6.5 && mId == -1)
		{
			Rating *q = list;
			while(q!= NULL)
			{
				if(q->mID == ptr->movieID)
					return;
				q = q->rchild;
			}
			cout<<"\t\t"<<ptr->movieID<<"\t"<<ptr->movieName<<"\t\t"<<ptr->genre<<"\t"<<ptr->imbdRating<<endl;
		}
		displaySelectedMovies(ptr->lchild, mId,list);
		displaySelectedMovies(ptr->rchild, mId, list);
	}
}
 void MovieRecommendationSystem::clearList(Rating* ptr)
 {
 	do
 	{
 		Rating* q= ptr;
 		ptr = ptr->rchild;
 		delete q;
	}while(ptr!=NULL);
 }
 
//----------------------------------Graphics Functions-----------------------------------------------
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

 
//----------------------------------Frequently used functions-----------------------------------------------
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

bool MovieRecommendationSystem::checkFileExist(string fileName)
{
	ifstream infile(fileName.c_str());
	return infile.good();
}
		
		
int MovieRecommendationSystem::invalidIntegerInputCheck()
{
	int n;
	cin >> n;
	while (cin.fail())
	{
		cin.clear();
	    while(cin.get() != '\n')
		{
		}   
	    cout << "\nPlease enter an integer : ";
	    cin >> n;
	    cout<<"\r";
	}
	return n;
}



void MovieRecommendationSystem::displayTitle(){
	cout << "\t\t\t<<<<<<<<<<<---------------MOVIE RECOMMENDATION SYSTEM--------------->>>>>>>>>>>>\n\n";
}

void MovieRecommendationSystem::clearScreen()
{
	system("CLS");
	displayTitle();
}

void MovieRecommendationSystem::pressKey() {
	cout << "\n\nPress any key to continue.....";
	getch();
}
void  MovieRecommendationSystem::loginScreen()
{
	char a = 177, b = 219;
	cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t     | Loging In |\n\n\t\t\t\t\t\t";
	for (int x = 1; x < 26; x++) {
        cout << a;
    }
    cout<<"\r\t\t\t\t\t\t";
    for (int x = 1; x < 26; x++) {
        Sleep(150);
        cout << b;
    }
    clearScreen();
}
void MovieRecommendationSystem::displayInterface()
{
	displayTitle();
	cout<<"Developed By \n\nMuhammad Usama \tSP23_BCS_021 \n\n";
	pressKey();
	clearScreen();
}
