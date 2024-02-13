//
//  CarInfo.h
//  learningcpp
//
//  Created by Sejun Moon on 2/9/24.
//

#ifndef CarInfo_h
#define CarInfo_h


#include"OwnerInfo.h"

class CarInfo: public OwnerInfo{
    
    private:
    std::string carMaker;
    std::string carModel;
    int carYear;
    
    void setCarMaker(std::string carMaker){
        this->carMaker = carMaker;
    }
    
    void setCarModel(std::string carModel){
        this->carModel = carModel;
    }
    
    void getCarYear(int carYear){
        this->carYear = carYear;
    }
    
    public:
    CarInfo(){
        
    }
    
    CarInfo(std::string carMaker, std::string carModel, int carYear):carMaker(carMaker),carModel(carModel),carYear(carYear){
        
    }
    
    CarInfo(const CarInfo& other):carMaker(other.carMaker),carModel(other.carModel),carYear(other.carYear){
        
    }
    
    ~CarInfo(){
        
    }
    
    std::string getCarMaker()const{
        return carMaker;
    }
    
    std::string getCarModel()const{
        return carModel;
    }
    
    int getCarYear()const{
        return carYear;
    }
    
    void askUserInfo()override{
        OwnerInfo::askUserInfo();
      std::cout << "\n\n_________________________ Car Info _________________________";
      std::cout << "\n\n\t\t\tCar Maker : ";
      std::cin >> carMaker;
      std::cout << "\n\n\t\t\tCar Model : ";
      std::cin >> carModel;
      std::cout << "\n\n\t\t\tCar Year : ";
      std::cin >> carYear;
  }
  
   void showUserInfo() override{
        OwnerInfo::showUserInfo();
      std::cout << "\n\n_________________________ Car Info _________________________";
      std::cout << "\n\n\t\t\tCar Maker : " << carMaker <<"\n";
      std::cout << "\n\n\t\t\tCar Model : " << carModel <<"\n";
      std::cout << "\n\n\t\t\tCar Year : " << carYear <<"\n";
      
  }
    
};

#endif /* CarInfo_h */
