
#pragma once

#include_next <mcuconf.h>

#if defined(MCU_RP)
#    undef RP_ADC_USE_ADC1
#    define RP_ADC_USE_ADC1 TRUE
#endif
