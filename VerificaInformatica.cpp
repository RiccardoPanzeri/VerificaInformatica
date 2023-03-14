
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "prototipi.h"
using namespace std;
int main()
{   
    char nome[100] = "";
    char cognome[100] = "";
    int stipendio = 0;
    bool ripeti = true;
    char scelta = '/';//variabile che conterrà l'azione che l'utente desidera effettuare;
    //utilizzo un array dinamico;
    Dipendente* azienda = NULL;//puntatore nullo;
    int dim = 0;
    //Richiedo la dimensione dell'array all'utente:
    printf("Inserisci la dimensione della lista: \n");
    scanf_s("%d", &dim);//utilizzo scanf_s perchè visual studio mi segnala scanf come poco sicura e non mi lascia proseguire;
    //assegno al puntatore nullo la memoria necessaria; 
    azienda = new Dipendente[dim];
    
    //Preparo l'array, riempendolo di posti liberi;
    preparaArray(azienda, dim);

    do {
        //richiamo il menu;
        menu();
        scanf_s(" %c", &scelta);
        switch (scelta) {
        case '1':
            printf("Inserisci nome: \n");
            getchar();//uso getchar() per risolvere il problema relativo al carattere \n lasciato dalla scanf_s e che verrebbe letto da fgets();
            fgets(nome, 100, stdin);
            printf("Inserisci cognome: \n");
            fgets(cognome, 100, stdin);
            printf("Inserisci stipendio: \n");
            scanf_s("%d", &stipendio);
            caricaElemento(azienda, dim, nome, cognome, stipendio);
            printf("Dipendente inserito con successo!\n");
            break;
        case '2':
            printf("Visualizzo i dipendenti presenti in lista:\n");
            visualizzaPresenti(azienda, dim);
            break;
        case '3':
            printf("Inserisci il cognome del dipendente da rimuovere dalla lista:\n");
            getchar();
            fgets(cognome, 100, stdin);
            cancellaDipendente(azienda, dim, cognome);
            break;
        case '4':
            printf("Inserisci il cognome del dipendente da ricercare:\n");
            getchar();
            fgets(cognome, 100, stdin);
            ricerca(azienda, dim, cognome);
            break;
        case '5':
            printf("A presto!\n");
            ripeti = false;
            break;
        default:
            printf("Input errato!\n");
            break;


            

        }
        
    } while (ripeti == true);
   





    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

