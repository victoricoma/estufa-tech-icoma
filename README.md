# 🌱 Estufa Automatizada com Arduino - Controle de Luz para Mudas de Alface

Este projeto tem como objetivo desenvolver um sistema automatizado com **Arduino UNO**, que utiliza um **sensor de luminosidade (LDR)**, **LEDs indicadores** e um **servo motor** responsável por ajustar **persianas de compensado**. O sistema regula a quantidade de luz solar que entra na estufa, proporcionando condições ideais para o crescimento de mudas de alface.

## 🛠 Componentes Utilizados

| Componente         | Quantidade |
|--------------------|------------|
| Arduino Uno        | 1          |
| Sensor LDR         | 1          |
| Resistores (10kΩ)  | 1          |
| LEDs (Vermelho, Amarelo, Verde) | 3          |
| Servo motor (SG90 ou similar) | 1          |
| Persiana com 3 pás de compensado | 1 conjunto |
| Jumpers e protoboard | Diversos |

---

## 🧠 Lógica de Funcionamento

O sistema funciona conforme os seguintes níveis de luminosidade detectados pelo sensor LDR:

- 🔴 **LED Vermelho:** Baixa luminosidade - as pás se abrem para permitir mais luz.
- 🟡 **LED Amarelo:** Luminosidade moderada - as pás ficam em posição intermediária.
- 🟢 **LED Verde:** Luminosidade ideal ou alta - as pás se fecham parcialmente para proteger as mudas.

A abertura das persianas é feita por meio de um servo motor que ajusta **três pás anguladas**, simulando a ação de venezianas.

---

## ⚙️ Diagrama de Ligação

- O LDR está conectado a uma entrada analógica (A0).
- Os LEDs estão conectados aos pinos digitais (ex: D2, D3, D4).
- O servo motor está conectado ao pino PWM (ex: D9).
- Os resistores estão ligados em série com o LDR e LEDs, conforme o circuito.

---

## 🧾 Código de Exemplo

```cpp
#include <Servo.h>

const int ldrPin = A0;
const int ledVerde = 2;
const int ledAmarelo = 3;
const int ledVermelho = 4;
const int servoPin = 9;

Servo meuServo;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  meuServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  int leituraLuz = analogRead(ldrPin);
  Serial.println(leituraLuz);

  if (leituraLuz < 300) {
    // Pouca luz
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    meuServo.write(0); // Persiana totalmente aberta
  } else if (leituraLuz < 600) {
    // Luminosidade moderada
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    meuServo.write(90); // Persiana semiaberta
  } else {
    // Muita luz
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
    meuServo.write(180); // Persiana fechada
  }

  delay(1000);
}
````

---

## 📸 Funcionamento Visual

* O sistema utiliza **3 pás de madeira compensada** presas a um eixo controlado por servo motor.
* O sistema pode ser replicado em uma **miniestufa didática** ou um protótipo para cultivo doméstico.
* Veja imagem ilustrativa na pasta `/images`.

---

## 🎯 Objetivos de Aprendizado

* Controle de sensores analógicos com Arduino.
* Uso prático de servos e PWM.
* Lógica condicional em automação agrícola.
* Aplicação real de IoT e sistemas embarcados na agricultura.

---

## 🧪 Sugestões de Melhorias Futuras

* Integração com display LCD para exibir o nível de luz.
* Uso de sensores de temperatura e umidade para decisões compostas.
* Controle via app com ESP8266 ou ESP32.
* Logging dos dados de luminosidade com cartão SD.

---

## 📄 Licença

Projeto licenciado sob [MIT License](LICENSE).

---

## 🤝 Contribuições

Contribuições são bem-vindas! Para contribuir, faça um fork, crie uma branch (`git checkout -b melhoria`), e envie um Pull Request.


