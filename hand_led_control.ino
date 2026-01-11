#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// --------- WiFi Credentials ----------
const char* ssid = "Enter Your ssid";
const char* password = "Enter Your Password";

// --------- LED Pins ----------
#define LED1 D1
#define LED2 D2
#define LED3 D3

ESP8266WebServer server(80);

// --------- LED Control Functions ----------
void led1On()  { digitalWrite(LED1, HIGH); server.send(200, "text/plain", "LED1 ON"); }
void led1Off() { digitalWrite(LED1, LOW);  server.send(200, "text/plain", "LED1 OFF"); }

void led2On()  { digitalWrite(LED2, HIGH); server.send(200, "text/plain", "LED2 ON"); }
void led2Off() { digitalWrite(LED2, LOW);  server.send(200, "text/plain", "LED2 OFF"); }

void led3On()  { digitalWrite(LED3, HIGH); server.send(200, "text/plain", "LED3 ON"); }
void led3Off() { digitalWrite(LED3, LOW);  server.send(200, "text/plain", "LED3 OFF"); }

void allOn() {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  server.send(200, "text/plain", "ALL ON");
}

void allOff() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  server.send(200, "text/plain", "ALL OFF");
}

// --------- Setup ----------
void setup() {
  Serial.begin(9600);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  allOff();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
  Serial.print("ESP8266 IP Address: ");
  Serial.println(WiFi.localIP());

  // URL Routes
  server.on("/L1_ON", led1On);
  server.on("/L1_OFF", led1Off);
  server.on("/L2_ON", led2On);
  server.on("/L2_OFF", led2Off);
  server.on("/L3_ON", led3On);
  server.on("/L3_OFF", led3Off);
  server.on("/ALL_ON", allOn);
  server.on("/ALL_OFF", allOff);

  server.begin();
}

// --------- Loop ----------
void loop() {
  server.handleClient();
}
