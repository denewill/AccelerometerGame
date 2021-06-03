################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/PITlab5.cpp \
../Sources/delay.cpp \
../Sources/ftfl.cpp \
../Sources/hardware.cpp \
../Sources/i2c.cpp \
../Sources/main.cpp \
../Sources/mcpio.cpp \
../Sources/mma845x.cpp \
../Sources/spi.cpp \
../Sources/usbdmError.cpp 

OBJS += \
./Sources/PITlab5.o \
./Sources/delay.o \
./Sources/ftfl.o \
./Sources/hardware.o \
./Sources/i2c.o \
./Sources/main.o \
./Sources/mcpio.o \
./Sources/mma845x.o \
./Sources/spi.o \
./Sources/usbdmError.o 

CPP_DEPS += \
./Sources/PITlab5.d \
./Sources/delay.d \
./Sources/ftfl.d \
./Sources/hardware.d \
./Sources/i2c.d \
./Sources/main.d \
./Sources/mcpio.d \
./Sources/mma845x.d \
./Sources/spi.d \
./Sources/usbdmError.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -g3 -O0 -ffunction-sections -fdata-sections -fno-rtti -Wall -Wextra -DDEBUG_BUILD -I"C:/Users/USER/OneDrive - Swinburne University/SEM 5/EEE20003/Labs/Lab 5/lab5/Sources" -I"C:/Users/USER/OneDrive - Swinburne University/SEM 5/EEE20003/Labs/Lab 5/lab5/Project_Headers" -fno-exceptions -std=gnu++17 -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  -o "$@" $<
	@echo 'Finished building: $<'
	@echo ' '


