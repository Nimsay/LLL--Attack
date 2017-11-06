/* Author : AIT MAKSENE Yasmin
   University : Université de Bretagne Occidentale UBO
   Year : 2016/ 2017 
   Work : LLL algorithm Implementation using C++
*/

// Fichier genere avec ./a.out LLL
#include "LLL.h"
#include <iostream>
#include <math.h> 
/* pour l aleatoire */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
/* pour le tri */
#include <algorithm>
#include <iostream>
#include <fstream>

//constucteur par défaut
LLL::LLL( /* ### */ )
 {
 }


//Matrice associé au réseau
void LLL:: matriceAssocieAuReseau( long tab[])
{


	 int taille= n;
	 int C=10;
	 long _tableau2[n];

		for(int k=0;k<=n-2;k++)
		{

	  	 for(int j=0;j<=n-2;j++)
		 {

	      		if ( k==j)
			 {
			 	matrice[k][j]=1;		
			
		         }else 
			 {
				matrice[k][j]=0;
			 }

	   	  }

		 }


		for(int i=0;i<=n-1;i++)
		{
	     
		       _tableau2[i]= tab[i]*C;

		}


		for( int l=0;l<=n-2;l++)
		{
	  	
			matrice[l][n-1]= _tableau2[l];
		}


		for( int l=0;l<=n-2;l++)
		{
	  	
			matrice[n-1][l]= 0;
		}

	 	matrice[n-1][n-1]= _tableau2[n-1];
 
}


//Affichage matrice associée au réseau
void LLL:: AffichageMatrice()
{
 
  cout<< "La matrice associée au réseau est : " << endl;

  for(int i=0;i<=n-1;i++)
  {

   	for(int j=0;j<=n-1;j++)
	{

  		cout<< matrice[i][j] << "|";
	}
 		
	cout << endl;

   }
}
void LLL:: VecteurSolution()
{

  for(int j=0;j<n-1;j++)
  {
    cout<< matrice[0][j];
   
  }
   cout << endl;
}


//Affichage de la matrice après application de l'algorithme LLL
void LLL:: AffichageMatriceApresApplicationDeLLL()
{
 
	  cout<< "la matrice après application de LLL est : " << endl;

	  for(int i=0;i<=n-1;i++)
	  {

	    for(int j=0;j<=n-1;j++)
	    {

	 	 cout<< matrice[i][j] << "|";
	    }

	    cout << endl;

	   }

}

	


//Affichage clé publique
void LLL:: AffichageTableau2()
{
 
	  cout<< "le tableau contenant la clé publique est : " << endl;

	  for(int i=0;i<=n-1;i++)
	  {
	   
	       cout<<  vec[i]<< endl;
	  }


}





void LLL :: gramSchmidt()
{

int i,j;

for(i=0;i<n;i++)
for(j=0;j<n;j++){


		matrice2[i][j]=0;
                switch (i){


			    case 0: 
                            u1[j]=matrice[i][j];
                            break;

			    case 1: 
                            u2[j]=matrice[i][j];
                            break;
                            
                            case 2: 
                            u3[j]=matrice[i][j];
                            break;

                            case 3: 
                            u4[j]=matrice[i][j];
                            break;
       
                            case 4: 
                            u5[j]=matrice[i][j];
                            break;

                            case 5: 
                            u6[j]=matrice[i][j];
                            break;

                            case 6: 
                            u7[j]=matrice[i][j];
                            break;
                           
                            case 7: 
                            u8[j]=matrice[i][j];
                            break;

                            case 8: 
                            u9[j]=matrice[i][j];
                            break;
                    

			}
	
		}

//Solve v
for (i=0;i<=n;i++)
    vCarre[i]=0;
for(i=0;i<n;i++){

		v1[i]= u1[i];
                vCarre[1]+=(v1[i]*v1[i]);
	}

Mu[2][1]=func(u2,v1);
for(i=0;i<n;i++){

		v2[i]= u2[i]-Mu[2][1]*v1[i];
                vCarre[2]+=(v2[i]*v2[i]);

	}

Mu[3][1]=func(u3,v1);
Mu[3][2]=func(u3,v2);
for(i=0;i<n;i++){

		v3[i]= u3[i]-Mu[3][1]*v1[i]-Mu[3][2]*v2[i];
                vCarre[3]+=(v3[i]*v3[i]);

              

	}
	
Mu[4][1]=func(u4,v1);
Mu[4][2]=func(u4,v2);
Mu[4][3]=func(u4,v3);
for(int i=0;i<n;i++){

		v4[i]= u4[i]-Mu[4][1]*v1[i]-Mu[4][2]*v2[i]-Mu[4][3]*v3[i];
                 vCarre[4]+=(v4[i]*v4[i]);


	}
Mu[5][1]=func(u5,v1);
                 Mu[5][2]=func(u5,v2);
                 Mu[5][3]=func(u5,v3);  
                 Mu[5][4]=func(u5,v4);
for(int i=0;i<n;i++){

		v5[i]= u5[i]-Mu[5][1]*v1[i]-Mu[5][2]*v2[i]-Mu[5][3]*v3[i]-Mu[5][4]*v4[i];
                vCarre[5]+=(v5[i]*v5[i]);

           
               

	}

Mu[6][1]=func(u6,v1);
                 Mu[6][2]=func(u6,v2);
                 Mu[6][3]=func(u6,v3);  
                 Mu[6][4]=func(u6,v4);
                 Mu[6][5]=func(u6,v5);

for(int i=0;i<n;i++){

		v6[i]= u6[i]-Mu[6][1]*v1[i]-Mu[6][2]*v2[i]-Mu[6][3]*v3[i]-Mu[6][4]*v4[i]-Mu[6][5]*v5[i];
		 vCarre[6]+=(v6[i]*v6[i]);

          
	}

Mu[7][1]=func(u7,v1);
                 Mu[7][2]=func(u7,v2);
                 Mu[7][3]=func(u7,v3);  
                 Mu[7][4]=func(u7,v4);
                 Mu[7][5]=func(u7,v5);
                 Mu[7][6]=func(u7,v6);


for(int i=0;i<n;i++){

		v7[i]= u7[i]-Mu[7][1]*v1[i]-Mu[7][2]*v2[i]-Mu[7][3]*v3[i]-Mu[7][4]*v4[i]-Mu[7][5]*v5[i]-Mu[7][6]*v6[i];
                vCarre[7]+=(v7[i]*v7[i]); 

           
	}

Mu[8][1]=func(u8,v1);
                 Mu[8][2]=func(u8,v2);
                 Mu[8][3]=func(u8,v3);  
                 Mu[8][4]=func(u8,v4);
                 Mu[8][5]=func(u8,v5);
                 Mu[8][6]=func(u8,v6);
                 Mu[8][7]=func(u8,v7);
for(int i=0;i<n;i++){

		v8[i]= u8[i]-Mu[8][1]*v1[i]-Mu[8][2]*v2[i]-Mu[8][3]*v3[i]-Mu[8][4]*v4[i]-Mu[8][5]*v5[i]-Mu[8][6]*v6[i]-Mu[8][7]*v7[i];
                vCarre[8]+=(v8[i]*v8[i]);

        
	}

Mu[9][1]=func(u9,v1);
                 Mu[9][2]=func(u9,v2);
                 Mu[9][3]=func(u9,v3);  
                 Mu[9][4]=func(u9,v4);
                 Mu[9][5]=func(u9,v5);
                 Mu[9][6]=func(u9,v6);
                 Mu[9][7]=func(u9,v7);
                 Mu[9][8]=func(u9,v8);
for(int i=0;i<n;i++){

		v9[i]= u9[i]-Mu[9][1]*v1[i]-Mu[9][2]*v2[i]-Mu[9][3]*v3[i]-Mu[9][4]*v4[i]-Mu[9][5]*v5[i]-Mu[9][6]*v6[i]-Mu[9][7]*v7[i]-Mu[9][8]*v8[i];
		vCarre[9]+=(v9[i]*v9[i]);

               
	}

for(int i=0;i<n;i++){

	            matrice2[0][i]= v1[i];



	            matrice2[1][i]= v2[i];



	            matrice2[2][i]= v3[i];



	            matrice2[3][i]= v4[i];



	            matrice2[4][i]= v5[i];



	            matrice2[5][i]= v6[i];


	            matrice2[6][i]= v7[i];


	            matrice2[7][i]= v8[i];



	            matrice2[8][i]= v9[i];

		    }

}


long double LLL:: normalise9d(long double a[n])
{


	long double normal =0.0;
        for(int i=0;i<n;i++)
	{
        normal += a[i]*a[i]; 
	}

        normal = sqrt(normal);
        return normal;


}

long double LLL:: func (long double a[n],long double b[n]){


	long double answ=0.0;
        long double norme= normalise9d(b);
        long double vecProduct =0.0;
	
for(int i =0;i<n;i++)



		      vecProduct += a[i]*b[i];
                      answ= vecProduct/(norme*norme);
    
                      return answ;
	

}

long double round(long double value) 
{

	return floor(value+0.5);
}


void LLL::LLLAlgorithm()
{

int k=2;
int j;
float sigma=0.75 ;
long double temp;



while(k<=n){

	for(j=k-1;j>=1;j--)
	{
                        
                       
				 if (fabs(Mu[k][j])>0.5)
				{
                                       
					//cout << " sup à 1/2" << endl;
					for(int i=0;i<n;i++)
					{
					   
                                               matrice[k-1][i]=matrice[k-1][i]- round(Mu[k][j])* matrice[j-1][i];

					}

      					gramSchmidt();      
      				}

	}


	 	          
         if (vCarre[k] >= (sigma-(Mu[k][k-1]*Mu[k][k-1]))*vCarre[k-1])
	 {
	 	k++;
         }else 
	 {
            
            for(int i=0;i<n;i++)
	    {
                   
		      
                       temp=matrice[k-1][i];
                       matrice[k-1][i]=matrice[k-2][i];
                       matrice[k-2][i]=temp;

            }
         

           gramSchmidt();
           
           
           if(k-1>2)
           k=k-1;
           else k=2;

	 }
         

    }



}




long LLL :: ProduitScalaireDeuxVecteurs(long vec1[n],long vec2[n])
{
	long result=0;

	for(int i=0;i<=n-1;i++)
	{

		    result+= vec1[i]*vec2[i];

	}
	return result;	

}

//--
LLL::LLL(const LLL& aL)
{
 _copy(aL);
}

//--
LLL& LLL::operator=(const LLL& aL)
{
 if (this != &aL)
 {
  _destroy();
  _copy(aL);
 }
 return *this;
}

//--
LLL::~LLL(void)
{
 _destroy();
}

//--
bool operator==(const LLL& aL1, const LLL& aL2)
{
 return aL1.isEqualTo(aL2);
}

//--
bool operator!=(const LLL& aL1, const LLL& aL2)
{
 return !(aL1==aL2);
}

//--
ostream& operator<<(ostream& os, const LLL& aL)
{
 aL.display(os);
 return os;
}

//--
void LLL::display(ostream& os) const
{
 (void)os; // Pour eviter un warning si pas utilise

 // ### : Affichage des attributs de la classe LLL
 // Exemple : os << _at;
}

//--
bool LLL::isEqualTo(const LLL& aL) const
{
 (void)aL; // Pour eviter un warning si pas utilise

 // ### : Test des attributs de la classe LLL
 // Exemple : if (_at != aL._at) return false;
 return true;
}

//--
void LLL::_copy(const LLL& aL)
{
 (void)aL; // Pour eviter un warning si pas utilise

 // ### : Affectation des attributs de la classe LLL
 // Exemple : _at = aL._at;
}

//--
void LLL::_destroy(void)
{
 // ### : Destruction des attributs de la classe LLL
 // Exemple : delete _at;
}

