#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>

using namespace std;

template <typename T>
class Lista {

public:

	Lista() {}
	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	~Lista() { brisi(); }

	Lista<T>& operator=(const Lista& l) {
		if (this != &l) {
			brisi();
			kopiraj(l);
		}
		return *this;
	}

	Lista<T>& operator=(const Lista&& l) {
		if (this != &l) {
			brisi();
			premesti(l);
		}
		return *this;
	}

	Lista<T>& dodaj(T obj);
	
	void reset_tek() const { tek = prvi; }
	void sled() const { tek = tek->next; }
	bool check_tek() const { return tek; }
	T& get_tek() const { return tek->val; }
	T& get_last() const { return posl->val; }
	Lista<T>& brisi_el(int);
	Lista<T>& insert_el(T&, int);
	T& operator[](int);
	const T& operator[](int) const;
	int length() const;


private:

	void kopiraj(const Lista&);
	void premesti(Lista&);
	void brisi();

	struct Elem {
		T val;
		Elem* next = nullptr;
		Elem(T v) : val(v), next(nullptr) {}
	};

	Elem* prvi = nullptr;
	Elem* posl = nullptr;
	mutable Elem* tek = nullptr;

};

template<typename T>
inline Lista<T>& Lista<T>::dodaj(T obj)
{
	Elem* novi = new Elem(obj);

	if (!prvi) {
		prvi = novi;
		posl = novi;
		reset_tek();
	}
	else {
		posl->next = novi;
		posl = novi;
	}

	return *this;
}

template<typename T>
inline Lista<T>& Lista<T>::brisi_el(int n)
{
	int i = 0;

	Elem* pret = nullptr;

	Elem* pom = prvi;

	if (n == 0) {
		prvi = prvi->next;
		reset_tek();
		delete pom;
	}
	else {
		for (reset_tek(), i; check_tek(); sled(), i++) {
			if (i == n && tek == posl) {
				posl = pret;
				posl->next = nullptr;
				pom = tek;
				reset_tek();
				delete pom;
				break;
			}
			else if (i == n) {
				pret->next = tek->next;
				pom = tek;
				reset_tek();
				delete pom;
				break;
			}
			pret = tek;
		}
	}

	return *this;
}

template<typename T>
inline Lista<T>& Lista<T>::insert_el(T& el, int n)
{
	Elem* novi = new Elem(el);

	int i = 0;

	for (reset_tek(), i; check_tek(); sled(), i++) {
		if (i == n) {
			novi->next = tek->next;
			tek->next = novi;
		}
	}

	return *this;
}

template<typename T>
inline T& Lista<T>::operator[](int n)
{
	int i = 0;

	Elem* pom = prvi;

	while (pom && i != n) {
		i++;
		pom = pom->next;
	}

	return pom->val;
}

template<typename T>
inline const T& Lista<T>::operator[](int n) const
{
	int i = 0;

	Elem* pom = prvi;

	while (pom && i != n) {
		i++;
		pom = pom->next;
	}

	return pom->val;
}

template<typename T>
inline int Lista<T>::length() const
{
	int cnt = 0;

	Elem* pom = prvi;

	while (pom) {
		cnt++;
		pom = pom->next;
	}

	return cnt;
}

template<typename T>
inline void Lista<T>::kopiraj(const Lista& l)
{
	for (l.reset_tek(); l.check_tek(); l.sled()) {
		dodaj(l.get_tek());
	}
}

template<typename T>
inline void Lista<T>::premesti(Lista& l)
{
	prvi = l.prvi;
	tek = l.tek;
	posl = l.posl;

	l.prvi = nullptr;
	l.tek = nullptr;
	l.posl = nullptr;
}

template<typename T>
inline void Lista<T>::brisi()
{
	Elem* tmp = nullptr;

	while (tmp = prvi) {
		prvi = prvi->next;
		delete tmp;
	}

	prvi = nullptr;
	posl = nullptr;
	tek = nullptr;
}

#endif
