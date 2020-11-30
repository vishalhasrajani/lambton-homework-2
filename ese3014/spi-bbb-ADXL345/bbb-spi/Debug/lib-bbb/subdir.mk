################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib-bbb/ADXL345.cpp \
../lib-bbb/BusDevice.cpp \
../lib-bbb/SPIDevice.cpp 

OBJS += \
./lib-bbb/ADXL345.o \
./lib-bbb/BusDevice.o \
./lib-bbb/SPIDevice.o 

CPP_DEPS += \
./lib-bbb/ADXL345.d \
./lib-bbb/BusDevice.d \
./lib-bbb/SPIDevice.d 


# Each subdirectory must supply rules for building sources it contributes
lib-bbb/%.o: ../lib-bbb/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I/home/star/cross-toolchain-beaglebone/workspace/bbb-spi/lib-bbb -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


