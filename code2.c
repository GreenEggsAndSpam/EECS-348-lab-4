#include <stdio.h>

//function to convert celsius to fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

//function to convert fahrenheit to celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

//function to convert celsius to kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

//function to convert kelvin to celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

//function to convert fahrenheit to kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    float celsius = fahrenheit_to_celsius(fahrenheit);
    return celsius_to_kelvin(celsius);
}

//function to convert kelvin to fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    float celsius = kelvin_to_celsius(kelvin);
    return celsius_to_fahrenheit(celsius);
}

//function to categorize the temperature and give an advisory using celsius
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a heavy coat, it's freezing.\n");
    } else if (celsius >= 0 && celsius <= 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket, it's cold.\n");
    } else if (celsius > 10 && celsius <= 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: It's the perfect weather.\n");
    } else if (celsius > 25 && celsius <= 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated, it's hot.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: It's burning outside.\n");
    }
}

//error handling kelvin becuase it cannot be negative
int is_valid_kelvin(float kelvin) {
    return kelvin >= 0;
}

int main() {
    float temperature, converted_temp;
    int input_scale, target_scale;
    int valid_input = 0;  //flag to track valid input

    while (!valid_input) {
        //get temperature input from the user
        printf("Enter the temperature: ");
        while (scanf("%f", &temperature) != 1) {
            // If the input is invalid, prompt the user again
            printf("Invalid input. Please enter a valid temperature: ");
            while (getchar() != '\n');  // Clear the input buffer
        }

        //input the scale of the temperature
        do {
            printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
            scanf("%d", &input_scale);
            if (input_scale < 1 || input_scale > 3) {
                printf("Invalid scale. Please enter 1, 2, or 3.\n");
            }
        } while (input_scale < 1 || input_scale > 3);

        // user input validation for temperature when the scale is kelvin
        if (input_scale == 3 && !is_valid_kelvin(temperature)) {
            printf("Invalid Kelvin temperature. Kelvin cannot be negative. Please enter a valid temperature.\n");
            continue;  // Ask for valid input again
        }

        //user input the target scale 
        do {
            printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
            scanf("%d", &target_scale);
            if (target_scale < 1 || target_scale > 3) {
                printf("Invalid target scale. Please enter 1, 2, or 3.\n");
            }
        } while (target_scale < 1 || target_scale > 3);

        //error handling to check if the scales are the same
        if (input_scale == target_scale) {
            printf("Input and target scales are the same. Please choose a different target scale.\n");
            continue;  //ask for valid input again
        }

        //handle conversions based on the scales given by the user
        if (input_scale == 1 && target_scale == 2) {
            //celsius to fahrenheit
            converted_temp = celsius_to_fahrenheit(temperature);
            printf("Converted temperature: %.2f°F\n", converted_temp);
        } else if (input_scale == 1 && target_scale == 3) {
            //celsius to kelvin
            converted_temp = celsius_to_kelvin(temperature);
            printf("Converted temperature: %.2fK\n", converted_temp);
        } else if (input_scale == 2 && target_scale == 1) {
            //fahrenheit to celsius
            converted_temp = fahrenheit_to_celsius(temperature);
            printf("Converted temperature: %.2f°C\n", converted_temp);
        } else if (input_scale == 2 && target_scale == 3) {
            //fahrenheit to kelvin
            converted_temp = fahrenheit_to_kelvin(temperature);
            printf("Converted temperature: %.2fK\n", converted_temp);
        } else if (input_scale == 3 && target_scale == 1) {
            //kelvin to celsius
            converted_temp = kelvin_to_celsius(temperature);
            printf("Converted temperature: %.2f°C\n", converted_temp);
        } else if (input_scale == 3 && target_scale == 2) {
            //kelvin to fahrenheit
            converted_temp = kelvin_to_fahrenheit(temperature);
            printf("Converted temperature: %.2f°F\n", converted_temp);
        }

        //categorize the temperature in Celsius regardless of the input or target scale
        if (target_scale == 1) {
            categorize_temperature(converted_temp);  //celsius
        } else if (target_scale == 2) {
            categorize_temperature(fahrenheit_to_celsius(converted_temp));  //convert fahrenheit to celsius
        } else if (target_scale == 3) {
            categorize_temperature(kelvin_to_celsius(converted_temp));  //convert kelvin to celsius
        }

        valid_input = 1;  //mark that valid input has been processed and exit loop
    }

    return 0;
}
