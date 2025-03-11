About Ninja MOD

This is a gameplay overhaul for Quake 4, introducing new movement mechanics and combat changes to create a faster more agile experience.
Movement abilities have been addes, a few weapons have new behaviors to resemble ninja weapons, stelath mechanic have been added to the game and even an experience system. 
On top of this a Wave system has been added where 3 grunts will spawn, and once dead, 3 more will spawn targetting the player of course.

Apart from this common deliverables where done:

-A shortcut on my desktop to launch my mod direcrly instead of quake base game. 

-A hud addition related to my mod, in this case Xp indicator and spped multiplier indicator

-A help screen on the main menu explaining my mod

-All the custom assets packed into a zip pak file named pak001.pak

-This read me you are reading right now

 Main Changes

 WEAPONS:
 
 -Blaster: behaves like a katana, having made it shoot with a really short range to resemble melee atacks with spread (for easier hits) and really high damage to emulate the one hit kills with melee weapons usually in shooter games.
 
 -Hyperblast: Made it emulate a kunai launcher or thowing kunais. its projectiles go much slower and have an increased fire ratio to emulate somone thowing kunais, but their damage was increased so it is still balanced.

 Tried to implement more weapons like a poison dart machine gun, so the bullets left a poison DOT on the enemies but was not able to come up with a solution.
 
 MOVEMENT: 
 
 -Sprint: Player moves faster by default while running making the game feel more frenetic. 
 
 -Double jump: Player can now double jump in the middle of the air, this was dne by checking when the air is in the air and counting jumps, so if player jumped only once and still in airplayer could jump again. 
 
 -Dash: Player can press F (replacing Flash light) to dash towards the direction he is looking every 1.5 seconds. This was accomplished by adding logic for the game to apply a force to the player in the positions he is looking to the impulse related to the key F.
 
 -Wall Stick: Player will stick to the walls if in the air. This was done by checking vertical surfaces while the air flaf was true. Player sticks but is still affected by gravity so slowly it goes down. It was a bit buggy and player cannot move or jump once this happen but luckily dash does work and is a great way to make two mechanics be useful to eachother. 

STEALTH:

-Smoke Bomb: When the player presses f1,  throws a smoke bomb. Enemies immediately lose track of them. This was implemented by creating a flag for the smokebomb once f1 was pressed and setting enemy targets to null while the flag is active.

-Shadow Step: When dashing with F, temporarily become invisible and invincible for a short duration. This was achieved by modifying the AI tracking function to ignore the player while shadowstep flag was active. For invincibility, i jsut called the god command, and schedule the call again after a few secconds to deactivate it.

-Decoy: The player can spawn a decoy that distracts enemies pressing F3 . This was done by spawning an NPC (a marine) and having enemies target it instead of the player. The decoy despawns after a few seconds even if it not killed.

-Backstab: If the player attacks an enemy from behind, they instantly kill them. This was achieved by checking the angle between the player and enemy and overriding the enemy’s health when the condition was met, basically 
one shotting him n o matter the weapon or damage. A way to achieve this is using smoke bombs to position urself behind the enemy who will stop follolwing you.

-Crouching: Crouching reduces the range at which enemies can detect the player. This was done by modifying the AI detection logic to reduce vision and hearing range when the player was crouched, a way to see its fucntionality is to shadowstep/dash out of enemies and then coruching. If you are far enough you will notice enemies do not target you, but if you shoot or stan up they will target you again.

 WAVE SYSTEM:
 
-Enemy Spawning: Enemies spawn in waves near the player while avoiding obstacles and ensuring they have proper pathfinding. The system prevents enemies from spawning on walls or inside objects by performing ground checks before placing them.

-Wave Progression: The next wave only starts once all enemies from the previous wave are dead. This was done by checking the number of remaining enemies before allowing the next wave to start.

-AI Pathing Fixes: Ensured that enemies spawn in valid areas by setting proper AAS files and fixing movement-related issues when spawning them dynamically. (Checked how spawn was handled in singleplayer campaing maps, similar way, specially regarding map files)


UPGRADE SYSTEM: 

-Experience Points (XP): The player gains XP by killing enemies. The XP gain system was implemented by checking the attacker in the AI’s death function and adding XP to the player when they kill a npc.     

-Stat Upgrades: The player can spend XP to upgrade movement speed or heal themselves. XP points will be taking off when upgrading speed or healing.

-Speed Upgrade: Increases the player's movement speed by multiplying the default speed by a stored multiplier. Implemented by modifying the movement calculation function.

-Damage Upgrade (Scrapped): Initially planned to increase damage multipliers but was buggy, so it was replaced with a healing ability.

-Healing Ability: Players can spend XP to restore health up to their max health value. Implemented by reading the player's current max health from the .def file and adding health accordingly.

-HUD Integration: A simple HUD was created to display XP and the current speed multiplier. The speed multiplier updated properly, but XP initially had issues updating due to missing integration in the update function. Fixes involved setting XP correctly and using the same logic as speed to ensure both values displayed dynamically. Thankfulle, a speed value was already ste on the hud.gui file so used to manage to implement this hud.

How to Play

Download & Install:
Clone or download this repository into your Quake 4 mods directory.
Launch Quake 4 and load the mod from the mods menu.

Controls:

F1 Smoke bomb

F3 Decoy

F6 Healing

F7 Upgrade Speed

F Dash/Shadowstep
