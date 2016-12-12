/*************************************************************************
 TrajetCompose  -  description
 -------------------
 d�but                : 16 Nov 2016
 copyright            : (C) 2016 par Dannemp
 *************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ------
#if ! defined ( TRAJETCOMPOSE_H_ )
#define TRAJETCOMPOSE_H_

//--------------------------------------------------- Interfaces utilis�es
//#include "Trajet.h"
//#include "TrajetSimple.h"
#include "Collection.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <TrajetCompose>
// contient en atribut une collection des trajets simples(mais peut aussi contenir des trajets composes)
// qui represente un trajet compose
//------------------------------------------------------------------------

class TrajetCompose: public Trajet {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

	void Afficher();
	// Mode d'emploi :
	// affiche un trajet compose comme une liste des trajets simples
	// Contrat :
	//

	bool PossibleDAjouter(Trajet* tSimple);
	// Mode d'emploi :
	// parametre Trajet* tSimple-un trajet a verifier
	// renvoie true si le trajet a ajouter a le meme point de depart que le point d'arrivee du dernier trajet
	// ou le trajet compose ne contient encore aucun trajet simple
	// Contrat :
	//

	char* getDestination();
	// Mode d'emploi :
	// retourne la destination d'un trajet compose
	// Contrat :
	//

	char* getOrigin();
	// Mode d'emploi :
	// retourne l'origine d'un trajet compose
	// Contrat :
	//

	bool AddToTC(Trajet* tSimple);
	// Mode d'emploi :
	// parametre Trajet* tSimple-le trajet a ajouter
	// ajoute un trajet simple au trajet compose
	// Contrat :
	//



//------------------------------------------------- Surcharge d'op�rateurs
	TrajetCompose & operator =(const TrajetCompose & unTrajetCompose);
	// Mode d'emploi :
	//
	// Contrat :
	//

	/*bool operator ==(const Trajet & unTrajetCompose);
	// Mode d'emploi :
	//
	// Contrat :
	//*/

//-------------------------------------------- Constructeurs - destructeur
	TrajetCompose(const TrajetCompose & unTrajetCompose);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	TrajetCompose();
	// Mode d'emploi :
	// constructeur par default de TrajetCompose, cree une nouvelle collection avec la taille 1
	// Contrat :
	//

	virtual ~TrajetCompose();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
Collection* collectionTrajet;
};

//--------------------------- Autres d�finitions d�pendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H_

