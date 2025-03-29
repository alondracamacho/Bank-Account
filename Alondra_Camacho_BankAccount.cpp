#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Alondra Camacho - member functions of class BankAccount that set, get, update, and display bank balance and interest rate

class BankAccount {
public:
    //Postcondition: The account balance has been set to	//$dollars.cents. The interest rate has been set to rate percent. 
    void set(int dollars, int cents, double rate);
	
	//Postcondition: The account balance has been set to $dollars.00. 
	//The interest rate has been set to rate percent. 
    void set(int dollars, double rate);
	
	//Postcondition: One year of simple interest has been added to the 	//account balance. 
    void update();
	
    //Returns the current account balance.
	double getBalance();
	
    //Returns the current account interest rate as a percentage. 
	double getRate();
	
    //Postcondition: Account balance and interest rate are printed on 	//the screen. 
	void output();
	
    //display output into a file
    void output(ofstream&);

    //makes one bank accounts data the same as the other
    BankAccount& operator=(const BankAccount&);
private:
	double balance;
	double interestRate;
	double fraction(double percent);
	//Converts a percentage to a fraction. 
	//For example, fraction(50.3%) returns 0.503. 
};

int main() {

    //declare two objects of BankAccount class
    BankAccount account1, account2;

    //set account balance and interest rate of both objects
    account1.set(156, 97, 3.5);
    account2.set(24, 4.3);

    //get balance and rate of account 1 and display
    double rate1, balance1;

    rate1 = account1.getRate();
    balance1 = account1.getBalance();

    cout << "Account 1 has a balance of $" << balance1 << " and an interest rate of " << rate1 << "%.\n\n";

    //display both account balances
    cout << "Initial statement - Account 1: " << endl;
    account1.output();

    cout << "Initial statement - Account 2: " << endl;
    account2.output();

    //update account1 - new balance after interest rate is applied
    account1.update();

    cout << "Account 1 after 1 year - interest rate applied: " << endl;
    account1.output();

    //set account 2 info equal to account 1 info
    account2 = account1;

    //display new info for account 2
    cout << "Statement after Account 2 is set equal to Account 1: " << endl;
    account2.output();

    
    
    //declare variable to ouput into a file
    ofstream outFile;

    //open file
    outFile.open("bankStatement.txt");

    //test to see if file opened
    if (outFile.fail()) {
        cout << "File not able to open." << endl;
        exit(1);
    }

    //display account 1 info in file
    outFile << "Bank Statement - Account 1: " << endl;
    account1.output(outFile);

    //display account 2 info in file
    outFile << "Bank Statement - Account 2: " << endl;
    account2.output(outFile);

    //close file
    outFile.close();

    return 0;
}

//Postcondition: The account balance has been set to 		//$dollors.cents. The interest rate has been set to rate percent. 
void BankAccount::set(int dollars, int cents, double rate) {
    balance = dollars + (cents / 100.00);
    interestRate = rate;
}

//Postcondition: The account balance has been set to $dollors.00. 
	//The interest rate has been set to rate percent. 
void BankAccount::set(int dollars, double rate) {
    balance = dollars;
    interestRate = rate;
}

//Postcondition: One year of simple interest has been added to the 	//account balance. 
void BankAccount::update() {
    double interestRateDecimal = fraction(interestRate);
    
    balance += balance * interestRateDecimal;
}

//Returns the current account balance.
double BankAccount::getBalance() {
    return balance;
}

//Returns the current account interest rate as a percentage.
double BankAccount::getRate() {
    return interestRate;
}

//Postecondition: Account balance and interest rate are printed on 	//the screen
void BankAccount::output() {
    cout << fixed << setprecision(2) << "Account Balance: $" << balance << endl;
    cout << fixed << setprecision(2) << "Interest Rate: " << interestRate << '%' << endl;
    cout << endl;
}
	
//Converts a percentage to a fraction. 
//For example, fraction(50.3%) returns 0.503.     
double BankAccount::fraction(double percent) {
    double fractionRate;
    fractionRate = percent / 100;
    return fractionRate;
}

//makes one bank accounts data the same as the other	 
BankAccount& BankAccount::operator=(const BankAccount& otherAccount) {
    balance = otherAccount.balance;
    interestRate = otherAccount.interestRate;

    return *this;
}

//display output into a file
void BankAccount::output(ofstream& out) {
out << fixed << setprecision(2);
out << "Account Balance: $" << balance << endl;
out << "Interest Rate: " << interestRate << '%' << "\n\n";
}

/*OUTPUT:
Account 1 has a balance of $156.97 and an interest rate of 3.5%.

Initial statement - Account 1: 
Account Balance: $156.97
Interest Rate: 3.50%

Initial statement - Account 2: 
Account Balance: $24.00
Interest Rate: 4.30%

Account 1 after 1 year - interest rate applied: 
Account Balance: $162.46
Interest Rate: 3.50%

Statement after Account 2 is set equal to Account 1: 
Account Balance: $162.46
Interest Rate: 3.50%

*/