#define BUFF_SIZE 40

#define DigitalRight 10
#define DigitalLeft 11

#define PWMRight 32
#define PWMLeft 33


char buffer[BUFF_SIZE];
String list;
String num1;
String num2;
String num3;
void setup(){

  pinMode(DigitalRight, OUTPUT);
  pinMode(DigitalLeft, OUTPUT);

  pinMode(PWMRight, OUTPUT);
  pinMode(PWMLeft, OUTPUT);

  Serial.begin(57600);
  Serial1.begin(57600);
  Serial1.write("#o1");


  Serial.println("Starting Communication with Razor IMU");
}

void loop() {


  int i = 0;
  while(Serial1.available()) {
    digitalWrite(DigitalRight,HIGH);
    digitalWrite(DigitalLeft,HIGH);
    list = Serial1.readStringUntil('#');
    list = list.substring(4);
    int comma1 = list.indexOf(',');
    int comma2 = list.indexOf(',',comma1 + 1);
    num1 = list.substring(0,comma1);
    num2 = list.substring(comma1 + 1,comma2);
    num3 = list.substring(comma2 + 1);

    float ang  = num3.toFloat();
    
    // Calibrações de motores e peso do robô (centro de massa)
    float kRight =.43;  // Motor da direita (lado do "hora do show")
    float kLeft  =  1;  // Motor da esquerda (lado sem o "hora do show")
    float kFront =.87;  // Frente (lado com "Hora do show")
    float kBack  = .7;  // Costas (lado sem "Hora do show")
    Serial.print(ang);
    if (ang < 140 && ang > -140){
        // Costas
        analogWrite(PWMRight,  255 * kRight * kBack);
        analogWrite(PWMLeft , -255 * kLeft  * kBack);
    }
    else {
        // Frente
        analogWrite(PWMRight, -255 * kRight * kFront); 
        analogWrite(PWMLeft ,  255 * kLeft  * kFront);
    }

    Serial.println(num2);
    if(i == BUFF_SIZE)
        break;
    }
}
