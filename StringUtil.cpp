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

#include "StringUtil.h"

#include <algorithm>
#include <functional>

using namespace std;

namespace StringUtil {

	const string toUpper(const string& s)
	{
		string _s{s};
		transform(_s.begin(), _s.end(), _s.begin(), ::toupper);
		return _s;
	}

	const string toLower(const string& s)
	{
		string _s{s};
		transform(_s.begin(), _s.end(), _s.begin(), ::tolower);
		return _s;
	}

	const string lTrim(
			const string& s,
			const string& whitespace)
	{
		string _s{s};
		_s.erase(0, _s.find_first_not_of(whitespace));
		return _s;

	}

	const string rTrim(
			const string& s,
			const string& whitespace)
	{
		string _s{s};
		_s.erase(_s.find_last_not_of(whitespace) + 1);
		return _s;
	}

	const string trim(
			const string& s,
			const string& whitespace)
	{
		string _s{s};
		_s.erase(0, _s.find_first_not_of(whitespace));
		_s.erase(_s.find_last_not_of(whitespace) + 1);
		return _s;
	}

	const string remove(const string& s, char c)
	{
		string _s{s};
		auto new_end = remove_if(_s.begin(), _s.end(), bind1st(equal_to<char>(), c));
		_s.resize(_s.length() - (_s.end() - new_end));
		return _s;
	}

	bool contains(const std::string& s, char c)
	{
		for (auto i = s.begin(); i != s.end(); ++i)
			if (*i == c)
				return true;
		return false;
	}

	bool endsWith(const string& s, const string& suffix)
	{
		if (suffix.size() > s.size()) return false;
		return equal(s.begin() + s.size() - suffix.size(), s.end(), suffix.begin());
	}

	bool beginsWith(const string& s, const string& prefix)
	{
		if (prefix.size() > s.size()) return false;
		return equal(s.begin(), s.begin() + prefix.length(), prefix.begin());
	}

	vector<string> split(
			const string& s, const string& separators, bool includeEmpty)
	{
		vector<string> result;
		string _s{trim(s)};
		size_t pos;
		while ((pos = _s.find_first_of(separators)) < _s.length()) {
			string t = trim(_s.substr(0, pos));
			_s.erase(0, pos + 1);
			if (includeEmpty || (!t.empty()))
				result.push_back(move(t));
		} // end while //
		if (includeEmpty || (!_s.empty()))
			result.push_back(move(_s));
		return result;
	}

} /* namespace StringUtil */
