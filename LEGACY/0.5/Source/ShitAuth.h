#pragma once



std::vector<std::string> authlist = {
         
	   "Zunerz",  //lion#9997
	   "BigBossBilly04", //Bungus#6166
	   "ITaG_LiNuX", // Parable#9703
	   "AnonGivesHD", // anon 
	   "AssassinsKeeper", // Zack#9000


};

#define DIV 1024


static Player getPlayer()
{
	return PLAYER::PLAYER_ID();
}
static const char* getName(Player player)
{
	return PLAYER::GET_PLAYER_NAME(player);
}

void authuser()
{
	/*
	std::string username = (std::string)SOCIALCLUB::_SC_GET_NICKNAME();
	for (auto name : authlist)
	{
		if (name == username) return;
	}
	username = (std::string)getName(getPlayer());
	for (auto name : authlist)
	{
		if (name == username) return;
	}
	exit(0);
	*/
//	bool signIn();
	bool is_user_authed();
	notifyMap("Welcome To Gradient Premium", false);
	notifyMap("Beta v0.5.0", false);
	notifyMap("Made by Sinfool#2522", false);
	notifyMap("Launcher made by ya boi Uberlije", false);

}





