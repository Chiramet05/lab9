#include <iostream>
#include <iomanip> // For using setw(), setprecision(), ...
using namespace std;

int main()
{
	double initialLoan, interestRate, annualPayment;
	cout << "Enter initial loan: ";
	cin >> initialLoan;

	cout << "Enter interest rate per year (%): ";
	cin >> interestRate;

	cout << "Enter amount you can pay per year: ";
	cin >> annualPayment;

	cout << setw(13) << left << "EndOfYear#";
	cout << setw(13) << left << "PrevBalance";
	cout << setw(13) << left << "Interest";
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	cout << fixed << setprecision(2);

	double balance = initialLoan;
	int year = 1;

	while (balance > 0)
	{
		double interest = balance * (interestRate / 100);
		double total = balance + interest;
		double payment = (total < annualPayment) ? total : annualPayment;

		cout << setw(13) << left << year;
		cout << setw(13) << left << balance;
		cout << setw(13) << left << interest;
		cout << setw(13) << left << total;
		cout << setw(13) << left << payment;
		balance = total - payment;
		cout << setw(13) << left << (balance < 0 ? 0.00 : balance);
		cout << "\n";

		if (balance <= 0)
			break;
		year++;
	}

	return 0;
}