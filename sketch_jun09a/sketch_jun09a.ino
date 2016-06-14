#define BUFF_SIZE 40
char buffer[BUFF_SIZE];

void setup() {
    Serial.begin(57600);
    Serial.println("Starting Communication with Razor IMU");
}

void loop() {
    int i = 0;
    while(Serial.available()) {
        buffer[i++] = Serial.read();
        // Serial.println(buffer[i]);
        if(i == BUFF_SIZE)
            break;
    }

    for(int j = 0; j < i; j++) {
        Serial.print(buffer[j]);
    }
    Serial.print('\n');
}
