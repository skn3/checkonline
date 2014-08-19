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

//glfw / xna
#elif defined _MSC_VER
	#pragma comment (lib, "wininet.lib")
	#include <wininet.h>
	
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
#elif _WIN32
	BOOL IsOnline() {
		return false;
	}
	
	BOOL IsOnMobileNetwork() {
		return false;
	}
#elif __APPLE__
//mac
bool IsOnline() {
	return true;
}

#endif
