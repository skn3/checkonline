Strict

'version 1
' - first commit

'set if supported and import native libs
#If TARGET = "html5"
	#SKN3_CHECKONLINE_IMPLEMENTED=True
	Import "native/checkonline.html5.js"
	
	Extern
		Function IsOnline:Bool()
	Public
#Elseif TARGET = "ios"
	#LIBS += "SystemConfiguration.framework"
	
	#SKN3_CHECKONLINE_IMPLEMENTED=True
	
	Import "native/checkonline.ios.cpp"
	
	Extern
		Function IsOnline:Bool()
	Public
#elseif TARGET="android"
	#SKN3_CHECKONLINE_IMPLEMENTED=True
	Import "native/checkonline.android.java"
	
	Extern
		Function IsOnline:Bool() = "Skn3CheckOnline.IsOnline"
	Public
#elseif LANG="cpp"
	#SKN3_CHECKONLINE_IMPLEMENTED=True
	Import "native/checkonline.cpp"
	
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