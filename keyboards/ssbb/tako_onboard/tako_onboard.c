/* Copyright 2023 ssbb
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "tako_onboard.h"
#include "ec_switch_matrix.h"

#define ROWS_PER_HAND (MATRIX_ROWS / 2)
#define MAX_READ 1022

static bool is_calibrating = false;

bool matrix_can_read(void) {
    return !is_calibrating;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EC_CLBR:
        if (record->event.pressed) {
            is_calibrating = true;

            print("CALIBRATION\n");
            print("Do not press any keys! Waiting 2 seconds before starting...\n");

            wait_ms(2000);

            print("Taking readings for 15 seconds...\n");

            uint16_t scan_timer = timer_read();

            uint16_t low_max[ROWS_PER_HAND][MATRIX_COLS];
            uint16_t low_min[ROWS_PER_HAND][MATRIX_COLS];

            for (int col = 0; col < MATRIX_COLS; col++) {
                for (int row = 0; row < MATRIX_ROWS / 2; row++) {
                    low_min[row][col] = MAX_READ;
                    low_max[row][col] = 0;
                }
            }

            while (timer_elapsed(scan_timer) < 5000) {
                for (int col = 0; col < MATRIX_COLS; col++) {
                    for (int row = 0; row < ROWS_PER_HAND; row++) {
                        uint16_t value = ecsm_readkey_raw(row, col);

                        if (value < low_min[row][col]) low_min[row][col] = value;
                        if (value > low_max[row][col]) low_max[row][col] = value;
                    }
                }
            }

            print("CALIBRATION RESULTS:\n");
            for (int row = 0; row < ROWS_PER_HAND; row++) {
                for (int col = 0; col < MATRIX_COLS; col++) {
                    uint16_t noise = low_max[row][col] - low_min[row][col];
                    if (noise == 0) noise = 1;

                    uint16_t low = low_max[row][col] - noise / 2;
                    uint16_t snr = (MAX_READ - low) / noise;

                    uprintf("%4d (%4d - %4d) [%4d%%]", low, low_min[row][col], low_max[row][col], snr);
                    if (col < (MATRIX_COLS - 1)) {
                        print(",");
                    }
                }
                print("\n");
            }

            print("\n");
            print("CALIBRATION DONE!\n");
            is_calibrating = false;

        }
        return false;
    }

    return process_record_user(keycode, record);
}
