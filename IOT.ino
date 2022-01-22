#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

//this is the username/password of your wifi
#define WIFI_SSID "Research_Wifi"
#define WIFI_PASSWORD "Research2017"

//THIS WHERE YOUR COMMAND DATA GOES
#define FIREBASE_HOST "robotics-workshop-2019.firebaseio.com"
#define FIREBASE_AUTH "89LQm6aMho81UcncsWM0xhHaIiwnv9wMJuwrBLY8"

//VARIABLES DESIGNATED BY PROGRAAMMER TO INSTRUCT OUR MICROCONTROLLER ON WHAT PINS TO MAKE IT FUNCTION

int LEDLIGHT = 4;
int FIREBASEDATA;

// put your setup code here, to run once:
void setup() {

  Serial.begin(9600); // THIS LINE OF CODE IS FOR SERIAL COMMUNICATION

//THIS LINES OF CODES IS FOR WIFI CONNECTION
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(LEDLIGHT, OUTPUT);
  
}

void loop() {
//THIS LINES OF CODES IS FOR TELLING THE NODEMCU IF FIREBASE DATA IS SET ON OR OFF
  motor = Firebase.getString("motor").toInt();
  if(FIREBASEDATA == 1){
    digitalWrite(LEDLIGHT, HIGH);
  }
  else {
    digitalWrite(LEDLIGHT, LOW);
  }
}
