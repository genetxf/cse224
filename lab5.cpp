#include <iostream>
using namespace std;

class Bank {
public:
    virtual double interestRate() const {
        return 0.0; // Default implementation, returning 0.0
    }
};

class SonaliBank : public Bank {
public:
    double interestRate() const override {
        return 5.1; // Interest rate for Sonali Bank is 5.1%
    }
};

class RupaliBank : public Bank {
public:
    double interestRate() const override {
        return 4.9; // Interest rate for Rupali Bank is 4.9%
    }
};

class PubaliBank : public Bank {
public:
    double interestRate() const override {
        return 4.7; // Interest rate for Pubali Bank is 4.7%
    }
};

int main() {

    // Create objects for each bank
    SonaliBank sonali;
    RupaliBank rupali;
    PubaliBank pubali;

    // Assuming the fixed deposit amount is 3 Lakh (300,000)
    double fixedDepositAmount = 300000;

    // Calculate the amount after 4 years for each bank
    double amountInSonali = fixedDepositAmount * (1 + (sonali.interestRate() / 100) * 4);
    double amountInRupali = fixedDepositAmount * (1 + (rupali.interestRate() / 100) * 4);
    double amountInPubali = fixedDepositAmount * (1 + (pubali.interestRate() / 100) * 4);

    // Output the results
    cout << "Amount in Sonali Bank with Interest rate of 5.1% after 4 years: " << amountInSonali << " Taka" << endl;
    cout << "Amount in Rupali Bank with Interest rate of 4.9% after 4 years: " << amountInRupali << " Taka" << endl;
    cout << "Amount in Pubali Bank with Interest rate of 4.7% after 4 years: " << amountInPubali << " Taka" << endl;

    return 0;
}
