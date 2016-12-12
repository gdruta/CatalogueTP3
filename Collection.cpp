/*************************************************************************
                           Collection  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Collection> (fichier Collection.h) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//#define MAP

//------------------------------------------------------ Include personnel
#include "Collection.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int Collection::AddTo(Trajet *t)
{
    if (cardMaximale == cardActuelle)
    {
        AjusterCollection(1);
    }
    element[cardActuelle] = t;
    cardActuelle++;
    return 1;
} //----- Fin de M�thode


void Collection::Afficher()
{
	for(unsigned int j=0;j<cardActuelle;j++)
	{
		cout<<"trajet "<<j<<" :";
		element[j]->Afficher();
	}
} //----- Fin de M�thode

void Collection::AfficherTC()
{
	for(unsigned int j=0;j<cardActuelle;j++)
	{
		cout<<"          trajet "<<j<<" :";
		element[j]->Afficher();
	}
}

unsigned int Collection::GetCardActuelle()
{
	return cardActuelle;
} //----- Fin de M�thode

Trajet* Collection::GetElement(unsigned int nr)
{
	return element[nr];
} //----- Fin de M�thode



//------------------------------------------------- Surcharge d'opérateurs
/*Collection & Collection::operator = ( const Collection & unCollection )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
Collection::Collection ( const Collection & unCollection )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Collection>" << endl;
#endif
cardActuelle=unCollection.cardActuelle;
cardMaximale=unCollection.cardMaximale;
element=new Trajet*[cardMaximale];
for (unsigned int i=0;i<cardActuelle;i++)
{
    element[i]=unCollection.element[i];
}

} //----- Fin de Collection (constructeur de copie)

Collection::Collection (unsigned int cardMax):cardMaximale(cardMax),cardActuelle(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Collection>" << endl;
#endif
    element=new Trajet*[cardMaximale];
} //----- Fin de Collection


Collection::~Collection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Collection>" << endl;
#endif
	for (unsigned int i=0; i<cardActuelle;i++)
	{
		delete element[i];
	}
    delete [] element;
} //----- Fin de ~Collection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
unsigned int Collection::AjusterCollection( int delta)
{
	if (delta>0)
	{
		cardMaximale=cardMaximale+delta;
	}
	if (delta<0)
	{
		unsigned int k;
		if ((cardMaximale+delta)>=0)
		{
			k=cardMaximale+delta;
		}
		else
		{
			k=0;
		}
		if ((cardActuelle<k))
		{
			cardMaximale=k;
		}
		else
		{
			cardMaximale=cardActuelle;
		}
	}
	if (delta!=0)
	{
		Trajet ** t;
		t=new Trajet*[cardMaximale];
		for (unsigned int i=0;i<cardActuelle;i++)
		{
			t[i]=element[i];
		}
		delete [] element;
		element=t;
	}

	return cardMaximale;
} //----- Fin de M�thode

