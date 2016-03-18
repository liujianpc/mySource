#include <Richedit.h>  // #defines MSFTEDIT_CLASS and RICHEDIT_CLASS


  
HWND CreateRichEditControl() {

  
  static HMODULE msft_mod = LoadLibrary("Msftedit.dll");

  
  if (msft_mod) {

  
    // Create a Rich Edit 4.1 control (requires Windows XP SP1 or later)

  
    return CreateWindowEx(exstyle, MSFTEDIT_CLASS, ...);

  
  }

  
  static HMODULE riched_mod = LoadLibrary("Riched20.dll");

  
  if (riched_mod) {
    // Create a Rich Edit 2.0 (98/NT4) or 3.0 (Me/2K/XP) control.

  
    return CreateWindowEx(exstyle, RICHEDIT_CLASS, ...);
  }

  
  // No suitable DLL found... time to upgrade Windows.

  
  return NULL;

  
}
