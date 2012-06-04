#include "system_encoding.h"

#if defined(_MSC_VER) || defined(__MINGW32__) || defined(_WIN32)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

char* get_system_encoding() 
{
	switch(GetACP())
	{	
	case 37:	return "ibm037" ; // IBM EBCDIC US-Canada
	case 437:	return "ibm437" ; // OEM United States
	case 500:	return "ibm500" ; // IBM EBCDIC International
	case 708:	return "ASMO_708" ; // Arabic (ASMO 708)
//	case 709:	return "" ; // Arabic (ASMO-449+, BCON V4)
//	case 710:	return "" ; // Arabic - Transparent Arabic
	case 720:	return "dos_720" ; // Arabic (Transparent ASMO); Arabic (DOS)
	case 737:	return "ibm737" ; // OEM Greek (formerly 437G); Greek (DOS)
	case 775:	return "ibm775" ; // OEM Baltic; Baltic (DOS)
	case 850:	return "ibm850" ; // OEM Multilingual Latin 1; Western European (DOS)
	case 852:	return "ibm852" ; // OEM Latin 2; Central European (DOS)
	case 855:	return "ibm855" ; // OEM Cyrillic (primarily Russian)
	case 857:	return "ibm857" ; // OEM Turkish; Turkish (DOS)
	case 858:	return "ibm00858" ; // OEM Multilingual Latin 1 + Euro symbol
	case 860:	return "ibm860" ; // OEM Portuguese; Portuguese (DOS)
	case 861:	return "ibm861" ; // OEM Icelandic; Icelandic (DOS)
	case 862:	return "dos_862" ; // OEM Hebrew; Hebrew (DOS)
	case 863:	return "ibm863" ; // OEM French Canadian; French Canadian (DOS)
	case 864:	return "ibm864" ; // OEM Arabic; Arabic (864)
	case 865:	return "ibm865" ; // OEM Nordic; Nordic (DOS)
	case 866:	return "cp866" ; // OEM Russian; Cyrillic (DOS)
	case 869:	return "ibm869" ; // OEM Modern Greek; Greek, Modern (DOS)
	case 870:	return "ibm870" ; // IBM EBCDIC Multilingual/ROECE (Latin 2); IBM EBCDIC Multilingual Latin 2
	case 874:	return "windows_874" ; // ANSI/OEM Thai (same as 28605, ISO 8859-15); Thai (Windows)
	case 875:	return "cp875" ; // IBM EBCDIC Greek Modern
	case 932:	return "shift_jis" ; // ANSI/OEM Japanese; Japanese (Shift-JIS)
	case 936:	return "gb2312" ; // ANSI/OEM Simplified Chinese (PRC, Singapore); Chinese Simplified (GB2312)
	case 949:	return "ks_c_5601_1987" ; // ANSI/OEM Korean (Unified Hangul Code)
	case 950:	return "big5" ; // ANSI/OEM Traditional Chinese (Taiwan; Hong Kong SAR, PRC); Chinese Traditional (Big5)
	case 1026:	return "ibm1026" ; // IBM EBCDIC Turkish (Latin 5)
	case 1047:	return "ibm01047" ; // IBM EBCDIC Latin 1/Open System
	case 1140:	return "ibm01140" ; // IBM EBCDIC US-Canada (037 + Euro symbol); IBM EBCDIC (US-Canada-Euro)
	case 1141:	return "ibm01141" ; // IBM EBCDIC Germany (20273 + Euro symbol); IBM EBCDIC (Germany-Euro)
	case 1142:	return "ibm01142" ; // IBM EBCDIC Denmark-Norway (20277 + Euro symbol); IBM EBCDIC (Denmark-Norway-Euro)
	case 1143:	return "ibm01143" ; // IBM EBCDIC Finland-Sweden (20278 + Euro symbol); IBM EBCDIC (Finland-Sweden-Euro)
	case 1144:	return "ibm01144" ; // IBM EBCDIC Italy (20280 + Euro symbol); IBM EBCDIC (Italy-Euro)
	case 1145:	return "ibm01145" ; // IBM EBCDIC Latin America-Spain (20284 + Euro symbol); IBM EBCDIC (Spain-Euro)
	case 1146:	return "ibm01146" ; // IBM EBCDIC United Kingdom (20285 + Euro symbol); IBM EBCDIC (UK-Euro)
	case 1147:	return "ibm01147" ; // IBM EBCDIC France (20297 + Euro symbol); IBM EBCDIC (France-Euro)
	case 1148:	return "ibm01148" ; // IBM EBCDIC International (500 + Euro symbol); IBM EBCDIC (International-Euro)
	case 1149:	return "ibm01149" ; // IBM EBCDIC Icelandic (20871 + Euro symbol); IBM EBCDIC (Icelandic-Euro)
	case 1200:	return "utf_16" ; // Unicode UTF-16, little endian byte order (BMP of ISO 10646); available only to managed applications
	case 1201:	return "unicodeFFFE" ; // Unicode UTF-16, big endian byte order; available only to managed applications
	case 1250:	return "windows_1250" ; // ANSI Central European; Central European (Windows)
	case 1251:	return "windows_1251" ; // ANSI Cyrillic; Cyrillic (Windows)
	case 1252:	return "windows_1252" ; // ANSI Latin 1; Western European (Windows)
	case 1253:	return "windows_1253" ; // ANSI Greek; Greek (Windows)
	case 1254:	return "windows_1254" ; // ANSI Turkish; Turkish (Windows)
	case 1255:	return "windows_1255" ; // ANSI Hebrew; Hebrew (Windows)
	case 1256:	return "windows_1256" ; // ANSI Arabic; Arabic (Windows)
	case 1257:	return "windows_1257" ; // ANSI Baltic; Baltic (Windows)
	case 1258:	return "windows_1258" ; // ANSI/OEM Vietnamese; Vietnamese (Windows)
	case 1361:	return "johab" ; // Korean (Johab)
	case 10000:	return "macintosh" ; // MAC Roman; Western European (Mac)
	case 10001:	return "x_mac_japanese" ; // Japanese (Mac)
	case 10002:	return "x_mac_chinesetrad" ; // MAC Traditional Chinese (Big5); Chinese Traditional (Mac)
	case 10003:	return "x_mac_korean" ; // Korean (Mac)
	case 10004:	return "x_mac_arabic" ; // Arabic (Mac)
	case 10005:	return "x_mac_hebrew" ; // Hebrew (Mac)
	case 10006:	return "x_mac_greek" ; // Greek (Mac)
	case 10007:	return "x_mac_cyrillic" ; // Cyrillic (Mac)
	case 10008:	return "x_mac_chinesesimp" ; // MAC Simplified Chinese (GB 2312); Chinese Simplified (Mac)
	case 10010:	return "x_mac_romanian" ; // Romanian (Mac)
	case 10017:	return "x_mac_ukrainian" ; // Ukrainian (Mac)
	case 10021:	return "x_mac_thai" ; // Thai (Mac)
	case 10029:	return "x_mac_ce" ; // MAC Latin 2; Central European (Mac)
	case 10079:	return "x_mac_icelandic" ; // Icelandic (Mac)
	case 10081:	return "x_mac_turkish" ; // Turkish (Mac)
	case 10082:	return "x_mac_croatian" ; // Croatian (Mac)
	case 12000:	return "utf_32" ; // Unicode UTF-32, little endian byte order; available only to managed applications
	case 12001:	return "utf_32BE" ; // Unicode UTF-32, big endian byte order; available only to managed applications
	case 20000:	return "x_chinese_cns" ; // CNS Taiwan; Chinese Traditional (CNS)
	case 20001:	return "x_cp20001" ; // TCA Taiwan
	case 20002:	return "x_chinese_eten" ; // Eten Taiwan; Chinese Traditional (Eten)
	case 20003:	return "x_cp20003" ; // IBM5550 Taiwan
	case 20004:	return "x_cp20004" ; // TeleText Taiwan
	case 20005:	return "x_cp20005" ; // Wang Taiwan
	case 20105:	return "x_ia5" ; // IA5 (IRV International Alphabet No. 5, 7-bit); Western European (IA5)
	case 20106:	return "x_ia5_german" ; // IA5 German (7-bit)
	case 20107:	return "x_ia5_swedish" ; // IA5 Swedish (7-bit)
	case 20108:	return "x_ia5_norwegian" ; // IA5 Norwegian (7-bit)
	case 20127:	return "ascii" ; // US-ASCII (7-bit)
	case 20261:	return "x_cp20261" ; // T.61
	case 20269:	return "x_cp20269" ; // ISO 6937 Non-Spacing Accent
	case 20273:	return "ibm273" ; // IBM EBCDIC Germany
	case 20277:	return "ibm277" ; // IBM EBCDIC Denmark-Norway
	case 20278:	return "ibm278" ; // IBM EBCDIC Finland-Sweden
	case 20280:	return "ibm280" ; // IBM EBCDIC Italy
	case 20284:	return "ibm284" ; // IBM EBCDIC Latin America-Spain
	case 20285:	return "ibm285" ; // IBM EBCDIC United Kingdom
	case 20290:	return "ibm290" ; // IBM EBCDIC Japanese Katakana Extended
	case 20297:	return "ibm297" ; // IBM EBCDIC France
	case 20420:	return "ibm420" ; // IBM EBCDIC Arabic
	case 20423:	return "ibm423" ; // IBM EBCDIC Greek
	case 20424:	return "ibm424" ; // IBM EBCDIC Hebrew
	case 20833:	return "x_ebcdic_koreanextended" ; // IBM EBCDIC Korean Extended
	case 20838:	return "ibm_thai" ; // IBM EBCDIC Thai
	case 20866:	return "koi8_r" ; // Russian (KOI8-R); Cyrillic (KOI8-R)
	case 20871:	return "ibm871" ; // IBM EBCDIC Icelandic
	case 20880:	return "ibm880" ; // IBM EBCDIC Cyrillic Russian
	case 20905:	return "ibm905" ; // IBM EBCDIC Turkish
	case 20924:	return "ibm00924" ; // IBM EBCDIC Latin 1/Open System (1047 + Euro symbol)
	case 20932:	return "euc_jp" ; // Japanese (JIS 0208-1990 and 0121-1990)
	case 20936:	return "x_cp20936" ; // Simplified Chinese (GB2312); Chinese Simplified (GB2312-80)
	case 20949:	return "x_cp20949" ; // Korean Wansung
	case 21025:	return "cp1025" ; // IBM EBCDIC Cyrillic Serbian-Bulgarian
//	case 21027:	return "" ; // (deprecated)
	case 21866:	return "koi8_u" ; //	Ukrainian (KOI8-U); Cyrillic (KOI8-U)
	case 28591:	return "iso_8859_1" ; // ISO 8859-1 Latin 1; Western European (ISO)
	case 28592:	return "iso_8859_2" ; // ISO 8859-2 Central European; Central European (ISO)
	case 28593:	return "iso_8859_3" ; // ISO 8859-3 Latin 3
	case 28594:	return "iso_8859_4" ; // ISO 8859-4 Baltic
	case 28595:	return "iso_8859_5" ; // ISO 8859-5 Cyrillic
	case 28596:	return "iso_8859_6" ; // ISO 8859-6 Arabic
	case 28597:	return "iso_8859_7" ; // ISO 8859-7 Greek
	case 28598:	return "iso_8859_8" ; // ISO 8859-8 Hebrew; Hebrew (ISO-Visual)
	case 28599:	return "iso_8859_9" ; // ISO 8859-9 Turkish
	case 28603:	return "iso_8859_13" ; // ISO 8859-13 Estonian
	case 28605:	return "iso_8859_15" ; // ISO 8859-15 Latin 9
	case 29001:	return "x_europa" ; // Europa 3
	case 38598:	return "iso_8859_8_i" ; // ISO 8859-8 Hebrew; Hebrew (ISO-Logical)
	case 50220:	return "iso_2022_jp" ; // ISO 2022 Japanese with no halfwidth Katakana; Japanese (JIS)
	case 50221:	return "csiso2022jp" ; // ISO 2022 Japanese with halfwidth Katakana; Japanese (JIS-Allow 1 byte Kana)
	case 50222:	return "iso_2022_jp" ; // ISO 2022 Japanese JIS X 0201-1989; Japanese (JIS-Allow 1 byte Kana - SO/SI)
	case 50225:	return "iso_2022_kr" ; // ISO 2022 Korean
	case 50227:	return "x_cp50227" ; // ISO 2022 Simplified Chinese; Chinese Simplified (ISO 2022)
//	case 50229:	return "" ; // ISO 2022 Traditional Chinese
//	case 50930:	return "" ; // EBCDIC Japanese (Katakana) Extended
//	case 50931:	return "" ; // EBCDIC US-Canada and Japanese
//	case 50933:	return "" ; // EBCDIC Korean Extended and Korean
//	case 50935:	return "" ; // EBCDIC Simplified Chinese Extended and Simplified Chinese
//	case 50936:	return "" ; // EBCDIC Simplified Chinese
//	case 50937:	return "" ; // EBCDIC US-Canada and Traditional Chinese
//	case 50939:	return "" ; // EBCDIC Japanese (Latin) Extended and Japanese
	case 51932:	return "euc_jp" ; // EUC Japanese
	case 51936:	return "euc_cn" ; // EUC Simplified Chinese; Chinese Simplified (EUC)
	case 51949:	return "euc_kr" ; // EUC Korean
//	case 51950:	return "" ; // EUC Traditional Chinese
	case 52936:	return "hz_gb_2312" ; // HZ-GB2312 Simplified Chinese; Chinese Simplified (HZ)
	case 54936:	return "gb18030" ; // Windows XP and later: GB18030 Simplified Chinese (4 byte); Chinese Simplified (GB18030)
	case 57002:	return "x_iscii_de" ; // ISCII Devanagari
	case 57003:	return "x_iscii_be" ; // ISCII Bengali
	case 57004:	return "x_iscii_ta" ; // ISCII Tamil
	case 57005:	return "x_iscii_te" ; // ISCII Telugu
	case 57006:	return "x_iscii_as" ; // ISCII Assamese
	case 57007:	return "x_iscii_or" ; // ISCII Oriya
	case 57008:	return "x_iscii_ka" ; // ISCII Kannada
	case 57009:	return "x_iscii_ma" ; // ISCII Malayalam
	case 57010:	return "x_iscii_gu" ; // ISCII Gujarati
	case 57011:	return "x_iscii_pa" ; // ISCII Punjabi
	case 65000:	return "utf_7" ; // Unicode (UTF-7)
	case 65001:	return "utf_8" ; // Unicode (UTF-8)
	}
	return "ascii" ;			// unknown encoding: resort to ascii
}


#else

#include <langinfo.h>
#include <locale.h>

char* get_system_encoding() {
  setlocale(LC_ALL,"");
  return nl_langinfo(CODESET);
}

#endif
