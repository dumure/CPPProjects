#pragma once
#include "User.h"
#include <vector>
#include <string>
#include <fstream>
class MoneyGuard
{
	User m_current_user;
	std::vector<User> m_users_list;
	void serialize();
	void deserialize();
public:
	~MoneyGuard();
	void start(User& a_user);
	void show_categories();
	void categories();
	void choice_category();
	void show_events(int a_index);
	void events(int a_index);
	void add_event(int a_index);
	void remove_event(int a_index);
	void add_category();
	void remove_category();
	void history();
	void clear_history();
    std::vector<User> get_users_list();
	void add_user();
	void update_user();
};

