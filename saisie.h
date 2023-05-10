#ifndef SAISIE_H
#define SAISIE_H
#include "struc.h"
/**
 * @brief Saisit les informations d'un utilisateur à partir de l'entrée de l'utilisateur.
 * @return Un pointeur vers l'objet User créé.
 */
User* SaisieUser();
/**
 * @brief Saisit les informations d'un événement à partir de l'entrée de l'utilisateur.
 * @return Un pointeur vers l'objet Event créé.
 */
Event* SaisieEvent();
/**
 * @brief Saisit les informations d'un plat à partir de l'entrée de l'utilisateur.
 * @return Un pointeur vers l'objet Plat créé.
 */
Plat* saisiePlat();
/**
 * @brief Saisit les informations d'une session à partir de l'entrée de l'utilisateur.
 * @return Un pointeur vers l'objet Session créé.
 */
Session* saisieSession();
/**
 * @brief Saisit les informations d'un film à partir de l'entrée de l'utilisateur.
 * @return Un pointeur vers l'objet Film créé.
 */
Film* saisieFilm();
/**
 * @brief Saisit les informations d'une place à partir de l'entrée de l'utilisateur.
 * @return Un pointeur vers l'objet Place créé.
 */
Place* saisiePlace();
/**
 * @brief Saisit les informations d'un ticket à partir de l'entrée de l'utilisateur.
 * @return Un pointeur vers l'objet Ticket créé.
 */
Ticket* saisieTicket();
#endif