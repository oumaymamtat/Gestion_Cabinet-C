#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct date {
	int j;
	int m;
	int a;
};
typedef struct date DATE;

struct patient{
	int num;
	char nom [30];
	char prenom [30];
	char adresse[30] ;
	DATE date_naissance;
	char lieu_naissance[30] ;
	char etat_civil[30] ;
};
typedef struct patient PATIENT; 

int ajout (PATIENT* tab_patient,int* n){
	PATIENT* p;
	tab_patient = (PATIENT*) realloc(tab_patient,sizeof(PATIENT));
	if(!tab_patient) exit(-1);
	printf("p = tab+(%d) \n",(*n));
	p = (tab_patient+(*n));
	printf("donner le numero de patient \n");
	scanf("%d", &(p->num)  );
	printf ("donner le nom de patient \n");
	scanf("%s",p->nom);
	printf("donner le prenom de patient \n");
	scanf("%s",p->prenom);
	printf ("donner l adresse de patient \n");
	scanf("%s",p->adresse);
	printf ("donner la date de naissance\n");
	while( (p->date_naissance.j) < 1 || (p->date_naissance.j) >31 ){
		printf ("donner le jour : (entre 1 et 31) \n");
		scanf ("%d",&(p->date_naissance.j));
	}; 
	while( (p->date_naissance.m) < 1 || (p->date_naissance.m) >12 ){
		printf("donner le mois : (entre 1 et 12)\n");
		scanf ("%d",&(p->date_naissance.m));
	};
	while( (p->date_naissance.a) < 1900 || (p->date_naissance.a) >2020 ){
		printf ("donner l annee : (entre 1900 et 2020) \n");
		scanf ("%d",&(p->date_naissance.a));
	};
	printf("donner le lieu de naissance\n");
	scanf("%s",p->lieu_naissance);
	printf ("donner l etat civil \n");
	scanf("%s",p->etat_civil);
	(*n)++;
	printf ("************** Patient ajoutee avec succes ********************\n");
	//printf("a la fin d'ajout n=%d \n",(*n));
}
void afficher_patient(PATIENT* p){
	printf("numero: %d \n",p->num);
	printf("nom: %s \n",p->nom);
	printf("prenom: %s \n",p->prenom);
	printf("adresse: %s \n",p->adresse);
	printf("numero : %d \n",p->num);
	printf("date de naissance : %d/%d/%d \n",p->date_naissance.j,p->date_naissance.m,p->date_naissance.a);
	printf("lieu de naissance: %s \n",p->lieu_naissance);
	printf("etat civil: %s \n",p->etat_civil);
	printf("-----------------------------------------------------\n ");
}
void afficher_tab_patient(PATIENT* tab_patient,int n){
	if(n==0){
	    printf("-----------------------------------------------------------------\n");
		printf("La liste ne contient aucun patient \n");
	    printf("-----------------------------------------------------------------\n");
	} 
	else{
	    printf("-----------------------------------------------------------------\n");
	    printf("La liste contient %d patient(s) avec les coordonnées suivants : \n",n);
	    printf("-----------------------------------------------------------------\n");
	    for(int i=0;i<n;i++){
			printf("Patient %d : \n",(i+1));
	    	afficher_patient((tab_patient+i));
	    }
	}
}
void supprimer (PATIENT* tab_patient,int *n,int numero){
	printf ("donner le numero de patient a supprimer\n");
	scanf ("%d",&numero);
	int pos = -1;
	for(int i=0;i<(*n);i++){
		if(( (tab_patient+i)->num) == numero){
			pos = i;
			printf("patient existe à la position %d \n",pos);
			printf("on va le supprimer :\n");
			if(pos != ((*n)-1)){
				for(int j=pos;j<(*n);j++){
					printf("j=%d , j+1 = %d \n",j,(j+1));
		            printf("tab_patient[j] %d <- tab_patient[j+1]:%d \n",tab_patient[j],tab_patient[j+1]);
		            tab_patient[j]=tab_patient[j+1];
            	}
			}
		    (*n)--;
		}
	}
	if(pos == -1){
		printf("patient n existe pas \n");
	}
    printf("-----------------------------------------------------------------\n");
	printf("**************** Patient supprime avec succes ***********\n");
}

void chercher (PATIENT* tab_patient,int n,int numero){
	printf ("donner le numero de patient a chercher : \n");
	scanf ("%d",&numero);
	int existe = 0;
	for(int i=0;i<n;i++){
		if((tab_patient+i)->num == numero){
			existe = 1;
			printf("patient existe à la position %d \n",i);
			printf("ses coordonnees sont les suivants :\n");
			afficher_patient((tab_patient+i));
		}
	}
	if(existe == 0){
		printf("patient n existe pas \n");
	}
}

void choix_modification(int x,PATIENT *p,int r,PATIENT* tab_patient ,int n){
			do {
				printf ("Qu est ce que vous voulez modifier ? \n");
		        printf ("si vous voulez modifier le nom tapez 1\n");
		        printf ("si vous voulez modifier le prenom tapez 2\n");
		        printf ("si vous voulez modifier l adresse tapez 3 \n");
		        printf ("si vous voulez modifier la date de naissance tapez 4\n");
		        printf ("si vous voulez modifier le lieu de naissance tapez 5\n");
		        printf ("si vous voulez modifier l'etat civil tapez 6\n");
		        printf ("si vous avez fini la modification tapez 0 \n");
            	printf("-----------------------------------------------------------------\n");
		        scanf ("%d",&x); 
				if(x<0 || x>6){
					printf("Veuillez tapez un chiffre valide \n");
					printf("-----------------------------------------------------------------\n");
				}
			}
			while( x<0 || x>6 );
			switch (x) {
				case 1 : printf ("donner le nouveau nom : \n");
				         scanf ("%s",p->nom); choix_modification(x,p,r,tab_patient , n); break;
		        case 2 : printf ("donner le nouveau prenom: \n");
		                 scanf ("%s",p->prenom);choix_modification(x,p,r,tab_patient , n);break;
		        case 3 : printf ("donner la nouvelle adresse : \n");
		                 scanf ("%s",p->adresse);choix_modification(x,p,r,tab_patient , n);break;
		        case 4 : printf ("donner la nouvelle date de naissance: \n");
				         do{
							 printf ("donner le jour : (entre 1 et 31) \n");
		                     scanf ("%d",&(p->date_naissance.j));
						 } while( (p->date_naissance.j) < 1 || (p->date_naissance.j) >31 );
						 do{
							 printf("donner le mois : (entre 1 et 12)\n");
		                     scanf ("%d",&(p->date_naissance.m));
						 } while( (p->date_naissance.m) < 1 || (p->date_naissance.m) >12 );		
						 do{
							 printf ("donner l annee : (entre 1900 et 2020) \n");
		                     scanf ("%d",&(p->date_naissance.a));
						 }                    
	                     while( (p->date_naissance.a) < 1900 || (p->date_naissance.a) >2020 );
						 choix_modification(x,p,r,tab_patient , n); break;
		        case 5 : printf ("donner le nouveau lieu de naissance: \n");
		                 scanf ("%s",p->lieu_naissance);choix_modification(x,p,r,tab_patient , n);break;
	            case 6 : printf ("donner le nouvel etat civil: \n");
		                 scanf ("%s",p->etat_civil); choix_modification(x,p,r,tab_patient , n);break;    
				case 0 : gestion_patient(r,tab_patient,n);break;		     
		 	}
}

void modifier (PATIENT* tab_patient,int n,int numero){
	int x,r;
	PATIENT *p;
	printf ("donner le numero de personne a modifier : \n");
	scanf ("%d",&numero);
	int pos = -1;
	for(int i=0;i<n;i++){
		if( ((tab_patient+i)->num) == numero){
			pos = i ;
			printf("patinet existe a la position %d \n",pos);
			p=(tab_patient+i);
			choix_modification(x,p,r,tab_patient , n);	
		}
	}
	if (pos == -1){
		printf("patient n existe pas\n");
	}
}

void gestion_patient(int r,PATIENT* tab_patient ,int n){
	int numero;
	do {
	    printf ("pour ajouter un nouveau patient tapez 1 \n");
	    printf ("pour supprimer un patient existant tapez 2 \n");
	    printf ("pour chercher un patient tapez 3 \n");
	    printf ("pour modifier un patient tapez 4 \n");
	    printf ("pour afficher la liste de tous les patients tapez 5 \n");
	    printf ("pour quitter tapez 0 \n");
     	printf("-----------------------------------------------------------------\n");
	    scanf ("%d",&r);
		if(r<0 || r>5){
			printf("Veuillez tapez un chiffre valide \n");
         	printf("-----------------------------------------------------------------\n");
		}
	}
	while ( r<0 || r>5);
	//printf("dans gestion patient : n=%d \n",(n));
	switch (r){
        case 1 : ajout (tab_patient,&n);gestion_patient(r,tab_patient,n);break;
        case 2 : supprimer (tab_patient,&n,numero);gestion_patient(r,tab_patient,n); break;
        case 3 : chercher (tab_patient,n,numero); gestion_patient(r,tab_patient,n);break;
        case 4 : modifier (tab_patient,n,numero);gestion_patient(r,tab_patient,n);break;
        case 5 : afficher_tab_patient(tab_patient,n);gestion_patient(r,tab_patient,n);break;
		case 0 : printf("Merci d avoir utiliser notre application !"); exit(-1);break;
	};
}

int main()
{
	int r;
	int n;
	n=0;
	PATIENT* tab_patient;
	printf("-----------------------------------------------------------------\n");
	printf("Bienvenue dans notre système de gestion de cabinet médical : \n");
	printf("-----------------------------------------------------------------\n");
	tab_patient= (PATIENT*) malloc(sizeof(PATIENT));
	if(!tab_patient) exit(-1);
	printf("Veuillez commencer par ajouter vos patients : \n");
	printf("-----------------------------------------------------------------\n");
	//printf("on va executer avec n = %d \n" ,n);
	gestion_patient(r,tab_patient,n);
	free(tab_patient);
	tab_patient= NULL;
	return (0);
}