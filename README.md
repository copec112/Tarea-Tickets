# Sistema de Gestión de Tickets de Soporte Técnico

Este proyecto implementa un sistema de gestión de tickets de soporte técnico en lenguaje C. Los tickets son organizados y procesados en base a su prioridad (Alta, Media, Baja), utilizando listas simplemente enlazadas genéricas (basadas en `void*`) para mayor flexibilidad.
## Estructura del proyecto

- `main.c`: Programa principal que contiene el menú y la lógica de interacción con el usuario.
- `list.c` y `list.h`: Implementación de listas simplemente enlazadas genéricas.
- `ticket.h`: Estructura del ticket y funciones asociadas (crear, mostrar, comparar, etc.).

## Funcionalidades principales

- 📌 **Registrar ticket**: Permite al usuario ingresar un nuevo ticket con los siguientes campos:
  - ID único
  - Nombre del cliente
  - Descripción del problema
  - Prioridad (Alta, Media, Baja)

- 🔎 **Buscar ticket por ID**: Muestra el detalle de un ticket según su identificador.

- 🛠️ **Procesar ticket**: Atiende el ticket más prioritario disponible (Alta > Media > Baja).

- 🧾 **Mostrar todos los tickets**: Lista todos los tickets organizados por prioridad.


## posibles fallas
no se asegura, que el ID de la persona solo sea numerico, si este pone su nombre, habira fallas.
errores ortograficos, esto se debe, que el programa no deja colocar tildes.
## Compilación

Para compilar el programa, usa los siguiente comando (desde el directorio donde está el código fuente) :

````bash
gcc -o ticket_system main.c list.c -std=c99
````
para luego ocupar
````
./ticket_system

````
## ejemplo del uso del programa

========================================
         Sistema de Tickets
========================================
1) Registrar ticket
2) Mostrar lista de tickets
3) procesar ticket
4) buscar ticket por ID
5) Salir
Ingrese su opcion: 1
Registrar nuevo ticket
Ingrese su ID: 234
Ingrese descripcion: Hola, no se como ocupar hithub 
Ingrese la prioridad del ticket(1 = Alto, 2 = Medio, 3 = Bajo): 1
Ticket registrado correctamente.

Presione ENTER para continuar...
========================================
         Sistema de Tickets
========================================
1) Registrar ticket
2) Mostrar lista de tickets
3) procesar ticket
4) buscar ticket por ID
5) Salir
Ingrese su opcion: 3
Ticket procesado: ID: 234, Descripcion: Hola, no se como ocupar hithub , Prioridad: 1

Presione ENTER para continuar...
========================================
         Sistema de Tickets
========================================
1) Registrar ticket
2) Mostrar lista de tickets
3) procesar ticket
4) buscar ticket por ID
5) Salir
Ingrese su opcion: 2
No hay tickets registrados de prioridad Alta.
No hay tickets registrados de prioridad Media.
No hay tickets registrados de prioridad Baja.

Presione ENTER para continuar...
========================================
         Sistema de Tickets
========================================
1) Registrar ticket
2) Mostrar lista de tickets
3) procesar ticket
4) buscar ticket por ID
5) Salir
Ingrese su opcion: 5
Saliendo del sistema de tickets...

Presione ENTER para continuar...
