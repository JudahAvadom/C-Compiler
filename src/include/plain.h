#ifndef PLAIN_H
#define PLAIN_H

void statements();

void expression();

void expr_prime();

void term();

void term_prime();

/**
 * factor   -> NUM_OR_ID
 *          | LP expression RP
 */
void factor();

#endif