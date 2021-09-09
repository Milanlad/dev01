#include <iostream>
#include <stdio.h>

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


//Demande un prenom et une note à l'utilisateur
void name_ask ()
{
	printf("\n");
	printf("\nSaisir un prenom : ");
	scanf("%s",&prenom);
	printf("Saisir une note : ");
	scanf("%f",&note);
	i=0;
	error_i=0;
}


// Vérifie si la nouvelle note est encore meilleur que la meilleur note si oui alors on stock le prenom et la note comme nouvelle meilleur note 
void lower_check ()
{
if(note < worst_note)
	{
	worst_note = note;
	while(i != 98)
		{
		worst_prenom[i] = prenom[i];	
		i++;
		}
	printf("\n\nNouvelle pire note de :");
	printf(" %.2f obtenue par : ",worst_note);
	printf("%s",worst_prenom);
	}
i=0;
}


// Vérifie si la nouvelle note est encore moin bonne que la pire note si oui alors on stock le prenom et la note comme nouvelle pire note 
void higher_check()
{
if(note > best_note)
	{
	best_note = note;
	while(i != 98)
		{
		best_prenom[i] = prenom[i];	
		i++;
		}
	printf("\n\nNouvelle meilleur note de :");
	printf(" %.2f obtenue par : ",best_note);
	printf("%s",best_prenom);
	}
i=0;
}


//calcule la moyenne
void do_average()
{
nb_note = nb_note + note;
nb_student++;
moyenne = nb_note / nb_student;
}


//Effectue la moyenne de toute les notes et fait le print de : la moyenne , La pire note et son détenteur, La meilleur note et son détenteur
void print_all_info()
{
printf("\n\nLa moyenne de la classe est de : ");
printf("%.2f",moyenne);
printf("\n\nLa pire note est de :");
printf(" %.2f obtenue par : ",worst_note);
printf("%s",worst_prenom);
printf("\n\nLa meilleur note est de :");
printf(" %.2f obtenue par : ",best_note);
printf("%s",best_prenom);
}


//Vérifie si la note est corect si non alors on redemande un prenom et une note
void mark_check()
{
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


//Vérifie si le prenom est corect si non alors on retourne erreur prenom
void name_check()
{
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
		}
	else
		{
		errorp=0;
		}
}


//Vérifie si la note et le prenom son bon 
void name_mark_check()
{
do
	{
	name_ask();//Demande un prenom et une note à l'utilisateur
	
	name_check();//Vérifie si le prenom est corect si non alors on ferme le programme
	
	if(errorp == 1 )
	{
	return ;
	}
	
	mark_check();//Vérifie si la note est corect si non alors on redemande un prenom et une note	
	}
while (errorn == 1 || errorp == 1 );
i=0;
}


//main du programme coupe la console une fois arrivé a la fin du programme
int main(int argc, char** argv) 
{
while (errorp != 1 )
	{
	name_mark_check();//Vérifie si la note et le prenom son bon 

	if(errorp == 0 )
		{
		lower_check();// Vérifie si la nouvelle note est encore meilleur que la meilleur note si oui alors on stock le prenom et la note comme nouvelle meilleur note.
		
		higher_check();// Vérifie si la nouvelle note est encore moin bonne que la pire note si oui alors on stock le prenom et la note comme nouvelle pire note.
		
		do_average();//Calcule la moyenne des notes des éleves.

		print_all_info();//Effectue la moyenne de toute les notes et fait le print de : la moyenne , La pire note et son détenteur, La meilleur note et son détenteur.
		}
	}
print_all_info();//Effectue la moyenne de toute les notes et fait le print de : la moyenne , La pire note et son détenteur, La meilleur note et son détenteur.
}
