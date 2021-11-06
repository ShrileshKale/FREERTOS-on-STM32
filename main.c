#include <stdio.h>
#include <stdint.h>
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stm32f446xx.h"

TaskHandle_t vHandle1 = NULL;
TaskHandle_t vHandle2 = NULL;
BaseType_t statusOfTask;

static void vtask1_handler(void *params);
static void vtask2_handler(void *params);
extern void initialise_monitor_handles();

int main(void)
{
#ifdef use_semihosting
// for semi hosting
initialise_monitor_handles();

printf("Semi hosting working");

#endif


statusOfTask = xTaskCreate( vtask1_handler,"Task1", configMINIMAL_STACK_SIZE,"Task-1 Executing",2, &vHandle1 );
configASSERT(statusOfTask == pdPASS);
xTaskCreate( vtask2_handler,"Task2", configMINIMAL_STACK_SIZE,"Task-2 Executing",2, &vHandle2 );
configASSERT(statusOfTask == pdPASS); // pdPASS = 1 then assert will not be called


// schedule the tasks
vTaskStartScheduler();

}
static void vtask1_handler(void* params)

{
	while(1)
	{
		printf("%s\n", (char*)params);
	}
}

static void vtask2_handler(void *params)

{
	while(1)
	{
		printf("%s\n", (char*)params);
	}
}
