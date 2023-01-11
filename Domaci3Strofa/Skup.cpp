#include <iostream>
#include <string>
#include "Skup.h"

using namespace std;

Skup& Skup::operator+=(char c)
{
	bool postoji = false;

	for (znakovi.reset_tek(); znakovi.check_tek(); znakovi.sled()) {
		if (znakovi.get_tek() == c) {
			postoji = true;
			break;
		}
	}
	if (!postoji) {
		znakovi.dodaj(c);
		return *this;
	}

	return *this;
}

bool Skup::operator()(char c)
{
	bool postoji = false;

	for (znakovi.reset_tek(); znakovi.check_tek(); znakovi.sled()) {
		if (znakovi.get_tek() == c) {
			postoji = true;
			break;
		}
	}
	
	return postoji;
}

void Skup::dodaj(string& s)
{

	for (char& c : s) {
		znakovi.dodaj(c);
	}

}
