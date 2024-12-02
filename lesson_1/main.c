void ClockCfg_N_GPIOCfg() {
	//Enable HSEON clock
	RCC->CR |= (RCC_CR_HSEON);
	while (!(RCC->CR & (RCC_CR_HSERDY)))
		;

	// Enable GPIOC clock
	RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN_Msk;
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOCEN);

    // Set to OUTPUT mode (00: input, 01: general purpose output, 10: alternate, 11: analog)
    GPIOC->MODER &= ~GPIO_MODER_MODER13_Msk;
    GPIOC->MODER |= (0x01 << GPIO_MODER_MODER13_Pos);

    //Disable pull-up/pull-down for PC13 (00: no pull-up/pull-down, 01: pull-up, 10: pull-down, 11: reserved)
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPD13_Msk;


    //
    //	// Set PC13 output type to push-pull (0: push-pull, 1: open-drain)
    //	GPIOC->OTYPER &= ~(GPIO_OTYPER_OT13);
    //

    GPIOC->ODR  &= ~GPIO_ODR_OD13;  //LED OFF


}
