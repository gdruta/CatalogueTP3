/*************************************************************************
 TrajetCompose  -  description
 -------------------
 d�but                : 16 Nov 2016
 copyright            : (C) 2016 par Dannemp
 *************************************************************************/

//---------- R�alisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void TrajetCompose::Afficher()
{
	cout<<"TC:"<<endl;
	TrajetCompose::collectionTrajet->AfficherTC();
	cout<<"fin TC"<<endl;
} //----- Fin de M�thode

bool TrajetCompose::PossibleDAjouter(Trajet* tSimple)
{
	if(collectionTrajet->GetCardActuelle()==0)
	{
		return true;
	}
	else
	{
		char* last=getDestination();
		char* pDepTS=tSimple->getOrigin();
		if(strcmp(last,pDepTS)==0)
		{
			return true;
		}
	}
	return false;
} //----- Fin de M�thode

bool TrajetCompose::AddToTC(Trajet* tSimple)
{
	if (PossibleDAjouter(tSimple))
	{
		collectionTrajet->AddTo(tSimple);
		return true;
	}
        else
        {
            cout<<"ce trajet ne suit pas le dernier! il n'a pas ete ajoute "<<endl;
            delete tSimple;
            return false;
        }
} //----- Fin de M�thode

char* TrajetCompose::getDestination()
{
	unsigned int last=collectionTrajet->GetCardActuelle();
		
	return collectionTrajet->GetElement(last-1)->getDestination();
} //----- Fin de M�thode

char* TrajetCompose::getOrigin()
{
	
	return collectionTrajet->GetElement(0)->getOrigin();
	
} //----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
/*TrajetCompose & TrajetCompose::operator =(const TrajetCompose & unTrajetCompose)
// Algorithme :
//
		{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(const TrajetCompose & unTrajetCompose)
// Algorithme :
//
		{
#ifdef MAP
	cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose (constructeur de copie)

TrajetCompose::TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
	collectionTrajet=new Collection(1);
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
	delete collectionTrajet;
} //----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

