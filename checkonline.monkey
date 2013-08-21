Strict

'version 1
' - first commit

'set if supported and import native libs
#If TARGET = "html5" Or TARGET = "ios" Or TARGET = "win8"
	#SKN3_CHECKONLINE_IMPLEMENTED=True
	Import "native/checkonline.${TARGET}.${LANG}"
	
	Extern
		Function IsOnline:Bool()
	Public
#elseif TARGET="android"
	#SKN3_CHECKONLINE_IMPLEMENTED=True
	Import "native/checkonline.${TARGET}.${LANG}"
	
	Extern
		Function IsOnline:Bool() = "Skn3CheckOnline.IsOnline"
	Public
#elseif LANG="cpp"
	#SKN3_CHECKONLINE_IMPLEMENTED=True
	Import "native/checkonline.${LANG}"
	
	Extern
		Function IsOnline:Bool()
	Public
#End
#SKN3_CHECKONLINE_IMPLEMENTED = False

'check if supported
#If SKN3_CHECKONLINE_IMPLEMENTED = "0"
	Function IsOnline:Bool()
		' --- default action ---
		Return False
	End
#end