#import "logger.h"

int main(){
  Logger logger=Logger();
  logger.log("testing log");
  logger.warning("testing warning");
  logger.error("testing error");
  return 0;
}
