# white-rabbit
Simple libmicrohttpd C web server. It hosts one route that returns the server hostname


# ** FAQ **

* ccache: error: Failed to create temporary file for Permission denied
	
	(ccache doc)[http://tsunanet.net/~tsuna/ccache.html]. According to this, we should chown `~/.ccache` to the compiling user