# 🤖 Controle de Braço Robótico com Arduino via Bluetooth

Este projeto permite o **controle remoto de um braço robótico** com 4 servos motores (Base, Ombro, Cotovelo, Garra) utilizando **comunicação Bluetooth** com um módulo como HC-05 ou HC-06.

---

## 📦 Componentes Utilizados

- Arduino Uno (ou compatível)  
- 4 Servos motores (SG90 ou MG996R, por exemplo)  
- Módulo Bluetooth HC-05 ou HC-06  
- Fonte externa para os servos (recomendado)  
- Jumpers macho-macho  
- Protoboard (opcional)  

---

## 🎯 Funcionalidades

- Controle individual de cada servo motor através de comandos simples via Bluetooth.
- Cada comando define o ângulo de um servo específico entre 0° e 180°.

---

## 🔌 Conexões

### Servos
| Servo        | Pino Arduino |
|--------------|--------------|
| Base         | 3            |
| Ombro        | 5            |
| Cotovelo     | 6            |
| Garra        | 9            |

### Bluetooth (HC-05 / HC-06)
| Módulo       | Arduino      |
|--------------|--------------|
| TX           | 10 (RX Soft) |
| RX           | 11 (TX Soft) |
| VCC          | 5V           |
| GND          | GND          |

> ⚠️ Obs: Use divisor de tensão para o pino RX do módulo Bluetooth (pois ele opera em 3.3V).

---

## 📲 Comandos via Bluetooth

Envie os comandos através de um app serial Bluetooth (como o [Serial Bluetooth Terminal](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal)).

Formato: **[ServoID][Ângulo]**

| Comando Exemplo | Ação                         |
|------------------|------------------------------|
| `A90`           | Base gira para 90°           |
| `B45`           | Ombro move para 45°          |
| `C120`          | Cotovelo move para 120°      |
| `D0`            | Garra fecha completamente    |

---

## 🧠 Lógica do Código

- A comunicação Bluetooth é lida via `SoftwareSerial`.
- O comando recebido é analisado: a primeira letra indica o servo (`A` a `D`) e o número seguinte o ângulo.
- Cada servo é movimentado com o método `.write()` da biblioteca Servo.

---

## 📷 Imagem (Opcional)

> Adicione aqui uma imagem do braço robótico em funcionamento ou do circuito montado.

---

## 🎥 Demonstração

📥 [Clique aqui para baixar e assistir o vídeo](./Imagens/Braço_robótico.mp4)

---

## 📜 Licença

Este projeto está sob a licença MIT. Sinta-se livre para modificar e reutilizar!
