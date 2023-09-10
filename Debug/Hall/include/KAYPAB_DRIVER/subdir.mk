################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hall/include/KAYPAB_DRIVER/keypad.c 

OBJS += \
./Hall/include/KAYPAB_DRIVER/keypad.o 

C_DEPS += \
./Hall/include/KAYPAB_DRIVER/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Hall/include/KAYPAB_DRIVER/%.o: ../Hall/include/KAYPAB_DRIVER/%.c Hall/include/KAYPAB_DRIVER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\LapTechnology\eclipse-workspace\voting_machine\Mcal\include" -I"C:\Users\LapTechnology\eclipse-workspace\voting_machine\library\include" -I"C:\Users\LapTechnology\eclipse-workspace\voting_machine\App\include" -I"C:\Users\LapTechnology\eclipse-workspace\voting_machine\Hall\include\KAYPAB_DRIVER" -I"C:\Users\LapTechnology\eclipse-workspace\voting_machine\Hall\include\LCD_DRIVER" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


