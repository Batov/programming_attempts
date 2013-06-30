/*
 * libstrtoint.h
 *
 *  Created on: 25.11.2012
 *      Author: sten
 */

#ifndef LIBSTRTOINT_H_
#define LIBSTRTOINT_H_
typedef struct Lexem
{
int value;
char* string;
int type;
} LEX;
typedef struct Lexer
{
LEX curLex;
char* string;
int position;
} Lexer;

int strtoint(char* str);


#endif /* LIBSTRTOINT_H_ */
