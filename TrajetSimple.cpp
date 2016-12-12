/*************************************************************************
 TrajetSimple  -  description
 -------------------
 d�but                : 14 nov. 2016
 copyright            : (C) 2016 par dandries
 *************************************************************************/

//---------- R�alisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void TrajetSimple::Afficher()
{
	cout<<"TS de ["<<pDepart<<"] à ["<<pArrivee<<"] avec ["<<moyTransport<<"]"<<endl;
} //----- Fin de M�thode

char * TrajetSimple::getOrigin()
{
    return pDepart;
} //----- Fin de M�thode

char * TrajetSimple::getDestination()
{
    return pArrivee;
} //----- Fin de M�thode



//------------------------------------------------- Surcharge d'op�rateurs
/*TrajetSimple & TrajetSimple::operator =(const TrajetSimple & unTrajetSimple)
// Algorithme :
//
		{
} //----- Fin de operator =*/

/*bool TrajetSimple::operator ==(const Trajet & unTrajetSimple)
// Algorithme :
//
{
} //----- Fin de operator*/

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const TrajetSimple & unTrajetSimple)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif	
} //----- Fin de TrajetSimple (constructeur de copie)

TrajetSimple::TrajetSimple(const char * pDep,const char * pArr,const char * moy)
{
#ifdef MAP
	cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
	pDepart=new char[strlen(pDep)+1];
	pArrivee=new char[strlen(pArr)+1];
	moyTransport=new char[strlen(moy)+1];
	strcpy(pDepart,pDep);
	strcpy(pArrivee,pArr);
	strcpy(moyTransport,moy);

} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete [] pDepart;
    delete [] pArrivee;
	delete [] moyTransport;
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

