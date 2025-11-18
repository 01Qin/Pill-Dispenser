//
// Created by Quinn on 18.11.2025.
//

#ifndef QIN_V1_MAIN_H
#define QIN_V1_MAIN_H

#define CLK_DIV 125
#define WRAP_VALUE 999
#define PWM_MAX 1000

#define SW_1 8 // middle button - light and dispenser switch
#define SW_0 9 // left button - led switch
#define BUTTONS_SIZE 2

#define LED_D1 22 // right LED
#define LEDS_SIZE 1

// Stepper motor control pins
#define IN1 2
#define IN2 3
#define IN3 6
#define IN4 13
#define INS_SIZE 4

#define SENSOR_PIN 28 // Optical sensor input with pull-up
#define INPUT_LENGTH 200 // Maximum input line length
#define SAFE_MAX_STEPS 20480 // Safety limit: 5 * 4096 steps
#define STEP_DELAY_MS 2

// Half-step sequence: A, AB, B, BC, C, CD, D, DA
const uint8_t sequence[8][4] = {
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {1, 0, 0, 1}
};

void buttons_initialisation(const uint *buttons);
void leds_initialisation(const uint *leds);
bool light_switch(const uint *leds, uint brightness, bool on);
void set_brightness(const uint *leds, uint brightness);
uint clamp_to_wrap(int bright_value);

#endif //QIN_V1_MAIN_H