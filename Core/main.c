/*
 * main.c
 */

#include "stdint.h"

#define __IO               volatile

#define RCC_APB2ENR                              (*((__IO uint32_t *)0x40021018))
#define RCC_APB2ENR_IOPCEN                       0x10


typedef struct
{
  __IO uint32_t CRL;
  __IO uint32_t CRH;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t BRR;
  __IO uint32_t LCKR;
} GPIO_TypeDef;

#define GPIOC_BASE          0x40011000UL
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)

#define GPIOC_CRH_VALUE                          0x44144444
#define GPIOC_ODR_ODR13                          0x2000


__attribute__((naked))int main(void)
{

	RCC_APB2ENR |= RCC_APB2ENR_IOPCEN;

	GPIOC->CRH = GPIOC_CRH_VALUE;




    uint32_t delay;

    while(1)
    {
    	GPIOC->ODR ^= GPIOC_ODR_ODR13;
        for(delay = 500000; delay != 0; delay--) {};
    }
}



