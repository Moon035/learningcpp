//
//  OwnerInfo.h
//  learningcpp
//
//  Created by Sejun Moon on 2/9/24.
//

#ifndef OwnerInfo_h
#define OwnerInfo_h


#include<iostream>
#include<string>

class OwnerInfo{
  
  private:
  std::string ownerName;
  std::string ownerPhoneNumber;
  std::string ownerEmail;
  
  void setOwnerName(std::string ownerName){
      this->ownerName = ownerName;
  }
  
  void setOwnerPhoneNumber(std::string ownerPhoneNumber){
      this->ownerPhoneNumber = ownerPhoneNumber;
  }
    
    void setOwnerEmail(std::string ownerEmail){
        this->ownerEmail = ownerEmail;
    }
  
  public:
  
  OwnerInfo(){
      
  }
  
  OwnerInfo(std::string ownerName, std::string ownerPhoneNumber, std::string ownerEmail){
      this->ownerName = ownerName;
      this->ownerPhoneNumber = ownerPhoneNumber;
      this->ownerEmail = ownerEmail;
  }
  
  OwnerInfo(const OwnerInfo& other):ownerName(other.ownerName), ownerPhoneNumber(other.ownerPhoneNumber),ownerEmail(other.ownerEmail){
      
  }
  
  ~OwnerInfo(){
      
  }
  
  std::string getOwnerName()const{
      return ownerName;
  }
  
  std::string getOwnerPhoneNumber()const{
      return ownerPhoneNumber;
  }
    
    std::string getOwnerEmail()const{
        return ownerEmail;
    }
  
  virtual void askUserInfo(){
      std::cout << "\n\n_________________________ Owner Info _________________________";
      std::cout << "\n\n\t\t\tOwner Name : ";
      std::cin >> ownerName;
      std::cout << "\n\n\t\t\tPhone number : ";
      std::cin >> ownerPhoneNumber;
      std::cout << "\n\n\t\t\tEmail : ";
      std::cin >> ownerEmail;
  }
  
  virtual void showUserInfo(){
      std::cout << "\n\n_________________________" << ownerName <<" Info _________________________";
      std::cout << "\n\n\t\t\tOwner Name : " << ownerName <<"\n";
      std::cout << "\n\n\t\t\tPhone Number : " << ownerPhoneNumber <<"\n";
      std::cout << "\n\n\t\t\tEmail : " << ownerEmail <<"\n";
  }
  
  
    
};

#endif /* OwnerInfo_h */
