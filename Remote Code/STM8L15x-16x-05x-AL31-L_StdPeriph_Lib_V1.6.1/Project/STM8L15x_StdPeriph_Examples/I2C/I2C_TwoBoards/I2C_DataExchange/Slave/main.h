/**
  ******************************************************************************
  * @file    I2C/I2C_TwoBoards/I2C_DataExchange/Slave/main.h
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H


/* Define I2C Address mode ---------------------------------------------------*/
/* Comment the line below if you want to use the 10-bit addressing mode */
#define I2C_slave_7Bits_Address

/* Define Slave Address  ---------------------------------------------------*/
#ifdef I2C_slave_7Bits_Address
#define SLAVE_ADDRESS 0x30
#else
#define SLAVE_ADDRESS 0x330
#endif

#endif /* __MAIN_H*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
