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

/** @file */

#ifndef STRINGUTIL_H_
#define STRINGUTIL_H_

#include <string>
#include <vector>

#ifdef LIBSTRINGUTIL_EXPORTS
# ifdef _WIN32
#  define LIBSTRINGUTIL_EXPORT __declspec(dllexport)
# else
#  define LIBSTRINGUTIL_EXPORT __attribute__ ((dllexport))
# endif
#else
# define LIBSTRINGUTIL_EXPORT
#endif

/**
 * All functions in StringUtil are in this namespace.
 */
namespace StringUtil {

/**
 * Normal definition of whitespace chars.
 */
LIBSTRINGUTIL_EXPORT extern const std::string WHITESPACE{ " \t\n\r\f\v" };

/**
 * Convert string to all upper case.
 * @param s The string to convert.
 * @return Converted string.
 */
LIBSTRINGUTIL_EXPORT const std::string toUpper(const std::string& s);

/**
 * Convert string to all lower case.
 * @param s The string to convert.
 * @return Converted string.
 */
LIBSTRINGUTIL_EXPORT const std::string toLower(const std::string& s);

/**
 * Trim all whitespace from the begin.
 * @param s The string to trim.
 * @param whitespace Characters considered as whitespace.
 * @return Trimmed string.
 */
LIBSTRINGUTIL_EXPORT const std::string lTrim(
		const std::string& s,
		const std::string& whitespace = WHITESPACE);

/**
 * Trim all whitespace from the end.
 * @param s The string to trim.
 * @param whitespace Characters considered as whitespace.
 * @return Trimmed string.
 */
LIBSTRINGUTIL_EXPORT const std::string rTrim(
		const std::string& s,
		const std::string& whitespace = WHITESPACE);

/**
 * Trim all whitespace from the begin and the end.
 * @param s The string to trim.
 * @param whitespace Characters considered as whitespace.
 * @return Trimmed string.
 */
LIBSTRINGUTIL_EXPORT const std::string trim(
		const std::string& s,
		const std::string& whitespace = WHITESPACE);

/**
 * Remove all occurrences of a character from a string.
 * @param s The input string.
 * @param c The character to remove.
 * @return String with all character c removed.
 */
LIBSTRINGUTIL_EXPORT const std::string remove(const std::string& s, char c);

/**
 * Test if a string contains a specific char.
 * @param s The string to check.
 * @param c The character to look for.
 * @return If s contains c.
 */
LIBSTRINGUTIL_EXPORT bool contains(const std::string& s, char c);

/**
 * Test if a string ends with a specific suffix.
 * @param s The string to check.
 * @param suffix The suffix to look for.
 * @return True, when a ends with b, false otherwise.
 */
LIBSTRINGUTIL_EXPORT bool endsWith(const std::string& s, const std::string& suffix);

/**
 * Test if a string begins with a specific prefix.
 * @param s The string to check.
 * @param prefix The suffix to look for.
 * @return True, when a ends with b, false otherwise.
 */
LIBSTRINGUTIL_EXPORT bool beginsWith(const std::string& s, const std::string& prefix);

/**
 * Split string into a vector of tokens.
 * @param s The string to split.
 * @param separators The separator characters.
 * @param includeEmpty Shall empty tokens be included into the.
 *        result
 * @return Vector of tokens
 */
LIBSTRINGUTIL_EXPORT std::vector<std::string> split(
		const std::string& s,
		const std::string& separators,
		bool includeEmpty = false);

} /* namespace StringUtil */

#endif /* STRINGUTIL_H_ */
