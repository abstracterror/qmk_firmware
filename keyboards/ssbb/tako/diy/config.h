#pragma once

#define MATRIX_ROW_PINS \
    { D1, D0, D4, B5 }
#define MATRIX_ROW_PINS_RIGHT \
    { F4, F5, D1, E6 }

#define MATRIX_COL_CHANNELS \
    { 4, 6, 2, 0, 3 }
#define MATRIX_COL_CHANNELS_RIGHT \
    { 2, 4, 6, 7, 5 }

#define MUX_SEL_PINS \
    { F4, F5, F7 }
#define MUX_SEL_PINS_RIGHT \
    { B5, B4, F7 }

#define APLEX_EN_PIN B4
#define APLEX_EN_PIN_RIGHT D0

#define DISCHARGE_PIN E6
#define DISCHARGE_PIN_RIGHT D4

#define ANALOG_PORT F6

#define DEFAULT_ACTUATION_LEVEL 700
#define DEFAULT_RELEASE_LEVEL 650

#define SPLIT_HAND_PIN B3
#define SERIAL_USART_TX_PIN D3
