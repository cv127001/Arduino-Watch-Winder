// user configurable constants
const int WIND_WATCH_ROTATIONS = 100;
const int MINUTES_TO_PAUSE_MOTOR = 15;


// program constants
const int MOTOR_STEPS_IN_ONE_ROTATION = 2045;


// setup() for arduino is equivalent to main() in traditional C/C++ language programs
void setup() {
    //seting up pins as outputs for motor driver
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
} //end-of-setup()


void wind_watch(unsigned long rotations_to_wind) {
    unsigned int step_count = 0;
    const unsigned long max_motor_steps = MOTOR_STEPS_IN_ONE_ROTATION * rotations_to_wind;
    do {
        switch(step_count % 4) {
        
            case 0:
                digitalWrite(2, HIGH);
                digitalWrite(3, LOW);
                digitalWrite(4, LOW);
                digitalWrite(5, LOW);
                break;
    
            case 1:
                digitalWrite(2, LOW);
                digitalWrite(3, HIGH);
                digitalWrite(4, LOW);
                digitalWrite(5, LOW);
                break;
        
            case 2:
                digitalWrite(2, LOW);
                digitalWrite(3, LOW);
                digitalWrite(4, HIGH);
                digitalWrite(5, LOW);
                break;
        
            case 3:
                digitalWrite(2, LOW);
                digitalWrite(3, LOW);
                digitalWrite(4, LOW);
                digitalWrite(5, HIGH);
                break;
            
          } //end-of-switch
    
          step_count++;
          delay(3);
    
      } while (step_count <= max_motor_steps); //end-of-do-while
  
} //end-of-wind_watch()


// let motor rest and cool-down, this will extend its life
void delay_number_of_seconds(unsigned long seconds) {
  delay(seconds*1000);    // delay expects milliseconds, so 1000 milliseconds in 1 second
}


// loop() in arduino has special meaning as it is always called continuously after setup()
void loop() {
  wind_watch( WIND_WATCH_ROTATIONS );
  delay_number_of_seconds(60*15);  // convert minutes to seconds
} // end-of-loop


// run the following linux command from a terminal 
// if you get an error while reprogramming:
// sudo chmod a+rw /dev/ttyUSB0
