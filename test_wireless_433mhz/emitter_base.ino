#include <VirtualWire.h> // Vous devez télécharger et installer la librairie VirtualWire.h dans votre dossier "/libraries" !

int ledPin=9;

void setup()
{
    Serial.begin(9600);
    vw_setup(2000);               // Bits par seconde (vous pouvez le modifier mais cela modifiera la portée). Voir la documentation de la librairie VirtualWire.
    vw_set_tx_pin(3);             // La broche 3 sera utilisée pour transmettre la DATA, vous pouvez changez de broche si vous le désirez.
}

void loop()
{
   const char *msg="envoi : 1337";                        // C'est le message à envoyer.
   vw_send((uint8_t *)msg, strlen(msg));
   vw_wait_tx();                                          // On attend que le message complet soit envoyé.
   digitalWrite(ledPin,HIGH);
   delay(120);
   digitalWrite(ledPin,LOW);
   delay(200);                                            // Très important sinon cela peut brouiller d'autres appareils !
}
