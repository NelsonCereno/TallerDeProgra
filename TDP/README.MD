Solución del Problema de los Bidones
Nelson Cereño

Para la persona que revise este codigo trate de ser lo mas pragmatico posible, realmente me costo mucho esta experiencia de laboratorio, asi que espero que se logre entender bien.

Descripción General

Este programa resuelve el problema de los bidones, donde se busca alcanzar un estado objetivo específico de agua en varios bidones, partiendo de un estado inicial. El programa utiliza una combinación de estructuras de datos y algoritmos para explorar posibles soluciones y encontrar el camino óptimo hacia el estado objetivo.

Funcionamiento del Programa

Entrada del Usuario: El programa solicita al usuario que ingrese el nombre de un archivo que contiene las capacidades de los bidones y el estado objetivo.

Lectura del Archivo: Utiliza la función readFile para leer las capacidades de los bidones y el estado objetivo desde el archivo especificado.

Inicialización: Crea un objeto Jug con las capacidades de los bidones, el estado objetivo y el número de bidones.

Resolución del Problema: Llama al método solve del objeto Jug para encontrar una solución al problema.

Medición del Tiempo: Mide el tiempo de ejecución del método solve y lo imprime en milisegundos.

Salida: Imprime el estado solución si se encuentra, o un mensaje indicando que no se encontró solución.

Ejecución del Programa

Para ejecutar el programa, compílelo utilizando el Makefile proporcionado y ejecute el archivo generado. A continuación, ingrese el nombre del archivo que contiene los datos de entrada cuando se le solicite.

Ejecucion

make all
./main

Si desea probar casa uno de los test facilitados aqui quedan sus codigos

./test_Utils
./test_State
./test_Queue
./test_Jug
./test_HashTable

Desafíos y Limitaciones

El desarrollo de este programa presentó varios desafíos significativos. A pesar de los esfuerzos realizados, no se logró implementar una solución rápida y eficiente para todos los casos. El programa funciona correctamente para casos simples, pero se tarda mucho en resolver casos de dificultad media y alta.

Intentos y Estrategias

Se intentaron varias estrategias para optimizar el rendimiento del programa, 

incluyendo:

Optimización de Estructuras de Datos: Se utilizaron tablas hash (HashTable) para manejar los estados abiertos y cerrados, con el objetivo de acelerar las operaciones de búsqueda e inserción.

Heurísticas: Se implementaron heurísticas para guiar la búsqueda hacia el estado objetivo de manera más eficiente.

Algoritmos de Búsqueda: Se exploraron diferentes algoritmos de búsqueda, como la búsqueda en anchura y la búsqueda A*.

Resultados
A pesar de estos esfuerzos, el programa no logró resolver casos de dificultad media y alta en un tiempo razonable. La complejidad del problema y la explosión combinatoria de estados posibles hicieron que las soluciones implementadas no fueran suficientes para manejar casos más complejos.

Conclusión
El programa representa un esfuerzo considerable para resolver el problema de los bidones, pero aún presenta limitaciones significativas en términos de rendimiento y eficiencia.

A modo de observacion personal si resulto un completo desafio implementar este problema tan complicado sumandole el hecho de intentar buscar una heuristica optima, todo esto en un lenguaje en el que no estoy del todo familiarizado...

Espero que para futuras entregas mi rendimiento mejore, agradezco la atencion.