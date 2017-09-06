#include<math.h>
#define publish_delay 1000
unsigned int lastPublish = 0;

void setup() {
}

void loop() {
    unsigned long now = millis();
    if ((now - lastPublish) < publish_delay) {
        return;
    }

    int x_value = analogRead(A0); //x-axis values
    int y_value = analogRead(A1); //y-axis values
    int z_value = analogRead(A2); //z-axis vaues
    int f_value = analogRead(A3); //flex sensor values
    int a=sqrt(((A0)^2)+((A1)^2+((A2)^2))); //formula to calculate average acceleration
    Particle.publish("thingSpeakWrite_a", "{ \"1\": \"" + String(a) + "\", \"k\": \"OXNO5VS2HW6WQISH\" }", 60, PRIVATE);
    Particle.publish("thingSpeakWrite_f", "{ \"1\": \"" + String(a) + "\", \"k\": \"OXNO5VS2HW6WQISH\" }", 60, PRIVATE);
}
