// main.c
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "adc_to_celsius.h"

int main() {
    stdio_init_all();      // Inicializa saída serial
    adc_init();            // Inicializa ADC
    adc_select_input(4);   // Canal 4 = sensor de temperatura interno
    adc_set_temp_sensor_enabled(true);  // Habilita sensor interno

    while (true) {
        uint16_t raw = adc_read();   // Lê valor bruto de 12 bits
        float temp = adc_to_celsius(raw);
        printf("Temperatura: %.2f °C\n", temp);
        sleep_ms(1000);  // Espera 1 segundo
    }

    return 0;
}
