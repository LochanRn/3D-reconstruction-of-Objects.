int LA1[] =  { 6, 4, 7};                        // A, B, PWM long 0-1 up
bool flag = 0;
int i = 0;
char x = 'q';
void setup() {;
  for (i = 0; i < 3; i++) {  // LA outputs
    pinMode(LA1[i], OUTPUT);
  }
  Serial2.begin(9600);
  Serial.begin(9600);   //Debug
}
int steps = 0;
void loop() {
  if(Serial.available()>0){
    x = Serial.read();
  }
  if(x == 'a'){
    control(50, 25, LA1, 150);
    delay(200);
    control(0, 25, LA1, 0);
    delay(2000);
    Serial.println(x);
    Serial2.write(1);
  }
  if(x == 'd'){
    control(-50, 25, LA1, 150);
    delay(200);
    control(0, 25, LA1, 0);
    delay(2000);
    Serial.println(x);
    Serial2.write(1);
  }
  else if(x == 'q')  {
    control(0, 25, LA1, 0);
    Serial.println(x);
    Serial2.write(0);
  }
}

void control(int inp, int lim, int M[], int pwm) {
  if (abs(inp) <= lim)  act(M, 0, 0, 0);
  else if (inp >  lim)  act(M, 0, 1, pwm);
  else if (inp < -lim)  act(M, 1, 0, pwm);
  else act(M, 0, 0, 0);
}
void act(int arr[], boolean A, boolean B, int pwm) {
  digitalWrite(arr[0], A);
  digitalWrite(arr[1], B);
  analogWrite(arr[2], pwm);
}
