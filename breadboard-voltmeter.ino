#include <Arduino.h>

const int LED_0 = 0;
const int LED_1 = 1;
const int LED_2 = 2;
const int LED_3 = 3;
const int ADC_IN = A2;

const int R1 = 6800;
const int R2 = 1000;

const float RECTIFIER_V_F = 0.2;
const float VCC = 2.5;

int adcReading = 0;
float voltageValue = 0;

void set_led(int i);
float compute_voltage(int adc_reading);

void setup() {}

void loop() {
  adcReading = analogRead(ADC_IN);
  voltageValue = compute_voltage(adcReading);

  set_led(round(voltageValue) - 3);
}

/*
 * Compute the actual voltage from the ADC reading.
 * ADC reading ranges from 0 to 1023, where 0 -> G_Ref
 * and 1023 -> Vcc (2.50 V)
 */
float compute_voltage(int adc_reading) {
  float v_measured = ((float) adc_reading) / 1023.0 * VCC;
  float v = (v_measured * (R1 + R2) / R2) + 2 * RECTIFIER_V_F;
  return v;
}

/*
 * zero-indexed from bottom. eg,
 * i=0 -> Turn on D1 (3V)
 * i=1 -> Turn on D2 (4V)
 * etc
 */
void set_led(int i) {
  if (i < 0) {
    i = 0;
  }
  if (i > 9) {
    i = 9;
  }
  if(i == 0) {
    pinMode(LED_0, OUTPUT);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, INPUT);
    pinMode(LED_3, INPUT);
    digitalWrite(LED_0, HIGH);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
  }
  if(i == 1) {
    pinMode(LED_0, OUTPUT);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, INPUT);
    pinMode(LED_3, INPUT);
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
  }
  if(i == 2) {
    pinMode(LED_0, INPUT);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, INPUT);
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
  }
  if(i == 3) {
    pinMode(LED_0, INPUT);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, INPUT);
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
  }
  if(i == 4) {
    pinMode(LED_0, INPUT);
    pinMode(LED_1, INPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
  }
  if(i == 5) {
    pinMode(LED_0, INPUT);
    pinMode(LED_1, INPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, HIGH);
  }
  if(i == 6) {
    pinMode(LED_0, OUTPUT);
    pinMode(LED_1, INPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, INPUT);
    digitalWrite(LED_0, HIGH);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
  }
  if(i == 7) {
    pinMode(LED_0, OUTPUT);
    pinMode(LED_1, INPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, INPUT);
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
  }
  if(i == 8) {
    pinMode(LED_0, OUTPUT);
    pinMode(LED_1, INPUT);
    pinMode(LED_2, INPUT);
    pinMode(LED_3, OUTPUT);
    digitalWrite(LED_0, HIGH);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
  }
  if(i == 9) {
    pinMode(LED_0, OUTPUT);
    pinMode(LED_1, INPUT);
    pinMode(LED_2, INPUT);
    pinMode(LED_3, OUTPUT);
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, HIGH);
  }
}
