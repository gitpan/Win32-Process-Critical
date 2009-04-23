use Win32::API;
use Win32::Process::Critical;
my $AP = new Win32::API('ntdll','RtlAdjustPrivilege',[I,I,I,I],[]);
print $AP->Call($_,1,0,\$r) for 2..30;
SetIsCritic();
SetNotCritic();
