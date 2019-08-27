# include "Button_Press.h"

bool is_button_pressed(const int button_pin)
{
  bool is_pressed = digitalRead(button_pin);
  
  if (is_pressed == true)
  {
    delay(300);
    return true;
  }
  else
    return false;
}