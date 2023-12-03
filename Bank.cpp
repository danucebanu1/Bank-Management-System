
#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
#include <fstream>
#include <sstream>
using namespace std;

string IDNP,password,nume,prenume;
string id,pw,nm,pn;
int a;
string balance,b;

int main();
void inregistrarile_noi();
bool autentificare();
void schimb_valutar();
void main_menu();
void deposit();
void logout();

void logout()
{
    Sleep(200);
    system("cls");
    main();
}

void deposit()
{
    ifstream file(IDNP + "balance" + "txt");
    cout<<"    Enter amount:";
    cin>>balance;
    if(!file.is_open())
    {
        ofstream file;
        file.open(IDNP + "balance" + ".txt");
        file << balance;
        file.close();
    }
    else
    {
        file >> balance;
        balance += balance;
    }
    cout<<endl;
    cout<<"    You just replenished your account with "<<balance<<"$";
}
void main_menu()
{
    int a;
    ifstream file;
    file.open(IDNP+ "balance" + "txt");
    file >> balance;
    if(!file.is_open())
    cout<<"File can't be opened"<<endl;
    cout<<endl;
    Sleep(500);
    system("cls");
    cout<<R"(
    ___  ___      _        ___  ___                 
    |  \/  |     (_)       |  \/  |                 
    | .  . | __ _ _ _ __   | .  . | ___ _ __  _   _ 
    | |\/| |/ _` | | '_ \  | |\/| |/ _ \ '_ \| | | |
    | |  | | (_| | | | | | | |  | |  __/ | | | |_| |
    \_|  |_/\__,_|_|_| |_| \_|  |_/\___|_| |_|\__,_|)"<<endl;
    cout<<endl; 
    cout<<"    Welcome Back,"<<prenume<<"                        Available Balance "<<balance<<"$";
    file.close();
    cout<<endl;
    cout<<"    [1] Deposit Amount"<<endl;
    cout<<"    [2] Withdraw Amount"<<endl;
    cout<<"    [3] Transfer Money"<<endl;
    cout<<"    [4] Add New Card"<<endl;
    cout<<"    [5] Logout"<<endl;
    cout<<endl;
    cout<<"    [99] Exit"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"    Enter an option:";
    cin>>a;
    switch(a)
    {
        case 1 : deposit(); break;
        case 5 : logout(); break;
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
 _______          __  .__                     .__    __________                __             _____     _____         .__       .___                   
 \      \ _____ _/  |_|__| ____   ____ _____  |  |   \______   \_____    ____ |  | __   _____/ ____\   /     \   ____ |  |    __| _/_______  _______   
 /   |   \\__  \\   __\  |/  _ \ /    \\__  \ |  |    |    |  _/\__  \  /    \|  |/ /  /  _ \   __\   /  \ /  \ /  _ \|  |   / __ |/  _ \  \/ /\__  \  
/    |    \/ __ \|  | |  (  <_> )   |  \/ __ \|  |__  |    |   \ / __ \|   |  \    <  (  <_> )  |    /    Y    (  <_> )  |__/ /_/ (  <_> )   /  / __ \_
\____|__  (____  /__| |__|\____/|___|  (____  /____/  |______  /(____  /___|  /__|_ \  \____/|__|    \____|__  /\____/|____/\____ |\____/ \_/  (____  /
        \/     \/                    \/     \/               \/      \/     \/     \/                        \/                  \/                 \/ )"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Welcome to National Bank of Moldova                                                    Made with love by guess <3 "<<endl;
    cout<<endl;
    cout<<"[1] Login into your Bank Account"<<endl;
    cout<<"[2] Register a new Bank Account"<<endl;
    cout<<"[3] Currency Exchange"<<endl;
    cout<<endl;
    cout<<"[99] Exit"<<endl;
    cout<<endl;
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
