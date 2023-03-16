#include <stdio.h>
#include "struc.h"
#include <mysql/mysql.h>
User *createUser(MYSQL *db, User *user)
{
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     int i = 0;
     char query[1000];
     sprintf(query, "insert into user (fist_name, last_name, rule, email, password) values(\"%s\", \"%s\", \"%s\",\"%s\", \"%s\")", user->firstName, user->lastName, user->rule, user->email, user->password);
     mysql_query(db, query);
     char query2[] = "select last_insert_id()";
     mysql_query(db, query2);
     result = mysql_store_result(db);
     row = mysql_fetch_row(result);
     user->id = atoi(row[0]);
}
Event *createEvent(MYSQL *db, Event *event)
{
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     int i = 0;
     char query[1000];
     sprintf(query, "insert into event(type, place, date_event, label) values(\"%s\", \"%s\", \"%s\",\"%s\")", event->type, event->lieu, event->dateEvent, event->label);
     mysql_query(db, query);
     char query2[] = "select last_insert_id()";
     mysql_query(db, query2);
     result = mysql_store_result(db);
     row = mysql_fetch_row(result);
     event->id = atoi(row[0]);
}

User *getUsers(MYSQL *db)
{
     char query[] = "select * from user";
     User *userTable =malloc(100 * sizeof(User));
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     unsigned int i = 0;
     unsigned int num_champs = 0;
     unsigned long *lengths;
     mysql_query(db, query);
     result = mysql_store_result(db);
     num_champs = mysql_num_fields(result);
     while ((row = mysql_fetch_row(result))){
          lengths = mysql_fetch_lengths(result);
          sprintf(userTable[i].firstName, "%s", row[1]);
          sprintf(userTable[i].lastName, "%s", row[2]);
          sprintf(userTable[i].rule, "%s", row[3]);
          sprintf(userTable[i].email, "%s", row[4]);
          sprintf(userTable[i].password, "%s", row[5]);
          userTable[i].id = atoi(row[0]);
          i++;
      }
      return userTable;
}
Ticket *createTicket(MYSQL *db,Ticket *ticket, Event * event, User *user)
{
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     int i = 0;
     char query[1000];
     sprintf(query, "insert into ticket (use_id, eve_id, number, date_ticket) values(\"%d\", \"%d\", \"%d\",NOW())", user->id, event->id, ticket->number);
     mysql_query(db, query);
     char query2[] = "select last_insert_id()";
     mysql_query(db, query2);
     result = mysql_store_result(db);
     row = mysql_fetch_row(result);
     ticket->id = atoi(row[0]);
     ticket->user = user;
     ticket->event= event;
     return ticket;
}

void createReservation(MYSQL * db, User * user, Place *  place){
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     int i = 0;
     char query[1000];
     sprintf(query, "insert into reserver (use_id, pla_id) values(\"%d\", \"%d\")", user->id, place->id);
     mysql_query(db, query);
}

void createCommander(MYSQL * db, User * user, Plat * plat){
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     int i = 0;
     char query[1000];
     sprintf(query, "insert into commander (use_id, pla_id) values(\"%d\", \"%d\")", user->id, plat->id);
     mysql_query(db, query);
}

Plat * createPlat(MYSQL * db, Plat *  plat, Event * event){
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     int i = 0;
     char query[1000];
     sprintf(query, "insert into plat (eve_id, label) values(\"%d\", \"%s\")", event->id, plat->label);
     mysql_query(db, query);
     char query2[] = "select last_insert_id()";
     mysql_query(db, query2);
     result = mysql_store_result(db);
     row = mysql_fetch_row(result);
     plat->id = atoi(row[0]);
     plat->event = event;
     return plat;
}

Place * createPlace(MYSQL * db, Place *  place, Event * event){
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     int i = 0;
     char query[1000];
     sprintf(query, "insert into place (eve_id, number) values(\"%d\", \"%d\")", event->id, place->number);
     mysql_query(db, query);
     char query2[] = "select last_insert_id()";
     mysql_query(db, query2);
     result = mysql_store_result(db);
     row = mysql_fetch_row(result);
     place->id = atoi(row[0]);
     place->event = event;
     return place;
}

Session * createSession(MYSQL * db,Session * session,  Event *  event){
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     int i = 0;
     char query[1000];
     sprintf(query, "insert into session (eve_id, name, date_session) values(\"%d\", \"%s\",\"%s\")", event->id, session->name, session->dateSession);
     mysql_query(db, query);
     char query2[] = "select last_insert_id()";
     mysql_query(db, query2);
     result = mysql_store_result(db);
     row = mysql_fetch_row(result);
     session->id = atoi(row[0]);
     session->event = event;
     return session;
}

Film * createFilm(MYSQL * db,Film * film,  Session *  session){
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     int i = 0;
     char query[1000];
     sprintf(query, "insert into film (ses_id, titre, description, auteur) values(\"%d\", \"%s\",\"%s\", \"%s\")", session->id, film->titre, film->description, film->auteur);
     mysql_query(db, query);
     char query2[] = "select last_insert_id()";
     mysql_query(db, query2);
     result = mysql_store_result(db);
     row = mysql_fetch_row(result);
     film->id = atoi(row[0]);
     film->session = session;
     return film;
}


Event *updateEvent(MYSQL *db, Event *event)
{
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     int i = 0;
     char query[1000];
     sprintf(query, "update event set type=\"%s\", place=\"%s\", date_event=\"%s\", label=\"%s\" where id=%d", event->type, event->lieu, event->dateEvent, event->label, event->id);
     mysql_query(db, query);
     return event;
}

void deleteEvent(MYSQL *db, Event * event){
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     int i = 0;
     char query[1000];
     sprintf(query, "delete from event where id=%d", event->id);
     mysql_query(db, query);
} 

Plat ** getPlatByEventId(MYSQL *db, Event * event){
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     unsigned int i = 0;
     unsigned int num_champs = 0;
     unsigned long *lengths;
     char query[1000];
     Plat **platTable = malloc(100 * sizeof(Plat*));
     sprintf(query, "select * from plat inner join event on plat.eve_id=event.id where event.id=%d", event->id);
     mysql_query(db, query);
     result = mysql_store_result(db);
     num_champs = mysql_num_fields(result);
     while ((row = mysql_fetch_row(result))){
          Plat * plat = malloc(100 * sizeof(Plat));
          lengths = mysql_fetch_lengths(result);
          sprintf(plat->label, "%s", row[2]);
          plat->id = atoi(row[0]);
          plat->event = event;
          platTable[i] = plat;
          i++;
      }
     return platTable;   
}

Session ** getSessionByEventId(MYSQL *db, Event * event){
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     unsigned int i = 0;
     unsigned int num_champs = 0;
     unsigned long *lengths;
     char query[1000];
     Session **sessionTable =malloc(100 * sizeof(Session*));
     sprintf(query, "select * from session inner join event on session.eve_id=event.id where event.id=%d", event->id);
     mysql_query(db, query);
     result = mysql_store_result(db);
     num_champs = mysql_num_fields(result);
     while ((row = mysql_fetch_row(result))){
          Session * session = malloc(100 * sizeof(Session));
          lengths = mysql_fetch_lengths(result);
          sprintf(session->name, "%s", row[2]);
          sprintf(session->dateSession, "%s", row[3]);
          session->id = atoi(row[0]);
          // sessionTable[i]->film=getFilmBySessionId(db, session);
          session->event = event;
          sessionTable[i] = session;
          i++;
      }
     return sessionTable;   
}
Place ** getPlaceByEventId(MYSQL *db, Event * event){
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     unsigned int i = 0;
     unsigned int num_champs = 0;
     unsigned long *lengths;
     char query[1000];
     Place **placeTable =malloc(100 * sizeof(Place*));
     sprintf(query, "select * from place inner join event on place.eve_id=event.id where event.id=%d", event->id);
     mysql_query(db, query);
     result = mysql_store_result(db);
     num_champs = mysql_num_fields(result);
     while ((row = mysql_fetch_row(result))){
          Place * place = malloc(100 * sizeof(Place));
          lengths = mysql_fetch_lengths(result);
          place->number= atoi(row[2]);
          place->id = atoi(row[0]);
          place->event = event;
          placeTable[i] = place;
          i++;
      }
     return placeTable;   
}
Ticket * getTicketByUserId(MYSQL *db, User * user, Event **event){
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     unsigned int i = 0;
     unsigned int num_champs = 0;
     unsigned long *lengths;
     char query[1000];
     Ticket *ticketTable =malloc(100 * sizeof(Ticket));
     sprintf(query, "select * from ticket inner join user on ticket.use_id=user.id where user.id=%d", user->id);
     mysql_query(db, query);
     result = mysql_store_result(db);
     num_champs = mysql_num_fields(result);
     while ((row = mysql_fetch_row(result))){
          lengths = mysql_fetch_lengths(result);
          ticketTable[i].number= row[3];
          ticketTable[i].id = atoi(row[0]);
          sprintf(ticketTable[i].dateTicket, "%s", row[4]);
          ticketTable[i].user= user;
          for(int j =0; j <100; j++){
               if(event[j]!=NULL && event[j]->id==row[2]){
                    ticketTable[i].event= event[j];
                    break;
               }
          }
          i++;
      }
     return ticketTable;   
}
Event * getEvents(MYSQL *db){
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     unsigned int i = 0;
     unsigned int num_champs = 0;
     unsigned long *lengths;
     char query[1000];
     Event *eventTable =malloc(100 * sizeof(Event));
     sprintf(query, "select * from event");
     mysql_query(db, query);
     result = mysql_store_result(db);
     num_champs = mysql_num_fields(result);
     while ((row = mysql_fetch_row(result))){
          lengths = mysql_fetch_lengths(result);
          eventTable[i].id = atoi(row[0]);
          sprintf(eventTable[i].type, "%s", row[1]);
          sprintf(eventTable[i].lieu, "%s", row[2]);
          sprintf(eventTable[i].dateEvent, "%s", row[3]);
          sprintf(eventTable[i].label, "%s", row[4]);
          eventTable[i].place = getPlaceByEventId(db, &eventTable[i]);
          eventTable[i].plat = getPlatByEventId(db, &eventTable[i]);
          eventTable[i].session = getSessionByEventId(db, &eventTable[i]);
          i++;
      }
     return eventTable;   
}

Film ** getFilmBySessionId(MYSQL *db, Session * session){
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     unsigned int i = 0;
     unsigned int num_champs = 0;
     unsigned long *lengths;
     char query[1000];
     Film **filmTable =malloc(100 * sizeof(Film*));
     sprintf(query, "select * from film inner join session on film.ses_id=session.id where session.id=%d", session->id);
     mysql_query(db, query);
     result = mysql_store_result(db);
     num_champs = mysql_num_fields(result);
     while ((row = mysql_fetch_row(result))){
          Film * film;
          lengths = mysql_fetch_lengths(result);
          sprintf(film->titre, "%s", row[2]);
          sprintf(film->description, "%s", row[3]);
          sprintf(film->auteur, "%s", row[4]);
          film->id = atoi(row[0]);
          film->session = session;
          filmTable[i] = film;
          i++;
      }
     return filmTable;   
}


bool authentification(MYSQL * db, User * user){
     MYSQL_RES *result = NULL;
     MYSQL_ROW row;
     unsigned int i = 0;
     unsigned int num_champs = 0;
     unsigned long *lengths;
     char query[1000];
     sprintf(query, "select * from user where email=\"%s\" and password=\"%s\"", user->email, user->password);
     mysql_query(db, query);
     result = mysql_store_result(db);
     num_champs = mysql_num_fields(result);
     bool isAuth = false;
     while ((row = mysql_fetch_row(result))){
          isAuth= true;
      }
     return isAuth;
}