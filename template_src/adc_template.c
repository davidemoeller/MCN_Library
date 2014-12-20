#include "template_all.h"
#include <math.h>

int datatest[] = {1, 5, 7, 2, 6, 7, 8, 2, 2, 7, 8, 3, 7, 3, 7, 3, 15, 6};

DSPfilter A0filter;
DSPfilter A1filter;
DSPfilter A2filter;
DSPfilter A3filter;
DSPfilter A4filter;
DSPfilter A5filter;
DSPfilter B0filter;
DSPfilter B1filter;
DSPfilter B2filter;
DSPfilter B3filter;
DSPfilter B4filter;
DSPfilter B5filter;
DSPfilter B6filter;
DSPfilter B7filter;


void adcinit()
{
	initDSPfilter(&A0filter, 1, TENK);
	initDSPfilter(&A1filter, ONEK, TENK);
	initDSPfilter(&A2filter, ONEK, TENK);
	initDSPfilter(&A3filter, ONEK, TENK);
	initDSPfilter(&A4filter, ONEK, TENK);
	initDSPfilter(&A5filter, ONEK, TENK);
	initDSPfilter(&B0filter, ONEK, TENK);
	initDSPfilter(&B1filter, ONEK, TENK);
	initDSPfilter(&B2filter, ONEK, TENK);
	initDSPfilter(&B3filter, ONEK, TENK);
	initDSPfilter(&B4filter, ONEK, TENK);
	initDSPfilter(&B5filter, ONEK, TENK);
	initDSPfilter(&B6filter, ONEK, TENK);
	initDSPfilter(&B7filter, ONEK, TENK);

	InitAdc();  // Init the ADC

	EALLOW;

	// Comment out other unwanted lines.
	GpioCtrlRegs.AIODIR.all = 0x0000;

	GpioCtrlRegs.AIOMUX1.bit.AIO2 = 2;    // Configure AIO2 for A2 (analog input) operation
	GpioCtrlRegs.AIOMUX1.bit.AIO4 = 2;    // Configure AIO4 for A4 (analog input) operation
	//GpioCtrlRegs.AIOMUX1.bit.AIO6 = 2;    // Configure AIO6 for A6 (analog input) operation
	GpioCtrlRegs.AIOMUX1.bit.AIO10 = 2;   // Configure AIO10 for B2 (analog input) operation
	GpioCtrlRegs.AIOMUX1.bit.AIO12 = 2;   // Configure AIO12 for B4 (analog input) operation
	GpioCtrlRegs.AIOMUX1.bit.AIO14 = 2;   // Configure AIO14 for B6 (analog input) operation


	//solve first conversion problem:
	AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 1;
	AdcRegs.ADCCTL2.bit.CLKDIV2EN = 1;

	AdcRegs.ADCSOC0CTL.bit.CHSEL  = 0; // SOC0 TO A0
	AdcRegs.ADCSOC1CTL.bit.CHSEL  = 1; // SOC1 TO A1
	AdcRegs.ADCSOC2CTL.bit.CHSEL  = 2; // SOC2 TO A2
	AdcRegs.ADCSOC3CTL.bit.CHSEL  = 3; // SOC3 TO A3
	AdcRegs.ADCSOC4CTL.bit.CHSEL  = 4; // SOC4 TO A4
	AdcRegs.ADCSOC5CTL.bit.CHSEL  = 5; // SOC5 TO A5
	AdcRegs.ADCSOC6CTL.bit.CHSEL  = 6; // SOC6 TO A6
	AdcRegs.ADCSOC7CTL.bit.CHSEL  = 7; // SOC7 TO A7

	AdcRegs.ADCSOC8CTL.bit.CHSEL  = 8; // SOC8 TO B0
	AdcRegs.ADCSOC9CTL.bit.CHSEL  = 9; // SOC9 TO B1
	AdcRegs.ADCSOC10CTL.bit.CHSEL  = 10; // SOC10 TO B2
	AdcRegs.ADCSOC11CTL.bit.CHSEL  = 11; // SOC11 TO B3
	AdcRegs.ADCSOC12CTL.bit.CHSEL  = 12; // SOC12 TO B4
	AdcRegs.ADCSOC13CTL.bit.CHSEL  = 13; // SOC13 TO B5
	AdcRegs.ADCSOC14CTL.bit.CHSEL  = 14; // SOC14 TO B6
	AdcRegs.ADCSOC15CTL.bit.CHSEL  = 15; // SOC15 TO B7

	AdcRegs.ADCSOC0CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC0 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC1CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC1 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC2CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC2 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC3CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC3 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC4CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC4 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC5CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC5 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC6CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC6 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC7CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC7 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC8CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC8 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC9CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC9 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC10CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC10 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC11CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC11 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC12CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC12 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC13CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC13 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC14CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC14 acquisition period to DEFINED PERIOD
	AdcRegs.ADCSOC15CTL.bit.ACQPS  = ACQPS_VALUE; //Set SOC15 acquisition period to DEFINED PERIOD

	AdcRegs.INTSEL1N2.bit.INT1SEL = 15; //Connect ADCINT1 to SOC15 (last conversion)
	AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1; //ADCINT1 trips after AdcResults latch
	AdcRegs.INTSEL1N2.bit.INT1E  =  1; //Enable ADCINT1
	AdcRegs.INTSEL1N2.bit.INT1CONT = 0; //Disable ADCINT1 Continuous mode

	AdcRegs.ADCSOC0CTL.bit.TRIGSEL 	= 7;	//set SOC0  start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC1CTL.bit.TRIGSEL 	= 7;	//set SOC1  start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC2CTL.bit.TRIGSEL 	= 7;	//set SOC2  start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC3CTL.bit.TRIGSEL 	= 7;	//set SOC3  start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC4CTL.bit.TRIGSEL 	= 7;	//set SOC4  start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC5CTL.bit.TRIGSEL 	= 7;	//set SOC5  start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC6CTL.bit.TRIGSEL 	= 7;	//set SOC6  start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC7CTL.bit.TRIGSEL 	= 7;	//set SOC7  start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC8CTL.bit.TRIGSEL 	= 7;	//set SOC8  start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC9CTL.bit.TRIGSEL 	= 7;	//set SOC9  start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC10CTL.bit.TRIGSEL = 7;	//set SOC10 start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC11CTL.bit.TRIGSEL = 7;	//set SOC11 start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC12CTL.bit.TRIGSEL = 7;	//set SOC12 start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC13CTL.bit.TRIGSEL = 7;	//set SOC13 start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC14CTL.bit.TRIGSEL = 7;	//set SOC14 start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...
	AdcRegs.ADCSOC15CTL.bit.TRIGSEL = 7;	//set SOC15 start trigger on EPWM2A, due to round-robin SOC0 converts first then SOC1, then SOC2, etc...

	AdcRegs.ADCCTL1.bit.ADCREFSEL = 0;      //Select internal reference mode
	AdcRegs.ADCCTL1.bit.VREFLOCONV = 1;     //Select VREFLO internal connection on B5
    AdcRegs.ADCOFFTRIM.bit.OFFTRIM = 80;    //Apply artificial offset (+80) to account for a negative offset that may reside in the ADC core

	// Assumes ePWM2 clock is already enabled in InitSysCtrl();
	EPwm2Regs.ETSEL.bit.SOCAEN	= 1;		// Enable SOC on A group
	EPwm2Regs.ETSEL.bit.SOCASEL	= 4;		// Select SOC from CPMA on upcount
	EPwm2Regs.ETPS.bit.SOCAPRD 	= 1;		// Generate pulse on 1st event
	EPwm2Regs.CMPA.half.CMPA 	= 0x0BB7;	// Set compare A value
	EPwm2Regs.TBPRD 			= 0x0BB7;	// Set period for ePWM2
	EPwm2Regs.TBCTL.bit.CTRMODE	= 0;		// count up and start
	//EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;

	PieCtrlRegs.PIEIER1.bit.INTx1 = 1;
	IER |= M_INT1;
	EDIS;
}
/*
void readADC()
{
	AdcRegs.ADCSOCFRC1.all = 0xFFFF; 	//all socs

    while(AdcRegs.ADCINTFLG.bit.ADCINT1 == 0){}  //Wait for ADCINT1
    updateDSPfilter(A0filter, AdcResult.ADCRESULT0);
    updateDSPfilter(A1filter, AdcResult.ADCRESULT1);
    updateDSPfilter(A2filter, AdcResult.ADCRESULT2);
    updateDSPfilter(A3filter, AdcResult.ADCRESULT3);
    updateDSPfilter(A4filter, AdcResult.ADCRESULT4);
    updateDSPfilter(A5filter, AdcResult.ADCRESULT5);
    updateDSPfilter(B0filter, AdcResult.ADCRESULT6);
    updateDSPfilter(B1filter, AdcResult.ADCRESULT7);
    updateDSPfilter(B2filter, AdcResult.ADCRESULT8);
    updateDSPfilter(B3filter, AdcResult.ADCRESULT9);
    updateDSPfilter(B4filter, AdcResult.ADCRESULT10);
    updateDSPfilter(B5filter, AdcResult.ADCRESULT11);
    updateDSPfilter(B6filter, AdcResult.ADCRESULT12);
    updateDSPfilter(B7filter, AdcResult.ADCRESULT13);
    AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;
}
*/


void initDSPfilter(DSPfilter *filter, float CANFrequency, float samplingFrequency)
{
	filter->alpha = 1.0 - exp(-2.0 * PI * (CANFrequency / samplingFrequency));
	filter->outputValue = 0;
	filter->isOn = 0;
}

void updateDSPfilter(DSPfilter *filter, unsigned newValue)
{
	if (!filter->isOn) {
		filter->outputValue = newValue;
	} else {
		filter->outputValue = filter->alpha * (float)newValue + (1.0 - filter->alpha) * (float)filter->outputValue;
	}
}

// INT1.1
__interrupt void ADCINT1_ISR(void)   // ADC  (Can also be ISR for INT10.1 when enabled)
{
	// Insert ISR Code here
	EALLOW;
	AdcRegs.ADCOFFTRIM.bit.OFFTRIM = AdcRegs.ADCOFFTRIM.bit.OFFTRIM - AdcResult.ADCRESULT13;  //Set offtrim register with new value (i.e remove artical offset (+80) and create a two's compliment of the offset error)
	EDIS;
	// To receive more interrupts from this PIE group, acknowledge this interrupt
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
	AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;


	// Update DSP filters
    updateDSPfilter(&A0filter, AdcResult.ADCRESULT0);
    //updateDSPfilter(A0filter, datatest[A0filter.index]);
    updateDSPfilter(&A1filter, AdcResult.ADCRESULT1);
    updateDSPfilter(&A2filter, AdcResult.ADCRESULT2);
    updateDSPfilter(&A3filter, AdcResult.ADCRESULT3);
    updateDSPfilter(&A4filter, AdcResult.ADCRESULT4);
    updateDSPfilter(&A5filter, AdcResult.ADCRESULT5);
    updateDSPfilter(&B0filter, AdcResult.ADCRESULT6);
    updateDSPfilter(&B1filter, AdcResult.ADCRESULT7);
    updateDSPfilter(&B2filter, AdcResult.ADCRESULT8);
    updateDSPfilter(&B3filter, AdcResult.ADCRESULT9);
    updateDSPfilter(&B4filter, AdcResult.ADCRESULT10);
    updateDSPfilter(&B5filter, AdcResult.ADCRESULT11);
    updateDSPfilter(&B6filter, AdcResult.ADCRESULT12);
    updateDSPfilter(&B7filter, AdcResult.ADCRESULT13);
}
