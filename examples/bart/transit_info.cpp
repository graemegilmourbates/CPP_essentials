#include <iostream>
#include "stationInfo.cpp"

int main(){
  auto info=getStationInfo("plza");
  std::cout << info.name << std::endl;
  // std::cout << URLGet(bartStationRequestURL("plza")) << std::endl;
  for(auto d : info.departures){
    std::cout << "Train to: " << d.destination << std::endl;
    for(auto t : d.times){
      std::cout << "\tIn " << t << " minutes" << std::endl;
    }
  }
  return 0;
}
