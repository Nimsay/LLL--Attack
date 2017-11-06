/* Author : AIT MAKSENE Yasmin
   University : Université de Bretagne Occidentale UBO
   Year : 2016/ 2017 
   Work: LLL algorithm Implementation using C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "LLL.h"

using namespace std;

int main()
{

	LLL algo1;
	long  _tableau[n];
	int C=10;

	//Un exemple de suite super croissante comme celle généré par un système Merkel-Hellman
	//Tel que le dernier élement est la somme des élements de la liste 
	long t[9]= {1890, 4500, 7335, 16110, 14233, 11244, 6886, 12917,22630};
	cout << endl;
	cout << "\t=====Cryptanalyse du cryptosysteme de Hellman-Merckle avec LLL=====" << endl;
	cout << " " <<endl;




	//La suite super croissante 
	cout << "La suite super croissante est : ";
	for( int i =0;i<8; i++)
	 {
	    cout<< t[i];
	    cout <<",";
	 }
	cout << endl;

	// La message envoyé après cryptage avec le système Merkel-Helman
	cout << "Le message à envoyer est S ="<< t[8];
	cout << endl; 

	//Le coefficient C
	cout << "Le coefficient utilisé est C =" << C ;
	cout << endl;
	cout << endl;

	//La matrice associé au réseau
	algo1.matriceAssocieAuReseau(t);
	algo1.AffichageMatrice();
	cout << endl ;


	//La matrice après application de LLL
	//Application de gram schmidth
	algo1.gramSchmidt();

	//Application de LLL
	algo1.LLLAlgorithm();

	//Affichage de la matrice finale
	algo1.AffichageMatriceApresApplicationDeLLL();
	cout << endl;

	//la suite (y1...yn) qui est une solution dans la matrice finale
	cout << "Le vecteur solution est:\t ";
        algo1.VecteurSolution();
        cout <<endl;
        cout << "Car il respectent les conditions suivantes :";
        cout << endl;
        cout << "|Yi| <=1  && Yi+1 = 0 && Somme des Yi*t[i] = le message envoyé, ici 22630";
        cout << endl;
        cout << endl;
        cout << "le vecteur sélectionné est alors la lettre F en binaire ";
        cout << endl;
        cout << "Et c'est cette lettre là qui été cryptée avec le cryptosystème Merkel-Helman";
        cout << endl;
        cout << endl;

	return 0;

	

}
