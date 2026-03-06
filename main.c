#define PERIPH_BASE     0x40000000UL
#define AHB2PERIPH_BASE (PERIPH_BASE + 0x08000000UL)
#define GPIOA_BASE      (AHB2PERIPH_BASE + 0x0000UL)
#define RCC_BASE        (PERIPH_BASE + 0x21000UL)

#define RCC_AHB2ENR     (*(volatile unsigned int *)(RCC_BASE + 0x4C))
#define GPIOA_MODER     (*(volatile unsigned int *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR       (*(volatile unsigned int *)(GPIOA_BASE + 0x14))

void delay(void)
{
    for (volatile int i = 0; i < 100000; i++);
}

int main(void)
{
    /* Enable GPIOA clock (bit 0) */
    RCC_AHB2ENR |= (1 << 0);

    /* Set PA1 as output */
    GPIOA_MODER &= ~(3 << (1 * 2));
    GPIOA_MODER |=  (1 << (1 * 2));

    while (1)
    {
        GPIOA_ODR ^= (1 << 1);
        delay();
    }
}
