#define led  5
#define kickread 1
#define rst 0

unsigned char highcount = 0;
unsigned char lowcount = 0;
bool rstFlg = 0;
void setup(){
  pinMode(kickread,INPUT);
  pinMode(rst,OUTPUT);
  pinMode(led,OUTPUT);
}
void loop(){
  digitalWrite(rst,HIGH);
  if(rstFlg){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
  
  if(digitalRead(kickread)==HIGH){
    highcount++;
    lowcount = 0;
  }else{
    lowcount++;
    highcount = 0;
  }
  if(highcount>100 || lowcount>100){
    digitalWrite(rst,LOW);
    rstFlg=1;
    delay(1);
    digitalWrite(rst,HIGH);
    delay(500);
    lowcount = 0;
    highcount = 0;
  }
  delay(1);
}

