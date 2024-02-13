#include<iostream>
#include"EngineOil.h"



int main()
{
    EngineOil car1;
    car1.askUserInfo();
    car1.showUserInfo();
    car1.Agreement();
    
//    curl_version_info_data *vinfo = curl_version_info(CURLVERSION_NOW);
//        std::cout << "libcurl version: " << vinfo->version << std::endl;
//        std::cout << "Supported protocols: " << std::endl;
//    for (const char *const *protocol = vinfo->protocols; *protocol; ++protocol) {
//        std::cout << "- " << *protocol << std::endl;}
    return 0;
}
