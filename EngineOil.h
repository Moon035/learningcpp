//
//  EngineOil.h
//  learningcpp
//
//  Created by Sejun Moon on 2/9/24.
//

#ifndef EngineOil_h
#define EngineOil_h


#include"CarInfo.h"
#include<chrono>
#include<ctime>
#include<fstream>
#include"EmailUtils.h"

class EngineOil: public CarInfo{
    
    private:
    std::string name;
    std::string phone;
    std::string brand;
    std::string model;
    int year;
    
    
    void setName(std::string name){
        this->name = name;
    }
    
     void setPhone(std::string phone){
        this->phone = phone;
    }
    
     void setBrand(std::string brand){
        this->brand = brand;
    }
    
     void setModel(std::string model){
        this->model = model;
    }
    
     void setYear(int year){
        this->year = year;
    }
    
    
    public:
    int changeyear;
    int changemonth;
    int changedate;
    int reminderyear;
    int remindermonth;
    int reminderday;
    
    std::chrono::system_clock::time_point six_months_later;
    std::chrono::system_clock::time_point reminderdate;
    
    
    EngineOil(){
        
    }
    
    EngineOil(std::string name, std::string phone, std::string brand, std::string model, int year){
        this->name = getOwnerName();
        this->phone = getOwnerPhoneNumber();
        this->brand = getCarMaker();
        this->model = getCarModel();
        this->year = getCarYear();
    }
    
    EngineOil(const EngineOil& other){
        this->name = other.name;
        this->phone = other.phone;
        this->brand = other.brand;
        this->model = other.model;
        this->year = other.year;
    }
    
    ~EngineOil(){
        
    }
    
    std::string getName(){
        return name;
    }
    
     std::string getPhone(){
        return phone;
    }
    
     std::string getBrand(){
        return brand;
    }
    
     std::string getModel(){
        return model;
    }
    
     int getYear(){
        return year;
    }
    
    void Agreement(){
        char c;
        std::cout << "\n\n\t\t Do you want to change your engineoil ?";
        std::cout << "\n\t\t\tIf yes, enter y.";
        std::cin >> c;
        if(c == 'y'){
            oilChangeDate();
        }
        else{
            exit(0);
        }
    }
    
    void oilChangeDate(){
        
        std::cout <<"\n\n\t Engine oil has been successfully replaced ! ";
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        auto local_time = std::localtime(&now_c);
        
        changeyear = 1900 + local_time->tm_year;
        changemonth = 1 + local_time->tm_mon;
        changedate = local_time->tm_mday;
        
        std::cout << "\n\n\t\t\t Oil Change Date\n\n";
        std::cout << "\tYear: " << changeyear <<std::endl;
        std::cout << "\tMonth: " << changemonth << std::endl;
        std::cout << "\tDay: " << changedate << std::endl;
        
        std::fstream record, recordcopy;
        record.open("database.txt",std::ios::in);
            if(!record){
                record.open("database.txt",std::ios::app|std::ios::out);
                record << name << " " << phone << " " << brand << " " << model << " " << year << " "
                << changemonth << " " << changedate << " " << changeyear << std::endl;
            }
            else{
                recordcopy.open("databasecopy.txt", std::ios::app|std::ios::out);
                record >> name >> phone >> brand >> model >> year >> changemonth >> changedate >>
                changeyear;
                while(!record.eof()){
                    recordcopy << name << " " << phone << " " << brand << " " << model << " " << year << " "
                << changemonth << " " << changedate << " " << changeyear << std::endl;
            }
        record.close();
        recordcopy.close();
        
        remove("database.txt");
        rename("databasecopy.txt","database.txt");
            }
        
        six_months_later = now + std::chrono::hours(24*180);
        auto six_months_later_time_t = std::chrono::system_clock::to_time_t(six_months_later);
        auto six_months_later_local = std::localtime(&six_months_later_time_t);
        
    
        
        std::cout << "\n\n\n\tPlease come to change your engine oil on this date\n";
        std::cout << "\t6 months later: " << 1900 + six_months_later_local->tm_year << ". "
        << 1 + six_months_later_local->tm_mon << ". " << six_months_later_local->tm_mday << std::endl;
        
        std::string emailMessage = "Dear " + name + ",\n\n"
                                       "This is a reminder that your next engine oil change is due soon.\n"
                                       "Your last oil change date was: " + std::to_string(changeyear) + "-" + std::to_string(changemonth) + "-" + std::to_string(changedate) + ".\n"
                                       "Please come to change your engine oil on: " + std::to_string(1900 + six_months_later_local->tm_year) + "-" + std::to_string(1 + six_months_later_local->tm_mon) + "-" + std::to_string(six_months_later_local->tm_mday) + ".\n\n"
                                        "Best regards,\n" +
                                        "Your Service Team";
       
            
            sendEmail(this->getOwnerEmail(),"msj990305@gmail.com", "brlt juge wqha bxbw", emailMessage);
        
        
        
    }
    
    
};

#endif /* EngineOil_h */
