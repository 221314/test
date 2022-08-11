#include <iostream>
//#include "json/json.h"
#include <curl/curl.h>
#include <string.h>

using namespace std;

// static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
// {  
//      ((string*)userp)->append((char*)contents, size * nmemb);
//      return size * nmemb;
// }

int main()
{
     CURL *curl;
     CURLcode curl_res;
     //string rBuffer;
     //string *s = new string("");

     //curl_global_init(CURL_GLOBAL_ALL);

     curl = curl_easy_init(); //curl 핸들
     if(curl)
     {
         curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/query.php");
         curl_easy_setopt(curl, CURLOPT_HTTPHEADER, "Content-Type: application/x-www-form-urlencoded");
         curl_easy_setopt(curl, CURLOPT_POST, 1);
         curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "test=data");
         //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
         //curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
         //curl_easy_setopt(curl, CURLOPT_WRITEDATA, s);
         curl_res = curl_easy_perform(curl); // curl 실행=request (res=respone은 curl 실행후 응답내용을 받음)
         if (curl_res != CURLE_OK) //request 실패시
             fprintf(stderr, "curl_easy_perform() failed: %s\n",    curl_easy_strerror(curl_res));
         curl_easy_cleanup(curl);
    }
     curl_global_cleanup();
 }
