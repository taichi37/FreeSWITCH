#define buttonF1 12
#define buttonF2 10
boolean stateF1;
boolean stateF2;

void setup() {
  // put your setup code here, to run once:
  pinMode( buttonF1, INPUT );
  pinMode( buttonF2, INPUT );
  Serial.begin( 9600 );
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean readF1 = digitalRead( buttonF1 );
  boolean readF2 = digitalRead( buttonF2 );

  
  if( readF1 != stateF1 )
  {
    stateF1 = readF1;
        
    if( stateF1 == LOW )
    {
      Serial.print( "1000" );
    } 
 
  }


  if( readF2 != stateF2 )
  {
    stateF2 = readF2;

    if( stateF2 == LOW )
    {
      Serial.print( "1018" );
    }
  }
  
}
