#ifndef LEX_H
#define LEX_H

/**
 * Lexeme (not '\0' terminated)
*/
extern char *text;

/**
 * Lexeme length
*/
extern int length;

/**
 * Input line number
*/
extern int line;

int lex();

#endif