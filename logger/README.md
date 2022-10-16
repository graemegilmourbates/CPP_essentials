# Logger

### Three levels
- DEBUG
- ERROR
- WARNING

### Usage:
```
Logger logger=Logger();
logger.log("Im a log");
logger.warning("Im a warning");
logger.error("Im an error");

logger.set_level("Warning");
logger.set_file("my_log_file.txt");
logger.log_to_file(false);
logger.log_to_screen(true);
```
