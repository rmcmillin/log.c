# log.c
A simple logging library implemented in C99


![logimage](https://user-images.githubusercontent.com/77390891/147371464-0bc2ab05-07a4-4088-baf3-1cd8e032f9ba.png)

## Usage
**[log.c](src/log.c?raw=1)** and **[log.h](src/log.h?raw=1)** should be dropped
into an existing project and compiled along with it.

There are two functions in log.c to be completed by the user:
```c
void uartSendByte(uint8_t byte);
uint32_t getTimestamp ();
```
uartSendByte requires a driver for your device to put a single byte onto the uart transmit pin (see example for atmega4809)

getTimestamp is required if timestamps or timeoffsets are desired.  An RTC or 1 second timer can be used.

The library provides 6 function-like macros for logging:

```c
log_trace(const char *fmt, ...);
log_debug(const char *fmt, ...);
log_info(const char *fmt, ...);
log_warn(const char *fmt, ...);
log_error(const char *fmt, ...);
log_fatal(const char *fmt, ...);
```



Each function takes a format string similar to printf followed by additional arguments:

I tried to keep things small by not including printf, so the only formatting available is:
| Format  | Description |
| ------------- | ------------- |
| %d  | unsigned 16bit integer  |
| %l  | unsigned 32bit integer  |
| %i  | binary                  |
| %h  | hex (wihout 0x prefix)  |

```c
log_trace("Register Contents %i", registerContents);
log_debug("Value: 0x%h", memoryContents);
log_info("i2c read device: %h address: %h contents: %d", slaveAddress, memoryAddress, memoryContents);
log_warn("i2c bus is stuck");
log_error("Failed with error code (%d)", errorCode);
log_fatal("No response");	
```

#### Set Log Level
To set the log level, set the definition to desired level
```c
#define LOG_LEVEL	LOG_TRACE	//no log output below this level
```

#### Enable Colour
To enable colour, define LOG_USE_COLR
```c
#define LOG_USE_COLOR	 //comment this line if colour not desired
```

#### Enable Timestamps
To enable timestamps, define LOG_TIME
```c
#define LOG_TIME	//comment this line if timestamps not desired
```
## License
This library is free software; you can redistribute it and/or modify it under
the terms of the MIT license. See [LICENSE](LICENSE) for details.
