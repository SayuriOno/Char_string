#include <Arduino.h>

#include <string.h>  //* vai trabalhar com strlen, strcpy, strcat, strcmp, strchr
#include <stdlib.h>  //* atoi


void textoChar();
void textoString();

void setup()
 {
 Serial.begin(9600);
 Serial.println("  ");
 textoChar();
 textoString();
}

void loop() { 
}


void textoChar()
{  //! strlen: ========================================================================================================================

   const char* cidade = "Sao Paulo";
   //! quando eu vejo um * significa que eu estou trabalhando com um endereco 
   Serial.println(cidade);
   int tamanhoTextoCidade = strlen(cidade);
   //! strlen conta os caracteres incluindo o /0 no final


   //! sizeof: ========================================================================================================================

   Serial.print( "comprimento do texto: ");
   Serial.println(tamanhoTextoCidade);
   int tamanhoVariavelCidade = sizeof(cidade);
   //! sizeof vai dizer o tamanho da variavel. 

    Serial.print("espaco ultilizado ");
    Serial.println(tamanhoVariavelCidade);

    //! char com vetor ========================================================================================================================

    char vetorTexto[]= {'s', 'a', 'y','u','r','i'};
    Serial.println(vetorTexto);


  const char* cidade1 = "sao Caetano";
  const char* cidade2 = "sao Caetano";


  //! strcmp: ========================================================================================================================

  if(strcmp(cidade1,cidade2) == 0 )
  //!compara o lexicamente as duas palavras
  //!se quem estiver lexicamente primeiro e estiver na primeira posicao e o segundo na segunda posicao
  //! isso eh igual a 0, caso contrario 1
  Serial.println("os textos sao iguais");
  else
  Serial.print(" os textos sao diferentes"); 


  //! texto editavel com char ========================================================================================================================

  char nomeAluno[20]= "thiagp";
  Serial.println(nomeAluno);

 //!alterando caracteres individualmente ========================================================================================================================

 nomeAluno[6]= 'o';
 Serial.print(nomeAluno);
 //! cuidado, o vetor precisa ter espaco o suficiente


//!strcpy: ========================================================================================================================

strcpy(nomeAluno, "Felipe");
//!copiando outro texto para dentro do vetor
Serial.println(nomeAluno);

//! strcat: ========================================================================================================================

char frase[40]= "ola ";
strcat(frase, "Mundo! ");
//! junta dois textos em um so
Serial.println(frase);


//! strchr: ========================================================================================================================

//!procurando um caractere no texto 
//!encontra um caracter no texto 
char* posicaoLetra = strchr(frase, "m" );
if (posicaoLetra != NULL )
//! null = /0
{ Serial.println( "letra encontrada");
 Serial.println(posicaoLetra);
}
else
{Serial.println("letra nao encontrada");
}


//! ATOI: ========================================================================================================================

//!convertendo texto numerico para inteiro 
char idadeTexto[ ] = "45"; // 52,53, /0
int idade = atoi(idadeTexto);
Serial.println(idade);


//! snprintf: ========================================================================================================================

//! monta um texto dentro de um vertor de char
char buffer[100];
char* local = "sala de aula";
int temperatura = 26.4;
int umidade = 58;
//! limita o tamanho do buffer que eu desejo construir
//! limita qualquer coisa maior que o buffer, que nesse caso eh 100
//! vai limitar tudas as letras a cima do numero limite do buffer
snprintf(buffer, sizeof(buffer), "%s | temp: %f | umid: %d %% \n\r ", local, temperatura, umidade);
Serial.print(buffer);
//! o S eh de string, ou seja, indica que eu vou colocar uma variavel de texto
//! o f indica float, indicando numeros
//! enquanto o d indica as variaveis de tipo int
//! ja o % indica % mesmo.
//! sintaxe: snprintf(variavel, onde ele vai ser montado , "texto que aparecera na tela", texto maximo do texto, txto com formatacao, itens de formato);
//! o \n mostra a mudanca de linha 
//! o \r retorna ao comeco da linha
//! um bom dev nao usa numeros constantes no programa
//! isto eh util quando:
//! - precisa salvar um texto
//! - mandar para o dusplay
//! - imprimir na serial
//!
//! ESPECIFICADORES:============================================================================================================================
//! %d ou &i sao variaveis tipo int
//! %U eh variavel tipo unsigned int 
//! %ld eh variavel tipo long
//! %lu eh variavel tipo unsigned long
//! %f eh variavel tipo float
//! %e eh variavel tipo notacao cientifica 
//! %g eh variavel tipo float mas mais curto
//! %c eh variavel tipo char
//! %s eh variavel tipo char* (string)
//! %x eh variavel hexadecimal minusculo/maiusculo 
//! %o eh variavel tipo octal
//! %p eh variavel tipo ponteiro 
//! %% eh variavel do proprio %

//! flag, largura, e precisao:
//! %5d = imprime com largura mnima alihado a direita [    3], [  100] [10000000]
//! %-4d = imprime com largura minima de 4 alinhado a esquerda [3    ],[100 ], [123456]
//! %03d = completa com zeros a esquerda [003]
//! %+d = sempre mostra o sinal de mais a frente [+3]
//! %.2f = 2 casas decimais em um float
//! %4.2f = largura minima 4 a direita com 2 casas decimais
//! %0.2X = exadeciaml com 2 digitos [0F] [3A]
//! %#x = imprime o prefixo 0x [0x2a] [0xF]
//! %.3s = somente os 3 primeiros caracteres da string
//! %*d = largura passada como argumento [ snprintf(buffer, sizeof(buffer), "numero %*d", largura, numero
//!                                                          logo sera impresso [  9] ]
//!
//!==============================================================================================================================================

String nome = "thiago";
String curso = "arduino";
String mensagem= "ola";

//! concatenado string =========================================================================================================================

mensagem=mensagem + "," + nome + "bem vindo ao curso de" + curso + ".";
Serial.println(mensagem);

//! tamanho do string ========================================================================================================================

int tamanhoMensagem = mensagem.length();
Serial.print("tamanho da string em letras:  ");
Serial.print( tamanhoMensagem);

//! acessando caractere em uma posicao especifica ========================================================================================================================

char primeiraLetra = mensagem.charAt(0);
Serial.println("primeira Letra: ");
Serial.println(primeiraLetra);

//! ao inves de charAt, eh possivel acessar um colchetes  

char segundaLetra = mensagem[1];
Serial.println(segundaLetra);


//! procurando um texto dentro da string ========================================================================================================================

int posicaoTextoProcurado = mensagem.indexOF(curso);
Serial.println(posicaoTextoProcurado);

//! extraindo um texto dentro a string ========================================================================================================================

int inicioNomeCurso = posicaoTextoProcurado + 9; //pocicao da palavra curso + 9 caracteres 
Serial.println(mensagem.substring(inicioNomeCurso, tamanhoMensagem));

//! substituindo texto dentro da string ========================================================================================================================

mensagem.replace("Ola," , "oi tudo bom?")
Serial.println(mensagem);

//! convertendo para maiuscula ========================================================================================================================

mensagem.toUpperCase();
Serial.println(mensagem);

//! convertendo tudo para minusculo ========================================================================================================================

mensagem.toLowerCase();
Serial.println(mensagem);

//! convertendo texto numerico para inteiro ========================================================================================================================

String textoNumero= "123";
int numero = textoNumero.toInt();
Serial.println(numero * 2);


//! verificando se a string esta vazia ========================================================================================================================

String textovazio = " "; 
if (textovazio.length()==0)
{Serial.println("o texto esta vazio");}



//! convertendo string para const char========================================================================================================================

//! isso eh util quando alguma biblioteca espera texto estilo C
const char* textoComoChar = mensagem.c_str();


}
void textoString()
{

}