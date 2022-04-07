
const int ledRojo = 12;
const int ledAmarillo = 13;
const int ledVerde = 2;

const int A = 4;
const int B = 5;
const int C = 6;
const int D = 7;

unsigned long previousMillis = 0;        // will store last time LED was updated

const long interval = 2000;           // interval at which to blink (milliseconds)

const int displayDecenasRojo = 8;
const int displayDecenasVerde = 9;

const int displayUnidadesRojo = 10;
const int displayUnidadesVerde= 11;

const int tiempo = 10;

int numero = 35;
int unidades = 0;
int decenas = 0;

//int conta = 0;  // Variable para el contador


void escribirBcd(byte num) {
  digitalWrite(A, (num&1)==1);
  digitalWrite(B, (num&2)==2);
  digitalWrite(C, (num&4)==4);
  digitalWrite(D, (num&8)==8);
}

void setup() {
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  
  pinMode(displayUnidadesRojo,OUTPUT);
  pinMode(displayDecenasRojo,OUTPUT);
  pinMode(displayUnidadesVerde,OUTPUT);
  pinMode(displayDecenasVerde,OUTPUT);
  
  digitalWrite(displayUnidadesRojo,LOW);
  digitalWrite(displayDecenasRojo,LOW);
  digitalWrite(displayUnidadesVerde,LOW);
  digitalWrite(displayDecenasVerde,LOW);

 }
 
//************************************************************************

void encenderRojos() {
  habilitarUnidadesRojo();
  habilitarDecenasRojo();
}

void encenderVerdes(){
  habilitarUnidadesVerde();
  habilitarDecenasVerde();
}

void habilitarUnidadesRojo(){
  escribirBcd(unidades);
  digitalWrite(displayUnidadesRojo,HIGH);
  digitalWrite(displayDecenasRojo,LOW);
  digitalWrite(displayUnidadesVerde,LOW);
  digitalWrite(displayDecenasVerde,LOW);
  delay(tiempo);
}  

void habilitarDecenasRojo()
{
  escribirBcd(decenas);
  digitalWrite(displayUnidadesRojo,LOW);
  digitalWrite(displayDecenasRojo,HIGH);
  digitalWrite(displayUnidadesVerde,LOW);
  digitalWrite(displayDecenasVerde,LOW);
  delay(tiempo);
}  

void habilitarUnidadesVerde(){
  escribirBcd(unidades);
  digitalWrite(displayUnidadesRojo,LOW);
  digitalWrite(displayDecenasRojo,LOW);
  digitalWrite(displayUnidadesVerde,HIGH);
  digitalWrite(displayDecenasVerde,LOW);
  delay(tiempo);
}  

void habilitarDecenasVerde() {
  escribirBcd(decenas);
  digitalWrite(displayUnidadesRojo,LOW);
  digitalWrite(displayDecenasRojo,LOW);
  digitalWrite(displayUnidadesVerde,LOW);
  digitalWrite(displayDecenasVerde,HIGH);
  delay(tiempo);
}  


void loop() {       
        unsigned long currentMillis = millis();

        if (currentMillis - previousMillis >= interval)         {
          numero = numero-1; 
          // save the last time you blinked the LED
          previousMillis = currentMillis;
        }

        if(numero <= 10)         {
          encenderRojos();
        }
        else         {
          encenderVerdes();
        }
                                
        if(numero<0)
        {
          numero = 35;
        }  
         
        decenas = numero/10;  //Extraigo el dìgito de las unidadesSS
       
        unidades=  numero-( decenas*10);  //Extraigo el dìgito de las decenas
         
        //habilitarUnidades();
        
        //habilitarDecenas();
         
 
}
