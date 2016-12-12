/*************************************************************************
 TrajetSimple  -  description
 -------------------
 d�but                : 14 nov. 2016
 copyright            : (C) 2016 par dandries
 *************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ------
#if ! defined ( TRAJETSIMPLE_H_ )
#define TRAJETSIMPLE_H_

//--------------------------------------------------- Interfaces utilis�es
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <TrajetSimple>
// contient en atribut un point de depart, un point d'arrivee et un moyen de transport
// tous ensemble constituant un trajet simple
//------------------------------------------------------------------------

class TrajetSimple: public Trajet {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

	void Afficher();
	// Mode d'emploi :
	// affiche un trajet simple
	// Contrat :
	//

	char * getOrigin();
	// Mode d'emploi :
	// retourne l'origine d'un trajet simple
	// Contrat :
	//

    char * getDestination();
	// Mode d'emploi :
	// retourne la destination d'un trajet simple
	// Contrat :
	//

//------------------------------------------------- Surcharge d'op�rateurs
	TrajetSimple & operator =(const TrajetSimple & unTrajetSimple);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	TrajetSimple(const TrajetSimple & unTrajetSimple);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	TrajetSimple(const char * pDep,const char * pArr,const char * moy);
	// Mode d'emploi :
	// le constructeur d´un trajet simple avec un point de depart, un point d'arrivee et un moyen de transport
	// Contrat :
	//

	virtual ~TrajetSimple();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
    char * pDepart;
    char * pArrivee;
char * moyTransport;
};

//--------------------------- Autres d�finitions d�pendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H_

