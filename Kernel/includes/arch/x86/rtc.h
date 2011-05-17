/*
 * rtc.h
 *
 *  Created on: 16/05/2011
 *      Author: admin
 */

#ifndef RTC_H_
#define RTC_H_

#include <types.h>

#define RTC_SECOND   0x00
#define RTC_MINUTE   0x02
#define RTC_HOUR     0x04
#define RTC_DAY      0x07
#define RTC_MONTH    0x08
#define RTC_YEAR     0x09

typedef struct _rtcTime_t {
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	uint8_t day;
	uint8_t mon;
	uint8_t year;
} rtcTime_t;

int rtcGetDateTime(rtcTime_t *rtc);
time_t makeTime(uint32_t year, uint32_t mon, uint32_t day,
         uint32_t hour, uint32_t min, uint32_t sec);
time_t rtcGetTime(void);
void setStartupTime(time_t time);
time_t getStartupTime(void);

#endif /* RTC_H_ */
