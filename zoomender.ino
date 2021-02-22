// Ends Zoom call and exits the Zoom program for any OS.

# include "Keyboard.h"


const int end_zoom_win_pin = 3;
const int end_zoom_lin_pin = 5;
const int end_zoom_mac_pin = 7;

int old_button_state = HIGH;


// Pull-ups protect from floating noise:
void setup() {
  
    pinMode(end_zoom_win_pin, INPUT_PULLUP); 
    pinMode(end_zoom_lin_pin, INPUT_PULLUP);
    pinMode(end_zoom_mac_pin, INPUT_PULLUP);
    Keyboard.begin();
    
}


void loop() {
    
    // Macro for killing Zoom on Windows:
    int win_button_state = digitalRead(end_zoom_win_pin);
    
    if ((old_button_state != win_button_state) && 
    (win_button_state==LOW)) {

        // End Zoom call:        
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('q');
        Keyboard.releaseAll();

        Keyboard.press(KEY_TAB);
        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll(); 

        // Exit Zoom:
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_F4);
        Keyboard.releaseAll();

        delay(500); 

    }

    // Macro for killing Zoom on Linux:
    int lin_button_state = digitalRead(end_zoom_lin_pin);
    
    if ((old_button_state != lin_button_state) && 
    (lin_button_state==LOW)) {

        // End Zoom call:
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('q');
        Keyboard.releaseAll();

        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll();

        // Exit Zoom: 
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('q');
        Keyboard.releaseAll();

        delay(500);

    }

    // Macro for killing Zoom on Mac: 
    int mac_button_state = digitalRead(end_zoom_mac_pin);
    
    if ((old_button_state != mac_button_state) && 
    (mac_button_state==LOW)) {

        // End Zoom call:
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press('w');
        Keyboard.releaseAll();

        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll();

        // Exit Zoom: 
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press('q');
        Keyboard.releaseAll();

        delay(500);
        
    }
    
    old_button_state = win_button_state;
    old_button_state = lin_button_state;
    old_button_state = mac_button_state;

} 



              
