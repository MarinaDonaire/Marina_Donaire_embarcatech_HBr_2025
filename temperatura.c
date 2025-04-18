#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main() {
    stdio_init_all();

    adc_init(); // Inicia ADC
    adc_set_temp_sensor_enabled(true); // Ativa sensor interno
    adc_select_input(4); // Canal 4 = temperatura interna

    while (true) {
        uint16_t leitura_adc = adc_read();

        // Converte para tensão
        float fator_conversao = 3.3f / (1 << 12); // 12 bits = 4096
        float tensao = leitura_adc * fator_conversao;

        // Converte tensão em ºC (conforme datasheet do RP2040)
        float temperatura = 27.0f - (tensao - 0.706f) / 0.001721f;

        printf("Temperatura: %.2f C\n", temperatura);
        sleep_ms(1000);
    }
}
