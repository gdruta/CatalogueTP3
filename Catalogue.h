/*************************************************************************
 Catalogue  -  description
 -------------------
 d�but                : 14 nov. 2016
 copyright            : (C) 2016 par dandries
 *************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ------
#if ! defined ( CATALOGUE_H_ )
#define CATALOGUE_H_

//--------------------------------------------------- Interfaces utilis�es
#include "TrajetSimple.h"
#include "TrajetCompose.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// R�le de la classe <Catalogue>
// contient en atribut une Collection des trajets(simples et composes)
// inclut les methodes de calcul des parcours
//
//------------------------------------------------------------------------

class Catalogue {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

	void UiCatalog();
	// Mode d'emploi :
	// permet de communiquer avec l'utilisateur en lui demandant la saisie des trajets
	// Contrat :
	//

    void Afficher();
    // Mode d'emploi :
	// affiche la totalite des objets dans le catalogue
	// Contrat :
	//

//------------------------------------------------- Surcharge d'op�rateurs
	Catalogue & operator =(const Catalogue & unCatalogue);
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	Catalogue(const Catalogue & unCatalogue);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Catalogue(unsigned int cardMax = CARD_MAX );
	// Mode d'emploi :
	// constructeur qui cree une nouvelle collection de cardinalite maximale egale a cardMax
	// Contrat :
	//

	virtual ~Catalogue();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

    Trajet* UiTrajetS();
	// Mode d'emploi :
	// permet la saisie(user input) dans la console d'un trajet simple
	// Contrat :
	//

	Trajet* UiTrajetC();
	// Mode d'emploi :
	// permet la saisie(user input) dans la console d'un trajet compose
	// Contrat :
	//
	
	void UiRecherche();
	// Mode d'emploi :
	// permet la saisie(user input) dans la console d'une recherche
	// Contrat :
	//
	
	int UiScenario();
	// Mode d'emploi :
	// permet la saisie(user input) dans la console d'un scenario de save ou load
	// Contrat :
	//
	
	string UiFichier();
	// Mode d'emploi :
	// permet la saisie(user input) dans la console du scenario 1 de save ou load
	// Contrat :
	//
	
	void Save(string filename);
	// Mode d'emploi :
	// permet la sauvegarde1 dans un fichier 
	// Contrat :
	//
	
	bool StringValide(const char * str);
	// Mode d'emploi :
	// parametre char *str-un string a verifier
	// renvoie true si le string contient au moins un charactere different de l'espace
	// Contrat :
	//

	void CalculerParcoursSimple(const char*pDep, const char*pArr) const;
	// Mode d'emploi :
	// parametre char*pDep-le point de depart, char*pArr-point d'arrivee
	// la methode calcule un parcours simple(utilisant un seul trajet)
	// Contrat :
	//

	void CalculerParcoursAvancee(const char* pDep, const char* pArr);
	// Mode d'emploi :
	// parametre char*pDep-le point de depart, char*pArr-point d'arrivee
	// la methode calcule un parcours avance(utilisant un seul ou plusieurs trajets)
	// Contrat :
	//

	void recursive(unsigned int liste[],unsigned int cardListe, unsigned int elem, const char* pDep,const char * pArr);
	// Mode d'emploi :
	// parametre Collection liste-une collection des trajets, Trajet*trajet-un trajet
	// parametre char*pDep-le point de depart, char*pArr-point d'arrivee
	// une methode recoursive qui ajoute a la liste le trajet passe en parametre,
	// et essaye de trouver un trajet qui peut suivre celui ajoute dans le parcours
	// Contrat :
	//
	
	void AfficherParcours(unsigned int liste [],unsigned int cardListe);

//----------------------------------------------------- Attributs prot�g�s
	Collection * catalog;
};

//--------------------------- Autres d�finitions d�pendantes de <Catalogue>

#endif // CATALOGUE_H_

