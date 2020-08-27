#define RED 11
#define GREEN 10
#define BLUE 9

#define trig 2
#define echo 3

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
  pinMode(trig, OUTPUT); // tfig는 초음파를 발사하기 때문에 'OUTPUT'
  pinMode(echo, INPUT); //echo는 나갔던 초음파가 돌아오기 때문에 'INPUT'
}


void loop() {

  int sensorValue; //밝기 값을 담아준다.
  sensorValue = analogRead(A0); //범위는 0~1023

  float duration, distance;
  digitalWrite(trig, HIGH); //초음파를 발사하는 코드
  delay(1); //초음파 발사가 연속되지 않기위해
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH); //초음파가 사물 맞고 돌아온 시간
  distance = ((float)(duration*340)/10000)/2; //시간을 거리로 cm단위 환산

  if(sensorValue > 100)
  {
    if(distance > 15){
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0); //밝고, 물체가 없음
    }
    else {
      analogWrite(RED, 255);
      analogWrite(GREEN, 255);
      analogWrite(BLUE, 0); //밝고, 물체가 있음 -> 노란색
    }
  }
  else
  {
    if(distance > 15){
      analogWrite(RED, 255);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);  //어둡고, 물체가 없음 -> 빨간색
    }
    else {
      for(int i = 0; i<5; i++) {
      analogWrite(RED, 255);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
      delay(200);
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
      delay(200);
    }
    } //어둡고, 물체가 있음 -> 빨간색 반짝임
}

}
