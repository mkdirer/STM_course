/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2019 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define x3_Pin GPIO_PIN_13
#define x3_GPIO_Port GPIOC
#define x2_Pin GPIO_PIN_0
#define x2_GPIO_Port GPIOC
#define x1_Pin GPIO_PIN_1
#define x1_GPIO_Port GPIOC
#define y1_Pin GPIO_PIN_2
#define y1_GPIO_Port GPIOC
#define y2_Pin GPIO_PIN_3
#define y2_GPIO_Port GPIOC
#define y3_Pin GPIO_PIN_1
#define y3_GPIO_Port GPIOA
#define y4_Pin GPIO_PIN_2
#define y4_GPIO_Port GPIOA
#define x4_Pin GPIO_PIN_4
#define x4_GPIO_Port GPIOC
#define x5_Pin GPIO_PIN_5
#define x5_GPIO_Port GPIOC
#define y5_Pin GPIO_PIN_0
#define y5_GPIO_Port GPIOB
#define y6_Pin GPIO_PIN_1
#define y6_GPIO_Port GPIOB
#define y7_Pin GPIO_PIN_2
#define y7_GPIO_Port GPIOB
#define y8_Pin GPIO_PIN_12
#define y8_GPIO_Port GPIOB
#define y9_Pin GPIO_PIN_13
#define y9_GPIO_Port GPIOB
#define y10_Pin GPIO_PIN_15
#define y10_GPIO_Port GPIOB
#define x14_Pin GPIO_PIN_10
#define x14_GPIO_Port GPIOC
#define x13_Pin GPIO_PIN_11
#define x13_GPIO_Port GPIOC
#define x12_Pin GPIO_PIN_12
#define x12_GPIO_Port GPIOC
#define x11_Pin GPIO_PIN_2
#define x11_GPIO_Port GPIOD
#define x10_Pin GPIO_PIN_3
#define x10_GPIO_Port GPIOB
#define x9_Pin GPIO_PIN_6
#define x9_GPIO_Port GPIOB
#define x8_Pin GPIO_PIN_7
#define x8_GPIO_Port GPIOB
#define x7_Pin GPIO_PIN_8
#define x7_GPIO_Port GPIOB
#define x6_Pin GPIO_PIN_9
#define x6_GPIO_Port GPIOB

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
