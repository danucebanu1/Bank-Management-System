
#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
#include <fstream>
#include <sstream>
using namespace std;

string IDNP,password,nume,prenume,IDNP2;
string id,pw,nm,pn;
int a;
int balance,b,balance2,amount;

/* Color id	Color	Color id	Color
    1	    Blue	       9	Light Blue
    2	    Green	       0	Black
    3	    Aqua	       A	Light Green
    4	    Red	           B	Light Aqua
    5	    Purple	       C	Light Red
    6	    Yellow	       D	Light Purple
	7       White	       E	Light Yellow
    8	    Gray	       F	Bright White*/

int main();
void inregistrarile_noi();
bool autentificare();
void schimb_valutar();
void main_menu();
void deposit();
void logout();
void transfer();
void withdraw();
void transfer()
{
    ifstream fileIn(IDNP + "balance" + ".txt");
    cout<<"    Enter account IDNP:";
    cin>>IDNP2;
    ifstream fileN(IDNP2 + "balance" + ".txt" );
    if(!fileN.is_open())
    {
        system("Color 04");
        cout<<"    This account appears to not exist"<<endl;
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
        cout<<"    Enter amount(maximum "<<balance<<"):";
        cin>>amount;
        if(amount>balance)
        {
            system("Color 04");
            cout<<"    You don't have enough money,try again."<<endl;
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
            cout<<"    You succesfully transferred"<<amount<<" to "<<IDNP2<<endl;
            Sleep(500);
            system("cls");
            main_menu();
        }
    }
}
void withdraw()
{
    int b,balance;
    ifstream fileIn(IDNP + "balance" + ".txt");
    cout<<"    Enter amount:";
    fileIn >> balance;
    cin>>b;
    fileIn.close(); 
    if(balance<b)
    {
        system("Color 04");
        cout<<"    You don't have sufficient funds,try again."<<endl;
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
    cout<<"    You just succesfully withdrawn "<<b<<"$"<<endl;
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
    int b,balance;
    ifstream fileIn(IDNP + "balance" + ".txt");
    cout<<"    Enter amount:";
    fileIn >> balance;
    cin>>b;
    fileIn.close(); 
    balance += b; 
    ofstream fileOut;
    fileOut.open(IDNP + "balance" + ".txt");
    fileOut << balance;
    fileOut.close();
    cout<<"    You just replenished your account with "<<b<<"$"<<endl;
    main_menu();
}
void main_menu()
{
    system("Color 0F");
    int a;
    ifstream file(IDNP + "balance" + ".txt");
    file>>balance;
    file.close();
    cout<<endl;
    Sleep(500);
    system("cls");
    cout<<
    R"(
    ___  ___      _        ___  ___                 
    |  \/  |     (_)       |  \/  |                 
    | .  . | __ _ _ _ __   | .  . | ___ _ __  _   _ 
    | |\/| |/ _` | | '_ \  | |\/| |/ _ \ '_ \| | | |
    | |  | | (_| | | | | | | |  | |  __/ | | | |_| |
    \_|  |_/\__,_|_|_| |_| \_|  |_/\___|_| |_|\__,_|)"<<endl;
    cout<<endl; 
    cout<<"    Welcome Back,"<<prenume<<"                        Available Balance "<<balance<<"$";
    cout<<endl;
    cout<<"    [1] Deposit Amount"<<endl;
    cout<<"    [2] Withdraw Amount"<<endl;
    cout<<"    [3] Transfer Money"<<endl;
    cout<<"    [4] Logout"<<endl;
    cout<<endl;
    cout<<"    [99] Exit"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"    Enter an option:";
    cin>>a;
    switch(a)
    {
        case 1 : deposit(); break;
        case 2 : withdraw(); break;
        case 3 : transfer(); break;
        case 4 : logout(); break;
        case 99 : break;
        default : system("Color 04"); cout<<"Enter a valid option."; Sleep(500); system("cls"); main_menu();
    }             
}

void schimb_valutar()
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
    
}

}
bool autentificare()
{
    system("Color 0F");
    cout<<"Enter Name:";
    cin>>nume;
    cout<<"Enter Surname:";
    cin>>prenume;
    cout<<"Enter your Identification Number:";
    cin>>IDNP;
    cout<<"Enter Password:";
    cin>>password;
    ifstream file(IDNP + ".txt");
        if(!file.is_open())
        {
            system("Color 04");
            cout << "Invalid Credentials."<<endl; 
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
                cout<<"Invalid Credentials."<<endl;
                Sleep(750);
                system("cls");
                autentificare();
            }
        }  
}
void inregistrarile_noi()
{
    system("Color 0F");
    string nume,prenume,password;
    string IDNP;
    cout<<endl;
    cout<<"Welcome to National Bank of Moldova."<<endl;
    cout<<"Name:";
    cin>>nume;
    cout<<"Surname:";
    cin>>prenume;
    cout<<"Enter a pasword:";
    cin>>password;
    if(password.length() < 6 )
    {
        system("Color 04");
        cout<<"Password lenght should be at least 6 characters,try again."<<endl;
        Sleep(1200);
        system("cls");
        inregistrarile_noi();
    }
    cout<<"IDNP:";
    cin>>IDNP;
    if(IDNP.length() != 13)
    {
        system("Color 04");
        cout << "The Identification Number should be 13 characters,try again.";
        Sleep(1200);
        system("cls");
        inregistrarile_noi();
    }
    else
    {
        string filename = IDNP + ".txt";
        ifstream file(filename);
        
        if (file.is_open())
        {
            system("Color 04");
            cout<<endl;
            cout << "An Acconut under this Identification Number was already created,you can choose to authentificate."<<endl;
            Sleep(1200);
            system("cls");
            main();
        }
        else
        {
        system("Color 02");
        cout<<endl;
        cout<<"You created an account with succes,you can log into your Bank Account now!";
        ofstream myfile; // Creates a file
        myfile.open(IDNP + ".txt"); 
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
    system("Color 0F");
    cout<<R"(    
    _   __      __  _                   __   __                __      __  ___      __    __                    
   / | / /___ _/ /_(_)___  ____  ____ _/ /  / /_  ____ _____  / /__   /  |/  /___  / /___/ /___ _   ______ _    
  /  |/ / __ `/ __/ / __ \/ __ \/ __ `/ /  / __ \/ __ `/ __ \/ //_/  / /|_/ / __ \/ / __  / __ \ | / / __ `/    
 / /|  / /_/ / /_/ / /_/ / / / / /_/ / /  / /_/ / /_/ / / / / ,<    / /  / / /_/ / / /_/ / /_/ / |/ / /_/ /     
/_/ |_/\__,_/\__/_/\____/_/ /_/\__,_/_/  /_.___/\__,_/_/ /_/_/|_|  /_/  /_/\____/_/\__,_/\____/|___/\__,_/      )"<<endl;
    cout<<endl;
    cout<<"Welcome to National Bank of Moldova                                Made with love by guess <3 "<<endl;
    cout<<endl;
    cout<<"[1] Login into your Bank Account"<<endl;
    cout<<"[2] Register a new Bank Account"<<endl;
    cout<<"[3] Currency Exchange"<<endl;
    cout<<endl;
    cout<<"[99] Exit"<<endl;
    cout<<endl;
    cout<<"Choose an option:";
    cin>>optiune;
    switch(optiune)
    {
        case 1 : autentificare(); break;
        case 2 : inregistrarile_noi(); break;
        case 3 : schimb_valutar(); break;
        case 99 : exit(0); break;
        default : 
        system("Color 04");
        cout<<"Choose a valid option!"<<endl;
        Sleep(1000);
        system("cls");
        main();
    }
}
