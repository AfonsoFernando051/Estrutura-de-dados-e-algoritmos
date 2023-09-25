################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/funcoes.c \
../src/lista_ziviani.c 

C_DEPS += \
./src/funcoes.d \
./src/lista_ziviani.d 

OBJS += \
./src/funcoes.o \
./src/lista_ziviani.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/funcoes.d ./src/funcoes.o ./src/lista_ziviani.d ./src/lista_ziviani.o

.PHONY: clean-src

