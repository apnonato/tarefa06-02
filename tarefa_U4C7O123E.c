#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22
#define RED_LED_PIN 13
#define GREEN_LED_PIN 11
#define BLUE_LED_PIN 12

#define PWM_FREQUENCY 50
#define PWM_WRAP 20000
#define WAIT_TIME_MS 5000
#define SMOOTH_DELAY_MS 10
#define INCREMENT_US 5

void configure_pwm(uint pin, uint frequency, uint wrap)
{
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_wrap(slice_num, wrap);
    pwm_set_clkdiv(slice_num, 125.0f);
    pwm_set_enabled(slice_num, true);
}

void set_active_cycle_us(uint pin, uint cycle_us)
{
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(pin), cycle_us);
}

int main()
{
    stdio_init_all();

    configure_pwm(SERVO_PIN, PWM_FREQUENCY, PWM_WRAP);
    configure_pwm(RED_LED_PIN, PWM_FREQUENCY, PWM_WRAP);
    configure_pwm(GREEN_LED_PIN, PWM_FREQUENCY, PWM_WRAP);
    configure_pwm(BLUE_LED_PIN, PWM_FREQUENCY, PWM_WRAP);

    set_active_cycle_us(SERVO_PIN, 2400);
    printf("180°\n");

    set_active_cycle_us(RED_LED_PIN, 2400);
    set_active_cycle_us(GREEN_LED_PIN, 0);
    set_active_cycle_us(BLUE_LED_PIN, 0);
    sleep_ms(WAIT_TIME_MS);

    set_active_cycle_us(SERVO_PIN, 1470);
    printf("90°\n");

    set_active_cycle_us(RED_LED_PIN, 0);
    set_active_cycle_us(GREEN_LED_PIN, 1470);
    set_active_cycle_us(BLUE_LED_PIN, 0);
    sleep_ms(WAIT_TIME_MS);

    set_active_cycle_us(SERVO_PIN, 500);
    printf("0°\n");

    set_active_cycle_us(RED_LED_PIN, 0);
    set_active_cycle_us(GREEN_LED_PIN, 0);
    set_active_cycle_us(BLUE_LED_PIN, 500);
    sleep_ms(WAIT_TIME_MS);

    while (true)
    {
        for (uint cycle_us = 500; cycle_us <= 2400; cycle_us += INCREMENT_US)
        {
            set_active_cycle_us(SERVO_PIN, cycle_us);
            set_active_cycle_us(RED_LED_PIN, cycle_us);
            set_active_cycle_us(GREEN_LED_PIN, 2400 - cycle_us);
            set_active_cycle_us(BLUE_LED_PIN, 500 + (cycle_us - 500) / 2);
            sleep_ms(SMOOTH_DELAY_MS);
        }

        for (uint cycle_us = 2400; cycle_us >= 500; cycle_us -= INCREMENT_US)
        {
            set_active_cycle_us(SERVO_PIN, cycle_us);
            set_active_cycle_us(RED_LED_PIN, cycle_us);
            set_active_cycle_us(GREEN_LED_PIN, 2400 - cycle_us);
            set_active_cycle_us(BLUE_LED_PIN, 500 + (cycle_us - 500) / 2);
            sleep_ms(SMOOTH_DELAY_MS);
        }
    }

    return 0;
}
