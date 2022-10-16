#import "logger.h"

const std::string LEVEL="DEBUG"

int main(){
  Logger logger=Logger(LEVEL);
  logger.log("testing log");
  logger.warning("testing warning");
  logger.error("testing error");
  return 0;
}
