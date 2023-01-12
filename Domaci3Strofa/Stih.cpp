#include <iostream>
#include <string>
#include "Stih.h"

using namespace std;

int Stih::operator~() const
{
	int cnt = 0;

	for (tekst.reset_tek(); tekst.check_tek(); tekst.sled()) {
		cnt += ~tekst.get_tek();
	}

	return cnt;
}

Rec& Stih::operator[](int n)
{
	int i = 0;

	for (tekst.reset_tek(), i; tekst.check_tek() && i != n; tekst.sled(), i++) {}

	return tekst.get_tek();
}

const Rec& Stih::operator[](int n) const
{
	int i = 0;

	for (tekst.reset_tek(), i; tekst.check_tek() && i != n; tekst.sled(), i++) {}

	return tekst.get_tek();
}

istream& operator>>(istream& ut, Stih& s)
{
	string tekst;

	std::getline(ut, tekst);

	string rec;


	for (auto x : tekst) {
		if (x != ' ') {
			rec += x;
		}
		else {
			s += Rec(rec);
			rec = "";
		}
	}

	s += Rec(rec);

	return ut;
}

ostream& operator<<(ostream& it, const Stih& s)
{
	int i = 0;

	for (s.tekst.reset_tek(), i; s.tekst.check_tek(); s.tekst.sled(), i++) {
		if (i == s.tekst.length() - 1) {
			cout << s.tekst.get_tek();
		}
		else {
			cout << s.tekst.get_tek() << " ";
		}
	}

	return it;
}
