#ifndef FUNCTION_H
#define FUNCTION_H
#include "struc.h"
/**
 * @brief Ajoute un plat à un événement.
 * @param plat Le plat à ajouter.
 * @param event L'événement auquel ajouter le plat.
 * @return Un pointeur vers l'objet Event modifié.
 */
Event* addPlatToEvent(Plat* plat, Event* event);
/**
 * @brief Ajoute une place à un événement.
 * @param place La place à ajouter.
 * @param event L'événement auquel ajouter la place.
 * @return Un pointeur vers l'objet Event modifié.
 */
Event* addPlaceToEvent(Place* place, Event* event);
/**
 * @brief Ajoute un ticket à un événement.
 * @param ticket Le ticket à ajouter.
 * @param event L'événement auquel ajouter le ticket.
 * @return Un pointeur vers l'objet Event modifié.
 */
Event* addTicketToEvent(Ticket* ticket, Event* event);
/**
 * @brief Ajoute un film à une session.
 * @param film Le film à ajouter.
 * @param session La session à laquelle ajouter le film.
 * @return Un pointeur vers l'objet Session modifié.
 */
Session* addFilmToSession(Film* film, Session* session);
/**
 * @brief Ajoute une session à un événement.
 * @param session La session à ajouter.
 * @param event L'événement auquel ajouter la session.
 * @return Un pointeur vers l'objet Event modifié.
 */
Event* addSessionToEvent(Session* session, Event* event);
/**
 * @brief Supprime un plat d'un événement.
 * @param plat Le plat à supprimer.
 * @param event L'événement duquel supprimer le plat.
 */
void deletePlatFromEvent(Plat* plat, Event* event);
/**
 * @brief Supprime une place d'un événement.
 * @param place La place à supprimer.
 * @param event L'événement duquel supprimer la place.
 */
void deletePlaceFromEvent(Place* place, Event* event);
/**
 * @brief Supprime un ticket d'un événement.
 * @param ticket Le ticket à supprimer.
 * @param event L'événement duquel supprimer le ticket.
 */
void deleteTicketFromEvent(Ticket* ticket, Event* event);
/**
 * @brief Supprime une session d'un événement.
 * @param session La session à supprimer.
 * @param event L'événement duquel supprimer la session.
 */
void deleteSessionFromEvent(Session* session, Event* event);
/**
 * @brief Affiche les informations d'un utilisateur.
 * @param user L'utilisateur à afficher.
 */
void printUser(User* user);
/**
 * @brief Affiche les informations d'un événement.
 * @param event L'événement à afficher.
 */
void printEvent(Event* event);
/**
 * @brief Affiche les informations d'une session.
 * @param session La session à afficher.
 */
void printSession(Session* session);
/**
 * @brief Affiche les informations d'un film.
 * @param film Le film à afficher.
 */
void printFilm(Film* film);
#endif