# TP FINAL PI

El programa consiste en dos ejecutables distintos que leen datasets en formato CSV para dos ciudades (CABA y Vancouver). Estos contendran informacion acerca de la cantidad de arboles y habitantes por barrio. 
Estos ejecutables crearan archivos con datos que respondan las siguientes queries:

	1. Total de arboles por habitante
	2. Especie de arbol mas popular por barrio
	3. Calle con mas arboles por barrio
	4. Minimo y maximo diametro por especie de arbol


## Compilacion
Lo primero que debe hacer es colocarse en el directorio donde se encuentran los archivos .c y .h. Dependiendo de cuales ejecutables quiera generar, escriba los siguientes comandos en la terminal:
- Ambos: make all
- CABA: make BUE
- Vancouver: make VAN

En el caso de querer eliminar los ejecutables creados:
- make clean


## Ejecucion
Una vez que los ejecutables fueron generados, estos se pueden invocar de la siguiente forma (en el caso que los archivos .csv se encuentran en el mismo directorio):

./arbolesADTBUE arbolesBUE.csv barriosBUE.csv

./arbolesADTVAN arbolesVAN.csv barriosVAN.csv

**IMPORANTE:** Si los archivos de datos no se encuentran en el mismo directorio debe invocarse agregando los paths correspondientes. Tambien debe respetars el orden de los archivos para obtener el resultado esperado. 


## Post ejecucion
En la salida estandar se debera ver un mensaje que diga 
"The files were created successfully".

**IMPORANTE:** Si este texto no aparece es porque hubo un error. De ser este el caso, tambien aparecera un mensaje apropiado explicando que fue lo que sucedio. 

Ademas, en el mismo directorio donde se ejecuto el programa se habran creado los siguientes archivos:
- query1.csv
- query2.csv
- query3.csv
- query4.csv

Cada uno estos tendran la informacion correspondiente a cada query.
