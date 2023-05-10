#ifndef FUNCTION_BD_H
#define FUNCTION_BD_H
#include "struc.h"
#include <mysql/mysql.h>
/**

@brief Fonction pour créer un nouvel utilisateur dans la base de données
@param db Pointeur vers la base de données
@param user Pointeur vers l'utilisateur à créer
@return Pointeur vers l'utilisateur créé dans la base de données
/
User createUser(MYSQL * db,User * user);
/**

@brief Fonction pour créer un nouvel événement dans la base de données
@param db Pointeur vers la base de données
@param event Pointeur vers l'événement à créer
@return Pointeur vers l'événement créé dans la base de données
/
Event createEvent(MYSQL * db,Event * event);
/**

@brief Fonction pour récupérer tous les utilisateurs de la base de données
@param db Pointeur vers la base de données
@return Pointeur vers un tableau d'utilisateurs récupérés depuis la base de données
*/
User *getUsers(MYSQL *db);
/**

@brief Fonction pour créer un nouveau ticket dans la base de données pour un utilisateur et un événement donné
@param db Pointeur vers la base de données
@param ticket Pointeur vers le ticket à créer
@param event Pointeur vers l'événement pour lequel le ticket est créé
@param user Pointeur vers l'utilisateur qui achète le ticket
@return Pointeur vers le ticket créé dans la base de données
*/
Ticket *createTicket(MYSQL *db,Ticket *ticket, Event * event, User *user);
/**

@brief Fonction pour créer une réservation dans la base de données pour un utilisateur et une place donnée
@param db Pointeur vers la base de données
@param user Pointeur vers l'utilisateur qui effectue la réservation
@param place Pointeur vers la place réservée
*/
void createReservation(MYSQL * db, User * user, Place * place);
/**

@brief Fonction pour créer une commande dans la base de données pour un utilisateur et un plat donné
@param db Pointeur vers la base de données
@param user Pointeur vers l'utilisateur qui effectue la commande
@param plat Pointeur vers le plat commandé
*/
void createCommander(MYSQL * db, User * user, Plat * plat);
/**

@brief Fonction pour créer un nouveau plat dans la base de données pour un événement donné
@param db Pointeur vers la base de données
@param plat Pointeur vers le plat à créer
@param event Pointeur vers l'événement pour lequel le plat est créé
@return Pointeur vers le plat créé dans la base de données
*/
Plat * createPlat(MYSQL * db, Plat * plat, Event * event);
/**

@brief Fonction pour créer une nouvelle place dans la base de données pour un événement donné
@param db Pointeur vers la base de données
@param place Pointeur vers la place à créer
@param event Pointeur vers l'événement pour lequel la place est créée
@return Pointeur vers la place créée dans la base de données
*/
Place * createPlace(MYSQL * db, Place * place, Event * event);
/**
 * @brief Crée une nouvelle session dans la base de données pour un événement donné
 * 
 * @param db Pointeur vers la base de données
 * @param session Pointeur vers la session à créer
 * @param event Pointeur vers l'événement auquel la session appartient
 * @return Session* Pointeur vers la session créée si elle a été créée avec succès, NULL sinon
 */
Session * createSession(MYSQL * db, Session * session, Event * event);
/**
 * @brief Crée un nouveau film dans la base de données pour une session donnée
 * 
 * @param db Pointeur vers la base de données
 * @param film Pointeur vers le film à créer
 * @param session Pointeur vers la session à laquelle le film appartient
 * @return Film* Pointeur vers le film créé si la création a réussi, NULL sinon
 */
Film * createFilm(MYSQL * db, Film * film, Session * session);

/**
 * @brief Met à jour un événement dans la base de données
 * 
 * @param db Pointeur vers la base de données
 * @param event Pointeur vers l'événement à mettre à jour
 * @return Event* Pointeur vers l'événement mis à jour si la mise à jour a réussi, NULL sinon
 */
Event * updateEvent(MYSQL * db, Event * event);

/**
 * @brief Supprime un événement de la base de données
 * 
 * @param db Pointeur vers la base de données
 * @param event Pointeur vers l'événement à supprimer
 */
void deleteEvent(MYSQL * db, Event * event);

/**
 * @brief Récupère tous les plats associés à un événement donné dans la base de données
 * 
 * @param db Pointeur vers la base de données
 * @param event Pointeur vers l'événement pour lequel récupérer les plats
 * @return Plat** Tableau de pointeurs vers les plats associés à l'événement
 */
Plat ** getPlatByEventId(MYSQL * db, Event * event);

/**
 * @brief Récupère toutes les sessions associées à un événement donné dans la base de données
 * 
 * @param db Pointeur vers la base de données
 * @param event Pointeur vers l'événement pour lequel récupérer les sessions
 * @return Session** Tableau de pointeurs vers les sessions associées à l'événement
 */
Session ** getSessionByEventId(MYSQL * db, Event * event);

/**
 * @brief Récupère toutes les places associées à un événement donné dans la base de données
 * 
 * @param db Pointeur vers la base de données
 * @param event Pointeur vers l'événement pour lequel récupérer les places
 * @return Place** Tableau de pointeurs vers les places associées à l'événement
 */
Place ** getPlaceByEventId(MYSQL * db, Event * event);

/**
 * @brief Récupère le ticket associé à un utilisateur et à un événement donnés dans la base de données
 * 
 * @param db Pointeur vers la base de données
 * @param user Pointeur vers l'utilisateur pour lequel récupérer le ticket
 * @param event Pointeur vers l'événement pour lequel récupérer le ticket
 * @return Ticket* Pointeur vers le ticket associé à l'utilisateur et à l'événement
 */
Ticket * getTicketByUserId(MYSQL * db, User * user, Event ** event);

/**
 * @brief Récupère tous les événements de la base de données
 * 
 * @param db Pointeur vers la base de données
 * @return Event* Tableau de pointeurs vers les événements de la base de données
 */
Event * getEvents(MYSQL * db);
/**

@brief Récupère tous les événements stockés dans la base de données.
Cette fonction se connecte à la base de données via le pointeur db fourni,
et récupère tous les événements stockés dans la table "events".
Elle renvoie un pointeur vers un tableau d'événements alloué dynamiquement.
Si aucun événement n'est trouvé dans la base de données, la fonction renvoie NULL.
@param db Pointeur vers la base de données.
@return Pointeur vers un tableau d'événements, ou NULL si aucun événement n'est trouvé.
*/
Event * getEvents(MYSQL *db);
/**

@brief Récupère tous les films associés à une session donnée.
Cette fonction se connecte à la base de données via le pointeur db fourni,
et récupère tous les films associés à la session fournie dans la table "films".
Elle renvoie un pointeur vers un tableau de films alloué dynamiquement.
Si aucun film n'est trouvé dans la base de données pour la session fournie, la fonction renvoie NULL.
@param db Pointeur vers la base de données.
@param session Pointeur vers la session pour laquelle récupérer les films.
@return Pointeur vers un tableau de films, ou NULL si aucun film n'est trouvé.
*/
Film ** getFilmBySessionId(MYSQL *db, Session *session);
/**

@brief Vérifie l'authentification d'un utilisateur.
Cette fonction se connecte à la base de données via le pointeur db fourni,
et vérifie si l'utilisateur fourni est présent dans la table "users" avec le mot de passe correspondant.
Elle renvoie true si l'authentification est réussie, sinon false.
@param db Pointeur vers la base de données.
@param user Pointeur vers l'utilisateur à vérifier.
@return true si l'authentification est réussie, sinon false.
*/
bool authentification(MYSQL *db, User *user);
#endif