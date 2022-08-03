#include "discordwirra.h"
#include "../../Discord/include/discord_register.h"
#include "../../Discord/include/discord_rpc.h"
//#pragma comment(lib, "../Libraries/Binaries/discord-rpc.lib")

DiscordRichPresence discordPresence;
const char* token = "your rpc key";
void UpdatePresence()
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = "fortnite balls";
	discordPresence.details = "RICH PRESENCE TEST";
	discordPresence.startTimestamp = time(0); //initlialize time
	discordPresence.largeImageKey = "test"; //large image file name no extension
	discordPresence.largeImageText = "69420";
	discordPresence.smallImageKey = "test"; //same as large
	discordPresence.smallImageText = "Your Text"; //displays on hover
	Discord_UpdatePresence(&discordPresence); //do the do
}

void Initialize()
{
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));
	Discord_Initialize("NO", &handlers, TRUE, nullptr);
}

void Shutdown()
{
	Discord_Shutdown(); //goodbye
}

void DiscordMain() //callin dllmain or hook w/e
{
	Initialize();
	UpdatePresence();
}