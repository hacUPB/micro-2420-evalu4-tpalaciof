################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/startup_mke18f16.c 

C_DEPS += \
./startup/startup_mke18f16.d 

OBJS += \
./startup/startup_mke18f16.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKE18F512VLL16 -DCPU_MKE18F512VLL16_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\tpala\Documents\MCUXpressoIDE_24.9.25\workspace\LCD_FINAL_Project\board" -I"C:\Users\tpala\Documents\MCUXpressoIDE_24.9.25\workspace\LCD_FINAL_Project\source" -I"C:\Users\tpala\Documents\MCUXpressoIDE_24.9.25\workspace\LCD_FINAL_Project" -I"C:\Users\tpala\Documents\MCUXpressoIDE_24.9.25\workspace\LCD_FINAL_Project\drivers" -I"C:\Users\tpala\Documents\MCUXpressoIDE_24.9.25\workspace\LCD_FINAL_Project\CMSIS" -I"C:\Users\tpala\Documents\MCUXpressoIDE_24.9.25\workspace\LCD_FINAL_Project\device" -I"C:\Users\tpala\Documents\MCUXpressoIDE_24.9.25\workspace\LCD_FINAL_Project\component\uart" -I"C:\Users\tpala\Documents\MCUXpressoIDE_24.9.25\workspace\LCD_FINAL_Project\component\lists" -I"C:\Users\tpala\Documents\MCUXpressoIDE_24.9.25\workspace\LCD_FINAL_Project\utilities" -I"C:\Users\tpala\Documents\MCUXpressoIDE_24.9.25\workspace\LCD_FINAL_Project\component\serial_manager" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_mke18f16.d ./startup/startup_mke18f16.o

.PHONY: clean-startup

