#ifndef LEX_H
#define LEX_H

/**
 * End of input
*/
#define EOI         0

/**
 * ;
*/
#define SEMI        1

/**
 * +
*/
#define PLUS        2

/**
 * +
*/
#define TIMES        3

/**
 * (
*/
#define LP          4

/**
 * )
*/
#define RP          5

/**
 * Decimal number or identifier
*/
#define NUM_OR_ID   6

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

static int Lookahead;

/**
 * Return true if "token" matches the current lookahead symbol
*/
int match(int token);

/**
 * Advance the lookahead to the next input symbol
*/
void advance();

#endif