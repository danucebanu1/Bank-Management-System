#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define reset   "\x1B[0m"
#define red     "\x1B[31m"
#define green   "\x1B[32m"
#define yellow  "\x1B[33m"
#define blue    "\x1B[34m"
#define magenta "\x1B[35m"
#define cyan    "\x1B[36m"
#define white   "\x1B[37m"

string IDNP,password,nume,prenume,IDNP2,password1,password2;
string id,pw,nm,pn;
int a;
int balance,b,balance2,amount;
char rs;
int status;

int main();
void inregistrarile_noi();
bool autentificare();
void schimb_valutar();
void main_menu();
void deposit();
void logout();
void transfer();
void withdraw();
void close_account();
void modify_account();
void change_name();
void change_password();

void change_name()
{
    ifstream file(IDNP + "data.txt");
    cout<<"Enter new name:";
    cin>>nume;
    cout<<"Do you wish to change the surname aswell?[Y/N]";
    cin>>rs;
    if (rs=='y'|| rs=='Y')
    {
        cout<<"Enter new surname: ";
        cin>>prenume;
        ofstream fout(IDNP + "data.txt");
        fout<<IDNP<<" "<<password<<" "<<nume<<" "<<prenume;
        fout.close();
        cout<<"Name and Surname changed succesfully!"<<endl;
        sleep(1);
        system("clear");
        main_menu();
    }
    else if(rs=='n' || rs=='N')
    {
        ofstream fiout(IDNP + "data.txt");
        fiout<<IDNP<<" "<<password<<" "<<nume<<" "<<prenume; 
        cout<<"Name changed succesfully!"<<endl;
        sleep(1);
        system("clear");
        main_menu();
    }
}

void change_password()
{
    ifstream file(IDNP + "data.txt");
    cout<<"Enter current password:";
    cin>>password1;
    if(password1 != password)
    {
        cout<<"Incorrect password,try again"<<endl;
        sleep(1);
        system("clear");
        change_password();
    }
    else
    {
        cout<<"Enter new password:";
        cin>>password1;
        cout<<"Re-enter new password:";
        cin>>password2;
        if(password1 == password2)
        {
            ofstream fout(IDNP + "data.txt");
            fout<<IDNP<<" "<<password1<<" "<<nume<<" "<<prenume;
            fout.close();
            cout<<"Password changed successfully!"<<endl;
            sleep(1);
            system("clear");
            main();
        }
        else
        {
            cout<<"Passwords do not match, try again."<<endl;
             sleep(1);
            system("clear");
            change_password();
        }
    }

}

void modify_account()
{
    cout<<endl;
    cout<<"[1] Change Password"<<endl;
    cout<<"[2] Change Name / Surname"<<endl;
    cout<<"Choose option";
    cin>>a;
    switch(a)
    {
        case 1 : change_password(); break;
        case 2 : change_name(); break;
        default :  sleep(1); modify_account();
    }
}

void close_account()
{
    cout<<"Are you sure you want to delete your account?[Y/N]:";
    cin>>rs;
    if(rs=='y' or rs=='Y')
    {
        cout<<"Enter your password to confirm:";
        cin>>password1;
        if(password1==password)
        {
            remove((IDNP + "data.txt").c_str()); 
            remove((IDNP + "balance.txt").c_str());
            cout<<"We are sad seeing you leaving us behind,account deleted succesfully."<<endl;
            sleep(1);
            system("clear");
            main();
        }
        else
        {
            cout<<"Passwords don't match,try again."<<endl;
            close_account();
        }
    }
    else if(rs=='N' or rs=='n')
    {
        sleep(1);
        system("clear");
        main_menu();
    }
    else
    {
        cout<<red;
        cout<<"Enter a valid option."<<endl;
        sleep(1);
        system("clear");
        main_menu();
    }
}

void transfer()
{
    
    ifstream fileIn(IDNP + "balance" + ".txt");
    cout<<"Enter account IDNP:";
    cin>>IDNP2;
    if(IDNP2==IDNP)
    {
        
        cout<<"You can't send money to yourself."<<endl;
        sleep(1);
        transfer();
    }
    ifstream fileN(IDNP2 + "balance" + ".txt" );
    if(!fileN.is_open())
    {
        
        cout<<"This account appears to not exist"<<endl;
        sleep(1);
        system("clear");
        main_menu();
    }
    else
    {
        fileIn>>balance;
        fileIn.close();
        fileN>>balance2;
        fileN.close();
        cout<<"Enter amount(maximum "<<balance<<"$):";
        cin>>amount;
        if(amount>balance)
        {

            cout<<"You don't have enough money,try again."<<endl;
            sleep(1);
            system("clear");
            main_menu();
        }
        else
        {
            balance-=amount;
            balance2+=amount;
            ofstream fileOut(IDNP + "balance" + ".txt");
            fileOut<<balance;
            fileOut.close();
            ofstream fileout(IDNP2 + "balance" + ".txt");
            fileout<<balance2;
            fileout.close();
            cout<<"You succesfully transferred "<<amount<<" to "<<IDNP2<<endl;
            sleep(1);
            system("clear");
            main_menu();
        }
    }
}
void withdraw()
{
    int b,balance;
    ifstream fileIn(IDNP + "balance" + ".txt");
    cout<<"Enter amount:";
    fileIn >> balance;
    cin>>b;
    fileIn.close(); 
    if(balance<b)
    {
        cout<<"You don't have sufficient funds,try again."<<endl;
        sleep(1);
        system("clear");
        main_menu();
    }
    else
    {
    balance -= b; 
    ofstream fileOut;
    fileOut.open(IDNP + "balance" + ".txt");
    fileOut << balance;
    fileOut.close();
    cout<<"You just succesfully withdrawn "<<b<<"$"<<endl;
    main_menu();
    } 
}
void logout()
{
    sleep(1);
    system("clear");
    main();
}
void deposit()
{
    int b,balance=0;
    ifstream fileIn(IDNP + "balance" + ".txt");
    cout<<"Enter amount:";
    fileIn >> balance;
    cin>>b;
    fileIn.close(); 
    balance += b; 
    ofstream fileOut;
    fileOut.open(IDNP + "balance" + ".txt");
    fileOut << balance;
    fileOut.close();
    cout<<"You just replenished your account with "<<b<<"$"<<endl;
    main_menu();
}
void main_menu()
{
    int a;
    ifstream file(IDNP + "balance" + ".txt");
    file>>balance;
    file.close();
    cout<<endl;
    sleep(1);
    system("clear");
    /*cout<<R"(   
   __  ___     _          __  ___             
  /  |/  /__ _(_)__      /  |/  /__ ___  __ __
 / /|_/ / _ `/ / _ \    / /|_/ / -_) _ \/ // /
/_/  /_/\_,_/_/_//_/   /_/  /_/\__/_//_/\_,_/ )"<<endl;*/
    cout<<endl; 
    cout<<"Welcome Back,"<<nume<<"                        Available Balance "<<balance<<"$";
    cout<<endl;
    cout<<endl;
    cout<<"[1] Deposit Amount                    [6] Modify account"<<endl;
    cout<<"[2] Withdraw Amount"<<endl;
    cout<<"[3] Transfer Money"<<endl;
    cout<<"[4] Logout"<<endl;
    cout<<"[5] Close Account"<<endl;
    cout<<endl;
    cout<<"[99] Exit"<<endl;
    cout<<"Enter an option:";
    cin>>a;
    switch(a)
    {
        case 1 : deposit(); break;
        case 2 : withdraw(); break;
        case 3 : transfer(); break;
        case 4 : logout(); break;
        case 5 : close_account(); break;
        case 6 : modify_account(); break;
        case 99 : break;
        default : cout<<"Enter a valid option.";  sleep(1); system("clear"); main_menu();
    }             
}

/*void schimb_valutar()
{
float MDL=1,USD=17.9802,EUR=19.2739,GBP=22.0797,TRY=0.6278,RON=3.8762,UAH=0.4949,RUB=0.1979;
int answer;
float answer1;
cout<<"Introdu valuta:";
cin>>answer;
switch(answer)
{
    case 1 : 
    cout<<"Introdu valoarea in MDL:";
    cin>>answer1;
    cout<<answer1<<" MDL este echivalent cu "<<answer1/USD<<" USD"<<endl;
    break;
    case 2 :
    cout<<"Introdu valoarea in MDL:";
    cin>>answer1;
    cout<<answer1<<" MDL este echivalent cu "<<answer1/EUR<<" EUR"<<endl;
    break;
    case 3 :
    cout<<"Introdu valoarea in MDL:";
    cin>>answer1;
    cout<<answer1<<" MDL este echivalent cu "<<answer1/GBP<<" GBP"<<endl;
    break;
    
}*/


bool autentificare()
{
    cout<<"       Enter Name:";
    cin>>nume;
    cout<<"       Enter Surname:";
    cin>>prenume;
    cout<<"       Enter Password:";
    cin>>password;
    cout<<"       Enter your Identification Number:";
    cin>>IDNP;
    ifstream file(IDNP + "data" + ".txt");
        if(!file.is_open())
        {
            cout << "       Invalid Credentials."<<endl; 
            sleep(1);
            system("clear");
            autentificare();  
        }
        while (file >> id >> pw >> nm >> pn)
        {
            if (id == IDNP && pw == password && nm == nume && pn == prenume)
            main_menu();
            else
            {
                cout<<"       Invalid Credentials."<<endl;
                sleep(1);
                system("clear");
                autentificare();
            }
        }  
}

void inregistrarile_noi()
{
    string nume,prenume,password;
    string IDNP;
    cout<<endl;
    cout<<"       Welcome to National Bank of Moldova."<<endl;
    cout<<"       Name:";
    cin>>nume;
    cout<<"       Surname:";
    cin>>prenume;
    cout<<"       Enter a pasword:";
    cin>>password;
    if(password.length() < 6 )
    {
        cout<<"       Password lenght should be at least 6 characters,try again."<<endl;
        sleep(1);
        system("clear");
        inregistrarile_noi();
    }
    cout<<"IDNP:";
    cin>>IDNP;
    if(IDNP.length() != 13)
    {
        cout << "       The Identification Number should be 13 characters,try again.";
        sleep(1);
        system("clear");
        inregistrarile_noi();
    }
    else
    {
        string filename = IDNP + "data" + ".txt";
        ifstream file(filename);
        
        if (file.is_open())
        {
            cout<<endl;
            cout << "       An Account under this Identification Number was already created,you can choose to authentificate."<<endl;
            sleep(1);
            system("clear");
            main();
        }
        else
        {
        cout<<endl;
        cout<<"       You created an account with succes,you can log into your Bank Account now!";
        ofstream myfile; // Creates a file
        myfile.open(IDNP + "data" + ".txt"); 
        myfile<<IDNP<<" "<<password<<" "<<nume<<" "<<prenume; 
        myfile.close();
        sleep(1);
        system("clear");
        main();
        }
    }
}
int main() 
{
    int optiune;
    /*cout<<R"(    
      _   __      __  _                   __   __                __      __  ___      __    __                    
     / | / /___ _/ /_(_)___  ____  ____ _/ /  / /_  ____ _____  / /__   /  |/  /___  / /___/ /___ _   ______ _    
    /  |/ / __ `/ __/ / __ \/ __ \/ __ `/ /  / __ \/ __ `/ __ \/ //_/  / /|_/ / __ \/ / __  / __ \ | / / __ `/    
   / /|  / /_/ / /_/ / /_/ / / / / /_/ / /  / /_/ / /_/ / / / / ,<    / /  / / /_/ / / /_/ / /_/ / |/ / /_/ /     
  /_/ |_/\__,_/\__/_/\____/_/ /_/\__,_/_/  /_.___/\__,_/_/ /_/_/|_|  /_/  /_/\____/_/\__,_/\____/|___/\__,_/      )"<<endl;*/
    cout<<endl;
    cout<<"       Welcome to National Bank of Moldova                                Made with love by guess <3 "<<endl;
    cout<<endl;
    cout<<"       [1] Login into your Bank Account                                                    [99] Exit"<<endl;
    cout<<"       [2] Register a new Bank Account"<<endl;
    cout<<"       [3] Currency Exchange                                                                         "<<endl;
    cout<<endl;
    cout<<"       Choose an option:";
    cin>>optiune;
    switch(optiune)
    {
        case 1 : autentificare(); break;
        case 2 : inregistrarile_noi(); break;
        case 3 :  break;
        case 99 : exit(0); break;
        default : sleep(1); system("clear"); main();
    }
}

/* Color id	Color	Color id	Color
    1	    Blue	       9	Light Blue
    2	    Green	       0	Black
    3	    Aqua	       A	Light Green
    4	    Red	           B	Light Aqua
    5	    Purple	       C	Light Red
    6	    Yellow	       D	Light Purple
	7       White	       E	Light Yellow
    8	    Gray	       F	Bright White*/