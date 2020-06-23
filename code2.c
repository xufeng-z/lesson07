#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define S   7
#define BT  8
#define LT  9
#define pinInterrupt 2

byte b=0;
void onChange()
{
  b=0;
  b%=10;
  digitalWrite(IN1, b&0x1);
  digitalWrite(IN2, (b>>1)&0x1);
  digitalWrite(IN3, (b>>2)&0x1);
  digitalWrite(IN4, (b>>3)&0x1);
  delay(1000);
}
void setup()
{
  pinMode(pinInterrupt, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(S, OUTPUT);
  pinMode(BT, OUTPUT);
  pinMode(LT, OUTPUT);
  digitalWrite(S, LOW);
  digitalWrite(BT, HIGH);
  digitalWrite(LT, HIGH);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
}

void loop()
{
  b%=10;
  digitalWrite(IN1, b&0x1);
  digitalWrite(IN2, (b>>1)&0x1);
  digitalWrite(IN3, (b>>2)&0x1);
  digitalWrite(IN4, (b>>3)&0x1);
  delay(1000);
  b++;
}