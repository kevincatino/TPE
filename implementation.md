# Estructuras

### arbolesCDT

- **Lista4 de árboles** en orden alfabético
    - Nombre del árbol
    - min y máx diámetro
- **dim4**
- **Lista23 de barrios** en orden alfababético
    - Nombre del barrio
    - Árbol más popular por barrio
    - **Vector de árboles** sin orden
        - Especie de árbol
        - Cantidad de árboles por especie
    - **dimVec1**
    - Calle con más árboles y cantidad
    - **Vector de calles** sin orden
        - Nombre de calle
        - Cantidad de árboles por calle
    - **dimVec2**
- **dim23**

### TQ23

- Nombre de barrio
- Árbol más popular
- Calle con más árboles
- Población
- Total de árboles

### TQ4

- Nombre de árbol
- Diámetro min
- Diámetro max

(definir todos en .h)

## Q1CDT

- **Lista1 de barrios** en orden de densidad x habitantes (queda vacía hasta llamar a la función correspondiente)
    - Nombre del barrio
    - Árboles x habitantes
- **dim1**

### TQ1

- Nombre de barrio
- Densidad de árboles x habitante

(definir en .h)

# Memoria que debe ser liberada

- **Dentro del ADT**
    - Nodos de lista1
    - Nodos de lista2
    - Nodos de lista3
    - Vector de arboles
    - Vector de calles
- **Dentro del main**
    - Vectores dinámico del Query1
    - Vector dinámico del Query2y3
    - Vector dinámico del Query4

# Orden de uso del ADT

1. Agregamos todos los barrios
2. Agregamos todos los arboles
3. Con esto logramos cumplir los Querys 2,3,4 dentro de la estructura (el Query2 y 3 pueden devolverse en un mismo vector porque el orden de barrios es el mismo)
4. Utilizamos el vector de las Querys23 para agregar los barrios al Q1ADT.
5. Q1ADT agrega los elementos de forma tal que el orden sea el que requiere la Query1, y la función correspondiente devuelve un vector ordenado de tipo TQ1.
6. Todas las funciones devuelven vectores dinámicos que en el front-end las pasamos al archivo de respuesta de cada Query.

# Funciones

- New
- AddHood
- AddTree
- SolveQ1
- SolveQ23
- SolveQ4
- Free
    - Lists
    - Vectors