#import <CoreFoundation/CoreFoundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <netdb.h>

BOOL IsOnline() {
	struct sockaddr_in zeroAddress;
	bzero(&zeroAddress, sizeof(zeroAddress));
	zeroAddress.sin_len = sizeof(zeroAddress);
	zeroAddress.sin_family = AF_INET;
	
	SCNetworkReachabilityRef reachability = SCNetworkReachabilityCreateWithAddress(kCFAllocatorDefault, (const struct sockaddr*)&zeroAddress);
	if(reachability != NULL) {
		//NetworkStatus retVal = NotReachable;
		BOOL result;
		SCNetworkReachabilityFlags flags;
		if (SCNetworkReachabilityGetFlags(reachability, &flags)) {
			if ((flags & kSCNetworkReachabilityFlagsReachable) == 0) {
				// if target host is not reachable
				CFRelease(reachability);
				return NO;
			}
			
			if ((flags & kSCNetworkReachabilityFlagsConnectionRequired) == 0) {
				// if target host is reachable and no connection is required
				//  then we'll assume (for now) that your on Wi-Fi
				CFRelease(reachability);
				return YES;
			}
			
			if ((((flags & kSCNetworkReachabilityFlagsConnectionOnDemand ) != 0) || (flags & kSCNetworkReachabilityFlagsConnectionOnTraffic) != 0)) {
				// ... and the connection is on-demand (or on-traffic) if the
				//     calling application is using the CFSocketStream or higher APIs
				
				if ((flags & kSCNetworkReachabilityFlagsInterventionRequired) == 0) {
					// ... and no [user] intervention is needed
					CFRelease(reachability);
					return YES;
				}
			}
			
			if ((flags & kSCNetworkReachabilityFlagsIsWWAN) == kSCNetworkReachabilityFlagsIsWWAN) {
				// ... but WWAN connections are OK if the calling application
				//     is using the CFNetwork (CFSocketStream?) APIs.
				CFRelease(reachability);
				return YES;
			}
		}
		
		CFRelease(reachability);
	}
	
	return NO;
}
