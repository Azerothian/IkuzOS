
#include <types.h>
#include <ikzlib/string.h>

uint8_t floppyDoneWait = FALSE;

floppyGeometry_t floppyGeometry[6] =
{
	{  0, 0,  0,   0 }, // no drive
	{  9, 2, 40, 512 }, // 360kb 5.25"
	{ 15, 2, 80, 512 }, // 1.2mb 5.25"
	{  9, 2, 80, 512 }, // 720kb 3.5"
	{ 18, 2, 80, 512 }, // 1.44mb 3.5"
	{ 36, 2, 80, 512 }  // 2.88mb 3.5"
};

char *floppyTypeToString[] =
{
	"None",
	"360kb 5.25\"",
	"1.2mb 5.26\"",
	"720kb 3.5\"",
	"1.44mb 3.5\"",
	"2.88mb 3.5\""
};
