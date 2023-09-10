################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/include/GPIO_Driver.c 

OBJS += \
./Mcal/include/GPIO_Driver.o 

C_DEPS += \
./Mcal/include/GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/include/%.o: ../Mcal/include/%.c Mcal/include/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\LapTechnology\eclipse-workspace\voting_machine\Mcal\include" -I"C:\Users\LapTechnology\eclipse-workspace\voting_machine\library\include" -I"C:\Users\LapTechnology\eclipse-workspace\voting_machine\App\include" -I"C:\Users\LapTechnology\eclipse-workspace\voting_machine\Hall\include\KAYPAB_DRIVER" -I"C:\Users\LapTechnology\eclipse-workspace\voting_machine\Hall\include\LCD_DRIVER" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


