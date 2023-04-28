/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: sensor utrasonico
   profesor: Alejandro Navas
   alumno: Alvaro Josue Antonio Marroquin Coado
   Fecha: 27 de abril
*/
#define dig1(pin) digitalWrite(pin, HIGH)
#define dig0(pin) digitalWrite(pin, LOW)
#define led 2
void configPinesInput(void);
void configpinesOutput(void);
int contador_display(int a, int b, int c, 
                     int d, int e, int f, 
                     int g, int FO);
int trig = 11;
int eco = 12;
int duracion;
int distancia;
int contador=0;
int display7;

void setup() {
 Serial.begin(9600); 
  configPinesInput();
  configpinesOutput();
}

void loop() {
   digitalWrite(trig, LOW);
   delay(15);
   digitalWrite(trig,HIGH);
   delay(15);
   digitalWrite(trig, LOW);
   duracion = pulseIn(eco, HIGH);
   distancia= duracion*0.032/2;    
  Serial.print(String(distancia));
  Serial.println(" cm");
  delay(400);

  if(distancia>=6 && distancia <=10) 
  {
     digitalWrite(led, LOW);
    contador++;
     Serial.println("contador");
     delay(1000);
  }
   else 
   {
    digitalWrite(led, HIGH);
   }
  contador_display(3,4,5,6,7,8,9,2);
}
 void configPinesInput(void){
  pinMode(eco, INPUT);
 }

 void configpinesOutput(void)
{
     pinMode(led, OUTPUT);
     pinMode(trig, OUTPUT);  
     pinMode(3, OUTPUT);
     pinMode(4, OUTPUT);
     pinMode(5, OUTPUT);
     pinMode(6, OUTPUT);
     pinMode(7, OUTPUT);
     pinMode(8, OUTPUT);
     pinMode(9, OUTPUT);
     pinMode(2, OUTPUT); 
}
 int contador_display(int a, int b, int c, 
                      int d, int e, int f, 
                      int g, int FO)
{
                      
switch(contador){
case(0):
 dig0(a); dig0(b); dig0(c); dig0(d); dig0(e); dig0(f); dig1(g); 
break;
case(1):
 dig1(a); dig0(b); dig0(c); dig1(d); dig1(e); dig1(f); dig1(g);
break;
case(2):
 dig0(a); dig0(b); dig1(c); dig0(d); dig0(e); dig1(f); dig0(g);
break;
case(3):
 dig0(a); dig0(b); dig0(c); dig0(d); dig1(e); dig1(f); dig0(g);
break;
case(4):
 dig1(a); dig0(b); dig0(c); dig1(d); dig1(e); dig0(f); dig0(g);
break;                
case(5):
 dig0(a); dig1(b); dig0(c); dig0(d); dig1(e); dig0(f); dig0(g);
break;       
case(6):
 dig0(a); dig1(b); dig0(c); dig0(d); dig0(e); dig0(f); dig0(g);
break;        
case(7):
 dig0(a); dig0(b); dig0(c); dig1(d); dig1(e); dig1(f); dig1(g);
break;
case(8):
 dig0(a); dig0(b); dig0(c); dig0(d); dig0(e); dig0(f); dig0(g);
break;
case(9):
 dig0(a); dig0(b); dig0(c); dig1(d); dig1(e); dig0(f); dig0(g); dig0(FO);
contador=9;
digitalWrite(2,HIGH);
break; 
}
 }
