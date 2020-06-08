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
    char url[300] = "https://drive.google.com/uc?export=download&id=1wcLsiLUtTZr-GVPvOEUtT2ab_koU-j5j"; //要下載的網址
    // char url[333] = "ttps://raw.githubusercontent.com/ren-hao/5-Linux-Mandatory-Access-Control-jhcheng/master/px.c";
    char outfilename[FILENAME_MAX] = "/var/X/py.c"; //存檔路徑
	curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename,"wb");
        if (fp == NULL){
            fprintf(stderr, "open error for %s, errno = %d\n", outfilename, errno);
            exit(1);
        }
        curl_easy_setopt(curl, CURLOPT_URL, url); //設定網址
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		//如果有錯誤的話會將錯誤寫在這邊的error buffer
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    // compile py.c by gcc
    system("cd /var/X && gcc py.c -o py");
    return 0;
}
