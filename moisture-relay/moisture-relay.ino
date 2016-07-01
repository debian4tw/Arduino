int humedad = A5;
int rele= 4;
int humedad1;

int led1=13; //Apagado
int led2=12; //Mojado
int led3=8;  //Humedo
int led4=7;  //Seco

void setup()
{       
  Serial.begin(9600) ;
  
  pinMode( rele, OUTPUT ); 
  pinMode( humedad, INPUT );
  pinMode( led1, OUTPUT );
  pinMode( led2, OUTPUT );
  pinMode( led3, OUTPUT );
  pinMode( led4, OUTPUT );
}

void loop()
{
  Medir_Humedad();
  delay(5000);
}

void Medir_Humedad()
{
  humedad1 = analogRead(A5); 
  Serial.println(humedad1);

 if(humedad1 >= 1000 ) // DESCONECTADO - ROJO
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(rele, LOW);
  }

  if(humedad1 < 370 ) // AGUA - AZUL
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(rele, LOW);
  }

  if(humedad1 >= 370 && humedad1 <= 500 ) //HUMEDAD - VERDE
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(rele, LOW);
  }

  if(humedad1 >= 500 && humedad1 <= 1000 ) //AMARILLO - SECO
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(rele, HIGH);
  }  
}

void Mostrar_humedad()
{
     Serial.print("Humedad:");
   Serial.println(analogRead(0));  
}
 
