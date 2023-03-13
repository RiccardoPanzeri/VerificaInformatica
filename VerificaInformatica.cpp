
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "prototipi.h"
using namespace std;
int main()
{   
    //utilizzo un array dinamico;
    Dipendente* azienda = NULL;//puntatore nullo;
    int dim = 10;
    //dichiaro le variabili contenenti i dati del dipendente 1:
    char nome[100] = "Mario";
    char cognome[100] = "Rossi";
    //dichiaro le variabili contenenti i dati del dipendente 2:
    char nome1[100] = "Tizio";
    char cognome1[100] = "Caio";
    //dichiaro le variabili contenenti i dati del dipendente 3:
    char nome2[100] = "Luigi";
    char cognome2[100] = "Verdi";
    //Richiedo la dimensione dell'array all'utente:
    printf("Inserisci la dimensione della lista: \n");
    scanf_s("%d", &dim);//utilizzo scanf_s perchè visual studio mi segnala scanf come poco sicura e non mi lascia proseguire;
    
    //assegno al puntatore nullo la memoria necessaria; 
    azienda = new Dipendente[dim];
    
    //Preparo l'array, riempendolo di posti liberi;
    preparaArray(azienda, dim);
    
    //carico l'array con il primo dipendente:
    caricaElemento(azienda, dim, nome, cognome, 1290);
    
    //carico l'array con il secondo dipendente:
    caricaElemento(azienda, dim, nome1, cognome1, 1488);
    
    //cancello il primo dipendente, liberando il primo posto:
    cancellaDipendente(azienda, dim, cognome);
    
    //carico il terzo dipendente, che verrà inserito al primo posto, dato che ora è il primo posto libero;
    caricaElemento(azienda, dim, nome2, cognome2, 1989);
    
    //verifico, visualizzando tutti i presenti;
    visualizzaPresenti(azienda, dim);
    
    //effettuo una ricerca per cognome su un dipendente che non è presente in lista:
    printf("cerco un dipendente non presente in lista:\n");
    ricerca(azienda, dim, cognome);
    
    //ora ne cerco uno presente inlista
    printf("cerco un dipendente:\n");
    ricerca(azienda, dim, cognome1);





    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

