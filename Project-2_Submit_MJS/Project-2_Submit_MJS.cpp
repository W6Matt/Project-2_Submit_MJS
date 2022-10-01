#include <iostream>
#include<iomanip>

using namespace std;

// Global variables
double numYears;
double numMonthlyDis;
double numAnnualInt;
double numStartAmount;


// Check Values, exit if not numeric
double CheckValue() {
    double  numVal;
    try {
        cin >> numVal;
        // correct entry for the vaiable
        if (!cin.good()) {
            throw 1;
        }
        // Greater than zero
        if (numVal < 0) {
            throw 3;
        }
    }
    // Display error
    catch (int a) {
        cout << "Invalid Entry";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        exit(1);
    }
    return numVal;
}


// Print Menu Dialog
void FunMenu() {
    cout << "**********************************" << '\n';
    cout << "*********** Data Input ***********" << '\n';
    cout << "Initial Investment Amount: $";
    numStartAmount = CheckValue();
    cout << "Monthly Deposit: $";
    numMonthlyDis = CheckValue();
    cout << "Annual Interest: %";
    numAnnualInt = CheckValue();
    cout << "Number of Years ";
    numYears = CheckValue();
    cout << "**********************************" << '\n';
    cout << "**********************************" << '\n';
}

// Print a line of the table
void PrintFunction(int numWidth, int numMonth, double numOpenBal, double numDeposit, double numTotal, double numIntTotal, double numClosingBal) {
    const char txtChar = ' ';
    cout << fixed;
    cout << left << setw(10) << setfill(txtChar) << setprecision(2) << numMonth;
    cout << left << setw(numWidth) << setfill(txtChar) << setprecision(2) << numOpenBal;
    cout << left << setw(numWidth) << setfill(txtChar) << setprecision(2) << numDeposit;
    cout << left << setw(numWidth) << setfill(txtChar) << setprecision(2) << numTotal;
    cout << left << setw(numWidth) << setfill(txtChar) << setprecision(2) << numIntTotal;
    cout << left << setw(numWidth) << setfill(txtChar) << setprecision(2) << numClosingBal;
    cout << '\n';

}

// Print Title
void FunTitle(int numWidth, string txtWith) {
    const char txtChar = ' ';
    cout << left << setw(110) << setfill('=') << '=';
    cout << '\n';
    cout << " Balance and Interest " << txtWith << " Additional Monthly Deposits" << '\n';
    cout << left << setw(110) << setfill('-') << '-';
    cout << '\n';
    // Title Table
    cout << left << setw(10) << setfill(txtChar) << "Month";
    cout << left << setw(numWidth) << setfill(txtChar) << "Opening Balance";
    cout << left << setw(numWidth) << setfill(txtChar) << "Monthly Deposit";
    cout << left << setw(numWidth) << setfill(txtChar) << "Total";
    cout << left << setw(numWidth) << setfill(txtChar) << "Interest";
    cout << left << setw(numWidth) << setfill(txtChar) << "Closing Balance";
    cout << '\n';
}

// Create Table
void FunCal(int numWidth, double numMonth, double numOpenBal, double numIntr, double numDeposit) {
    double numTotal;
    double numIntTotal;
    double numClosingBal;

    for (int i = 1; i <= numMonth; ++i) {
        numTotal = numOpenBal + numDeposit;
        numIntTotal = numTotal * numIntr;
        numClosingBal = numTotal + numIntTotal;
        PrintFunction(numWidth, i, numOpenBal, numDeposit, numTotal, numIntTotal, numClosingBal);
        numOpenBal = numClosingBal;
    }
}

// Create Output
void FunOutput() {
    // Variables
    double numMonth;
    double numOpenBal;
    double numDeposit;
    double numIntr;
    const char txtChar = ' ';
    const int numWidth = 20;

    // Do Math
    numMonth = numYears * 12;
    numOpenBal = numStartAmount;
    numIntr = ((numAnnualInt / 100) / 12);
    numDeposit = numMonthlyDis;

    // Build table Without monthly deposit
    FunTitle(numWidth, "Without");
    FunCal(numWidth, numMonth, numOpenBal, numIntr, 0);

    // Build table With Monthly Deposit
    FunTitle(numWidth, "With");
    FunCal(numWidth, numMonth, numOpenBal, numIntr, numDeposit);
}

void LoopCode() {
    string txtStop;

    while (true) {
        FunMenu();
        FunOutput();

        cout << '\n' << '\n';
        cout << left << setw(110) << setfill('=') << '=';
        cout << '\n' << '\n';
        cout << "Type y to Calculate again" << '\n';
        cout << "Type any other key to exit" << '\n';
        cin >> txtStop;

        // exit if anything other than y typed
        if (txtStop != "y") {
            break;
        }
    }
}

int main() {
    LoopCode();
    return 0;
}
