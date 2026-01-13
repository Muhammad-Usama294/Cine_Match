#include<iostream>
#include<string>
#include "mrs.h"
using namespace std;
int main()
{
	MovieRecommendationSystem mrs;
	mrs.displayInterface();
	int choice,rating, id;
	while(true)
	{
		cout<<"\n\t\t\t\t1. Login\n";
		cout<<"\t\t\t\t2. SignUp\n";
		cout<<"\t\t\t\t3. Exit\n";
		cout<<"Enter your choice : ";
		choice = mrs.invalidIntegerInputCheck();
		cin.ignore();
		switch(choice)
		{
			case 1:
				{
					bool check = true;
					mrs.mroot = NULL;
					mrs.uroot = NULL;
					mrs.rroot = NULL;
					if(mrs.checkFileExist(USERS_FILE) == true)
					{
						mrs.readUsersFromFile();
						cout<<"\nEnter your credentials to Login\n\n";
						if(mrs.userLogin(mrs.uID) == 0)
						{
							break;
						}
					}
					
					else
					{
						cout<<"\nNo User ID to login\n";
						break;
					}
					
					if(mrs.checkFileExist(MOVIES_FILE) == true)
						mrs.readMoviesFromFile();
					if(mrs.checkFileExist(RATINGS_FILE) == true)
						mrs.readRatingFromFile();
					
					
					while(check)
					{
						cout<<"\n\t\t\t\t1. Add a new Movie \n";
						cout<<"\t\t\t\t2. Display Movies List\n";
						cout<<"\t\t\t\t3. Add a new User \n";
						cout<<"\t\t\t\t4. Display Users List\n";
						cout<<"\t\t\t\t5. Rate a Movie\n";
						cout<<"\t\t\t\t6. Delete a Movie\n";
						cout<<"\t\t\t\t7. Remove any of your previous Ratings\n";
						cout<<"\t\t\t\t8. Recommended Movies For You\n";
						cout<<"\t\t\t\t30. Display Ratings\n";
						cout<<"\t\t\t\t0. Logout\n";
						cout<<"\nEnter You Choice : ";
						choice = mrs.invalidIntegerInputCheck();
						switch(choice)
						{
							case 1:
								{
									mrs.addMovie();
									break;
								}
							case 2:
								{
									bool check = false;
									cout<<"\n\t\t\t\tThe List of Movies is\n";
									cout<<"\n\t\t\t\t---------------------\n";
									cout<<"\t\tID\tName\t\tGenre\tIMDB\n";
									cout<<"\t\t--\t----\t\t-----\t----\n";
									mrs.display(mrs.mroot,-1, check);
									mrs.pressKey(); mrs.clearScreen();
									break;
								}
							case 3:
								{
									mrs.addUser();
									break;
								}
							case 4:
								{
									mrs.display(mrs.uroot);
									mrs.pressKey(); mrs.clearScreen();
									break;
								}
							case 5:
								{
									bool check = false;
									cout<<"\n\t\t\t\tThe List of Movies is\n";
									cout<<"\n\t\t\t\t---------------------\n";
									cout<<"\t\tID\tName\t\tGenre\tIMDB\n";
									cout<<"\t\t--\t----\t\t-----\t----\n";
									mrs.display(mrs.mroot, -1, check);
									cout<<"Enter the ID of movie to rate : ";
									id = mrs.invalidIntegerInputCheck();
									mrs.display(mrs.mroot,id, check);
									if(check == false)
									{
										cout<<"\nInvalid Id\n"; mrs.pressKey(); mrs.clearScreen();
										break;
									}
									cout<<"Give Rating (1-5) : ";
									rating = mrs.invalidIntegerInputCheck();
									if(rating<1 || rating>5)
									{
										cout<<"\nInvalid Rating\n";
										mrs.pressKey(); mrs.clearScreen();
									}
									mrs.doRating(mrs.uID, id, rating);
									break;
								}
							case 6:
								{
									bool check =false;
									cout<<"\n\t\t\t\tThe List of Movies is\n";
									cout<<"\n\t\t\t\t---------------------\n";
									cout<<"\t\tID\tName\t\tGenre\tIMDB\n";
									cout<<"\t\t--\t----\t\t-----\t----\n";
									mrs.display(mrs.mroot,-1,check );
									cout<<"Enter the ID of movie to Delete : ";
									id = mrs.invalidIntegerInputCheck();
									mrs.deleteMovie(id);
									break;
								}
							case 7:
								{
									cout<<"\t\t\t"<<"Movie ID"<<"\t"<<"User ID"<<"\t\t"<<"Rating Given"<<endl;
									cout<<"\t\t\t"<<"--------"<<"\t"<<"-------"<<"\t"<<"------------"<<"\n\n";
									mrs.deleteRating(mrs.rroot, mrs.uID);
									break;
								}
							case 8:
								{
									if(mrs.mroot == NULL)
									{
										cout<<"\nColdStart... No Movies in Database\n";
										break;
									}
									cout<<"\n\t\t\t\tMovies Recommended for You are\n";
									cout<<"\n\t\t\t\t------------------------------\n";
									cout<<"\t\tID\tName\t\tGenre\tIMDB\n";
									cout<<"\t\t--\t----\t\t-----\t----\n";
									mrs.movieRecommendation(mrs.uID);
									mrs.pressKey(); mrs.clearScreen();
									break;
								}
							case 30:
								{
									mrs.display(mrs.rroot);
									break;
								}
							case 0:
								{
									mrs.clearScreen();
									check = false;
									break;
								}
							default:
								{
									cout<<"\nInvalid Choice\n"; mrs.pressKey();mrs.clearScreen();
								}
						}
					}
					break;
				}
			case 2:
				{
					mrs.addUser();
					cout<<"\n\nYour account has Been created.... Enter Your credential to login\n\n";
					mrs.pressKey();mrs.clearScreen();
					break;
				}
			case 3:
				exit(0);
			default:
				{
					cout<<"\nInvalid Choice\n"; mrs.pressKey();mrs.clearScreen();
				}
		}
	}
}
