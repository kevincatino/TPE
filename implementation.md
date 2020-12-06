# Estructuras

### arbolesCDT

- **Lista1 de barrios** en orden de densidad x habitantes (queda vacía hasta llamar a la función correspondiente)
    - Nombre del barrio
    - Árboles x habitantes
- **dim1**
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
    - Población
    - Total de árboles
    - Calle con más árboles y cantidad
    - **Vector de calles** sin orden
        - Nombre de calle
        - Cantidad de árboles por calle
    - **dimVec2**
- **dim23**

### TQ1

- Nombre de barrio
- Densidad de árboles x habitante

### TQ23

- Nombre de barrio
- Árbol más popular
- Calle con más árboles

### TQ4

- Nombre de árbol
- Diámetro min
- Diámetro max

(definir todos en .h)

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
4. Nos faltarÍa una función que genere la lista de barrios en orden de densidad x habitante
5. Todas las funciones devuelven vectores dinámicos que en el front-end las pasamos al archivo de respuesta de cada Query.

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