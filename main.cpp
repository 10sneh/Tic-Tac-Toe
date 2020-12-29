#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>

int firstpage();
int Login();
using namespace std;

void DisplayHeader();

fstream F,G;
//Creating the Admin Class
class admin
{

private:
    int id,chk;

public:
    admin()
{
    id=0;
    chk=0;
}

    int AdminMenu();
    void addmovie();
    void show_selected_movie();
    void displayMovies();
    void deleteMovie();
    void bookTicket();
    void disp_bkd_tkt();


};
//Creating The Guest Class
//Used inheritance to access Functions from admin class

class guest : public admin
{
public:
    int GuestMenu();




};
//Creating objects of admin and guest class
admin aobj;
guest gobj;

class MovieInfo
{ public:
    int mid;
	char movie_name[200];
	char time[50];
	int max_seats;
	int booked;
	int price;
	public:
	MovieInfo()
	{
	mid=0;
	max_seats=50;
	booked=0;
	price=0;
	strcpy(time,"9:10am");
	strcpy(movie_name,"");
	}
	void input();
	void show();
	void display();
	int getid() //to get movie id from the users
	{
	return mid;
	}
	void book()
	{
	booked++;
	}
	char* getMoviename()
	{
	return movie_name;
	}
	char* getTime()
	{
	return time;
	}
	int getBooked(){
	return booked;
	}
	int getMax(){
	return max_seats;
	}
	int getFare()
	{
		return price;
	}
};
class Ticket
{
	char name[50];
	MovieInfo mov; //Object is created
	public:

	void generate(char cname[], MovieInfo tb)
	{
		strcpy(name,cname);
		mov=tb;
	}
	void display() //Display The Details
	{
	cout<<"Customer Name "<<name<<endl;
	cout<<"Details of Movie "<<endl;
	mov.show();
		}
};
void MovieInfo::input()
{
   int c=0;
     try
    {
        cout<<" Enter Movie Id : ";
        cin>>mid;
         if(mid>0)
            c++;
         else
            throw(mid);
    }
            catch(int i)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout<<"Exception Caught: Movie Id should be a numeric value"<<endl;//This prevents user from entering anything else than a numeric value.
                system("pause");
                system("CLS");
                aobj.AdminMenu();
            }




	cout<<"Enter movie name ";
	getchar();
    gets(movie_name);
	cout<<"Enter time of movie ";
	cin>>time;
	cout<<"Enter price of the movie ";
	cin>>price;
}
void MovieInfo::display()
{
	cout<<mid<<"\t"<<movie_name<<"\t"<<time<<"\t"<<max_seats<<"\t"<<booked<<"\t"<<price<<"\n";
}
void MovieInfo::show()
{
	cout<<"Movie Id "<<mid<<endl;
	cout<<"Movie Name "<<movie_name<<endl;
	cout<<"Time "<<time<<endl;
	cout<<"No. of seats remaining "<<max_seats-booked<<endl;
	cout<<""<<endl;

}



int main()
{

    firstpage();
    return 0;
}


int firstpage()
{

    DisplayHeader();

    int choice;
    int c=0;


    cout<<" [1] Login " << endl;
    cout<<" [2] Exit \n\n " << endl;
    cout<<" Press 1 to Login and 2 to Exit \n" << endl;//Exception Handling used so that we cannot enter anything except 1 and 2
    try
    {
        cout<<" Enter your choice : ";
        cin>>choice;
         if(choice==1||choice==2)
            c++;
         else
            throw(choice);
    }
            catch(int c)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout<<"Exception Caught: Choice should be either 1 or 2"<<endl;
                system("pause");
            }

            /*If The Choice Entered is 1 The Program Goes to the Login Page
            If the Choice Entered is 2 Then We Exit*/

    switch(choice)
    {
    case 1:
        Login();

    case 2:
        exit(0);
    default:
        firstpage();
    }

}


int Login()
{
DisplayHeader();//The Display header function is called And the Header is Displayed
string Username;
int c=0;

 cout << " If logging in as a guest, type Guest as the username."<<endl<<endl;
 /*If we Enter 'Guest' (Without The Single inverted commas) we go to The Guest Page
 If we Enter 'Admin' (Without The Single inverted commas) And Enter the password as 'pass'(Without The Single inverted commas) we go to the Admin page */

 try
    {
        cout<<" Username: ";
        cin>>Username;
         if(Username=="Guest"||Username=="Admin")
            c++;
         else
            throw(Username);
    }
            catch(string i)
            {
                cout<<"Exception Caught: Username should be either Admin or Guest"<<endl;
                system("pause");
                Login();
            }

 if (Username == "Guest")
 {
     cout << "Loging in as a guest\n" << endl;

     system(" pause ");
     gobj.GuestMenu();
 }
if (Username == "Admin")
{

        cout<<"Enter password : ";
        char pass[10];
        int p = 0;
        do{
            pass[p]=getch();
            if(pass[p]!='\r')
            {
                cout<<"*";
            }p++;

        }while(pass[p-1]!='\r');
        pass[p-1]='\0';
        cout<<""<<endl;


        if(strcmp(pass,"pass")==0)
        {
            system(" pause ");
            aobj.AdminMenu();
        }
        else
        {
            Login();
        }



}

 }

 int guest::GuestMenu() //The layout of the Guest Menu where if we enter the choice we go to the corresponding function
 {
     DisplayHeader();
     int choice;
     int c=0;
     cout <<"[1] View All Movies : "<< endl;
     cout <<"[2] Buy Ticket : "<< endl ;
     cout <<"[3] Log Out : "<<endl;
     try
    {
        cout<<" Enter your choice : ";
        cin>>choice;
         if(choice==1||choice==2||choice==3)
            c++;
         else
            throw(choice);
    }
            catch(int c)
            {

                cin.clear();
                cin.ignore(100, '\n');
                cout<<"Exception Caught: Choice should be either 1, 2 or 3"<<endl;
                system("pause");
                gobj.GuestMenu();
            }


     switch(choice)
     {
     case 1:
        gobj.displayMovies();
        gobj.GuestMenu();
     case 2:
        gobj.bookTicket();
        gobj.GuestMenu();
     case 3:
       firstpage();

     }


 }


 int admin::AdminMenu()//The layout of the Admin Menu where if we enter the choice we go to the corresponding function
{
	DisplayHeader();
	int ch;
	int c=0;
	fstream F,G;
	MovieInfo b;



		cout<<"Press 1 - Add a New Movie"<<endl;
		cout<<"Press 2 - Show Selected Movie"<<endl;
		cout<<"Press 3 - Display All Movies"<<endl;
		cout<<"Press 4 - Delete a Movie"<<endl;
		cout<<"Press 5 - Book a ticket "<<endl;
		cout<<"Press 6 - Display Booked Tickets "<<endl;
		cout<<"Press 7 - Exit "<<endl;
		try
    {
        cout<<" Enter your choice : ";
        cin>>ch;
         if(ch==1||ch==2||ch==3||ch==4||ch==5||ch==6||ch==7)
            c++;
         else
            throw(ch);
    }
            catch(int c)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout<<"Exception Caught: Choice should be between 1 - 7"<<endl;
                system("pause");
                system("CLS");
                aobj.AdminMenu();
            }


		switch(ch)
		{
		case 1:
			{

			 aobj.addmovie();

		break;}
		case 2:
			{
			    aobj.show_selected_movie();
                break;
			}
        case 3:
			{
			    aobj.displayMovies();
			    aobj.AdminMenu()
;		         break;}
		case 4:
			{
			     aobj.deleteMovie();
			      break;}
		case 5:
			{
                aobj.bookTicket();
                aobj.AdminMenu();
			     break;}
		case 6:
			{
			     aobj.disp_bkd_tkt();
			     break;
			}
		case 7:
            {
                firstpage();
                break;
            }

		}

}
/*The Admin can Add Movies
He can enter Movie id, Movie Name, Movie Time Price*/

void admin::addmovie()
{DisplayHeader();
MovieInfo b;
F.open("tour.dat",ios::app | ios::binary);
//Open a .dat file so that we store the details and access when needed and also we cant change it without using the program
			b.input();
			F.write((char*)&b, sizeof(b));
			F.close();
			cout<<"Movie added Successfully "<<endl;
            system("pause");
			system("CLS");
			aobj.AdminMenu();
}


void admin::show_selected_movie()
{   DisplayHeader();
    MovieInfo b;

			cout<<"Enter the Movie id to be displayed ";
			cin>>id;
			F.open("tour.dat",ios::in | ios::binary);
			if(F.fail())
				cout<<"Can't open file "<<endl;
			else
			{
				while(F.read((char*)&b,sizeof(b)))
				{
					if(b.getid()==id)
					{
						b.show();
						chk=1;
						break;
					}
				}
				if(chk==0)
					cout<<"Movie not Found"<<endl;
			}
			F.close();
			system("pause");//It pauses and when we press any key it continues again
			system("CLS");
			aobj.AdminMenu();
}


void admin::displayMovies()//Displays all the Movies and its details
{
    DisplayHeader();
    MovieInfo b;
    fstream f;
    f.open("tour.dat",ios::in| ios:: binary);
    //The Layout of the Table
    //The Headings
    cout<<"\n\t\t---------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\t\t|"<<setw(20)<<"MOVIE ID |"<<setw(20)<<"MOVIE NAME |"<<setw(20)<<"TIME |"<<setw(20)<<"TOTAL TICKETS |"<<setw(20)<<"TOTAL TICKETS BOOKED |"<<setw(20)<<"PRICE  |";
    cout<<"\n\t\t---------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\t\t|"<<setw(20)<<" |"<<setw(20)<<" |"<<setw(20)<<" |"<<setw(20)<<" |"<<setw(22)<<" |"<<setw(20)<<" |"<<endl;
    while(f.read((char*)&b,sizeof(b))){
//Entering the Saved Things And Print It
        cout<<"\t\t|"<<setw(18)<<b.mid<<" |"<<setw(18)<<b.movie_name<<" |"<<setw(18)<<b.time<<" |"<<setw(18)<<50<<" |"<<setw(20)<<b.booked<<" |"<<setw(18)<<b.price<<" |";
        cout<<endl;
    }
    cout<<"\t\t|"<<setw(20)<<" |"<<setw(20)<<" |"<<setw(20)<<" |"<<setw(20)<<" |"<<setw(22)<<" |"<<setw(20)<<" |";
    cout<<"\n\t\t---------------------------------------------------------------------------------------------------------------------------\n";
    cout<<endl;
    f.close();
    system("pause");
    system("CLS");

}

void admin::deleteMovie()//Delete the movie by entering movie id.
{   DisplayHeader();
    MovieInfo b;

			cout<<"Enter the Movie id to be deleted ";
			cin>>id;
			F.open("tour.dat",ios::in | ios::binary);
			G.open("temp.dat",ios::out | ios::binary);
			if(F.fail())
				cout<<"Can't open file "<<endl;
			else
			{
				while(F.read((char*)&b,sizeof(b)))
				{
					if(b.getid()!=id)
					{
					G.write((char*)&b,sizeof(b));
					}
					else
					{
						b.show();
						chk=1;

					}
				}
				if(chk==0)
					cout<<"Movie not Found"<<endl;

				else
					cout<<"Movie Deleted "<<endl;
			}
			F.close();
			G.close();
			remove("tour.dat");
			rename("temp.dat","tour.dat");
			system("pause");
			system("CLS");
			aobj.AdminMenu();
}


void admin::bookTicket()//Book the Tickets By Entering the Movie name And then add a Customer Name
{    DisplayHeader();
    MovieInfo b;
    char movie[70],cname[50];

			Ticket t;
			cout<<"Enter the movie name ";
			getchar();
            gets(movie);
			F.open("tour.dat",ios::in | ios::out | ios::binary);
			if(F.fail())
				cout<<"Can't open file "<<endl;
			else
			{
				while(F.read((char*)&b,sizeof(b)))
				{
					if(strcmpi(b.getMoviename(),movie)==0)
					{
						b.show();
						chk=1;
						cout<<"Enter the customer name ";
						cin>>cname;
						b.book();
						t.generate(cname,b);
						G.open("tickets.dat",ios::app | ios::binary);
						G.write((char*)&t,sizeof(t));
						G.close();
					F.seekp(F.tellg()-sizeof(b),ios::beg);

					F.write((char*)&b,sizeof(b));

					cout<<"Ticket booked"<<endl;

					break;
					}
				}
				if(chk==0)
					cout<<"No Movie Found"<<endl;

			}
			F.close();
			system("pause");
			system("CLS");


}


void admin::disp_bkd_tkt()//Display all The Booked Tickets
{
    DisplayHeader();
    MovieInfo b;
    Ticket t;
			    cout<<"Booked Tickets "<<endl;
			G.open("tickets.dat",ios::in | ios::binary);
			if(G.fail())
				cout<<"can't open file "<<endl;
			else
			{
				while(G.read((char*)&t,sizeof(t)))
				t.display();
			}

			G.close();
			system("pause");
			system("CLS");
			aobj.AdminMenu();
}


void DisplayHeader()
{
system("cls");
cout << endl;
// Upper Border
cout << " \xC9";
for (int i = 0; i < 76; i++)
cout << "\xCD";
cout << "\xBB";
cout << endl;
// Middle Border
cout << " \xBA";
// [FROM_HERE TO_HERE]
cout << " Movie Reservation System ";
cout << "\xBA";
cout << endl;
// Upper Border
cout << " \xC8";
for (int i = 0; i < 76; i++)
cout << "\xCD";
cout << "\xBC";
cout << endl;
cout << endl;
}


