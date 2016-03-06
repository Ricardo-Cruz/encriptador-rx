# encriptador-rx

Éste programa encripta y desencripta textos con el alfabeto inglés de 26 letras
(no incluye la ñ del español).

Aún debe tener varios fallos pero cumple con los propositos para lo que fue hecho.

Sólo funciona con minusculas y sin ñ.

Hecho en GNU/Linux Emacs

Compilación:

$g++ encriptador.cpp -o encriptador

Uso:


Para encriptar:

$./encriptador encriptar b l m letra mensaje para encriptar

Para que regrese valores númericos:

$./encriptador encriptar b lambda modulo numeros 0 1 2 3 4 5 6

Donde:

b es primo relativo de m

P es algún caracter del texto.

C es el caracter resultante de cifrar P.

C = ( b * P ) + l (mod m)

Ejemplo:
$./encriptador-rx encriptar 15 15 26 numero mensaje para encriptar
n x c z p u x g p k p x c t k f g o p k 

$./encriptador encriptar b lambda modulo numero 0 1 2 3 4 5 6
13 23 2 25 15 20 23 6 15 10 15 23 2 19 10 5 6 14 15 10 


Para desencriptar:

$./encriptador desencriptar b lambda modulo letra mensaje para desencriptar

Para que regrese valores númericos:

$./encriptador desencriptar b lambda modulo numeros 0 1 2 3 4 5 6 


Donde:

x es b elevado a la función indicatriz de Euler aplicada a m

P es algún caracter del texto.

C es el caracter resultante de cifrar P.

P = x * ( C - l ) (mod m)

Ejemplo:
./encriptador desencriptar 15 15 26 letra 13 23 2 25 15 20 23 6 15 10 15 23 2 19 10 5 6 14 15 10 

m e n s a j e p a r a e n c r i p t a r 

./encriptador desencriptar 15 15 26 letra 13 23 2 25 15 20 23 6 15 10 15 23 2 19 10 5 6 14 15 10 

12 4 13 18 0 9 4 15 0 17 0 4 13 2 17 8 15 19 0 17 

