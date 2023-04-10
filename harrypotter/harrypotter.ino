//Frequência das notas
#define as4 466
#define b4 494
#define ds5 622
#define e5 659
#define f5 698
#define fs5 740
#define g5 784
#define gs5 830
#define a5 880
#define as5 932
#define b5 988
#define c6 1046
#define cs6 1109
#define d6 1175

// Pino do LED e do Buzzer
int ledPin = 13;
int speakerPin = 11;

void setup() 	 
{ 
  //Setando Led e buzzer como Saída  
  pinMode(ledPin, OUTPUT);  
  pinMode(speakerPin, OUTPUT);  
} 	  
	 
void loop() 
{
  hp();
} 	 
  	 
//Acendendo e apagando Led no rítmo da música
void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{ 
    digitalWrite(ledPin, HIGH);	   
    
    int x; 	 
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    for (x=0;x<loopTime;x++) 	 
    { 	 
        digitalWrite(speakerPin,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(speakerPin,LOW);
        delayMicroseconds(delayAmount);
    } 	 
    
    digitalWrite(ledPin, LOW);   
    delay(20);   //Pequeno delay para marcar e separar as notas     
} 	 
  	 
void hp()
{       
    //Foi usado 80 bpm como andamento - semínima = 750ms    
    beep(speakerPin, b4, 375); 
    beep(speakerPin, e5, 563);     
    beep(speakerPin, g5, 188); 
    beep(speakerPin, fs5, 375); 
    beep(speakerPin, e5, 750);
    
    beep(speakerPin, b5, 375);
    beep(speakerPin, a5, 1125);
    beep(speakerPin, fs5, 1125);
    

    beep(speakerPin, e5, 563);  
    beep(speakerPin, g5, 188);
    beep(speakerPin, fs5, 375);
    beep(speakerPin, ds5, 750);    
    beep(speakerPin, f5, 375); 
    beep(speakerPin, b4, 1875);
    
    beep(speakerPin, b4, 375);
    beep(speakerPin, e5, 563);
    beep(speakerPin, g5, 188);
    beep(speakerPin, fs5, 375);     
    beep(speakerPin, e5, 750);

    beep(speakerPin, b5, 375); 
    beep(speakerPin, d6, 750);
    beep(speakerPin, cs6, 375);
    beep(speakerPin, c6, 750);
 
    beep(speakerPin, gs5, 375);    
    beep(speakerPin, c6, 563);
    beep(speakerPin, b5, 188);    
    beep(speakerPin, as5, 375);
    beep(speakerPin, b4, 750);
    beep(speakerPin, g5, 375);  
    beep(speakerPin, e5, 1875);
  
    beep(speakerPin, g5, 375);  
    beep(speakerPin, b5, 750);  
    beep(speakerPin, g5, 375);  
    beep(speakerPin, b5, 750); 
     
    beep(speakerPin, g5, 375);  
    beep(speakerPin, c6, 750);  
    beep(speakerPin, b5, 375);  
    beep(speakerPin, as5, 750); 
    
    beep(speakerPin, fs5, 375); 
    beep(speakerPin, g5, 555);  
    beep(speakerPin, b5, 188); 
    beep(speakerPin, as5, 375); 
   
    beep(speakerPin, as4, 750);
    beep(speakerPin, b4, 375); 
    beep(speakerPin, b5, 1875);

    beep(speakerPin, g5, 375);
    beep(speakerPin, b5, 750); 
    beep(speakerPin, g5, 375);
    beep(speakerPin, b5, 750);

    beep(speakerPin, g5, 375);    
    beep(speakerPin, d6, 750);
    beep(speakerPin, cs6, 375);    
    beep(speakerPin, c6, 750);
  
    beep(speakerPin, gs5, 375);  
    beep(speakerPin, c6, 563);      
    beep(speakerPin, b5, 188);  
    beep(speakerPin, as5, 375);
  
    beep(speakerPin, fs5, 750);          
    beep(speakerPin, g5, 375);  
    beep(speakerPin, e5, 750);  
    beep(speakerPin, e5, 1500);      
}