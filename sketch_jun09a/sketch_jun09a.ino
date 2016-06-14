#define BUFF_SIZE 40
char buffer[BUFF_SIZE];

void setup() {
    Serial.begin(57600);
    Serial.println("Starting Communication with Razor IMU");
}

void loop() {

    int i = 0;
    while(Serial.available()) {
        Serial.println("Teste");
        buffer[i++] = Serial.read();

        // Print it out in many formats:
        Serial.println(buffer[i]);       // print as an ASCII-encoded decimal
        Serial.println(buffer[i], DEC);  // print as an ASCII-encoded decimal
        Serial.println(buffer[i], HEX);  // print as an ASCII-encoded hexadecimal
        Serial.println(buffer[i], OCT);  // print as an ASCII-encoded octal
        Serial.println(buffer[i], BIN);  // print as an ASCII-encoded binary
        // Serial.println(buffer[i], BYTE); // print as a raw byte value

        if(i == BUFF_SIZE)
            break;
    }

    // for(int j = 0; j < i; j++) {
    //     Serial.print(buffer[j]);
    //
    // }

}
