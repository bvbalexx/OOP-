#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>

using namespace std;



class MateriePrima {

private:
	char* tip = nullptr;
	int cantitate = 0;

public:

	void stoc(int cantitate)
	{
		this->cantitate = this->cantitate - cantitate;

	}

	int gestiuneStoc() {
		if (this->cantitate >= 0)
			return 1;
		else return 0;
	}

	void setTip(const char* tipnou)
	{
		if (strlen(tipnou) > 0)
			strcpy(this->tip, tipnou);
	}
	char* getTip()
	{
		return this->tip;
	}

	void setCantitate(int cantitatenoua)
	{

		this->cantitate = cantitatenoua;
	}
	int getCantitate()
	{
		return this->cantitate;
	}

	~MateriePrima() {

		delete[] this->tip;
		this->tip = nullptr;
	}

	MateriePrima(int cantitate) : cantitate(cantitate) {}

	MateriePrima(const char* tip, int cantitate) : cantitate(cantitate) {

		if (tip != NULL)
		{
			this->tip = new char[strlen(tip) + 1];
			strcpy(this->tip, tip);
		}
		if (cantitate > 0)
			this->cantitate = cantitate;
	}

	MateriePrima(const MateriePrima& mp)
	{
		if (mp.tip != NULL)
		{
			this->tip = new char[strlen(mp.tip) + 1];
			strcpy(this->tip, mp.tip);
		}
		if (cantitate > 0)
			this->cantitate = mp.cantitate;

	}

	void operator=(const MateriePrima& mp) {

		delete[] this->tip;
		this->tip = nullptr;
		if (mp.tip != NULL)
		{
			this->tip = new char[strlen(mp.tip) + 1];
			strcpy(this->tip, mp.tip);
		}
		if (cantitate > 0)
			this->cantitate = mp.cantitate;
	}

	friend ostream& operator<<(ostream& out, const MateriePrima& mp) {

		out << "\n---------AFISARE MATERIE PRIMA-----------";
		out << "\nTip:" << mp.tip;
		out << "\nCantitate:" << mp.cantitate;
		out << "\n-------------------------";
		return out;
	}

	friend istream& operator>>(istream& in, MateriePrima& mp) {

		delete[] mp.tip;
		mp.tip = nullptr;
		cout << "\nIntroduceti tipul: ";
		string buffer;
		in >> buffer;
		mp.tip = new char[buffer.size() + 1];
		strcpy(mp.tip, buffer.data());
		cout << "Introduceti cantitatea disponibila din aceasta materie prima: ";
		in >> mp.cantitate;
		return in;
	}

	bool operator!() {
		if (this->tip == nullptr)
			return false;
	}

	bool operator>=(const MateriePrima& mp)const {

		if (this->cantitate >= mp.cantitate)
			return true;
		else return false;
	}
	void afisare()
	{
		cout << "\n--------------------";
		cout << "\nTip:" << this->tip;
		cout << "\nCantitate:" << this->cantitate;
		cout << "\n--------------------";
	}

	bool operator==(const MateriePrima& mp) {

		if (strcmp(this->tip, mp.tip) != 0 || this->cantitate != mp.cantitate) {
			return false;
		}
		else return true;
	}

};

class Preparat

{
private:
	char* denumire = nullptr;
	int nrIngrediente = 0;
	string* ingrediente = nullptr;
	int* gramajIngrediente = nullptr;


public:

	void setdenumire(char* denumirenoua)
	{
		if (strlen(denumirenoua) > 0)
			this->denumire = denumirenoua;

	}
	char* getDenumire()
	{
		return this->denumire;
	}

	void setnrIngrediente(int nrIngrediente)
	{
		if (nrIngrediente > 0)
			this->nrIngrediente = nrIngrediente;
	}
	int getnrIngrediente()
	{
		return this->nrIngrediente;
	}


	Preparat() {
		this->denumire = nullptr;
		this->nrIngrediente = 0;
		this->ingrediente = nullptr;
		this->gramajIngrediente = nullptr;
	}

	Preparat(const char* denumire, int nrIngrediente, string* ingrediente, int* gramajIngrediente)
	{
		if (denumire != nullptr && strlen(denumire) > 0)
		{
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}

		if (nrIngrediente > 0)
		{
			this->nrIngrediente = nrIngrediente;

			this->gramajIngrediente = new int[nrIngrediente];
			this->ingrediente = new string[nrIngrediente];

			for (int i = 0; i < nrIngrediente; i++)
			{
				this->gramajIngrediente[i] = gramajIngrediente[i];

				this->ingrediente[i] = ingrediente[i];
			}

		}

	}

	Preparat(const Preparat& p)
	{

		if (p.denumire != nullptr && strlen(p.denumire) > 0)
		{
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy(this->denumire, p.denumire);
		}

		if (p.nrIngrediente > 0)
		{
			this->nrIngrediente = p.nrIngrediente;

			this->gramajIngrediente = new int[p.nrIngrediente];
			this->ingrediente = new string[p.nrIngrediente];

			for (int i = 0; i < p.nrIngrediente; i++)
			{
				this->gramajIngrediente[i] = p.gramajIngrediente[i];

				this->ingrediente[i] = p.ingrediente[i];
			}

		}

	}

	~Preparat() {

		delete[] this->denumire;
		this->denumire = nullptr;

		delete[] this->ingrediente;
		this->ingrediente;

		delete[] this->gramajIngrediente;
		this->gramajIngrediente;


	}

	void operator=(const Preparat& p) {

		delete[] this->denumire;
		this->denumire = nullptr;

		delete[] this->ingrediente;
		this->ingrediente;

		delete[] this->gramajIngrediente;
		this->gramajIngrediente;

		if (p.denumire != nullptr && strlen(p.denumire) > 0)
		{
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy(this->denumire, p.denumire);
		}

		if (p.nrIngrediente > 0)
		{
			this->nrIngrediente = p.nrIngrediente;

			this->gramajIngrediente = new int[p.nrIngrediente];
			this->ingrediente = new string[p.nrIngrediente];

			for (int i = 0; i < p.nrIngrediente; i++)
			{
				this->gramajIngrediente[i] = p.gramajIngrediente[i];

				this->ingrediente[i] = p.ingrediente[i];
			}

		}

	}

	friend ostream& operator<<(ostream& out, const Preparat& p) {

		out << "\n---------" << p.denumire << "------------";
		out << "\nDenumire preparat: " << p.denumire;
		out << "\nNumar ingrediente necesare:" << p.nrIngrediente;
		out << "\nLista ingredientelor si a gramajelor necesare: " << endl;
		for (int i = 0; i < p.nrIngrediente; i++)
		{
			out << p.ingrediente[i] << " -- " << p.gramajIngrediente[i] << " grame " << endl;

		}




		return out;
	}

	void afisare() {
		cout << "\n---------AFISARE PREPARAT-----------";
		cout << "\nDenumire preparat: " << this->denumire;
		cout << "\nNumar ingrediente necesare:" << this->nrIngrediente;
		cout << "\nLista ingredientelor si a gramajelor necesare: " << endl;
		for (int i = 0; i < this->nrIngrediente; i++)
		{
			cout << this->ingrediente[i] << " -- " << this->gramajIngrediente[i] << " grame " << endl;

		}


		cout << "\n----------------------------";

	}
	string afisareIndex()
	{
		return this->denumire;

	}

	friend istream& operator>>(istream& in, Preparat& p) {

		delete[] p.denumire;
		p.denumire = nullptr;

		delete[] p.ingrediente;
		p.ingrediente = nullptr;

		delete[] p.gramajIngrediente;
		p.gramajIngrediente = nullptr;

		cout << "\nIntroduceti numele preparatului: ";
		string buffer;
		in >> buffer;
		p.denumire = new char[buffer.size() + 1];
		strcpy(p.denumire, buffer.data());


		cout << "Introduceti numarul necesar de ingrediente al acestui preparat: ";
		in >> p.nrIngrediente;

		p.ingrediente = new string[p.nrIngrediente];
		p.gramajIngrediente = new int[p.nrIngrediente];

		for (int i = 0; i < p.nrIngrediente; i++)
		{
			cout << "Ingredientul " << i + 1 << " este: "; in >> p.ingrediente[i];
			cout << "Gramajul necesar din ingredientul " << i + 1 << " este: "; in >> p.gramajIngrediente[i];
			cout << endl;
		}


		return in;
	}


};

class Meniu {

private:
	Preparat* preparate = nullptr;
	float* preturi = nullptr;
	int numarPreparate = 0;

public:

	void setNumarPreparate(int nr)
	{
		if (nr > 0)
			this->numarPreparate = nr;
	}
	int getNumarPreparate()
	{
		return this->numarPreparate;
	}

	Meniu() {

		this->preparate = nullptr;
		this->preturi = nullptr;
		this->numarPreparate = 0;
	}
	Meniu(Preparat preparate) {

		this->preparate = nullptr;
		this->preturi = nullptr;
		this->numarPreparate = 0;


	}

	Meniu(Preparat* preparate, float* preturi, int numarPreparate)
	{
		if (numarPreparate > 0 && preturi != nullptr)
		{

			this->numarPreparate = numarPreparate;

			this->preparate = new Preparat[this->numarPreparate];
			this->preturi = new float[this->numarPreparate];

			for (int i = 0; i < this->numarPreparate; i++)
			{
				this->preparate[i] = preparate[i];
				this->preturi[i] = preturi[i];

			}


		}
	}
	Meniu(const Meniu& m) {

		if (m.numarPreparate > 0 && m.preturi != nullptr)
		{

			this->numarPreparate = m.numarPreparate;
			this->preparate = new Preparat[m.numarPreparate];


			this->preturi = new float[m.numarPreparate];
			for (int i = 0; i < m.numarPreparate; i++)
			{
				this->preparate[i] = m.preparate[i];
				this->preturi[i] = m.preturi[i];

			}


		}

	}


	~Meniu() {

		delete[] this->preparate;
		this->preparate = nullptr;

		delete[] this->preturi;
		this->preturi = nullptr;


	}

	void afisare() {
		cout << "\n---------AFISARE MENIU-----------";

		for (int i = 0; i < this->numarPreparate; i++)
		{
			cout << preparate[i];

		}
	}


	friend ostream& operator<<(ostream& out, const Meniu& m) {
		out << "\n--------- MENIU-----------" << endl << endl;
		out << "\nNumar preparate : " << m.numarPreparate << endl;
		for (int i = 0; i < m.numarPreparate; i++)
		{

			out << i + 1 << ". " << m.preparate[i] << " ";
			out << "PRET: " << m.preturi[i] << " RON" << " " << endl << endl;

		}
		return out;
	}

	void operator=(const Meniu& m) {

		delete[] this->preparate;
		this->preparate = nullptr;

		delete[] this->preturi;
		this->preturi = nullptr;

		if (m.numarPreparate > 0 && m.preturi != nullptr)
		{

			this->numarPreparate = m.numarPreparate;
			this->preparate = new Preparat[m.numarPreparate];


			this->preturi = new float[m.numarPreparate];
			for (int i = 0; i < m.numarPreparate; i++)
			{
				this->preparate[i] = m.preparate[i];
				this->preturi[i] = m.preturi[i];

			}


		}
	}

	friend istream& operator>>(istream& in, Meniu& m) {

		delete[] m.preparate;
		m.preparate = nullptr;

		delete[] m.preturi;
		m.preturi = nullptr;

		cout << "\nIntroduceti numarul de preparate care sa existe in meniu: ";
		in >> m.numarPreparate;

		m.preparate = new Preparat[m.numarPreparate];
		m.preturi = new float[m.numarPreparate];

		for (int i = 0; i < m.numarPreparate; i++)
		{
			cout << "Preparatul " << i + 1 << "este "; in >> m.preparate[i];
		}

		return in;

	}

};

class Restaurant {

private:

	Meniu* meniuRestaurant = nullptr;
	char* numeRestaurant = nullptr;
	char* locatieRestaurant = nullptr;
	static int numarMese;
	int numarAngajati = 0;;

public:

	void setNume(char* denumireNoua)
	{
		if (denumireNoua != nullptr)
			this->numeRestaurant = denumireNoua;
	}
	char* getNume()
	{
		return this->numeRestaurant;

	}

	void setLocatie(char* locatieNoua)
	{
		if (locatieNoua != nullptr)
			this->locatieRestaurant = locatieNoua;
	}
	char* getLocatie()
	{
		return this->locatieRestaurant;

	}

	void setnrAngajati(int nrNou)
	{
		if (nrNou > 0)
			this->numarAngajati = nrNou;
	}
	int getnrAngajati()
	{
		return this->numarAngajati;
	}


	Restaurant(Meniu* meniuRestaurant, const char* numeRestaurant, const char* locatieRestaurant, int numarAngajati)
	{

		this->meniuRestaurant = meniuRestaurant;
		this->numarMese = numarMese;
		if (numeRestaurant != nullptr)
		{
			this->numeRestaurant = new char[strlen(numeRestaurant) + 1];
			strcpy(this->numeRestaurant, numeRestaurant);
		}
		if (locatieRestaurant != nullptr)
		{
			this->locatieRestaurant = new char[strlen(locatieRestaurant) + 1];
			strcpy(this->locatieRestaurant, locatieRestaurant);
		}
		if (numarAngajati > 0)
			this->numarAngajati = numarAngajati;
	}

	Restaurant(const Restaurant& r)
	{
		this->meniuRestaurant = r.meniuRestaurant;
		this->numarMese = numarMese;
		if (r.numeRestaurant != nullptr)
		{
			this->numeRestaurant = new char[strlen(r.numeRestaurant) + 1];
			strcpy(this->numeRestaurant, r.numeRestaurant);
		}
		if (r.locatieRestaurant != nullptr)
		{
			this->locatieRestaurant = new char[strlen(r.locatieRestaurant) + 1];
			strcpy(this->locatieRestaurant, r.locatieRestaurant);
		}
		if (r.numarAngajati > 0)
			this->numarAngajati = r.numarAngajati;

	}

	void operator=(const Restaurant& r)
	{
		delete[] this->meniuRestaurant;
		this->meniuRestaurant = nullptr;


		delete[] this->numeRestaurant;
		this->numeRestaurant = nullptr;

		delete[] this->locatieRestaurant;
		this->locatieRestaurant = nullptr;

		this->meniuRestaurant = r.meniuRestaurant;
		this->numarMese = numarMese;
		if (r.numeRestaurant != nullptr)
		{
			this->numeRestaurant = new char[strlen(r.numeRestaurant) + 1];
			strcpy(this->numeRestaurant, r.numeRestaurant);
		}

		if (r.locatieRestaurant != nullptr)
		{
			this->locatieRestaurant = new char[strlen(r.locatieRestaurant) + 1];
			strcpy(this->locatieRestaurant, r.locatieRestaurant);
		}
		if (r.numarAngajati > 0)
			this->numarAngajati = r.numarAngajati;

	}

	~Restaurant() {

		delete[] this->meniuRestaurant;
		this->meniuRestaurant = nullptr;

		delete[] this->numeRestaurant;
		this->numeRestaurant = nullptr;

		delete[] this->locatieRestaurant;
		this->locatieRestaurant = nullptr;
	}

	friend ostream& operator<<(ostream& out, const Restaurant& r) {

		out << "\n---------" << r.numeRestaurant << "------------";
		out << "\nNumele restaurantului este: " << r.numeRestaurant;
		out << "\nRestaurantul se afla in: " << r.locatieRestaurant;
		out << "\nRestaurantul are: " << r.numarMese << " disponibile ";
		out << "\nRestaurantul are: " << r.numarAngajati << " angajati ";

		return out;
	}
	friend istream& operator>>(istream& in, Restaurant& r) {


		delete[] r.numeRestaurant;
		r.numeRestaurant = nullptr;

		delete[] r.locatieRestaurant;
		r.locatieRestaurant = nullptr;

		r.meniuRestaurant = new Meniu;
		r.numeRestaurant = new char;
		r.locatieRestaurant = new char;

		cout << "\nIntroduceti numele restaurantului: "; in >> r.numeRestaurant;
		cout << "\nIntroduceti locatia restaurantului: "; in >> r.locatieRestaurant;
		cout << "\nIntroduceti numarul de angajati al restaurantului: "; in >> r.numarAngajati;



		return in;
	}

};
int Restaurant::numarMese = 25;

class Comanda {

private:

	const int ID;
	Preparat* elementeComanda = nullptr;
	int* numarElementeComanda = nullptr;
	int totalElemente = 0;

public:

	int getID()
	{
		return this->ID;
	}

	int gettotalelemente() {
		this->totalElemente;
	}



	Comanda(int ID) : ID(ID) {};

	Comanda(int ID, Preparat* elementeComanda, int* numarElementeComanda, int totalElemente) : ID(ID) {

		if (totalElemente > 0) {

			this->totalElemente = totalElemente;

			if (elementeComanda != nullptr)
			{
				this->elementeComanda = new Preparat[this->totalElemente];
				this->numarElementeComanda = new int[this->totalElemente];
				for (int i = 0; i < this->totalElemente; i++)
				{
					this->elementeComanda[i] = elementeComanda[i];
					this->numarElementeComanda[i] = numarElementeComanda[i];
				}

			}


		}
		else
		{
			this->totalElemente = 0;
			this->elementeComanda = nullptr;
			this->numarElementeComanda = nullptr;
		}
	}

	~Comanda() {
		delete[] this->elementeComanda;
		this->elementeComanda = nullptr;

		delete[] this->numarElementeComanda;
		this->numarElementeComanda = nullptr;
	}

	Comanda(const Comanda& c) : ID(c.ID)
	{

		if (totalElemente > 0) {

			this->totalElemente = totalElemente;

			if (elementeComanda != nullptr)
			{
				this->elementeComanda = new Preparat[this->totalElemente];
				this->numarElementeComanda = new int[this->totalElemente];
				for (int i = 0; i < this->totalElemente; i++)
				{
					this->elementeComanda[i] = elementeComanda[i];
					this->numarElementeComanda[i] = numarElementeComanda[i];
				}

			}


		}
	}

	void operator=(const Comanda& c) {

		delete[] this->elementeComanda;
		this->elementeComanda = nullptr;

		delete[] this->numarElementeComanda;
		this->numarElementeComanda = nullptr;
		if (totalElemente > 0) {

			this->totalElemente = totalElemente;

			if (elementeComanda != nullptr)
			{
				this->elementeComanda = new Preparat[this->totalElemente];
				this->numarElementeComanda = new int[this->totalElemente];
				for (int i = 0; i < this->totalElemente; i++)
				{
					this->elementeComanda[i] = elementeComanda[i];
					this->numarElementeComanda[i] = numarElementeComanda[i];
				}

			}


		}


	}

	friend ostream& operator<<(ostream& out, const Comanda& c)
	{
		out << "\nID-ul comenzii este: " << c.ID;
		out << "\nComanda contine: " << c.totalElemente << " preparate ";
		out << "\nComanda este compusa din: ";
		for (int i = 0; i < c.totalElemente; i++)
		{
			out << "\nPreparatul " << c.elementeComanda[i] << " ";

		}
		return out;

	}
	friend istream& operator>>(istream& in, Comanda& c) {

		delete[] c.elementeComanda;
		c.elementeComanda = nullptr;

		delete[] c.numarElementeComanda;
		c.numarElementeComanda = nullptr;



		cout << "\Introduceti numarul de preparate dorite: "; in >> c.totalElemente;

		c.elementeComanda = new Preparat[c.totalElemente];
		c.numarElementeComanda = new int[c.totalElemente];

		for (int i = 0; i < c.totalElemente; i++)
		{
			cout << "\Introduceti preparatul dorit si cantitatea acestuia: "; in >> c.elementeComanda[i]; in >> c.numarElementeComanda[i];
		}
		return in;

	}


};




int main() {

	MateriePrima faina("faina", 2999);
	MateriePrima cartofi("cartofi", 10000);
	MateriePrima ulei("ulei", 350);
	MateriePrima pui("pui", 5000);
	MateriePrima legume("legume", 3000);
	MateriePrima orez("orez", 6000);
	MateriePrima zahar("zahar", 200);
	MateriePrima oua("oua", 400);
	MateriePrima lapte("lapte", 2000);
	MateriePrima nutella("nutella", 100);

	string IngredienteArray1[] = { "cartofi", "ulei" };
	int gramajIngredienteArray1[] = { 200, 30 };

	string IngredienteArray3[] = { "pui", "legume", "orez" };
	int gramajIngredienteArray3[] = { 200, 360, 400 };

	string IngredienteArray2[] = { "zahar", "faina", "oua", "lapte" };
	int gramajIngredienteArray2[] = { 30, 100 , 20 , 300 };

	string IngredienteArray4[] = { "lapte", "oua", "nutella" };
	int gramajIngredienteArray4[] = { 17, 10, 100 };

	Preparat clatite("Clatite", 3, IngredienteArray4, gramajIngredienteArray4);
	Preparat cartofiprajiti("Cartofi prajiti", 2, IngredienteArray1, gramajIngredienteArray1);
	Preparat prajitura("Prajitura", 4, IngredienteArray2, gramajIngredienteArray2);
	Preparat PuiCuptor("Pui la cuptor cu legume si orez", 3, IngredienteArray3, gramajIngredienteArray3);



	Preparat preparate[] = { cartofiprajiti,prajitura, PuiCuptor,clatite };
	float preturiMeniu[] = { 20, 30, 50, 15 };

	Meniu meniu(preparate, preturiMeniu, 4);




	int optiune;
	int tComanda = 0;
	while (tComanda == 0)
	{
		cout << "Alegeti optiunea dorita: " << endl;
		cout << "1.Afisare meniu " << endl;
		cout << "2.Comanda " << endl;
		cout << "3.EXIT " << endl;

		cin >> optiune;
		switch (optiune) {

		case 1: cout << meniu;
			break;

		case 2: cout << "Introduceti numarul de preparate dorite: " << endl;
			int nrprep; cin >> nrprep;

			for (int i = 0; i < nrprep; i++)
			{

				cout << "Introduceti  numarul corespunzator preparatului dorit din meniu: "; int p; cin >> p;

				if (p < 0 || p>4)

				{
					cout << "Numar preparat invalid" << endl;
					cout << "Introduceti  numarul corespunzator preparatului dorit din meniu: "; cin >> p;

				}
				else

					if (p >= 1 && p <= 4)
					{
						if (p == 1) {


							cartofi.stoc(200);
							ulei.stoc(30);


						}
						else
							if (p == 2) {

								zahar.stoc(30);
								faina.stoc(100);
								oua.stoc(20);
								lapte.stoc(300);

							}
							else


								if (p == 3) {
									pui.stoc(200);
									legume.stoc(360);
									orez.stoc(400);

								}
								else
									if (p == 4) {
										lapte.stoc(17);
										oua.stoc(10);
										nutella.stoc(100);


									}
					}










			}


			if (cartofi.gestiuneStoc() == 1 && ulei.gestiuneStoc() == 1 && zahar.gestiuneStoc() == 1 && faina.gestiuneStoc() == 1 && oua.gestiuneStoc() == 1
				&& lapte.gestiuneStoc() == 1 && pui.gestiuneStoc() == 1 && legume.gestiuneStoc() == 1 && orez.gestiuneStoc() == 1 && nutella.gestiuneStoc() == 1)

				cout << "Comanda a fost plasata" << endl;
			else
				cout << "Comanda nu a fost plasata, nu exista suficiente materii prime" << endl;

			break;

		case 3: tComanda++;
			break;



		}

	}
	return 0;
}