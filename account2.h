/*Program Name: Savings Account
Programmer Name: Liseidy Bueno
Purpose: To determine the balance of a savings account using the average daily balance
No Global Variables

ACCOUNT2 HEADER FILE

VALUE SEMANTICS for the account class:
Assignments and the copy constructor may b e used with account objects

DYNAMIC MEMORY USAGE by account:
The following functions use dynamic memory: constructors, resize, and insert.
 */
#ifndef PROJECT_1_ACCOUNT_H
#define PROJECT_1_ACCOUNT_H

#include <cstdlib>
#include <string>

using namespace std;

class account{
public:

    //TYPEDEFS for the account class:


    //account::value_type is the data type of the balance in the account
    typedef double value_type;

    //account::size_type is the data type of any variables that keep track of how many days the account
    // has saved the balance
    typedef size_t size_type;

    //CONSTRUCTORS for the account class:

    //default constructor
    //Postcondition: Balance is 0 and no days have passed. APR is also 0.
    account();

    //constructor with rate passed
    //Postcondition: Balance is 0 and no days have passed. APR is rate.
    account(double rate);

    //copy constructor
    account(const account& source);

    //destructor
    ~account();

    //MUTATOR FUNCTIONS

    //Deposits amount and adds to total balance
    //Precondition: Deposit amount cannot be a negative number
    //Postcondition: Adds deposit amount to the existing balance
    void deposit(double deposit_amount);

    //Withdraws amount and subtracts from total balance
    //Precondition: Withdraw amount cannot be a negative number
    //Postcondition: Subtracts withdrawal amount from the existing balance
    void withdraw(double withdraw_amount);

    //Advances the amount of days indicated
    //Postcondition: Advances the current day by the days to advance and calculates the average daily balance
    // of the account for the current month as well as the balance at the end of every 30 days after adding the
    // interest.
    void advanceDay(int days_to_advance);

    //Sets APR
    //Postcondition: Calculates APR for monthly compounding (divide by 12 and then by 100)
    void setAPR(double APR);

    //CONSTANT MEMBER FUNCTIONS for the account class:

    //Returns the current day (days since account was opened)
    double getDayNumber() const;

    //Returns the balance from a specified day that has passed
    double getPreviousBalance(int day) const;

    //Returns the current balance
    double getCurrentBalance() const;

    /*INVARIANT DECLARATION
    The current balance of the account is stored in the data array and in balance
    balance2 and balance3 are used to set precise amounts
    The current day of the account is stored in the variable current_day
    The APR of the account is stored in the variable int_rate
    Used keeps count of the amount of days that have passed (how many balance inputs there are)
    Capacity is how large the array is and is set to increase in the resize function
    The dynamic array data stores the balance each day*/

private:
    double balance;
    double balance2;
    int balance3;
    double int_rate; //stores APR
    int current_day; //stores current day
    double average;
    int starting_point;
    int end_point;

    size_type used; // how many days account has been active
    size_type capacity = 30;
    value_type* data; // stores every day's balance

    //PRIVATE FUNCTIONS


    //Makes array larger when capacity has been reached
    //Postcondition: Larger array by two times the original size
    void resize(size_t);

    //Inserts a new balance into array
    //Postcondition: A new copy of target is inserted into the next day the account is open
    void insert(double target);

};


#endif //PROJECT_1_ACCOUNT_H
