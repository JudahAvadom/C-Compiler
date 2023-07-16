#include <stdio.h>
#include <ctype.h>
#include "include/lex.h"

char *text = "";
int length = 0;
int line = 0;

int lex(){
    static char input_buffer[128];
    char *current;
    current = text + length;            /* Skip curent lexeme*/
    while (1)                           /* Get the next one */
    {
        while (!*current)
        {
            current = input_buffer;
            if (!gets(input_buffer))
            {
                *current = '\0';
                return EOI;
            }
            ++line;
            while (isspace(*current))
            {
                ++current;
            }
            for (  ; *current ; ++current)
            {
                /* Get the next token */
                text = current;
                length = 1;
                switch (*current)
                {
                    case EOF: return EOI;
                    case ';': return SEMI;
                    case '+': return PLUS;
                    case '*': return TIMES;
                    case '(': return LP;
                    case ')': return RP;
                    case '\n':
                    case '\t':
                    case ' ':break;
                    default:
                        if (!isalnum(*current))
                        {
                            fprintf(stderr, "Ignoring illegal input <%c>\n", *current);
                        }
                        else
                        {
                            while (isalnum(*current))
                            {
                                ++current;
                            }
                            length = current - text;
                            return NUM_OR_ID;
                        }
                        break;
                }
            }           
        }
    }
}

/**
 * Lookahead token
*/
static int Lookahead = -1;

int match(int token){
    if (Lookahead == -1)
    {
        Lookahead = lex();
    }
    return token == Lookahead;
}

void advance(){
    Lookahead = lex();
}