#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "list.h"
#include "list.c"


typedef struct {
  int id;
  char descripcion[400];
  int prioridad;  // 1=Alto, 2=Medio, 3=Bajo
  char hora[6];   // formato HH:MM
} Ticket;

int esNumeroValido(const char* cadena) {
  int largo = strlen(cadena);
  if (largo != 1) return 0;  // solo se acepta una opción (1 carácter)

  return isdigit(cadena[0]); // verifica que sea un dígito
}

void presioneTeclaParaContinuar() {
    printf("\nPresione ENTER para continuar...");
    getchar(); // Limpia el '\n' pendiente
    getchar(); // Espera ENTER
  }
  
void mostrarMenuPrincipal() 
  {
    puts("========================================");
    puts("         Sistema de Tickets");
    puts("========================================");
  
    puts("1) Registrar ticket");
    puts("2) Mostrar lista de tickets");
    puts("3) procesar ticket");
    puts("4) buscar ticket por ID");
    puts("5) Salir");
  }
  
void registrar_ticket(List *tickets1, List *tickets2, List *tickets3) {
  printf("Registrar nuevo ticket\n");
  
  Ticket *nuevo = malloc(sizeof(Ticket));
  if (nuevo == NULL) {
    printf("Error al asignar memoria para el ticket.\n");
    return;
  }
  
  printf("Ingrese su ID: ");
  scanf("%d", &nuevo->id);
  getchar(); // limpiar newline
  
  printf("Ingrese descripcion: ");
  fgets(nuevo->descripcion, sizeof(nuevo->descripcion), stdin);
  nuevo->descripcion[strcspn(nuevo->descripcion, "\n")] = '\0';
  
  printf("Ingrese la prioridad del ticket(1 = Alto, 2 = Medio, 3 = Bajo): ");
  scanf("%d", &nuevo->prioridad);

  if(nuevo->prioridad == 1) pushBack(tickets1, nuevo);
  
  if(nuevo->prioridad == 2)pushBack(tickets2, nuevo);

  if(nuevo->prioridad == 3)pushBack(tickets3, nuevo);
  
  printf("Ticket registrado correctamente.\n");
}

void mostrar_lista_tickets(List *tickets1, List *tickets2, List *tickets3) {
    if (tickets1   == NULL || tickets1->head == NULL) 
    {
      printf("No hay tickets registrados de prioridad Alta.\n");
    }
    else
    {
      printf("Lista de tickets de prioridad Alta:\n");
      Node *current = tickets1->head;
      while (current != NULL) {
        Ticket *ticket1 = (Ticket *)current->data;
        printf("ID: %d, Descripcion: %s, Prioridad: %d\n", ticket1->id, ticket1->descripcion, ticket1->prioridad);
        current = current->next;
      }
    }
    if (tickets2   == NULL || tickets2->head == NULL) 
    {
      printf("No hay tickets registrados de prioridad Media.\n");
    }
    else 
    {
      printf("Lista de tickets de prioridad Media:\n");
      Node *current = tickets2->head;
      while (current != NULL) {
        Ticket *ticket2 = (Ticket *)current->data;
        printf("ID: %d, Descripcion: %s, Prioridad: %d\n", ticket2->id, ticket2->descripcion, ticket2->prioridad);
        current = current->next;
      }
    }
    if (tickets3   == NULL || tickets3->head == NULL) 
    {
      printf("No hay tickets registrados de prioridad Baja.\n");
    }
    else 
    {
      printf("Lista de tickets de prioridad Baja:\n");
      Node *current = tickets3->head;
      while (current != NULL) {
        Ticket *ticket3 = (Ticket *)current->data;
        printf("ID: %d, Descripcion: %s, Prioridad: %d\n", ticket3->id, ticket3->descripcion, ticket3->prioridad);
        current = current->next;
      }
    }
    if (tickets1 == NULL && tickets2 == NULL && tickets3 == NULL) 
    {
      printf("No hay tickets registrados.\n");
      return;
    }
}

void procesar_ticket(List *tickets1, List *tickets2, List *tickets3) {
    if (tickets1->head == NULL && tickets2->head == NULL && tickets3->head == NULL) {
      printf("No hay tickets para procesar.\n");
      return;
    }
  
    Ticket *ticket = NULL;
    if (tickets1->head != NULL) {
      ticket = (Ticket *)popFront(tickets1);
    } else if (tickets2->head != NULL) {
      ticket = (Ticket *)popFront(tickets2);
    } else if (tickets3->head != NULL) {
      ticket = (Ticket *)popFront(tickets3);
    }
  
    if (ticket != NULL) {
      printf("Ticket procesado: ID: %d, Descripcion: %s, Prioridad: %d\n", ticket->id, ticket->descripcion, ticket->prioridad);
      free(ticket); // Liberar memoria del ticket procesado
    }
  }

void buscar_ticket_por_ID(List *tickets1, List *tickets2, List *tickets3) {
  int id;
  printf("Ingrese el ID del ticket a buscar: ");
  scanf("%d", &id);
  
  Ticket *ticket = NULL;
  Node *current = tickets1->head;
  while (current != NULL) 
  {
    Ticket *t = (Ticket *)current->data;
    if (t->id == id) 
    {
      ticket = t;
      break;
    }
    current = current->next;
  }
  
  if (ticket == NULL) 
  {
    current = tickets2->head;
    while (current != NULL) 
    {
      Ticket *t = (Ticket *)current->data;
      if (t->id == id) 
      {
        ticket = t;
        break;
      }
      current = current->next;
    }
  }
  
  if (ticket == NULL) 
  {
    current = tickets3->head;
    while (current != NULL) {
      Ticket *t = (Ticket *)current->data;
      if (t->id == id) {
        ticket = t;
        break;
      }
      current = current->next;
    }
  }
  
  if (ticket != NULL) 
  {
    printf("Ticket encontrado: ID: %d, Descripcion: %s, Prioridad: ", ticket->id, ticket->descripcion);
    if (ticket->prioridad == 1) 
    {
      printf("Alta\n\n");
    } else if (ticket->prioridad == 2) 
    {
      printf("Media\n\n");
    } else if (ticket->prioridad == 3) 
    {
      printf("Baja\n\n");
    }
  } 
  else printf("No se encontro el ticket con ID: %d\n", id);
}



int main() {
  char opcion[10]; // permite ingresar texto como "11111111"
  List *tickets1 = crearList();
  List *tickets2 = crearList();
  List *tickets3 = crearList();

  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opcion: ");
    scanf(" %9s", opcion);

    if (!esNumeroValido(opcion) || opcion[0] < '1' || opcion[0] > '5') {
      printf("Opcion invalida. Intente de nuevo.\n");
      presioneTeclaParaContinuar();
      continue;
    }

    switch (opcion[0]) {
      case '1':
        registrar_ticket(tickets1, tickets2, tickets3);
        break;
      case '2':
        mostrar_lista_tickets(tickets1, tickets2, tickets3);
        break;
      case '3':
        procesar_ticket(tickets1, tickets2, tickets3);
        break;
      case '4':
        buscar_ticket_por_ID(tickets1, tickets2, tickets3);
        break;
      case '5':
        puts("Saliendo del sistema de tickets...");
        break;
      default:
        puts("Opcion no valida. Por favor, intente de nuevo.");
    }

    presioneTeclaParaContinuar();

  } while (opcion[0] != '5');

  clean(tickets1); clean(tickets2); clean(tickets3);
  free(tickets1); free(tickets2); free(tickets3);

  return 0;
}