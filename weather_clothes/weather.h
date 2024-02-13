//
//  weather.h
//  weather_clothes
//
//  Created by Sejun Moon on 2/9/24.
//

#ifndef weather_h
#define weather_h
class Weather{
  
private:
    std::string weather;
    float celsius;
    float fahrenheit;
    std::string clothes;
    
public:
    
    void ask_weather(){
        
        std::cout << "          Today's weather          ";
        std::cout << "\n\n\n          "
    }
    
};

#endif /* weather_h */
