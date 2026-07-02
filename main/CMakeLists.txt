idf_component_register(
        SRCS "main.c" "hx711.c" "storage.c"
        INCLUDE_DIRS "." "include"
        PRIV_REQUIRES esp_driver_gpio nvs_flash
)