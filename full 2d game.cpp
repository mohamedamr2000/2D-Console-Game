#include <iostream>
#include <conio.h>
#include<windows.h>
using namespace std;

struct player
{
	char sprite[17] = { '_','_','_','|','O','-','o','|','/','|','_','_','_','|','\\','|','|' };
	int Hrp = 10, dir2 = 0;
	int Hcp = 14, dir = 0, lvldir = 0, templvldir = 0;
	int orientation = 0;
	char healthbar = { '-' };
	int death = 0;
	int health = 300;
	int money = 0;
	int kills = 0;
	int reward = 0;
	int level = 1;
	int levelct = 0;
	int reset = 0;
	char interact_draw[12] = { '[','E',']',' ','I','n','t','e','r','a','c','t' };
	int interact = 0, interact_trigger = 0;
	char pickup_draw[10] = { '[','S',']',' ','P','i','c','k','u','p' };
	int pickup = 0, pickup_trigger = 0, portalgo = 0, portal_trigger = 0;
	int jump = 0, jump_trigger = 0, gravity = 0;
	char portinter_draw[10] = { '[','I',']',' ','P','o','r','t','a','l' };
};

struct npcs
{
	//Random NPC
	int NPC_rp = 15;
	int NPC_cp = 40;
	char Rsprite[18] = { '_','_','_','|','O','_','o','|','/','|','_','_','_','|','\\','|','|', '-' };
	int NPC_Rand = 0;
	int NPC_Rand_terminate = 0;

	//Enemy NPC
	int Erp = 15;
	int Ecp = 70;
	char esprite[17] = { '_','\\','_','|','@','-','@','|','c','|','_','_','_','|','c','|','|' };
	char epistol[3] = { '-','-','-' };
	int NPC_En = 0;
	int damage = 0;
	int NPC_En_terminate = 0;
	int En_aggro = 0;

	//Enemy Dog
	int Drp = 15;
	int Dcp = 57;
	char dsprite[11] = { '-', '-','-','_','_','_','/','/','\\', '-', '-' };
	int En_D = 0;
	int En_D_terminate = 0;
	int En_D_aggro = 0;
	int Ddmg = 0;

	//Enemy Slime
	int SLrp = 15;
	int SLcp = 60;
	char Ssprite[15] = { '_', '_', '_', '_', '|', '@', '@', '|', '|', '_', '_', '_', '_', '|' };
	int En_Sl = 0;
	int En_Sl_terminate = 0;
	int En_Sl_aggro;
	int Sldmg = 0;

	//Shop NPC
	int Srp = 15;
	int Scp = 40;
	char interaction22[17] = { 'H','e','l','l','o',' ','T','r','a','v','e','l','l','e','r','!','\0' };
	int NPC_Shop;
	int NPC_Shop_terminate = 0;

	//NPC chat dialogs
	char interaction1[26] = { 'H','E','L','P','!',' ','P','l','e','a','s','e',' ','h','e','l','p',' ','i','m',' ','h','u','r','t', '!' };
	char interaction2[48] = { 'A',' ','r','o','b','o','t',' ','c','a','m','e',' ','a','n','d',' ','k','i','d','n','a','p','p','e','d',' ','m','y',' ','d','a','u','g','h','t','e','r','!' };
	char interaction3[29] = { 'U','s','e',' ','t','h','e',' ','p','i','s','t','o','l',' ','o','n',' ','t','h','e',' ','g','r','o', 'u','n','d', '\0' };
	char interaction4[12] = { 'M','r',' ','H','o','u', 'o', 'u', 'o', 'i' , 'n' , '\0' };
	char interaction5[11] = { 'E','N','E','M','Y',' ','R', 'O', 'B', 'O', 'T' };
	char interaction6[29] = { 'T','H','A','N','K',' ','Y','O','U','!',' ','Y','o','u',' ','s','a','v','e','d',' ','m','y',' ','g', 'i', 'r', 'l','!' };
	char interaction7[20] = { 'H','e','r','e',' ','i','s',' ','y','o','u','r',' ','r','e','w','a','r','d','.' };
};

struct items
{
	char inventory_draw[2] = { '_', '|' };

	char pistol_draw[3] = { '-', '-', '-' };
	int pistol = 0;
	int pistol_ammo = 12;

	char sword_draw[5] = { '+','-','/','-','\\' };
	int sword = 0;

	char rocket_draw[3] = { '=', '=', '>' };
	int rocket = 0;
	int rocket_ammo = 3;
};

struct attack
{
	int b1r = 0, b1c = 0, firetrigger = 0, damage = 0, ammo = 0, dec_ammo = 0;
	int speed = 1, damage_multiplier = 1;
	char Bsprite = '-';
	char Btrail[3] = { '-', '-' , '-' }; //bullet trail for rocket launcher//
	int trail = 0;
	//Enemy atk//
	int En_b1r = 0, En_b1c = 0, En_firetrigger = 0, En_damage = 0;
	int En_speed = 1, En_damage_multiplier = 0;
	char En_Bsprite = '-';
	char En_Btrail[3] = { '-', '-' , '-' }; //bullet trail for rocket launcher//
	int En_trail = 0;
};

struct objects
{
	char portsprite = 177;
	int portrp = 15;
	int portcp = 78;
	int portalcheck = 0;
};

struct Elevator
{
	char elvsprite = '@';
	int elvrp = 18, elvdir = 0;
	int elvcp = 171;
	int trigelv = 0;
	int elvcount = 0;
	int elvstep = 0;
};

class EnemyNPC
{
public:
	//Enemy NPC

	int Erp = 15;
	int Ecp = 70;
	char esprite[17] = { '_','\\','_','|','@','-','@','|','c','|','_','_','_','|','c','|','|' };
	char epistol[3] = { '-','-','-' };
	int NPC_En = 0;
	int NPC_En_terminate = 0;
	int Enlimiter = 0;
	int En_b1r = 0, En_b1c = 0, En_firetrigger = 0, En_damage = 0;
	int En_speed = 1, En_damage_multiplier = 0;
	char En_Bsprite = '-';
	char En_Btrail[3] = { '-', '-' , '-' }; //bullet trail for rocket launcher//
	int En_trail = 0;

	void setenemy(char game[][400], player &x)
	{
		epistol[0] = 203; epistol[1] = 205; epistol[2] = 196;
		esprite[1] = 203; esprite[15] = 244; esprite[16] = 244;
		if (NPC_En == 1)
		{
			game[Erp][Ecp] = esprite[0]; //head
			game[Erp][Ecp + 1] = esprite[1]; //antenna left
			game[Erp][Ecp + 2] = esprite[2]; //head
			game[Erp + 1][Ecp - 1] = esprite[3]; //head
			game[Erp + 1][Ecp] = esprite[4]; //left eye
			game[Erp + 1][Ecp + 1] = esprite[5]; //mouth
			game[Erp + 1][Ecp + 2] = esprite[6]; //right eye
			game[Erp + 1][Ecp + 3] = esprite[7]; //head
			game[Erp + 2][Ecp - 2] = esprite[8]; //left arm
			game[Erp + 2][Ecp - 1] = esprite[9]; //body
			game[Erp + 2][Ecp] = esprite[10]; //body
			game[Erp + 2][Ecp + 1] = esprite[11]; //body
			game[Erp + 2][Ecp + 2] = esprite[12]; //body
			game[Erp + 2][Ecp + 3] = esprite[13]; //body
			game[Erp + 2][Ecp + 4] = esprite[14]; //right arm
			game[Erp + 3][Ecp] = esprite[15]; //left leg
			game[Erp + 3][Ecp + 2] = esprite[16]; //right leg
			game[Erp + 2][Ecp - 3] = epistol[0];
			game[Erp + 2][Ecp - 4] = epistol[1];
			game[Erp + 2][Ecp - 5] = epistol[2];
			game[Erp - 1][Ecp - 1] = x.healthbar;
			game[Erp - 1][Ecp] = x.healthbar;
			game[Erp - 1][Ecp + 1] = x.healthbar;
			game[Erp - 1][Ecp + 2] = x.healthbar;
			game[Erp - 1][Ecp + 3] = x.healthbar;
		}
		if (NPC_En_terminate == 1)
		{
			game[Erp][Ecp] = ' '; //head
			game[Erp][Ecp + 1] = ' '; //antenna left
			game[Erp][Ecp + 2] = ' '; //head
			game[Erp + 1][Ecp - 1] = ' '; //head
			game[Erp + 1][Ecp] = ' '; //left eye
			game[Erp + 1][Ecp + 1] = ' '; //mouth
			game[Erp + 1][Ecp + 2] = ' '; //right eye
			game[Erp + 1][Ecp + 3] = ' '; //head
			game[Erp + 2][Ecp - 2] = ' '; //left arm
			game[Erp + 2][Ecp - 1] = ' '; //body
			game[Erp + 2][Ecp] = ' '; //body
			game[Erp + 2][Ecp + 1] = ' '; //body
			game[Erp + 2][Ecp + 2] = ' '; //body
			game[Erp + 2][Ecp + 3] = ' '; //body
			game[Erp + 2][Ecp + 4] = ' '; //right arm
			game[Erp + 3][Ecp] = ' '; //left leg
			game[Erp + 3][Ecp + 2] = ' '; //right leg
			game[Erp + 2][Ecp - 3] = ' ';
			game[Erp + 2][Ecp - 4] = ' ';
			game[Erp + 2][Ecp - 5] = ' ';
			game[Erp - 1][Ecp - 1] = ' ';
			game[Erp - 1][Ecp] = ' ';
			game[Erp - 1][Ecp + 1] = ' ';
			game[Erp - 1][Ecp + 2] = ' ';
			game[Erp - 1][Ecp + 3] = ' ';
		}
	}
	void attack(char game[][400], player &x)
	{

		//Attack stats://
		En_speed = 1;
		En_damage_multiplier = 60;
		En_Bsprite = '<';
		En_trail = 1;
		En_Btrail[0] = '=';
		En_Btrail[1] = '-';
		En_Btrail[2] = '*';

		if (NPC_En == 1 && En_firetrigger == 0 && x.lvldir > Enlimiter)
		{
			En_b1r = Erp + 2;
			En_b1c = Ecp - 5;
			En_firetrigger = 1;
		}

		//Enemy bullet firing
		game[x.Hrp + 2][x.Hcp - 2] = x.sprite[8]; //left arm
		if (En_firetrigger == 1 && En_b1c != 1 && NPC_En_terminate != 1 && NPC_En == 1)
		{
			game[En_b1r][En_b1c] = ' ';
			if (En_b1c != 1 && game[En_b1r][En_b1c - 1] != '/')
			{
				En_b1c--;
			}
			/*if (En_b1c != 1 && game[En_b1r][En_b1c - 1] != x.sprite[12] && En_speed > 1)
			{
				En_b1c--;
			}
			if (En_b1c != 1 && game[En_b1r][En_b1c - 1] != x.sprite[12] && En_speed > 2)
			{
				En_b1c--;
			}*/
			game[En_b1r][En_b1c] = En_Bsprite;
			if (game[En_b1r][En_b1c - 1] == '/')
			{
				x.health -= En_damage_multiplier;
				En_firetrigger = 0;
				game[En_b1r][En_b1c] = ' ';
			}
		}
		else
		{
			game[En_b1r][En_b1c] = ' ';
			En_firetrigger = 0;
		}
		game[x.Hrp - x.dir2][x.Hcp - x.dir] = ' '; //head
		game[x.Hrp - x.dir2][x.Hcp + 1 - x.dir] = ' '; //head
		game[x.Hrp - x.dir2][x.Hcp + 2 - x.dir] = ' '; //head
		game[x.Hrp + 1 - x.dir2][x.Hcp - 1 - x.dir] = ' '; //head
		game[x.Hrp + 1 - x.dir2][x.Hcp - x.dir] = ' '; //left eye
		game[x.Hrp + 1 - x.dir2][x.Hcp + 1 - x.dir] = ' '; //mouth
		game[x.Hrp + 1 - x.dir2][x.Hcp + 2 - x.dir] = ' '; //right eye
		game[x.Hrp + 1 - x.dir2][x.Hcp + 3 - x.dir] = ' '; //head
		game[x.Hrp + 2 - x.dir2][x.Hcp - 1 - x.dir] = ' '; //body
		game[x.Hrp + 2 - x.dir2][x.Hcp - x.dir] = ' '; //body
		game[x.Hrp + 2 - x.dir2][x.Hcp + 1 - x.dir] = ' '; //body
		game[x.Hrp + 2 - x.dir2][x.Hcp + 2 - x.dir] = ' '; //body
		game[x.Hrp + 2 - x.dir2][x.Hcp + 3 - x.dir] = ' '; //body
		game[x.Hrp + 3 - x.dir2][x.Hcp - x.dir] = ' '; //left leg
		game[x.Hrp + 3 - x.dir2][x.Hcp + 2 - x.dir] = ' '; //right leg
		game[x.Hrp][x.Hcp] = x.sprite[0]; //head
		game[x.Hrp][x.Hcp + 1] = x.sprite[1]; //head
		game[x.Hrp][x.Hcp + 2] = x.sprite[2]; //head
		game[x.Hrp + 1][x.Hcp - 1] = x.sprite[3]; //head
		if (x.orientation == 0)
		{
			game[x.Hrp + 1][x.Hcp] = x.sprite[4]; //left eye
		}
		else
		{
			game[x.Hrp + 1][x.Hcp] = x.sprite[6]; //left eye
		}
		game[x.Hrp + 1][x.Hcp + 1] = x.sprite[5]; //mouth
		if (x.orientation == 0)
		{
			game[x.Hrp + 1][x.Hcp + 2] = x.sprite[6]; //right eye
		}
		else
		{
			game[x.Hrp + 1][x.Hcp + 2] = x.sprite[4]; //right eye
		}
		game[x.Hrp + 1][x.Hcp + 3] = x.sprite[7]; //head
		game[x.Hrp + 2][x.Hcp - 1] = x.sprite[9]; //body
		game[x.Hrp + 2][x.Hcp] = x.sprite[10]; //body
		game[x.Hrp + 2][x.Hcp + 1] = x.sprite[11]; //body
		game[x.Hrp + 2][x.Hcp + 2] = x.sprite[12]; //body
		game[x.Hrp + 2][x.Hcp + 3] = x.sprite[13]; //body
		game[x.Hrp + 3][x.Hcp] = x.sprite[15]; //left leg
		game[x.Hrp + 3][x.Hcp + 2] = x.sprite[16]; //right leg

		//Left overs fix
		if (game[x.Hrp + 2][x.Hcp + 7] == '-')
		{
			game[x.Hrp + 2][x.Hcp + 7] = ' ';
		}
		if (game[x.Hrp + 3][x.Hcp + 3] == '|')
		{
			game[x.Hrp + 3][x.Hcp + 3] = ' ';
		}
		if (game[x.Hrp + 3][x.Hcp - 1] == '|')
		{
			game[x.Hrp + 3][x.Hcp - 1] = ' ';
		}
		if (game[x.Hrp + 2][x.Hcp - 3] == '/')
		{
			game[x.Hrp + 2][x.Hcp - 3] = ' ';
		}
		if (game[x.Hrp + 3][x.Hcp + 1] == '|')
		{
			game[x.Hrp + 3][x.Hcp + 1] = ' ';
		}
	}
};

class Bullet
{
public:
	int brp = 0, bcp = 0, firetrigger = 0, damage = 0;
	int speed = 1, damage_multiplier = 1;
	char Bsprite = '-';
	int limiterb = 1;
	void playerattack(char game[][80], player &x, npcs &z, EnemyNPC l[])
	{
		if (x.orientation == 0)
		{
			Bsprite = '>';
		}
		else
		{
			Bsprite = '<';
		}
		if (firetrigger == 1 && game[brp][bcp + 1] != '#' && game[brp][bcp - 1] != '#')
		{
			game[brp][bcp] = ' ';

			if (x.orientation == 0)
			{
				if (game[brp][bcp + 1] != '#' && game[brp][bcp + 1] != z.esprite[12] && game[brp][bcp + 1] != z.esprite[4])
				{
					bcp++;
				}
			}
			else
			{
				if (game[brp][bcp - 1] != '#' && game[brp][bcp - 1] != z.esprite[12] && game[brp][bcp - 1] != z.esprite[4])
				{
					bcp--;
				}
			}
			if (x.orientation == 0)
			{
				if (game[brp][bcp + 1] != '#' && game[brp][bcp + 1] != z.esprite[12] && game[brp][bcp + 1] != z.esprite[4])
				{
					bcp++;
				}
			}
			else
			{
				if (game[brp][bcp - 1] != '#' && game[brp][bcp - 1] != z.esprite[12] && game[brp][bcp - 1] != z.esprite[4] && speed > 1)
				{
					bcp--;
				}
			}
			if (x.orientation == 0)
			{
				if (game[brp][bcp + 1] != '#' && game[brp][bcp + 1] != z.esprite[12] && game[brp][bcp + 1] != z.esprite[4])
				{
					bcp++;
				}
			}
			else
			{
				if (game[brp][bcp - 1] != '#' && game[brp][bcp - 1] != z.esprite[12] && game[brp][bcp - 1] != z.esprite[4] && speed > 1)
				{
					bcp--;
				}
			}
			game[brp][bcp] = Bsprite;

			if (x.orientation == 0)
			{
				if (game[brp][bcp + 1] == z.esprite[12] || game[brp][bcp + 1] == z.esprite[4])
				{
					z.damage += damage_multiplier;
					if (x.level == 4)
					{
						l[0].En_damage += damage_multiplier;
					}
					firetrigger = 0;
				}
			}

			else
			{
				if (game[brp][bcp - 1] == z.esprite[12] || game[brp][bcp - 1] == z.esprite[4])
				{
					z.damage += damage_multiplier;
					if (x.level == 4)
					{
						l[0].En_damage += damage_multiplier;
					}
					firetrigger = 0;
					firetrigger = 0;
				}
			}
		}
		else
		{
			game[brp][bcp] = ' ';
			firetrigger = 0;
		}
	}
};

class Doggie
{
public:
	//Enemy Dog
	int Drp = 17;
	int Dcp = 57, Ddir = 0;
	char dsprite[11] = { '-', '-','-','_','_','_','/','/','\\', '-', '-' };
	int En_D = 1;
	int En_D_terminate = 0;
	int En_Dlimiter = 0;
	int Ddmg = 0;
	int Dcount = 0;
	int change = 1;
	int steps = 0;

	void movedoggie(player &x)
	{
		if (En_D != 0 /*&& x.lvldir > En_Dlimiter*/)
		{
			if (steps < 8)
			{
				Ddir = 0;
				Dcount++;
				if (Dcount % 2 == 0)
				{
					Dcp--, Ddir = -1;
					steps++;
				}
			}
			if (steps < 16 && steps >= 8)
			{
				Ddir = 0;
				Dcount--;
				if (Dcount % 2 == 0)
				{
					steps++;
					Dcp++, Ddir = 1;
				}
			}
			if (steps >= 16)
			{
				steps = 0;
			}
		}
	}

	void setdoggie(char game[][400])
	{
		if (En_D == 1)
		{
			game[Drp][Dcp - Ddir] = ' ';
			game[Drp][Dcp + 1 - Ddir] = ' ';
			game[Drp][Dcp + 2 - Ddir] = ' ';
			game[Drp][Dcp + 3 - Ddir] = ' ';
			game[Drp][Dcp + 4 - Ddir] = ' ';
			game[Drp][Dcp + 5 - Ddir] = ' ';
			game[Drp][Dcp + 6 - Ddir] = ' ';
			game[Drp + 1][Dcp + 3 - Ddir] = ' ';
			//game[d[1].Drp + 1][z.Dcp + 4] = z.dsprite[8]; (when running)
			game[Drp + 1][Dcp + 5 - Ddir] = ' ';
			//game[d[1].Drp + 1][z.Dcp + 6] = z.dsprite[10]; (when running)

			//Doggie Enemy
			game[Drp][Dcp] = dsprite[0]; //nose
			game[Drp][Dcp + 1] = dsprite[1]; //face
			game[Drp][Dcp + 2] = dsprite[2]; //ears
			game[Drp][Dcp + 3] = dsprite[3]; //body
			game[Drp][Dcp + 4] = dsprite[4]; //body
			game[Drp][Dcp + 5] = dsprite[5]; //body
			game[Drp][Dcp + 6] = dsprite[6]; //body
			game[Drp + 1][Dcp + 3] = dsprite[7]; //left leg
			//game[d[1].Drp + 1][z.Dcp + 4] = z.dsprite[8]; (when running)
			game[Drp + 1][Dcp + 5] = dsprite[9]; // right leg
			//game[d[1].Drp + 1][z.Dcp + 6] = z.dsprite[10]; (when running)
		}
	}

	void barking(char game[][80], player &x)
	{
		if (game[Drp][Dcp - 1] == x.sprite[14])
		{
			x.health -= 80;
		}
	}
};


void controller(char game[][80], char keyB, player &x, items &i, attack &a, Elevator&e, Bullet b[])
{
	if (keyB == 'a' || keyB == 'A')
	{

		x.orientation = 1;
		if (game[x.Hrp + 1][x.Hcp - 3] != '#')
		{
			if (x.level < 4)
			{
				x.Hcp--, x.dir = -1;
			}
			else
			{
				if (x.level == 4)
				{
					if (x.lvldir >= 101)
					{
						x.Hcp--, x.dir = -1;
						x.templvldir++;
					}
					else if (x.lvldir != 0)
					{
						x.lvldir--;
					}
				}
				else if (x.lvldir != 0)
				{
					x.lvldir--;
				}
			}
		}
	}
	if (keyB == 'd' || keyB == 'D')
	{
		x.orientation = 0;
		if (game[x.Hrp + 1][x.Hcp + 7] != '#')
		{
			if (x.level < 4)
			{
				x.Hcp++, x.dir = 1;
			}
			else
			{
				if (x.level == 4)
				{
					if (x.lvldir < 101)
					{
						x.lvldir++;
					}
					else
					{
						x.Hcp++, x.dir = 1;
					}
				}
				else
				{
					x.lvldir++;
				}
			}
		}
	}
	if (keyB == 'w' || keyB == 'W' || keyB == 32)
	{
		if (x.gravity == 0)
		{
			if (x.jump_trigger == 0 && game[x.Hrp + 4][x.Hcp] == '#' || game[x.Hrp + 4][x.Hcp] == '@')
			{
				x.jump_trigger = 1;
			}
		}
	}
	if (keyB == 'x' || keyB == 'X')
	{
		for (int j = 0; j < b[0].limiterb; j++)
		{
			if (i.pistol == 1 || i.sword == 1 || i.rocket == 1 && a.ammo != 0)
			{
				if (x.orientation == 0)
				{
					if (game[x.Hrp + 1][x.Hcp + 7] != '#')
					{
						if (b[j].firetrigger == 0 && x.orientation == 0)
						{
							b[j].brp = x.Hrp + 2;
							b[j].bcp = x.Hcp + 7;
							if (game[x.Hrp][x.Hcp + 1] != '#')
							{
								b[j].firetrigger = 1;
							}
						}
					}
				}
				else
				{
					if (game[x.Hrp + 1][x.Hcp - 7] != '#')
					{
						if (b[j].firetrigger == 0 && x.orientation != 0)
						{
							b[j].brp = x.Hrp + 2;
							b[j].bcp = x.Hcp - 5;
							if (game[x.Hrp][x.Hcp - 1] != '#')
							{
								b[j].firetrigger = 1;
							}
						}
					}
				}
			}
		}
		b[0].limiterb++;
	}
	if (keyB == 'e' || keyB == 'E' || keyB == 13)
	{
		if (x.Hcp > 20)
		{
			x.interact++;
		}
	}
	if (keyB == 's' || keyB == 'S')
	{
		if (x.pickup_trigger == 1)
		{
			x.pickup = 1;
		}
	}

	if (keyB == 'i' || keyB == 'I')
	{
		if (x.portal_trigger == 1)
		{
			x.portalgo = 1;
		}
		if (x.level == 4 && x.lvldir == 101)
		{
			x.level++;
		}
	}
}
void setplayer(char game[][80], player &x)
{
	if (x.health < 0 || x.health == 0)
	{
		x.death = 1;
	}

	if (x.level > 1 && x.reset == 1)
	{
		game[x.Hrp][x.Hcp] = ' '; //head
		game[x.Hrp][x.Hcp + 1] = ' '; //head
		game[x.Hrp][x.Hcp + 2] = ' '; //head
		game[x.Hrp + 1][x.Hcp - 1] = ' '; //head
		game[x.Hrp + 1][x.Hcp] = ' '; //left eye
		game[x.Hrp + 1][x.Hcp + 1] = ' '; //mouth
		game[x.Hrp + 1][x.Hcp + 2] = ' '; //right eye
		game[x.Hrp + 1][x.Hcp + 3] = ' '; //head
		game[x.Hrp + 2][x.Hcp - 1] = ' '; //body
		game[x.Hrp + 2][x.Hcp] = ' '; //body
		game[x.Hrp + 2][x.Hcp + 1] = ' '; //body
		game[x.Hrp + 2][x.Hcp + 2] = ' '; //body
		game[x.Hrp + 2][x.Hcp + 3] = ' '; //body
		game[x.Hrp + 3][x.Hcp] = ' '; //left leg
		game[x.Hrp + 3][x.Hcp + 2] = ' '; //right leg
		game[x.Hrp + 2 - x.dir2][x.Hcp + 4 - x.dir] = ' ';
		game[x.Hrp + 2 - x.dir2][x.Hcp + 5 - x.dir] = ' ';
		game[x.Hrp + 2 - x.dir2][x.Hcp + 6 - x.dir] = ' ';
		x.Hrp = 10, x.Hcp = 14;
		x.reset = 0;
	}
	game[x.Hrp - x.dir2][x.Hcp - x.dir] = ' '; //head
	game[x.Hrp - x.dir2][x.Hcp + 1 - x.dir] = ' '; //head
	game[x.Hrp - x.dir2][x.Hcp + 2 - x.dir] = ' '; //head
	game[x.Hrp + 1 - x.dir2][x.Hcp - 1 - x.dir] = ' '; //head
	game[x.Hrp + 1 - x.dir2][x.Hcp - x.dir] = ' '; //left eye
	game[x.Hrp + 1 - x.dir2][x.Hcp + 1 - x.dir] = ' '; //mouth
	game[x.Hrp + 1 - x.dir2][x.Hcp + 2 - x.dir] = ' '; //right eye
	game[x.Hrp + 1 - x.dir2][x.Hcp + 3 - x.dir] = ' '; //head
	game[x.Hrp + 2 - x.dir2][x.Hcp - 1 - x.dir] = ' '; //body
	game[x.Hrp + 2 - x.dir2][x.Hcp - x.dir] = ' '; //body
	game[x.Hrp + 2 - x.dir2][x.Hcp + 1 - x.dir] = ' '; //body
	game[x.Hrp + 2 - x.dir2][x.Hcp + 2 - x.dir] = ' '; //body
	game[x.Hrp + 2 - x.dir2][x.Hcp + 3 - x.dir] = ' '; //body
	game[x.Hrp + 3 - x.dir2][x.Hcp - x.dir] = ' '; //left leg
	game[x.Hrp + 3 - x.dir2][x.Hcp + 2 - x.dir] = ' '; //right leg
	game[x.Hrp][x.Hcp] = x.sprite[0]; //head
	game[x.Hrp][x.Hcp + 1] = x.sprite[1]; //head
	game[x.Hrp][x.Hcp + 2] = x.sprite[2]; //head
	game[x.Hrp + 1][x.Hcp - 1] = x.sprite[3]; //head
	if (x.orientation == 0)
	{
		game[x.Hrp + 1][x.Hcp] = x.sprite[4]; //left eye
	}
	else
	{
		game[x.Hrp + 1][x.Hcp] = x.sprite[6]; //left eye
	}
	game[x.Hrp + 1][x.Hcp + 1] = x.sprite[5]; //mouth
	if (x.orientation == 0)
	{
		game[x.Hrp + 1][x.Hcp + 2] = x.sprite[6]; //right eye
	}
	else
	{
		game[x.Hrp + 1][x.Hcp + 2] = x.sprite[4]; //right eye
	}
	game[x.Hrp + 1][x.Hcp + 3] = x.sprite[7]; //head
	game[x.Hrp + 2][x.Hcp - 1] = x.sprite[9]; //body
	game[x.Hrp + 2][x.Hcp] = x.sprite[10]; //body
	game[x.Hrp + 2][x.Hcp + 1] = x.sprite[11]; //body
	game[x.Hrp + 2][x.Hcp + 2] = x.sprite[12]; //body
	game[x.Hrp + 2][x.Hcp + 3] = x.sprite[13]; //body
	game[x.Hrp + 3][x.Hcp] = x.sprite[15]; //left leg
	game[x.Hrp + 3][x.Hcp + 2] = x.sprite[16]; //right leg

	//Left overs fix
	if (game[x.Hrp + 2][x.Hcp + 7] == '-')
	{
		game[x.Hrp + 2][x.Hcp + 7] = ' ';
	}
	if (game[x.Hrp + 3][x.Hcp + 3] == '|')
	{
		game[x.Hrp + 3][x.Hcp + 3] = ' ';
	}
	if (game[x.Hrp + 3][x.Hcp - 1] == '|')
	{
		game[x.Hrp + 3][x.Hcp - 1] = ' ';
	}
	if (game[x.Hrp + 2][x.Hcp - 3] == '/')
	{
		game[x.Hrp + 2][x.Hcp - 3] = ' ';
	}
	if (game[x.Hrp + 3][x.Hcp + 1] == '|')
	{
		game[x.Hrp + 3][x.Hcp + 1] = ' ';
	}
}


void setlevels(char game[][80], char lvl[][400], player &x, Elevator &e, Doggie d[], EnemyNPC l[], objects &k)
{


	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 400; j++)
			lvl[i][j] = ' ';
	for (int i = 0; i < 80; i++)
		lvl[0][i] = ' ';

	if (x.level == 5)
	{
		x.health = 0;
	}
	if (x.portalgo == 1)
	{
		x.portal_trigger = 0;
		k.portalcheck = 0;
		x.portalgo = 0;

		//erase
		lvl[k.portrp + 1][k.portcp] = ' ';
		lvl[k.portrp + 2][k.portcp] = ' ';
		lvl[k.portrp + 3][k.portcp] = ' ';
		lvl[k.portrp + 1][k.portcp - 1] = ' ';
		lvl[k.portrp + 2][k.portcp - 1] = ' ';
		lvl[k.portrp + 3][k.portcp - 1] = ' ';
		lvl[k.portrp + 1][k.portcp - 2] = ' ';
		lvl[k.portrp + 2][k.portcp - 2] = ' ';
		lvl[k.portrp + 3][k.portcp - 2] = ' ';
		lvl[k.portrp + 1][k.portcp - 3] = ' ';
		lvl[k.portrp + 2][k.portcp - 3] = ' ';
		lvl[k.portrp + 3][k.portcp - 3] = ' ';

		x.level++;
		x.reset = 1;
		x.lvldir = 0;
	}


	if (k.portalcheck == 1)
	{
		lvl[k.portrp + 1][k.portcp] = k.portsprite;
		lvl[k.portrp + 2][k.portcp] = k.portsprite;
		lvl[k.portrp + 3][k.portcp] = k.portsprite;
		lvl[k.portrp + 1][k.portcp - 1] = k.portsprite;
		lvl[k.portrp + 2][k.portcp - 1] = k.portsprite;
		lvl[k.portrp + 3][k.portcp - 1] = k.portsprite;
		lvl[k.portrp + 1][k.portcp - 2] = k.portsprite;
		lvl[k.portrp + 2][k.portcp - 2] = k.portsprite;
		lvl[k.portrp + 3][k.portcp - 2] = k.portsprite;
		lvl[k.portrp + 1][k.portcp - 3] = k.portsprite;
		lvl[k.portrp + 2][k.portcp - 3] = k.portsprite;
		lvl[k.portrp + 3][k.portcp - 3] = k.portsprite;
	}


	if (x.level == 4)
	{
		if (d[2].change == 1)
		{
			d[2].Dcp = 60;
			d[2].change = 0;
		}
		d[2].movedoggie(x);
		d[2].setdoggie(lvl);
	}

	if (x.level == 4)
	{
		l[0].Erp = 10, l[0].Ecp = 65, l[0].NPC_En = 1, l[0].Enlimiter = 16;
		l[0].setenemy(lvl, x);
		l[0].attack(lvl, x);
		l[1].Erp = 5, l[1].Ecp = 166, l[1].NPC_En = 1, l[1].Enlimiter = 101;
		l[1].setenemy(lvl, x);
		l[1].attack(lvl, x);
		e.trigelv = 1;
		k.portalcheck = 1;
		k.portcp = 120;

		if (e.trigelv == 1)
		{
			//erase elv
			lvl[e.elvrp + e.elvdir][e.elvcp] = ' ';
			lvl[e.elvrp + e.elvdir][e.elvcp + 1] = ' ';
			lvl[e.elvrp + e.elvdir][e.elvcp + 2] = ' ';
			lvl[e.elvrp + e.elvdir][e.elvcp + 3] = ' ';

			//draw elv
			lvl[e.elvrp][e.elvcp] = e.elvsprite;
			lvl[e.elvrp][e.elvcp + 1] = e.elvsprite;
			lvl[e.elvrp][e.elvcp + 2] = e.elvsprite;
			lvl[e.elvrp][e.elvcp + 3] = e.elvsprite;
		}
		for (int i = 40; i < 70; i++)
		{
			lvl[14][i] = '#';
		}

		int g = 0;
		for (int i = 1; i < 5; i++)
		{
			lvl[14 + i][40 - g] = '#';
			lvl[14 + i][40 - (g + 1)] = '#';
			lvl[14 + i][40 - (g + 2)] = '#';
			lvl[14 + i][40 - (g + 3)] = '#';
			g += 3;
		}


		for (int i = 100; i < 130; i++)
		{
			lvl[14][i] = '#';
		}
		for (int i = 141; i < 171; i++)
		{
			lvl[9][i] = '#';
		}

		g = 0;
		for (int i = 1; i < 5; i++)
		{
			lvl[14 + i][100 - g] = '#';
			lvl[14 + i][100 - (g + 1)] = '#';
			lvl[14 + i][100 - (g + 2)] = '#';
			lvl[14 + i][100 - (g + 3)] = '#';
			g += 3;
		}

		g = 0;
		for (int i = 1; i < 5; i++)
		{
			lvl[9 + i][141 - g] = '#';
			lvl[9 + i][141 - (g + 1)] = '#';
			lvl[9 + i][141 - (g + 2)] = '#';
			lvl[9 + i][141 - (g + 3)] = '#';
			g += 3;
		}

		for (int i = 1; i < 19; i++)
		{
			for (int j = 1; j < 79; j++)
			{
				game[i][j] = lvl[i][j + x.lvldir];
			}
		}
	}
}



void inventory(char game[][80], player &x, items &i, attack &a)
{
	int invpos = 0;
	for (int i = 50; i < 73; i++)
	{
		game[1][i] = '_';
		game[3][i] = '_';
	}
	for (int i = 2; i < 4; i++)
	{
		game[i][49] = '|';
		game[i][55] = '|';
		game[i][61] = '|';
		game[i][67] = '|';
		game[i][73] = '|';
	}

	if (i.pistol == 1)
	{
		//inventory spot://
		game[2][51 + invpos] = i.pistol_draw[0];
		game[2][52 + invpos] = i.pistol_draw[1];
		game[2][53 + invpos] = i.pistol_draw[2];
		invpos += 6;

		//spot on hand://
		if (x.orientation == 0)
		{
			game[x.Hrp + 2 - x.dir2][x.Hcp - 4 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp - 5 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp - 6 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp + 4 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp + 5 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp + 6 - x.dir] = ' ';
			game[x.Hrp + 2][x.Hcp + 4] = i.pistol_draw[0];
			game[x.Hrp + 2][x.Hcp + 5] = i.pistol_draw[1];
			game[x.Hrp + 2][x.Hcp + 6] = i.pistol_draw[2];
		}
		else
		{
			game[x.Hrp + 2 - x.dir2][x.Hcp + 4 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp + 5 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp + 6 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp - 4 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp - 5 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp - 6 - x.dir] = ' ';
			game[x.Hrp + 2][x.Hcp - 2] = i.pistol_draw[0];
			game[x.Hrp + 2][x.Hcp - 3] = i.pistol_draw[1];
			game[x.Hrp + 2][x.Hcp - 4] = i.pistol_draw[2];
		}
		//ammo draw & decrease://
		a.Bsprite = '>';
		a.ammo = i.pistol_ammo;
		if (a.firetrigger == 1 && i.pistol_ammo > 0 && a.dec_ammo == 1)
		{
			a.dec_ammo = 0;
			i.pistol_ammo--;
		}

		//weapon stats://
		a.speed = 2;
		a.damage_multiplier = 1;
	}
	if (i.sword == 1)
	{
		//inventory spot://
		game[2][51 + invpos] = i.sword_draw[0];
		game[2][52 + invpos] = i.sword_draw[1];
		game[2][53 + invpos] = i.sword_draw[1];
		invpos += 6;

		//spot on hand://
		game[x.Hrp + 2 - x.dir2][x.Hcp + 4 - x.dir] = ' ';
		game[x.Hrp + 2 - x.dir2][x.Hcp + 5 - x.dir] = ' ';
		game[x.Hrp + 2 - x.dir2][x.Hcp + 6 - x.dir] = ' ';
		game[x.Hrp + 2][x.Hcp + 4] = i.sword_draw[0];
		game[x.Hrp + 2][x.Hcp + 5] = i.sword_draw[1];
		game[x.Hrp + 2][x.Hcp + 6] = i.sword_draw[1];

		//weapon stats://
		a.speed = 3;
		a.damage_multiplier = 2;
		a.Bsprite = '>';
	}
	if (i.rocket == 1)
	{
		//inventory spot://
		game[2][51 + invpos] = i.rocket_draw[0];
		game[2][52 + invpos] = i.rocket_draw[1];
		game[2][53 + invpos] = i.rocket_draw[1];
		invpos += 6;

		//spot on hand://
		if (x.orientation == 0)
		{
			game[x.Hrp + 2 - x.dir2][x.Hcp - 4 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp - 5 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp - 6 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp + 4 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp + 5 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp + 6 - x.dir] = ' ';
			game[x.Hrp + 2][x.Hcp + 4] = i.rocket_draw[0];
			game[x.Hrp + 2][x.Hcp + 5] = i.rocket_draw[1];
			game[x.Hrp + 2][x.Hcp + 6] = 'O';
			a.Bsprite = '>';
		}
		else
		{
			game[x.Hrp + 2 - x.dir2][x.Hcp + 4 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp + 5 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp + 6 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp - 4 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp - 5 - x.dir] = ' ';
			game[x.Hrp + 2 - x.dir2][x.Hcp - 6 - x.dir] = ' ';
			game[x.Hrp + 2][x.Hcp - 2] = i.rocket_draw[0];
			game[x.Hrp + 2][x.Hcp - 3] = i.rocket_draw[1];
			game[x.Hrp + 2][x.Hcp - 4] = 'O';
			a.Bsprite = '<';
		}

		//ammo draw & decrease://
		a.trail = 1;
		a.Btrail[0] = '=';
		a.Btrail[1] = '-';
		a.Btrail[2] = '*';
		a.ammo = i.rocket_ammo;
		if (a.firetrigger == 1 && i.rocket_ammo > 0 && a.dec_ammo == 1)
		{
			a.dec_ammo = 0;
			i.rocket_ammo--;
		}

		//weapon stats://
		a.speed = 3;
		a.damage_multiplier = 4;
	}

	if (x.orientation == 0)
	{
		game[x.Hrp + 2 - x.dir2][x.Hcp - 2 - x.dir] = ' '; //left arm
		game[x.Hrp + 2 - x.dir2][x.Hcp + 4 - x.dir] = ' '; //right arm
		game[x.Hrp + 2][x.Hcp + 4] = x.sprite[17]; //right arm
		game[x.Hrp + 2][x.Hcp - 2] = x.sprite[8]; //left arm
	}
	else
	{
		game[x.Hrp + 2 - x.dir2][x.Hcp + 4 - x.dir] = ' '; //right arm
		game[x.Hrp + 2 - x.dir2][x.Hcp - 2 - x.dir] = ' '; //left arm
		game[x.Hrp + 2][x.Hcp - 2] = x.sprite[17]; //left arm
		game[x.Hrp + 2][x.Hcp + 4] = x.sprite[14]; //right arm
	}
}

void npc(char game[][80], player &x, npcs &z, attack &a)
{
	int ct = 0;
	if (z.NPC_Rand == 1)
	{
		game[z.NPC_rp][z.NPC_cp] = z.Rsprite[0]; //head
		game[z.NPC_rp][z.NPC_cp + 1] = z.Rsprite[1]; //head
		game[z.NPC_rp][z.NPC_cp + 2] = z.Rsprite[2]; //head
		game[z.NPC_rp + 1][z.NPC_cp - 1] = z.Rsprite[3]; //head
		game[z.NPC_rp + 1][z.NPC_cp] = z.Rsprite[4]; //left eye
		game[z.NPC_rp + 1][z.NPC_cp + 1] = z.Rsprite[5]; //mouth
		game[z.NPC_rp + 1][z.NPC_cp + 2] = z.Rsprite[6]; //right eye
		game[z.NPC_rp + 1][z.NPC_cp + 3] = z.Rsprite[7]; //head
		game[z.NPC_rp + 2][z.NPC_cp - 2] = z.Rsprite[8]; //left arm
		game[z.NPC_rp + 2][z.NPC_cp - 1] = z.Rsprite[9]; //body
		game[z.NPC_rp + 2][z.NPC_cp] = z.Rsprite[10]; //body
		game[z.NPC_rp + 2][z.NPC_cp + 1] = z.Rsprite[11]; //body
		game[z.NPC_rp + 2][z.NPC_cp + 2] = z.Rsprite[12]; //body
		game[z.NPC_rp + 2][z.NPC_cp + 3] = z.Rsprite[13]; //body
		game[z.Srp + 2][z.Scp + 4] = z.Rsprite[14]; //right arm
		game[z.NPC_rp + 3][z.NPC_cp] = z.Rsprite[15]; //left leg
		game[z.NPC_rp + 3][z.NPC_cp + 2] = z.Rsprite[16]; //right leg
		game[z.NPC_rp + 3][z.NPC_cp - 3] = z.Rsprite[17]; //thingy
		for (int i = z.NPC_cp - 4; i < z.NPC_cp + 7; i++)
		{
			game[z.NPC_rp - 2][i] = z.interaction4[0 + ct];
			ct++;
		}
	}
	if (z.NPC_En == 1)
	{
		game[z.Erp][z.Ecp] = z.esprite[0]; //head
		game[z.Erp][z.Ecp + 1] = z.esprite[1]; //antenna left
		game[z.Erp][z.Ecp + 2] = z.esprite[2]; //head
		game[z.Erp + 1][z.Ecp - 1] = z.esprite[3]; //head
		game[z.Erp + 1][z.Ecp] = z.esprite[4]; //left eye
		game[z.Erp + 1][z.Ecp + 1] = z.esprite[5]; //mouth
		game[z.Erp + 1][z.Ecp + 2] = z.esprite[6]; //right eye
		game[z.Erp + 1][z.Ecp + 3] = z.esprite[7]; //head
		game[z.Erp + 2][z.Ecp - 2] = z.esprite[8]; //left arm
		game[z.Erp + 2][z.Ecp - 1] = z.esprite[9]; //body
		game[z.Erp + 2][z.Ecp] = z.esprite[10]; //body
		game[z.Erp + 2][z.Ecp + 1] = z.esprite[11]; //body
		game[z.Erp + 2][z.Ecp + 2] = z.esprite[12]; //body
		game[z.Erp + 2][z.Ecp + 3] = z.esprite[13]; //body
		game[z.Erp + 2][z.Ecp + 4] = z.esprite[14]; //right arm
		game[z.Erp + 3][z.Ecp] = z.esprite[15]; //left leg
		game[z.Erp + 3][z.Ecp + 2] = z.esprite[16]; //right leg
		game[z.Erp + 2][z.Ecp - 3] = z.epistol[0];
		game[z.Erp + 2][z.Ecp - 4] = z.epistol[1];
		game[z.Erp + 2][z.Ecp - 5] = z.epistol[2];
		game[z.Erp - 1][z.Ecp - 1] = x.healthbar;
		game[z.Erp - 1][z.Ecp] = x.healthbar;
		game[z.Erp - 1][z.Ecp + 1] = x.healthbar;
		game[z.Erp - 1][z.Ecp + 2] = x.healthbar;
		game[z.Erp - 1][z.Ecp + 3] = x.healthbar;

		//Enemy robot attack stats://
		a.En_speed = 1;
		a.En_damage_multiplier = 60;
		a.En_Bsprite = '<';
		a.En_trail = 1;
		a.En_Btrail[0] = '=';
		a.En_Btrail[1] = '-';
		a.En_Btrail[2] = '*';

		if (z.NPC_En == 1 && a.En_firetrigger == 0 && x.Hcp > 10)
		{
			a.En_b1r = z.Erp + 2;
			a.En_b1c = z.Ecp - 5;
			a.En_firetrigger = 1;
		}
	}
	if (z.En_D == 1)
	{
		//Doggie Enemy
		game[z.Drp][z.Dcp] = z.dsprite[0]; //nose
		game[z.Drp][z.Dcp + 1] = z.dsprite[1]; //face
		game[z.Drp][z.Dcp + 2] = z.dsprite[2]; //ears
		game[z.Drp][z.Dcp + 3] = z.dsprite[3]; //body
		game[z.Drp][z.Dcp + 4] = z.dsprite[4]; //body
		game[z.Drp][z.Dcp + 5] = z.dsprite[5]; //body
		game[z.Drp][z.Dcp + 6] = z.dsprite[6]; //body
		game[z.Drp + 1][z.Dcp + 3] = z.dsprite[7]; //left leg
		//game[z.Drp + 1][z.Dcp + 4] = z.dsprite[8]; (when running)
		game[z.Drp + 1][z.Dcp + 5] = z.dsprite[9]; // right leg
		//game[z.Drp + 1][z.Dcp + 6] = z.dsprite[10]; (when running)
		game[z.Drp - 1][z.Dcp] = x.healthbar;
		game[z.Drp - 1][z.Dcp + 1] = x.healthbar;
		game[z.Drp - 1][z.Dcp + 2] = x.healthbar;
	}
	if (z.En_Sl == 1)
	{
		//Enemy Slime
		game[z.SLrp][z.SLcp + 1] = z.Ssprite[0]; //body
		game[z.SLrp][z.SLcp + 2] = z.Ssprite[1]; //body
		game[z.SLrp][z.SLcp + 3] = z.Ssprite[2]; //body
		game[z.SLrp][z.SLcp + 4] = z.Ssprite[3]; //body
		game[z.SLrp + 1][z.SLcp] = z.Ssprite[4]; //body
		game[z.SLrp + 1][z.SLcp + 1] = z.Ssprite[5]; //left eye
		game[z.SLrp + 1][z.SLcp + 3] = z.Ssprite[6]; //right eye
		game[z.SLrp + 1][z.SLcp + 5] = z.Ssprite[7]; //body
		game[z.SLrp + 2][z.SLcp] = z.Ssprite[8]; //body
		game[z.SLrp + 2][z.SLcp + 1] = z.Ssprite[9]; //body
		game[z.SLrp + 2][z.SLcp + 2] = z.Ssprite[10]; //mouth
		game[z.SLrp + 2][z.SLcp + 3] = z.Ssprite[11]; //body
		game[z.SLrp + 2][z.SLcp + 4] = z.Ssprite[12]; //body
		game[z.SLrp + 2][z.SLcp + 5] = z.Ssprite[13]; //body
		game[z.SLrp + 2][z.SLcp + 6] = z.Ssprite[14]; //body
	}
	if (z.NPC_Shop == 1)
	{
		game[z.Srp][z.Scp] = x.sprite[0]; //head
		game[z.Srp][z.Scp + 1] = x.sprite[1]; //head
		game[z.Srp][z.Scp + 2] = x.sprite[2]; //head
		game[z.Srp + 1][z.Scp - 1] = x.sprite[3]; //head
		game[z.Srp + 1][z.Scp] = x.sprite[4]; //left eye
		game[z.Srp + 1][z.Scp + 1] = x.sprite[5]; //mouth
		game[z.Srp + 1][z.Scp + 2] = x.sprite[6]; //right eye
		game[z.Srp + 1][z.Scp + 3] = x.sprite[7]; //head
		game[z.Srp + 2][z.Scp - 2] = x.sprite[8]; //left arm
		game[z.Srp + 2][z.Scp - 1] = x.sprite[9]; //body
		game[z.Srp + 2][z.Scp] = x.sprite[10]; //body
		game[z.Srp + 2][z.Scp + 1] = x.sprite[11]; //body
		game[z.Srp + 2][z.Scp + 2] = x.sprite[12]; //body
		game[z.Srp + 2][z.Scp + 3] = x.sprite[13]; //body
		game[z.Srp + 2][z.Scp + 4] = x.sprite[14]; //right arm
		game[z.Srp + 3][z.Scp] = x.sprite[15]; //left leg
		game[z.Srp + 3][z.Scp + 2] = x.sprite[16]; //right leg
	}
	if (z.NPC_Rand_terminate == 1)
	{
		game[z.NPC_rp][z.NPC_cp] = ' '; //head
		game[z.NPC_rp][z.NPC_cp + 1] = ' '; //head
		game[z.NPC_rp][z.NPC_cp + 2] = ' '; //head
		game[z.NPC_rp + 1][z.NPC_cp - 1] = ' '; //head
		game[z.NPC_rp + 1][z.NPC_cp] = ' '; //left eye
		game[z.NPC_rp + 1][z.NPC_cp + 1] = ' '; //mouth
		game[z.NPC_rp + 1][z.NPC_cp + 2] = ' '; //right eye
		game[z.NPC_rp + 1][z.NPC_cp + 3] = ' '; //head
		game[z.NPC_rp + 2][z.NPC_cp - 2] = ' '; //left arm
		game[z.NPC_rp + 2][z.NPC_cp - 1] = ' '; //body
		game[z.NPC_rp + 2][z.NPC_cp] = ' '; //body
		game[z.NPC_rp + 2][z.NPC_cp + 1] = ' '; //body
		game[z.NPC_rp + 2][z.NPC_cp + 2] = ' '; //body
		game[z.NPC_rp + 2][z.NPC_cp + 3] = ' '; //body
		game[z.NPC_rp + 2][z.NPC_cp + 4] = ' '; //right arm
		game[z.NPC_rp + 3][z.NPC_cp] = ' '; //left leg
		game[z.NPC_rp + 3][z.NPC_cp + 2] = ' '; //right leg
		game[z.NPC_rp + 3][z.NPC_cp - 3] = ' '; //thingy
		for (int i = z.NPC_cp - 4; i < z.NPC_cp + 7; i++)
		{
			game[z.NPC_rp - 2][i] = ' ';
			ct++;
		}
	}
	if (z.NPC_En_terminate == 1)
	{
		game[z.Erp][z.Ecp] = ' '; //head
		game[z.Erp][z.Ecp + 1] = ' '; //antenna left
		game[z.Erp][z.Ecp + 2] = ' '; //head
		game[z.Erp + 1][z.Ecp - 1] = ' '; //head
		game[z.Erp + 1][z.Ecp] = ' '; //left eye
		game[z.Erp + 1][z.Ecp + 1] = ' '; //mouth
		game[z.Erp + 1][z.Ecp + 2] = ' '; //right eye
		game[z.Erp + 1][z.Ecp + 3] = ' '; //head
		game[z.Erp + 2][z.Ecp - 2] = ' '; //left arm
		game[z.Erp + 2][z.Ecp - 1] = ' '; //body
		game[z.Erp + 2][z.Ecp] = ' '; //body
		game[z.Erp + 2][z.Ecp + 1] = ' '; //body
		game[z.Erp + 2][z.Ecp + 2] = ' '; //body
		game[z.Erp + 2][z.Ecp + 3] = ' '; //body
		game[z.Erp + 2][z.Ecp + 4] = ' '; //right arm
		game[z.Erp + 3][z.Ecp] = ' '; //left leg
		game[z.Erp + 3][z.Ecp + 2] = ' '; //right leg
		game[z.Erp + 2][z.Ecp - 3] = ' ';
		game[z.Erp + 2][z.Ecp - 4] = ' ';
		game[z.Erp + 2][z.Ecp - 5] = ' ';
		game[z.Erp - 1][z.Ecp - 1] = ' ';
		game[z.Erp - 1][z.Ecp] = ' ';
		game[z.Erp - 1][z.Ecp + 1] = ' ';
		game[z.Erp - 1][z.Ecp + 2] = ' ';
		game[z.Erp - 1][z.Ecp + 3] = ' ';
	}
	if (z.En_D_terminate == 1)
	{
		//Doggie Enemy
		game[z.Drp][z.Dcp] = ' ';
		game[z.Drp][z.Dcp + 1] = ' ';
		game[z.Drp][z.Dcp + 2] = ' ';
		game[z.Drp][z.Dcp + 3] = ' ';
		game[z.Drp][z.Dcp + 4] = ' ';
		game[z.Drp][z.Dcp + 5] = ' ';
		game[z.Drp][z.Dcp + 6] = ' ';
		game[z.Drp + 1][z.Dcp + 3] = ' ';
		//game[z.Drp + 1][z.Dcp + 4] = ' ';
		game[z.Drp + 1][z.Dcp + 5] = ' ';
		//game[z.Drp + 1][z.Dcp + 6] = ' ';
	}
	if (z.En_Sl_terminate == 1)
	{
		//Enemy Slime
		game[z.SLrp][z.SLcp + 1] = ' ';
		game[z.SLrp][z.SLcp + 2] = ' ';
		game[z.SLrp][z.SLcp + 3] = ' ';
		game[z.SLrp][z.SLcp + 4] = ' ';
		game[z.SLrp + 1][z.SLcp] = ' ';
		game[z.SLrp + 1][z.SLcp + 1] = ' ';
		game[z.SLrp + 1][z.SLcp + 3] = ' ';
		game[z.SLrp + 1][z.SLcp + 5] = ' ';
		game[z.SLrp + 2][z.SLcp] = ' ';
		game[z.SLrp + 2][z.SLcp + 1] = ' ';
		game[z.SLrp + 2][z.SLcp + 2] = ' ';
		game[z.SLrp + 2][z.SLcp + 3] = ' ';
		game[z.SLrp + 2][z.SLcp + 4] = ' ';
		game[z.SLrp + 2][z.SLcp + 5] = ' ';
		game[z.SLrp + 2][z.SLcp + 6] = ' ';
	}
}

void elv(char lvl[][400], Elevator &e, EnemyNPC l[], player &x)
{
	if (e.trigelv == 1)
	{
		//erase elv
		lvl[e.elvrp + e.elvdir][e.elvcp] = ' ';
		lvl[e.elvrp + e.elvdir][e.elvcp + 1] = ' ';
		lvl[e.elvrp + e.elvdir][e.elvcp + 2] = ' ';
		lvl[e.elvrp + e.elvdir][e.elvcp + 3] = ' ';

		//draw elv
		lvl[e.elvrp][e.elvcp] = e.elvsprite;
		lvl[e.elvrp][e.elvcp + 1] = e.elvsprite;
		lvl[e.elvrp][e.elvcp + 2] = e.elvsprite;
		lvl[e.elvrp][e.elvcp + 3] = e.elvsprite;
	}
}

void elevmove(char game[][80], char lvl[][400], player &x, Elevator &e)
{
	if (e.trigelv != 0)
	{
		if (e.elvstep == 0)
		{
			e.elvdir = 0;
			e.elvcount++;
			if (e.elvcount % 4 == 0)
			{
				if (e.elvrp != 18)
				{
					if (game[x.Hrp + 4][x.Hcp + 2] == '@')
					{
						x.Hrp++, x.dir2 = 1;
					}
					e.elvrp++;
					e.elvdir = 1;
				}
				else
				{
					e.elvstep = 1;
					e.elvcount = 0;
				}
			}
		}
		if (e.elvstep == 1)
		{
			e.elvdir = 0;
			e.elvcount++;
			if (e.elvcount % 4 == 0)
			{
				if (e.elvrp != 9)
				{
					if (game[x.Hrp + 4][x.Hcp + 2] == '@')
					{
						x.Hrp--, x.dir2 = -1;
					}
					e.elvrp--;
					e.elvdir = -1;
				}
				else
				{
					e.elvstep = 2;
					e.elvcount = 1;
				}
			}
		}
		if (e.elvstep == 2)
		{
			e.elvdir = 0;
			e.elvcount++;
			if (e.elvcount % 4 == 0)
			{
				e.elvstep = 3;
				e.elvcount = 0;
			}
		}
		if (e.elvstep == 3)
		{
			e.elvdir = 0;
			e.elvcount++;
			if (e.elvcount % 4 == 0)
			{
				e.elvstep = 4;
				e.elvcount = 0;
			}
		}
		if (e.elvstep == 4)
		{
			e.elvdir = 0;
			e.elvcount++;
			if (e.elvcount % 4 == 0)
			{
				e.elvstep = 0;
				e.elvcount = 1;
			}
		}
	}
}

void setnpc(char game[][80], player &x, npcs &z, attack &a, objects &k)
{
	if (x.level == 1)
	{
		z.NPC_Rand = 1;
	}
	if (x.level == 2)
	{
		z.NPC_Rand_terminate = 1;
		z.NPC_En = 1;
		if (z.NPC_En_terminate == 1)
		{
			x.lvldir = 0;
			x.level++;
			x.reset = 1;
		}
	}
	if (x.level == 3)
	{
		z.NPC_Rand_terminate = 0;
		k.portalcheck = 1;
	}

	if (x.level == 4)
	{
		z.NPC_Rand_terminate = 1;
	}
}

void enemycontrol(char game[][80], player &x, npcs &z, attack &a)
{
	if (a.En_firetrigger == 1 && a.En_b1c != 1 && z.NPC_En_terminate != 1 && z.NPC_En == 1)
	{
		game[a.En_b1r][a.En_b1c] = ' ';
		if (a.En_trail == 1)
		{
			game[a.En_b1r][a.En_b1c + 1] = ' ';
			game[a.En_b1r][a.En_b1c + 2] = ' ';
			game[a.En_b1r][a.En_b1c + 3] = ' ';
			game[a.En_b1r][a.En_b1c + 4] = ' ';
		}
		if (a.En_b1c != 1 && game[a.En_b1r][a.En_b1c - 1] != x.sprite[12])
		{
			a.En_b1c--;
		}
		if (a.En_b1c != 1 && game[a.En_b1r][a.En_b1c - 1] != x.sprite[12] && a.En_speed > 1)
		{
			a.En_b1c--;
		}
		if (a.En_b1c != 1 && game[a.En_b1r][a.En_b1c - 1] != x.sprite[12] && a.En_speed > 2)
		{
			a.En_b1c--;
		}
		game[a.En_b1r][a.En_b1c] = a.En_Bsprite;
		if (a.En_trail == 1)
		{
			game[a.En_b1r][a.En_b1c + 1] = a.En_Btrail[0];
			game[a.En_b1r][a.En_b1c + 2] = a.En_Btrail[0];
			game[a.En_b1r][a.En_b1c + 3] = a.En_Btrail[0];
			game[a.En_b1r][a.En_b1c + 4] = a.En_Btrail[2];
		}
		if (game[a.En_b1r][a.En_b1c - 1] == x.sprite[12])
		{
			x.health -= a.En_damage_multiplier;
			a.En_firetrigger = 0;
			game[a.En_b1r][a.En_b1c] = ' ';
			if (a.En_trail == 1)
			{
				game[a.En_b1r][a.En_b1c + 1] = ' ';
				game[a.En_b1r][a.En_b1c + 2] = ' ';
				game[a.En_b1r][a.En_b1c + 3] = ' ';
				game[a.En_b1r][a.En_b1c + 4] = ' ';
			}
		}
	}
	else
	{
		game[a.En_b1r][a.En_b1c] = ' ';
		if (a.En_trail == 1)
		{
			game[a.En_b1r][a.En_b1c + 1] = ' ';
			game[a.En_b1r][a.En_b1c + 2] = ' ';
			game[a.En_b1r][a.En_b1c + 3] = ' ';
			game[a.En_b1r][a.En_b1c + 4] = ' ';
		}
		a.En_firetrigger = 0;
	}
}

void damage(char game[][80], player &x, npcs &z, attack &a, Bullet b[])
{
	if (z.damage == 1 && z.NPC_En_terminate == 0)
	{
		game[z.Erp - 1][z.Ecp - 1] = ' ';
	}
	if (z.damage == 2 && z.NPC_En_terminate == 0)
	{
		game[z.Erp - 1][z.Ecp - 1] = ' ';
		game[z.Erp - 1][z.Ecp] = ' ';
	}
	if (z.damage == 3 && z.NPC_En_terminate == 0)
	{
		game[z.Erp - 1][z.Ecp - 1] = ' ';
		game[z.Erp - 1][z.Ecp] = ' ';
		game[z.Erp - 1][z.Ecp + 1] = ' ';
	}
	if (z.damage == 4 && z.NPC_En_terminate == 0)
	{
		game[z.Erp - 1][z.Ecp - 1] = ' ';
		game[z.Erp - 1][z.Ecp] = ' ';
		game[z.Erp - 1][z.Ecp + 1] = ' ';
		game[z.Erp - 1][z.Ecp + 2] = ' ';
	}
	if (z.damage >= 5 && z.NPC_En_terminate == 0)
	{
		z.NPC_En_terminate = 1;
		z.NPC_En = 0;
		z.damage = 0;
		x.money += 50;
		x.kills++;
		x.reward = 1;
	}
}

/*void playerattack(char game[][80], player &x, npcs &z, items &i, attack &a)
{
	if (a.firetrigger == 1 && game[a.b1r][a.b1c + 1] != '#' && game[a.b1r][a.b1c - 1] != '#')
	{
		game[a.b1r][a.b1c] = ' ';
		if (a.trail == 1)
		{
			if (x.orientation == 0)
			{
				game[a.b1r][a.b1c - 1] = ' ';
				game[a.b1r][a.b1c - 2] = ' ';
				game[a.b1r][a.b1c - 3] = ' ';
				game[a.b1r][a.b1c - 4] = ' ';
			}
			else
			{
				game[a.b1r][a.b1c + 1] = ' ';
				game[a.b1r][a.b1c + 2] = ' ';
				game[a.b1r][a.b1c + 3] = ' ';
				game[a.b1r][a.b1c + 4] = ' ';
			}
		}
		if (x.orientation == 0)
		{
			if (game[a.b1r][a.b1c + 1] != '#' && game[a.b1r][a.b1c + 1] != z.esprite[12] && game[a.b1r][a.b1c + 1] != z.esprite[4])
			{
				a.b1c++;
			}
		}
		else
		{
			if (game[a.b1r][a.b1c - 1] != '#' && game[a.b1r][a.b1c - 1] != z.esprite[12] && game[a.b1r][a.b1c - 1] != z.esprite[4])
			{
				a.b1c--;
			}
		}
		if (x.orientation == 0)
		{
			if (game[a.b1r][a.b1c + 1] != '#' && game[a.b1r][a.b1c + 1] != z.esprite[12] && game[a.b1r][a.b1c + 1] != z.esprite[4])
			{
				a.b1c++;
			}
		}
		else
		{
			if (game[a.b1r][a.b1c - 1] != '#' && game[a.b1r][a.b1c - 1] != z.esprite[12] && game[a.b1r][a.b1c - 1] != z.esprite[4] && a.speed > 1)
			{
				a.b1c--;
			}
		}
		if (x.orientation == 0)
		{
			if (game[a.b1r][a.b1c + 1] != '#' && game[a.b1r][a.b1c + 1] != z.esprite[12] && game[a.b1r][a.b1c + 1] != z.esprite[4])
			{
				a.b1c++;
			}
		}
		else
		{
			if (game[a.b1r][a.b1c - 1] != '#' && game[a.b1r][a.b1c - 1] != z.esprite[12] && game[a.b1r][a.b1c - 1] != z.esprite[4] && a.speed > 1)
			{
				a.b1c--;
			}
		}
		game[a.b1r][a.b1c] = a.Bsprite;
		if (a.trail == 1)
		{
			if (x.orientation == 0)
			{
				game[a.b1r][a.b1c - 1] = a.Btrail[0];
				game[a.b1r][a.b1c - 2] = a.Btrail[0];
				game[a.b1r][a.b1c - 3] = a.Btrail[0];
				game[a.b1r][a.b1c - 4] = a.Btrail[2];
			}
			else
			{
				game[a.b1r][a.b1c + 1] = a.Btrail[0];
				game[a.b1r][a.b1c + 2] = a.Btrail[0];
				game[a.b1r][a.b1c + 3] = a.Btrail[0];
				game[a.b1r][a.b1c + 4] = a.Btrail[2];
			}
		}
		if (x.orientation == 0)
		{
			if (game[a.b1r][a.b1c + 1] == z.esprite[12] || game[a.b1r][a.b1c + 1] == z.esprite[4])
			{
				a.damage += a.damage_multiplier;
				a.firetrigger = 0;
			}
		}
		else
		{
			if (game[a.b1r][a.b1c - 1] == z.esprite[12] || game[a.b1r][a.b1c - 1] == z.esprite[4])
			{
				a.damage += a.damage_multiplier;
				a.firetrigger = 0;
			}
		}
	}
	else
	{
		game[a.b1r][a.b1c] = ' ';
		if (a.trail == 1)
		{
			if (x.orientation == 0)
			{
				game[a.b1r][a.b1c - 1] = ' ';
				game[a.b1r][a.b1c - 2] = ' ';
				game[a.b1r][a.b1c - 3] = ' ';
				game[a.b1r][a.b1c - 4] = ' ';
			}
			else
			{
				game[a.b1r][a.b1c + 1] = ' ';
				game[a.b1r][a.b1c + 2] = ' ';
				game[a.b1r][a.b1c + 3] = ' ';
				game[a.b1r][a.b1c + 4] = ' ';
			}
		}
		a.firetrigger = 0;
	}
}*/

void pickup(char game[][80], player &x, npcs z, items &i)
{
	int ct = 0, picked = 0;
	if (x.Hcp > 60 && x.Hcp < 80 && x.level == 1)
	{
		x.pickup_trigger = 1;
		for (int i = 65; i < 75; i++)
		{
			game[16][i] = x.pickup_draw[0 + ct];
			ct++;
		}
	}
	if (x.level == 1)
	{
		game[18][70] = i.pistol_draw[0];
		game[18][71] = i.pistol_draw[1];
		game[18][72] = i.pistol_draw[2];
	}
	if (x.pickup == 1)
	{
		picked = 1;
		//pistol = 1;
		i.pistol = 1;
		x.pickup = 0;
	}
	if (picked == 1)
	{
		x.pickup_trigger = 0;
		game[18][70] = ' ';
		game[18][71] = ' ';
		game[18][72] = ' ';
		for (int i = 65; i < 75; i++)
		{
			game[16][i] = ' ';
			ct++;
		}
		if (x.level == 1)
		{
			x.level = 2;
			x.reset = 1;
		}
	}
}

void interact(char game[][80], player &x, npcs z, objects &k)
{
	int ct = 0;
	int ct2 = 0;
	if (x.level == 1)
	{
		if (x.Hcp > 25 && x.Hcp < 50)
		{
			for (int i = z.NPC_cp - 5; i < z.NPC_cp + 7; i++)
			{
				game[z.NPC_rp - 1][i] = x.interact_draw[0 + ct2];
				ct2++;
			}
			for (int i = 15; i < 65; i++)
			{
				game[7][i] = '-';
				game[9][i] = '-';
			}
			game[8][15] = '>';
			if (x.interact == 0)
			{
				for (int i = 17; i < 43; i++)
				{
					game[8][i] = z.interaction1[0 + ct];
					ct++;
				}
			}
			else if (x.interact == 1)
			{
				for (int i = 17; i < 65; i++)
				{
					game[8][i] = z.interaction2[0 + ct];
					ct++;
				}
			}
			else if (x.interact == 2)
			{
				for (int i = 17; i < 46; i++)
				{
					game[8][i] = z.interaction3[0 + ct];
					ct++;
					for (int j = 46; j < 65; j++)
					{
						game[8][j] = ' ';
					}
				}
			}
		}
		else
		{
			x.interact = 0;
			for (int i = z.NPC_cp - 5; i < z.NPC_cp + 7; i++)
			{
				game[z.NPC_rp - 1][i] = ' ';
			}
			for (int i = 15; i < 65; i++)
			{
				game[7][i] = ' ';
			}
			for (int i = 15; i < 65; i++)
			{
				game[9][i] = ' ';
			}
			game[8][15] = ' ';
			for (int i = 15; i < 65; i++)
			{
				game[8][i] = ' ';
				ct++;
			}
		}
	}
	if (x.level == 3)
	{
		if (x.Hcp > 25 && x.Hcp < 50)
		{
			for (int i = z.NPC_cp - 5; i < z.NPC_cp + 7; i++)
			{
				game[z.NPC_rp - 1][i] = x.interact_draw[0 + ct2];
				ct2++;
			}
			for (int i = 15; i < 65; i++)
			{
				game[7][i] = '-';
			}
			for (int i = 15; i < 65; i++)
			{
				game[9][i] = '-';
			}
			game[8][15] = '>';
			if (x.interact == 0)
			{
				for (int i = 17; i < 46; i++)
				{
					game[8][i] = z.interaction6[0 + ct];
					ct++;
				}
			}
			else if (x.interact == 1)
			{
				if (x.reward == 1)
				{
					x.money += 500;
					x.reward = 0;
				}
				for (int i = 17; i < 37; i++)
				{
					game[8][i] = z.interaction7[0 + ct];
					ct++;
				}
				for (int j = 37; j < 65; j++)
				{
					game[8][j] = ' ';
				}
			}
		}
		else
		{
			x.interact = 0;
			for (int i = z.NPC_cp - 5; i < z.NPC_cp + 7; i++)
			{
				game[z.NPC_rp - 1][i] = ' ';
			}
			for (int i = 15; i < 65; i++)
			{
				game[7][i] = ' ';
			}
			for (int i = 15; i < 65; i++)
			{
				game[9][i] = ' ';
			}
			game[8][15] = ' ';
			for (int i = 15; i < 65; i++)
			{
				game[8][i] = ' ';
				ct++;
			}
		}
		if (x.Hcp >= k.portcp - 8)
		{
			ct2 = 0;
			x.portal_trigger = 1;
			for (int i = 68; i < 78; i++)
			{
				game[14][i] = x.portinter_draw[0 + ct2];
				ct2++;
			}
		}
		else
		{
			ct2 = 0;
			x.portal_trigger = 0;
			for (int i = 68; i < 78; i++)
			{
				game[14][i] = ' ';
				ct2++;
			}
		}
	}
}

void jump(player &x, Elevator &e, char game[][80])
{
	if (game[x.Hrp + 4][x.Hcp] != '#' && game[x.Hrp + 4][x.Hcp] != '@')
	{
		if (x.jump_trigger == 0)
		{
			x.gravity++;

			if ((x.gravity %= 2) == 0)
			{
				x.Hrp++, x.dir2 = 1;
			}
		}
		else
		{
			x.gravity = 0;
		}
	}
	else
	{
		x.gravity = 0;
	}
	if (game[x.Hrp - 1][x.Hcp] != '#')
	{
		if (x.jump_trigger == 1)
		{
			x.jump++;

			if (x.jump == 2)
			{
				x.Hrp--, x.dir2 = -1;
			}
			if (x.jump == 4)
			{
				x.Hrp--, x.dir2 = -1;
			}
			if (x.jump == 6)
			{
				x.Hrp--, x.dir2 = -1;
				x.jump_trigger++;
			}
		}
		if (x.jump_trigger == 2)
		{
			x.jump++;
			if (x.jump == 9)
			{
				x.jump_trigger = 0;
				x.jump = 0;
			}

		}
	}
	else
	{
		x.jump_trigger = 0;
	}
}

void setportal(char game[][400], objects &k, player &x)
{

	if (x.portalgo == 1)
	{
		x.portal_trigger = 0;
		k.portalcheck = 0;
		x.portalgo = 0;

		//erase
		game[k.portrp + 1][k.portcp] = ' ';
		game[k.portrp + 2][k.portcp] = ' ';
		game[k.portrp + 3][k.portcp] = ' ';
		game[k.portrp + 1][k.portcp - 1] = ' ';
		game[k.portrp + 2][k.portcp - 1] = ' ';
		game[k.portrp + 3][k.portcp - 1] = ' ';
		game[k.portrp + 1][k.portcp - 2] = ' ';
		game[k.portrp + 2][k.portcp - 2] = ' ';
		game[k.portrp + 3][k.portcp - 2] = ' ';
		game[k.portrp + 1][k.portcp - 3] = ' ';
		game[k.portrp + 2][k.portcp - 3] = ' ';
		game[k.portrp + 3][k.portcp - 3] = ' ';

		x.level++;
		x.reset = 1;
		x.lvldir = 0;
	}


	if (k.portalcheck == 1)
	{
		game[k.portrp + 1][k.portcp] = k.portsprite;
		game[k.portrp + 2][k.portcp] = k.portsprite;
		game[k.portrp + 3][k.portcp] = k.portsprite;
		game[k.portrp + 1][k.portcp - 1] = k.portsprite;
		game[k.portrp + 2][k.portcp - 1] = k.portsprite;
		game[k.portrp + 3][k.portcp - 1] = k.portsprite;
		game[k.portrp + 1][k.portcp - 2] = k.portsprite;
		game[k.portrp + 2][k.portcp - 2] = k.portsprite;
		game[k.portrp + 3][k.portcp - 2] = k.portsprite;
		game[k.portrp + 1][k.portcp - 3] = k.portsprite;
		game[k.portrp + 2][k.portcp - 3] = k.portsprite;
		game[k.portrp + 3][k.portcp - 3] = k.portsprite;
	}
}

void setmap(char map[][80], char lvl[][400], player &x)
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 80; j++)
			map[i][j] = ' ';
	for (int i = 0; i < 80; i++)
		map[0][i] = ' ';
	for (int i = 1; i < 20; i++)
		map[i][0] = '#';
	for (int i = 0; i < 80; i++)
		map[19][i] = '#';
	for (int i = 1; i < 20; i++)
		map[i][79] = '#';
}

void printgame(char map[][80], char lvl[][400], player &x, Elevator &e)
{
	system("cls");

	if (x.death != 1)
	{
		cout << "  FLOOR: " << x.level; cout << "  GOLD: " << x.money; cout << "  KILLED: " << x.kills; cout << "  HP: " << x.health; cout << "  LIVES:"; cout << x.lvldir;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 80; j++)

				cout << map[i][j];
			cout << "\n";
		}
	}
	else
	{
		cout << "You died!";
	}
	cout.flush();
	Sleep(10);
}

int main()
{
	char view[20][80];
	char lvl[20][400];
	player x; npcs z; items i; attack a; objects k;
	Elevator e;
	Doggie d[5]; EnemyNPC l[5]; Bullet b[1000];
	i.pistol_draw[0] = 203; i.pistol_draw[1] = 205; i.pistol_draw[2] = 196;
	i.sword_draw[1] = 196;
	x.healthbar = 03;
	z.Rsprite[4] = 169, z.Rsprite[6] = 170, z.Rsprite[17] = 244;
	z.epistol[0] = 203; z.epistol[1] = 205; z.epistol[2] = 196;
	z.esprite[1] = 203; z.esprite[15] = 244; z.esprite[16] = 244;
	d[1].dsprite[1] = 205, d[1].dsprite[2] = 202, d[1].dsprite[7] = 173, d[1].dsprite[8] = 173, d[1].dsprite[9] = 173, d[1].dsprite[10] = 173;
	d[2].dsprite[1] = 205, d[2].dsprite[2] = 202, d[2].dsprite[7] = 173, d[2].dsprite[8] = 173, d[2].dsprite[9] = 173, d[2].dsprite[10] = 173;
	z.Ssprite[10] = 196;
	setmap(view, lvl, x);
	printgame(view, lvl, x, e);
	for (;;)
	{
		x.dir = 0, x.dir2 = 0;
		for (; !_kbhit();)
		{
			setlevels(view, lvl, x, e, d, l, k);
			setnpc(view, x, z, a, k);
			npc(view, x, z, a);
			for (int j = 0; j < b[0].limiterb; j++)
			{
				b[j].playerattack(view, x, z, l);
			}
			damage(view, x, z, a, b);
			//setportal(lvl, k, x);
			jump(x, e, view);
			elevmove(view, lvl, x, e);
			setplayer(view, x);
			interact(view, x, z, k);
			inventory(view, x, i, a);
			pickup(view, x, z, i);
			elv(lvl, e, l, x);
			printgame(view, lvl, x, e);
			enemycontrol(view, x, z, a);
		}
		char kb = _getch();
		controller(view, kb, x, i, a, e, b);
		setplayer(view, x);
		inventory(view, x, i, a);
		setnpc(view, x, z, a, k);
	}

	system("pause");
	return 0;
}

//fix:
//multi bullets