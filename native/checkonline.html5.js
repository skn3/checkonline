function IsOnline() {
	return typeof navigator.onLine !== undefined && navigator.onLine == true;
}

function IsOnMobileNetwork() {
	//not supported by browsers yet...
	return false;
}