/*
 * test1.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: dandries
 */
using namespace std;

#include "Collection.h"
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <iostream>
#include <string>
//
int main()
{
	Catalogue c=Catalogue (10);

    c.UiCatalog();
	c.Afficher();


}



