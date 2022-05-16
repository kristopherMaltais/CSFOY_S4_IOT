#include <Arduino.h>
#include <wifi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#define WIFI_SSID "VIRGIN599"
#define WIFI_PASSWORD "242DAA63D5AE"


const char* obtenirIPPublique()
{
  const char* resultat = "";

  if(WiFi.status() == WL_CONNECTED)
  {
    String url = "https://ifconfig.co/json";
    HTTPClient httpClient;
    httpClient.begin(url);
    int codeStatut = httpClient.GET();

    if(codeStatut != 200)
    {
      Serial.println(HTTPClient::errorToString(codeStatut));
    }
    else
    {
      resultat = httpClient.getString().c_str();
    }
  }
  else
  {
    Serial.println("Non connecté au WiFi...");
  }

  return resultat;
}
const char* deserializer(const char* p_chaineJson)
{
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, p_chaineJson);

  if (error)
  {
    Serial.print(F("deserializedJson() failed: "));
    Serial.println(error.f_str());
    
  }

  return doc["ip"];

}
void verifierConnexion()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.begin(115200);
  Serial.print("Connexion : ");

  int nbEssais = 0;
  int nbEssaisMaximum = 30;
  while(nbEssais < nbEssaisMaximum && WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    nbEssais++;

  }

  Serial.println("");

  if(WiFi.status() == WL_CONNECTED)
  {
    Serial.print("connecté au réseau wifi, adresse IP : ");
    Serial.println(WiFi.localIP());
    Serial.println("");
  }
  else
  {
      Serial.print("Non Connecté...");
  }

  const char* test = obtenirIPPublique();
  Serial.print(deserializer(test));
}


void setup() {
  verifierConnexion();
}

void loop() {

}

