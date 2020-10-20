unsigned int startTime;

void setup() {
  Serial.begin(9600); //begin communication via serial port, 9600 bit/s
  Serial.println("Connection established");  //message about connection
  startTime = millis(); //save time when the program starts
}

// Function that returns formatted time
String getFormattedTime(){
  unsigned long timeInMs = millis() - startTime;  //calculate current time in ms
  unsigned int timeS = timeInMs / 1000; //convert to s
  unsigned int timeM = timeInMs / 60000;  //convert to m
  unsigned int timeH = timeInMs / 3600000;  //convert to h
  return String(timeH) + ":" + String(timeM % 60) + ":" + String(timeS % 60); //format time
}
void loop() {
  //send formatted time via serial port
  Serial.println(getFormattedTime());
  
  //wait one second
  delay(1000);
}
