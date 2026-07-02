idf_component_register(
        SRCS "main.c" "hx711.c" "storage.c" "button.c" "console.c"
        INCLUDE_DIRS "." "include"
        PRIV_REQUIRES esp_timer esp_driver_gpio nvs_flash
)