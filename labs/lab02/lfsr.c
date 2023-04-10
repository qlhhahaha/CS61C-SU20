#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

uint16_t get_bit(uint16_t x,
                 uint16_t n) {
    return (x >> n) & 1;
}


void set_bit(uint16_t * x,
             uint16_t n,
             uint16_t v) {
    // YOUR CODE HERE
    uint16_t mask = ~(1<<n);
    (*x) = ((*x) & mask)|(v << n);
}

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    uint16_t tmp = get_bit(*reg, 0) ^ get_bit(*reg, 2) ^ get_bit(*reg, 3) ^ get_bit(*reg, 5);
    *reg = (*reg >> 1);
    set_bit(reg, 15, tmp);
}

