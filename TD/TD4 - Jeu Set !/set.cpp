#include "set.h"

namespace Set {
	
	std::initializer_list<Couleur> Couleurs = { Couleur::rouge, Couleur::mauve, Couleur::vert };
	std::initializer_list<Nombre> Nombres = { Nombre::un, Nombre::deux, Nombre::trois };
	std::initializer_list<Forme> Formes = { Forme::ovale, Forme::vague, Forme::losange };
	std::initializer_list<Remplissage> Remplissages = { Remplissage::plein, Remplissage::vide, Remplissage::hachure };

	string toString(Couleur c) {
		switch (c) { 
		case Couleur::rouge: return "R";
		case Couleur::mauve: return "M";
		case Couleur::vert: return "V";
		default: throw SetException("Couleur inconnue");
		}
	}

	string toString(Nombre v) {
		switch (v) {
		case Nombre::un: return "1";
		case Nombre::deux: return "2";
		case Nombre::trois: return "3";
		default: throw SetException("Nombre inconnue");
		}
	}

	string toString(Forme f) {
		switch (f) {
		case Forme::ovale: return "O";
		case Forme::vague: return "~";
		case Forme::losange: return "\004";
		default: throw SetException("Forme inconnue");
		}
	}

	string toString(Remplissage r) {
		switch (r) {
		case Remplissage::plein: return "P";
		case Remplissage::vide: return "_";
		case Remplissage::hachure: return "H";
		default: throw SetException("Remplissage inconnu");
		}
	}

	std::ostream& operator<<(std::ostream& f, Couleur c) { f << toString(c); return f; }
	std::ostream& operator<<(std::ostream& f, Nombre v) {	f << toString(v); return f; }
	std::ostream& operator<<(std::ostream& f, Forme x) { f << toString(x);  return f; }
	std::ostream& operator<<(std::ostream& f, Remplissage r) { f << toString(r); return f; }

	void printCouleurs(std::ostream& f) {
		for (auto c : Couleurs) f << c << " ";
		f << "\n";
	}

	void printNombres(std::ostream& f) {
		for (auto v : Nombres) f << v << " ";
		f << "\n";
	}

	void printFormes(std::ostream& f) {
		for (auto x : Formes) f << x << " ";
		f << "\n";
	}

	void printRemplissages(std::ostream& f) {
		for (auto r : Remplissages) f << r << " ";
		f << "\n";
	}
	//Surcharge de l'opérateur << pour afficher une carte sur le flux
	std::ostream& operator<<(std::ostream& flux, Carte c)
	{
		flux << "(" << c.getCouleur()<< ", " << c.getForme() << ", " << c.getNombre() << ", " << c.getRemplissage() << ")";
		return flux;
	}

	Jeu::Jeu()
	{
		int indice_carte = 0;
		for (auto c : Couleurs)
		{
			for (auto n : Nombres)
			{
				for (auto f : Formes)
				{
					for (auto r : Remplissages)
					{
						cartes[indice_carte] = new Carte(c, n, f, r);
						indice_carte++;
					}
				}
			}
		}
		
	}

	Jeu::~Jeu()
	{
		for (int i = 0; i < 81; i++)
		{
			delete cartes[i];
		}
	}

	const Carte& Jeu::getCarte(size_t i) const
	{
		if ( i < 0 || i >= getNbCartes()) throw SetException("Erreur : l'indice doit être compris entre 0 et 80 !");
		return *cartes[i];
	}

	Pioche::Pioche(const Jeu& j)
	{
		nb = j.getNbCartes();
		cartes = new const Carte* [j.getNbCartes()];
		for (size_t i = 0; i < j.getNbCartes(); i++)
		{
			cartes[i] = &j.getCarte(i);
		}
	}

	Pioche::~Pioche()
	{
		delete[] cartes;
	}

	const Carte& Pioche::piocher()
	{
		if (estVide())
		{
			throw SetException("Erreur : la pioche est vide !");
		}
		else
		{
			size_t i = rand() % nb;
			//Carte à retourner
			const Carte* old = cartes[i];
			//On modifie la pioche
			cartes[i] = cartes[--nb];
			return *old;
		}
	}

	Plateau::Plateau(const Plateau& p)
	{
		nb = p.nb;
		nbMax = p.nbMax;
		cartes = new const Carte * [nbMax];
		for (size_t i = 0; i < nbMax; i++)
		{
			cartes[i] = p.cartes[i];
		}
	}

	Plateau& Plateau::operator=(const Plateau& p)
	{
		if (this != &p)
		{
			if (nbMax < p.nb)
			{
				const Carte** newtab = new const Carte * [p.nb];
				nbMax = p.nb;
				const Carte** old = cartes;
				cartes = newtab;
				delete[] old;
			}

			for (int i = 0; i < nb; i++)
			{
				cartes[i] = p.cartes[i];
			}
			nb = p.nb;
		}
		return *this;
	}

	void Plateau::ajouter(const Carte& carte)
	{
		if (nb == nbMax)
		{
			//Agrandir le tableau
			const Carte** newtab = new const Carte* [nbMax + 5];
			nbMax = nbMax + 5;
			for (size_t i = 0; i < nbMax; i++)
			{
				newtab[i] = cartes[i];
			}
			const Carte** old = cartes;
			cartes = newtab;
			delete[] old; //Destruction de l'ancien tableau
		}
		cartes[nb++] = &carte;
	}

	void Plateau::retirer(const Carte& carte)
	{
		size_t i = 0;
		while (i < nbMax && cartes[i] != &carte)
		{
			i++;
		}
		//Si la carte n'est pas sur le plateau
		if (i == nbMax)
		{
			throw SetException("Erreur : la carte n'est pas sur le plateau !");
		}
		else
		{
			cartes[i] = cartes[nb - 1];
			nb--;
		}
	}
	void Plateau::print(ostream& flux)
	{
		flux << "Plateau : " << endl;
		for (size_t i = 0; i < nb; i++)
		{
			flux << *cartes[i];
			if (i % 3 == 0) flux << "\n";
		}
		flux << "\n";
	}
}