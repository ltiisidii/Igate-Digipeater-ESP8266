#include "WebServerManager.h"

const char* ssid = "wifialaqueconectarse";
const char* password = "passwordwifi";
int ledPin = 2; // GPIO2 en NodeMCU
WiFiServer server(80);

void connectToWiFi() {
  // Intenta conectarse a la red WiFi
  WiFi.begin(ssid, password);

  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void setupWebServer() {
  // Inicia el servidor
  server.begin();
  Serial.println("Server started");

  // Imprime la dirección IP
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void handleWebServer() {
  // Espera a que un cliente se conecte
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Espera hasta que el cliente envíe algunos datos
  while (!client.available()) {
    delay(1);
  }

  // Lee la primera línea de la solicitud
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Procesa la solicitud
  int value = HIGH; // Inicialmente apagado
  if (request.indexOf("/LED=OFF") != -1) {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, LOW);
    value = LOW;
  }

  // Devuelve la respuesta al cliente
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.print("Led pin is now: ");
  if (value == HIGH) {
    client.print("Off");
  } else {
    client.print("On");
  }
  client.println("");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br />");
  client.println("</html>");

  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}
