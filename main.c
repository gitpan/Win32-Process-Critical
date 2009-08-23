typedef LONG (*pRtlSetProcessIsCritical)(BOOL,PBOOL,BOOL);
pRtlSetProcessIsCritical SetCritical = NULL;
typedef LONG (*pRtlAdjustPrivilege)(int,BOOL,BOOL,int*);
pRtlAdjustPrivilege RtlAdjPriv = NULL;

bool Import () {
	HANDLE hNTDLL = LoadLibraryA("ntdll.dll");
	if(!hNTDLL)
		return FALSE;
	SetCritical = (pRtlSetProcessIsCritical)GetProcAddress((HINSTANCE)hNTDLL,"RtlSetProcessIsCritical");
	RtlAdjPriv = (pRtlAdjustPrivilege)GetProcAddress((HINSTANCE)hNTDLL,"RtlAdjustPrivilege");
	{
		int prtn;
		RtlAdjPriv(20,TRUE,FALSE,&prtn);
	}
	RtlAdjPriv = NULL;
	FreeLibrary(hNTDLL);
	return TRUE;
}

bool SetIsCritic(void){
	if(!SetCritical(TRUE,NULL,FALSE))
		return FALSE;
	if(!SetProcessShutdownParameters(0,0))
		return FALSE;
	return TRUE;
}

bool SetNotCritic(void){
       	if(!SetCritical(FALSE,NULL,FALSE))
		return FALSE;
	return TRUE;
}
