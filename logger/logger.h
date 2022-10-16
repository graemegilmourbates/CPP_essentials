#include <iostream>
#include <fstream>

#ifndef linkedList_h
#define linkedList_h

class Logger{
  private:
    bool to_screen=true;
    bool to_file=false;
    int debug_level;
    int debug_file_level=2;
    std::ofstream log_file;

  public:
    Logger(){
      debug_level=0;
    }

    Logger(int level){
      debug_level=level;
    }

    Logger(std::string level){
      if(level=="ERROR"){
        debug_level=2;
      } else if(level=="WARNING"){
        debug_level=1;
      } else{
        debug_level=0;
      }
    }

    ~Logger(){
      if(log_file.is_open()){
        log_file.close();
      }
    }

    void set_level(int level){
      debug_level=level;
    }

    void set_level(std::string level){
      if(level=="ERROR"){
        debug_level=2;
      } else if(level=="WARNING"){
        debug_level=1;
      } else{
        debug_level=0;
      }
    }

    void set_log_file(std::string file){
      log_file.open(file);
    }

    void log(std::string message){
      if(to_screen){
        if(debug_level==0){
          std::cout << "LOG: " << message << std::endl;
        }
      }
      if(to_file){
        if(log_file.is_open()){
          if(debug_file_level==1){
            log_file << "LOG: " << message << "\n";
          }
        } else {
          throw "No file opened";
        }
      }
    }

    void warning(std::string message){
      if(to_screen){
        if(debug_level<2){
          std::cout << "WARNING: " << message << std::endl;
        }
      }
      if(to_file){
        if(log_file.is_open()){
          if(debug_file_level>1){
            log_file << "WARNING: " << message << "\n";
          }
        } else {
          throw "No file opened";
        }
      }
    }

    void error(std::string message){
      if(to_screen){
        std::cout << "ERROR: " << message << std::endl;
      }
      if(to_file){
        if(log_file.is_open()){
          log_file << "ERROR: " << message << "\n";
        } else {
          throw "No file opened";
        }
      }
    }
};

#endif
