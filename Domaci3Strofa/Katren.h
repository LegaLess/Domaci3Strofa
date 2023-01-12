#ifndef _KATREN_H_
#define _KATREN_H_

#include <iostream>
#include <string>
#include "Strofa.h"

using namespace std;

class Katren : public Strofa {

public:

	Katren() : Strofa(4) { oznaka = 'K'; }
	virtual bool operator*() const override { return stihovi.length() == 4 && stihovi[0] ^ stihovi[3] && stihovi[1] ^ stihovi[2]; }
	virtual char get_oznaka() const override { return oznaka; }

private:



};


#endif
