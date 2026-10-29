################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/Third_Party/FatFs/src/option/subdir.mk
-include Middlewares/Third_Party/FatFs/src/subdir.mk
-include FATFS/Target/subdir.mk
-include FATFS/App/subdir.mk
-include Drivers/STM32L4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Core/Librerias/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Clase74_MANEJO_SD_FIR_stm32L476RG
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Clase74_MANEJO_SD_FIR_stm32L476RG.elf \

MAP_FILES += \
Clase74_MANEJO_SD_FIR_stm32L476RG.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Clase74_MANEJO_SD_FIR_stm32L476RG.list \

OBJCOPY_HEX += \
Clase74_MANEJO_SD_FIR_stm32L476RG.hex \


# All Target
all: main-build

# Main-build Target
main-build: Clase74_MANEJO_SD_FIR_stm32L476RG.elf secondary-outputs

# Tool invocations
Clase74_MANEJO_SD_FIR_stm32L476RG.elf Clase74_MANEJO_SD_FIR_stm32L476RG.map: $(OBJS) $(USER_OBJS) C:\Users\MIGUEL\ A.\ FERNANDEZ\Desktop\Lib_mikroC_y_Otros\linkSTM32\Clase74_MANEJO_SD_FIR_stm32L476RG\STM32L476RGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Clase74_MANEJO_SD_FIR_stm32L476RG.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\MIGUEL A. FERNANDEZ\Desktop\Lib_mikroC_y_Otros\linkSTM32\Clase74_MANEJO_SD_FIR_stm32L476RG\STM32L476RGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Clase74_MANEJO_SD_FIR_stm32L476RG.map" -Wl,--gc-sections -static -L../Middlewares/ST/ARM/DSP/Lib --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -u _scanf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Clase74_MANEJO_SD_FIR_stm32L476RG.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Clase74_MANEJO_SD_FIR_stm32L476RG.list"
	@echo 'Finished building: $@'
	@echo ' '

Clase74_MANEJO_SD_FIR_stm32L476RG.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Clase74_MANEJO_SD_FIR_stm32L476RG.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Clase74_MANEJO_SD_FIR_stm32L476RG.elf Clase74_MANEJO_SD_FIR_stm32L476RG.hex Clase74_MANEJO_SD_FIR_stm32L476RG.list Clase74_MANEJO_SD_FIR_stm32L476RG.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
