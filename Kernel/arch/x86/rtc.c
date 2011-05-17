#include <types.h>
#include <arch/x86/rtc.h>
#include "cpu.h"

#define OM_RTC_BASE 0x70
#define OM_RTC_DATA 0x71

/* when we booted! */
static time_t startupTime = 0;

void rtcSendByte(int byte)
{
	outportb(OM_RTC_BASE, byte);
}

uint8_t rtcGetByte(void)
{
	return inportb(OM_RTC_DATA);
}

uint32_t rtcGetDecFromBcd(uint8_t in)
{
	uint32_t out;
	out = ((in >> 4) & 0x0f) * 10;
	out += (in & 0x0f);
	return out;
}

#define MINUTE 60
#define HOUR ( 60 * MINUTE )
#define DAY  ( 24 * HOUR )
#define YEAR ( 365 * DAY )

static int32_t anMonth [ 12 ] = {
    0,
    DAY * ( 31 ),
    DAY * ( 31 + 29 ),
    DAY * ( 31 + 29 + 31 ),
    DAY * ( 31 + 29 + 31 + 30 ),
    DAY * ( 31 + 29 + 31 + 30 + 31 ),
    DAY * ( 31 + 29 + 31 + 30 + 31 + 30 ),
    DAY * ( 31 + 29 + 31 + 30 + 31 + 30 + 31),
    DAY * ( 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31),
    DAY * ( 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30),
    DAY * ( 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 ),
    DAY * ( 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 )
};


time_t makeTime(uint32_t year, uint32_t mon, uint32_t day,
                uint32_t hour, uint32_t min, uint32_t sec)
{
	time_t nRes;
	int nYearInt;
	if(year < 70) year += 100;
	nYearInt = year - 70;

	nRes = YEAR * nYearInt + DAY * ((nYearInt + 1) / 4);
	nRes += anMonth[mon - 1];
	if(mon - 1 > 1 && ((nYearInt + 2) % 4)) {
		nRes -= DAY;
	}

	nRes += DAY * (day - 1);
	nRes += HOUR * hour;
	nRes += MINUTE * min;
	nRes += sec;
	return nRes;
}


int rtcGetDateTime(rtcTime_t *rtc)
{
	if(!rtc)
		return -1;

	memset(rtc, 0, sizeof(rtcTime_t));

	rtcSendByte(RTC_SECOND);
	rtc->sec = rtcGetDecFromBcd(rtcGetByte());

	rtcSendByte(RTC_MINUTE);
	rtc->min = rtcGetDecFromBcd(rtcGetByte());

	rtcSendByte(RTC_HOUR);
	rtc->hour = rtcGetDecFromBcd(rtcGetByte());

	rtcSendByte(RTC_DAY);
	rtc->day = rtcGetDecFromBcd(rtcGetByte());

	rtcSendByte(RTC_MONTH);
	rtc->mon = rtcGetDecFromBcd(rtcGetByte());

	rtcSendByte(RTC_YEAR);
	rtc->year = rtcGetDecFromBcd(rtcGetByte());

	return 0;
}

time_t rtcGetTime(void)
{
	rtcTime_t rtc;

	rtcGetDateTime(&rtc);

	return makeTime(rtc.year, rtc.mon, rtc.day, rtc.hour, rtc.min, rtc.sec);
}

void setStartupTime(time_t time) {
	startupTime = time;
}

time_t getStartupTime(void) {
	return startupTime;
}
