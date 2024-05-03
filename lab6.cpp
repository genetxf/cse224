#include <iostream>
#include <cmath>

// Global variables for other parameters
double global_principal;
double global_rate;
double interest;
int global_period;
double global_deposits;
double global_withdraw;
double global_fees;
double global_tax;
double taxrate;

class Bank {
private:
    double interest;
    int years;
    double money;

public:
    // Constructor with parameters

    Bank(double rate, int period, double principal, double deposits, double withdraw, double fees, double tax)
            : interest(rate), years(period), money(principal) {}


    // Calculate total

    double total() {

        /*  Formula for interest calculation
            1. Compounded interest formula A = P * (1 + r)^n
            2. Simple interest formula: A = P * (1 + r * n)

            Where:
            A is the total amount (principal + interest)
            P is the principal amount (the initial amount of money)
            r is the annual interest rate (in decimal)
            n is the number of years the money is invested for
         */

        //total with compounded interest
        double total = global_principal * pow((1 + global_rate), global_period);

        // total with simple interest
        //double total = global_principal * (1 + global_rate * global_period);



        total += global_deposits; //Add deposits
        total -= global_withdraw; //Deduct withdraw
        total -= global_fees; //Deduct fees
        total *= (1 - global_tax); //Deduct taxes

        return total; //return total amount
    }

};

int main() {
    // input parameter for bank
    Bank account(global_rate, global_period, global_principal, global_deposits, global_withdraw, global_fees,
                 global_tax);

    //input account info
    global_principal = 1000.0;
    interest = 10;
    global_period = 3;
    global_deposits = 1000.0;
    global_withdraw = 500.0;
    global_fees = 50.0;
    taxrate = 5;

    //interest rate calculation
    global_rate = interest / 100;
    //tax rate calculation
    global_tax = taxrate / 100;

    //Calculate total amount of money
    double total = account.total();

    // Display result
    std::cout << " Basic Money: BDT " << global_principal <<
              "\n Interest rate: " << interest << "%"
              "\n Years: " << global_period <<
              "\n Deposit: BDT " << global_deposits <<
              "\n Withdraw: BDT " << global_withdraw <<
              "\n Fees: BDT " << global_fees <<
              "\n Tax rate: " << taxrate << "%"
              "\n -----------------------------------"
              "\n Total amount of money: BDT " << total << std::endl;

    return 0;
}