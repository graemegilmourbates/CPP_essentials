#include <curl/curl.h>

static size_t WriteMemoryCallback(
  void *contents, size_t size, size_t nmemb, void *userp
){
  ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string URLGet(std::string url){
  CURL *curl_handle;
  CURLcode res;
  std::string readBuffer;

  curl_global_init(CURL_GLOBAL_ALL);

  curl_handle=curl_easy_init();
  if(curl_handle){
    curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    //preform request, store response in res
    auto res=curl_easy_perform(curl_handle);
    //check for errors
    if(res!=CURLE_OK){
      std::cout << "Failed request" << std::endl;
    }
  }
  curl_easy_cleanup(curl_handle);
  return readBuffer;
}
