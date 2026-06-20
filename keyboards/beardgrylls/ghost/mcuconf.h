#pragma once

#include_next <mcuconf.h>

#undef STM32_PWM_USE_TIM16
#define STM32_PWM_USE_TIM16 TRUE
#define STM32_TIM16_SUPPRESS_ISR
