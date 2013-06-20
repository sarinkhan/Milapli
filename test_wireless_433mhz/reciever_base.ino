#include <VirtualWire.h> // Vous devez télécharger et installer la librairie VirtualWire.h dans votre dossier "/libraries" !

void setup()
{
    Serial.begin(9600);    
    vw_setup(2000);               // Bits par seconde (vous pouvez le modifier mais cela modifiera la portée). Voir la documentation de la librairie VirtualWire.
    vw_set_rx_pin(5);             // C'est sur cette broche que l'on reliera les broches DATA du récepteur, vous pouvez changez de broche si vous le désirez.
    vw_rx_start();                // On démarre le récepteur.
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen)) // On test afin de savoir si un message est reçu.
    {// Un message est reçu.
      int i;

        for (i = 0; i < buflen; i++)
        {
          Serial.write(buf[i]);  // On affiche le message lettre par lettre. Par exemple buf[4] sera égale à la 5ème lettre du mot envoyé (Snootlab donc "t") car on compte le zéro ici.
        }
      Serial.println(""); // On saute une ligne afin d'avoir plus de clarté.
     }
}
