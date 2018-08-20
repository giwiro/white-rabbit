# white-rabbit
![logo](https://github.com/giwiro/white-rabbit/raw/master/assets/logo.png)

Simple libmicrohttpd C web server. It hosts one route `/whois` that returns the server hostname.
Some things to take notice:

- **Threading model**: Main thread doing select, and Thread Pool (min 2).
- **Hostname variable**: Is a global heap-allocated variable (freed up when exiting program), it is re-defined on `controller.h`.
- **Linking**: Is dynamically linked.
	
# Compile

## Install libmicrohttpd
First download [libmicrohttpd](https://www.gnu.org/software/libmicrohttpd/).

Fedora:
```
sudo dnf install libmicrohttpd libmicrohttpd-devel
```
Ubuntu:
```
sudo apt-get install libmicrohttpd libmicrohttpd-dev
```

## Make
Execute `make`. You can use this options:

- `DEBUG=1`: It uses the `MHD_USE_DEBUG`

# ** FAQ **

* Which **threading model** should i use ?

	- [Threading models](https://www.gnu.org/software/libmicrohttpd/). The best combo for maximum performance and scalability is `MHD_USE_SELECT_INTERNALLY` with `MHD_OPTION_THREAD_POOL_SIZE`.

* ccache: error: Failed to create temporary file for Permission denied
	
	- [ccache doc](http://tsunanet.net/~tsuna/ccache.html). According to this, we should chown `~/.ccache` to the compiling user
