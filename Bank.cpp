Găsește mai repede ceea ce-ți trebuie … Pagina de pornire este noua pagină de destinație și afișează cele mai relevante fișiere și dosare
#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
#include <fstream>
using namespace std;

void meniu_principal()
{

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
    system("Color F0");
    string IDNP,password,nume,prenume;
    string id,pw,nm,pn;
    
    cout<<"Introdu Numele:";
    cin>>nume;
    cout<<"Introdu Prenumele:";
    cin>>prenume;
    cout<<"Introdu IDNP-ul:";
    cin>>IDNP;
    ifstream file(IDNP + ".txt");
        if(!file.is_open())
        {
            system("Color F4");
            cout << "Login invalid,nu exista asa cont "<<endl; 
            Sleep(750);
            system("cls");
            autentificare();  
        }
        cout<<"Introdu parola:";
        cin>>password;
        while (file >> id >> pw >> nm >> pn)
        {
            if (id == IDNP && pw == password && nm == nume && pn == prenume)
            {
                system("Color F9");
                cout<<"Bine ai revenit,"<<nm<<endl;
                cout<<endl;
                Sleep(1250);
                meniu_principal();
            }
            else
            {
                system("Color F4");
                cout<<"Login invalid nu exista asa cont "<<endl;
                Sleep(1250);
                system("cls");
                autentificare();
            }
        }
        return 0;     
}
void inregistrarile_noi()
{
    system("Color F0");
    string nume,prenume,password;
    string IDNP;
    cout<<endl;
    cout<<"Bine ati venit la Moldincombank!"<<endl;
    cout<<"Nume:";
    cin>>nume;
    cout<<"Prenume:";
    cin>>prenume;
    cout<<"Introdu o parola:";
    cin>>password;
    if(password.length() < 6 )
    {
        system("Color F4");
        cout<<"Parola este prea scurta,incearca din nou"<<endl;
        Sleep(1200);
        system("cls");
        inregistrarile_noi();
    }
    cout<<"IDNP:";
    cin>>IDNP;
    if(IDNP.length() != 13)
    {
        system("Color F4");
        cout << "Codul de identificare este prea scurt sau prea lung,incearca din nou!";
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
            system("Color F4");
            cout<<endl;
            cout << "Un cont sub acest IDNP este deja inregistrat,autentificati-va."<<endl;
            Sleep(1200);
            system("cls");
            autentificare();
        }
        else
        {
        system("Color F2");
        cout<<endl;
        cout<<"Ai creat un cont cu succes,acum poti alege optiune de Autentificare in Cont!";
        ofstream myfile; // Creates a file
        myfile.open(IDNP + ".txt"); 
        myfile<<IDNP<<" "<<password<<" "<<nume<<" "<<prenume; 
        myfile.close();
        exit(0);
        }
    }
}


int main() 
{
    int optiune;
    system("Color F0");
    cout<<" __   __  _______  ___      ______   ___   __    _  _______  _______  __   __  _______  _______  __    _  ___   _ "<<endl;
    cout<<"|  |_|  ||       ||   |    |      | |   | |  |  | ||       ||       ||  |_|  ||  _    ||   _   ||  |  | ||   | | |"<<endl;
    cout<<"|       ||   _   ||   |    |  _    ||   | |   |_| ||       ||   _   ||       || |_|   ||  |_|  ||   |_| ||   |_| |"<<endl;
    cout<<"|       ||  | |  ||   |    | | |   ||   | |       ||       ||  | |  ||       ||       ||       ||       ||      _|"<<endl;
    cout<<"|       ||  |_|  ||   |___ | |_|   ||   | |  _    ||      _||  |_|  ||       ||  _   | |       ||  _    ||     |_ "<<endl;
    cout<<"| ||_|| ||       ||       ||       ||   | | | |   ||     |_ |       || ||_|| || |_|   ||   _   || | |   ||    _  |"<<endl;
    cout<<"|_|   |_||_______||_______||______| |___| |_|  |__||_______||_______||_|   |_||_______||__| |__||_|  |__||___| |_|"<<endl;
    cout<<endl;
    cout<<"                                                                                       Made with love by GUESS <3 "<<endl;
    cout<<endl;
    cout<<"Bine ati venit la Moldincombank"<<endl;
    cout<<endl;
    cout<<"[1] Autentificarea in contul bancar"<<endl;
    cout<<"[2] Inregistrare a unui cont bancar nou"<<endl;
    cout<<"[3] Schimb Valutar"<<endl;
    cout<<endl;
    cout<<"[99] Iesire din sistem"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Alegeti o optiune:";
    cin>>optiune;
    switch(optiune)
    {
        case 1 : autentificare(); break;
        case 2 : inregistrarile_noi(); break;
        case 3 : schimb_valutar(); break;
        case 99 : exit(0); break;
        default : 
        system("Color F4");
        cout<<"Optiune inexistenta!"<<endl;
        Sleep(1000);
        system("cls");
        main();
    }
}
    