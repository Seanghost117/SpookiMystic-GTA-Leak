#include "stdafx.h"

bool chat_cmd_func(__int64 a2, __int64 a3, const char* origText, BOOL isTeam) {

	string text(origText);
	
	if (chatCMDTeam && isTeam || chatCMDAll && !isTeam) {
		/*for (int x = 0; x < 32; x++) {	//test char
			Log::Msg("ok2222");
			if (c2w2c(get_player_name(x)) == origText) {
				Log::Msg("success");
			}
		}*/

		if (!text.find("!")) {	//cmd prefix
			__int8 plrID = *(std::int8_t*)(Hooking::get_chat_player(a3, a2, a3) + 0x2D);
			vector<string> words;
			string t = "";
			for (int x = 1; x < text.length(); x++) {
				if (text.at(x) == ' ') {
					words.push_back(t);
					t.erase();
				}
				else {
					t += text.at(x);
					if (x == text.length() - 1) words.push_back(t);

				}
			}
			if (plrID >= 0 && plrID < 32) {	// [start cmd options]	

				// [info: first word (at index [0]) not contain the prefix / use always cmd::get_word_at() to get the word at index x]
				if (chatCMDWeapons && cmd::get_word_at(words, 0) == "weapon") {	//give weapon
					if (cmd::is_in_vector(chatCMD2weap, cmd::get_word_at(words, 1))) {
						for (int a = 0; a < chatCMD2weap.size(); a++) {
							if (cmd::get_word_at(words, 1) == chatCMD2weap.at(a))
								Hooking::give_delayed_weapon_to_ped(get_player_ped(plrID), $(chatCMD2weapHash.at(a)), 9999, true);
						}
					}
					else if (cmd::get_word_at(words, 1) == "all")
						GiveAllWeapons(plrID);
				}
				else if (chatCMDGiveMoney && cmd::get_word_at(words, 0) == "money") {	//give money

					if (cmd::get_word_at(words, 1) == "stop")
						chatCMDPlrMoney[plrID] = 0;
					else if (cmd::get_word_at(words, 1) == "rain")
						chatCMDPlrMoney[plrID] = 1;
					else if (cmd::get_word_at(words, 1) == "circle")
						chatCMDPlrMoney[plrID] = 2;
					else if (cmd::get_word_at(words, 1) == "delay") {
						if (cmd::is_word_int(cmd::get_word_at(words, 2))) {
							int delay = cmd::get_int_from_word(cmd::get_word_at(words, 2));
							if (delay >= 0 && delay < INT_MAX * 2)
								chatCMDPlrMoneyDelay[plrID] = delay;
						}
					}
					else if (cmd::get_word_at(words, 1) == "value") {
						if (cmd::is_word_int(cmd::get_word_at(words, 2))) {
							int value = cmd::get_int_from_word(cmd::get_word_at(words, 2));
							if (value >= 0 && value <= 2500)
								chatCMDPlrMoneyValue[plrID] = value;
						}
					}
					else if (cmd::get_word_at(words, 1) == "radius") {
						if (cmd::is_word_int(cmd::get_word_at(words, 2))) {
							int radius = cmd::get_int_from_word(cmd::get_word_at(words, 2));
							if (radius >= 0 && radius <= 100)
								chatCMDPlrMoneyRadius[plrID] = radius;
						}
					}
				}
				//else if (x == cmd_money && chatCMDGiveMoney) {	//give money

				//}

				//add more here

				else notifyMap("~r~Command Not Exist!");
			}
			else
				Log::Msg("ERROR finding the player id from chat!");
		}
	}
	return true;
}