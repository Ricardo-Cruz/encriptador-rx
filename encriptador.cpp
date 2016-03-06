// Encriptador-rx
// Copyright (c) 2016 Ricardo Cruz (rcruz at inteligencia-artificial dot net)
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#include "def.encriptador.h"		

int main(int entradas, char* parametros[]) {
  bool quiereEncriptar = obtenerPeticion( parametros[1] );
  string mensajeDeVuelta;
  if ( quiereEncriptar ) {
    mensajeDeVuelta = encriptarMensaje( entradas , parametros );
  } else {
    mensajeDeVuelta = desencriptarMensaje( entradas , parametros );
  }
  imprimirMensaje( mensajeDeVuelta );
  return 0;
}

bool obtenerPeticion( char* eleccion ){
  bool eleccionBooleana;
  char textoEncriptar[9];
  strcpy( textoEncriptar , "encriptar" ); 
  eleccionBooleana = regresaSiSonIguales( textoEncriptar , eleccion );
  return eleccionBooleana;
}

bool regresaSiSonIguales( char* texto1 , char* texto2 ){
  int comparacionDeLongitudes = strcmp( texto1 , texto2 );
  if ( comparacionDeLongitudes < 0 ){
    return false;
  } else if ( comparacionDeLongitudes > 0 ) {
    return false;
  } else {
    return true;
  }
  return true;
}

string encriptarMensaje( int entradas, char* mensaje[] ){
  string mensajeEncriptado = "";
  int lambda, C, b, largoDeCadenaDeCaracteres, i, j, modulo, P;
  char* cadena;
  lambda = obtenerLambda( mensaje[3] );
  b = obtenerB( mensaje[2] );
  modulo = obtenerModulo( mensaje[4]  );
  int suma = 0;
  bool esLetra = obtenerPeticionVariable( mensaje[5]  );
  for ( i = 6 ; i < entradas ; i++ ) {
    largoDeCadenaDeCaracteres = strlen( mensaje[i] );
    cadena = mensaje[ i ];
    for ( j = 0 ; j < largoDeCadenaDeCaracteres ; j++ ) {
      P = cadena[ j ];
      P = P - 97;
      if ( P < 0 ){
	P = 0;
      }
      C = ( b * P ) + lambda;
      C = aplicarModulacion( C , modulo );
      mensajeEncriptado = mensajeEncriptado + agregarAMensaje( C , esLetra  );
    }
  }
  return mensajeEncriptado;
}

bool obtenerPeticionVariable( char* eleccion ){
  bool eleccionBooleana;
  char textoEncriptar[9];
  strcpy( textoEncriptar , "letra" );
  eleccionBooleana = regresaSiSonIguales( textoEncriptar , eleccion );
  return eleccionBooleana;
}

string desencriptarMensaje(int entradas, char* mensaje[]){
  string mensajeDesencriptado = "";
  int C, lambda, b, P, largoDeCadenaDeCaracteres, i, j, x, modulo;
  lambda = obtenerLambda( mensaje[3] );
  b = obtenerB( mensaje[2] );
  modulo = obtenerModulo( mensaje[4]  );
  x = obtenerX( b , modulo );
  bool esLetra = obtenerPeticionVariable( mensaje[5]  );
  char caracter;
  for ( i = 6 ; i < entradas ; i++ ) {
    C = caracterANumero( mensaje[i] );
    P = x * ( C - lambda );
    P = aplicarModulacion( P , modulo );
    mensajeDesencriptado = mensajeDesencriptado + agregarAMensaje( P , esLetra );
  }
  return mensajeDesencriptado;
}

int obtenerX( int numero , int modulo ){
  int num, i, limite;
  if ( esPrimo( modulo ) ) { 
    limite = funcionDeEulerParaPrimos( modulo ) - 1;
  } else {
    limite = funcionDeEuler( modulo ) - 1;
  }
  num = 1;
  for ( i = 0 ; i < limite ; i++ ){
    num = num * numero;
    num = aplicarModulacion( num , modulo);
  }
  return num;
}

bool esPrimo( int entero ){
  return false;
}

int funcionDeEulerParaPrimos( int numero ){
  return numero - 1;
}

int funcionDeEuler( int modulo ){
  int i, m, a, cantidadDePrimos, limite;
  m = modulo;
  cantidadDePrimos = 0;
  for ( i = 1 ; i < modulo ; i++ ){
    if ( sonPrimosRelativos( i , modulo ) ){
      cantidadDePrimos = cantidadDePrimos + 1;
    }
  }
  return cantidadDePrimos;
}

bool sonPrimosRelativos(int n1, int n2){
  int a = mcd(n1,n2);
  bool b;
  if (a == 1){
    b = true;
  } else{
    b = false;
  }
  return b;
}

int mcd(int a,int b){
  return (b == 0)? a : mcd(b, a % b);
}

int obtenerLimite( int entero ){
  if ( esPar( entero ) ){
    return  entero / 2;
  } else {
    return ( (entero - 1) / 2);
  }
}

string agregarAMensaje ( int caracterSimple , bool enLetra ){
  string texto;
  char car;
  int sum;
  if ( enLetra ) {
    sum = caracterSimple + 97;
    car = sum;
    texto = charToString( car );
  }else{
    texto = intToString( caracterSimple );
  }
  return texto + " ";
}

string charToString( char c ){
  stringstream ss;
  string s;
  ss << c;
  ss >> s;
  return s;
}

string intToString( int caracter ){
  string variableDeRetorno;
  stringstream variableDeConversion;
  variableDeConversion << caracter;
  variableDeConversion >> variableDeRetorno;
  return variableDeRetorno;
}

bool esPar(int numero){
  if(numero % 2 == 0){
    return true;
  }else{
    return false;
  }
}

int aplicarModulacion( int numero, int modulo ){
  int num = numero;
  if (num >= 0) {
    while ( num >= modulo ){
      num = num - modulo;
    }
  } else {
    while ( num < 0 ){
      num = num + modulo;
    }
  }
  return num;
}

int obtenerLambda( char* caracter ){
  return caracterANumero( caracter );
}

int obtenerB( char* caracter ){
  return caracterANumero( caracter );
}

int obtenerModulo( char* caracter ){
  return caracterANumero( caracter );
}

int caracterANumero( char* caracter){
  return atoi( caracter  );
}

void imprimirMensaje(string mensaje){
  cout << endl;
  cout << mensaje << endl;
  cout << endl;
}
