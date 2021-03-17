int GunTiger=0;
int GunOuput=1;
bool GunFiring=false;
bool GunTigerEdge=false;
int GunAccLevel=0;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(GunTiger, INPUT); //gun triger
  pinMode(GunOuput, OUTPUT); //LED on Model A  or Pro
}

// the loop routine runs over and over again forever:
void loop() {

    if (digitalRead(GunTiger) && !GunTigerEdge) {
        GunFiring=true;
    }
    GunTigerEdge=digitalRead(GunTiger);
    while (GunFiring || digitalRead(GunTiger)){
        digitalWrite(GunOuput,HIGH);
        if(GunAccLevel<20){
          GunAccLevel++;
          }
        delay((500-(GunAccLevel*10)));
        digitalWrite(GunOuput,LOW);
        GunFiring=false;
        delay(500-(GunAccLevel*10));
    }
    GunAccLevel=0;
}