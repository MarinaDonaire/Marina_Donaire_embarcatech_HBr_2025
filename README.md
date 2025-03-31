# Projetos de Sistemas Embarcados - EmbarcaTech 2025

Autor: Marina Donaire

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Campinas, março de 2025

---

## Sobre este repositório

Este repositório reúne meus projetos desenvolvidos ao longo do curso de Sistemas Embarcados, durante a etapa de residência.  

---
## Projetos 


## Projeto Fase 01 - Embarcatech 

O projeto RelaxBerry consiste no desenvolvimento de um dispositivo embarcado para auxiliar no controle da respiração durante crises de ansiedade e ataques de pânico. Utilizando um Raspberry Pi Pico, um display OLED e LEDs RGB, o sistema guia o usuário por meio de instruções visuais para realizar a técnica de respiração quadrada (inspirar, segurar, expirar, segurar). O dispositivo opera de maneira autônoma, sem necessidade de conexão com um smartphone ou internet, proporcionando uma solução acessível e eficiente para pessoas que necessitam de suporte em momentos de crise.

**Objetivo do projeto**

Componentes usados

Microcontrolador: Raspberry Pi Pico

Display: OLED 128x64 pixels (I2C)

LEDs RGB: Para indicação visual das fases da respiração

Bateria: Fonte de alimentação 


**Pinagem dos dispositivos**

Display OLED (I2C):

SDA → GPIO 14

SCL → GPIO 15

LEDs RGB:

LED Verde → GPIO 11

LED Vermelho → GPIO 12

LED Azul → GPIO 13

**Como compilar e executar** 

Instalar o Raspberry Pi Pico SDK.

Baixar e configurar a biblioteca ssd1306 para controle do display OLED.

Compilar o código utilizando CMake e Make.

Conectar o Raspberry Pi Pico ao computador em modo bootloader.

Transferir o arquivo UF2 compilado para o Raspberry Pi Pico.

O dispositivo iniciará automaticamente e guiará o usuário na técnica de respiração.


**Imagens e vídeos**

Diagrama de blocos do funcionamento : ![image](https://github.com/user-attachments/assets/454cd3ee-9e51-4ed9-ade9-609ad5cac581)


Link para o vídeo do funcionamento :  https://youtu.be/sk14xKnpJd8?si=rfSoK9_Jz3X5Z1LY  
 

**Resultados esperados ou observados**

O dispositivo deve indicar visualmente as fases da respiração quadrada de forma clara e intuitiva.

A técnica de respiração guiada ajudará a reduzir sintomas de ansiedade e hiperventilação.

O baixo consumo energético garantirá uma boa autonomia da bateria.

O RelaxBerry funcionará de maneira independente, sem necessidade de aplicativos ou configurações complexas.

O projeto demonstrará a viabilidade do uso de sistemas embarcados no suporte à saúde mental.





