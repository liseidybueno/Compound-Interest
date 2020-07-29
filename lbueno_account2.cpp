#include "account2.h"
#include <algorithm>

using namespace std;

//Constructors
account::account() {
    //Constructor with no interest rate
    current_day = 1;
    used = 0;
    data = new value_type[capacity];
    balance = 0;
    data[current_day - 1] = 0;
}

account::account(double rate) {
    //Constructor given the interest rate
    int_rate = (rate / 100) / 12;
    current_day = 1;
    used = 0;
    data = new value_type[capacity];
    balance = 0;
    data[current_day - 1] = 0;
}

account::~account() {
    delete [] data;
}

account::account(const account& source){
    data = new value_type[source.capacity];
    capacity = source.capacity;
    used = source.used;
    copy(source.data, source.data + used, data);


}

void account::deposit(double deposit_amount){
    if(deposit_amount < 0)
        deposit_amount = 0;
    
    balance += deposit_amount;


   balance2 = (balance + .005) * 1000;

    balance3 = balance2 / 10;

    balance = balance3/100.0;

    data[current_day - 1] = balance;
}

void account::withdraw(double withdraw_amount){
    if(withdraw_amount < 0)
        withdraw_amount = 0;

    balance -= withdraw_amount;
   balance2 = (balance + .005) * 1000;

    balance3 = balance2 / 10;


    balance = balance3/100.0;

    data[current_day - 1] = balance;

}

void account::advanceDay(int days_to_advance) {

    if (current_day == 1) {
        for (int i = 0; i < days_to_advance + 1; ++i) {
            insert(data[current_day - 1]);
        }
    } else {
        for (int i = current_day; i < days_to_advance + current_day; ++i)
            insert(data[current_day - 1]);
    }

    current_day += days_to_advance;

    double total = 0;
    int month = current_day / 30;
    int end_point = 0;
    int starting_point = 0;

    if (month > 1) {
        starting_point = (month * 30) - 29;
        end_point = starting_point + 29;
    } else {
        starting_point = 0;
        end_point = 30;
    }

    for (int i = starting_point; i < end_point + 1; ++i) {
        total = total + data[i];
    }

    average = total / 30;


    if (month >= 1) {
        data[current_day - 1] = data[end_point] + (average * int_rate);
    }

}



void account::resize(size_t n)
{
    if(n < used)
        n = used;

    if(n==capacity)
        return;

    value_type *temp = new value_type[n];
    copy(data, data + used, temp);
    delete[] data;
    data = temp;
    capacity = n;
}

void account::insert(double target){
    if(capacity == 0)
    {
        capacity = 1;
        data = new double[capacity];
    } else if(capacity == used)
    {
        resize(capacity * 2);
        value_type * temp = new value_type[capacity];
        copy(data, data + used, temp);
        delete[] data;
        data = temp;
    }

    data[used] = target;
    ++ used;
}

double account::getDayNumber() const{

    return current_day;

}

double account::getPreviousBalance(int day) const{

    return data[day - 1];

}

double account::getCurrentBalance() const{


    return data[current_day - 1];


}

void account::setAPR(double APR){

    int_rate = (APR / 100) / 12;

}




