/*
El siguiente código tiene por objetivo leer el rebote de un pulso y medir la distancia donde se produce aquel rebote.
El telémetro emitirá un pulso dentro de un determinado rango, en donde cualquier objeto que se encuentre dentro de este rango
hará rebotar el pulso, de donde el telemetro interpretará esta señal y la enviará al arduino para poder generar la lectura de la distancia
en la que se encuentre el objeto.
*/
int inches = 0;
                 //variables globales para distancias en pulgadas y centimetros
int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin) //funcion que establece configuración para la lectura del telemetro
{
  pinMode(triggerPin, OUTPUT);  //depeja el disparador
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH); //configura el disparador en HIGH (o estado 1) durante 10 microsegundos
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT); // Lee el pin del eco, y retorna el tiempo de viaje de la onda de sonido en microsegundos
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600); //Establece la velocidad de datos en bits por segundo para la transmisión de datos en serie
}

void loop()
{
  cm = 0.01723 * readUltrasonicDistance(7, 7); //se mide el tiempo de recorrido de onda en centimetros
  inches = (cm / 2.54); //se transforma los centimetros a pulgadas
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm); //se muestra la información de la distancia en pulgadas y centimetros
  Serial.println("cm");
  delay(100);
}
