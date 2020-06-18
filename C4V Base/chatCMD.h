#pragma once


namespace cmd
{
	static string get_word_at(std::vector<string> list, int atIndex) {
		if (list.size() > atIndex) return list.at(atIndex);
		return "null";
	}

	static bool does_word_at_exist(std::vector<string> list, int atIndex) {
		if (list.size() > atIndex) return true;
		return false;
	}

	static bool is_word_int(std::string word) {
		return word.find_first_not_of("0123456789") == string::npos;
	}

	static int get_int_from_word(std::string word) {
		return std::stoi(word);
	}

	static bool is_in_vector(std::vector<string> list, std::string word) {
		for (int x = 0; x < list.size(); x++) {
			if (list.at(x) == word) return true;
		}
		return false;
	}
}

bool chat_cmd_func(__int64 a2, __int64 a3, const char* origText, BOOL isTeam);