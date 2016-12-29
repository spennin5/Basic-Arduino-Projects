Last Updated: December 29th, 2016

This project works in conjunction with the AMR_Voice app for an Android smartphone. 

To use bluetooth control:
  1) Download the app
  2) Wire the circuit as seen in the Fritzing schematic
  3) Within the app, click "connect robot" and select your bluetooth module (mine was the HC-05)
  4) Speak your commands
  
Commands are intepreted as strings beginning with * and ending with #. The included code breaks the "voice" string when the #
character is reached. Additional commands can be added in the same way as the on and off commands. 
  Ex: if (voice == "*start the car"){
        motor.run(256);
      }
  Please Note: The asterisk at the beginning of the command string must be included or the code will not work
  
Necessary parts:
  -Arduino board (I used a knockoff Arduino Uno)
  -4 Jumper Wires
  -1 LED 
  -1 Bluetooth Module (I used HC-05)
  -1 Android smartphone
  -1 USB Cable to provide power and upload code to Arduino
  
Additional Notes:
  -The app will disconnect from the BT module everytime the phone screen goes black so you must reconnect it
  -BT might not connect with your phone if you are powering it with the 3.3V source on the Arduino board
