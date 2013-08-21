Strict

Import mojo
Import checkonline

Function Main:Int()
	New MyApp
	Return 1
End

Class MyApp Extends App

	Method OnCreate:Int()
		' --- setup the game ---
		SetUpdateRate(30)
		
		Return 0
	End
	
	Method OnUpdate:Int()
		' --- update the game ---
		'basic app update
		If KeyHit(KEY_ESCAPE) Error("")
		
		Return 0
	End
	
	Method OnRender:Int()
		' --- render the game ---
		Cls(Rnd(0, 255), Rnd(0, 255), Rnd(0, 255))
		
		If IsOnline()
			SetColor(0, 255, 0)
			DrawText("online :D", 5, 5)
		Else
			SetColor(255, 0, 0)
			DrawText("offline :(", 5, 5)
		EndIf
		
		Return 0
	End
End