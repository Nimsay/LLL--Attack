/* Author : AIT MAKSENE Yasmin
   University : Université de Bretagne Occidentale UBO
   Year : 2016/ 2017 
   Work : LLL algorithm Implementation using C++
*/

                   // Fichier genere avec ./a.out LLL
#ifndef _LLL_H_
#define _LLL_H_


#include <iostream>
#define n 9
#define m 28


using namespace std;

class LLL
{
   friend ostream& operator<<(ostream& os, const LLL& aL);

 public :

   // Allocateurs/Desallocateurs

            LLL( /* ### */ );
            LLL(const LLL& aL);
            LLL& operator=(const LLL& aL);
	    void matriceAssocieAuReseau(long tab[]);
	    void AffichageMatrice();
            void AffichageMatriceApresApplicationDeLLL();
	    void AffichageTableau(long tab[n]);
	    void AffichageTableau2();
	    void VecteurSolution();
	    long  ProduitScalaireDeuxVecteurs(long vec1[n],long vec2[n]);
            void  gramSchmidt();
            long double func (long double a[n],long double b[n]);
            long double normalise9d(long double a[n]);
            void LLLAlgorithm();

   virtual ~LLL(void);

   // Comparaisons

   friend  bool operator==(const LLL& aL1, const LLL& aL2);
   friend  bool operator!=(const LLL& aL1, const LLL& aL2);

   // Inspecteurs/modificateurs

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
   virtual bool isEqualTo(const LLL& aL) const;

 protected :

             // ###

 private :

            long _tableau[n];
            long _tableau2[n];
            long tab[n];
            long matrice[n][n];
	    long matriceAbs[n][n];
            long double matrice2[n][n];
	    long vec[n];   
            long vec2[n];
            long double Mu[n+2][n+2];
            long double u1[n],u2[n],u3[n],u4[n],u5[n],u6[n],u7[n],u8[n],u9[n];
	    long double v1[n],v2[n],v3[n],v4[n],v5[n],v6[n],v7[n],v8[n],v9[n],vp[n];
            long double vCarre[n+2];
            

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const LLL& aL);
   void _destroy(void);
};

#endif // _LLL_H_
