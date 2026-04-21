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
		power--;
	    }
	}
    }
    printf("%d\n", value);
    return value;
}

void dec2BaseX(int base, int decimal, char *buffer)
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
	baseXStr[(strlen(baseXStrRev) - 1) - i] = baseXStrRev[i];
    }

    strcpy(buffer, baseXStr);
}

void bin2BaseX(const char *binStr, int baseX, char *buffer)
{
    int size = strlen(binStr);
    int groups;
    int strCount;
    char outStr[16] = {0};
    int IDX_OUT;
    int IDX;
    char tmpBuf[5] = {0};
    int bitCount;
    int value;
    if (baseX == 8)
    {
	bitCount = 3;
	groups = size / bitCount;
	if (size % bitCount == 0)
	{
	    IDX_OUT = groups;
	    IDX = 0;
	    for (int i = 0; i < groups; i++)
	    {
		int j;
		for (j = 0; j < 3; j++)
		{
		    tmpBuf[j] = binStr[IDX+j];
		}
		IDX += j;
		int value = baseX2Dec(2, tmpBuf, strlen(tmpBuf));
		outStr[IDX_OUT - 1] = value + '0';
		IDX_OUT--;
		memset(tmpBuf, 0, sizeof(tmpBuf));
	    }
	}
	else
	{
	    IDX = size % bitCount;
	    IDX_OUT = 1;
	    for (int i = 0; i <= groups; i++)
	    {
		if (i == groups)
		{
		    for (int k = 0; k <= size % bitCount - 1; k++)
		    {
			tmpBuf[k] = binStr[k];
		    } 
		    value = baseX2Dec(2, tmpBuf, strlen(tmpBuf));
		    outStr[0] = value + '0';
		}
		else
		{
		    int j;
		    for (j = 0; j < bitCount; j++)
		    {
			tmpBuf[j] = binStr[IDX+j];
		    }
		    IDX += j;
		    value = baseX2Dec(2, tmpBuf, strlen(tmpBuf));
		    outStr[IDX_OUT] = value + '0';
		    IDX_OUT++;
		}
		memset(tmpBuf, 0, sizeof(tmpBuf));
	    }
	}
    }
    else if (baseX == 16)
    {
	bitCount = 4;
	groups = size / bitCount;
	if (size % bitCount == 0)
	{
	    IDX_OUT = groups;
	    IDX = 0;
	    for (int i = 0; i < groups; i++)
	    {
		int j;
		for (j = 0; j < bitCount; j++)
		{
		    tmpBuf[j] = binStr[IDX+j];
		}
		IDX += j;
		int value = baseX2Dec(2, tmpBuf, strlen(tmpBuf));
		if (value >= 10)
		{
		    outStr[IDX_OUT - 1] = 'A' + (value % 10);
		}
		else
		{
		    outStr[IDX_OUT - 1] = value + '0';
		}
		IDX_OUT--;
		memset(tmpBuf, 0, sizeof(tmpBuf));
	    }
	}
	else
	{
	    IDX = size % bitCount;
	    IDX_OUT = 1;
	    printf("%s\n", binStr);
	    for (int i = 0; i <= groups; i++)
	    {
		if (i == groups)
		{
		    for (int k = 0; k <= size % bitCount - 1; k++)
		    {
			tmpBuf[k] = binStr[k];
		    }
		    value = baseX2Dec(2, tmpBuf, strlen(tmpBuf));
		    if (value >= 10)
		    {
			outStr[0] = 'A' + value % 10;
		    }
		    else
		    {
			outStr[0] = value + '0';
		    }
		}
		else
		{
		    int j;
		    for (j = 0; j < bitCount; j++)
		    {
			tmpBuf[j] = binStr[IDX+j];
		    }
		    IDX += j;
		    value = baseX2Dec(2, tmpBuf, strlen(tmpBuf));
		    if (value >= 10)
		    {
			outStr[IDX_OUT] = 'A' + value % 10;
		    }
		    else
		    {
			outStr[IDX_OUT] = value + '0';
		    }
		    IDX_OUT++;
		}
		memset(tmpBuf, 0, sizeof(tmpBuf));
	    }
	}
    }
    else
    {
	printf("ERR: Unsupported Base.\n");
	return;
    }
    strcpy(buffer, outStr);
    memset(outStr, 0, sizeof(outStr));
}

void baseX2Bin(int base, const char *baseStr, char *buffer)
{
    int decimal = baseX2Dec(base, baseStr, strlen(baseStr));
    dec2BaseX(2, decimal, buffer);
}

void baseX2BaseY(int baseX, int baseY, const char *baseXStr, char *buffer)
{
    int decimal = baseX2Dec(baseX, baseXStr, strlen(baseXStr));
    dec2BaseX(baseY, decimal, buffer);
}
