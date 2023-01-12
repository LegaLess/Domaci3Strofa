#ifndef _REC_H_
#define _REC_H_

#include <iostream>
#include <string>
#include "Skup.h"

using namespace std;

class Rec {

public:

	Rec(string s) : tekst(s) {}

	int operator+() const { return size(); }
	int operator~() const;
	int operator()(int) const;
	friend istream& operator>>(istream&, Rec&);
	friend ostream& operator<<(ostream& it, const Rec& r) { return it << r.tekst; }
	friend bool operator^(const Rec&, const Rec&);

private:

	string tekst;

	int size() const;

};

#endif