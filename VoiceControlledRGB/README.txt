Last Updated: December 30th, 2016

This project is a mixture between the continuously changing RGB project and the BT Voice Controlled LED project.

This project allows a user to turn the RGB LED red, green, blue, a random color, or off using their voice and the AMR_Voice app for Android phones.

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

Parts:
  -HC-05 Bluetooth Module
  -Jumper Wires
  -Arduino Uno
  -RGB LED (Common Anode)
  -220ohm resistor
  -Android smartphone

Schematics have been uploaded as a .fzz file.

