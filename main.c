#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "struc.h"
#include "saisie.h"
#include "function-bd.h"
#include <string.h>
/**
 * @brief Fonction principale du programme.
 *
 * Cette fonction initialise la connexion à la base de données, et permet à
 * l'utilisateur d'intéragir avec le programme en choisissant différentes
 * options.
 *
 * @return 0 si le programme s'est exécuté correctement, une autre valeur sinon.
 */
int main(){
    MYSQL *db = mysql_init(NULL);
    if(db==NULL){
        fprintf(stderr, "%s\n", mysql_error(db));
        exit(1);
    }
    if(mysql_real_connect(db, "localhost", "mohamed", "Drabo@mhd5985", "event", 0, NULL, 0)==NULL){
        fprintf(stderr, "%s\n", mysql_error(db));
        mysql_close(db);
        exit(1);
    }
    bool isAuth = false;
    int choix = 0;
    char section ='M';
    User *currentUser = NULL;
    while (true) {
        switch (isAuth) {
            case false:
                switch (section) {
                    case 'L':
                        currentUser = (User*) malloc(sizeof(User));
                        printf("Nom d'utilisateur: ");
                        fgets(currentUser->email, 100, stdin);
                        printf("Mot de passe: ");
                        fgets(currentUser->password, 100, stdin);
                        currentUser->email[strcspn(currentUser->email, "\n")] = 0;
                        currentUser->password[strcspn(currentUser->password, "\n")] = 0;
                        if (authentification(db, currentUser)) {
                            isAuth = true;
                        }else{
                            printf("\n*****Mot de passe ou le mail incorrecte\n\n");
                        }
                        break;
                }
                if(isAuth){
                    break;
                }
                printf("Bienvenue dans le système. Que souhaitez-vous faire ?\n");
                printf("1. Se connecter\n");
                printf("2. S'inscrire\n");
                printf("Votre choix: ");
                scanf("%d", &choix);
                getchar();
                switch (choix) {
                    case 1:
                        section = 'L';
                        break;
                    case 2:
                        currentUser = createUser(db, SaisieUser());
                        if (currentUser != NULL) {
                            isAuth = true;
                        }
                        break;
                }
                break;
            case true:
                printf("Bienvenue dans le système. Que souhaitez-vous faire ?\n");
                printf("1. Liste des événements\n");
                printf("2. Liste de mes événements\n");
                printf("3. Créer un événement\n");
                printf("Votre choix: ");
                scanf("%d", &choix);
                getchar();
                switch (choix) {
                    case 1:
                        section='E';
                        Event * event = getEvents(db);
                        for(int i=0; i<100; i++){
                            if(event[i].id){
                                printf("\n\nEvenement :%d\n", event[i].id);
                                printEvent(&event[i]);
                            }
                        }
                        free(event);
                        break;
                    case 2:
                        section='M';
                        // Récupération des événements de l'utilisateur courant
                        // Event* myEvents = getMyEvents(db, currentUser);
                        // if (myEvents == NULL) {
                        //     printf("Vous n'avez aucun événement enregistré.\n");
                        // } else {
                        //     // Affichage des événements de l'utilisateur courant
                        //     for(int i=0; i<100; i++){
                        //         if(myEvents[i].id){
                        //             printf("\n\nEvenement :%d\n", myEvents[i].id);
                        //             printEvent(&myEvents[i]);
                        //         }
                        //     }
                        //     free(myEvents);
                        // }
                        break;
                    case 3:
                        section='C';
                        // Création d'un événement
                        Event* newEvent = createEvent(db, SaisieEvent());
                        if (newEvent == NULL) {
                            printf("Une erreur est survenue lors de la création de l'événement.\n");
                        } else {
                            printf("L'événement a été créé avec succès !\n");
                            printf("Que souhaitez-vous faire maintenant ?\n");
                            printf("1. Afficher la liste de mes événements\n");
                            printf("2. Créer une session\n");
                            printf("3. Ajouter une place à l'événement\n");
                        printf("4. Ajouter un plat à l'événement\n");
                        printf("5. Retourner au menu principal\n");
                        printf("Votre choix: ");
                        scanf("%d", &choix);
                        getchar();
                        switch (choix) {
                            case 1:
                                section = 'M';
                                break;
                            case 2:
                                section = 'S';
                                // Création d'une session
                                Session* newSession = createSession(db, saisieSession(), newEvent);
                                if (newSession == NULL) {
                                    printf("Une erreur est survenue lors de la création de la session.\n");
                                } else {
                                    printf("La session a été créée avec succès !\n");
                                }
                                break;
                            case 3:
                                section = 'P';
                                // Ajout d'une place à l'événement
                                Place* newPlace = saisiePlace();
                                if (newPlace == NULL) {
                                    printf("Une erreur est survenue lors de la création de la place.\n");
                                } else {
                                    createPlace(db, newPlace, newEvent);
                                    printf("La place a été ajoutée avec succès à l'événement !\n");
                                }
                                break;
                            case 4:
                                section = 'T';
                                // Ajout d'un plat à l'événement
                                Plat* newPlat = createPlat(db, saisiePlat(), newEvent);
                                if (newPlat == NULL) {
                                    printf("Une erreur est survenue lors de la création du plat.\n");
                                } else {
                                    printf("Le plat a été ajouté avec succès à l'événement !\n");
                                }
                                break;
                            case 5:
                                section = 'P';
                                break;
                        }
    }
    break;
                }
}
}}
