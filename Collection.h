/*************************************************************************
                           Collection -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Collection> (fichier Collection.h) ------
#if ! defined ( Collection_H_ )
#define Collection_H_

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes
const int CARD_MAX=5;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Collection>
// contient en atribut un tableau dinamique des trajets avec une cardinalite actuelle et une maximale
//
//------------------------------------------------------------------------

class Collection
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int AddTo(Trajet *t);
    // Mode d'emploi :
    // parametre Trajet *t-un trajet a ajouter
    // la methode ajoute un trajet a la collection
    // Contrat :
    //

    void Afficher();
    // Mode d'emploi :
    // la methode affiche la totalite des trajets contenus dans la collection
    // Contrat :
    //
    
    void AfficherTC();

    unsigned int GetCardActuelle();
    // Mode d'emploi :
    // renvoie le nombre des trajets contenus dans la collection
    // Contrat :
    //

    Trajet* GetElement(unsigned int nr);
    // Mode d'emploi :
    // parametre unsigned int nr-le nombre d'ordre dans le tableau element
    // la methode renvoie le trajet contenu dans la case nr
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Collection& operator = ( const Collection& unCollection );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Collection ( const Collection & unCollection );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Collection (unsigned int cardMax = CARD_MAX  );
    // Mode d'emploi :
    // parametre unsigned int cardMax- la cardinalite maximale
    // constructeur de collection avec une cardinalite maximale
    // Contrat :
    //

    virtual ~Collection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    unsigned int AjusterCollection(int delta);
    // Mode d'emploi :
    // parametre int delta-difference de la cardinalite maximale
    // augmente ou reduit de delta la cardinalite maximale de la collection
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés
    unsigned int cardMaximale;
    unsigned int cardActuelle;
    Trajet ** element;
};

//--------------------------- Autres définitions dépendantes de <Collection>

#endif // Collection_H_

