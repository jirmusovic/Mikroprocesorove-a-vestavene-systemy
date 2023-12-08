#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "nvs.h"
#include <string.h>


#define LED_PIN_G GPIO_NUM_23
#define LED_PIN_R GPIO_NUM_19

#define ROW_1 GPIO_NUM_14
#define ROW_2 GPIO_NUM_26
#define ROW_3 GPIO_NUM_25
#define ROW_4 GPIO_NUM_16

#define COL_1 GPIO_NUM_27
#define COL_2 GPIO_NUM_12
#define COL_3 GPIO_NUM_17

static const char* TAG = "TAG";


void hw_init(){
    
    esp_log_level_set("*", ESP_LOG_INFO);

    esp_rom_gpio_pad_select_gpio(COL_1);
    gpio_set_direction(COL_1, GPIO_MODE_OUTPUT);
    esp_rom_gpio_pad_select_gpio(COL_2);
    gpio_set_direction(COL_2, GPIO_MODE_OUTPUT);
    esp_rom_gpio_pad_select_gpio(COL_3);
    gpio_set_direction(COL_3, GPIO_MODE_OUTPUT);

    esp_rom_gpio_pad_select_gpio(ROW_1);
    gpio_set_direction(ROW_1, GPIO_MODE_INPUT);
    gpio_set_pull_mode(ROW_1, GPIO_PULLDOWN_ENABLE);
    esp_rom_gpio_pad_select_gpio(ROW_2);
    gpio_set_direction(ROW_2, GPIO_MODE_INPUT);
    gpio_set_pull_mode(ROW_2, GPIO_PULLDOWN_ENABLE);
    esp_rom_gpio_pad_select_gpio(ROW_3);
    gpio_set_direction(ROW_3, GPIO_MODE_INPUT);
    gpio_set_pull_mode(ROW_3, GPIO_PULLDOWN_ENABLE);
    esp_rom_gpio_pad_select_gpio(ROW_4);
    gpio_set_direction(ROW_4, GPIO_MODE_INPUT);
    gpio_set_pull_mode(ROW_4, GPIO_PULLDOWN_ENABLE);

    esp_rom_gpio_pad_select_gpio(LED_PIN_G);
    gpio_set_direction(LED_PIN_G, GPIO_MODE_OUTPUT);
    esp_rom_gpio_pad_select_gpio(LED_PIN_R);
    gpio_set_direction(LED_PIN_R, GPIO_MODE_OUTPUT);
}

int password_check(char saved_pwd, char input_pwd){
        if(saved_pwd == input_pwd){
            gpio_set_level(LED_PIN_R, 0);
            gpio_set_level(LED_PIN_G, 1);
            vTaskDelay(2000 / portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN_R, 1);
            gpio_set_level(LED_PIN_G, 0);
        }
}

void app_main() {

    hw_init();
    char password[100] = "";
    int i = 0;
    char saved_pwd[100] = "1234";
    
    while(1) {

        password_check(saved_pwd, password);
        gpio_set_level(LED_PIN_R, 1);

        //1st col
        gpio_set_level(COL_1, 1);
        if(gpio_get_level(ROW_1) == 1){
            password[i] = '1';
            i++;
            gpio_set_level(LED_PIN_G, 1);
            vTaskDelay(100 / portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN_G, 0);
        }else if(gpio_get_level(ROW_2) == 1){
            password[i] = '4';
            i++;
            gpio_set_level(LED_PIN_G, 1);
            vTaskDelay(100 / portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN_G, 0);
        }else if(gpio_get_level(ROW_3) == 1){
            password[i] = '7';
            i++;
            gpio_set_level(LED_PIN_G, 1);
            vTaskDelay(100 / portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN_G, 0);
        }else if(gpio_get_level(ROW_4) == 1){
            password[i] = '*';
            i++;
            gpio_set_level(LED_PIN_G, 1);
            vTaskDelay(100 / portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN_G, 0);
        }
        gpio_set_level(COL_1, 0);

        //2nd col
        gpio_set_level(COL_2, 1);
        if(gpio_get_level(ROW_1) == 1){
            password[i] = '2';
            i++;
            gpio_set_level(LED_PIN_G, 1);
            vTaskDelay(100 / portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN_G, 0);
        }else if(gpio_get_level(ROW_2) == 1){
            password[i] = '5';
            i++;
            gpio_set_level(LED_PIN_G, 1);
            vTaskDelay(100 / portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN_G, 0);
        }else if(gpio_get_level(ROW_3) == 1){
            password[i] = '8';
            i++;
            gpio_set_level(LED_PIN_G, 1);
            vTaskDelay(100 / portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN_G, 0);
        }else if(gpio_get_level(ROW_4) == 1){
            password[i] = '0';
            i++;
            gpio_set_level(LED_PIN_G, 1);
            vTaskDelay(100 / portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN_G, 0);
        }
        gpio_set_level(COL_2, 0);

        //3rd col
        gpio_set_level(COL_3, 1);
        if(gpio_get_level(ROW_1) == 1){
            password[i] = '3';
            i++;
            gpio_set_level(LED_PIN_G, 1);
            vTaskDelay(100 / portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN_G, 0);
        }else if(gpio_get_level(ROW_2) == 1){
            password[i] = '6';
            i++;
            gpio_set_level(LED_PIN_G, 1);
            vTaskDelay(100 / portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN_G, 0);
        }else if(gpio_get_level(ROW_3) == 1){
            password[i] = '9';
            i++;
            gpio_set_level(LED_PIN_G, 1);
            vTaskDelay(100 / portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN_G, 0);
        }else if(gpio_get_level(ROW_4) == 1){
            password[i] = '#';
            i++;
            gpio_set_level(LED_PIN_G, 1);
            vTaskDelay(100 / portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN_G, 0);
        }
        gpio_set_level(COL_3, 0);

        if(i >= 3){
            if((password[i-3] == '#') && (password[i-2] == '#') && (password[i-1] == '#')){
                for(int j = 0; j < 100; j++){
                    password[j] = '\0';
                }
            i = 0;            
            }
        }

        //#906090*
        if(i >= 8){
            if((password[i-8] == '#') && (password[i-7] == '9') && (password[i-6] == '0') && (password[i-5] == '6')
            && (password[i-4] == '0') && (password[i-3] == '9') && (password[i-2] == '0') && (password[i-1] == '*')){
                for(int j = 4; j < 100; j++){
                    saved_pwd[0] = '5';
                    saved_pwd[1] = '6';
                    saved_pwd[2] = '7';
                    saved_pwd[3] = '8';
                    saved_pwd[j] = '\0';
                }
            i = 0;            
            }
        }

        ESP_LOGI(TAG, "password: %s", password);

        vTaskDelay(100 / portTICK_PERIOD_MS);
    
    }
}