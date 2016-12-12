/*************************************************************************
 Catalogue  -  description
 -------------------
 d�but                : 14 nov. 2016
 copyright            : (C) 2016 par dandries
 *************************************************************************/

//---------- R�alisation de la classe <Catalogue> (fichier Catalogue.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Collection.h"

//------------------------------------------------------------- Constantes
unsigned int MAX_LEN=1024;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void Catalogue::Afficher()
{
	if(catalog->GetCardActuelle()==0)
	{
		cout<<"Le catalogue des trajets est vide"<<endl;
	}
	else
	{
		cout<<"Le catalogue des trajets:"<<endl;
		catalog->Afficher();
		cout<<"Fin du Catalogue"<<endl;
    }
} //----- Fin de M�thode

void Catalogue::UiCatalog()
{
    bool bol = true;
    while (bol)
    {
		char* userInput=new char[MAX_LEN];
        cout << "<a> pour affichage, <s> pour ajouer un trajet simple, <c> pour ajouer un trajet compose";
        cout<< " <r> pour rechercher un parcours,<save> pour sauvegarder,<load> pour charger, <bye> pour finir" << endl;
        cin.getline(userInput, MAX_LEN, '\n');
        if (strcmp(userInput, "a") == 0)
        {
            Afficher();
        }else if (strcmp(userInput, "s") == 0)
        {
            Trajet * t;
            t = UiTrajetS();
            catalog->AddTo(t);
        } else if (strcmp(userInput, "c") == 0)
        {
            Trajet * t;
            t=UiTrajetC();
            catalog->AddTo(t);
        } else if(strcmp(userInput, "r") == 0)
        {
            UiRecherche();
        }
        else if (strcmp(userInput,"save"))
        {
		}
		else if (strcmp(userInput,"load"))
		{
		}
        else if (strcmp(userInput, "bye") == 0)
        {
            bol=false;
        } else
        {
            cout << "vous n'avez pas choisi une option valide" << endl;
        }
    
		delete [] userInput;
    }
    
} //----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
/*Catalogue & Catalogue::operator =(const Catalogue & unCatalogue)
// Algorithme :
//
{
} //----- Fin de operator =*/

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue(const Catalogue & unCatalogue)
// Algorithme :
//
		{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)

Catalogue::Catalogue(unsigned int cardMax)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
        catalog=new Collection(cardMax);
} //----- Fin de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
	delete catalog;
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

Trajet* Catalogue::UiTrajetS()
{
    Trajet* t;
    char* pArr = new char[MAX_LEN];
    char* pDep = new char[MAX_LEN];
    char* mTrans = new char[MAX_LEN];
    bool bol;
    bol=true;
    while(bol)
    {
		cout << "pt de depart:" << endl;
		cin.getline(pDep, MAX_LEN, '\n');
		if(StringValide(pDep))
			bol=false;
		else
			cout<< "le point introduit n'est pas valide, veuillez recommencer"<<endl;
    }
    bol=true;
        while(bol)
        {
    		cout << "pt d'arrivee:" << endl;
    		cin.getline(pArr, MAX_LEN, '\n');
    		if(StringValide(pArr))
    			bol=false;
    		else
    			cout<< "le point introduit n'est pas valide, veuillez recommencer"<<endl;
        }
	bol=true;
		while(bol)
		{
			cout << "moyen de transport:" << endl;
			cin.getline(mTrans, MAX_LEN, '\n');
			if(StringValide(pDep))
				bol=false;
			else
				cout<< "le moyen de transport introduit n'est pas valide, veuillez recommencer"<<endl;
		}
    
    t = new TrajetSimple(pDep, pArr, mTrans);
    delete [] pArr;
    delete [] pDep;
    delete [] mTrans;
    return t;
} //----- Fin de M�thode

Trajet* Catalogue::UiTrajetC()
{
    TrajetCompose* t;
    t = new TrajetCompose();
    cout<<"introduisez la premiere partie du trajet"<<endl;
    Trajet * ts;
    ts = UiTrajetS();
    t->AddToTC(ts);
    bool ajoutReussi=false;
    while (ajoutReussi==false)
    {
		cout<<"introduisez la seconde partie du trajet"<<endl;
		Trajet * ts;
		ts = UiTrajetS();
		ajoutReussi=t->AddToTC(ts);
	}
    cout<<"voulez vous introduire encore une partie de trajet y/n"<<endl;
    char* userInput = new char[MAX_LEN];
    cin.getline(userInput, MAX_LEN, '\n');
    while ((strcmp(userInput,"n") != 0))
    {		
        if(strcmp(userInput,"y")==0)
        {
            Trajet * ts;
            ts = UiTrajetS();
            t->AddToTC(ts);
            cout<<"voulez vous introduire une nouvelle partie de trajet? y/n "<<endl;
            cin.getline(userInput, MAX_LEN, '\n');
        }
        else
        {
            cout << "vous n'avez pas choisi une option valide" << endl;
            cout << "<y> pour une nouvelle partie du trajet, <n> pour finir" << endl;
            cin.getline(userInput, MAX_LEN, '\n');
        }
    }
    delete [] userInput;
     return t;
} //----- Fin de M�thode

void Catalogue::UiRecherche()
{
	if (catalog->GetCardActuelle()==0)
		{
			cout<< " catalogue vide, pas de recherche posible"<<endl;
		}
		else
		{
			char* pArr = new char[MAX_LEN];
			char* pDep = new char[MAX_LEN];
			bool bol;
			bol=true;
			while(bol)
			{
				cout << "pt de depart du parcours:" << endl;
				cin.getline(pDep, MAX_LEN, '\n');
				if(StringValide(pDep))
					bol=false;
				else
					cout<< "le point introduit n'est pas valide, veuillez recommencer"<<endl;
			}
			bol=true;
			while(bol)
			{
				cout << "pt d'arrivee du parcours:" << endl;
				cin.getline(pArr, MAX_LEN, '\n');
				if(StringValide(pArr))
					bol=false;
				else
					cout<< "le point introduit n'est pas valide, veuillez recommencer"<<endl;
				}
				CalculerParcoursAvancee(pDep,pArr);
				delete [] pArr;
				delete [] pDep;
		}
}

int Catalogue::UiScenario()
{
	string userInput="";
}

bool Catalogue::StringValide(const char*str)
{
	if(strlen(str)==0)
		return false;
	else
	{
		for(unsigned int i=0;i<strlen(str);i++)
			if(str[i]!=' ')
				return true;
	}
	return false;
} //----- Fin de M�thode

void Catalogue::CalculerParcoursSimple(const char*pDep, const char*pArr) const
{
	unsigned int cardActuelle=catalog->GetCardActuelle();
	Trajet * t;
	int j=0;
	for (unsigned int i=0;i<cardActuelle;i++)
    {
        t=catalog->GetElement(i);
        if(( strcmp(pDep,t->getOrigin()) ==0 )&&( strcmp(pArr,t->getDestination()) == 0 ))
           {
               cout<<(++j)<<" ";
               t->Afficher();
           }
    }
}//----- Fin de M�thode

void Catalogue::CalculerParcoursAvancee(const char* pDep, const char* pArr)
{
    unsigned int cardActuelle=catalog->GetCardActuelle();
	Trajet * t;
	for (unsigned int i=0;i<cardActuelle;i++)
    {
        t=catalog->GetElement(i);
        if ( strcmp( pDep,t->getOrigin() ) ==0)
        {
            unsigned int candidat[cardActuelle];
            recursive(candidat,0,i,t->getDestination(),pArr);
        }
    }
}//----- Fin de M�thode

void Catalogue::recursive(unsigned int liste[],unsigned int cardListe, unsigned int elem, const char* pDep,const char * pArr)
{
    liste[cardListe]=elem;
    cardListe++;
    if (strcmp(pDep,pArr)==0)
    {
        AfficherParcours(liste,cardListe);
    }
    else
    {
        unsigned int cardActuelle=catalog->GetCardActuelle();
        Trajet * t;
        for (unsigned int i=0;i<cardActuelle;i++)
        {
            t=catalog->GetElement(i);
            bool notIn=true;
            for (unsigned int j=0;j<cardListe;j++)
			{
				if (i==liste[j])
				{
					notIn=false;
					break;
				}
			}
            if( (notIn)&&( strcmp( pDep, t->getOrigin() )== 0 ) )
            {
                recursive(liste,cardListe,i,t->getDestination(),pArr);
            }
        }
    }
}//----- Fin de M�thode

void Catalogue::AfficherParcours(unsigned int liste[],unsigned int cardListe)
{
	cout<<"debut parcours"<<endl;
	for (unsigned int j=0;j<cardListe;j++)
	{
		catalog->GetElement(liste[j])->Afficher();
	}
	cout<<"fin parcours"<<endl;
}
