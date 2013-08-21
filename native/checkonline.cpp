#if _WIN32
//glfw / xna
#pragma comment (lib, "wininet.lib")
#include <Wininet.h>

BOOL IsOnline() {
	DWORD dwState = 0 ;
	BOOL bIsConnected = InternetGetConnectedState(&dwState, 0);
	return bIsConnected;
}

#elif WINDOWS_PHONE_8 || WINDOWS_8
bool IsOnline() {
	return NetworkInterface.GetIsNetworkAvailable();
}

#elif __APPLE__
//mac
bool IsOnline() {

}

#endif
