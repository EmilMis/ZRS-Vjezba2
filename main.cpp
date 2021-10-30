#include <iostream>
#include <vector>

using namespace std;

int has_lost(int limit, int amount) {
	if (limit <= amount)
	{
		return 1;
	}
	return 0;
}

int ppq(string kamenje, int index) {
	if (kamenje[index] == 'C')
	{
		return 1;
	}
	return 0;
}

int min_(int n1, int n2) {
	if (n1 > n2) {
		return n2;
	}
	return n1;
}

int can_win(string kamenje, int kamenje_CB, int kamenje_CA, int limit, int player) {
	int player_kamenje;
	if (player == 0)
	{
		player_kamenje = kamenje_CB;
	}
	else {
		player_kamenje = kamenje_CA;
	}
	if (has_lost(limit, player_kamenje) == 1)
	{
		return 0;
	}

	if (kamenje.size() == 0)
	{
		return 0;
	}

	string kamenje1 = kamenje.substr(0, kamenje.size() - 1);
	string kamenje2 = kamenje.substr(1, kamenje.size());

	int win1;
	int win2;

	if (player == 0)
	{
		win1 = can_win(kamenje1, kamenje_CB + ppq(kamenje, kamenje.size() - 1), kamenje_CA, limit, (player + 1) % 2);
		win2 = can_win(kamenje2, kamenje_CB + ppq(kamenje, 0), kamenje_CA, limit, (player + 1) % 2);

	}
	else {
		win1 = can_win(kamenje1, kamenje_CB, kamenje_CA + ppq(kamenje, kamenje.size() - 1), limit, (player + 1) % 2);
		win2 = can_win(kamenje2, kamenje_CB, kamenje_CA + ppq(kamenje, 0), limit, (player + 1) % 2);
	}

	int _min = min_(win1, win2);

	if (_min == 0)
	{
		return 1;
	}
	return 0;

}

int main(void) {
	int broj_kamencica;
	int limit;
	string kamenje;
	scanf_s("%d%d", &broj_kamencica, &limit);
	cin >> kamenje;
	int status =  can_win(kamenje, 0, 0, limit, 0);

	if (status == 1) {
		cout << "DA";
		return 0;
	}

	cout << "NE";
	return 0;

}
