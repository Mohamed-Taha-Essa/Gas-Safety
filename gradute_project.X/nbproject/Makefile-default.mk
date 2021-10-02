#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/gradute_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/gradute_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_LAYER/7_segment/ecu_seven_segment.c ECU_LAYER/character_lcd/ecu_character_lcd.c ECU_LAYER/ecu_dc_motor/ecu_dc_motor.c ECU_LAYER/KeyPad/ecu_keypad.c ECU_LAYER/LED/led.c ECU_LAYER/Relay/ecu_relay.c ECU_LAYER/ecu_init.c MCAL_LAYER/ADC/hal_adc.c MCAL_LAYER/GPIO/hal_gpio.c MCAL_LAYER/Interrupt/mcal_external_interrupt.c MCAL_LAYER/Interrupt/mcal_internal_interrupt.c MCAL_LAYER/Interrupt/mcal_interrupt_manager.c MCAL_LAYER/USART/hal_USART.c MCAL_LAYER/device_config.c MCAL_LAYER/Mcal_init.c project.c ECU_LAYER/gsm.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1 ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1 ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1 ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1 ${OBJECTDIR}/ECU_LAYER/LED/led.p1 ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1 ${OBJECTDIR}/ECU_LAYER/ecu_init.p1 ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1 ${OBJECTDIR}/MCAL_LAYER/device_config.p1 ${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1 ${OBJECTDIR}/project.p1 ${OBJECTDIR}/ECU_LAYER/gsm.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1.d ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1.d ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1.d ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1.d ${OBJECTDIR}/ECU_LAYER/LED/led.p1.d ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1.d ${OBJECTDIR}/ECU_LAYER/ecu_init.p1.d ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1.d ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d ${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1.d ${OBJECTDIR}/project.p1.d ${OBJECTDIR}/ECU_LAYER/gsm.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1 ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1 ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1 ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1 ${OBJECTDIR}/ECU_LAYER/LED/led.p1 ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1 ${OBJECTDIR}/ECU_LAYER/ecu_init.p1 ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1 ${OBJECTDIR}/MCAL_LAYER/device_config.p1 ${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1 ${OBJECTDIR}/project.p1 ${OBJECTDIR}/ECU_LAYER/gsm.p1

# Source Files
SOURCEFILES=ECU_LAYER/7_segment/ecu_seven_segment.c ECU_LAYER/character_lcd/ecu_character_lcd.c ECU_LAYER/ecu_dc_motor/ecu_dc_motor.c ECU_LAYER/KeyPad/ecu_keypad.c ECU_LAYER/LED/led.c ECU_LAYER/Relay/ecu_relay.c ECU_LAYER/ecu_init.c MCAL_LAYER/ADC/hal_adc.c MCAL_LAYER/GPIO/hal_gpio.c MCAL_LAYER/Interrupt/mcal_external_interrupt.c MCAL_LAYER/Interrupt/mcal_internal_interrupt.c MCAL_LAYER/Interrupt/mcal_interrupt_manager.c MCAL_LAYER/USART/hal_USART.c MCAL_LAYER/device_config.c MCAL_LAYER/Mcal_init.c project.c ECU_LAYER/gsm.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/gradute_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1: ECU_LAYER/7_segment/ecu_seven_segment.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/7_segment" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1 ECU_LAYER/7_segment/ecu_seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.d ${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1: ECU_LAYER/character_lcd/ecu_character_lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/character_lcd" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1 ECU_LAYER/character_lcd/ecu_character_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.d ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1: ECU_LAYER/ecu_dc_motor/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/ecu_dc_motor" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1 ECU_LAYER/ecu_dc_motor/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.d ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1: ECU_LAYER/KeyPad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/KeyPad" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1 ECU_LAYER/KeyPad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.d ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/LED/led.p1: ECU_LAYER/LED/led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/LED" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LED/led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LED/led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/LED/led.p1 ECU_LAYER/LED/led.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/LED/led.d ${OBJECTDIR}/ECU_LAYER/LED/led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/LED/led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1: ECU_LAYER/Relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/Relay" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1 ECU_LAYER/Relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.d ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/ecu_init.p1: ECU_LAYER/ecu_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ecu_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ecu_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/ecu_init.p1 ECU_LAYER/ecu_init.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/ecu_init.d ${OBJECTDIR}/ECU_LAYER/ecu_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/ecu_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1: MCAL_LAYER/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 MCAL_LAYER/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.d ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1: MCAL_LAYER/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 MCAL_LAYER/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1: MCAL_LAYER/Interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1 MCAL_LAYER/Interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1: MCAL_LAYER/Interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1 MCAL_LAYER/Interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1: MCAL_LAYER/Interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1 MCAL_LAYER/Interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1: MCAL_LAYER/USART/hal_USART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/USART" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1 MCAL_LAYER/USART/hal_USART.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.d ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/device_config.p1: MCAL_LAYER/device_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/device_config.p1 MCAL_LAYER/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/device_config.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1: MCAL_LAYER/Mcal_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1 MCAL_LAYER/Mcal_init.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Mcal_init.d ${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/project.p1: project.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/project.p1.d 
	@${RM} ${OBJECTDIR}/project.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/project.p1 project.c 
	@-${MV} ${OBJECTDIR}/project.d ${OBJECTDIR}/project.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/project.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/gsm.p1: ECU_LAYER/gsm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/gsm.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/gsm.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/gsm.p1 ECU_LAYER/gsm.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/gsm.d ${OBJECTDIR}/ECU_LAYER/gsm.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/gsm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1: ECU_LAYER/7_segment/ecu_seven_segment.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/7_segment" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1 ECU_LAYER/7_segment/ecu_seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.d ${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/7_segment/ecu_seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1: ECU_LAYER/character_lcd/ecu_character_lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/character_lcd" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1 ECU_LAYER/character_lcd/ecu_character_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.d ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/character_lcd/ecu_character_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1: ECU_LAYER/ecu_dc_motor/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/ecu_dc_motor" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1 ECU_LAYER/ecu_dc_motor/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.d ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/ecu_dc_motor/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1: ECU_LAYER/KeyPad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/KeyPad" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1 ECU_LAYER/KeyPad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.d ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/KeyPad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/LED/led.p1: ECU_LAYER/LED/led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/LED" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LED/led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/LED/led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/LED/led.p1 ECU_LAYER/LED/led.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/LED/led.d ${OBJECTDIR}/ECU_LAYER/LED/led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/LED/led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1: ECU_LAYER/Relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER/Relay" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1 ECU_LAYER/Relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.d ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/Relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/ecu_init.p1: ECU_LAYER/ecu_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ecu_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/ecu_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/ecu_init.p1 ECU_LAYER/ecu_init.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/ecu_init.d ${OBJECTDIR}/ECU_LAYER/ecu_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/ecu_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1: MCAL_LAYER/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1 MCAL_LAYER/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.d ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1: MCAL_LAYER/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1 MCAL_LAYER/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1: MCAL_LAYER/Interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1 MCAL_LAYER/Interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1: MCAL_LAYER/Interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1 MCAL_LAYER/Interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1: MCAL_LAYER/Interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1 MCAL_LAYER/Interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1: MCAL_LAYER/USART/hal_USART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER/USART" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1 MCAL_LAYER/USART/hal_USART.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.d ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/USART/hal_USART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/device_config.p1: MCAL_LAYER/device_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/device_config.p1 MCAL_LAYER/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/device_config.d ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1: MCAL_LAYER/Mcal_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL_LAYER" 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1 MCAL_LAYER/Mcal_init.c 
	@-${MV} ${OBJECTDIR}/MCAL_LAYER/Mcal_init.d ${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_LAYER/Mcal_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/project.p1: project.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/project.p1.d 
	@${RM} ${OBJECTDIR}/project.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/project.p1 project.c 
	@-${MV} ${OBJECTDIR}/project.d ${OBJECTDIR}/project.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/project.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_LAYER/gsm.p1: ECU_LAYER/gsm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ECU_LAYER" 
	@${RM} ${OBJECTDIR}/ECU_LAYER/gsm.p1.d 
	@${RM} ${OBJECTDIR}/ECU_LAYER/gsm.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_LAYER/gsm.p1 ECU_LAYER/gsm.c 
	@-${MV} ${OBJECTDIR}/ECU_LAYER/gsm.d ${OBJECTDIR}/ECU_LAYER/gsm.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_LAYER/gsm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/gradute_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/gradute_project.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/gradute_project.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/gradute_project.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/gradute_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/gradute_project.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/gradute_project.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
