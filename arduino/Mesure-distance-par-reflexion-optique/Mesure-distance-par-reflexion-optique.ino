const int DEL_DETECTION = 2;
const int DEL_STATUT = 3;
const int BOUTON = 4;
const int CAPTEUR = A0;

void setup() {
  pinMode(DEL_DETECTION, OUTPUT);
  pinMode(DEL_STATUT, OUTPUT);
  pinMode(BOUTON, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  if (digitalRead(BOUTON) == LOW || Serial.read() == 'm') {
    digitalWrite(DEL_STATUT, HIGH);
    
    digitalWrite(DEL_DETECTION, HIGH);
    delay(20);
    int M1 = analogRead(CAPTEUR);
    
    digitalWrite(DEL_DETECTION, LOW);
    delay(20);
    int M2 = analogRead(CAPTEUR);

    int R = M1 - M2;
    if (R < 0) {
      R = -R;
    }
    Serial.println(R);
    
    digitalWrite(DEL_STATUT, LOW);
  }
}
