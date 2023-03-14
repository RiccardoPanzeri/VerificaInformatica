#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "prototipi.h"

using namespace std;

void preparaArray(Dipendente azienda[], int dim) {
	for (int i = 0; i < dim; i++) {
		strcpy_s(azienda[i].nome, "");
		strcpy_s(azienda[i].cognome, "");//uso strcopy_s perchè visual studio mi segnala strcpy come non sicura;
		azienda[i].stipendio = 0;
		azienda[i].presente = 0;
	}

}

void caricaElemento(Dipendente azienda[], int dim, char nome[], char cognome[], int stipendio) {
	int trovato = 0;
	for (int i = 0; i < dim; i++) {
		 if (azienda[i].presente == 0 && trovato == 0) {
			 strcpy_s(azienda[i].nome, nome);
			 strcpy_s(azienda[i].cognome, cognome);
			 azienda[i].stipendio = stipendio;
			 azienda[i].presente = 1;
			 trovato = 1;//modificando il booleano, una volta trovato il primo posto libero, non verrà assegnato alcun valore ai posti liberi successivi;

			}
		
	}



}


void visualizzaPresenti(Dipendente azienda[], int dim) {
	int vuoto = 1;//il booleano chesegnala se l'array è vuoto ha valore iniziale "vero";
	for (int i = 0; i < dim; i++) {
		if (azienda[i].presente != 0) {
			vuoto = 0;//se viene trovato almeno un elemento, il booleano vuoto viene impostato su "falso";
		}
	}
	if (vuoto == 0) {//se l'array non è vuoto, vengono stampati i presenti;
		for (int i = 0; i < dim; i++) {
			if (azienda[i].presente != 0) {
				printf("Nome: %s\n", azienda[i].nome);
				printf("cognome: %s\n", azienda[i].cognome);
				printf("stipendio: %d\n\n", azienda[i].stipendio);
			}
		}
	}
	else {//se l'array è vuoto, viene visualizzato l'errore;
		printf("Attenzione, non ci sono dipendenti all'interno della lista!\n\n");
	}
}

void cancellaDipendente(Dipendente azienda[], int dim, char cognome[]) {
	int vuoto = 1;//il booleano chesegnala se l'array è vuoto ha valore iniziale "vero";
	for (int i = 0; i < dim; i++) {
		if (azienda[i].presente != 0) {
			vuoto = 0;//se viene trovato almeno un elemento, il booleano vuoto viene impostato su "falso";
		}
	}
	if (vuoto == 0) {
		for (int i = 0; i < dim; i++) {
			if (strcmp(azienda[i].cognome, cognome) == 0) {
				strcpy_s(azienda[i].nome, "");
				strcpy_s(azienda[i].cognome, "");
				azienda[i].stipendio = 0;
				azienda[i].presente = 0;
			}

		}
		printf("Elemento eliminato con successo!\n\n");

	}
	else {
		printf("Non ci sono dipendenti presenti in lista!\n\n");
	}
}


void ricerca(Dipendente azienda[], int dim, char cognome[]) {
	int trovato = 0;//utilizzo un booleano per capire se il cognome è presente in lista: il valore iniziale è "falso";
	for (int i = 0; i < dim; i++) {
		if (strcmp(azienda[i].cognome, cognome) == 0) {
			printf("Nome: %s\n", azienda[i].nome);
			printf("cognome: %s\n", azienda[i].cognome);
			printf("stipendio: %d\n\n", azienda[i].stipendio);
			trovato = 1;//se ne trovo uno, cambio il booleano in "vero";
		}

	}
	if (trovato == 0) {//se non ne trovo, il booleano resta falso e viene visualizzato il messaggio;
		printf("Nessun Dipendente con questo cognome è presente nella lista!\n\n");
	}
}

void menu() {
	printf("cosa vuoi fare?\n");
	printf("1- inserisci un dipendente alla lista\n");
	printf("2- visualizza i dipendenti presenti nella lista\n");
	printf("3- cancella un dipendente dalla lista\n");
	printf("4- ricerca un dipendente nella lista\n");
	printf("5- esci\n");
}