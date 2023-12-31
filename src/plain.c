#include <stdio.h>
#include "include/plain.h"
#include "include/lex.h"

void statements(){
    expression();
    if (match(SEMI))
    {
        advance();
    }
    else
    {
        fprintf(stderr, "%d: Inserting missing semicolon \n", line);
    }
    if (!match(EOI))
    {
        statements();
    }
}

void expression(){
    term();
    expr_prime();
}

void expr_prime(){
    if (match(PLUS))
    {
        advance();
        term();
        expr_prime();
    }
}

void term(){
    factor();
    term_prime();
}

void term_prime(){
    if (match(TIMES))
    {
        advance();
        factor();
        term_prime();
    }
}

void factor(){
    if (match(NUM_OR_ID))
    {
        advance();
    }
    else if (match(LP))
    {
        advance();
        expression();
        if (match(RP))
        {
            advance();
        }
        else
        {
            fprintf(stderr, "%d: Mismatched parenthesis \n", line);
        }
    }
    else
    {
        fprintf(stderr, "%d: Number or identifier expected \n", line);
    }
}