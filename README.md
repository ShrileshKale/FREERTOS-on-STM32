# FREERTOS-on-STM32
Basic application to demonstrate rtos on STM32 Nucleo f446re development board


1. rtos_stm32_interface_main.c file has 3 implemented tasks which blinks leds (2 tasks) and send data to arduino uno rev v2 wifi board via SPI interface. This code uses the inbuilt "freertos" interface which can be configured via STMCubeMX software.

2. main.c uses third party freertos package and demonstrates some basic freertos apis.
