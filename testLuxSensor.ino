/**
 * Ce programme permet de tester l'utilisation du module lux-mètre d'Adafruit.
 * le module : http://www.adafruit.com/products/1384
 * le datasheet du module : http://www.adafruit.com/datasheets/GA1A1S202WP_Spec.pdf
 * Code source sous licence GNU GPL 2.0.
 * Ce fichier fait partie du projet Milapli : https://github.com/sarinkhan/Milapli
 */


int luxSensorPin=A3;
void setup()
{
    Serial.begin(9600);
}

/**
 * Cette fonction lit et retourne le flux lumineux mesuré, en LUX.
 * @param pin la broche sur laquelle la sortie analogique du luxmetre est branchée
 * @returns éclairement lumineux en lux.
 */
float readLux(int pin)
{
    float I=readLuxMeterCurrent(pin); //courant en Ampères
    //Io=10*log(Ev) alors Io/10=log(Ev) <=> Ev=(Io/10)^10 (µA)
    float Ev=pow(I/10,10);
    return Ev;
}

/**
 * Cette fonction lit et retourne la tension lue sur la borne de sortie du module lux-metre.
 * @param pin la broche sur laquelle la sortie analogique du luxmetre est branchée
 * @returns la tension de sortie du module lux-mètre, en volts.
 */
float readLuxMeterTension(int pin)
{
    int VCC=5;
    float U=analogRead(pin);
    U=U/1024*VCC;
    return U;
}

/**
 * Cette fonction lit et retourne le courant en µA en sortie de la photodiode
 * @param pin la broche sur laquelle la sortie analogique du luxmetre est branchée
 * @returns le courant en µA (micro ampères) généré par la photodiode
 */
float readLuxMeterCurrent(int pin)
{
    float U=readLuxMeterTension(pin);
    float R_out=68000;
    float I=U/R_out; //courant en Ampères
    I=I*1000000;//conversion en µA
    return I;
}

/**
 * Cette fonction calcule la moyenne de "count" mesures effectuées à "waitDelay" ms d'écart.
 * @param pin la broche sur laquelle la sortie analogique du luxmetre est branchée
 * @param waitDelay le délai entre deux mesures
 * @param count le nombre de mesures à effectuer
 * @returns éclairement lumineux en lux.
 */
float readAvgLux(int pin, int waitDelay, int count)
{
   int k=0;
   float sum=0.0;
   for(k=0;k<count;k++)
   {
       sum=sum + readLux(pin);
       delay(waitDelay);
   }
   float avg=sum/(float)count;
   return avg;
}


void loop()
{
   //lecture des données de la photodiode
   float U1=readLuxMeterTension(luxSensorPin);
   float I1=readLuxMeterCurrent(luxSensorPin);
   float Ev1=readLux(luxSensorPin);
   
   Serial.print("Tension : ");
   Serial.print(+U1);
   Serial.println("v");
   
   Serial.print("Courant : ");
   Serial.print(I1);
   Serial.println("uA");
   
   Serial.print("Flux : ");
   Serial.print(Ev1);
   Serial.println("lx");
}
