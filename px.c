#include <stdio.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <errno.h>
#include <stdlib.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main() {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char error[CURL_ERROR_SIZE];
    char url[50] = "http://www.google.com.tw/"; //要下載的網址
    char outfilename[FILENAME_MAX] = "/var/X/index.html"; //存檔路徑
	curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename,"w");
        if (fp == NULL){
            fprintf(stderr, "open error for %s, errno = %d\n", outfilename, errno);
            exit(1);
        }
        curl_easy_setopt(curl, CURLOPT_URL, url); //設定網址
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		//如果有錯誤的話會將錯誤寫在這邊的error buffer
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return 0;
}
