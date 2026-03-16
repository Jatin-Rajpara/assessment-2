#include <iostream>
#include <ctime>
using namespace std;

class ATM
{
private:
    int pin;
    double balance;
    int accno;
    string userName;
    string branch;
    string address;

    

public:
    ATM(); 

    void showWelcome();
    void help();
    void menu();
    void deposit();
    void withdraw();
    void checkBalance();
};


ATM::ATM()
{
    pin = 2618;
    balance = 20000;
    accno = 1560;
    userName = "Jatin Rajpara";
    branch = "Ahmedabad Main Branch";
    address = "Ahmedabad, Gujarat";

}
void ATM::showWelcome()
{
    cout << "=============================\n";
    cout << "        ATM BANKING\n";
    cout << "=============================\n";
    
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << dt;

    cout << "1. Enter ATM PIN\n";
    cout << "2. Help\n";
    cout << "3. Exit\n";
}

void ATM::help()
{
    cout << "\n------ HELP SCREEN ------\n";
    cout << "1. Enter PIN to access account\n";
    cout << "2. Deposit money\n";
    cout << "3. Withdraw money\n";
    cout << "4. Check account balance\n";
}

void ATM::menu()
{
    int choice;

    do
    {
        cout << "\n------ ATM MENU ------\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                deposit();
                break;

            case 2:
                withdraw();
                break;

            case 3:
                checkBalance();
                break;

            case 4:
                cout << "Thank you for using ATM\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 4);
}


void ATM::deposit()
{
    double amount;

    cout << "Enter amount to deposit: ";
    cin >> amount;

    balance += amount;
    cout << "Amount Deposited Successfully\n";
    cout << "\nAccount Holder : " << userName << endl;
    cout<<"Account number : "<<accno<<endl;
    cout << "Branch         : " << branch << endl;
    cout << "Current Balance: " << balance << endl;
}


void ATM::withdraw()
{
    double amount;

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if(amount > balance)
    {
        cout << "Insufficient Balance\n";
        cout << "Transaction Failed\n";
    }
    else
    {
        
        balance -= amount;
         cout << "Withdrawal Successful\n";
         cout << "\nAccount Holder : " << userName << endl;
         cout<<"Account number : "<<accno<<endl;
         cout << "Branch         : " << branch << endl;
         cout << "Remaining Balance: " << balance << endl;
    }
}


void ATM::checkBalance()
{
    cout << "Current Balance: " << balance << endl;
}

int main()
{
    ATM atm;
    int choice;
    int enteredPin;

    atm.showWelcome();

    cout << "\nEnter Choice: ";
    cin >> choice;

    if(choice == 1)
    {
        cout << "Enter ATM PIN: ";
        cin >> enteredPin;

        if(enteredPin == 2618)
        {
            cout << "PIN Verified Successfully\n";
            atm.menu();
        }
        else
        {
            cout << "Incorrect PIN\n";
            cout << "Exiting Program\n";
        }
    }
    else if(choice == 2)
    {
        atm.help();
    }
    else
    {
        cout << "Program Exit\n";
    }

    return 0;
}