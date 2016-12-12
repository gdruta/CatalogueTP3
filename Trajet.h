/*************************************************************************
                           Trajet  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilis�es
#include <cstring>
#include <string>
//------------------------------------------------------------- Constantes
//
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Trajet>
// classe abstraite qui generalise la notion de trajet
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

    virtual void Afficher()=0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual char * getOrigin()=0;
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual char * getDestination()=0;
	// Mode d'emploi :
    //
    // Contrat :
    //
//------------------------------------------------- Surcharge d'op�rateurs
    Trajet & operator = ( const Trajet & unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Trajet ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s


};

//--------------------------- Autres d�finitions d�pendantes de Trajet

#endif // TRAJET_H

