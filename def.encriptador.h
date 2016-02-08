#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <stdbool.h>

using namespace std;

bool obtenerPeticion( char* eleccion);
string encriptarMensaje(int entradas, char* parametros[]);
string desencriptarMensaje( int entradas, char* parametros[]);
int aplicarModulacion( int numero, int modulo );
string agregarAMensaje ( int caracterSimple , bool enLetra );
int obtenerLambda( char* caracter  );
int obtenerB( char* caracter );
int caracterANumero( char* caracter );
int obtenerX(int numero, int modulo);
bool esPrimo( int entero );
int funcionDeEulerParaPrimos( int numero );
int funcionDeEuler( int modulo );
bool sonPrimosRelativos(int n1, int n2);
int mcd(int a,int b);
int obtenerLimite( int entero );
bool esPar(int numero);
string agregarCaracter(char caracter);
int obtenerModulo( char* caracter );
void imprimirMensaje( string mensaje );
bool regresaSiSonIguales( char* texto1, char* texto2 );
bool obtenerPeticionVariable( char* eleccion );
string charToString( char caracter );
string intToString( int caracter );

