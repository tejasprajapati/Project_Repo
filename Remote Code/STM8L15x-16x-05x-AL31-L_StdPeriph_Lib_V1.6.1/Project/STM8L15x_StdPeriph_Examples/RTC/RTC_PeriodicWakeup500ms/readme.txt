/** @page RTC_PeriodicWakeup500ms Use RTC periodic Wakeup unit to toggle leds each 500ms

  @verbatim
  ******************** (C) COPYRIGHT 2013 STMicroelectronics *******************
  * @file    RTC/RTC_PeriodicWakeup500ms/readme.txt 
  * @author  MCD Application Team
  * @version V1.5.1
  * @date    28-June-2013
  * @brief   Description of the RTC Periodic (each 500ms   Wakeup Example.
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
  @endverbatim
  
  @par Example description
  
  This example provides a short description of how to use the RTC peripheral
  periodic wakeup interrupt to toggle periodically leds.
  In the first time, all Leds are on, and each time the periodic wake up event 
  occurs, LED1 and LED4 toggle. 
    
  @par Directory contents

  - RTC/RTC_PeriodicWakeup500ms/main.c             Main file 
  - RTC/RTC_PeriodicWakeup500ms/stm8l15x_conf.h    Library Configuration file
  - RTC/RTC_PeriodicWakeup500ms/stm8l15x_it.c      Interrupt routines source
  - RTC/RTC_PeriodicWakeup500ms/stm8l15x_it.h      Interrupt routines declaration

  
 @par Hardware and Software environment

    - This example runs on STM8L15x High-Density, Medium-Density Plus, Medium-Density
    and Low-Density Devices.
  
  - This example has been tested with STMicroelectronics STM8L1528-EVAL 
    (STM8L15x High-Density devices) and STM8L1526-EVAL (STM8L15x Medium-Density and
    Low-Density devices) evaluation boards and can be easily tailored to any other
    development board.

  - STM8L1528-EVAL Set-up
     - Make sure that the LCD glass daughter board is mounted in IO position.
       For more details please refer to the evaluation board user manual.
     - LED1..4
     - External 32.768kHz LSE clock (X1)  
     - Make sure that SB9 (Solder Bridge) is in position 2-3.
     
  - STM8L1526-EVAL Set-up
     - Make sure that the LCD glass daughter board is mounted in IO position.
       For more details please refer to the evaluation board user manual.
     - LED1..4
     - External 32.768kHz LSE clock (X2)  
     

  @par How to use it ?

  In order to make the program work, you must do the following :

  - Copy all source files from this example folder to the template folder under
    Project\STM8L15x_StdPeriph_Template
  - Open your preferred toolchain 
  - Add the required file:
    - stm8_eval   (under Utilities\STM8_EVAL)
  - Rebuild all files and load your image into target memory
  - Run the example



 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */