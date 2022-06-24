// programul de mai jos citeste niste date de intrare dintr-un fisier, verifica 2 cate 2 daca contin aceleasi cifre
// si daca contin, inverseaza primul element in vector, urmand la final sa afiseze vectorul rezultat
// 123 321 34 45 54 567 675 0   ->    321 321 34 54 54 765 675 
// 12 1233 1132 2338 8533 10000 21500 0     ->     12 3321 1132 2338 8533 10000 21500

#include <iostream>
#include <fstream>
#include <set>
using namespace std;
void functie1(int x[], int& n) { // citeste elementele strict pozitive din fisierul data.in
	ifstream fin("date.in");     // le introduce intr-un vector v, iar cand intalneste
	n = 0;						 // un element <=0, citirea se opreste
	int v = 0;
	do {
		fin >> v;
		if (v > 0) {
			x[n++] = v;
		}
	} while (v > 0);
	fin.close();
}
void functie2(int x[], int n) { // afiseaza in fisierul date.out, vectorul x dat ca parametru
	ofstream fout("date.out");
	for (int i = 0; i < n; i++) {
		fout << x[i] << " ";
	}
	fout << endl;
	fout.close();
}
void functie3(int a, std::set<int>& s) { // insereaza intr-un TAD de tip set cifrele 
	s.clear();							 // numarului a, in ordine inversa
	do {
		s.insert(a % 10);
		a /= 10;
	} while (a > 0);
}
bool functie4(int a, int b) { // populam cele 2 set-uri cu cifrele numerelor a si b
	std::set<int> Ma;		  // si returnam daca seturile sunt egale, adica daca 
	std::set<int> Mb;		  // a si b au aceleasi cifre
	functie3(a, Ma);
	functie3(b, Mb);
	return Ma == Mb;
}
void functie5(int& p) { // calculeaza inversul unui numar p dat ca parametru
	int v = 0;
	do {
		v = v * 10 + p % 10;
		p /= 10;
	} while (p > 0);
	p = v;
}

void functie6(int x[], int n) {			// parcurgem vectorul iar daca 2 elemente consecutive au aceleasi cifre
	for (int i = 0; i < n - 1; i++) {   // ii facem inversul si il inlocuim
		if (functie4(x[i], x[i + 1]))
			functie5(x[i]);
	}
}
int main() {
	int x[100];
	int n = 0;
	functie1(x, n);
	functie6(x, n);
	functie2(x, n);
	return 0;
}