#include "hal_led.h"
#include "led_embutido.h"
#include "pico/stdlib.h"

void hal_led_init() {
    led_embutido_init();
}

void hal_led_toggle() {
    static int estado = 0;
    estado = !estado;
    led_embutido_set(estado);
}
