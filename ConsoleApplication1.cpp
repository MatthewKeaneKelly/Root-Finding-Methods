#include <iostream>
#include <cstdlib>

using namespace std

bool tosscoin();
{
	int coinvalue;
	srand(time(nullptr));
	coinvalue = rand() % 2;
	if (coinvalue == 1)
		return true;
	else
		return false;
}

bool gamlersruin(int n1, int n2)
{
	// Player one will be heads, player two will be tails. 
	int finalcoins = n1 + n2;
	const int winnings = 1;
	int counter, result;
	for (counter = 0; (n1 || n2) == finalcoins; counter++) {
		result = tosscoin();
		if (result == 1) {
			n1 = n1 + winnings;
			n2 = n2 - winnings;
		}
		else {
			n2 = n2 + winnings;
			n1 = n1 - winnings;
		}
	}
	if (n1 == finalcoins)
		return true;
	else if (n2 == finalcoins)
		return false;
	else
		return EXIT_FAILURE;
}

int main()
{
	cout << gamlersruin(1, 10);
	int coin;
	coin = tosscoin();
	cout << coin;
}
