#include "rf24l01.h"

int main( void )
{
  RF24L01_init();
  uint8_t rx_addr[5] = {0x04, 0xAD, 0x45, 0x98, 0x51};
  uint8_t tx_addr[5] = {0x44, 0x88, 0xBA, 0xBE, 0x42};
  RF24L01_setup(tx_addr, rx_addr, 12);

  //IRQ
  GPIO_Init(
    GPIOC,
    GPIO_PIN_2,
    GPIO_MODE_IN_FL_IT
  );
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC, EXTI_SENSITIVITY_FALL_ONLY);
  enableInterrupts();

  RF24L01_set_mode_RX();
  
  while(1);
}

INTERRUPT_HANDLER(EXTI_PORTC_IRQHandler, 5)
{
  uint8_t recv_data[32];
  if(RF24L01_is_data_available()) {
    RF24L01_read_payload(recv_data, 32);
  }
  
  asm("nop"); //Place a breakpoint here
}
