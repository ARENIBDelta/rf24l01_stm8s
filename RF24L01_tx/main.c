#include "rf24l01.h"

int main( void )
{
  RF24L01_init();
  uint8_t rx_addr[5] = {0x44, 0x88, 0xBA, 0xBE, 0x42};
  uint8_t tx_addr[5] = {0x04, 0xAD, 0x45, 0x98, 0x51};
  RF24L01_setup(tx_addr, rx_addr, 12);
  RF24L01_set_mode_TX();
  
  uint8_t data_to_send[32] = {0x42, 0x51, 0x33, 0x44, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28};
  while(1) {
      RF24L01_write_payload(data_to_send, 32);
      
      uint16_t delay = 0x1FF;
      while(delay--);
      data_to_send[0]++;
      data_to_send[1]+=2;
  }
}
