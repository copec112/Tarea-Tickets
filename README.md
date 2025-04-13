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

- ✏️ **Modificar un ticket**: Permite cambiar la información de un ticket específico (nombre, descripción o prioridad).

## Compilación

Para compilar el programa, usa el siguiente comando (desde el directorio donde está el código fuente):

```bash
gcc -o ticket_system main.c list.c -std=c99
