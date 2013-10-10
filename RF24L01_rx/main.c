#include "rf24l01.h"

int main( void )
{
  RF24L01_init();
  uint8_t rx_addr[5] = {0x04, 0xAD, 0x45, 0x98, 0x51};
  uint8_t tx_addr[5] = {0x44, 0x88, 0xBA, 0xBE, 0x42};
  RF24L01_setup(tx_addr, rx_addr, 12);
  RF24L01_set_mode_RX();
  
  uint8_t recv_data[32];
  while(1) {
    uint16_t delay = 0x2FF;
    while(delay--);

    while(!RF24L01_is_data_available());
    RF24L01_read_payload(recv_data, 32);

    asm("nop"); //Place a breakpoint here
    
  }
}
