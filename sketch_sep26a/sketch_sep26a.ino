//pinos do sensor
const int s0 = 8;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;
 
//Variaveis cores
int red = 0;
int green = 0;
int blue = 0;

void setup()
{
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  Serial.begin(9600);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
}
 
void loop()
{
  if (Serial.available() > 0) {
    if(Serial.read() == 'A'){//comando para detectar cor pela serial
      color();//função que detecta as cores
      int vermelho = 0;
      int azul = 0;
      int verde = 0;
      for(int i=0;i<5;i++){
        if (red < blue && red < green && red < 100)
        {
          vermelho++;
        }
        else if (blue < red && blue < green && blue < 1000)
        {
          azul++;
        }
        else if (green < red && green < blue)
        {
          verde++;
        }
      }
      //feito total de 5 verificações
      //retorna a cor que atingir as 5 confirmações
      if(vermelho == 5)Serial.println("Vermelho");      
      else if(azul == 5)Serial.println("azul");      
      else if(verde == 5)Serial.println("verde");
      else Serial.println("nao reconhecido");
    }
    delay(100);
  }
}
 
void color()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
