//
//  main.cpp
//  weather_clothes
//
//  Created by Sejun Moon on 2/9/24.
//

#include <iostream>
#include<string>
#include<ctime>
#include<cstdlib>

class WeatherData{
    
private:
    double temperature;
    double humidity;
    std::string weatherConditions;
    
    void generateRandomWeatherData(WeatherData& weather){
        
    }
  
public:
    WeatherData():temperature(0), humidity(0),weatherConditions(""){
        
    }
    
    void setTemperature(double temp){temperature = temp;}
    void setHumidity(double hum){humidity = hum;}
    void setWeatherConditions(const std::string& conditions){weatherConditions = conditions;}
    
    double getTemperature(){return temperature;}
    double getHumidity(){return humidity;}
    std::string getWeatherConditions(){return weatherConditions;}
    
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
