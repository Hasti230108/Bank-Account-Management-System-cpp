#include<iostream>
using namespace std;

class Account{
    private:
        string name;
        int accountNumber;
        double balance;
    public:
        Account(string n, int accNo, double bal){
            name = n;
            accountNumber = accNo;
            balance = bal;
        }

        void deposit(double amount){
            balance += amount;
        }

        void withdraw(double amount){
            if(amount > balance){
                cout<<"Insufficient balance\n";
            }
            else{
                balance -= amount;
            }
        }

        void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"Account Number: "<<accountNumber<<endl;
            cout<<"Balance: "<<balance<<endl;
        }
};

class SavingsAccount : public Account{
    public:
        SavingsAccount(string n, int accNo, double bal) : Account(n, accNo, bal) {}
};

class CurrentAccount : public Account{
    public:
        CurrentAccount(string n, int accNo, double bal) : Account(n, accNo, bal) {}
};

int main(){
    int choice;

    SavingsAccount* sAcc = nullptr;
    CurrentAccount* cAcc = nullptr;

    while(1){
        cout<<"1.Create Savings Account"<<endl;
        cout<<"2.Create Current Account"<<endl;
        cout<<"3.Deposit Money"<<endl;
        cout<<"4.Withdraw Money"<<endl;
        cout<<"5.Display Account Details"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1: {
                string name;
                int accNo;
                double bal;

                cout<<"Enter name: ";
                cin.ignore();
                getline(cin, name);

                cout<<"Enter account number: ";
                cin>>accNo;

                cout<<"Enter initial balance: ";
                cin>>bal;

                sAcc = new SavingsAccount(name, accNo, bal);
                cout<<"Savings Account Created!\n";
                break;
            }
                
            case 2: {
                string name;
                int accNo;
                double bal;

                cout<<"Enter name: ";
                cin.ignore();
                getline(cin, name);

                cout<<"Enter initil balance: ";
                cin>>bal;

                cAcc = new CurrentAccount(name, accNo, bal);
                cout<<"Current Account Created!\n";
                break;
            }

            case 3: {
                int type;
                double amount;

                cout<<"1. Savings 2. Current \nChoose account type: ";
                cin>>amount;

                if(type == 1 && sAcc != nullptr){
                    sAcc->deposit(amount);               
                }
                else if(type == 2 && cAcc != nullptr){
                    cAcc->deposit(amount);
                }
                else{
                    cout<<"Account not found!\n";
                }
                break;
            }
            case 4: {
                int type;
                double amount;

                cout<<"1. Savings 2. Current\nChoose account type: ";
                cin>>type;

                cout<<"Enter amount to withdraw: ";
                cin>>amount;    

                if(type == 1 && sAcc != nullptr){
                    sAcc->withdraw(amount);
                }
                else if(type == 2 && cAcc != nullptr){
                    cAcc->withdraw(amount);
                }
                else{
                    cout<<"Account not found!\n";
                }
                break;

            }
            case 5: {
                int type;

                cout<<"1. Savings 2. Current\nChoose account type: ";
                cin>>type;

                if(type == 1 && sAcc != nullptr){
                    sAcc->display();
                }
                else if(type == 2 && cAcc != nullptr){
                    cAcc->display();
                }
                else{
                    cout<<"Account not found!\n";
                }
                break;

            }
            case 6:
                cout<<"Thank you!\n";
                break;
        }
    }
    return 0;
}