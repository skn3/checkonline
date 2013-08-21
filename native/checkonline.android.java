import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;

class Skn3CheckOnline {
	public static boolean IsOnline() {
	    ConnectivityManager manager = (ConnectivityManager) BBAndroidGame.AndroidGame().GetActivity().getSystemService(Context.CONNECTIVITY_SERVICE);
		
	    NetworkInfo[] netInfo = manager.getAllNetworkInfo();
	    for (NetworkInfo info : netInfo) {
	        if (info.getTypeName().equalsIgnoreCase("WIFI") && info.isConnected()) { return true; }
	        if (info.getTypeName().equalsIgnoreCase("MOBILE") && info.isConnected()) { return true; }
	    }
	    return false;
	}
}
