//
//  EmailUtils.h
//  learningcpp
//
//  Created by Sejun Moon on 2/9/24.
//

#ifndef EmailUtils_h
#define EmailUtils_h
#include <curl/curl.h>

size_t playload_source(void *ptr, size_t size, size_t nmemb, void *userp){
    std::string *payload = static_cast <std::string*>(userp);
    if(payload->empty()){
        return 0;
    }
    
    size_t buffer_size = size * nmemb;
    
    if(buffer_size < payload->size()){
        memcpy(ptr, payload->c_str(), buffer_size);
        payload->erase(0, buffer_size);
        return buffer_size;
    }
    
    memcpy(ptr, payload->c_str(), payload->size());
    size_t result = payload->size();
    payload->clear();
    return result;
}


void sendEmail(const std::string& toEmail, const std::string& fromEmail, const std::string& fromPassword, const std::string& emailMessage){
    CURL *curl;
    CURLcode res = CURLE_OK;
    
    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);

//        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_USERNAME, fromEmail.c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, fromPassword.c_str());
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM,("<"+fromEmail+">").c_str());
        
        struct curl_slist *recipients = NULL;
        recipients = curl_slist_append(recipients, ("<" + toEmail + ">").c_str());
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        
        std::string emailData = "To: " + toEmail + "\r\n"
                                "From: " + fromEmail + "\r\n"
                                "\r\n"
                                "Subject: Engine Oil Change Reminder\r\n"
                                    "\r\n" + emailMessage;
        
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, playload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &emailMessage);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
//        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, emailData.c_str());
        
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK){
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
}



#endif /* EmailUtils_h */
