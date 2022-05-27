String recebido;
String sequenciaNumerica = "";
int led;
long numeroGerado;
char stateGame = 0;
int sequencia;
String botoes = "";
int buzzer = 12;
int x = 0;
int botao;

void setup() {
  // Iniciar comunicacao serie
  Serial.begin(9600);
  // Definir LEDs como OUTPUTs pinos 8,9,10 e 11
  for(int led = 8; led <= 11; led++){
    pinMode(led, OUTPUT);
  } 
  // Definir Botoes como OUTPUTs pinos 2,3,4 e 5
  for(int botao = 2; botao <= 5; botao++){
      pinMode(botao, INPUT_PULLUP); ;
 } 
  pinMode(buzzer, OUTPUT);
  // Definir a seed do gerador de números aleatórios
  randomSeed(analogRead(0));
}

void loop() {
  switch (stateGame) {
    case 0:
      // inicio de jogo
      Serial.println("* INICIO *");
      Serial.println("Comecar? (s/n)");
      if (digitalRead(botao == 1) == LOW){
        stateGame = 1;
        Serial.println("Jogo começando...");
        piscaled(1000,3);
      } else if(digitalRead(botao == 2) == LOW ) {
        stateGame = 3;
        Serial.println("Jogo não iniciado"); 
        piscaled(300,5);     
      }
      break;

  
    case 1:
      // Nivel 1 
      for(int i = 2;i < 100; i++){
      botoes = "";
      Serial.println("Se prepare");
      geraSequencia(500, i); 
      leserial(i);
      if (botoes == sequenciaNumerica){

        Serial.println("Parabens! proximo nivel");
        piscaled(1000,3);
      } else {
        stateGame = 2;
        Serial.println("Errooooo!!!"); 
        piscaled(300,5);  
        break;
      }
}

    case 2:
      // Game over!!!
      Serial.println("Game Over"); 
      piscaled(100,5);
      stateGame = 3;
      break;
      
    case 3:
      Serial.println("jogar novamente? (s/n)"); 
      if (digitalRead(botao == 1) == LOW){
        stateGame = 1;
        Serial.println("Jogo comecando...");
        piscaled(500,3);
      } else if(digitalRead(botao == 2) == LOW ) {
        stateGame = 3;
        Serial.println("Jogo não iniciado"); 
        piscaled(300,5);     
      }
      break;
  }
}

void leserial(int i){
  Serial.println("* Insira sua resposta *");
  while(1) {
    if (digitalRead(botao == 1) == LOW){
        delay(200);
        botoes = botoes + 1;
        digitalWrite(8, HIGH);
        tone(buzzer, 500);
        delay(500);
        noTone(buzzer);
        digitalWrite(8, LOW);
        x++;
      }else if (digitalRead(botao == 2) == LOW){
        delay(200);
        botoes = botoes + 2;
        digitalWrite(9, HIGH);
        tone(buzzer, 1000);
        delay(500);
        noTone(buzzer);
        digitalWrite(9, LOW);
        x++;
      }else if (digitalRead(botao == 3) == LOW){
        delay(200);
        botoes = botoes + 3;
        digitalWrite(10, HIGH);
        tone(buzzer, 1500);
        delay(500);
        noTone(buzzer);
        digitalWrite(10, LOW);
        x++;
      }else if (digitalRead(botao == 4) == LOW){
        delay(200);
        botoes = botoes + 4;
        digitalWrite(11, HIGH);
        tone(buzzer, 2000);
        delay(500);
        noTone(buzzer);
        digitalWrite(11, LOW);
        x++;
      }else if (x == i){
        x = 0;
        delay(500);
        break;
      }  
   }
}

void piscaled(int tempo, int vezes){
  for(int i = 0;i < vezes; i++){
    for(int led = 8; led <= 11; led++){
      digitalWrite(led, HIGH);
    }
    delay(tempo);
    for(int led = 8; led <= 11; led++){
      digitalWrite(led, LOW);
    }
    delay(tempo);
  }
}



void geraSequencia (int tempo, int sequencia){
  // Criar uma lista de inteiros com o tamanho que e passado como argumento
  int ordemLeds[sequencia];

  // Gerar sequencia aleatoria
  for (int i = 0; i < sequencia; i++){
    numeroGerado = random(1, 5);
    ordemLeds[i] = numeroGerado;
  }

  // Inicialmente, a String sequenciaNumerica é uma String vazia
  sequenciaNumerica = "";

  // Pisca os LEDs na sequencia gerada
  for (int j = 0; j < sequencia; j++){
    led = ordemLeds[j];
    if (led == 1){
      digitalWrite(8, HIGH);
      tone(buzzer, 500);
      delay(tempo);
      noTone(buzzer);
      digitalWrite(8, LOW);
      delay(tempo);
    }else if (led == 2){
      digitalWrite(9, HIGH);
      tone(buzzer, 1000);
      delay(tempo);
      noTone(buzzer);
      digitalWrite(9, LOW);
      delay(tempo);
    }else if (led == 3){
      digitalWrite(10, HIGH);
      tone(buzzer, 1500);
      delay(tempo);
      noTone(buzzer);
      digitalWrite(10, LOW);
      delay(tempo);
    }else if (led == 4){
      digitalWrite(11, HIGH);
      tone(buzzer, 2000);
      delay(tempo);
      noTone(buzzer);
      digitalWrite(11, LOW);
      delay(tempo);
    }
    // Converte a lista numa String   
    sequenciaNumerica = sequenciaNumerica + led;
  }
}
