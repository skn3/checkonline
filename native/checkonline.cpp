#if WINDOWS_PHONE_8
using namespace Windows::Networking::Connectivity;

bool IsOnline() {
	//Retrieve the ConnectionProfile
	ConnectionProfile^ profile = NetworkInformation::GetInternetConnectionProfile();
    if (profile) { return true; }// && profile->GetNetworkConnectivityLevel() == NetworkConnectivityLevel::InternetAccess);
	return false;
}

bool IsOnMobileNetwork() {
	//Retrieve the ConnectionProfile
	ConnectionProfile^ profile = NetworkInformation::GetInternetConnectionProfile();
    return (profile && profile->GetNetworkConnectivityLevel() == NetworkConnectivityLevel::InternetAccess && profile.GetConnectionCost() != NetworkCostType.Unrestricted);
}

#elif WINDOWS_8
using namespace Windows::Networking::Connectivity;

bool IsOnline() {
	//Retrieve the ConnectionProfile
	ConnectionProfile^ profile = NetworkInformation::GetInternetConnectionProfile();
    return (profile && profile->GetNetworkConnectivityLevel() == NetworkConnectivityLevel::InternetAccess);
}

bool IsOnMobileNetwork() {
	//Retrieve the ConnectionProfile
	ConnectionProfile^ profile = NetworkInformation::GetInternetConnectionProfile();
    return (profile && profile->GetNetworkConnectivityLevel() == NetworkConnectivityLevel::InternetAccess && profile.GetConnectionCost() != NetworkCostType.Unrestricted);
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

BOOL IsOnMobileNetwork() {
	//unreliable...
	//what if 3g dongle/card is specified as lan adapter?
	DWORD dwState = 0 ;
	BOOL bIsConnected = InternetGetConnectedState(&dwState, 0);
    return bIsConnected && dwState & INTERNET_CONNECTION_MODEM;
}

#elif __APPLE__
//mac
bool IsOnline() {
	return true;
}

#endif
