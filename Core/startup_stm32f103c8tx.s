
    .syntax unified
    .cpu cortex-m3

    .section .isr_vector,"a",%progbits
    .type g_pfnVectors, %object
    .size g_pfnVectors, .-g_pfnVectors

    .global  __isr_vector
    .global  g_pfnVectors

g_pfnVectors:
__isr_vector:
    .long    __StackTop
    .long    main         /* Reset Handler */

    //.size    __isr_vector, . - __isr_vector

    .text
    .thumb
    .thumb_func
    .align 2



