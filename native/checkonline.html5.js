function IsOnline() {
	return typeof navigator.onLine !== undefined && navigator.onLine == true;
}