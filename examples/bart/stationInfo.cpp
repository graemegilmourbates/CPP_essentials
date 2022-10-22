#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "curlHandler.cpp"
#include <vector>

const std::string BART_URL="https://api.bart.gov/api/etd.aspx?";

struct departures{
  std::string destination;
  std::vector<std::string> times;
};

struct StationInformation{
  std::string name;
  std::vector<departures> departures;
};

std::string bartStationRequestURL(std::string station){
  std::string url=BART_URL;
  std::string origin="orig=" + station;
  url.append(origin);
  url.append("&cmd=etd");
  url.append("&key=MW9S-E7SL-26DU-VV8V");
  url.append("&json=y");
  return url;
}

std::string bartStationRequestURL(std::string station, std::string direction){
  std::string url=bartStationRequestURL(station);
  std::string dir="&dir="+direction;
  url.append(dir);
  return url;
}

rapidjson::Document parseJson(std::string data){
  rapidjson::Document document;
  document.Parse(data.c_str());
  return document;
}

StationInformation pullInfo(std::string request){
  std::string data=URLGet(request);
  rapidjson::Document document=parseJson(data);
  StationInformation temp;
  temp.name=document["root"]["station"][0]["name"].GetString();
  for(auto &v : document["root"]["station"][0]["etd"].GetArray()){
    departures d;
    d.destination=v["destination"].GetString();
    for(auto &t : v["estimate"].GetArray()){
      d.times.push_back(t["minutes"].GetString());
    }
    temp.departures.push_back(d);
  }
  return temp;
}

StationInformation getStationInfo(std::string station){
  std::string url=bartStationRequestURL(station);
  return pullInfo(url);
}

StationInformation getStationInfo(std::string station, std::string direction){
  std::string url=bartStationRequestURL(station, direction);
  return pullInfo(url);
}
