//programa en C para consultar los datos de la base de datos
//Incluir esta libreria para poder hacer las llamadas en shiva2.upc.es
//#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas 
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	int fecha;
	char nombre[20];
	char password[20];
	char consulta [80];
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexiￃﾳn: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//inicializar la conexion
	conn = mysql_real_connect (conn, "localhost","user", "pass", "personas",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexiￃﾳn: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}

	err=mysql_query (conn, "SELECT * FROM Partidas");
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
		mysql_errno(conn), mysql_error(conn));
		exit (1);
	}

	resultado = mysql_store_result (conn);

	row = mysql_fetch_row (resultado);

	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		while (row !=NULL) {

			fecha = atoi (row[2]);
			printf ("Nombre: %s, password: %s \n", row[0], row[1]);
			// obtenemos la siguiente fila
			row = mysql_fetch_row (resultado);
	}
		//recogemos el resultado de la consulta 
		resultado = mysql_store_result (conn); 
		row = mysql_fetch_row (resultado);
		if (row == NULL)
			printf ("No se han obtenido datos en la consulta\n");
		else

			printf ("Numero de partidas en febrero: %d\n", row[2] );
		// cerrar la conexion con el servidor MYSQL 
		mysql_close (conn);
		exit(0);
}

