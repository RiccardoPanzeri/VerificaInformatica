#include "struct.h"
//Funzione che imposta l'array, riempendolo di posti vuoti; 
void preparaArray(Dipendente azienda[], int dim);
//funzione che permette di inserire unsingolo dipendente nell'array;
void caricaElemento(Dipendente azienda[], int dim, char nome[], char cognome[], int stipendio);
//funzione che stampa i dati dei dipendenti presenti, ignorando i posti vuoti; 
void visualizzaPresenti(Dipendente azienda[], int dim);
//funzioneche cancella un dipendente, selezionandolo per cognome;
void cancellaDipendente(Dipendente azienda[], int dim, char cognome[]);
//funzione che permette di cercare un dipendente per cognome;
void ricerca(Dipendente azienda[], int dim, char cognome[]);
//funzione che stampa un menù con le istruzioni per l'utente;
void menu();



