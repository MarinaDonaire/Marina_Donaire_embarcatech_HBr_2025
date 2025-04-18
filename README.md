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

O objetivo é levar técnicas de respirações para pessoas com ansiedade ou crise de pânico por diversos motivos. 

**Funcionamento do Projeto**

O RelaxBerry funciona através da exibição de mensagens no display OLED e do acionamento sequencial dos LEDs RGB para indicar cada etapa da técnica de respiração quadrada. O dispositivo segue um ciclo controlado de acordo com o tempo de cada respiração. 
Inspirar (4 segundos) : O display exibe "Respire" e um LED verde pisca progressivamente para orientar a inalação.
Segurar (4 segundos) :  O display exibe "Segure a Respiração", e um LED vermelho  se acende fixamente durante os 4 segundos.
Expirar (4 segundos) : O display exibe "Solte" e um LED azul pisca para orientar a exalação.
Segurar (4 segundos) : O display repete "Segure a Respiração", e o LED vermelho se acende novamente.
Esse ciclo se repete continuamente, guiando o usuário de forma simples e objetiva até que sinta que sua respiração se acalmou e que melhorou, assim pode desligar o dispositivo.


**Componentes usados**

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

![image](https://github.com/user-attachments/assets/10ecb5af-1178-4aa2-b92a-2040f0cf17af)


**Como compilar e executar** 

Instalar o Raspberry Pi Pico SDK.

Baixar e configurar a biblioteca ssd1306 para controle do display OLED.

Compilar o código utilizando CMake e Make.

Conectar o Raspberry Pi Pico ao computador em modo bootloader.

Transferir o arquivo UF2 compilado para o Raspberry Pi Pico.

O dispositivo iniciará automaticamente e guiará o usuário na técnica de respiração.


**Imagens e vídeos**



Diagrama de blocos do funcionamento : ![image](https://github.com/user-attachments/assets/454cd3ee-9e51-4ed9-ade9-609ad5cac581)

Apresentação do Projeto : ![image](https://github.com/user-attachments/assets/69f8d15e-e93e-4b7d-aa0a-c1b7c38c07cf)



Link para o vídeo do funcionamento :  https://youtu.be/sk14xKnpJd8?si=rfSoK9_Jz3X5Z1LY  
 

**Resultados esperados ou observados**

O dispositivo deve indicar visualmente as fases da respiração quadrada de forma clara e intuitiva.

A técnica de respiração guiada ajudará a reduzir sintomas de ansiedade e hiperventilação.

O baixo consumo energético garantirá uma boa autonomia da bateria.

O RelaxBerry funcionará de maneira independente, sem necessidade de aplicativos ou configurações complexas.

O projeto demonstrará a viabilidade do uso de sistemas embarcados no suporte à saúde mental.


# Projeto Contador de Eventos com Interrupção 

**Funcionamento**

Este programa foi desenvolvido para ser executado em uma placa Raspberry Pi Pico e utiliza dois botões físicos e um display OLED com o driver SSD1306. Quando o Botão A (GPIO5) é pressionado, o programa inicia um contador decrescente de 9 até 0, atualizando o display OLED a cada segundo com o valor atual do contador e o número de vezes que o Botão B (GPIO6) foi pressionado durante essa contagem. Cada vez que o Botão B é pressionado enquanto a contagem está ativa, o número de cliques é incrementado e exibido no display. Quando o contador atinge 0, o sistema congela a execução e permanece mostrando o valor 0 e os cliques registrados, até que o Botão A seja pressionado novamente, reiniciando todo o processo. O programa utiliza interrupções por borda de descida para detectar os cliques nos botões, tornando o sistema mais responsivo e eficiente.


**Objetivo**

Implementar um sistema que:

Inicie a contagem de 9 até 0 ao pressionar o Botão A.

Durante essa contagem, conte quantas vezes o Botão B foi pressionado.

Exiba tudo no display OLED.

Após chegar a 0, o sistema congela, e ignora novas pressões do Botão B.

O sistema só reinicia uma nova contagem com uma nova pressão no Botão A.

**Pinagem e Função**


![image](https://github.com/user-attachments/assets/0a0915e5-e05d-42ee-a7b6-042235377e42)

**Fluxo Lógico do Programa**

Inicialização:
     Configura GPIO5 e GPIO6 como entrada com pull-up.
    
     Configura interrupções para os botões.
     
     Inicializa o display OLED.


Interrupção do Botão A (GPIO5):
     Reinicia o contador para 9.
     
     Zera o contador de cliques do Botão B.
     
     Ativa o modo de contagem.

**Loop Principal (ou Timer):**

**Se a contagem estiver ativa:**

     A cada 1 segundo, decrementa o contador.
     
     Atualiza o display com o novo valor e cliques.

**Se o contador chegar a 0:**
    Congela o sistema (desativa contagem).
    
    Ignora cliques no Botão B (por software).

**Interrupção do Botão B (GPIO6):**

    Se a contagem estiver ativa:
    
    Incrementa o contador de cliques.
    
    Atualiza o display.

![image](https://github.com/user-attachments/assets/0baa04f5-3c49-45fb-9990-61ec855c98ac)



# Projeto para ler os valores convertidos digitalmente do joystick da BitDogLab

**Funcionamento**

Este programa foi desenvolvido para ser executado em uma placa Raspberry Pi Pico utilizando dois botões físicos conectados aos GPIOs 5 (Botão A) e 6 (Botão B). Ao pressionar o Botão A, o sistema inicia uma contagem decrescente de 9 até 0, exibida no terminal serial USB. Durante essa contagem, cada vez que o Botão B é pressionado, um contador de cliques é incrementado e também mostrado no terminal. Quando a contagem atinge 0, o sistema congela e permanece exibindo os valores finais no terminal. A contagem só pode ser reiniciada com uma nova pressão no Botão A. O programa utiliza interrupções por borda de descida para detectar os cliques dos botões, garantindo maior eficiência e resposta rápida do sistema.

**Objetivo**

Implementar um sistema que:

Inicie a contagem de 9 até 0 ao pressionar o Botão A (GPIO5).

Durante essa contagem, conte quantas vezes o Botão B (GPIO6) foi pressionado.

Exiba o valor atual do contador e o número de cliques no terminal serial.

Após chegar a 0, o sistema congele e ignore novos cliques no Botão B.

Permita reiniciar a contagem apenas com nova pressão no Botão A.


**Pinagem e função**

![image](https://github.com/user-attachments/assets/d7639fc1-572b-4955-9716-66caedffa8d6)
Obs.: Ambos os pinos são configurados como entrada com pull-up interno ativado.


**Fluxo Lógico do Programa**

Inicialização:

Configura GPIO5 (Botão A) e GPIO6 (Botão B) como entradas com pull-up.

Define interrupções por borda de descida para ambos os botões.

Inicializa a comunicação serial via USB.

Interrupção do Botão A (GPIO5):

Reinicia o contador de 9 até 0.

Zera o contador de cliques do Botão B.

Ativa o modo de contagem.

Loop Principal:

Se a contagem estiver ativa:

A cada 1 segundo, decrementa o contador.

Exibe no terminal o valor atual do contador e o número de cliques.

Se o contador chegar a 0:

Desativa a contagem.

O sistema congela e aguarda nova ativação via Botão A.

Interrupção do Botão B (GPIO6):

Se a contagem estiver ativa:

Incrementa o número de cliques.

Atualiza os dados no terminal.

Imagem do Funcionamento : 

![image](https://github.com/user-attachments/assets/71c0aeeb-0d6c-4217-83d3-74eaaf25e9d3)

# Projeto para ler a temperatura interna do RP2040

**Funcionamento**

Este programa foi desenvolvido para ser executado em uma placa Raspberry Pi Pico (RP2040) utilizando o sensor de temperatura interno do microcontrolador. A cada segundo, o sistema realiza uma leitura do ADC (Conversor Analógico-Digital) interno, que está conectado ao sensor de temperatura embutido no chip. O valor lido é convertido para tensão elétrica e, em seguida, para graus Celsius (ºC) utilizando a fórmula fornecida no datasheet do RP2040. O valor da temperatura é então exibido no terminal serial USB, permitindo o monitoramento em tempo real da temperatura interna do chip.

**Objetivo**

Implementar um sistema que:

Leia a temperatura interna do microcontrolador RP2040 utilizando o canal 4 do ADC.

Converta a leitura analógica para um valor de tensão.

Calcule a temperatura em graus Celsius com base na tensão lida.

Exiba a temperatura no terminal serial USB a cada segundo.

**Obs : o sensor de temperatura é interno ao microcontrolador. A leitura é feita por meio do canal 4 do ADC, que é reservado exclusivamente para esse sensor.**

**Fluxo Lógico do Programa**

Inicialização:

Inicia o sistema e configura o ADC interno.

Habilita o sensor de temperatura interno.

Seleciona o canal 4 do ADC, que está conectado ao sensor interno.

Inicializa a comunicação serial via USB para envio dos dados ao terminal.

Loop Principal:

Realiza a leitura do valor analógico do sensor de temperatura.

Converte o valor lido em uma tensão elétrica (baseado na resolução de 12 bits do ADC).

Converte essa tensão em um valor de temperatura em ºC utilizando a fórmula:

**temperatura = 27.0 - (tensao - 0.706) / 0.001721**


Exibe o valor da temperatura no terminal serial.

Aguarda 1 segundo antes de repetir o processo.

Fluxograma : 

![image](https://github.com/user-attachments/assets/98b7a36b-9496-4c39-bd2f-e543071f949d)


Imagem do funcionamento : 

![image](https://github.com/user-attachments/assets/0b1e18df-ce1e-4846-8a7e-2c7c0642214e) 




