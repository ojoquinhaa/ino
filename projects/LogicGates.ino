/** LOGICAL GATES
 * Programa para demostrar com um led os tipos de
 * portas logicas que existem dentre elas: AND, OR,
 * NAND, NOR, XOR, XNOR, NOT. Para isso e utilizado
 * tres botoes, dois para as portas logicas e outro
 * para trocar dentre elas que estao organizadas na
 * sequencia acima.
 * 
 * BY: OJOQUINHAA =)
 */

 /* Definindo os pinos */
 #define firstButtonPin 16 // DEFAULT: 16
 #define secondButtonPin 5 // DEFAULT: 5
 #define changeButtonPin 12 // DEFAULT: 12
 #define resultLedPin 14 // DEFAULT: 14

 /* VARIAVEIS */
 int firstButtonState;
 int secondButtonState;
 int changeButtonState;
 int logicGate = 1;

 void setup() {
  Serial.begin(115200); // Iniciando o monitor serial
  pinMode(firstButtonPin, INPUT); // Definindo o pino do primeiro botao como entrada
  pinMode(secondButtonPin, INPUT); // Definindo o pino do segundo botao como entrada
  pinMode(changeButtonPin, INPUT); // Definindo o pino do botao de mudanca logica como entrada
  pinMode(resultLedPin, OUTPUT); // Defininfo o pino do led de resultado como saida
 }

 void loop() {
  // Atualizando os valores dos botoes
  firstButtonState = digitalRead(firstButtonPin);
  secondButtonState = digitalRead(secondButtonPin);
  changeButtonState = digitalRead(changeButtonPin);

  // Se o botão for apertado muda o portão logico
  if (changeButtonState == HIGH) {
    logicGate++;
    Serial.println(logicGate);
    if (logicGate == 8) {
      logicGate = 1;
    }
    delay(1000);
  }

  // Analisando e definindo qual portão logico seguir
  switch (logicGate) {
    // AND
    case 1:
      digitalWrite(resultLedPin, firstButtonState && secondButtonState);
      break;

    // OR
    case 2:
      digitalWrite(resultLedPin, firstButtonState || secondButtonState);
      break;

    // NAND
    case 3:
      digitalWrite(resultLedPin, !(firstButtonState && secondButtonState));
      break;

    // NOR
    case 4:
      digitalWrite(resultLedPin, !(firstButtonState || secondButtonState));
      break;

    // XOR
    case 5:
      digitalWrite(resultLedPin, firstButtonState ^ secondButtonState);
      break;

    // XNOR
    case 6:
      digitalWrite(resultLedPin, !(firstButtonState ^ secondButtonState));
      break;

    // NOT
    case 7:
      digitalWrite(resultLedPin, !firstButtonState);
      break;
  }
 }
