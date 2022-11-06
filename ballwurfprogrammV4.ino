// constants won't change. They're used here to
// set pin numbers:
//const int onoff = 2;     // Betriebsmodus
const int ball = 4;     // the number of the pushbutton pin
const int runde = 9;     // wenn eine Runde durch ist
const int aktiv = 5;     // ob überhaupt geworfen werden soll
const int manuell = 6;     // manuell auslösen
const int frei = 8;     // vorne frei
const int freioben = 7;     // oben frei


const int motor =  3;      // Motor läuft
const int ledstatus =  13; 


bool ballstate;

bool freistate;

bool rundestate;

bool manuellstate;

bool freiobenstate;

bool motorstate;

bool aktivstate;

#define DEBUG  // serial debuging



void setup() {
  // initialize the LED pin as an output:
  pinMode(motor, OUTPUT); // initialize the pushbutton pin as an input:
  pinMode(ledstatus, OUTPUT); // initialize the pushbutton pin as an input:
  pinMode(runde, INPUT);
  pinMode(ball, INPUT);
  pinMode(aktiv, INPUT);
  pinMode(manuell, INPUT);
  pinMode(frei, INPUT);
  pinMode(freioben, INPUT);
  
#ifdef DEBUG
Serial.begin(9600);
#endif

}


void serial(){
Serial.println("ball");
Serial.println(ballstate);
Serial.println(); 
Serial.println("frei");
Serial.println(freistate);
Serial.println(); 
Serial.println("runde");
Serial.println(rundestate);
Serial.println(); 
Serial.println("manuell");
Serial.println(manuellstate);
Serial.println();
Serial.println("freioben");
Serial.println(freiobenstate);
Serial.println(); 
Serial.println("motor");
Serial.println(motorstate);
Serial.println(); 
Serial.println("aktiv");
Serial.println(aktivstate);
Serial.println("________________________________________");
}


  
void loop() {


ballstate = digitalRead(ball);

freistate = digitalRead(frei);

rundestate = digitalRead(runde);

manuellstate = digitalRead(manuell);

freiobenstate = digitalRead(freioben);

motorstate = digitalRead(motor);

aktivstate = digitalRead(aktiv);



delay(100);

#ifdef DEBUG

 serial();

#endif



delay(300);

while (digitalRead(manuell) == HIGH){ //manuell
digitalWrite(motor,LOW);
Serial.println(); 
Serial.println("wurf");
delay(100);
}

  if (digitalRead(aktiv) == HIGH){ //automatikbetrieb
    
  digitalWrite(ledstatus,HIGH);
  

    if (((digitalRead(ball) == LOW) and (digitalRead(frei) == LOW) and (digitalRead(freioben) == LOW)))  {   // wenn der ball da ist geht es los oder manuell gedrückt
      while (((digitalRead(runde) == HIGH) and (digitalRead(frei) == LOW) and (digitalRead(freioben) == LOW))){//solange die Runde noch nicht durch 
      digitalWrite(motor,LOW);

#ifdef DEBUG

serial();

#endif

      delay(50);
      }
      delay(60); //noch ein bisschen weiter laufen lassen bis der taster überfahren
      digitalWrite(motor,HIGH);
    } else {
    // nichts passiert
    digitalWrite(motor, HIGH);
    }
  } 
  else {
  digitalWrite(ledstatus,LOW);
  digitalWrite(motor, HIGH);
  }
}
