#ifndef STRUC_H
#define STRUC_H
typedef struct user User; /**< Type de données représentant un utilisateur */
typedef struct place Place; /**< Type de données représentant un emplacement pour un événement */
typedef struct ticket Ticket; /**< Type de données représentant un billet pour un événement */
typedef struct plat Plat; /**< Type de données représentant un plat pour un événement */
typedef struct event Event; /**< Type de données représentant un événement */
typedef struct session Session; /**< Type de données représentant une session pour un événement */
typedef struct film Film; /**< Type de données représentant un film */
typedef struct user {
    int id; /**< L'identifiant de l'utilisateur */
    char firstName[100]; /**< Le prénom de l'utilisateur */
    char lastName[100]; /**< Le nom de l'utilisateur */
    char rule[100]; /**< La règle de l'utilisateur */
    char email[100]; /**< L'email de l'utilisateur */
    char password[100]; /**< Le mot de passe de l'utilisateur */
    Place **place; /**< Les emplacements associés à cet utilisateur */
    Ticket **ticket; /**< Les billets associés à cet utilisateur */
    Plat **plat; /**< Les plats associés à cet utilisateur */
} User;
/**
 * @struct place
 * @brief Structure représentant un emplacement
 *
 * Cette structure représente un emplacement et contient son identifiant,
 * son numéro, l'utilisateur et l'événement associés à cet emplacement.
 */
typedef struct place {
    int id; /**< L'identifiant de l'emplacement */
    int number; /**< Le numéro de l'emplacement */
    User *user; /**< L'utilisateur associé à cet emplacement */
    Event *event; /**< L'événement associé à cet emplacement */
} Place;

/**

@struct film
@brief Structure représentant un film
Cette structure représente un film et contient son identifiant,
son titre, sa description, son auteur, ainsi que la session associée à ce film.
*/
typedef struct film{
    int id;
    char titre[100];
    char description[100];
    char auteur[100];
    Session* session;
} Film;

/**

@struct ticket
@brief Structure représentant un billet
Cette structure représente un billet et contient son identifiant, son numéro,
sa date d'émission, l'utilisateur qui l'a acheté ainsi que l'événement auquel il est associé.
*/
typedef struct ticket
{
    int id;
    int number;
    char dateTicket[100];
    User* user;
    Event * event;
} Ticket;

/**

@struct event
@brief Structure représentant un événement
Cette structure représente un événement et contient son identifiant,
son type, son lieu, son label, sa date, ainsi que les sessions, emplacements,
billets et plats associés à cet événement.
*/
typedef struct event {
int id; /*< Identifiant de l'événement */
char type[100]; /*< Type de l'événement */
char lieu[100]; /*< Lieu de l'événement */
char label[100]; /*< Libellé de l'événement*/
char dateEvent[100]; /*< Date de l'événement */
int nbrPlat; /*< Nombre de plats associés à l'événement */
int nbrPlace; /*< Nombre d'emplacements associés à l'événement */
int nbrTicket; /*< Nombre de billets associés à l'événement */
int nbrSession; /**< Nombre de sessions associées à l'événement */
Session **session; /**< Tableau de pointeurs vers les sessions associées à l'événement */
Place** place; /**< Tableau de pointeurs vers les emplacements associés à l'événement */
Ticket **ticket; /**< Tableau de pointeurs vers les billets associés à l'événement */
Plat** plat; /*< Tableau de pointeurs vers les plats associés à l'événement */
} Event;





/**
 * @struct plat
 * @brief Structure représentant un plat
 *
 * Cette structure représente un plat et contient son identifiant,
 * son label, l'utilisateur et l'événement associés à ce plat.
 */
typedef struct plat {
    int id; /**< L'identifiant du plat */
    char label[100]; /**< Le label du plat */
    User *user; /**< L'utilisateur associé à ce plat */
    Event *event; /**< L'événement associé à ce plat */
} Plat;


/**
 * @struct session
 * @brief Structure représentant une session
 *
 * Cette structure représente une session et contient son identifiant,
 * le nombre de films, le nom de la session, la date de la session,
 * ainsi que l'événement et les films associés à cette session.
 */
typedef struct session {
    int id; /**< L'identifiant de la session */
    int nbrFilm; /**< Le nombre de films de la session */
    char name[100]; /**< Le nom de la session */
    char dateSession[100]; /**< La date de la session */
    Event *event; /**< L'événement associé à cette session */
    Film **film; /**< Les films associés à cette session */
} Session;
#endif