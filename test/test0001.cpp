/*
    Project libStringUtils
    Copyright (C) 2015  tania@df9ry.de

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../StringUtil.h"

#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;
using namespace StringUtil;

int main(int argc, const char* argv[]) {
	{
		string result = toUpper("Quick brown Fox, 12345");
		assert(result == "QUICK BROWN FOX, 12345");
	}

	{
		string result = toLower("Quick brown fox, 12345");
		assert(result == "quick brown fox, 12345");
	}

	{
		string result = lTrim(" \t\r\nQuick brown fox, 12345 \t\r\n");
		assert(result == "Quick brown fox, 12345 \t\r\n");
	}

	{
		string result = rTrim(" \t\r\nQuick brown fox, 12345 \t\r\n");
		assert(result == " \t\r\nQuick brown fox, 12345");
	}

	{
		string result = trim(" \t\r\nQuick brown fox, 12345 \t\r\n");
		assert(result == "Quick brown fox, 12345");
	}

	{
		string result = remove("Quick brown fox, 12345", 'o');
		assert(result == "Quick brwn fx, 12345");
	}

	{
		bool result = contains("Quick brown fox, 12345", 'o');
		assert(result);
	}

	{
		bool result = contains("Quick brown fox, 12345", 'y');
		assert(!result);
	}

	{
		bool result = endsWith("Quick brown fox, 12345", "12345");
		assert(result);
	}

	{
		bool result = endsWith("Quick brown fox, 12345", "Quick");
		assert(!result);
	}

	{
		bool result = beginsWith("Quick brown fox, 12345", "12345");
		assert(!result);
	}

	{
		bool result = beginsWith("Quick brown fox, 12345", "Quick");
		assert(result);
	}

	{
		vector<string> result = split("Quick brown fox, 12345", " ,");
		assert(result.size() == 4);
		assert(result[0] == "Quick");
		assert(result[1] == "brown");
		assert(result[2] == "fox");
		assert(result[3] == "12345");
	}

	{
		vector<string> result = split("Quick brown fox, 12345", " ,", true);
		assert(result.size() == 5);
		assert(result[0] == "Quick");
		assert(result[1] == "brown");
		assert(result[2] == "fox");
		assert(result[3] == "");
		assert(result[4] == "12345");
	}

	cout << "Test OK" << endl;

	return EXIT_SUCCESS;
}



