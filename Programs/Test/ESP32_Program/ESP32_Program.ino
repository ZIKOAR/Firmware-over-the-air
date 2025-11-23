#include <WebServer.h>
#include <WiFi.h>

#include "htmlPage.h"

#define BIN_FILE_SIZE 16000

char *binFileBytes = nullptr;
char byteData;
String binFileHexString;
String byteString;
uint32_t binFileHexLen = 0;
uint32_t counter = 0;

const char *ssid = "SWISS";
const char *pass = "swiss006";

const char *http_username = "admin0";
const char *http_password = "admin0";

WebServer server(80);

bool isAuthorized();
void handleRoot();
void handleFirmwareReceive();

void setup() {
    Serial.begin(115200);
    while (!Serial) {
    }

    Serial.print("Available heap: ");
    Serial.print(ESP.getFreeHeap());
    Serial.println("");

    binFileBytes = (char *)malloc(BIN_FILE_SIZE);
    if (!binFileBytes) {
        Serial.println("Failed to allocate memory!");
        while (true) {
            delay(500);
            Serial.print(".");
        }
    }

    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");

    Serial.print("Connected to network: ");
    Serial.print(ssid);
    Serial.print(", IP address: ");
    Serial.println(WiFi.localIP());
    delay(100);

    server.on("/", handleRoot);
    server.on("/fota", handleFirmwareReceive);
    server.begin();
    Serial.println("Web server started!");
}

void loop() { server.handleClient(); }

bool isAuthorized() {
    if (!server.authenticate(http_username, http_password)) {
        server.requestAuthentication();
        return false;
    }

    return true;
}

void handleRoot() {
    if (!isAuthorized())
        return;

    server.send(200, "text/html", htmlPage);
}

void handleFirmwareReceive() {
    if (!isAuthorized())
        return;

    Serial.println("Start FOTA update!");

    if (!server.hasArg("plain")) {
        Serial.println("No plain body found!");
        server.send(400, "text/plain", "No plain body found!");
        return;
    }

    binFileHexString = server.arg("plain");
    binFileHexLen = binFileHexString.length();

    for (uint32_t i = 0; i < binFileHexLen; i += 3) {
        byteString = binFileHexString.substring(i, i + 2);
        byteData = (char)strtol(byteString.c_str(), nullptr, 16);
        binFileBytes[counter++] = byteData;
    }

    // COMPARE A SAMPLE OF BYTES
    /* for (int i = 0; i < 16; i++) {
        Serial.printf("%02X ", (uint8_t)binFileBytes[i]);
    }
    Serial.println(); */

    String message = "OK, " + String(counter) + " " + String(binFileHexLen);
    server.send(200, "text/plain", message);
}
