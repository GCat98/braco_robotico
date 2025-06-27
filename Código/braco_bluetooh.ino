#include <Servo.h>
#include <SoftwareSerial.h>

// Objetos Servo
Servo servoBase;     
Servo servoOmbro;    
Servo servoCotovelo; 
Servo servoGarra;    

// Comunicação Bluetooth (pinos 10 = RX, 11 = TX)
SoftwareSerial bluetooth(10, 11);

String comando = "";

void setup() {
  // Define os pinos PWM para os servos
  servoBase.attach(3);
  servoOmbro.attach(5);
  servoCotovelo.attach(6);
  servoGarra.attach(9);

  // Posição inicial dos servos
  servoBase.write(90);
  servoOmbro.write(90);
  servoCotovelo.write(90);
  servoGarra.write(90);

  // Inicializa comunicação serial
  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() {
  while (bluetooth.available()) {
    char c = bluetooth.read();
    comando += c;
    delay(5);
  }

  if (comando.length() >= 1) {
    char cmd = comando.charAt(0);

    if (comando.length() >= 2 && isDigit(comando.charAt(1))) {
      // Comando de servo: formato A90, B45, etc.
      char servoID = cmd;
      int angulo = comando.substring(1).toInt();

      if (angulo >= 0 && angulo <= 180) {
        bool comandoValido = true;

        switch (servoID) {
          case 'A': servoBase.write(angulo); break;
          case 'B': servoOmbro.write(angulo); break;
          case 'C': servoCotovelo.write(angulo); break;
          case 'D': servoGarra.write(angulo); break;
          default:
            comandoValido = false;
            Serial.print("⚠️ Erro: Servo inválido '");
            Serial.print(servoID);
            Serial.println("'");
        }

        if (comandoValido) {
          Serial.print("✅ Comando recebido: Servo ");
          Serial.print(servoID);
          Serial.print(" → Ângulo ");
          Serial.println(angulo);
        }

      } else {
        Serial.print("⚠️ Ângulo inválido: ");
        Serial.println(angulo);
      }
    }

    comando = ""; // Limpa comando
  }
}
