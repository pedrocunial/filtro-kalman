#define BUFF_SIZE 100

#define DigitalRight 10
#define DigitalLeft 11

#define PWMRight 32
#define PWMLeft 33

char buffer[BUFF_SIZE];

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
    buffer[i++] = Serial1.read();
    if(i == BUFF_SIZE) 
      break;
  }
  for(int j = 0; j < i; j++) {
    Serial.print(buffer[j]);
    Serial.print("|");
  }
}
