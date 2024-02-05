#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

string generateCreditCardNumber(string prefix, int length)
{
    string cardNumber = prefix;
    int additionalLength = length - prefix.length();
    
    while(additionalLength--)
    {
        int digit = rand() % 10;
        cardNumber += to_string(digit);
    }
    
    return cardNumber;
}

#define reset   "\x1B[0m"
#define red     "\x1B[31m"
#define green   "\x1B[32m"
#define yellow  "\x1B[33m"
#define blue    "\x1B[34m"
#define magenta "\x1B[35m"
#define cyan    "\x1B[36m"
#define white   "\x1B[37m"

string IDNP,password,nume,prenume,IDNP2,password1,password2,type;
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
void create_card();
void classic();
void gold();
void platinum();
void elite();
void worldclass();

void worldclass()
{
    ifstream file(IDNP + "balance" + ".txt");
    file>>balance;
    file.close();
    if(balance < 70)
    {
        cout<<red<<"You don't have enough funds"<<endl;
        sleep(1);
        system("clear");
        create_card();
    }
    else if(balance >= 70)
    {
        string cardnumber = generateCreditCardNumber("5188" , 16);
        string cvv = generateCreditCardNumber("1" , 3);
        cout<<"Advantages of the Mastercard WorldClass Card"<<endl;
        cout<<"Fees - 15$ per month"<<endl;
        cout<<"Comfortable - Free P2P Transfers"<<endl;
        cout<<"Maximum daily transfer - No Daily Limit"<<endl;
        cout<<"Price - 70$"<<endl;
        cout<<"Cashback - 7% for every purchase you make"<<endl;
        cout<<"Fast - payment takes 6 seconds to process"<<endl;
        cout<<"Loyalty - you get to stay in a first class lounge in every airport with the WorldClass Elite card"<<endl;
        cout<<"Sales - get 25% sale in every grocery store and our parteners stores"<<endl;
        cout<<endl;
        cout<<"Are you sure you want to submit this card?[Y/N]:";
        cin>>rs;
        if(rs == 'Y' or rs=='y')
        {
            balance = balance - 70;
            ofstream fileOut(IDNP + "balance" + ".txt");
            fileOut<<balance;
            fileOut.close();
            cout<<endl<<"Card Number:"<<cardnumber<<endl;
            cout<<"CVV:"<<cvv<<endl;
            cout<<"Expiration Date:12/28"<<endl;
            cout<<"Cardholder Name:"<<nume<<' '<<prenume<<endl;
              fstream fin(IDNP + "card.txt");
            if(!fin.is_open())
            {
                ofstream file(IDNP  + "card.txt");
                file << cardnumber << " " << cvv << " " << "WorldClass"<<" "<<"12/28";
                file.close();
            }
            else
            {
                ifstream fias(IDNP + "card2.txt");
                if(!fias.is_open())
                {
                ofstream file(IDNP + "card2.txt");
                file << cardnumber << " " << cvv << " " << "WorldClass"<<" "<<"12/28";
                file.close();
                }
                else
                {
                    ifstream fial(IDNP + "card3.txt");
                    if (!fial.is_open())
                    {
                    ofstream file(IDNP + "card3.txt");
                    file << cardnumber << " " << cvv << " " << "WorldClass"<<" "<<"12/28";
                    file.close();
                    }
                    else
                    {
                        ifstream fial(IDNP + "card4.txt");
                        if(!fial.is_open())
                        {
                        ofstream  file(IDNP + "card4.txt");
                        file << cardnumber << " " << cvv << " " << "WorldClass"<<" "<<"12/28";
                        file.close();
                        }
                        else    
                        {
                            ifstream fial(IDNP + "card5.txt");
                            if(!fial.is_open())
                            {
                            ofstream file(IDNP +  "card5.txt");
                            file << cardnumber << " " << cvv << " " << "WorldClass"<<" "<<"12/28";
                            file.close();
                            }
                            else
                            {
                                cout<<red<<"You reached the limit to creating cards. (5/5)"<<endl;
                                sleep(1);
                                system("clear");
                                main_menu();
                            }
                        }
                    }
                }
            }
            ofstream file;        
            file << cardnumber << " " << cvv << " " << "WorldClass"<<" "<<"12/28";
            file.close();
            cout<<"You have just became the owner of the Mastercard Worldclass Card"<<endl;
            cout<<"Please keep your CVV safe, as it is used for identification purposes."<<endl;
            sleep(5);
            main_menu();
        }
        else if(rs == 'n' or rs == 'N')
        {
            system("clear");
            create_card();
        }
    }
}

void elite()
{
    if(balance<50)
    {
        cout<<red<<"You don't have enough funds"<<endl;
        sleep(1);
        system("clear");
        create_card();
    }

        string cardnumber = generateCreditCardNumber("5188" , 16);
        string cvv = generateCreditCardNumber("1" , 3);
        cout<<"Advantages of the Mastercard Elite Card"<<endl;
        cout<<"Fees - 7$ per month"<<endl;
        cout<<"Comfortable - Free P2P Transfers"<<endl;
        cout<<"Maximum daily transfer - 5000$"<<endl;
        cout<<"Price - 50$ "<<endl;
        cout<<"Cashback - 3% for every purchase you make"<<endl;
        cout<<"Fast - payment takes 6 seconds to process"<<endl;
        cout<<"Loyalty - you get to stay in a business lounge in every airport with the Elite card"<<endl;
        cout<<"Sales - get 20% sale in every grocery store and our parteners stores"<<endl;
        cout<<endl;
        cout<<"Are you sure you want to submit this card?[Y/N]:";
        cin>>rs;
        if(rs == 'Y' or rs=='y')
        {
            balance -= 50;
            ofstream fileOut(IDNP + "balance" + ".txt");
            fileOut<<balance;
            fileOut.close();
            cout<<endl<<"Card Number:"<<cardnumber<<endl;
            cout<<"CVV:"<<cvv<<endl;
            cout<<"Expiration Date:12/28"<<endl;
            cout<<"Cardholder Name:"<<nume<<' '<<prenume<<endl;
              fstream fin(IDNP + "card.txt");
            if(!fin.is_open())
            {
                ofstream file(IDNP  + "card.txt");
                file << cardnumber << " " << cvv << " " << "Elite"<<" "<<"12/28";
                file.close();
            }
            else
            {
                ifstream fias(IDNP + "card2.txt");
                if(!fias.is_open())
                {
                ofstream file(IDNP + "card2.txt");
                file << cardnumber << " " << cvv << " " << "Elite"<<" "<<"12/28";
                file.close();
                }
                else
                {
                    ifstream fial(IDNP + "card3.txt");
                    if (!fial.is_open())
                    {
                    ofstream file(IDNP + "card3.txt");
                    file << cardnumber << " " << cvv << " " << "Elite"<<" "<<"12/28";
                    file.close();
                    }
                    else
                    {
                        ifstream fial(IDNP + "card4.txt");
                        if(!fial.is_open())
                        {
                        ofstream  file(IDNP + "card4.txt");
                        file << cardnumber << " " << cvv << " " << "Elite"<<" "<<"12/28";
                        file.close();
                        }
                        else    
                        {
                            ifstream fial(IDNP + "card5.txt");
                            if(!fial.is_open())
                            {
                            ofstream file(IDNP +  "card5.txt");
                            file << cardnumber << " " << cvv << " " << "Elite"<<" "<<"12/28";
                            file.close();
                            }
                            else 
                            {
                                cout<<red<<"You reached the limit to creating cards. (5/5)"<<endl;
                                sleep(1);
                                system("clear");
                                main_menu();
                            }
                        }
                    }
                }
            }
            ofstream file;
                file << cardnumber << " " << cvv << " " << "Elite"<<" "<<"12/28";
                file.close();
            cout<<"You have just became the owner of the Mastercard Elite Card"<<endl;
            cout<<"Please keep your CVV safe, as it is used for identification purposes."<<endl;
            sleep(5);
            main_menu();
        }
        else if(rs == 'n' or rs == 'N')
        {
            system("clear");
            create_card();
        }
}

void platinum()
{
    if(balance < 30)
    {
        cout<<red<<"You don't have enough funds"<<endl;
        sleep(1);
        system("clear");
        create_card();
    }
    else
    {
        string cardnumber = generateCreditCardNumber("5188" , 16);
        string cvv = generateCreditCardNumber("1" , 3);
        cout<<"Advantages of the Mastercard Platinum Card"<<endl;
        cout<<"Fees - 5$ per month"<<endl;
        cout<<"Comfortable - Free P2P Transfers"<<endl;
        cout<<"Maximum daily transfer - 2500$"<<endl;
        cout<<"Price - 30$ upfront cost"<<endl;
        cout<<"Cashback - 1% for every purchase you make"<<endl;
        cout<<"Fast - payment takes 6 seconds to process"<<endl;
        cout<<"Sales - get 10% sale in every grocery store and our parteners stores"<<endl;
        cout<<endl;
        cout<<"Are you sure you want to submit this card?[Y/N]:";
        cin>>rs;
        if(rs == 'Y' or rs=='y')
        {
                balance -= 30;
                ofstream fileOut(IDNP + "balance" + ".txt");
                fileOut<<balance;
                fileOut.close();
                cout<<endl<<"Card Number:"<<cardnumber<<endl;
                cout<<"CVV:"<<cvv<<endl;
                cout<<"Expiration Date:12/28"<<endl;
                cout<<"Cardholder Name:"<<nume<<' '<<prenume<<endl;
                fstream fin(IDNP + "card.txt");
            if(!fin.is_open())
            {
                ofstream file(IDNP  + "card.txt");
                file << cardnumber << " " << cvv << " " << "Platinum"<<" "<<"12/28";
                file.close();
            }
            else
            {
                ifstream fias(IDNP + "card2.txt");
                if(!fias.is_open())
                {
                ofstream file(IDNP + "card2.txt");
                file << cardnumber << " " << cvv << " " << "Platinum"<<" "<<"12/28";
                file.close();
                }
                else
                {
                    ifstream fial(IDNP + "card3.txt");
                    if (!fial.is_open())
                    {
                    ofstream file(IDNP + "card3.txt");
                    file << cardnumber << " " << cvv << " " << "Platinum"<<" "<<"12/28";
                    file.close();
                    }
                    else
                    {
                        ifstream fial(IDNP + "card4.txt");
                        if(!fial.is_open())
                        {
                        ofstream  file(IDNP + "card4.txt");
                        file << cardnumber << " " << cvv << " " << "Platinum"<<" "<<"12/28";
                        file.close();
                        }
                        else    
                        {
                            ifstream fial(IDNP + "card5.txt");
                            if(!fial.is_open())
                            {
                            ofstream file(IDNP +  "card5.txt");
                            file << cardnumber << " " << cvv << " " << "Platinum"<<" "<<"12/28";
                            file.close();
                            }
                            else
                            {
                            cout<<red<<"You reached the limit to creating cards. (5/5)"<<endl;
                            sleep(1);
                            system("clear");
                            main_menu();
                            }
                        }
                    }
                }
            }
            ofstream file;
            file << cardnumber << " " << cvv << " " << "Platinum"<<" "<<"12/28";
            file.close();
            cout<<"You have just became the owner of the Mastercard Platinum Card"<<endl;
            cout<<"Please keep your CVV safe, as it is used for identification purposes."<<endl;                
            sleep(5);
            main_menu();
        }
        else if(rs == 'n' or rs == 'N')
        {
            system("clear");
            create_card();
        }
    }
}

void gold()
{
    if(balance < 15)
    {
        cout<<red<<"You don't have enough funds"<<endl;
        sleep(1);
        system("clear");
        create_card();
    }
    else
    {
        balance -= 15;
        ofstream fileOut(IDNP + "balance" + ".txt");
        fileOut<<balance;
        fileOut.close();
        string cardnumber = generateCreditCardNumber("5188" , 16);
        string cvv = generateCreditCardNumber("1" , 3);
        cout<<"Advantages of the Mastercard Gold Card"<<endl;
        cout<<"Fees - 2$ per month"<<endl;
        cout<<"Comfortable - Free P2P Transfers"<<endl;
        cout<<"Maximum daily transfer - 1500$"<<endl;
        cout<<"Price - 15$"<<endl;
        cout<<"Fast - payment takes 6 seconds to process"<<endl;
        cout<<"Sales - get 5% sale in every grocery store and our parteners stores"<<endl;
        cout<<endl;
        cout<<"Are you sure you want to submit this card?[Y/N]:";
        cin>>rs;
        if(rs == 'Y' or rs=='y')
        {
            balance -= 15;
            ofstream fileOut(IDNP + "balance" + ".txt");
            fileOut<<balance;
            fileOut.close();
            cout<<endl<<"Card Number:"<<cardnumber<<endl;
            cout<<"CVV:"<<cvv<<endl;
            cout<<"Expiration Date:12/28"<<endl;
            cout<<"Cardholder Name:"<<nume<<' '<<prenume<<endl;
              fstream fin(IDNP + "card.txt");
            if(!fin.is_open())
            {
                ofstream file(IDNP  + "card.txt");
                file << cardnumber << " " << cvv << " " << "Gold"<<" "<<"12/28";
                file.close();
            }
            else
            {
                ifstream fias(IDNP + "card2.txt");
                if(!fias.is_open())
                {
                ofstream file(IDNP + "card2.txt");
                file << cardnumber << " " << cvv << " " << "Gold"<<" "<<"12/28";
                file.close();
                }
                else
                {
                    ifstream fial(IDNP + "card3.txt");
                    if (!fial.is_open())
                    {
                    ofstream file(IDNP + "card3.txt");
                    file << cardnumber << " " << cvv << " " << "Gold"<<" "<<"12/28";
                    file.close();
                    }
                    else
                    {
                        ifstream fial(IDNP + "card4.txt");
                        if(!fial.is_open())
                        {
                        ofstream  file(IDNP + "card4.txt");
                        file << cardnumber << " " << cvv << " " << "Gold"<<" "<<"12/28";
                        file.close();
                        }
                        else    
                        {
                            ifstream fial(IDNP + "card5.txt");
                            if(!fial.is_open())
                            {
                            ofstream file(IDNP +  "card5.txt");
                            file << cardnumber << " " << cvv << " " << "Gold"<<" "<<"12/28";
                            file.close();
                            }
                            else
                            {
                            cout<<red<<"You reached the limit to creating cards. (5/5)"<<endl;
                            sleep(1);
                            system("clear");
                            main_menu();
                            }
                        }
                    }
                }
            }
            ofstream file;
            file << cardnumber << " " << cvv << " " << "Gold"<<" "<<"12/28";
            file.close();
            cout<<"You have just became the owner of the Mastercard Gold Card"<<endl;
            cout<<"Please keep your CVV safe, as it is used for identification purposes."<<endl;
            sleep(5);
            main_menu();
        }
        else if(rs == 'n' or rs == 'N')
        {
            system("clear");
            create_card();
        }   
    }
}

void classic()
{
    srand(time(0));
    string cardnumber = generateCreditCardNumber("5188" , 16);
    string cvv = generateCreditCardNumber("1" , 3);
    cout<<"Advantages of the Mastercard Classic Card"<<endl;
    cout<<"Fees - No annual fees"<<endl;
    cout<<"Comfortable - Free P2P Transfers"<<endl;
    cout<<"Maximum daily transfer - 700$"<<endl;
    cout<<"Price - No cost to create"<<endl;
    cout<<"Fast - payment takes 6 seconds to process"<<endl;
    cout<<endl;
    cout<<"Are you sure you want to submit this card?[Y/N]:";
    cin>>rs;
    if(rs == 'Y' or rs=='y')
    {
        cout<<endl<<"Card Number:"<<cardnumber<<endl;
        cout<<"CVV:"<<cvv<<endl;
        cout<<"Expiration Date:12/28"<<endl;
        cout<<"Cardholder Name:"<<nume<<' '<<prenume<<endl;
          fstream fin(IDNP + "card.txt");
            if(!fin.is_open())
            {
            ofstream file(IDNP  + "card.txt");
            file << cardnumber << " " << cvv << " " << "Classic"<<" "<<"12/28";
             file.close();
            }
            else
            {
                ifstream fias(IDNP + "card2.txt");
                if(!fias.is_open())
                {
                ofstream file(IDNP + "card2.txt");
                file << cardnumber << " " << cvv << " " << "Classic"<<" "<<"12/28";
                file.close();
                }
                else
                {
                    ifstream fial(IDNP + "card3.txt");
                    if (!fial.is_open())
                    {
                    ofstream file(IDNP + "card3.txt");
                    file << cardnumber << " " << cvv << " " << "Classic"<<" "<<"12/28";
                    file.close();
                    }
                    else
                    {
                        ifstream fial(IDNP + "card4.txt");
                        if(!fial.is_open())
                        {
                        ofstream  file(IDNP + "card4.txt");
                        file << cardnumber << " " << cvv << " " << "Classic"<<" "<<"12/28";
                        file.close();
                        }
                        else    
                        {
                            ifstream fial(IDNP + "card5.txt");
                            if(!fial.is_open())
                            {
                            ofstream file(IDNP +  "card5.txt");
                            file << cardnumber << " " << cvv << " " << "Classic"<<" "<<"12/28";
                            file.close();
                            }
                            else
                            {
                                cout<<red<<"You reached the limit to creating cards. (5/5)"<<endl;
                                sleep(1);
                                system("clear");
                                main_menu();
                            }
                        }
                    }
                }
            }
            ofstream file;
            file << cardnumber << " " << cvv << " " << "Classic"<<" "<<"12/28";
            file.close();
        cout<<"You have just became the owner of the Mastercard Classic Card"<<endl;
        cout<<"Please keep your CVV safe, as it is used for identification purposes."<<endl;
        sleep(5);
        main_menu();
    }
    else if(rs == 'n' or rs == 'N')
    {
        system("clear");
        create_card();
    }
}

void create_card()
{
    cout<<endl;
    string gold_av,platinum_av,elite_av,worldclass_av;
    ofstream fileOut(IDNP + "balance" + ".txt");
    fileOut<<balance;
    fileOut.close();
    cout<<white;
    cout<<"What kind of credit card do you wish to submit?"<<endl;
    cout<<white<<"[1] Mastercard Classic"<<endl;
    if(balance < 15)
    {
        cout<<red<<"[2] Mastercard Gold"<<gold_av<<endl;
    }
    else
    {   
        cout<<white<<"[2] Mastercard Gold"<<gold_av<<endl;
    }
    if(balance < 30)
    {
        cout<<red<<"[3] Mastercard Platinum"<<platinum_av<<endl;
    }
    else
    {
        cout<<white<<"[3] Mastercard Platinum"<<endl;
    }
    if(balance < 50)
    {
        cout<<red<<"[4] Mastercard Elite"<<elite_av<<endl;
    }
    else
    {
        cout<<white<<"[4] Mastercard Elite"<<elite_av<<endl;
    }
    if(balance < 70)
    {
        cout<<red<<"[5] Mastercard WorldClass Elite"<<worldclass_av<<endl;
    }
    else
    {
        cout<<white<<"[5] Mastercard WorldClass Elite"<<worldclass_av<<endl;
    }    
    cout<<white;
    cout<<"[99] Return to Menu "<<endl;
    cout<<endl;
    cout<<"Enter an option:";
    cin>>a;
    switch(a)
    {
        case 1 : classic(); break;
        case 2 : gold(); break;
        case 3 : platinum(); break;
        case 4 : elite(); break;
        case 5 : worldclass(); break;
        case 99 : system("clear"); main_menu(); break;
        default : cout<<red<<"Enter a valid option."; sleep(1); system("clear"); create_card();

    }
}

void change_name()
{
    cout<<white;
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
        cout<<green<<"Name and Surname changed succesfully!"<<endl;
        sleep(1);
        system("clear");
        main_menu();
    }
    else if(rs=='n' || rs=='N')
    {
        ofstream fiout(IDNP + "data.txt");
        fiout<<IDNP<<" "<<password<<" "<<nume<<" "<<prenume; 
        cout<<green<<"Name changed succesfully!"<<endl;
        sleep(1);
        system("clear");
        main_menu();
    }
    else
    {
        cout<<red;
        sleep(1);
        system("clear");
        change_name();
    }
}

void change_password()
{
    cout<<white;
    ifstream file(IDNP + "data.txt");
    cout<<"Enter current password:";
    cin>>password1;
    if(password1 != password)
    {
        cout<<red<<"Incorrect password,try again"<<endl;
        sleep(1);
        system("clear");
        change_password();
    }
    else
    {
        cout<<"Enter new password (Min. 6 characters):";
        cin>>password1;
        cout<<"Re-enter new password:";
        cin>>password2;
        if(password2.length() < 6)
        {
            cout<<yellow<<"Password lenght should be at least 6 characters long,try again"<<endl;
            sleep(1);
            modify_account();
        }
        else
        {
            if(password1 == password2)
            {
                ofstream fout(IDNP + "data.txt");
                fout<<IDNP<<" "<<password1<<" "<<nume<<" "<<prenume;
                fout.close();
                cout<<green<<"Password changed successfully!"<<endl;
                sleep(1);
                system("clear");
                main();
            }
            else
            {
                cout<<red<<"Passwords do not match, try again."<<endl;
                sleep(1);
                system("clear");
                change_password();
            }
        }
    }   

}

void modify_account()
{
    cout<<white;
    cout<<endl;
    cout<<"[1] Change Password"<<endl;
    cout<<"[2] Change Name / Surname"<<endl;
    cout<<"[99] Go Back to Main Menu"<<endl;
    cout<<endl;
    cout<<"Choose option:";
    cin>>a;
    switch(a)
    {
        case 1 : change_password(); break;
        case 2 : change_name(); break;
        case 99 : main_menu(); break;
        default : sleep(1); cout<<red; modify_account();
    }
}

void close_account()
{
    cout<<white<<endl;
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
            cout<<magenta<<"We are sad seeing you leaving us behind,account deleted succesfully."<<endl;
            sleep(1);
            system("clear");
            main();
        }
        else
        {
            cout<<red<<"Passwords don't match,try again."<<endl;
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
        cout<<red<<"Enter a valid option."<<endl;
        sleep(1);
        system("clear");
        main_menu();
    }
}

void transfer()
{
    
    cout<<white;
    ifstream fileIn(IDNP + "balance" + ".txt");
    cout<<"Enter account IDNP:";
    cin>>IDNP2;
    if(IDNP2==IDNP)
    {
        
        cout<<yellow<<"You can't send money to yourself."<<endl;
        sleep(1);
        transfer();
    }
    ifstream fileN(IDNP2 + "balance" + ".txt" );
    if(!fileN.is_open())
    {
        
        cout<<red<<"This account appears to not exist"<<endl;
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

            cout<<red<<"You don't have enough money,try again."<<endl;
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
            cout<<green<<"You succesfully transferred "<<amount<<" to "<<IDNP2<<endl;
            sleep(1);
            system("clear");
            main_menu();
        }
    }
}
void withdraw()
{
    cout<<white;
    int b,balance;
    ifstream fileIn(IDNP + "balance" + ".txt");
    cout<<"Enter amount:";
    fileIn >> balance;
    cin>>b;
    fileIn.close(); 
    if(balance<b)
    {
        cout<<red<<"You don't have sufficient funds,try again."<<endl;
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
    cout<<green<<"You just succesfully withdrawn "<<b<<"$"<<endl;
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
    cout<<white;
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
    cout<<green<<"You just replenished your account with "<<b<<"$"<<endl;
    main_menu();
}
void main_menu()
{
    string cd , cv , type , date; 
    cout<<white;
    int a;
    ifstream file(IDNP + "balance" + ".txt");
    file>>balance;
    file.close();
    cout<<endl;
    sleep(1);
    system("clear");
    cout<<"   __  ___     _          __  ___             "<<endl;     
    cout<<"  /  |/  /__ _(_)__      /  |/  /__ ___  __ __"<<endl;
    cout<<" / /|_/ / _ `/ / _ \    / /|_/ / -_) _ \/ // /"<<endl;
    cout<<"/_/  /_/\_,_/_/_//_/   /_/  /_/\__/_//_/\_,_/ "<<endl;
    cout<<endl; 
    cout<<"Welcome Back,"<<nume<<"                        Available Balance "<<balance<<"$";
    cout<<endl;
    cout<<endl;
    cout<<"[1] Deposit Amount                    [6] Modify account"<<endl;
    cout<<"[2] Withdraw Amount                   [7] Create Card"<<endl;
    cout<<"[3] Transfer Money"<<endl;
    cout<<"[4] Logout"<<endl;
    cout<<"[5] Close Account"<<endl;
    cout<<endl;
    cout<<"[99] Exit"<<endl;
    cout<<endl;
    fstream ile(IDNP + "card.txt");
    fstream dat(IDNP + "card2 .txt");
    fstream  dat2(IDNP + "card3.txt");
    fstream  dat3(IDNP + "card4.txt");
    fstream dat4(IDNP + "card5.txt");
    string cd1,cv1,type1;
    if(ile.is_open())
    {
        ile >> cd >> cv >> type >> date;
        cout<<"_________________________________________"<<endl;
        cout<<"|                                       |"<<endl;
        cout<<"|  Your card details are:               |"<<endl;
        cout<<"|  Card Number : "<<cd<<"       |"<<endl;
        cout<<"|  CVV : "<<cv<<"                            |"<<endl;
        cout<<"|  Expiration Date : "<<date<<"              |" << endl;
        cout<<"|  Type : "<<type<<"                      |"<<endl;
        cout<<"|_______________________________________|"<<endl;
    }
    if(dat.is_open())
    {
        string cd1 , cv1 , type1;
        dat >> cd1 >> cv1 >> type1 ;
        cout<<"_________________________________________"<<endl;
        cout<<"|                                       |"<<endl;
        cout<<"|  Your card details are:               |"<<endl;
        cout<<"|  Card Number : "<<cd1<<"       |"<<endl;
        cout<<"|  CVV : "<<cv1<<"                            |"<<endl;
        cout<<"|  Expiration Date : "<<date<<"              |" << endl;
        cout<<"|  Type : "<<type1<<"                      |"<<endl;
        cout<<"|_______________________________________|"<<endl;

    }
    if(dat2.is_open())
    {
        string cdd,cvc,typ;
        dat2 >> cdd >> cvc >> typ;
        cout<<"_________________________________________"<<endl;
        cout<<"|                                       |"<<endl;
        cout<<"|  Your card details are:               |"<<endl;
        cout<<"|  Card Number : "<<cdd<<"       |"<<endl;
        cout<<"|  CVV : "<<cvc<<"                            |"<<endl;
        cout<<"|  Expiration Date : "<<date<<"              |" << endl;
        cout<<"|  Type : "<<typ<<"                      |"<<endl;
        cout<<"|_______________________________________|"<<endl;

    }
    if(dat3.is_open())
    {
        string cdc , cvd , tipe;
        dat3 >> cdc >> cvd >> tipe;
        cout<<"_________________________________________"<<endl;
        cout<<"|                                       |"<<endl;
        cout<<"|  Your card details are:               |"<<endl;
        cout<<"|  Card Number : "<<cdc<<"       |"<<endl;
        cout<<"|  CVV : "<<cvd<<"                            |"<<endl;
        cout<<"|  Expiration Date : "<<date<<"               |" << endl;
        cout<<"|  Type : "<<tipe<<"                      |"<<endl;
        cout<<"|_______________________________________|"<<endl;

    }
    if(dat4.is_open())
    {
        string cdv,cvdc,tip;
        dat4 >> cdv >> cvdc >> tip;
        cout<<"_________________________________________"<<endl;
        cout<<"|                                       |"<<endl;
        cout<<"|  Your card details are:               |"<<endl;
        cout<<"|  Card Number : "<<cdv<<"       |"<<endl;
        cout<<"|  CVV : "<<cvdc<<"                            |"<<endl;
        cout<<"|  Expiration Date : "<<date<<"                |" << endl;
        cout<<"|  Type : "<<tip<<"                      |"<<endl;
        cout<<"|_______________________________________|"<<endl;
    }
    cout<<endl<<"Enter an option:";
    cin>>a;
    switch(a)
    {
        case 1 : deposit(); break;
        case 2 : withdraw(); break;
        case 3 : transfer(); break;
        case 4 : logout(); break;
        case 5 : close_account(); break;
        case 6 : modify_account(); break;
        case 7 : create_card(); break;
        case 99 : system("clear"); break;
        default : cout<<red<<"Enter a valid option.";  sleep(1); system("clear"); main_menu();
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
    cout<<white;
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
            cout << red << "       Invalid Credentials."<<endl; 
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
                cout<< red <<"       Invalid Credentials."<<endl;
                sleep(1);
                system("clear");
                autentificare();
            }
        }  
}

void inregistrarile_noi()
{
    cout<<white;
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
        cout<< yellow << "       Password lenght should be at least 6 characters,try again."<<endl;
        sleep(1);
        system("clear");
        inregistrarile_noi();
    }
    cout<<"       IDNP:";
    cin>>IDNP;
    if(IDNP.length() != 13)
    {
        cout << yellow << "       The Identification Number should be 13 characters,try again.";
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
            cout <<red<< "       An Account under this Identification Number was already created,you can choose to authentificate."<<endl;
            sleep(1);
            system("clear");
            main();
        }
        else
        {
        cout<<endl;
        cout<<green<<"       You created an account with succes,you can log into your Bank Account now!";
        ofstream myfile; // Creates a file
        myfile.open(IDNP + "data" + ".txt"); 
        myfile<<IDNP<<" "<<password<<" "<<nume<<" "<<prenume; 
        myfile.close();
        sleep(1);
        system("clear");
        cout<<endl;
        main();
        }
    }
}
int main() 
{
    system("clear");
    cout<<white;
    int optiune;   
    cout<<"    _   __      __  _                   __   __                __      __  ___      __    __                     "<<endl;
    cout<<"   / | / /___ _/ /_(_)___  ____  ____ _/ /  / /_  ____ _____  / /__   /  |/  /___  / /___/ /___ _   ______ _     "<<endl;
    cout<<"  /  |/ / __ `/ __/ / __ \/ __ \/ __ `/ /  / __ \/ __ `/ __ \/ //_/  / /|_/ / __ \/ / __  / __ \ | / / __ `/      "<<endl;
    cout<<" / /|  / /_/ / /_/ / /_/ / / / / /_/ / /  / /_/ / /_/ / / / / ,<    / /  / / /_/ / / /_/ / /_/ / |/ / /_/ /      "<<endl;
    cout<<"/_/ |_/\__,_/\__/_/\____/_/ /_/\__,_/_/  /_.___/\__,_/_/ /_/_/|_|  /_/  /_/\____/_/\__,_/\____/|___/\__,_/     "<<endl;
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
        case 3 :  cout<<yellow<<"       Coming Soon..."<<endl; sleep(1); system("clear"); main(); break;
        case 99 : system("clear"); break;
        default : sleep(1); cout<<red; system("clear"); main();
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