# white-rabbit
Simple libmicrohttpd C web server. It hosts one route that returns the server hostname


# ** FAQ **

* Which **threading model** should i use ?

	- [Threading models](https://www.gnu.org/software/libmicrohttpd/)

* ccache: error: Failed to create temporary file for Permission denied
	
	- [ccache doc](http://tsunanet.net/~tsuna/ccache.html). According to this, we should chown `~/.ccache` to the compiling user
