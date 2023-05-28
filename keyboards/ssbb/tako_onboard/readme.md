# Tako

![Tako Keyboard](https://github.com/ssbb/tako/blob/dbc6211e5c4ba931b4ea7a987243862151c7dac3/docs/img/assembled.jpg)

Tako is a vertical stagger split keyboard with electrostatic capacitive (EC) non-contact switches.

-   Keyboard Maintainer: [ssbb](https://github.com/ssbb)
-   Hardware Supported: Tako
-   Hardware Availability: [Github](https://github.com/ssbb/tako)

Make example for this keyboard (after setting up your build environment):

    make ssbb/tako_onboard:default

Flashing example for this keyboard (and set handness by EEPROM):

    make ssbb/tako_onboard:default:dfu-util-split-left
    make ssbb/tako_onboard:default:dfu-util-split-right

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

-   **Physical Boot0 button**: Hold down the Boot0 button (near TRRS socket) while plugging in the keyboard
-   **Bootmagic reset**: Hold down the key at `(0,0)` (QWERTY `T` on the left half) or `(4,4)` (QWERTY `Y` on the right half) and plug in the keyboard
-   **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
