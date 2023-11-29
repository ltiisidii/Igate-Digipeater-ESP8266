#include "WebServerManager.h"
#include <LittleFS.h>

WiFiServer server(80);

void setupWebServer() {
  LittleFS.begin();  // Inicia LittleFS
  server.begin();
  Serial.println("Server started");
  Serial.print("Use this URL to connect: http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void handleWebServer() {
  WiFiClient client = server.accept();
  if (!client) {
    return;
  }

  while (!client.available()) {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Determinar la ruta solicitada
  String path = request.substring(request.indexOf(' ') + 1, request.lastIndexOf(' '));
    if (path == "/" || path == "/index.html") {
      serveFile(client, "/index.html", "text/html");
    } else if (path == "/css/styles.css") {
      serveFile(client, "/css/styles.css", "text/css");
    } else if (path == "/js/script.js") {
      serveFile(client, "/js/script.js", "application/javascript");
    } else if (path == "/css/bootstrap.min.css") {
      serveFile(client, "/css/bootstrap.min.css", "text/css");
    } else if (path == "/js/jquery-3.5.1.slim.min.js") {
      serveFile(client, "/js/jquery-3.5.1.slim.min.js", "application/javascript");
    } else if (path == "/js/popper.min.js") {
      serveFile(client, "/js/popper.min.js", "application/javascript");
    } else if (path == "/js/bootstrap.min.js") {
      serveFile(client, "/js/bootstrap.min.js", "application/javascript");
    } else {
    // Manejar otras rutas según sea necesario
    // Puedes agregar más rutas y su manejo aquí
    // Por ejemplo, puedes manejar solicitudes de imágenes, etc.
  }

  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}

void serveFile(WiFiClient& client, const char* path, const char* contentType) {
  File file = LittleFS.open(path, "r");
  if (!file) {
    Serial.println("Error al abrir el archivo: " + String(path));
    return;
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: " + String(contentType));
  client.println("");

  while (file.available()) {
    client.write(file.read());
  }

  file.close();
}
