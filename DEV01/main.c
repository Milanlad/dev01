#include <stdio.h>
#include <string.h>



void name_ask(char name[99])
{
	printf("\n");
	printf("\nSaisir un prenom : ");
	scanf(" %[^\n]",name);
}

void mark_ask(float *mark)
{
	printf("Saisir une note : ");
	scanf("%f",mark);
}

int name_check (char name[99],char error_name[99])
{
if (strcmp(error_name,name) == 0)
	{
	return 1 ;
	}
else
	{
	return 0 ;
	}
}

int mark_check(float mark)
{
		if (mark >20 || mark <0)
			{
			printf("\nC'est pas une note corect ");
			return 1;
			}
		else
			{
			return 0;
			}	
}

void higher_check (float *mark, float *best_mark, char name[99], char best_name[99])
{
if(*mark > *best_mark)
	{
	*best_mark = *mark;
	strcpy(best_name,name);
	printf("\n\nNouvelle meilleur note de :");
	printf(" %.2f obtenue par : ",*best_mark);
	printf("%s",best_name);
	}
}

void lower_check (float *mark, float *worst_mark, char name[99], char worst_name[99])
{
if(*mark < *worst_mark)
	{
	*worst_mark = *mark;
	strcpy(worst_name,name);
	printf("\n\nNouvelle pire note de :");
	printf(" %.2f obtenue par : ",*worst_mark);
	printf("%s",worst_name);
	}
}

//effectue la moyenne
float do_average(float mark)
{
float average = 0;
static float nb_student = 0;
static float somme_note = 0;

somme_note = somme_note + mark;
nb_student++;
average = somme_note / nb_student;
return average ;
}

void print_all_info(float *average,char best_name[99],char worst_name[99],float *best_mark,float *worst_mark)
{
printf("\n\nLa moyenne de la classe est de : %.2f",*average);
printf("\n\nLa pire note est de : %.2f obtenue par : %s",*worst_mark,worst_name);
printf("\n\nLa meilleur note est de : %.2f obtenue par : %s",*best_mark,best_name);
}

int main ()
{
char error_prenom[99] = "X AE A-XII";
char prenom[99] = "";
char best_prenom[99]= "";
char worst_prenom[99] = "";
int errorp = 0;
int errorn = 0;
float moyenne = 0;
//float worst_note = 21;
//float note,best_note,nb_note,nb_student = 0;
float note = 0;
float best_note = 0;
float worst_note = 21;
while (errorp != 1 )// si le mauvais prenom est rentree on ne boucle plus et on affiche une derniere fois toute les info avant de fermer le programme.
	{
	do
	{
	name_ask(prenom);//Demande un prenom à l utilisateur
    errorp = name_check(prenom,error_prenom);//Verifie si le prenom est corect si non alors on ferme le programme
    if(errorp == 1 )
        {
        errorn = 0;
        }
    else
        {
        mark_ask(&note);//Demande une note à l utilisateur
        errorn = mark_check(note);//VÃ©rifie si la note est corect si non alors on redemande un prenom et une note
        }
    }
while (errorn == 1 );

	if(errorp == 0 ) // si le mauvais prenom est rentrÃ©e alors on esquive toute les procedure afin de ne pas impacter les notes.
		{
		lower_check(&note,&worst_note,prenom,worst_prenom);// VÃ©rifie si la nouvelle note est encore meilleur que la meilleur note si oui alors on stock le prenom et la note comme nouvelle meilleur note.
		higher_check(&note,&best_note,prenom,best_prenom);// VÃ©rifie si la nouvelle note est encore moin bonne que la pire note si oui alors on stock le prenom et la note comme nouvelle pire note.
		moyenne = do_average(note);//Calcule la moyenne des notes des Ã©leves.
		}
	}
print_all_info(&moyenne,best_prenom,worst_prenom,&best_note,&worst_note);//Fait le print de : la moyenne , La pire note et son dÃ©tenteur, La meilleur note et son dÃ©tenteur.
}