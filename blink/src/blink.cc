/**
 * @file   blink.cc
 * @author ZiTe (honmonoh@gmail.com)
 * @brief  Basic LED blink example with 'stm32_oop_lib'.
 */

#include <libopencm3/stm32/rcc.h>
#include <stm32_oop_lib_gpio.h>

stm32_oop_lib::GPIO led(stm32_oop_lib::UserLED,
                        stm32_oop_lib::OutputPushPull,
                        false,
                        stm32_oop_lib::Speed2MHz);

void delay(int value);

int main(void)
{
  rcc_periph_clock_enable(RCC_GPIOA);
  led.Init();

  while (1)
  {
    led.Toggle();
    delay(500000);
  }

  return 0;
}

void delay(int value)
{
  while (value--)
  {
    __asm__("nop");
  }
}
