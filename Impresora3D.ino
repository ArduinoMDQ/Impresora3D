
int L1=9,L2=10,L3=11,L4=12;
int Vel=10,Pasos=70;

int sensorPin = A0;
int interruptPin=3;
float average = 0;
int led=5;
int val =0;
int ena485=2;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


void setup() {
  
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
 // pinMode(interruptPin, INPUT_PULLUP);
//  attachInterrupt(digitalPinToInterrupt(interruptPin), blink(), RISING);
  pinMode(ena485, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(sensorPin, INPUT);
  digitalWrite(ena485,HIGH);
  digitalWrite(led,HIGH);
  Serial.begin(9600);
  delay(50);
  Serial.println("Impresora 3D");
  delay(50);
  digitalWrite(ena485,LOW);
  digitalWrite(led,LOW);
  
  
}

void loop() {
 
   serialEvent();
   
   if (stringComplete) 
        {
        comandos(inputString);
        inputString = "";
        stringComplete = false;
        }
}


void serialEvent() {
 
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
   
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\r') {
      stringComplete = true;
    }
  }
 
}

void comandos(String com){

  int sensorValue =0;
  float voltage=0;
  float temp=0;

  char com_char;

  com_char=inputString[0];
 
  
  switch (com_char) {
     
    case 'a':
     
        digitalWrite(ena485,HIGH);
        delay(50);
        Serial.println("avanzando paso normal");
        AvanzarDeDosBobinas(Pasos,Vel);
        Detener();
        break;
        
    case 'A':
        digitalWrite(ena485,HIGH);
        delay(50);
        Serial.println("avanzando paso intercalado");
        AvanzarPasoIntermedio(Pasos,Vel);
        Detener();
        break; 
     
    case 'r':
         digitalWrite(ena485,HIGH);
        delay(50);
        Serial.println("retrocediendo paso normal");
        RetrocederDosBobinas(Pasos,Vel);
        Detener();
        break;
      
    case 'R':
        digitalWrite(ena485,HIGH);
        delay(50);
        Serial.println("retrocediendo paso intercalado");
        RetrocederPasoIntermedio(Pasos,Vel);
        Detener();
        break;
    default:
        break;
   }  
 Serial.println("detenido");
  delay(50);
  digitalWrite(ena485,LOW);
 

  }
  
  void Detener(){
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
        digitalWrite(L3,LOW);
        digitalWrite(L4,LOW);
  }
  
   void RetrocederDosBobinas(int posiciones,int velocidad){
    for(int i=0;i<posiciones;i++){
       
     
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
        digitalWrite(L3,HIGH);
        digitalWrite(L4,HIGH);
        Serial.print(".");
        delay(velocidad);
  
        digitalWrite(L1,LOW);
        digitalWrite(L2,HIGH);
        digitalWrite(L3,HIGH);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
  
        digitalWrite(L1,HIGH);
        digitalWrite(L2,HIGH);
        digitalWrite(L3,LOW);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
  
        digitalWrite(L1,HIGH);
        digitalWrite(L2,LOW);
        digitalWrite(L3,LOW);
        digitalWrite(L4,HIGH);
        Serial.println(".");
        delay(velocidad);
    }
    }
  
  
  
  void Retroceder(int posiciones,int velocidad){
    for(int i=0;i<posiciones;i++){
       
     
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
        digitalWrite(L3,LOW);
        digitalWrite(L4,HIGH);
        Serial.print(".");
        delay(velocidad);
  
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
        digitalWrite(L3,HIGH);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
  
        digitalWrite(L1,LOW);
        digitalWrite(L2,HIGH);
        digitalWrite(L3,LOW);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
  
        digitalWrite(L1,HIGH);
        digitalWrite(L2,LOW);
        digitalWrite(L3,LOW);
        digitalWrite(L4,LOW);
        Serial.println(".");
        delay(velocidad);
    }
    }
  
  void Avanzar(int posiciones,int velocidad){
    
      for(int i=0;i<posiciones;i++){
       
        digitalWrite(L1,HIGH);
        digitalWrite(L2,LOW);
        digitalWrite(L3,LOW);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,LOW);
        digitalWrite(L2,HIGH);
        digitalWrite(L3,LOW);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
        digitalWrite(L3,HIGH);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
        digitalWrite(L3,LOW);
        digitalWrite(L4,HIGH);
        Serial.println(".");
        delay(velocidad);
       }
  
  
  }
  
   void AvanzarPasoIntermedio(int posiciones,int velocidad){
    
      for(int i=0;i<posiciones;i++){
       
        digitalWrite(L1,HIGH);
        digitalWrite(L2,LOW);
        digitalWrite(L3,LOW);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,HIGH);
        digitalWrite(L2,HIGH);
        digitalWrite(L3,LOW);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,LOW);
        digitalWrite(L2,HIGH);
        digitalWrite(L3,LOW);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,LOW);
        digitalWrite(L2,HIGH);
        digitalWrite(L3,HIGH);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
        digitalWrite(L3,HIGH);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
        digitalWrite(L3,HIGH);
        digitalWrite(L4,HIGH);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
        digitalWrite(L3,LOW);
        digitalWrite(L4,HIGH);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,HIGH);
        digitalWrite(L2,LOW);
        digitalWrite(L3,LOW);
        digitalWrite(L4,HIGH);
        Serial.println(".");
        delay(velocidad);
        
    }
  
  
  }
  
    void RetrocederPasoIntermedio(int posiciones,int velocidad){
    
      for(int i=0;i<posiciones;i++){
        
        digitalWrite(L1,HIGH);
        digitalWrite(L2,LOW);
        digitalWrite(L3,LOW);
        digitalWrite(L4,HIGH);
        Serial.println(".");
        delay(velocidad);
        
       
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
        digitalWrite(L3,LOW);
        digitalWrite(L4,HIGH);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
        digitalWrite(L3,HIGH);
        digitalWrite(L4,HIGH);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
        digitalWrite(L3,HIGH);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,LOW);
        digitalWrite(L2,HIGH);
        digitalWrite(L3,HIGH);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,LOW);
        digitalWrite(L2,HIGH);
        digitalWrite(L3,LOW);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,HIGH);
        digitalWrite(L2,HIGH);
        digitalWrite(L3,LOW);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,HIGH);
        digitalWrite(L2,LOW);
        digitalWrite(L3,LOW);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
        
       
    }
  
  
  }
  
   void AvanzarDeDosBobinas(int posiciones,int velocidad){
    
      for(int i=0;i<posiciones;i++){
        
        digitalWrite(L1,HIGH);
        digitalWrite(L2,HIGH);
        digitalWrite(L3,LOW);
        digitalWrite(L4,LOW);
        Serial.println(".");
        delay(velocidad);
             
        digitalWrite(L1,LOW);
        digitalWrite(L2,HIGH);
        digitalWrite(L3,HIGH);
        digitalWrite(L4,LOW);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
        digitalWrite(L3,HIGH);
        digitalWrite(L4,HIGH);
        Serial.print(".");
        delay(velocidad);
        
        digitalWrite(L1,HIGH);
        digitalWrite(L2,LOW);
        digitalWrite(L3,LOW);
        digitalWrite(L4,HIGH);
        Serial.print(".");
        delay(velocidad);
           
       
    }
  
  
  }
  
  
 void blink(){
  

  
  }

 
