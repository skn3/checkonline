#if WINDOWS_PHONE_8
using namespace Windows::Networking::Connectivity;

bool IsOnline() {
	//Retrieve the ConnectionProfile
	ConnectionProfile^ profile = NetworkInformation::GetInternetConnectionProfile();
    if (profile) { return true; }// && profile->GetNetworkConnectivityLevel() == NetworkConnectivityLevel::InternetAccess);
	return false;
}

#elif WINDOWS_8
using namespace Windows::Networking::Connectivity;

bool IsOnline() {
	//Retrieve the ConnectionProfile
	ConnectionProfile^ profile = NetworkInformation::GetInternetConnectionProfile();
    return (profile && profile->GetNetworkConnectivityLevel() == NetworkConnectivityLevel::InternetAccess);
}

#elif _WIN32
//glfw / xna
#pragma comment (lib, "wininet.lib")
#include <Wininet.h>

BOOL IsOnline() {
	DWORD dwState = 0 ;
	BOOL bIsConnected = InternetGetConnectedState(&dwState, 0);
	return bIsConnected;
}

#elif __APPLE__
//mac
bool IsOnline() {

}

#endif
