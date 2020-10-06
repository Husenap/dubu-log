![Windows](https://github.com/Husenap/dubu-log/workflows/Windows/badge.svg)
![Ubuntu](https://github.com/Husenap/dubu-log/workflows/Ubuntu/badge.svg)

```
   _     _           _         
 _| |_ _| |_ _ _ ___| |___ ___ 
| . | | | . | | |___| | . | . |
|___|___|___|___|   |_|___|_  |
                          |___|
```

C++ Logger using fmt for formatting

# Features

* Supports custom Logger implementations by implementing the `ILogger` interface
* Supports all the formatting options that you get from fmt

# Examples

##### **Log custom type**
```cpp
#include <dubu_log/dubu_log.h>

struct Vector {
  float x;
  float y;
  float z;

  friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
    return os << "(x: " << v.x << ", y: " << v.y << ", z: " << v.z << ")";
  }
};


int main(){
  dubu::log::Register<dubu::log::ConsoleLogger>();
  Vector v{1, 2, 3};
  DUBU_LOG_DEBUG("Vector: {}", v); // Vector: (x: 1, y: 2, z: 3)
}
```

##### **Log to file**
```cpp
#include <dubu_log/dubu_log.h>

int main(){
  dubu::log::Register<dubu::log::FileLogger>("log.txt");
  DUBU_LOG_DEBUG("this is in a file now :)");
}
```

##### **Implementing Custom Logger**
```cpp
#include <dubu_log/dubu_log.h>

class CustomLogger : dubu::log::ILogger {
protected:
  virtual void InternalLog(LogLevel           level,
                           const std::string& file,
                           uint32_t           line,
                           const std::string& function,
                           const std::string& text) override {
    // Custom logging implementation
  }
};

int main(){
  dubu::log::Register<CustomLogger>();
  DUBU_LOG_DEBUG("this is some cool custom logging");
}
```