#include <LiquidCrystal_I2C.h>
#include <Servo.h>


Servo myservo;
LiquidCrystal_I2C lcd(0x27,16,2);

int sens=500,wait=10;

void setup() {
  pinMode(A1,INPUT);
 
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  myservo.attach(3);

  
}


void loop() {

 dis("  No rain is","   detected!");
    myservo.write(0);
  
 if(!val()) return;
 
  for(int i=0; val() &&  i<wait;i++){
    
    dis("Raining! Please","wait for "+String(wait-i)+" sec");
    delay(500);
     if(!val()) return;
    delay(500);
   
  }


  while(val()){
    myservo.write(90);
    dis("   Pure water","  is  filling!");
  }

}

bool val(){
  return 1023-analogRead(A1)>sens;
}



void dis(String a, String b){

  lcd.setCursor(0,0);  
  lcd.print(a+"               ");
  
  lcd.setCursor(0,1);  
  lcd.print(b+"               ");
  Serial.println(a+" "+b);
}
