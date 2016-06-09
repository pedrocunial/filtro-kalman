#define BUFF_SIZE 40
char buffer[BUFF_SIZE];

void setup(){
  Serial.begin(57600);
  Serial1.begin(57600);
  Serial1.write("#o1");  
  Serial.println("Starting Communication with Razor IMU");
}

void loop() {
  Serial1.write("#o1");
  int i = 0;
  while(Serial1.available()) {
    buffer[i++] = Serial1.read();
    Serial.println(buffer[i]);
    if(i == BUFF_SIZE) 
      break;
  }

  for(int j = 0; j < i; j++) {
    Serial.print(buffer[j]);
  }

}
