// Copyright (c) 2026 BYK. All Rights Reserved.
//
// This file is part of BaseCalc.
//
// BaseCalc is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, under version 2 of the License.
//
// BaseCalc is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with BaseCalc. If not, see <https://www.gnu.org/licenses/>.
//
// Maintainer: BYK <bykdev@proton.me>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <gtk/gtk.h>

int baseX2Dec (int base, const char *binStr, size_t strSize)
{
    // printf("%d\n", base);
    char upBinStr[strSize];
    int value = 0;
    int power = strSize - 1;
    for (int i = 0; i < strSize; i++)
    {
	int numValue = binStr[i] - '0';
	upBinStr[i] = toupper(binStr[i]);
	int hexValue = (upBinStr[i] - '0') - 7;
	// printf("%d\n", hexValue);
	// printf("%d\n", base);
	if (numValue < 10)
	{
	    if (numValue >= base)
	    {
		printf("Illegal value.\n");
		return -1;
	    }
	    else
	    {
		int multiplier = numValue;
		value += pow(base, power) * multiplier;
		// printf("%d\n", value);
		power--;
	    }
	}
	else
	{
	    if (hexValue >= base)
	    {
		printf("Illegal value.\n");
		return -1;
	    }
	    else
	    {
		int multiplier = (upBinStr[i] - '0') - 7;
		int tmpValue = pow(base, power) * multiplier;
		value += tmpValue;
		// printf("%d %d\n", tmpValue, value);
		power--;
	    }
	}
	// printf("%c\n", binStr[i]);
    }
    printf("%d\n", value);
    return value;
    // printf("%d\n%s\n", strSize, binStr);
}

void dec2BaseX(int base, int decimal, GtkButton *button)
{
    int IDX = 0;
    char baseXStrRev[32] = {0};
    char baseXStr[32] = {0};
    int divide = decimal / base;
    while (divide != 0)
    {
	if (decimal % base != 0)
	{
	    if (decimal % base < 10)
	    {
		snprintf(&baseXStrRev[IDX], sizeof(&baseXStrRev[IDX]), "%d", decimal % base);
		IDX++;
	    }
	    else
	    {
		baseXStrRev[IDX] = '7' + (decimal % base);
		IDX++;
	    }
	}
	else
	{
	    baseXStrRev[IDX] = '0';
	    IDX++;
	}
	decimal /= base;
	divide = decimal / base;
    }
    
    if (decimal % base != 0)
    {
	if (decimal % base < 10)
	{
	    snprintf(&baseXStrRev[IDX], sizeof(&baseXStrRev[IDX]), "%d", decimal % base);
	    IDX++;
	}
	else
	{
	    baseXStrRev[IDX] = '7' + (decimal % base);
	    IDX++;
	}
    }
    else
    {
	baseXStrRev[IDX] = '0';
	IDX++;
    }
    decimal /= base;
    divide = decimal / base;

    for (int i = (strlen(baseXStrRev) + 1); i >= 0; i--)
    {
	// printf("%c", baseXStrRev[i]);
	baseXStr[(strlen(baseXStrRev) - 1) - i] = baseXStrRev[i];
	// printf("%d\n", (strlen(baseXStrRev)) -i);
	printf("i: %d\n", i);
	printf("bin: %c\n", baseXStrRev[i]);

    }

    printf("DBG: %s\n", baseXStr);
    printf("\n");

    gtk_button_set_label(GTK_BUTTON (button), baseXStr);

    // printf("%s\n", baseXStr);
}
