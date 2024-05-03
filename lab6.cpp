#include <iostream>

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
        // Assuming interest is compounded annually
        double total = global_principal;

        //total with interest
        for (int i = 0; i < global_period; ++i) {
            total += total * global_rate;
        }

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

    //interest rate calculation
    global_rate = interest/100;
    //tax rate calculation
    global_tax = taxrate/100;

    //input account info
    global_principal = 1000.0;
    interest = 5;
    global_period = 3;
    global_deposits = 1000.0;
    global_withdraw = 500.0;
    global_fees = 50.0;
    taxrate = 2;

    //Calculate total amount of money
    double total = account.total();

    // Display result
    std::cout << "Total amount of money after " << global_period << " years with " << interest << "% interest rate is: $" << total << std::endl;

    return 0;
}


