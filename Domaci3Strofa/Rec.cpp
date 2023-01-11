
#include <iostream>
#include <string>
#include "Rec.h"

using namespace std;

int Rec::operator~() const
{
    int cnt = 0;

    Skup samoglasnici("aeiou");
    Skup sonat("lnr");

    for (int i = 0; i < size(); i++) {
        if (samoglasnici(tekst[i])) cnt++;
        else if (sonat(tekst[i]) && i > 0 && i < size() - 1) {

            if ((tekst[i] == 'l' || tekst[i] == 'n') && tekst[i - 1] != 'j' && !samoglasnici(tekst[i - 1]) && !samoglasnici(tekst[i + 1])) cnt++;

            else if (!samoglasnici(tekst[i - 1]) && !samoglasnici(tekst[i + 1]) && tekst[i] == 'r') cnt++;
        }
    }

    return cnt;
}


int Rec::operator()(int n) const
{

    int cnt = 0;

    Skup samoglasnici("aeiou");
    Skup sonat("lnr");

    

    if (n > 0) {
        for (int i = 0; i < size(); i++) {
            if (samoglasnici(tekst[i])) cnt++;
            else if (sonat(tekst[i]) && i > 0 && i < size() - 1) {

                if ((tekst[i] == 'l' || tekst[i] == 'n') && tekst[i - 1] != 'j' && !samoglasnici(tekst[i - 1]) && !samoglasnici(tekst[i + 1])) cnt++;

                else if (!samoglasnici(tekst[i - 1]) && !samoglasnici(tekst[i + 1]) && tekst[i] == 'r') cnt++;
            }
            if (n == cnt) {
                return i;
            }
        }
    }
    else if (n < 0) {
        for (int i = size() - 1; i != 0; i--) {
            if (samoglasnici(tekst[i])) cnt++;
            else if (sonat(tekst[i]) && i > 0 && i < size() - 1) {

                if ((tekst[i] == 'l' || tekst[i] == 'n') && tekst[i - 1] != 'j' && !samoglasnici(tekst[i - 1]) && !samoglasnici(tekst[i + 1])) cnt++;

                else if (!samoglasnici(tekst[i - 1]) && !samoglasnici(tekst[i + 1]) && tekst[i] == 'r') cnt++;
            }
            if (-n == cnt) {
                return i;
            }
        }
    }
    else {
        for (int i = 0; i < size(); i++) {
            if (samoglasnici(tekst[i])) return i;
            else if (sonat(tekst[i]) && i > 0 && i < size() - 1) {

                if ((tekst[i] == 'l' || tekst[i] == 'n') && tekst[i - 1] != 'j' && !samoglasnici(tekst[i - 1]) && !samoglasnici(tekst[i + 1])) return i;

                else if (!samoglasnici(tekst[i - 1]) && !samoglasnici(tekst[i + 1]) && tekst[i] == 'r') return i;
            }
        }
    }

    return -1;
}

int Rec::size() const
{
    int cnt = 0;

    for (auto& c : tekst) {
        cnt++;
    }

    return cnt;
}

istream& operator>>(istream& ut, Rec& r)
{
    char c;
    int cnt = 0, i;
    string rec = "";
    int pocetak = 0;
    Lista<char> svi_kar;

    ut >> rec;

    for (char& c : rec) {
        svi_kar.dodaj(c);
        cnt++;
        if (c < 'A' && c > 'z') pocetak = cnt;
    }

    rec = "";

    for (i = 0, svi_kar.reset_tek(); i < pocetak; i++, svi_kar.sled());

    for (; svi_kar.check_tek(); svi_kar.sled()) rec += svi_kar.get_tek();

    r.tekst = rec;

    return ut;
}

bool operator^(const Rec& r1, const Rec& r2)
{
    int nosilac1 = 0, nosilac2 = 0;

    int broj_slogova = 0;

    if (~r1 == 1 || ~r2 == 1) broj_slogova = 1;
    else broj_slogova = 2;

    Lista<char> slog1, slog2;

    nosilac1 = r1(-broj_slogova); nosilac2 = r2(-broj_slogova);
    for (int i = nosilac1; i < r1.size(); i++) slog1.dodaj(r1.tekst[i]);
    for (int i = nosilac2; i < r2.size(); i++) slog2.dodaj(r2.tekst[i]);

    for (slog1.reset_tek(), slog2.reset_tek(); slog1.check_tek() || slog2.check_tek(); slog1.sled(), slog2.sled()) {
        if (slog1.get_tek() != slog2.get_tek()) return false;
    }

    return true;
}
