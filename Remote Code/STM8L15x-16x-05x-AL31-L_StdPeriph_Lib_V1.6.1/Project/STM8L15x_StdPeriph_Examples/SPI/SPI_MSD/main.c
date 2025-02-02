/**
  ******************************************************************************
  * @file    SPI/SPI_MSD/main.c
  * @author  MCD Application Team
  * @version V1.5.1
  * @date    28-June-2013
  * @brief   Main program body
  ******************************************************************************
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm8l15x.h"
#include "stm8_eval.h"
#include "stm8_eval_spi_sd.h"

/** @addtogroup STM8L15x_StdPeriph_Examples
  * @{
  */

/**
  * @addtogroup SPI_MSD
  * @{
  */

/* Private macro -------------------------------------------------------------*/
#define countof(a) (sizeof(a) / sizeof(*(a)))

/* Private define ------------------------------------------------------------*/
#define BUFFER_SIZE (countof(TxBuffer)-1)

/* Private variables ---------------------------------------------------------*/
__IO uint16_t Status = 0;
uint8_t TxBuffer[] = "STM8l15x SPI Firmware Library Example: communication with a microSD card";
uint8_t RxBuffer[BUFFER_SIZE] = {0};
__IO ErrorStatus TransferStatus = ERROR;

/* Private function prototypes -----------------------------------------------*/
void Delay (uint16_t nCount);
static ErrorStatus Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
void main(void)
{
  /* High speed internal clock prescaler: 1*/
  CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);

  /* Initialize I/Os in Output Mode for LEDs */
  STM_EVAL_LEDInit(LED1);
  STM_EVAL_LEDInit(LED2);
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);

  /***********************SPI and MSD Card initialization******************/

  while (SD_Detect() == SD_NOT_PRESENT);
  {
    /* Wait MicroSD card insertion */
  }

  Delay(0xFFFF);
  /* Init the flash micro SD*/
  Status = SD_Init();

  /***************************Block Read/Write******************************/
  /* Write block of 512 bytes on address 0 */
  SD_WriteBlock(TxBuffer, 0, BUFFER_SIZE);

  /* Read block of 512 bytes from address 0 */
  SD_ReadBlock(RxBuffer, 0, BUFFER_SIZE);

  /* Check data */
  TransferStatus = Buffercmp(TxBuffer, RxBuffer, BUFFER_SIZE);
  if (TransferStatus != SUCCESS)
  {
    while (1) /* Go to infinite loop when there is mismatch in data programming*/
    {
      STM_EVAL_LEDToggle(LED1);
      Delay((uint16_t)0xFFFF);
    }
  }
  while (1)
  {
    STM_EVAL_LEDToggle(LED1);
    STM_EVAL_LEDToggle(LED2);
    STM_EVAL_LEDToggle(LED3);
    STM_EVAL_LEDToggle(LED4);
    Delay((uint16_t)0xFFFF);
  }
}

/**
  * @brief  Compares two buffers.
  * @param  pBuffer1, pBuffer2: buffers to be compared.
  * @param  BufferLength: buffer's length
  * @retval
 * - PASSED: pBuffer1 identical to pBuffer2
 * - FAILED: pBuffer1 differs from pBuffer2
  */
ErrorStatus Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength)
{
  while (BufferLength--)
  {
    if (*pBuffer1 != *pBuffer2)
    {
      return ERROR;
    }

    pBuffer1++;
    pBuffer2++;
  }

  return SUCCESS;
}

/**
  * @brief  Delay.
  * @param  nCount
  * @retval None
  */
void Delay(uint16_t nCount)
{
  /* Decrement nCount value */
  while (nCount != 0)
  {
    nCount--;
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif

/**
  * @}
  */

/**
  * @}
  */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/