#pragma once
#include "Discord/discord_rpc.h"
#define DISCORD_APP_ID "879066935059435551"





struct DiscordPresence
{
    int64_t StartTime = 0;
    std::string CurrentWorld = "";
    std::string CurrentPlayerName = "";
    int CurrentPlayerCount = 0;

    DiscordPresence()
    {
        StartTime = time(NULL);
        InitRPC();
    }
    
    void UpdatePresence()
    {
        if (!Globals::DiscordRPCBools["Use Rich Presence"])
        {
            Discord_ClearPresence();
            return;
        }
        char buffer[256];
        char buffer2[256];
        char buffer3[256];
        DiscordRichPresence discordPresence;
        ZeroMemory(&discordPresence, sizeof(discordPresence));

        //static Il2CppClass* nwClient = il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", "NetworkClient");
        //static int currentWorldOffset = il2cpp_class_get_field_from_name(nwClient, "currentWorld")->offset;
        //
        //static Il2CppClass* staticPlayer = il2cpp_class_from_name(Globals::Assemblies["Assembly-CSharp"]->image, "", "StaticPlayer");
        //static int theRealPlayernameOffset = il2cpp_class_get_field_from_name(staticPlayer, "theRealPlayername")->offset;

        if (Globals::DiscordRPCBools["Show Current World"])
        {
            if (Globals::IsInWorld)
            {
                //Il2CppList<Il2CppObject*>* otherPlayers = (Il2CppList<Il2CppObject*>*)Il2Cpp::Helpers::ObjectFromFieldPath(/*Globals::NetworkPlayers*/(Il2CppClass*)Globals::Classes["Assembly-CSharp.NetworkPlayers"], { "otherPlayers" });
                //std::string currentWorld = cppstr(il2cpp_object_get_field_value_by_offset(nwClient->static_fields, Il2CppString*, currentWorldOffset));
                if (Globals::DiscordRPCBools["Show Current Player Count In World"])
                {
                    sprintf(buffer3, "%i/50 Players", CurrentPlayerCount);
                    discordPresence.largeImageText = buffer3;
                    sprintf(buffer, "In World %s (%i/50)", CurrentWorld.c_str(), CurrentPlayerCount);
                }
                else
                {
                    sprintf(buffer, "In World %s", CurrentWorld.c_str());
                }
                discordPresence.details = buffer;
            }
            else
            {
                discordPresence.details = "In Menus";
            }
        }


        if (Globals::DiscordRPCBools["Show Logged in Username"])
        {
            sprintf(buffer2, "Logged In As %s", CurrentPlayerName.c_str());
            discordPresence.state = buffer2;
        }

        if (Globals::DiscordRPCBools["Show Amount of Time Playing"])
        {
            discordPresence.startTimestamp = StartTime;
        }
        discordPresence.largeImageKey = "ali-a";
        //sprintf(buffer, "Frustration level: %d", FrustrationLevel);
        //discordPresence.details = buffer;
        //discordPresence.startTimestamp = StartTime;
        //discordPresence.endTimestamp = time(0) + 5 * 60;
        //discordPresence.largeImageKey = "canary-large";
        //discordPresence.smallImageKey = "ptb-small";
        //discordPresence.partyId = "party1234";
        //discordPresence.partySize = 1;
        //discordPresence.partyMax = 6;
        //discordPresence.partyPrivacy = DISCORD_PARTY_PUBLIC;
        //discordPresence.matchSecret = "xyzzy";
        //discordPresence.joinSecret = "join";
        //discordPresence.spectateSecret = "look";
        //discordPresence.instance = 0;
        Discord_UpdatePresence(&discordPresence);
        //Discord_ClearPresence();
    }

    static void handleDiscordReady(const DiscordUser* connectedUser)
    {
        Console.printf("\nDiscord: connected to user %s#%s - %s\n",
            connectedUser->username,
            connectedUser->discriminator,
            connectedUser->userId);
    }

    static void handleDiscordDisconnected(int errcode, const char* message)
    {
        Console.printf("\nDiscord: disconnected (%d: %s)\n", errcode, message);
    }

    static void handleDiscordError(int errcode, const char* message)
    {
        Console.printf("\nDiscord: error (%d: %s)\n", errcode, message);
    }
    void Shutdown()
    {
        Discord_Shutdown();
    }
    void InitRPC()
    {
        DiscordEventHandlers handlers;
        ZeroMemory(&handlers, sizeof(handlers));
        StartTime = time(0);
        Discord_Initialize(DISCORD_APP_ID, &handlers, 1, NULL);
    }
};

DiscordPresence Discord;