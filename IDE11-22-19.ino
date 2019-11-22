/*
IDE for wind tunnel desing based on 2 force sensitive resistors fcr1 and fcr2
fcr1 measures the drag
fcr2 measures the lift
lift is calculated by finding the weight of the objcet before any wind is applied and then subtracting the weight of the object during the trial any change in observed weight is assumed to be caused by lift
*/

//Threshhold values for determining whether the test experiences low, medium, or high lift/drag
const int lowDrag=65;
const int highDrag=50;

int fcr1 = 0;              //this variable will hold a value based on the force applied to the sensor downstream of the object
#include <LiquidCrystal.h>          //the liquid crystal library contains commands for printing to the display

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   // tell the RedBoard what pins are connected to the display

void setup()
{
  Serial.begin(9600);               //start a serial connection with the computer
  
  lcd.begin(16, 2);                 //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                      //clear the display

}

void loop()
{
  n
  fcr1 = analogRead(A0);   //set sensor to a number between 0 and 1023 based on the force for this sensor
  Serial.println(fcr1);    //print the value of sensor in the serial monitor on the computer
  
  
  lcd.setCursor(0,0);               //set the cursor to the 0,0 position (top left corner)
  lcd.print("Drag:");
  lcd.setCursor(7,0);
       
  if (fcr1<highDrag){
    lcd.print("HIGH");
  }
  else if(fcr1>lowDrag){
    lcd.print("LOW ");
  }
  else{
    lcd.print("MED.");
  }
      
  delay(75);                       //short delay to make the printout easier to read
}
