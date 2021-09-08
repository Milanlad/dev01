#include <iostream>
#include <stdio.h>
#include <string.h>
/*
Milan Jérémy 07/09/2021
*/

/*
Lire les prénoms et les notes des élèves de la classe, tant que le prénom saisi est différent de: 
« XAEA-XII ». Vérifier que la note saisie soit comprise entre 0 et 20.
Afficher ensuite: 
la moyenne de la classe
la meilleure note de la classe et le prénom correspondant.
la moins bonne note de la classe et le prénom correspondant.
*/


//Déclaration des variables
char error_prenom[99] = "XAEA-XII";
char prenom[99] = "";
char best_prenom[99]= "";
char worst_prenom[99] = "";
int errorp,errorn,i,error_i =0;
float moyenne = 0;
float worst_note = 21;
float note,best_note,nb_note,nb_student = 0;
	
int main(int argc, char** argv) 
{
	
while (i!=2)
{
do
	{
	//Demande un prenom et une note à l'utilisateur
	printf("\n");
	printf("\nSaisir un prenom : ");
	scanf("%s",&prenom);
	printf("Saisir une note : ");
	scanf("%f",&note);
	i=0;
	error_i=0;
	
	//Ferme le programme quand le prenom "END" est saisie
	if (prenom[0] == 'E' && prenom[1] == 'N' && prenom[2] == 'D')
		{
		return 0;
		}
	
	//Vérifie si le prenom est corect si non alors on ferme le programme
	while (prenom[i]!= '\0')
		{
		if (prenom[i]== error_prenom[i])
			{
			error_i++;
			}
		else
			{
			error_i--;
			}
		i++;
		}
	if (error_i == 8)
		{
		printf("\nC'est pas le bon prenom ");
		errorp = 1;
		return 0;
		}
	else
		{
		errorp=0;
		
		//Vérifie si la note est corect si non alors on redemande un prenom et une note
		if (note >20 || note <0)
			{
			printf("\nC'est pas une note corect ");
			errorn = 1;
			}
		else
			{
			errorn = 0;
			}
		}	
	}
while (errorn == 1 || errorp == 1);
i=0;

// Vérifie si la nouvelle note est encore meilleur que la meilleur note si oui alors on stock le prenom et la note comme nouvelle meilleur note 
if(note > best_note)
	{
	memset(best_prenom, ' ', 99);
	best_note = note;
	while(prenom[i] != '\0')
		{
		best_prenom[i] = prenom[i];
		i++;
		}
	printf("\nNouvelle meilleur note de :");
	printf(" %.2f obtenue par : ",best_note);
	printf("%s",best_prenom);
	}
i=0;

// Vérifie si la nouvelle note est encore moin bonne que la pire note si oui alors on stock le prenom et la note comme nouvelle pire note 
if(note < worst_note)
	{
	memset(worst_prenom, ' ', 99);
	worst_note = note;
	while(prenom[i] != '\0')
		{
		worst_prenom[i] = prenom[i];	
		i++;
		}
	printf("\nNouvelle pire note de :");
	printf(" %.2f obtenue par : ",worst_note);
	printf("%s",worst_prenom);
	}
i=0;

//Effectue la moyenne de toute les notes et fait le print de : la moyenne , La pire note et son détenteur, La meilleur note et son détenteur
nb_note = nb_note + note;
nb_student++;
moyenne = nb_note / nb_student;
printf("\nLa moyenne de la classe est de : ");
printf("%.2f",moyenne);
printf("\n\nLa pire note est de :");
printf(" %.2f obtenue par : ",worst_note);
printf("%s",worst_prenom);
printf("\nLa meilleur note est de :");
printf(" %.2f obtenue par : ",best_note);
printf("%s",best_prenom);
}
}
