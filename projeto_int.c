#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"
#include "inc/ssd1306.h"

// ==== Definições dos GPIOs dos botões ====
#define BUTTON_A 5
#define BUTTON_B 6

volatile bool start_count = false;
volatile uint8_t click_count = 0;
volatile bool button_a_pressed = false;
volatile bool button_b_pressed = false;

// === Manipulador de interrupção do Botão A ===
void gpio_callback_button_a(uint gpio, uint32_t events) {
    if (gpio == BUTTON_A && (events & GPIO_IRQ_EDGE_FALL)) {
        button_a_pressed = true;
    }
}

// === Manipulador de interrupção do Botão B ===
void gpio_callback_button_b(uint gpio, uint32_t events) {
    if (gpio == BUTTON_B && (events & GPIO_IRQ_EDGE_FALL)) {
        if (start_count) {
            click_count++;
        }
    }
}

// === Inicialização dos botões com interrupções ===
void init_buttons() {
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_callback_button_a);

    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);
    gpio_set_irq_enabled(BUTTON_B, GPIO_IRQ_EDGE_FALL, true);
    gpio_set_irq_callback(&gpio_callback_button_b);
}

// === Exibir contador e cliques no display ===
void display_status(uint8_t count, uint8_t clicks) {
    char buffer[20];
    ssd1306_clear();
    sprintf(buffer, "Contador: %d", count);
    ssd1306_print(0, 0, buffer);
    sprintf(buffer, "Cliques B: %d", clicks);
    ssd1306_print(0, 10, buffer);
    ssd1306_show();
}

int main() {
    stdio_init_all();
    sleep_ms(500); // Delay para garantir inicialização
    ssd1306_init();
    init_buttons();

    uint8_t contador = 0;

    while (1) {
        if (button_a_pressed) {
            button_a_pressed = false;
            contador = 9;
            click_count = 0;
            start_count = true;

            for (int i = contador; i >= 0; i--) {
                display_status(i, click_count);
                sleep_ms(1000);
                if (i == 0) {
                    start_count = false;
                    break;
                }
            }

            // Congela o sistema após o contador zerar
            while (!button_a_pressed) {
                display_status(0, click_count);
                sleep_ms(100);
            }

            // Quando botão A for pressionado de novo, reinicia no próximo loop
            button_a_pressed = false;
        }

        tight_loop_contents(); // Para economizar energia em espera
    }

    return 0;
}
