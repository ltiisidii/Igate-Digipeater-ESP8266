#include "WebServerManager.h"

const char* ssid = "ssid_name"; // ssid_name
const char* password = "password_wifi";  // password_wifi
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
  WiFiClient client = server.accept();
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

  // Devuelve la respuesta al cliente
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"></head>");
  client.println("<body>");

  client.println("<h1>Información de la red Wi-Fi</h1>");
  client.print("<p>Nombre de la red Wi-Fi: ");
  client.print(ssid);
  client.println("</p>");
  client.print("<p>Dirección IP: ");
  client.print(WiFi.localIP());
  client.println("</p>");

  client.println("</body>");
  client.println("</html>");

  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}
