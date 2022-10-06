#ifndef _SET_H
#define _SET_H

#include <iostream>
#include <string>
#include <initializer_list>
#include <array>
#include <cstdlib>
using namespace std;

namespace Set {
	// classe pour g�rer les exceptions dans le set
	class SetException {
	public:
		SetException(const string& i) :info(i) {}
		string getInfo() const { return info; }
	private:
		string info;
	};

	// caract�ristiques
	enum class Couleur { rouge, mauve, vert };
	enum class Nombre { un=1, deux=2, trois=3 };
	enum class Forme { ovale, vague, losange };
	enum class Remplissage { plein, vide, hachure };

	// conversion d'une caract�ristique en string
	string toString(Couleur c);
	string toString(Nombre v);
	string toString(Forme f);
	string toString(Remplissage v);

	// �criture d'une caract�ristique sur un flux ostream
	ostream& operator<<(ostream& f, Couleur c);
	ostream& operator<<(ostream& f, Nombre v);
	ostream& operator<<(ostream& f, Forme x);
	ostream& operator<<(ostream& f, Remplissage r);

	// listes contenant les valeurs possibles pour chacune des caract�ristiques
	extern std::initializer_list<Couleur> Couleurs;
	extern std::initializer_list<Nombre> Nombres;
	extern std::initializer_list<Forme> Formes;
	extern std::initializer_list<Remplissage> Remplissages;

	// affichage des valeurs possibles pour chaque caract�ristiques
	void printCouleurs(std::ostream& f = cout);
	void printNombres(std::ostream& f = cout);
	void printFormes(std::ostream& f = cout);
	void printRemplissages(std::ostream& f = cout);

	//Classe Carte
	class Carte
	{
	private:
		Couleur couleur;
		Nombre nombre;
		Forme forme;
		Remplissage remplissage;
	public:
		Carte(Couleur c, Nombre n, Forme f, Remplissage r) :couleur(c), nombre(n), forme(f), remplissage(r) {};
		Couleur getCouleur() const { return couleur; };
		Nombre getNombre() const { return nombre; };
		Forme getForme() const { return forme; };
		Remplissage getRemplissage() const { return remplissage; };
	};
	//Classe Jeu
	class Jeu
	{
	private:
		const Carte* cartes[81];
		//Impossible de dupliquer un Jeu par construction ou par affectation
		Jeu(const Jeu&) = delete;
		Jeu& operator=(const Jeu&) = delete;

	public:
		//Constructeur et destructeur
		Jeu();
		~Jeu();
		//Fonction qui retourne le nombre de cartes dans le jeu
		size_t getNbCartes() const { return 81; };
		const Carte& getCarte(size_t i) const;
	};

	//Classe Pioche
	class Pioche
	{
	private:
		const Carte** cartes;
		size_t nb;
		Pioche& operator= (const Pioche& p) = delete;
		Pioche(const Pioche&) = delete;
	public:
		Pioche(const Jeu& j);
		~Pioche();
		size_t getNbCartes() const { return nb; };
		bool estVide() const { return nb == 0; };
		const Carte& piocher();
	};

	//Classe Plateau
	class Plateau
	{
	private:
		const Carte** cartes = nullptr;
		size_t nb = 0; // taille du tableau
		size_t nbMax = 0; // partie utilis�e du tableau
	public:
		Plateau()=default;
		Plateau(const Plateau& p);
		Plateau& operator=(const Plateau& p);
		~Plateau() { delete[] cartes; };
		void ajouter(const Carte& carte);
		void retirer(const Carte& carte);
		void print(ostream& flux = cout);
	};

	//Surchage de << pour afficher une carte
	std::ostream& operator<< (std::ostream& flux, Carte c);
}


#endif