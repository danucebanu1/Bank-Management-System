#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;

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
        Sleep(500);
        system("cls");
        main_menu();
    }
    else if(rs=='n' || rs=='N')
    {
        ofstream fiout(IDNP + "data.txt");
        fiout<<IDNP<<" "<<password<<" "<<nume<<" "<<prenume; 
        cout<<"Name changed succesfully!"<<endl;
        Sleep(500);
        system("cls");
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
        Sleep(3000);
        system("cls");
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
            Sleep(500);
            system("cls");
            main();
        }
        else
        {
            cout<<"Passwords do not match, try again."<<endl;
            Sleep(3000);
            system("cls");
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
        default : system("Color 04"); Sleep(200); modify_account();
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
            system("Color 06");
            remove((IDNP + "data.txt").c_str()); 
            remove((IDNP + "balance.txt").c_str());
            cout<<"We are sad seeing you leaving us behind,account deleted succesfully."<<endl;
            Sleep(750);
            system("cls");
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
        Sleep(100);
        system("cls");
        main_menu();
    }
    else
    {
        system("Color 04");
        cout<<"Enter a valid option."<<endl;
        Sleep(200);
        system("cls");
        main_menu();
    }
}

void transfer()
{
    system("Color 09");
    ifstream fileIn(IDNP + "balance" + ".txt");
    cout<<"Enter account IDNP:";
    cin>>IDNP2;
    if(IDNP2==IDNP)
    {
        system("Color 04");
        cout<<"You can't send money to yourself."<<endl;
        Sleep(500);
        transfer();
    }
    ifstream fileN(IDNP2 + "balance" + ".txt" );
    if(!fileN.is_open())
    {
        system("Color 04");
        cout<<"This account appears to not exist"<<endl;
        Sleep(500);
        system("cls");
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
            system("Color 04");
            cout<<"You don't have enough money,try again."<<endl;
            Sleep(500);
            system("cls");
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
            Sleep(500);
            system("cls");
            main_menu();
        }
    }
}
void withdraw()
{
    system("Color 09");
    int b,balance;
    ifstream fileIn(IDNP + "balance" + ".txt");
    cout<<"Enter amount:";
    fileIn >> balance;
    cin>>b;
    fileIn.close(); 
    if(balance<b)
    {
        system("Color 04");
        cout<<"You don't have sufficient funds,try again."<<endl;
        Sleep(300);
        system("cls");
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
    Sleep(200);
    system("cls");
    main();
}
void deposit()
{
    system("Color 09");
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
    system("Color 09");
    int a;
    ifstream file(IDNP + "balance" + ".txt");
    file>>balance;
    file.close();
    cout<<endl;
    Sleep(500);
    system("cls");
    cout<<
    R"(   
   __  ___     _          __  ___             
  /  |/  /__ _(_)__      /  |/  /__ ___  __ __
 / /|_/ / _ `/ / _ \    / /|_/ / -_) _ \/ // /
/_/  /_/\_,_/_/_//_/   /_/  /_/\__/_//_/\_,_/ )"<<endl;
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
        default : system("Color 04"); cout<<"Enter a valid option."; Sleep(500); system("cls"); main_menu();
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
    system("Color 09");
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
            system("Color 04");
            cout << "       Invalid Credentials."<<endl; 
            Sleep(750);
            system("cls");
            autentificare();  
        }
        while (file >> id >> pw >> nm >> pn)
        {
            if (id == IDNP && pw == password && nm == nume && pn == prenume)
            main_menu();
            else
            {
                system("Color 04");
                cout<<"       Invalid Credentials."<<endl;
                Sleep(750);
                system("cls");
                autentificare();
            }
        }  
}

void inregistrarile_noi()
{
    system("Color 09");
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
        system("Color 04");
        cout<<"       Password lenght should be at least 6 characters,try again."<<endl;
        Sleep(1200);
        system("cls");
        inregistrarile_noi();
    }
    cout<<"IDNP:";
    cin>>IDNP;
    if(IDNP.length() != 13)
    {
        system("Color 04");
        cout << "       The Identification Number should be 13 characters,try again.";
        Sleep(1200);
        system("cls");
        inregistrarile_noi();
    }
    else
    {
        string filename = IDNP + "data" + ".txt";
        ifstream file(filename);
        
        if (file.is_open())
        {
            system("Color 04");
            cout<<endl;
            cout << "       An Account under this Identification Number was already created,you can choose to authentificate."<<endl;
            Sleep(1200);
            system("cls");
            main();
        }
        else
        {
        system("Color 02");
        cout<<endl;
        cout<<"       You created an account with succes,you can log into your Bank Account now!";
        ofstream myfile; // Creates a file
        myfile.open(IDNP + "data" + ".txt"); 
        myfile<<IDNP<<" "<<password<<" "<<nume<<" "<<prenume; 
        myfile.close();
        Sleep(1200);
        system("cls");
        main();
        }
    }
}
int main() 
{
    int optiune;
    system("Color 09");
    cout<<R"(    
      _   __      __  _                   __   __                __      __  ___      __    __                    
     / | / /___ _/ /_(_)___  ____  ____ _/ /  / /_  ____ _____  / /__   /  |/  /___  / /___/ /___ _   ______ _    
    /  |/ / __ `/ __/ / __ \/ __ \/ __ `/ /  / __ \/ __ `/ __ \/ //_/  / /|_/ / __ \/ / __  / __ \ | / / __ `/    
   / /|  / /_/ / /_/ / /_/ / / / / /_/ / /  / /_/ / /_/ / / / / ,<    / /  / / /_/ / / /_/ / /_/ / |/ / /_/ /     
  /_/ |_/\__,_/\__/_/\____/_/ /_/\__,_/_/  /_.___/\__,_/_/ /_/_/|_|  /_/  /_/\____/_/\__,_/\____/|___/\__,_/      )"<<endl;
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
        default : system("Color 04"); Sleep(1000); system("cls"); main();
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