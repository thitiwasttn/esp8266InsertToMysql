#include <ESP8266WiFi.h>

const char* ssid = "tns8";

const char* password = "pppppppp";

const char* host = "192.168.43.10"; //ใส่ IP หรือ Host ของเครื่อง Database ก็ได้

const int httpPort = 80;

int value = 1;

void setup() 
{

  Serial.begin(9600);

  delay(10);


  Serial.print("Connecting to ");

  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {

    delay(500);

    Serial.print(".");

  }

  Serial.println("");

  Serial.println("WiFi connected");

  Serial.println("IP address: ");

  Serial.println(WiFi.localIP());

}

void loop() 
{

  Serial.print("connecting to ");

  Serial.println(host);

  WiFiClient client;

  if (!client.connect(host, httpPort)) 
  {

    Serial.println("connection failed");

    return;

  }

  String url = "http://192.168.43.10/iot/insert.php?value="; //ชุด Directory ที่เก็บไฟล์ และตัวแปรที่ต้องการจะฝาก /ProjectCL/index.php?module=MCU&Rooms=0&Status=Wh&Data=

  url += value; //ส่งค่าตัวแปร
  value++;

  Serial.print("Requesting URL: ");

  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +

               "Host: " + host + "\r\n" +

               "Connection: close\r\n\r\n");

  unsigned long timeout = millis();

  while (client.available() == 0) 
  {

    if (millis() - timeout > 5000) 
    {

      Serial.println(">>> Client Timeout !");

      client.stop();

      return;

    }

  }

  // Read all the lines of the reply from server and print them to Serial

  while (client.available()) 
  {

    String line = client.readStringUntil('\r');

    Serial.print(line);

  }

  Serial.println();

  Serial.println("closing connection");

  delay(10000);
}
