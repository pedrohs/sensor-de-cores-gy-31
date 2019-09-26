const int s0 = 8;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;
 
//Variaveis cores
int red = 0;
int green = 0;
int blue = 0;

int vermelho = 0;
int verde = 0;
int azul = 0;


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
    if(Serial.read() == 'A'){
      color();
      vermelho = 0;
      azul = 0;
      verde = 0;
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
  //Rotina que le o valor das cores
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  //count OUT, pRed, RED
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  //count OUT, pBLUE, BLUE
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  //count OUT, pGreen, GREEN
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
