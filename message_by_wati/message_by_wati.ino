#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "AXIO LIMITED";
const char* password = "xttok2fb";
const char* phoneNumber = "923321363803";
const char* endpoint = "https://app-server.wati.io/api/v1/sendSessionMessage/";
const char* authToken = "Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJqdGkiOiJjZTU0NmQ2Mi1hY2RlLTQ5MDYtOWRjNi1kNDNlYmQyZmUwZGIiLCJ1bmlxdWVfbmFtZSI6InNoYWthaWJuYXF2aTQwMUBnbWFpbC5jb20iLCJuYW1laWQiOiJzaGFrYWlibmFxdmk0MDFAZ21haWwuY29tIiwiZW1haWwiOiJzaGFrYWlibmFxdmk0MDFAZ21haWwuY29tIiwiYXV0aF90aW1lIjoiMDYvMjgvMjAyNCAxMDo0NTo1MSIsImRiX25hbWUiOiJ3YXRpX2FwcF90cmlhbCIsImh0dHA6Ly9zY2hlbWFzLm1pY3Jvc29mdC5jb20vd3MvMjAwOC8wNi9pZGVudGl0eS9jbGFpbXMvcm9sZSI6IlRSSUFMIiwiZXhwIjoxNzIwMjI0MDAwLCJpc3MiOiJDbGFyZV9BSSIsImF1ZCI6IkNsYXJlX0FJIn0.G-sbqojOV3zRIlVaA3IC9pJEUckLEkmLuh6lvJiLgGE";

void send_messagee_wati(String messageText) {

  HTTPClient http;

  // Construct the complete URL with phoneNumber and messageText
  String url = String(endpoint) + phoneNumber + "?messageText=" + messageText;

  http.begin(url);

  http.addHeader("Authorization", authToken);
  int httpResponseCode = http.POST("");

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}


void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  // Empty, since we are not doing anything in the loop
  send_messagee_wati("This Message is from ESP32");
  delay(10000);
}
