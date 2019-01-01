

// assign pin num
int right = 2;
int left = 4;
int forward = 7;
int reverse = 8;

// duration for output
int time = 10;
// initial command
int command = 0;
char test_command = '0';

void setup() {
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(forward, OUTPUT);
  pinMode(reverse, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello there!");
}

void loop() {
  //  //receive command
  //  if (Serial.available() > 0){
  //    test_command = Serial.read();
  //    Serial.println(test_command);
  //    command=test_command - '0';
  //  }
  //  else{
  //    reset();
  //  }
  //   send_command(command,time);
}

void go_right(int time) {
  digitalWrite(reverse, LOW);
  digitalWrite(left, LOW);
  digitalWrite(forward, LOW);
  digitalWrite(right, HIGH);
  delay(time);
}

void go_left(int time) {
  digitalWrite(reverse, LOW);
  digitalWrite(forward, LOW);
  digitalWrite(right, LOW);
  digitalWrite(left, HIGH);
  delay(time);
}

void go_forward(int time) {
  digitalWrite(reverse, LOW);
  digitalWrite(left, LOW);
  digitalWrite(right, LOW);
  digitalWrite(forward, HIGH);
  delay(time);
}

void go_reverse(int time) {
  digitalWrite(left, LOW);
  digitalWrite(right, LOW);
  digitalWrite(forward, LOW);
  digitalWrite(reverse, HIGH);
  delay(time);
}

void go_forward_right(int time) {
  digitalWrite(left, LOW);
  digitalWrite(reverse, LOW);
  digitalWrite(forward, HIGH);
  digitalWrite(right, HIGH);
  delay(time);
}

void go_reverse_right(int time) {
  digitalWrite(left, LOW);
  digitalWrite(forward, LOW);
  digitalWrite(reverse, HIGH);
  digitalWrite(right, HIGH);
  delay(time);
}

void go_forward_left(int time) {
  digitalWrite(forward, HIGH);
  digitalWrite(left, HIGH);
  digitalWrite(reverse, LOW);
  digitalWrite(right, LOW);
  delay(time);
}

void go_reverse_left(int time) {
  digitalWrite(reverse, HIGH);
  digitalWrite(left, HIGH);
  digitalWrite(right, LOW);
  digitalWrite(forward, LOW);
  delay(time);
}

void reset() {
  digitalWrite(right, LOW);
  digitalWrite(left, LOW);
  digitalWrite(forward, LOW);
  digitalWrite(reverse, LOW);
}

void serialEvent() {
//void send_command(int command, int time){
  while (Serial.available() > 0)
  {
    test_command = Serial.read();
    command = test_command - '0';
    Serial.println(test_command);
    switch (command) {

      //reset command
      case 0: reset(); break;

      // single command
      case 1: go_forward(time); break;
      case 2: go_reverse(time); break;
      case 3: go_right(time); break;
      case 4: go_left(time); break;

      //combination command
      case 6: go_forward_right(time); break;
      case 7: go_forward_left(time); break;
      case 8: go_reverse_right(time); break;
      case 9: go_reverse_left(time); break;

      //default: Serial.print("Invalid Command\n"); break;
    }
  }
}
