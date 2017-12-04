const uint8_t MOTOR_PIN = 22;
const uint8_t PWM_THRESHOLD = 50;
int motor_pwm_value = 0;
bool increasing = true;

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(motor_pwm_value < PWM_THRESHOLD && increasing){
    motor_pwm_value++;
  }
  else if(motor_pwm_value > 0 && !increasing){
    motor_pwm_value--;
  }

  if(motor_pwm_value > PWM_THRESHOLD){
    increasing = false;
  }
  else if(motor_pwm_value < 0){
    increasing = true;
  }
  analogWrite(MOTOR_PIN, motor_pwm_value);
}
