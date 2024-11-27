//Definir os pinos dos LEDs 
int leds[4] = {9,8,7,6};
//Definir pinos dos botoes
int botoes[4] = {2,3,4,5};
//Pinos do display 
int leds_display[7]={10,11,12,13,A0,A1,A2};
//Definir as variáveis do jogo
int sequencia[10];
int nivel = 0;
int estadoBotao = 0;
int comparaSequencia =0;
int estadoPartida = true;
bool jogadorPerdeu = false;

void setup(){
//definindo que os pinos dos leds são saídas
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT); 
//definindo que os pinos dos botoes são entradas
  pinMode(5,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  
  //inicioJogo();
}
void loop(){
  
  proximoNivel();
  reproduzirSequencia();
  jogador();
  //delay(1000);
  
  if (jogador()) {
    
    nivel++;
    
    if (nivel == 9) {
      
      nivel = 0;
    } else {
      
      //mostrarNivel(nivel);
    }
  } else {
     int i;
    while(i < 4){
      
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
      i++;
    } 

    nivel = 0; 
    comparaSequencia = 0;
    estadoPartida = true; 
    //mostrarNivel(nivel);

  }
}  
//criterio 2: ascender e apagar em ordem especifica
 void inicioJogo() {

  for(int i=0; i<3; i++) 
  {
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    delay(300);
    
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    delay(300);
    
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
    delay(300);
    
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(6,LOW);
    delay(300);
  }
  delay(1000);
 }
  
void proximoNivel()
{
  if(nivel <= sequencia[10]){
    int numAleatorio = random(4);
    sequencia[nivel] = numAleatorio;
    nivel = nivel + 1;
  }
}
 void reproduzirSequencia()
  {
    for(int i=0; i < nivel; i++){
      digitalWrite(leds[sequencia[i]],HIGH);
      delay(500);
      digitalWrite(leds[sequencia[i]],LOW);
      delay(500);
    }
  }

 bool jogador() {
  for (int i = 0; i < nivel; i++) {
    if(leds[i] == botoes[i]){}
   	 bool jogou = false;
   	 while (!jogou) {
      for (int i = 0; i < 4; i++) {
        if (digitalRead(botoes[i]) == HIGH) {
          estadoBotao = i;
          digitalWrite(leds[i], HIGH);
          delay(500);
          digitalWrite(leds[i], LOW);
          delay(500);
          jogou = true;
        }
      }
    }
    if (sequencia[comparaSequencia] != estadoBotao) {
      estadoPartida = false;
      break;
    }
    comparaSequencia++;
  }
  comparaSequencia = 0;
  return estadoPartida;