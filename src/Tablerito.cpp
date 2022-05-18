#include "Tablerito.h"

Tablerito::Tablerito()
{
	tablerito = new string * [8];
	for (int i = 0; i < 8; i++)
	{
		tablerito[i] = new string[8];
	}
}


void Tablerito::Inicializa()
{
	for (int i = 0; i < 8; i++)   //flias
	{
		for (int j = 0; j < 8; j++)  //coliunns
		{
			tablerito[i][j]="00000";  //FILA I , COLUMNA J
		}
	}

	//FIGURAS NEGRAS

	tablerito[0][0] = "NT18A"; //LA FILA 8 ES EN X=0; LA COLUMNA A ES EN Y=0;
	tablerito[0][1] = "NC18B";
	tablerito[0][2] = "NA18C"; 
	tablerito[0][3] = "ND18D";
	tablerito[0][4] = "NR18E";
	tablerito[0][5] = "NA18F";
	tablerito[0][6] = "NC18G"; 
	tablerito[0][7] = "NT18H";

	//PEONES NEGROS

	for (int i = 0; i < 8; i++)
	{
		tablerito[1][i] = "NP000";
		tablerito[1][i][2] = 49+i;
		tablerito[1][i][3] = '7';
		tablerito[1][i][4] = 65 + i;
	}

	//PEONES BLANCOS

	for (int i = 0; i < 8; i++)
	{
		tablerito[6][i] = "BP000";
		tablerito[6][i][2] = 49 + i;
		tablerito[6][i][3] = '2';
		tablerito[6][i][4] = 65 + i;
	}

	//FIGURAS BLACAS

	tablerito[7][0] = "BT11A"; 
	tablerito[7][1] = "BC11B";
	tablerito[7][2] = "BA11C";
	tablerito[7][3] = "BD11D";
	tablerito[7][4] = "BR11E";
	tablerito[7][5] = "BA11F";
	tablerito[7][6] = "BC11G";
	tablerito[7][7] = "BT11H";

}


//sobrecarga de la funcion localizar pieza 
//te dice que pieza hay en la posicion

string Tablerito::Localizar_pieza(int x, int y)  //con la nomnclatura de la matriz
{
	int fila = x / 10;
	int columna = y / 10;

	return tablerito[fila][columna];
}

string Tablerito::Localizar_pieza(char x, char y) //con la nomenclaturadel tablero
{
	int fila;
	for (int i = 0, j=7 ; i < 8; i++,j--)
	{
		if (x ==49+i)
			fila = j;
	}	
	int columna = y-65;
	return tablerito[fila][columna];
}


//COMPROBAR MOVIMIENTO, TE DEVUELVE UN 1 SI PUEDES MOVER Y UN 0 SI NO PUEDES MOVER
//EL STRING QUE ENTRA ES 

int Tablerito::Comprobar_movimiento(int x, int y)  //COLOR TIPO NUMERO FILA COLUMNA
{
	int fila = x / 10;
	int columna = y / 10;

	if (tablerito[fila][columna][0] == '0') //si no hay fichas
	{
		return 0;
	}
	else if(tablerito[fila][columna][0] == 'B' && tablerito[fila][columna][1] != 'R') //si la ficha que hay es blanca
	{
		return 1;
	}
	else if (tablerito[fila][columna][0] == 'N' && tablerito[fila][columna][1] != 'R') 
	{
		return 2;
	}
	else if(tablerito[fila][columna][0] == 'B' && tablerito[fila][columna][1] == 'R')
	{
		return 3;
		//si es un rey blaco
	}
	else if (tablerito[fila][columna][0] == 'N' && tablerito[fila][columna][1] == 'R')
	{
		return 4;
		//si es un rey negro
	} 
}


//MOVER FICHA EN EL TABLERO

bool Tablerito::Mover(char x, char y, string& pieza)
{
	//a donde mueves
	int fila;
	for (int i = 0, j = 7; i < 8; i++, j--)
	{
		if (x == 49 + i)
			fila = j;
	}
	int columna = y - 65;

	cout << pieza;
	tablerito[fila][columna] = pieza;
	tablerito[fila][columna][3] = x;
	tablerito[fila][columna][4] = y;


	//poner a 0 donde estabas
	
	char fila_anterior = pieza[3];
	char columna_anterior = pieza[4];
	int fila_ant=0;
	int columna_ant=0;

	for (int i = 0, j = 7; i < 8; i++, j--)
	{
		if (fila_anterior == 49 + i)
			fila_ant = j; //bien
		if (columna_anterior == 65 + i)
			columna_ant = i;
	}
	
	

	tablerito[fila_ant][columna_ant] = "00000";
	if (tablerito[fila_ant][columna_ant] == "00000")
		return 1;
	else
		return 0;


}


/*
bool Tablerito::Mover(int x, int y, string& pieza)
{
	int fila = x / 10;
	int columna = y / 10;

	tablerito[fila][columna] = pieza;

	//comprobar
	tablerito[fila][columna][3] = x;
	tablerito[fila][columna][4] = y+97;


	//poner a 0 donde estabas
	char fila_anterior = pieza[3];
	char columna_anterior = pieza[4];
	int fila_ant = 0;
	int columna_ant = 0;
	
		for (int i = 0, j = 7; i < 8; i++, j--)
		{
			if (fila_anterior == 49 + i)
				fila_ant = j;
		}
		
		//columna_ant = columna_anterior - 97;

	tablerito[fila_ant][columna_ant] = "00000";
	if (tablerito[fila_ant][columna_ant] == "00000")
		return 1;
	else
		return 0;



}

*/



ostream& Tablerito::to_string(ostream& o)
{
	for (int i = 0; i < 8; i++)   //flias
	{
		for (int j = 0; j < 8; j++)  //coliunns
		{
			o<<tablerito[i][j]<<" ";
		}
		o << endl;
	}
	return o;
	
}