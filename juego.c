#include <stdio.h>
#include <stdlib.h>

// Matriz principal de escenarios
int contenedor[18][18] = {
    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 00
    {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // 01 
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 02 
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0}, // 03 
    {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 04 
    {0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 05 
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0}, // 06 
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // 07 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0}, // 08 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0}, // 09 
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, // 10 
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0}, // 11 
    {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 12 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0}, // 13 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0}, // 14 
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1}, // 15 
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}, // 16 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  // 17 
  };

int main(void) {
  // Matriz de escenas
   char escenas[18][100] = {
        {"inicio"},
        {"01. Cambiarse"},
        {"02. Tomar agua"},
        {"03. Desayunar"},
        {"04. Meditar"},
        {"05. Hacer otra cosa"},
        {"06. Revisase el celular"},
        {"07. Jugar con la consola"},
        {"08. Jugar Mario Kart"},
        {"09. Jugar FIFA"},
        {"10. No jugar nada"},
        {"11. Ir a sala"},
        {"12. Leer libro"},
        {"13. Sentarse en la cama"},
        {"14. Ver la televisión"},
        {"15. Regresar a la habitación"},
        {"16. No hacer nada"},
        {"17. Olvidar todo e ir a dormir"} 
    };
  // Matriz de escenarios
  char escenarios[18][100] = {
        {"Te acabas de levanta, ¿qué haces primero?"},
        {"Te cambiaste"},
        {"Tomaste agua, ¿ahora qué haces?"},
        {"Comiste el desayuno"},
        {"Meditaste 15 minutos"},
        {"¿Qué quieres hacer ahora?"},
        {"Revisaste el celular, no encontraste nada"},
        {"¿Qué juego jugarás ahora?"},
        {"Jugaste Mario Kart"},
        {"Jugaste al FIFA."},
        {"No jugaste nada."},
        {"Decides irte a la sala"},
        {"Te pusiste a leer un libro"},
        {"Te sentaste en la cama"},
        {"Estas viendo la televisión"},
        {"Estas en tu habitación"},
        {"Perdiste tu valioso tiempo"},
        {"¿Deseas abandonar y regresar a dormir?"} 
    };

  int acciones[50],i = 0,r = 0, seleccion,s_repetida = 0; // Variables para almacenar repuestas del usuario
  
  do { // ciclo para recorrer las filas (escenas)
    if (seleccion != 5 || seleccion != 14) { // arreglo de opciones ya elegidas
        acciones[r] = seleccion;
        printf("--------------------------------------------\n");
        r++;
    }
    if (i == 0) { // Muestra el escenario de inicio
      printf("%s\n", escenarios[i]); 
      printf("--------------------------------------------\n");
    }
    for (int j = 0; j < 18; j++) { // ciclo para recorer las columnas (opciones)
      if (contenedor[i][j] > 0) {
        printf("%s\n", escenas[j]);
      }
    }
    if (seleccion == 17){ // Si decide irse, imprimir acciones asociadas
        printf("0.  No\n18. Si\n");
    }

    s_repetida = acciones[r]; // te lleva a la escena elejida
    printf("--------------------------------------------\n");
    printf("Opcion: "); scanf(" %d", &seleccion); // Elijes tu opcion
    system("clear"); // limpia la pantalla
   
    if (seleccion < 0 || seleccion > 18) {  // Si tu repuesta no esta en las opciones mostradas
      printf("--------------------------------------------\n");
      printf("Esa opción no existe\n");
      printf("--------------------------------------------\n");
    }
    for (int u = 0; u <= r; u++) { // Ciclo para revisa las acciones anteriores y verifica si ya fue elegida
      if (acciones[u] == seleccion) {
        printf("--------------------------------------------\n");
        printf("No se pueden repetir las opciones");
        printf("\n-------------------------------------\n");
        i = s_repetida;
      }
      else
        i = seleccion;
    }
    printf("%s\n", escenarios[i]); // imprime los ecenarios
  } while(i < 18);

  if (seleccion == 18){ // Mensaje de despedida
    system("clear");
    printf("--------------------------------------------\n");
    printf("¡Buenas noches, hasta la próxima!");
    printf("\n-------------------------------------\n");
  }
  return 0;
}