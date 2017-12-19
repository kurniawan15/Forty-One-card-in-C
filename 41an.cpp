//Sumber referensi : Pahlevi Ridwan
//Pengembang : 
//PEGA KURNIAWAN (161511060)
//RIZKY BAHTIAR (161511062)
//WILDAN MUHAMMAD (161511066)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define ver 179
#define hor 196
#define panjang 600
#define siku_kiri_atas 218
#define siku_kiri_bawah 192
#define siku_kanan_atas 191
#define siku_kanan_bawah 127


//ASCII Code untuk 3=LOVE 4=TAHU 5=KRITING 6=SKOP

int a[5], b[5], c[5], d[5], B[4], dek[52];
int jdek,temp, i,j,k,dek_sisa,level,player,pemain,menu;

//modul-modul
void tampilan_awal1();
void tampilan_awal2();
void menu_game();
void jenis_kartu(int, char, int, int);
int kursor (int, int, int);
int kursor2 (int, int, int);
void exit();
void gambar_atas();
void menu_nama();
void menu_pemain(); 
void menu_level();
void kartu_both();
void kartu(int ,char ,int , int );
void cetak_kartu_a();
void cetak_kartu_b();
void cetak_kartu_c();
void cetak_kartu_d();
void random();
void bagi_kartu_2();
void bagi_kartu_3();
void bagi_kartu_4();
void cetak_b1(int ,int );
void cetak_b2(int ,int );
void cetak_b3(int ,int );
void cetak_b4(int ,int );
void cetak_hasil(int);
void langkah_pertama_vs1();
void langkah_pertama_vs2();
void langkah_pertama_vs3();
void urut_kartu();
void keputusan_game(int, int);
void gameplay();
void keputusan_player();
void cek_menang(int );
void tampilan_utama(int);
void cetak_hasil(int);
void keputusan_1vs1();
void keputusan_1vs2();
void keputusan_1vs3();
void menang_tak_pasti(int, int, int, int);
void win();
void lose();
void rule();
void about();
void sorting(int,int , int);
void showData(int,int);
int readFile(int, int, int);
void save(int,int,int);
void highscore(int,int);
void draw();
void headscore();
void menuhighscore();
void menuhighscorelevel();

struct skor{
	char nama[31];
	int  nilai;
	int level[2];
};
skor file[40];


//Modul untuk memberi warna ke karakter
void color(int warna)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, warna);
	
}

//Modul Gotoxy
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int main()
{
	system("mode 120,70");
	tampilan_awal1();
	tampilan_awal2();
	getch();
	return 0;
}
//modul ketika tampilan awal saat aplikasi di mulai
void tampilan_awal1(){
	int i=50;
	color(1);
gotoxy(30,31);  printf("     0000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,30);  printf("    000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,29);  printf("   00000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,28);  printf("  0000000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,27);  printf(" 000000000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,26);  printf("00000000000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,25);  printf("00000000000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,24);  printf("00000000000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,23);  printf("00000000000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,22);  printf("00000000000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,21);  printf("00000000000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,20);  printf("00000000000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,19);  printf("00000000000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,18);  printf("00000000000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,17);  printf("00000000000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,16);  printf("00000000000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,15);  printf("00000000000000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,14);  printf(" 000000000000000000000000000000000000000000000  ");Sleep(i);
gotoxy(30,13);   printf("  0000000000000000000000000000000000000000000   ");Sleep(i);
gotoxy(30,12);   printf("   00000000000000000000000000000000000000000    ");Sleep(i);
gotoxy(30,11);   printf("    000000000000000000000000000000000000000     ");Sleep(i);
gotoxy(30,10);   printf("     0000000000000000000000000000000000000      ");Sleep(i);

gotoxy(30,10);  printf("      000000000000000000000000000000000000        ");Sleep(i);
gotoxy(30,11);  printf("     00000000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,12);  printf("    000000    000000000000000000000000000000 ");Sleep(i);
gotoxy(30,13);  printf("   0000000    0000000000000000000000000000000 ");Sleep(i);
gotoxy(30,14);  printf("  00000000    00000000000000000000000000000000 ");Sleep(i);
gotoxy(30,15);  printf(" 000000000    000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,16);  printf(" 000000000    000000000000000000000000000000000 ");Sleep(i);
gotoxy(30,17);  printf("0000000000    00                000000000000000");Sleep(i);
gotoxy(30,18);  printf("0000000000    00                000000000000000");Sleep(i);
gotoxy(30,19);  printf("0000000000    00 00000    00000 000000000000000 ");Sleep(i);
gotoxy(30,20);  printf("000   0000    00000000    000000000000000000000 ");Sleep(i);
gotoxy(30,21);  printf("000           00000000    000000000000000000000 ");Sleep(i);
gotoxy(30,22);  printf("000          000000000    000000000000000000000 ");Sleep(i);
gotoxy(30,23);  printf("0000000000000000000000    00    00000    000000 ");Sleep(i);
gotoxy(30,24);  printf("0000000000000000000000    00    0000    0000000 ");Sleep(i);
gotoxy(30,25);  printf("0000000000000000000000    00    000    00000000 ");Sleep(i);
gotoxy(30,26);  printf("0000000000000000000000    00    0     000000000 ");Sleep(i);
gotoxy(30,27);  printf("0000000000000000000000    00         0000000000 ");Sleep(i);
gotoxy(30,28);  printf("0000000000000000000000000000          000000000 ");Sleep(i);
gotoxy(30,29);  printf("0000000000000000000000000000    000    00000000 ");Sleep(i);
gotoxy(30,30);  printf("0000000000000000000000000000    0000    0000000 ");Sleep(i);
gotoxy(30,31);  printf("0000000000000000000000000000    00000    000000 ");Sleep(i);
gotoxy(30,32);  printf("0000000000000000000000000000    000000    00000 ");Sleep(i);
gotoxy(30,33);  printf(" 000000000000000000000000000    0000000    000   ");Sleep(i);
gotoxy(30,34);  printf("  0000000000000000000000000000000000000000000  ");Sleep(i);
gotoxy(30,35);  printf("   0000000000000000000000000000000000000000 ");
Sleep(i);

//Menghapus tampilan awal
	i=1; j=10;
	while (i<=55)
	{
		gotoxy(76-i,j); printf("    \n");
		gotoxy(76-i,11); printf("    \n");
		gotoxy(76-i,12); printf("    \n");
		gotoxy(76-i,13); printf("    \n");
		gotoxy(76-i,14); printf("    \n");
		gotoxy(76-i,15); printf("    \n");
		gotoxy(76-i,16); printf("    \n");
		gotoxy(76-i,17); printf("    \n");
		gotoxy(76-i,18); printf("    \n");
		gotoxy(76-i,19); printf("    \n");
		gotoxy(76-i,20); printf("    \n");
		gotoxy(76-i,21); printf("    \n");
		gotoxy(76-i,22); printf("    \n");
		gotoxy(76-i,23); printf("    \n");
		gotoxy(76-i,24); printf("    \n");
		gotoxy(76-i,25); printf("    \n");
		gotoxy(76-i,26); printf("    \n");
		gotoxy(76-i,27); printf("    \n");
		gotoxy(76-i,28); printf("    \n");
		gotoxy(76-i,29); printf("    \n");
		gotoxy(76-i,30); printf("    \n");
		gotoxy(76-i,31); printf("    \n");
		gotoxy(76-i,32); printf("    \n");
		gotoxy(76-i,33); printf("    \n");
		gotoxy(76-i,34); printf("    \n");
		gotoxy(76-i,35); printf("    \n");
	
	Sleep(30);
	i++;
	}		
	system("cls");
}

//Modul untuk menampilkan judul game 
void tampilan_awal2 ()
{
	int i,j;
	char tamp_awal;
	char garis = 196;
		i=1;
		j=1;
	system("cls");
	
	
	while (j<=28)
	{
	color(15);	
	gotoxy(j-1,10);printf(" лллллллллллл     ллллл     ллллллллллллллл  ллллллллл \n");
	gotoxy(j-1,11);printf(" ллл             лл   лл    ллл   ллл   ллл  ллл        \n");
	gotoxy(j-1,12);printf(" ллл           ллл     ллл  ллл   ллл   ллл  ллл        \n");
	gotoxy(j-1,13);printf(" ллл  ллллллл  ллллллллллл  ллл   ллл   ллл  ллллллллл \n");
	gotoxy(j-1,14);printf(" ллл      ллл  ллл     ллл  ллл   ллл   ллл  ллл        \n");
	gotoxy(j-1,15);printf(" ллл      ллл  ллл     ллл  ллл   ллл   ллл  ллл        \n");
	gotoxy(j-1,16);printf(" лллллллллллл  ллл     ллл  ллл   ллл   ллл  ллллллллл \n");
		Sleep(25);
	j++;
	
	}
	while(i<=30)
	{	
	color(10);gotoxy (i-1,19);  printf(" ллл    ллл     ллл      ");color(15); printf("  ллллл    лллл    ллл \n");
	color(10);gotoxy(59-i,20);  printf(" ллл    ллл   ллллл      ");color(15); printf(" лл   лл   ллллл   ллл \n");
	color(10);gotoxy (i-1,21);  printf(" ллл    ллл     ллл      ");color(15); printf("ллл   ллл  лллллл  ллл \n");
	color(10);gotoxy(59-i,22);  printf(" лллллллллл     ллл  ллл ");color(15); printf("ллллллллл  ллл ллл ллл \n");
	color(10);gotoxy (i-1,23);  printf("        ллл     ллл      ");color(15); printf("ллл   ллл  ллл  лллллл \n");
	color(10);gotoxy(59-i,24);  printf("        ллл     ллл      ");color(15); printf("ллл   ллл  ллл   ллллл \n");
	color(10);gotoxy (i-1,25);  printf("        ллл     ллл      ");
	color(10);gotoxy(59-i,26);  printf("        ллл   лллллллл===");color(10); printf("====================== \n");
		
		Sleep(50);
		i++;
	}	
	

//Membuat garis garis di atas dan bawah
	i=1;
	while(i<=118)
	{
		color(12);
		gotoxy(i,7); printf("%c",garis);
		gotoxy(117-i,45); printf("%c",garis);
		i++;
		Sleep(10);
	}
//Membuat kartu
	color(240); jenis_kartu(65, 5, 30, 37);
	color(252); jenis_kartu(65, 3, 45, 37);
	color(252); jenis_kartu(65, 4, 60, 37);
	color(240); jenis_kartu(65, 6, 75, 37);
		
//mulai permaina
	color(12);gotoxy(53,32); printf("START GAME");
	color(12);gotoxy(53,33); printf("QUIT GAME\n");
	
	menu=kursor(2,50,32);switch(menu)
	{
case 1:
	//Menghapus judul game
	i=1;
	while (i<=45)
	{
		gotoxy(i-1,10); printf("    \n");
		gotoxy(i-1,11); printf("    \n");
		gotoxy(i-1,12); printf("    \n");
		gotoxy(i-1,13); printf("    \n");
		gotoxy(i-1,14); printf("    \n");
		gotoxy(i-1,15); printf("    \n");
		gotoxy(i-1,16); printf("    \n");
		gotoxy(i-1,17); printf("    \n");
		gotoxy(i-1,18); printf("    \n");
		gotoxy(i-1,19); printf("    \n");
		gotoxy(i-1,20); printf("    \n");
		gotoxy(i-1,21); printf("    \n");
		gotoxy(i-1,22); printf("    \n");
		gotoxy(i-1,23); printf("    \n");
		gotoxy(i-1,24); printf("    \n");
		gotoxy(i-1,25); printf("    \n");
		gotoxy(i-1,26); printf("    \n");

	Sleep(20);
	i++;
	}		
	i=10;
	while (i<=36)
	{
		gotoxy(30,i); printf("                                                                ");
		Sleep(40);
	i++;
	}
	
//menghapus kartu
	i=10;
	while(i<=89)
	{
		gotoxy(i,37); printf(" ");
		gotoxy(i,38); printf(" ");
		gotoxy(i,39); printf(" ");
		gotoxy(i,40); printf(" ");
		gotoxy(i,41); printf(" ");
		gotoxy(i,42); printf(" ");
		Sleep(20);
	i++;
	}
//menghapus Garis
	i=1;
	while(i<=118)
	{
		gotoxy(119-i,7);	printf(" ");
		gotoxy(i,45); 		printf(" ");
		Sleep(10);
	i++;
	}
	system("cls");
	i=1;

 menu_game();break;
case 2: exit();break;
	}
}
//Modul untuk menampilkan Menu pada game 
void menu_game ()
{
system("cls");
	gambar_atas();
	color(15);
	gotoxy(30,20);printf("        ллл    ллл  лллллллллл  ллллллллллллллл  ллллллллл \n");
	gotoxy(30,21);printf("        ллл    ллл  ллл    ллл  ллл   ллл   ллл  ллл        \n");
	gotoxy(30,22);printf("        ллл    ллл  ллл    ллл  ллл   ллл   ллл  ллл        \n");
	gotoxy(30,23);printf("        лллллллллл  ллл    ллл  ллл   ллл   ллл  ллллллллл \n");
	gotoxy(30,24);printf("        ллл    ллл  ллл    ллл  ллл   ллл   ллл  ллл        \n");
	gotoxy(30,25);printf("        ллл    ллл  ллл    ллл  ллл   ллл   ллл  ллл        \n");
	gotoxy(30,26);printf("        ллл    ллл  лллллллллл  ллл   ллл   ллл  ллллллллл \n");

	
	gotoxy(30,31);printf("КллллллллК                   PLAY                     КллллллллК\n");
	gotoxy(30,32);printf("КллллллллК                HOW TO PLAY                 КллллллллК\n");
	gotoxy(30,33);printf("КллллллллК                 HIGH SCORE                 КллллллллК\n");
	gotoxy(30,34);printf("КллллллллК                  ABOUT US                  КллллллллК\n");
	gotoxy(30,35);printf("КллллллллК                    EXIT                    КллллллллК\n");


menu=kursor(5,54,31); switch(menu)
{
	case 1 : menu_pemain();break;
	case 2 : rule(); break;
	case 3 : menuhighscore();break;
	case 4 : about();break;
	case 5 : exit();	
	}
}
//modul mencetak jenis jenis kartu seperti kartu J,q,K dan AS 
void jenis_kartu(int x, char y, int i, int j)
{
		if (x<10 || x>14)
		{
			gotoxy(i,j+1);printf("%c%c%c%c%c%c%c\n",' ',x,' ',' ',' ',' ',' ');
		}
		else
		{
			gotoxy(i,j+1);printf("%c%c%c%c%c%c\n",' ',x,' ',' ',' ',' ');	
		}
		gotoxy(i,j+2);printf("%c%c%c%c%c%c%c\n",' ',' ',' ',' ',' ',' ',' ');
		gotoxy(i,j+3);printf("%c%c%c%c%c%c%c\n",' ',' ',' ',y,' ',' ',' ');
		gotoxy(i,j+4);printf("%c%c%c%c%c%c%c\n",' ',' ',' ',' ',' ',' ',' ');
		if (x<10 || x>14)
		{
			gotoxy(i,j+5);printf("%c%c%c%c%c%c%c\n",' ',' ',' ',' ',' ',x,' ');
		}
		else
		{
			gotoxy(i,j+5);printf("%c%c%c%c%c%c\n",' ',' ',' ',' ',' ',x);	
		}
}
//modul untuk Menampilkan jika memilih tampilan About As pada menu game, modul ini untuk menampilkan identitas bagi pembuat gamenya
void about()
{
	color(14);
	system("cls");
	char hline = 196;
	i=5;
	while (i<=10)
	{
	gotoxy(i-1,2);   printf(" ллллллллллл   лллллллллллл   ллллллллллл    лллл    лллл   лллллллллллллл       лллл    лллл   ллллллллллл \n");
	gotoxy(19-i,3);  printf(" ллллллллллл   лллллллллллл   ллллллллллл    лллл    лллл   лллллллллллллл       лллл    лллл   ллллллллллл \n");
	gotoxy(i-1,4);   printf(" лллл   лллл   лллл   ллллл   лллл   лллл    лллл    лллл        лллл            лллл    лллл   лллллл      \n");
	gotoxy(19-i,5);  printf(" лллл   лллл   лллл   ллллл   лллл   лллл    лллл    лллл        лллл            лллл    лллл   лллллл	     \n");
	gotoxy(i-1,6);   printf(" ллллллллллл   ллллллллллл    лллл   лллл    лллл    лллл        лллл            лллл    лллл   ллллллллллл \n");
	gotoxy(19-i,7);  printf(" ллллллллллл   лллл   ллллл   лллл   лллл    лллл    лллл        лллл            лллл    лллл   ллллллллллл \n");
	gotoxy(i-1,8);   printf(" лллл   лллл   лллл   ллллл   лллл   лллл    лллл    лллл        лллл            лллл    лллл         ллллл \n");
	gotoxy(19-i,9);  printf(" лллл   лллл   лллллллллллл   ллллллллллл    лллллллллллл        лллл            лллллллллллл   ллллллллллл \n");
	gotoxy(i-1,10);  printf(" лллл   лллл   лллллллллллл   ллллллллллл    лллллллллллл        лллл            лллллллллллл   ллллллллллл \n");
		Sleep(85);
	i++;
	}		
	
	// Membuat Garis Atas
	i=10;
	while(i<=54)
	{
		gotoxy(i,15);printf("%c",hline);	gotoxy(124-i,17);	printf("%c",hline);
		gotoxy(i,17);printf("%c",hline);	gotoxy(124-i,15);	printf("%c",hline);
		Sleep(10);
	i++;
	}
	i=10;
	while(i<=50)
	{
		gotoxy(i,16);printf("%c",hline);	gotoxy(124-i,16);	printf("%c",hline);
		Sleep(30);
		i++;
	}
	// Membuat Tulisan Here We Are!
	gotoxy(55,16); printf("T");	Sleep(125); gotoxy(56,16); printf("H");	Sleep(125);
	gotoxy(57,16); printf("I");	Sleep(125);	gotoxy(58,16); printf("S");	Sleep(125);
	gotoxy(59,16); printf(" ");	Sleep(125);	gotoxy(60,16); printf("I");	Sleep(125);
	gotoxy(61,16); printf("S");	Sleep(125);	gotoxy(62,16); printf(" ");	Sleep(125);
	gotoxy(63,16); printf("W");	Sleep(125);	gotoxy(64,16); printf("E");	Sleep(125);
	gotoxy(65,16); printf(" ");	Sleep(125);	gotoxy(66,16); printf("A"); Sleep(125);
	gotoxy(67,16); printf("R");	Sleep(125);	gotoxy(68,16); printf("E"); Sleep(125);
	gotoxy(69,16); printf("!");
	j=1;
	while (j<=5)
	{
		i=10;
		while(i<11)
		{
			switch (j)
			{
			case 2 : gotoxy(i,22);printf(" Member		: \n"); break;
			case 3 : gotoxy(i,28);printf(" class 		: \n"); break;
			case 4 : gotoxy(i,30);printf(" Years 		: \n"); break;
			case 5 : gotoxy(i,32);printf(" Lecturer 		: \n"); break;
			} 
			Sleep(100);
		i++;
		}
	j++;
	}
	
	j=1;
	while (j<=11)
	{
		i=37;
		while (i>35)
		{
			switch(j)
			{
				case 1 : gotoxy(i,20);	  printf("  "); break;
				case 2 : gotoxy(i,22);	  printf(" Pega Kurniawan		161511060 "); break;
				case 3 : gotoxy(i,24);	  printf(" Rizky Bahtiar		161511064 "); break;
				case 4 : gotoxy(i,26);	  printf(" Wildan Muhamad Aqso	161511066 "); break;
				case 5 : gotoxy(i,28);	  printf(" 1B "); break;
				case 6 : gotoxy(i,30);	  printf(" 2016 "); break;
				case 7 : gotoxy(i,32);	  printf(" Santi Sundari, M.T "); break;
				case 8 : gotoxy(i,34);	  printf(" Ade Hodijah "); break;
				case 9 : gotoxy(50,43);   printf(" JURUSAN TEKNIK KOMPUTER "); break;
			}
			Sleep(10); 
		i--;
		}
	j++;
	}
	
	gotoxy(49,39); printf("л"); Sleep(125);
	gotoxy(51,39); printf("D");	Sleep(125); gotoxy(52,39); printf("A");	Sleep(125);
	gotoxy(53,39); printf("S");	Sleep(125);	gotoxy(54,39); printf("A");	Sleep(125);
	gotoxy(55,39); printf("R");	Sleep(125);	gotoxy(56,39); printf(" ");	Sleep(125);
	gotoxy(57,39); printf("-");	Sleep(125);	gotoxy(58,39); printf(" ");	Sleep(125);
	gotoxy(59,39); printf("D");	Sleep(125); gotoxy(60,39); printf("A");	Sleep(125);	
	gotoxy(61,39); printf("S");	Sleep(125); gotoxy(62,39); printf("A");	Sleep(125);	
	gotoxy(63,39); printf("R"); Sleep(125); gotoxy(64,39); printf(" ");	Sleep(125);	
	gotoxy(65,39); printf("P"); Sleep(125); gotoxy(66,39); printf("E");	Sleep(125); 
	gotoxy(67,39); printf("M");	Sleep(125); gotoxy(68,39); printf("R");	Sleep(125);	
	gotoxy(69,39); printf("O");	Sleep(125); gotoxy(70,39); printf("G");	Sleep(125);	
	gotoxy(71,39); printf("R");	Sleep(125); gotoxy(72,39); printf("A");	Sleep(125);	
	gotoxy(73,39); printf("M");	Sleep(125); gotoxy(74,39); printf("A");	Sleep(125);	
	gotoxy(75,39); printf("N");	Sleep(125); gotoxy(76,39); printf(" ");	Sleep(125);
	gotoxy(77,39); printf("л");	
	
	
	gotoxy(35,44);printf(" P O L I T E K N I K   N E G E R I   B A N D U N G \n");
	// Membuat Garis Bawah
	i=10;
	while(i<=114)
	{
		gotoxy(i,45); printf("%c",hline);
		gotoxy(124-i,46); printf("%c",hline);
		Sleep(10);
	i++;
	}
	printf("\n\n\n"); 
	getch();
	menu_game();
}

//Modul exit dari permainan jika di pilih Exit pada menu game , modul ini akan memangil file "exit.txt"
void exit()
{
	color(11);
	system("cls");
FILE *pf;
char data;

	if((pf=fopen("exit.txt","r"))==NULL)
	{
		printf("FAILED. FILE NOT FOUND!!! \n");
	}
	while((data=fgetc(pf))!=EOF)
			putchar(data);
		fclose(pf);
	}

//modul untuk menampilkan aturan game permainan 41an , modul ini akan muncul jika di pilih "how to play" pada menu game. modul ini akan memangil file "Rule.txt"
void rule()
{
	color(13);
	system("cls");
	FILE *f_Rule;	
	char rule[panjang];
	
	f_Rule= fopen("Rule.txt","r");
	
	while ((fgets(rule,panjang,f_Rule)) != NULL)
	printf("%s\r",rule);
	
	fclose(f_Rule);
	getch();
system("cls");
	menu_game();	
}
//modul ini untuk membuat pilihan yang disediakan menjadi kursir tampa mengimput sebuah pilihan dengan arah ke bawah
int kursor(int option, int x, int y)
{
	int select=1;
	int input;
	gotoxy(x,y); printf("%c",16);
	do 
	{
		input=getch();
		if(input==80)
		{
			gotoxy(x,y); printf(" ");
			y++; select++;
			if(select>option)
			{
				y=y-option;
				select=1;
			}
			gotoxy(x,y);printf("%c",16);
		}
		if(input==72)
		{
			gotoxy(x,y); printf(" ");
			y--; select--;
			if (select<1)
			{
				y=y+option;
				select=option;
			}
			gotoxy(x,y); printf("%c",16);
		}
	}
	while(input!=13);
	return select;
}
//modul untuk menanmpilkan tampilan atas pada tampilan menu, pilih pemain, pilih level dan menu pengisisan nama
void gambar_atas()
{	
	color(10);gotoxy(29,9); printf("                                                    ллл               ");
	color(10);gotoxy(29,10);printf("                                                   ллллл              ");
	color(10);gotoxy(29,11);printf("            ллл                                   ллллллл             ");
	color(10);gotoxy(29,12);printf("           ллллл                                 ллллллллл            ");
	color(10);gotoxy(29,13);printf("          ллллллл           лллл     лллл       ллллллллллл           ");
	color(10);gotoxy(29,14);printf("         ллллллллл         лллллл   лллллл     ллллллллллллл          ");
	color(10);gotoxy(29,15);printf("    ллл ллллллллллл ллл   лллллллл лллллллл   ллллллллллллллл         ");
	color(10);gotoxy(29,16);printf("   ллллл ллллллллл ллллл  ллллллллллллллллл  ллллллллллллллллл        ");
	color(10);gotoxy(29,17);printf("  ллллллл ллллллл ллллллл  ллллллллллллллл  ллллллллллллллллллл       ");
	color(10);gotoxy(29,18);printf(" ллллллллл ллллл ллллллллл  ллллллллллллл  лллллллллл лллллллллл      ");
	color(10);gotoxy(29,19);printf("  лллл                                                       ллл     ");
	
	color(15);	
	gotoxy(30,27);printf("ЩЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ\n");
	gotoxy(30,28);printf("КллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллК\n");
	gotoxy(30,29);printf("КллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллК\n");
	gotoxy(30,30);printf("КллллллллЩЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛллллллллК\n");
	gotoxy(30,31);printf("КллллллллК                                            КллллллллК\n");
	
	gotoxy(30,36);printf("КллллллллК                                            КллллллллК\n");
	gotoxy(30,37);printf("КллллллллШЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМллллллллК\n");
	gotoxy(30,38);printf("КллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллК\n");
	gotoxy(30,39);printf("КллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллК\n");
	gotoxy(30,40);printf("ШЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ\n");	
	
}
//modul untuk menampilkan tampilan pengisisan nama setelah game selesai
void menu_nama()
{
	system("cls");
	gambar_atas();
	int posisi=0;
	posisi=readFile(posisi,level,pemain);
	color(15);
	gotoxy(30,20);printf("       ллл     ллл    лллллл    ллллллллллллллл  ллллллллл \n");
	gotoxy(30,21);printf("       лллл    ллл   лл    лл   ллл   ллл   ллл  ллл        \n");
	gotoxy(30,22);printf("       ллллл   ллл  ллл    ллл  ллл   ллл   ллл  ллл        \n");
	gotoxy(30,23);printf("       ллл лл  ллл  лллллллллл  ллл   ллл   ллл  ллллллллл \n");
	gotoxy(30,24);printf("       ллл  лл ллл  ллл    ллл  ллл   ллл   ллл  ллл        \n");
	gotoxy(30,25);printf("       ллл   ллллл  ллл    ллл  ллл   ллл   ллл  ллл        \n");
	gotoxy(30,26);printf("       ллл    лллл  ллл    ллл  ллл   ллл   ллл  ллллллллл \n");

	

	gotoxy(30,32);printf("КллллллллК                PLAYER NAME ?               КллллллллК\n");
	gotoxy(30,33);printf("КллллллллК                                            КллллллллК\n");
	gotoxy(30,34);printf("КллллллллК                                            КллллллллК\n");
	gotoxy(30,35);printf("КллллллллК                                            КллллллллК\n");

	gotoxy(56,34); gets(file[posisi].nama);	
			 fflush(stdin);	 
	file[posisi].nilai=B[0];
	posisi++;
		fflush(stdin);
		sorting(posisi,pemain,level);
	
}
//modul untuk menampilkan pemilihan lawan pemain ketika akan memulai permainan
void menu_pemain()
{
	system("cls");
	gambar_atas();
	color(15);
	gotoxy(28,20);printf("  лллллллллл ллл         лллллл   ллл      ллл лллллллл ллллллл \n");
	gotoxy(28,21);printf("  ллл    ллл ллл        лл    лл   ллл    ллл  ллл      ллл  ллл    \n");
	gotoxy(28,22);printf("  ллл    ллл ллл       ллл    ллл   ллл  ллл   ллл      ллл   ллл    \n");
	gotoxy(28,23);printf("  лллллллллл ллл       лллллллллл    лллллл    лллллллл ллл  ллл      \n");
	gotoxy(28,24);printf("  ллл        ллл       ллл    ллл     ллл      ллл      ллллллл      \n");
	gotoxy(28,25);printf("  ллл        ллл       ллл    ллл     ллл      ллл      ллл  ллл     \n");
	gotoxy(28,26);printf("  ллл        ллллллллл ллл    ллл     ллл      лллллллл ллл    ллл    \n");

	
	
	gotoxy(30,32);printf("КллллллллК                CHOOSE PLAYER :             КллллллллК\n");
	gotoxy(30,33);printf("КллллллллК                  1 vs 1 COM                КллллллллК\n");
	gotoxy(30,34);printf("КллллллллК                  1 vs 2 COM                КллллллллК\n");
	gotoxy(30,35);printf("КллллллллК                  1 vs 3 COM                КллллллллК\n");
	gotoxy(30,36);printf("КллллллллК                 BACK TO MENU               КллллллллК\n");	

	menu=kursor(4,55,33); switch(menu)
	{
		case 1 : 
			pemain=1;
			menu_level(); break;
		case 2 : 
			pemain=2;
			menu_level(); break;
		case 3 :
			pemain=3; 
			menu_level(); break;
		case 4:
			menu_game();
 	}
}
//modul untuk memilih tingkat kesulitan pada game
void menu_level()
{
	//tampilan Pemilihan level permainan
	system("cls");
	gambar_atas();
	color(15);
	gotoxy(30,20);printf("      ллл       ллллллллл  ллл         ллл  ллллллллл ллл \n");
	gotoxy(30,21);printf("      ллл       ллл         ллл       ллл   ллл       ллл \n");
	gotoxy(30,22);printf("      ллл       ллл          ллл     ллл    ллл       ллл \n");
	gotoxy(30,23);printf("      ллл       ллллллллл     ллл   ллл     ллллллллл ллл \n");
	gotoxy(30,24);printf("      ллл       ллл            ллл ллл      ллл       ллл \n");
	gotoxy(30,25);printf("      ллл       ллл             ллллл       ллл       ллл \n");
	gotoxy(30,26);printf("      лллллллл  ллллллллл        ллл        ллллллллл лллллллл \n");

	

	gotoxy(30,32);printf("КллллллллК                CHOOSE LEVEL :              КллллллллК\n");
	gotoxy(30,33);printf("КллллллллК                   EASY                     КллллллллК\n");
	gotoxy(30,34);printf("КллллллллК                   MEDIUM                   КллллллллК\n");
	gotoxy(30,35);printf("КллллллллК                   HARD                     КллллллллК\n");
	gotoxy(30,36);printf("КллллллллК                BACK TO MENU                КллллллллК\n");	

	menu=kursor(4,55,33); switch(menu)
	{
		case 1 : 
			level=1;
			gameplay(); break;
		case 2 : 
			level=2;
			gameplay(); break;
		case 3 :
			level=3; 
			gameplay(); break;
		case 4:
			menu_game();
 	}
}

//modul untuk memulai dan menjalan langkah langkah ketika permainan dimulai
void gameplay()
{
random(); //kartu akan di kocok secara random
//pemabagian kartu kesetiap player
	if (pemain==3){
  		bagi_kartu_4();
  		system("cls");
  		tampilan_utama(pemain);
  		langkah_pertama_vs3();
  	}
    else if (pemain==2){
	 		bagi_kartu_3();
	 		system("cls");
	 		tampilan_utama(pemain);
	 		langkah_pertama_vs2();
		  }
	else{
			bagi_kartu_2();
			system("cls");
			tampilan_utama(pemain);
			langkah_pertama_vs1();
			}
//looping memilih keputusan membuang kartu dan mengambil kartu sampai kondisi menang atw dek habis
	while(jdek<52){
	if (pemain==3){
		if(jdek!=52){
			system("cls");
			tampilan_utama(pemain);
			player=2;
			keputusan_game(level,player);
			cek_menang(player);
		}if(jdek!=52){
			system("cls");
			tampilan_utama(pemain);
			player=3;
			keputusan_game(level,player);
			cek_menang(player);
		}if(jdek!=52){
			system("cls");
			tampilan_utama(pemain);
			player=4;
			keputusan_game(level,player);
			cek_menang(player);
		}if(jdek!=52){
			system("cls");
			tampilan_utama(pemain);
			player=1;
			urut_kartu();
			cetak_kartu_a();
			keputusan_1vs3();
			cek_menang(player);
	}	
}

else if(pemain==2)
{	
	if (jdek!=52){		
		system("cls");
		tampilan_utama(pemain);
		player=3;
		keputusan_game(level, player);
		cek_menang(player);		
	}if (jdek!=52){
		system("cls");
		tampilan_utama(pemain);
		player=4;
		keputusan_game(level, player);
		cek_menang(player);		
	}if (jdek!=52){
		system("cls");
		tampilan_utama(pemain);
		player=1;
		urut_kartu();
		cetak_kartu_a();		
		keputusan_1vs2();
		cek_menang(player);		
		}
}
	else
	{	
if (jdek!=52){
		system("cls");
		tampilan_utama(pemain);
		player=4;
		keputusan_game(level, player);
		cek_menang(player);		
 }if (jdek!=52){
		system("cls");
		tampilan_utama(pemain);
		player=1;
		urut_kartu();
		cetak_kartu_a();		
		keputusan_1vs1();
		cek_menang(player);		
		}
}
}

//ketika permaian sudah mesuk ke kondisi jumlah kartu 41 atw dek habis
	system("cls");
		if (pemain==3){
			tampilan_utama(pemain);
			player=1;		
			cetak_kartu_a();
			cetak_hasil(player);
			printf("\n");
			
			player=2;
			cetak_kartu_b();
			cetak_hasil(player);
			printf("\n");
		
			player=3;
			cetak_kartu_c();
			cetak_hasil(player);
			printf("\n");
			
			player=4;
			cetak_kartu_d();
			cetak_hasil(player);
			printf("\n");
			}
	else if (pemain==2){
	tampilan_utama(pemain);
	player=1;		
		cetak_kartu_a();
		cetak_hasil(player);
		printf("\n");
		
		player=3;
		cetak_kartu_c();
		cetak_hasil(player);
		printf("\n");
		
		player=4;
		cetak_kartu_d();
		cetak_hasil(player);
		printf("\n");
	
				}
			else if (pemain==1){
			tampilan_utama(pemain);
		player=1;		
		cetak_kartu_a();
		cetak_hasil(player);
		printf("\n");
				
		player=4;
		cetak_kartu_d();
		cetak_hasil(player);
		printf("\n");
	
			}
			
	//jika permainan selesai dengan kondisi dek habis maka akan mengecel ke menang tak pasti
		menang_tak_pasti(B[0],B[1],B[2],B[3]);
		printf("______________________________________________________________________________\n\n\n\n");	
		system("pause");
	//setelah game selesai dan sudah mengetahui player mana yang menang kemudian akan masuk ke menu pengisisan nama untuk dimasukan ke high score 
		system("cls");
		menu_nama();
		system("cls");		
		
	//dilanjutkan ke menu pemilihan untuk memainkan game kembali atau mengakhiri game dan keeluar dari aplikasi
color(15);gotoxy(40,20);printf("КллллллллллллллллллллллллллллллллК\n");color(10);
		gotoxy(40,21);printf("КллллЩЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛллллК\n");
		gotoxy(40,22);printf("КллллК                      КллллК\n");
		gotoxy(40,23);printf("КллллК       TRY AGAIN      КллллК\n");
		gotoxy(40,24);printf("КллллК      BACK TO MENU    КллллК\n");
		gotoxy(40,25);printf("КллллК                      КллллК\n");
		gotoxy(40,26);printf("КллллЩЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМллллК\n");
color(15);gotoxy(40,27);printf("КллллллллллллллллллллллллллллллллК\n");
		menu=kursor(2,49,23);	
			switch(menu)
			{
			case 1: 
				menu_pemain();
				break;
			case 2: 
				menu_game();
			}
		}	
		

// Modul Mencetak kartu bernilai dari 1 -10
void kartu(int x,char y,int i, int j)
{
		if (x<10)
		{
			gotoxy(i,j+1);printf("%c%d%c%c%c%c%c\n",' ',x,' ',' ',' ',' ',' ');
		}else
		{
			gotoxy(i,j+1);printf("%c%d%c%c%c%c\n",' ',x,' ',' ',' ',' ');	
		}
		gotoxy(i,j+2);printf("%c%c%c%c%c%c%c\n",' ',' ',' ',' ',' ',' ',' ');
		gotoxy(i,j+3);printf("%c%c%c%c%c%c%c\n",' ',' ',' ',y,' ',' ',' ');
		gotoxy(i,j+4);printf("%c%c%c%c%c%c%c\n",' ',' ',' ',' ',' ',' ',' ');
		if (x<10)
		{
			gotoxy(i,j+5);printf("%c%c%c%c%c%d%c\n",' ',' ',' ',' ',' ',x,' ');
		}
		else
		{
			gotoxy(i,j+5);printf("%c%c%c%c%c%d\n",' ',' ',' ',' ',' ',x);	
		}
}
//modul mencetak kartu pada both
void kartu_both(int i, int j)
{
	gotoxy(i,j);printf("%c%c%c%c%c%c%c%c\n",siku_kiri_atas,hor,hor,hor,hor,hor,hor,siku_kanan_atas);
	gotoxy(i,j+1);printf("%c%c%c%c%c%c%c%c\n",ver,'/','/','/','/','/','/',ver);
	gotoxy(i,j+2);printf("%c%c%c%c%c%c%c%c\n",ver,'/','/','/','/','/','/',ver);
	gotoxy(i,j+3);printf("%c%c%c%c%c%c%c%c\n",ver,'/','/','/','/','/','/',ver);
	gotoxy(i,j+4);printf("%c%c%c%c%c%c%c%c\n",ver,'/','/','/','/','/','/',ver);
	gotoxy(i,j+5);printf("%c%c%c%c%c%c%c%c\n",siku_kiri_bawah,hor,hor,hor,hor,hor,hor,siku_kanan_bawah);
}

//modul membagikan kartu untuk 2 pemain
void bagi_kartu_2()
{
	jdek=8;
	for(i=0; i<4;i++)
	{
		a[i]=dek[i];
		dek[i]=0;
	}
	for(i=4; i<8; i++)
	{
		d[i-4]=dek[i];
		dek[i]=0;	
	}
}
//modul membagikan kartu untuk 3 pemain
void bagi_kartu_3()
{
	jdek=12;
	for(i=0; i<4; i++)
	{
		a[i]=dek[i];
		dek[i]=0;	
	}
	for(i=4;i<8;i++){
		c[i-4]=dek[i];
		dek[i]=0;
	}
	for(i=8;i<12;i++){
			d[i-8]=dek[i];
			dek[i]=0;
	}
}
//modul membagikan kartu untuk 4 pemain
void bagi_kartu_4()
{
	jdek=16;
		for(i=0;i<4;i++){
		
			a[i]=dek[i];
			dek[i]=0;
		}
		for(i=4;i<8;i++){
			b[i-4]=dek[i];
			dek[i]=0;
		}
		for(i=8;i<12;i++){
			c[i-8]=dek[i];
			dek[i]=0;
		}						
		for(i=12;i<16;i++){
			d[i-12]=dek[i];
			dek[i]=0;
		}						
					
}
//modul mencetak kartu player 1
void cetak_kartu_a()
{
for(i=0;i<=4;i++){
	if(a[i]%10==3 || a[i]%10==4)
	{color(252);}
	else if (a[i]%10==0)
	{color(00);}
	else
	{color(240);}
	
	//gotoxy(i,32)
	if(a[i]/10>10){
		if(a[i]/10==11){
			jenis_kartu(74,a[i]%10,(i+2)*10,32);	
		}else if(a[i]/10==12){
			jenis_kartu(75,a[i]%10,(i+2)*10,32);	
		}else if(a[i]/10==13){
			jenis_kartu(81,a[i]%10,(i+2)*10,32);						
		}else if(a[i]/10==14){
			jenis_kartu(65,a[i]%10,(i+2)*10,32);
		}
		else{
				kartu(10,a[i]%10,(i+2)*10,32);
		}				
	}else
	{
		kartu(a[i]/10,a[i]%10,(i+2)*10,32);			
	}
color(7);
gotoxy((i+2)*10,38);printf("Kartu %d",i+1);
}
}
//modul mencetak kartu player 2
void cetak_kartu_b()
{
for(i=0;i<=4;i++){
	if(b[i]%10==3 || b[i]%10==4)
	{color(252);}
	else if (b[i]%10==0)
	{color(00);}
	else
	{color(240);}
	
	//gotoxy(i,32)
	if(b[i]/10>10){
		if(b[i]/10==11){
			jenis_kartu(74,b[i]%10,(i+2)*10,39);	
		}else if(b[i]/10==12){
			jenis_kartu(75,b[i]%10,(i+2)*10,39);	
		}else if(b[i]/10==13){
			jenis_kartu(81,b[i]%10,(i+2)*10,39);						
		}else if(b[i]/10==14){
			jenis_kartu(65,b[i]%10,(i+2)*10,39);
		}
		else{
				kartu(10,b[i]%10,(i+2)*10,39);
		}			
	}else
	{
				kartu(b[i]/10,b[i]%10,(i+2)*10,39);			
	}
color(7);
}
}
//modul mencetak kartu pemain 3
void cetak_kartu_c()
{
for(i=0;i<=4;i++){
	if(c[i]%10==3 || c[i]%10==4)
	{color(252);}
	else if (c[i]%10==0)
	{color(00);}
	else
	{color(240);}
	
	//gotoxy(i,32)
	if(c[i]/10>10){
		if(c[i]/10==11){
			jenis_kartu(74,c[i]%10,(i+2)*10,46);	
		}else if(c[i]/10==12){
			jenis_kartu(75,c[i]%10,(i+2)*10,46);	
		}else if(c[i]/10==13){
			jenis_kartu(81,c[i]%10,(i+2)*10,46);						
		}else if(c[i]/10==14){
			jenis_kartu(65,c[i]%10,(i+2)*10,46);
		}
		else{
				kartu(10,c[i]%10,(i+2)*10,46);
		}				
	}else
	{
		kartu(c[i]/10,c[i]%10,(i+2)*10,46);		
	}
color(7);

}
}
//modul mencetak kartu pemain 4
void cetak_kartu_d()
{
for(i=0;i<=4;i++){
	if(d[i]%10==3 || d[i]%10==4)
	{color(252);}
	else if (d[i]%10==0)
	{color(00);}
	else
	{color(240);}
	
	//gotoxy(i,32)
	if(d[i]/10>10){
		if(d[i]/10==11){
			jenis_kartu(74,d[i]%10,(i+2)*10,53);	
		}else if(d[i]/10==12){
			jenis_kartu(75,d[i]%10,(i+2)*10,53);	
		}else if(d[i]/10==13){
			jenis_kartu(81,d[i]%10,(i+2)*10,53);						
		}else if(d[i]/10==14){
			jenis_kartu(65,d[i]%10,(i+2)*10,53);
		}
		else{
				kartu(10,d[i]%10,(i+2)*10,53);
		}				
	}else
	{
		kartu(d[i]/10,d[i]%10,(i+2)*10,53);			
	}
color(7);
}
}

//Modul Random Kartu
void random(){
	int dekawal[52] = 
  	{
  	23,24,25,26,
	33,34,35,36,
	43,44,45,46,
  	53,54,55,56,
	63,64,65,66,
	73,74,75,76,
  	83,84,85,86,
	93,94,95,96,
	153,154,155,156, // kartu angka 10
  	113,114,115,116,
	123,124,125,126,
	133,134,135,136,
  	143,144,145,146,
  	};
	srand (time(NULL));    
		for(i=0;i<52;i++) //modul untuk merandom	
		{  
		  	do{
		   		j=(rand()% ((52+0) - 0) + 0);
				k=dekawal[j];      		
   			}
			while(k==0);   	
  		dek[i]=k;
  		dekawal[j]=0;  	
  		}
//  	jdek=16;
  	B[0]=0;B[1]=0;B[2]=0;B[3]=0;
}

//modul Tampilan utama saat permaiann di mullai
void tampilan_utama(int pemain)
{
	dek_sisa=52-jdek;
int i;	
printf("	|                             GAME 41-AN                                     |\n");
printf("	|                           1B- JTK POLBAN                                   |\n");
printf("	|____________________________________________________________________________|\n");	
//untuk menampikan kartu both secara di sembunyikan
for(i=1;i<=4;i++)
{
	if(pemain==3)
	{
	kartu_both(10,(((i+2)-1)*4)+1);
	kartu_both((i+1)*10,3);
	kartu_both(70,(((i+2)-1)*4)+1);
	}
	else if(pemain==2)
	{
	kartu_both(10,((i))*5);
	kartu_both(70,((i))*5);
	}
	else
	{
	kartu_both((i+1)*10,3);	
	}
}
//untuk menampilkan kartu trash
if(pemain==3)
{
cetak_b1(40,26);
cetak_b2(20,17);
cetak_b3(40,9);
cetak_b4(60,17);
}
else if(pemain==2)
{
cetak_b1(40,26);
cetak_b3(20,17);
cetak_b4(60,17);
}
else
{
cetak_b1(40,26);
cetak_b4(40,9);
}
kartu_both(40, 17);
gotoxy(38,23);printf("Dek sisa : %d", dek_sisa);
}

//Modul untuk mencetak kartu TRASH 1
void cetak_b1(int i, int j)
{
	if(B[0]%10==3 || B[0]%10==4)
	{color(252);}
	else
	{color(240);}
	//gotoxy(i,32)
		if(B[0]/10>10){
			if(B[0]/10==11){
				jenis_kartu(74,B[0]%10,i,j);
			}else if(B[0]/10==12){
				jenis_kartu(75,B[0]%10,i,j);
			}else if(B[0]/10==13){
				jenis_kartu(81,B[0]%10,i,j);
			}else{
				jenis_kartu(65,B[0]%10,i,j);
			}
	}
	else
	{
		kartu(B[0]/10,B[0]%10,i,j);
	}
	color(7);
}

//Modul untuk mencetak kartu TRASH 2
void cetak_b2(int i, int j)
{
	if(B[1]%10==3 || B[1]%10==4)
	{color(252);}
	else
	{color(240);}
	//gotoxy(i,32)
		if(B[1]/10>10){
			if(B[1]/10==11){
				jenis_kartu(74,B[1]%10,i,j);
			}else if(B[1]/10==12){
				jenis_kartu(75,B[1]%10,i,j);
			}else if(B[1]/10==13){
				jenis_kartu(81,B[1]%10,i,j);
			}else{
				jenis_kartu(65,B[1]%10,i,j);
			}
	}
	else
	{
		kartu(B[1]/10,B[1]%10,i,j);
	}
	color(7);
}


//Modul untuk mencetak kartu TRASH 3
void cetak_b3(int i, int j)
{
	if(B[2]%10==3 || B[2]%10==4)
	{color(252);}
	else
	{color(240);}
	//gotoxy(i,32)
		if(B[2]/10>10){
			if(B[2]/10==11){
				jenis_kartu(74,B[2]%10,i,j);
			}else if(B[2]/10==12){
				jenis_kartu(75,B[2]%10,i,j);
			}else if(B[2]/10==13){
				jenis_kartu(81,B[2]%10,i,j);
			}else{
				jenis_kartu(65,B[2]%10,i,j);
			}
	}
	else
	{
		kartu(B[2]/10,B[2]%10,i,j);
	}
	color(7);
}

//Modul untuk mencetak TRASH 4
void cetak_b4(int i, int j)
{
	if(B[3]%10==3 || B[3]%10==4)
	{color(252);}
	else
	{color(240);}
	//gotoxy(i,32)
		if(B[3]/10>10){
			if(B[3]/10==11){
				jenis_kartu(74,B[3]%10,i,j);
			}else if(B[3]/10==12){
				jenis_kartu(75,B[3]%10,i,j);
			}else if(B[3]/10==13){
				jenis_kartu(81,B[3]%10,i,j);
			}else{
				jenis_kartu(65,B[3]%10,i,j);
			}
	}
	else
	{
		kartu(B[3]/10,B[3]%10,i,j);
	}
	color(7);
}

//Modul untuk menjalankan langkah pertama saat mulai game 1 vs 3
void langkah_pertama_vs3()
{
	char program;
	a[4]=dek[jdek];
	dek[jdek]=0;
	jdek=jdek+1;
	urut_kartu();
	cetak_kartu_a();
	
	
	printf("\n\n______________________________________________________________________________\n");		
	printf("\n\n\n\t\t\t\t *** BUANG KARTU ***");
		menu=kursor2(5,20,39);switch(menu){
			case 1:
				B[1]=a[0];
	    		a[0]=a[1];a[1]=a[2];a[2]=a[3];a[3]=a[4];a[4]=0;  		
				break;
			case 2:
				B[1]=a[1];
	    		a[1]=a[2];a[2]=a[3];a[3]=a[4];a[4]=0;
				break;
			case 3:
				B[1]=a[2];
	    		a[2]=a[3];a[3]=a[4];a[4]=0;
				break;
			case 4:
				B[1]=a[3];
	    		a[3]=a[4];a[4]=0;
				break;
			case 5:
				B[1]=a[4];
				a[4]=0;
				break;	
	}
		}

//Modul untuk menjalankan langkah pertama saat mulai game 1 vs 2
void langkah_pertama_vs2()
{
	char program;
	a[4]=dek[jdek];
	dek[jdek]=0;
	jdek=jdek+1;
	urut_kartu();
	cetak_kartu_a();
	
	
	printf("\n\n______________________________________________________________________________\n");		
	printf("\n\n\n\t\t\t\t *** BUANG KARTU ***");
		menu=kursor2(5,20,39);switch(menu){
			case 1:
				B[2]=a[0];
	    		a[0]=a[1];a[1]=a[2];a[2]=a[3];a[3]=a[4];a[4]=0;  		
				break;
			case 2:
				B[2]=a[1];
	    		a[1]=a[2];a[2]=a[3];a[3]=a[4];a[4]=0;
				break;
			case 3:
				B[2]=a[2];
	    		a[2]=a[3];a[3]=a[4];a[4]=0;
				break;
			case 4:
				B[2]=a[3];
	    		a[3]=a[4];a[4]=0;
				break;
			case 5:
				B[2]=a[4];
				a[4]=0;
				break;	
	}
}
//Modul untuk menjalankan langkah pertama saat mulai game 1 vs 1
void langkah_pertama_vs1()
{
	char program;
	a[4]=dek[jdek];
	dek[jdek]=0;
	jdek=jdek+1;
	urut_kartu();
	cetak_kartu_a();
	
	printf("\n\n______________________________________________________________________________\n");		
	printf("\n\n\n\t\t\t\t *** BUANG KARTU ***");
		menu=kursor2(5,20,39);switch(menu){
			case 1:
				B[3]=a[0];
	    		a[0]=a[1];a[1]=a[2];a[2]=a[3];a[3]=a[4];a[4]=0;  		
				break;
			case 2:
				B[3]=a[1];
	    		a[1]=a[2];a[2]=a[3];a[3]=a[4];a[4]=0;
				break;
			case 3:
				B[3]=a[2];
	    		a[2]=a[3];a[3]=a[4];a[4]=0;
				break;
			case 4:
				B[3]=a[3];
	    		a[3]=a[4];a[4]=0;
				break;
			case 5:
				B[3]=a[4];
				a[4]=0;
				break;	
	}
}
//modul untuk mengurutkan kartu
void urut_kartu()
{
	for(i=0; i<=3; i++){
        for(j=i+1; j<=3; j++){
            if(a[i]/10>a[j]/10){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            if(a[i]%10>a[j]%10){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
			if(a[i]%10>a[j]%10)
			{
				temp = a[i];
                a[i] = a[j];
                a[j] = temp;
			}
        }        
    }
}

int kursor2(int option, int x, int y)
{
	int select=1;
	int input;
	gotoxy(x,y); printf("%c",16);
	do 
	{
		input=getch();
		if(input==77)
		{
			gotoxy(x,y); printf(" ");
			x=x+10; select++;
			if(select>option)
			{
				x=x-(option*10);
				select=1;
			}
			gotoxy(x,y);printf("%c",16);
		}
		if(input==75)
		{
			gotoxy(x,y); printf(" ");
			x=x-10; select--;
			if (select<1)
			{
				x=x+(option*10);
				select=option;
			}
			gotoxy(x,y); printf("%c",16);
		}
	}
	while(input!=13);
	return select;
}

//modul untuk menentukan keputusan ketika menentuka level
void keputusan_game(int level,int player)
{
	int JK_love=0, JK_tahu=0, JK_kri=0, JK_skop=0;
	//Mekanisme Level Easy 
	if (level==1)
	{
		srand (time(NULL));  
		if (player==2)
			{
				b[4]=dek[jdek];
				dek[jdek]=0;
				jdek++;  
		   		
				i=(rand()% 5) + 1;
				B[2]=b[i-1]; 
				b[i-1]=b[4];     								
				b[4]=0;
			}
		if (player==3)
			{
				c[4]=dek[jdek];
				dek[jdek]=0;
				jdek++;
				    
   				j=(rand()% 5) + 1;
				B[3]=c[i-1]; 
				c[i-1]=c[4];
				c[4]=0;     								
				
			}
		if (player==4)
			{
				d[4]=dek[jdek];
				dek[jdek]=0;
				jdek++;
			   
   				k=(rand()% 5) + 1;
				B[0]=d[i-1]; 
				d[i-1]=d[4];     								
				d[4]=0;
			}
	}
	
//Mekanisme jika memilih level medium
	if (level==2)
	{
	if(player==2){//GILIRAN PLAYER-2
		for(i=0; i<=3; i++){
	        for(j=i+1; j<=3; j++){
	            if(b[i]/10>b[j]/10){
	                temp = b[i];
	                b[i] = b[j];
	                b[j] = temp;
	            }
	        }        
	    }		    
	    if(B[1]%10==b[3]%10){	    				
			b[4]=B[1];		
	    		if(b[2]%10!=b[3]%10){
	    			B[2]=b[2];
		    		b[2]=b[3];b[3]=b[4];
					b[4]=0;		
	    		}else if(b[2]%10!=b[3]%10){
	    			B[2]=b[1];
		    		b[1]=b[2];b[2]=b[3];b[3]=b[4];
		    		b[4]=0;					
	    		}else{
	    			B[2]=b[0];
		    		b[0]=b[1];b[1]=b[2];b[2]=b[3];b[3]=b[4];
		    		b[4]=0;					
	    		}
	    		   		   		    	
	    }else{
	    	b[4]=dek[jdek];
	    	dek[jdek]=0;	    	
	    	jdek=jdek+1;
	    	if(b[4]%10==b[3]%10){
	    		if(b[2]%10!=b[3]%10){
	    			B[2]=b[2];
		    		b[2]=b[3];b[3]=b[4];
		    		b[4]=0;										    		
	    		}else if(b[1]%10!=b[3]%10){
	    			B[2]=b[1];
		    		b[1]=b[2];b[2]=b[3];b[3]=b[4];
		    		b[4]=0;									
	    		}
				else{
					B[2]=b[0];
		    		b[0]=b[1];b[1]=b[2];b[2]=b[3];b[3]=b[4];
		    		b[4]=0;					
				}	    			    		
	    	}else{	   	    							    	 		
		    		for(i=0; i<=4; i++){
		        		for(j=i+1; j<=4; j++){
		            		if(b[i]/10>b[j]/10){
			                	temp = b[i];
			                	b[i] = b[j];
		    	            	b[j] = temp;
		            		}
		        		}        
		    		}
				B[2]=b[0];
		    	b[0]=b[1];b[1]=b[2];b[2]=b[3];b[3]=b[4];
		    	b[4]=0;				
	    	}	    	
	    }	    
	}else if(player==3){//GILIRAN PLAYER-3
		for (i=0; i<=3; i++){
	        for (j=i+1; j<=3; j++){
	            if (c[i]/10>c[j]/10){
	                temp = c[i];
	                c[i] = c[j];
	                c[j] = temp;
	            }
	        }        
	    }			
	    if(B[2]%10==c[4]%10){	    				
			c[4]=B[2];		
	    		if(c[2]%10!=c[3]%10){
	    			B[3]=c[2];
		    		c[2]=c[3];c[3]=c[4];
		    		c[4]=0;				
	    		}else if(c[1]%10!=c[3]%10){
	    			B[3]=c[1];
		    		c[2]=c[3];c[3]=c[4];
		    		c[4]=0;						
	    		}
				else{
					B[3]=c[0];
		    		c[0]=c[1];c[1]=c[2];c[2]=c[3];c[3]=c[4];
		    		c[4]=0;					
				}	    		   		   		    	
	    }else{
	    	c[4]=dek[jdek];
	    	dek[jdek]=0;	    	
	    	jdek=jdek+1;
	    	if(c[4]%10==c[3]%10){
	    		if(c[2]%10!=c[3]%10){
	    			B[3]=c[2];
		    		c[2]=c[3];c[3]=c[4];
		    		c[4]=0;										    						
	    		}else if(c[1]%10!=c[3]%10){
	    			B[3]=c[1];
		    		c[1]=c[2];c[2]=c[3];c[3]=c[4];
		    		c[4]=0;					
	    		}
				else{
					B[3]=c[0];
		    		c[0]=c[1];c[1]=c[2];c[2]=c[3];c[3]=c[4];
		    		c[4]=0;					
				}	    			    		
	    	}else{	   	    						    	 		
		    		for(i=0; i<=4; i++){
		        		for(j=i+1; j<=4; j++){
		            		if(c[i]/10>c[j]/10){
			                	temp = c[i];
			                	c[i] = c[j];
		    	            	c[j] = temp;
		            		}
		        		}        
		    		}
				B[3]=c[0];
		    	c[0]=c[1];c[1]=c[2];c[2]=c[3];c[3]=c[4];
		    	c[4]=0;				
	    	}	    	
	    }
	}else{//GILIRAN PLAYER-4
		for (i=0; i<=3; i++){
	        for (j=i+1; j<=3; j++){
	            if (d[i]/10>d[j]/10){
	                temp = d[i];
	                d[i] = d[j];
	                d[j] = temp;
	            }
	        }        
	    }			
	    if(B[3]%10==d[3]%10){	    				
			d[4]=B[3];		
	    		if(d[2]%10!=d[3]%10){
	    			B[0]=d[2];
		    		d[2]=d[3];d[3]=d[4];
		    		d[4]=0;				
	    		}else if(d[1]%10!=d[3]%10){
	    			B[0]=d[1];
		    		d[1]=d[2];d[2]=d[3];d[3]=d[4];
		    		d[4]=0;											
	    		}
				else{
					B[0]=d[0];
		    		d[0]=d[1];d[1]=d[2];d[2]=d[3];d[3]=d[4];
		    		d[4]=0;					
				}
	    }else{
	    	d[4]=dek[jdek];
	    	dek[jdek]=0;	    	
	    	jdek=jdek+1;
	    	if(d[4]%10==d[3]%10){
	    		if(d[2]%10!=d[3]%10){
	    			B[0]=d[2];
		    		d[2]=d[3];d[3]=d[4];
		    		d[4]=0;										    		
	    		}else if(d[1]%10!=d[3]%10){
	    			B[0]=d[1];
		    		d[1]=d[2];d[2]=d[3];d[3]=d[4];
		    		d[4]=0;									
	    		}
				else{
					B[0]=d[0];
		    		d[0]=d[1];d[1]=d[2];d[2]=d[3];d[3]=d[4];
		    		d[4]=0;					
				}	    			    		
	    	}else{	   	    						    	 		
		    		for(i=0; i<=4; i++){
		        		for(j=i+1; j<=4; j++){
		            		if(d[i]/10>d[j]/10){
			                	temp = d[i];
			                	d[i] = d[j];
		    	            	d[j] = temp;
		            		}
		        		}        
		    		}
				B[0]=d[0];
		    	d[0]=d[1];d[1]=d[2];d[2]=d[3];d[3]=d[4];
		    	d[4]=0;				
	    	}	    		
		}
	
	    }
	}
//Mekanisme jika memilih level hard
	if (level==3)
	{
		if (player==2)
	{
	for (i=0;i<4;i++)
	{
		if (b[i]%10==3)
		{
			JK_love=JK_love+b[i]/10;
		}
		else if (b[i]%10==4)
		{
			JK_tahu=JK_tahu+b[i]/10;
		}
		else if (b[i]%10==5)
		{
			JK_kri=JK_kri+b[i]/10;
		}
		else if (b[i]%10==6)
		{
		 	JK_skop=JK_skop+b[i]/10;
	 	}
	}
				for(i=0; i<=3; i++)
				{
	        		for(j=i+1; j<=3; j++)
					{

	            		if(b[i]/10>b[j]/10)
						{
	                		temp = b[i];
	                		b[i] = b[j];
	                		b[j] = temp;
	            		}
	            		if(b[i]%10>b[j]%10)
						{
	                		temp = b[i];
	               			b[i] = b[j];
	                		b[j] = temp;
	           			}
			if(JK_love>JK_tahu && JK_love>JK_kri && JK_love>JK_skop)
				{
			 		if(b[i]%10==3 && b[j]%10!=3)
						{
							temp = b[i];
	                		b[i] = b[j];
	               		 	b[j] = temp;
						}
	        	}
			else if(JK_tahu>JK_love && JK_tahu>JK_kri && JK_tahu>JK_skop)
				{
			 		if(b[i]%10==4 && b[j]%10!=4)
						{
							temp = b[i];
	                		b[i] = b[j];
	               		 	b[j] = temp;
						}
	        	}
			else if(JK_kri>JK_love && JK_kri>JK_tahu && JK_kri>JK_skop)
				{
			 		if(b[i]%10==5 && b[j]%10!=5)
						{
							temp = b[i];
	                		b[i] = b[j];
	               		 	b[j] = temp;
						}
	        	}
			else 
				{
			 		if(b[i]%10==6 && b[j]%10!=6)
						{
							temp = b[i];
	                		b[i] = b[j];
	               		 	b[j] = temp;
						}
	        	}        
	    		}	
			}
			if((b[0]%10!=b[4]%10 && B[1]%10==b[4]%10) || B[1]%10==b[4]%10 && b[0]%10==b[4]%10 && b[0]/10<B[1]/10)
			{
				b[4]=B[1];
				B[2]=b[0];
				b[0]=b[4];
				b[4]=0;
			}
			else
			{
				b[4]=dek[jdek];
				dek[jdek]=0;
				jdek++;
				if((b[0]%10!=b[3]%10 && b[4]%10==b[3]%10) || b[4]%10==b[3]%10 && b[0]%10==b[3]%10 && b[0]/10<b[4]/10)
				{
					B[2]=b[0];
					b[0]=b[4];
					b[4]=0;
				}
				else 
				{
					B[2]=b[4];
					b[4]=0;
				}
			}	
	}
	if (player==3)
	{
		for (i=0;i<4;i++)
	{
		if (c[i]%10==3)
		{
			JK_love=JK_love+c[i]/10;
		}
		else if (c[i]%10==4)
		{
			JK_tahu=JK_tahu+c[i]/10;
		}
		else if (c[i]%10==5)
		{
			JK_kri=JK_kri+c[i]/10;
		}
		else if (c[i]%10==6)
		{
		 	JK_skop=JK_skop+c[i]/10;
	 	}
	}
				for(i=0; i<=3; i++)
				{
	        		for(j=i+1; j<=3; j++)
					{
	            		if(c[i]/10>c[j]/10)
						{
	                		temp = c[i];
	                		c[i] = c[j];
	                		c[j] = temp;
	            		}
	            		if(c[i]%10>c[j]%10)
						{
	                		temp = c[i];
	               			c[i] = c[j];
	                		c[j] = temp;
	           			}
			if(JK_love>JK_tahu && JK_love>JK_kri && JK_love>JK_skop)
				{
			 		if(c[i]%10==3 && c[j]%10!=3)
						{
							temp = c[i];
	                		c[i] = c[j];
	               		 	c[j] = temp;
						}
	        	}
			else if(JK_tahu>JK_love && JK_tahu>JK_kri && JK_tahu>JK_skop)
				{
			 		if(c[i]%10==4 && c[j]%10!=4)
						{
							temp = c[i];
	                		c[i] = c[j];
	               		 	c[j] = temp;
						}
	        	}
			else if(JK_kri>JK_love && JK_kri>JK_tahu && JK_kri>JK_skop)
				{
			 		if(c[i]%10==5 && c[j]%10!=5)
						{
							temp = c[i];
	                		c[i] = c[j];
	               		 	c[j] = temp;
						}
	        	}
			else 
				{
			 		if(c[i]%10==6 && c[j]%10!=6)
						{
							temp = c[i];
	                		c[i] = c[j];
	               		 	c[j] = temp;
						}
	        	}        
	    		}	
			}
			if((c[0]%10!=c[3]%10 && B[2]%10==c[3]%10) || B[2]%10==c[3]%10 && c[0]%10==c[3]%10 && c[0]/10<B[2]/10)
			{
				c[4]=B[2];
				B[3]=c[0];
				c[0]=c[4];
				c[4]=0;
			}
			else
			{
				c[4]=dek[jdek];
				dek[jdek]=0;
				jdek++;
				if((c[0]%10!=c[3]%10 && c[4]%10==c[3]%10) || c[3]%10==c[3]%10 && c[0]%10==c[3]%10 && c[0]/10<c[4]/10)
				{
					B[3]=c[0];
					c[0]=c[4];
					c[4]=0;
				}
				else 
				{
					B[3]=c[4];
					c[4]=0;
				}
			}
	}
	if (player==4)
	{
		for (i=0;i<4;i++)
	{
		if (d[i]%10==3)
		{
			JK_love=JK_love+d[i]/10;
		}
		else if (d[i]%10==4)
		{
			JK_tahu=JK_tahu+d[i]/10;
		}
		else if (d[i]%10==5)
		{
			
			
			
			JK_kri=JK_kri+d[i]/10;
		}
		else if (d[i]%10==6)
		{
		 	JK_skop=JK_skop+d[i]/10;
	 	}
	}
				for(i=0; i<=3; i++)
				{
	        		for(j=i+1; j<=3; j++)
					{
	            		if(d[i]/10>d[j]/10)
						{
	                		temp = d[i];
	                		d[i] = d[j];
	                		d[j] = temp;
	            		}
	            		if(d[i]%10>d[j]%10)
						{
	                		temp = d[i];
	               			d[i] = d[j];
	                		d[j] = temp;
	           			}
			if(JK_love>JK_tahu && JK_love>JK_kri && JK_love>JK_skop)
				{
			 		if(d[i]%10==3 && d[j]%10!=3)
						{
							temp = d[i];
	                		d[i] = d[j];
	               		 	d[j] = temp;
						}
	        	}
			else if(JK_tahu>JK_love && JK_tahu>JK_kri && JK_tahu>JK_skop)
				{
			 		if(d[i]%10==4 && d[j]%10!=4)
						{
							temp = d[i];
	                		d[i] = d[j];
	               		 	d[j] = temp;
						}
	        	}
			else if(JK_kri>JK_love && JK_kri>JK_tahu && JK_kri>JK_skop)
				{
			 		if(d[i]%10==5 && d[j]%10!=5)
						{
							temp = d[i];
	                		d[i] = d[j];
	               		 	d[j] = temp;
						}
	        	}
			else 
				{
			 		if(d[i]%10==6 && d[j]%10!=6)
						{
							temp = d[i];
	                		d[i] = d[j];
	               		 	d[j] = temp;
						}
	        	}        
	    		}	
			}
			if((d[0]%10!=d[3]%10 && B[3]%10==d[3]%10) || B[3]%10==d[3]%10 && d[0]%10==d[3]%10 && d[0]/10<B[3]/10)
			{
				d[4]=B[3];
				B[0]=d[0];
				d[0]=d[4];
				d[4]=0;
			}
			else
			{
				d[4]=dek[jdek];
				dek[jdek]=0;
				jdek++;
				if((d[0]%10!=d[3]%10 && d[4]%10==d[3]%10) || d[4]%10==d[3]%10 && d[0]%10==d[3]%10 && d[0]/10<d[4]/10)
				{
					B[0]=d[0];
					d[0]=d[4];
					d[4]=0;
				}
				else 
				{
					B[0]=d[4];
					d[4]=0;
				}
			}
	}	
	}
}
//Modul untuk menentukan keputusa-keputusan player 1vs 1
void keputusan_1vs1()
{
	char program, menu2;
	
	printf("\n______________________________________________________________________________________\n");
		gotoxy(20,43); printf("AMBIL KARTU :");
		gotoxy(20,45); printf("1. Ambil dari DEK");
		gotoxy(20,46); printf("2. Ambil dari Sampah");
	printf("\n______________________________________________________________________________________\n");
	
	
	menu=kursor(2,18,45);
	switch (menu)
	{
		case 1: program=1;
			a[4]=dek[jdek];
			dek[jdek]=0;
			jdek=jdek+1;
			break;
		case 2: program=2;
			a[4]=B[0];
			B[0]=0;
			break;
	}
		system("cls");
		tampilan_utama(pemain);			
		cetak_kartu_a();
		
//Langkah setelah mengambil kartu maka akan di suruh memilih kartu untuk di buang
printf("\n\n\n___________________________________________________________________________________________\n");
	printf("\t\t\t\t jumlah dek keluar : %d",jdek);
	printf("\n\n\t\t\t\t *** BUANG KARTU ***:");
	menu=kursor2(5,20,39);switch(menu)
	{
		case 1 :
			B[3]=a[0];
			a[0]=a[1]; a[1]=a[2]; a[2]=a[3]; a[3]=a[4];
			a[4]=0;
			break;
		case 2 :
			B[3]=a[1];
			a[1]=a[2]; a[2]=a[3]; a[3]=a[4]; 
			a[4]=0;
			break;
		case 3 :
			B[3]=a[2];
			a[2]=a[3]; a[3]=a[4]; 
			a[4]=0;
			break;
		case 4 :
			B[3]=a[3];
			a[3]=a[4];
			a[4]=0;
			break;
		case 5 :
			B[3]=a[4];
			a[4]=0;
			break;
	}
	
}

//Modul untuk menentukan keputusa-keputusan player 1 vs 2
void keputusan_1vs2()
{

	char program, menu2;
	
	printf("\n______________________________________________________________________________________\n");
		gotoxy(20,43); printf("AMBIL KARTU :");
		gotoxy(20,45); printf("1. Ambil dari DEK");
		gotoxy(20,46); printf("2. Ambil dari Sampah");
	printf("\n______________________________________________________________________________________\n");
	
	
	menu=kursor(2,18,45);
	switch (menu)
	{
		case 1: program=1;
			a[4]=dek[jdek];
			dek[jdek]=0;
			jdek=jdek+1;
			break;
		case 2: program=2;
			a[4]=B[0];
			B[0]=0;
			break;
	}
		system("cls");
		tampilan_utama(pemain);			
		cetak_kartu_a();
		
	//Langkah setelah mengambil kartu maka akan di suruh memilih kartu untuk di buang
	printf("\n\n\n___________________________________________________________________________________________\n");
	printf("\t\t\t\t jumlah dek keluar : %d",jdek);
	printf("\n\n\t\t\t\t *** BUANG KARTU ***:");
	menu=kursor2(5,20,39);switch(menu)
	{
		case 1 :
			B[2]=a[0];
			a[0]=a[1]; a[1]=a[2]; a[2]=a[3]; a[3]=a[4];
			a[4]=0;
			break;
		case 2 :
			B[2]=a[1];
			a[1]=a[2]; a[2]=a[3]; a[3]=a[4]; 
			a[4]=0;
			break;
		case 3 :
			B[2]=a[2];
			a[2]=a[3]; a[3]=a[4]; 
			a[4]=0;
			break;
		case 4 :
			B[2]=a[3];
			a[3]=a[4];
			a[4]=0;
			break;
		case 5 :
			B[2]=a[4];
			a[4]=0;
			break;
	}
		
}

//Modul untuk menentukan keputusa-keputusan player 1 vs 3
void keputusan_1vs3()
{

	char program, menu2;
	
	printf("\n______________________________________________________________________________________\n");
		gotoxy(20,43); printf("AMBIL KARTU :");
		gotoxy(20,45); printf("1. Ambil dari DEK");
		gotoxy(20,46); printf("2. Ambil dari Sampah");
	printf("\n______________________________________________________________________________________\n");
	
	
	menu=kursor(2,18,45);
	switch (menu)
	{
		case 1: program=1;
			a[4]=dek[jdek];
			dek[jdek]=0;
			jdek=jdek+1;
			break;
		case 2: program=2;
			a[4]=B[0];
			B[0]=0;
			break;
	}
		system("cls");
		tampilan_utama(pemain);			
		cetak_kartu_a();
		
	//Langkah setelah mengambil kartu maka akan di suruh memilih kartu untuk di buang
	printf("\n\n\n___________________________________________________________________________________________\n");
	printf("\t\t\t\t jumlah dek keluar : %d",jdek);
	printf("\n\n\t\t\t\t *** BUANG KARTU ***:");
	menu=kursor2(5,20,39);switch(menu)
	{
		case 1 :
			B[1]=a[0];
			a[0]=a[1]; a[1]=a[2]; a[2]=a[3]; a[3]=a[4];
			a[4]=0;
			break;
		case 2 :
			B[1]=a[1];
			a[1]=a[2]; a[2]=a[3]; a[3]=a[4]; 
			a[4]=0;
			break;
		case 3 :
			B[1]=a[2];
			a[2]=a[3]; a[3]=a[4]; 
			a[4]=0;
			break;
		case 4 :
			B[1]=a[3];
			a[3]=a[4];
			a[4]=0;
			break;
		case 5 :
			B[1]=a[4];
			a[4]=0;
			break;
	}
				
}

//modul untuk kondisi menang , kalah atau seri
void cek_menang(int player)
{
	int jml_kr=0,jml_th=0,jml_sk=0,jml_lo=0;	
	if(player==1){
		for(i=0;i<=3;i++){
			if(a[i]/10==15){
				a[i]=a[i]-50;
			}
			if(a[i]%10==3){
			jml_lo=jml_lo+a[i]/10;	
			}else if(a[i]%10==4){
			jml_th=jml_th+a[i]/10;
			}else if(a[i]%10==5){
			jml_kr=jml_kr+a[i]/10;
			}else{
			jml_sk=jml_sk+a[i]/10;
			}
		}
	//karena kondisi dengan julah 41 berlaku bagi angka 10 sehingga kombinasi menang menjadi lebih kompleks
	//karena pada dek AS = 14 , J=11 , Q=12 dan K=13 dan angka 10= 15 , mengapa angka 10 = 15 karena jika angka 10 di beri angka 10 maka hasil yg di dapat
	// bukan jumlah asli dari kartu dan hal tersebut bisa membuat kemenangan
	//sehingga kombinasi agar menang menjadi 50,52,53 dan 54
		if(jml_lo==50 || jml_lo==52 ||jml_lo==53 ||jml_lo==54 ||jml_th==50|| jml_th==52 || jml_th==53 ||jml_th==54 ||jml_kr==50|| jml_kr==52 || jml_kr==53 ||jml_kr==54||jml_sk==50|| jml_sk==52 || jml_sk==53||jml_sk==54){
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("\n______________________________________________________________________________________\n");
			win();
			system("PAUSE");
			jdek=52;
			
		}
	}else if(player==2){
		for(i=0;i<=3;i++){
				if(a[i]/10==15){
				b[i]=b[i]-50;
			}
			if(b[i]%10==3){
			jml_lo=jml_lo+b[i]/10;	
			}else if(b[i]%10==4){
			jml_th=jml_th+b[i]/10;
			}else if(b[i]%10==5){
			jml_kr=jml_kr+b[i]/10;
			}else{
			jml_sk=jml_sk+b[i]/10;
			}
		}
	if(jml_lo==50 || jml_lo==52 ||jml_lo==53 ||jml_lo==54 ||jml_th==50|| jml_th==52 || jml_th==53 ||jml_th==54 ||jml_kr==50|| jml_kr==52 || jml_kr==53 ||jml_kr==54||jml_sk==50|| jml_sk==52 || jml_sk==53||jml_sk==54){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n______________________________________________________________________________________\n");
	 	lose();
	 	printf("\n______________________________________________________________________________________\n");			
			system("PAUSE");
			jdek=52;
		}
	}else if(player==3){
		for(i=0;i<=3;i++){
				if(c[i]/10==15){
				c[i]=c[i]-50;
			}
			if(c[i]%10==3){
			jml_lo=jml_lo+c[i]/10;	
			}else if(c[i]%10==4){
			jml_th=jml_th+c[i]/10;
			}else if(c[i]%10==5){
			jml_kr=jml_kr+c[i]/10;
			}else{
			jml_sk=jml_sk+c[i]/10;
			}
		}
	if(jml_lo==50 || jml_lo==52 ||jml_lo==53 ||jml_lo==54 ||jml_th==50|| jml_th==52 || jml_th==53 ||jml_th==54 ||jml_kr==50|| jml_kr==52 || jml_kr==53 ||jml_kr==54||jml_sk==50|| jml_sk==52 || jml_sk==53||jml_sk==54){
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("\n______________________________________________________________________________________\n");
			lose();
			printf("\n______________________________________________________________________________________\n");
			
			system("PAUSE");
			jdek=52;
		}
	}else{
		for(i=0;i<=3;i++){
				if(d[i]/10==15){
				d[i]=d[i]-50;
			}
			if(d[i]%10==3){
			jml_lo=jml_lo+d[i]/10;	
			}else if(d[i]%10==4){
			jml_th=jml_th+d[i]/10;
			}else if(d[i]%10==5){
			jml_kr=jml_kr+d[i]/10;
			}else{
			jml_sk=jml_sk+d[i]/10;
			}
		}
	if(jml_lo==50 || jml_lo==52 ||jml_lo==53 ||jml_lo==54 ||jml_th==50|| jml_th==52 || jml_th==53 ||jml_th==54 ||jml_kr==50|| jml_kr==52 || jml_kr==53 ||jml_kr==54||jml_sk==50|| jml_sk==52 || jml_sk==53||jml_sk==54){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n______________________________________________________________________________________\n");
		lose();
		printf("\n______________________________________________________________________________________\n");
			
			getch();
			jdek=52;
		}		
	}	
}

void menang_tak_pasti(int b1, int b2, int b3, int b4)
{
	if(b1<b2 || b1<b3 || b1<b4){
	lose();
	}
	else if(b1==b2 || b1==b3 || b1==b4) {
	draw();
	}
	else{
	win();
	}
}

//Modul untuk menghitung dan menampilkan score tiap player
void cetak_hasil(int player)
{
	int jml_kr=0,jml_th=0,jml_sk=0,jml_lo=0;	
	int hasil=0, susunan[4];		
	if(player==1){
	for(i=0;i<4;i++){
		if (a[i]/10==11)
		{
			a[i]=a[i]-10;
		}
		else if (a[i]/10==12)
		{
			a[i]=a[i]-20;
		}
		else if (a[i]/10==13)
		{
			a[i]=a[i]-30;
		}
		else if (a[i]/10==14)
		{
			a[i]=a[i]-30;
		}
		else if(a[i]/10==15){
			a[i]=a[i]-50;
		}
			if(a[i]%10==3){
					jml_lo=jml_lo+a[i]/10;	
			}else if(a[i]%10==4){
					jml_th=jml_th+a[i]/10;
			}else if(a[i]%10==5){
					jml_kr=jml_kr+a[i]/10;
			}else{
					jml_sk=jml_sk+a[i]/10;
				}
		}
	susunan[0]=jml_lo;susunan[1]=jml_th;susunan[2]=jml_kr;susunan[3]=jml_sk;
	
		for(i=0; i<4; i++){
    	    for(j=i+1; j<4; j++){
	            if(susunan[i]/10>susunan[j]/10){
	                temp = susunan[i];
	                susunan[i] = susunan[j];
	                susunan[j] = temp;
	            }
	        }        
	    }
	    hasil=susunan[3]-susunan[2]-susunan[1]-susunan[0];	    
		printf("\n				Player 1  :  %d",hasil);
		B[0]=hasil;
		
	}else if(player==2){
		for(i=0;i<4;i++){
			if (b[i]/10==11)
		{
			b[i]=b[i]-10;
		}
		else if (b[i]/10==12)
		{
			b[i]=b[i]-20;
		}
		else if (b[i]/10==13)
		{
			b[i]=b[i]-30;
		}
		else if (b[i]/10==14)
		{
			b[i]=b[i]-30;
		}
			else if (b[i]/10==15)
		{
			b[i]=b[i]-50;
		}
			if(b[i]%10==3){
				jml_lo=jml_lo+b[i]/10;	
			}else if(b[i]%10==4){
				jml_th=jml_th+b[i]/10;
			}else if(b[i]%10==5){
				jml_kr=jml_kr+b[i]/10;
			}else{
				jml_sk=jml_sk+b[i]/10;
			}
		}		
		susunan[0]=jml_lo;susunan[1]=jml_th;susunan[2]=jml_kr;susunan[3]=jml_sk;
	
		for(i=0; i<4; i++){
    	    for(j=i+1; j<4; j++){
	            if(susunan[i]/10>susunan[j]/10){
	                temp = susunan[i];
	                susunan[i] = susunan[j];
	                susunan[j] = temp;
	            }
	        }        
	    }
	    hasil=susunan[3]-susunan[2]-susunan[1]-susunan[0];	    
		printf("\n				Player 2  :  %d",hasil);
		B[1]=hasil;
		
	}else if(player==3){
		for(i=0;i<4;i++){
		if (c[i]/10==11)
		{
			c[i]=c[i]-10;
		}
		else if (c[i]/10==12)
		{
			c[i]=c[i]-20;
		}
		else if (c[i]/10==13)
		{
			c[i]=c[i]-30;
		}
		else if (c[i]/10==14)
		{
			c[i]=c[i]-30;
		}
			else if (c[i]/10==15)
		{
			c[i]=c[i]-50;
		}
			if(c[i]%10==3){
				jml_lo=jml_lo+c[i]/10;	
			}else if(c[i]%10==4){
				jml_th=jml_th+c[i]/10;
			}else if(c[i]%10==5){
				jml_kr=jml_kr+c[i]/10;
			}else{
				jml_sk=jml_sk+c[i]/10;
			}
		}
		susunan[0]=jml_lo;susunan[1]=jml_th;susunan[2]=jml_kr;susunan[3]=jml_sk;
	
		for(i=0; i<4; i++){
    	    for(j=i+1; j<4; j++){
	            if(susunan[i]/10>susunan[j]/10){
	                temp = susunan[i];
	                susunan[i] = susunan[j];
	                susunan[j] = temp;
	            }
	        }        
	    }
	    hasil=susunan[3]-susunan[2]-susunan[1]-susunan[0];	    
		printf("\n				Player 3  :  %d",hasil);
		B[2]=hasil;
	}	else{
		for(i=0;i<4;i++){
		if (d[i]/10==11)
		{
			d[i]=d[i]-10;
		}
		else if (d[i]/10==12)
		{
			d[i]=d[i]-20;
		}
		else if (d[i]/10==13)
		{
			d[i]=d[i]-30;
		}
		else if (d[i]/10==14)
		{
			d[i]=d[i]-30;
		}
		else if (d[i]/10==15)
		{
			d[i]=d[i]-50;
		}
			if(d[i]%10==3){
				jml_lo=jml_lo+d[i]/10;	
			}else if(d[i]%10==4){
				jml_th=jml_th+d[i]/10;
			}else if(d[i]%10==5){
				jml_kr=jml_kr+d[i]/10;
			}else{
				jml_sk=jml_sk+d[i]/10;
			}
		}
		susunan[0]=jml_lo;susunan[1]=jml_th;susunan[2]=jml_kr;susunan[3]=jml_sk;
	
		for(i=0; i<4; i++){
    	    for(j=i+1; j<4; j++){
	            if(susunan[i]/10>susunan[j]/10){
	                temp = susunan[i];
	                susunan[i] = susunan[j];
	                susunan[j] = temp;
	            }
	        }        
	    }
	    hasil=susunan[3]-susunan[2]-susunan[1]-susunan[0];	    
		printf("\n				Player 4  :  %d",hasil);
		B[3]=hasil;
		
		printf("\n______________________________________________________________________________\n");
	}		
}

void lose()
{
		printf("     ллл     ллл  ллл    ллл    ллл     ллл        ллл     ллллллл ллллллл\n");
		printf("      ллл   ллл лл   лл  ллл    ллл     ллл      лл   лл  лл       ллл    \n");
		printf("       ллл ллл лл     лл ллл    ллл     ллл     лл     лл лл       ллл    \n");
		printf("        ллллл  лл     лл ллл    ллл     ллл     лл     лл  лллллл  ллллллл\n");
		printf("         ллл   лл     лл ллл    ллл     ллл     лл     лл       лл ллл    \n");
		printf("         ллл    лл   лл   ллл  ллл      ллл      лл   лл        лл ллл    \n");
		printf("         ллл      ллл      лллллл       ллллллл    ллл    ллллллл  ллллллл\n");
}
void win()
{
			printf("     ллл     ллл  ллл    ллл    ллл     ллл       ллл ллл ллл   ллл\n");
			printf("      ллл   ллл лл   лл  ллл    ллл     ллл       ллл ллл лллл  ллл\n");
			printf("       ллл ллл лл     лл ллл    ллл     ллл       ллл ллл ллллл ллл\n");
			printf("        ллллл  лл     лл ллл    ллл     ллл ллллл ллл ллл ллллллллл\n");
			printf("         ллл   лл     лл ллл    ллл     лллллл лллллл ллл ллл ллллл\n");
			printf("         ллл    лл   лл   ллл  ллл      ллллл   ллллл ллл ллл  лллл\n");
			printf("         ллл      ллл      лллллл       лллл     лллл ллл ллл   ллл\n");	
}

void draw()
{
			printf("     ллл     ллл  ллл    ллл    ллл     ллллллллллл  ллллллллл  лллллллллл ллл       ллл\n");
			printf("      ллл   ллл лл   лл  ллл    ллл     ллл      ллл ллл   ллл  ллл    ллл ллл       ллл\n");
			printf("       ллл ллл лл     лл ллл    ллл     ллл      ллл ллл   ллл  ллл    ллл ллл       ллл\n");
			printf("        ллллл  лл     лл ллл    ллл     ллл      ллл ллллллллл  лллллллллл ллл ллллл ллл \n");
			printf("         ллл   лл     лл ллл    ллл     ллл      ллл ллл  ллл   ллл    ллл лллллл лллллл\n");
			printf("         ллл    лл   лл   ллл  ллл      ллл      ллл ллл   ллл  ллл    ллл ллллл   ллллл\n");
			printf("         ллл      ллл      лллллл       ллллллллллл  ллл    ллл ллл    ллл лллл     лллл \n");	
}
//mudul menu mengurutkan data berdasarkan NILAI
void sorting (int posisi,int pemain, int level){

	  //prosedur sorting data
	 skor temp;
	 int small; 
	      for(int j=0; j<= (posisi-1); j++)
	        {
	        	small=j;
	          for(int k=(j+1); k<=posisi; k++)
	        	 {
	            if(file[small].nilai<file[k].nilai)  
		        {
		        	small=k;
				}
			  }
	            strcpy(temp.nama, file[j].nama);
	            temp.nilai=file[j].nilai;
	   
	            strcpy(file[j].nama, file[small].nama);
	            file[j].nilai=file[small].nilai;

	            strcpy(file[small].nama, temp.nama);
	            file[small].nilai=temp.nilai;
	            }
	save(posisi,level,pemain);
}

	//modul untuk membaca data dari sebuah file	
int readFile(int posisi,int level,int pemain)
{
	if(pemain==1)
	{
		if(level==1)
		{
		FILE *f = fopen("highscore_1_easy.dat","r");
			while(fscanf(f,"%[^;]; %d\n",file[posisi].nama, &file[posisi].nilai)!=EOF)
			{
				posisi++;
			}
			fclose(f);
			return posisi;

		}
		else if(level==2)
		{
		FILE *f = fopen("highscore_1_medium.dat","r");
			while(fscanf(f,"%[^;]; %d\n",file[posisi].nama, &file[posisi].nilai)!=EOF)
			{
				posisi++;
			}
			fclose(f);
			return posisi;
	
		}
		else
		{
		FILE *f = fopen("highscore_1_hard.dat","r");
			while(fscanf(f,"%[^;]; %d\n",file[posisi].nama, &file[posisi].nilai)!=EOF)
			{
				posisi++;
			}
			fclose(f);
			return posisi;
		}
		
	}	
	else if(pemain==2)
	{
		if(level==1)
		{
		FILE *f = fopen("highscore_2_easy.dat","r");
			while(fscanf(f,"%[^;]; %d\n",file[posisi].nama, &file[posisi].nilai)!=EOF)
			{
				posisi++;
			}
			fclose(f);
			return posisi;

		}
		else if(level==2)
		{
		FILE *f = fopen("highscore_2_medium.dat","r");
			while(fscanf(f,"%[^;]; %d\n",file[posisi].nama, &file[posisi].nilai)!=EOF)
			{
				posisi++;
			}
			fclose(f);
			return posisi;
	
		}
		else
		{
		FILE *f = fopen("highscore_2_hard.dat","r");
			while(fscanf(f,"%[^;]; %d\n",file[posisi].nama, &file[posisi].nilai)!=EOF)
			{
				posisi++;
			}
			fclose(f);
			return posisi;
	}
}
	else
	{
		if(level==1)
		{
		FILE *f = fopen("highscore_3_easy.dat","r");
			while(fscanf(f,"%[^;]; %d\n",file[posisi].nama, &file[posisi].nilai)!=EOF)
			{
				posisi++;
			}
			fclose(f);
			return posisi;

		}
		else if(level==2)
		{
		FILE *f = fopen("highscore_3_medium.dat","r");
			while(fscanf(f,"%[^;]; %d\n",file[posisi].nama, &file[posisi].nilai)!=EOF)
			{
				posisi++;
			}
			fclose(f);
			return posisi;
	
		}
		else
		{
			FILE *f = fopen("highscore_3_hard.dat","r");
			while(fscanf(f,"%[^;]; %d\n",file[posisi].nama, &file[posisi].nilai)!=EOF)
			{
				posisi++;
			}
			fclose(f);
			return posisi;
		}
	
	}
}

	//modul menampilkan data dari sebuah file
void showData(int posisi,int level)
{	
if(level==1)
	{
		printf("\n\n\t\t\t\t\t  *******--- EASY ---*****");

			printf("\n\n\t\t\t\tNO  NAMA PEMAIN \tSCORE \n");
		 for(int i=0; i<posisi; i++){
	 printf("\t\t\t\t\t%-3d %-20s %-8d\n ",i+1, file[i].nama, file[i].nilai);
			}
	}
else if (level==2)
	{
		printf("\n\n\t\t\t\t\t  *******--- MEDIUM ---*****");

			printf("\n\n\t\t\t\t\tNO  NAMA PEMAIN \tSCORE \n");
		 for(int i=0; i<posisi; i++){
	 printf("\t\t\t\t\t%-3d %-20s %-8d\n ",i+1, file[i].nama, file[i].nilai);
			}		
	}
	else
	{
		printf("\n\n\t\t\t\t\t  *******--- HARD ---*****");

			printf("\n\n\t\t\t\t\tNO  NAMA PEMAIN \tSCORE \n");
		 for(int i=0; i<posisi; i++){
	 printf("\t\t\t\t\t%-3d %-20s %-8d\n ",i+1, file[i].nama, file[i].nilai);
	}		
	}
}
//modul menu menambahkan data yang akan disimpan pada file
void save(int posisi, int level, int pemain )
{
	if(pemain==1)
	{
		if(level==1)
		{
			FILE *f = fopen("highscore_1_easy.dat","w");
				for(int i=0; i<posisi; i++){
				fprintf(f,"%s;%d\n",file[i].nama, file[i].nilai);
				}
			  fclose(f);
		}
		else if(level==2)
		{
			FILE *f = fopen("highscore_1_medium.dat","w");
					for(int i=0; i<posisi; i++){
					fprintf(f,"%s;%d\n",file[i].nama, file[i].nilai);
					}
				  fclose(f);	
		}
		else
		{
			FILE *f = fopen("highscore_1_hard.dat","w");
				for(int i=0; i<posisi; i++){
				fprintf(f,"%s;%d\n",file[i].nama, file[i].nilai);
				}
			  fclose(f);
		}
		
	}
	else if(pemain==2)
	{
			if(level==1)
		{
			FILE *f = fopen("highscore_2_easy.dat","w");
				for(int i=0; i<posisi; i++){
				fprintf(f,"%s;%d\n",file[i].nama, file[i].nilai);
				}
			  fclose(f);
		}
		else if(level==2)
		{
			FILE *f = fopen("highscore_2_medium.dat","w");
				for(int i=0; i<posisi; i++){
				fprintf(f,"%s;%d\n",file[i].nama, file[i].nilai);
				}
			  fclose(f);	
		}
		else
		{
			FILE *f = fopen("highscore_2_hard.dat","w");
				for(int i=0; i<posisi; i++){
				fprintf(f,"%s;%d\n",file[i].nama, file[i].nilai);
				}
			  fclose(f);
		}
	}
	else
	{
			if(level==1)
		{
			FILE *f = fopen("highscore_3_easy.dat","w");
				for(int i=0; i<posisi; i++){
				fprintf(f,"%s;%d\n",file[i].nama, file[i].nilai);
				}
			  fclose(f);
		}
		else if(level==2)
		{
			FILE *f = fopen("highscore_3_medium.dat","w");
				for(int i=0; i<posisi; i++){
				fprintf(f,"%s;%d\n",file[i].nama, file[i].nilai);
				}
			  fclose(f);	
		}
		else
		{
			FILE *f = fopen("highscore_3_hard.dat","w");
				for(int i=0; i<posisi; i++){
			fprintf(f,"%s;%d\n",file[i].nama, file[i].nilai);
			}
		  fclose(f);
		}
	}
}
//moful untuk menampilkan highscore berdasarkan level dan banyak pemain yg telah di pilih sebelumnya
void highscore(int pemain, int level)
{
	system("cls");
	int posisi=0;

if (pemain==2)
	{
	 headscore();
gotoxy(25,16); printf("        лллл	                                         лллл");
gotoxy(25,17); printf("        лллл	    лллллл                     лллллл    лллл");
gotoxy(25,18); printf("        лллл	      лл      лл   лл  лллл        лл    лллл");
gotoxy(25,19); printf("        лллл	      лл       лл лл  лл        лллл     лллл");
gotoxy(25,20); printf("        лллл	      лл        ллл     ллл    лл        лллл");
gotoxy(25,21); printf("        лллл	    лллллл       л    лллл     лллллл    лллл");
gotoxy(25,22); printf("        лллл	                                         лллл");
gotoxy(25,23); printf("        лллллллллллллллллллллллллллллллллллллллллллллллллл");

	if(level==1)
	{
			posisi=readFile(posisi, level, pemain);
			showData(posisi,level);
	}
	else if (level==2)
	{
			posisi=readFile(posisi, level, pemain);
			showData(posisi,level);		
	}
	else
	{
			posisi=readFile(posisi, level, pemain);
			showData(posisi,level);		
	}
}
	else if(pemain==3)
	{
		headscore();
gotoxy(25,16);  printf("       лллл                                           лллл");
gotoxy(25,17);  printf("       лллл     лллллл                     лллллл     лллл");
gotoxy(25,18);  printf("       лллл       лл      лл   лл  лллл         лл    лллл");
gotoxy(25,19);  printf("       лллл       лл       лл лл  лл        лллллл    лллл");
gotoxy(25,20);  printf("       лллл       лл        ллл     ллл         лл    лллл");
gotoxy(25,21);  printf("       лллл     лллллл       л    лллл     лллллл     лллл");
gotoxy(25,22);  printf("       лллл                                           лллл");
gotoxy(25,23);  printf("       ллллллллллллллллллллллллллллллллллллллллллллллллллл");
	if(level==1)
	{
			posisi=readFile(posisi, level, pemain);
			showData(posisi,level);
	}
	else if (level==2)
	{
			posisi=readFile(posisi, level, pemain);
			showData(posisi,level);
	}
		else
	{
			posisi=readFile(posisi, level, pemain);
			showData(posisi,level);
	}
}
	else
	{
headscore();
gotoxy(25,16); printf("        лллл	                                         лллл");
gotoxy(25,17); printf("        лллл	    лллллл                     лллллл    лллл");
gotoxy(25,18); printf("        лллл	      лл      лл   лл  лллл      лл      лллл");
gotoxy(25,19); printf("        лллл	      лл       лл лл  лл         лл      лллл");
gotoxy(25,20); printf("        лллл	      лл        ллл     ллл      лл      лллл");
gotoxy(25,21); printf("        лллл	    лллллл       л    лллл     лллллл    лллл");
gotoxy(25,22); printf("        лллл	                                         лллл");
gotoxy(25,23); printf("        лллллллллллллллллллллллллллллллллллллллллллллллллл");
	if(level==1)
	{
			posisi=readFile(posisi, level, pemain);
			showData(posisi,level);
	}
	else if (level==2)
	{
			posisi=readFile(posisi, level, pemain);
			showData(posisi,level);
	}
		else
	{
			posisi=readFile(posisi, level, pemain);
			showData(posisi,level);
	}
 }
 	getch();
 menu_game();

}
//modul untuk menampilkan tampilan atas pada highscore
void headscore()
{

color(10);
gotoxy(10,5);  printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
gotoxy(10,6);  printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
gotoxy(10,7);  printf("        лллл                                                                            лллл");
gotoxy(10,8);  printf("        лллл	  лл   лл лл ллллллл лл   лл     лллллл ллллллл ллллллл ллллллл ллллллл   лллл");
gotoxy(10,9);  printf("        лллл	  лл   лл лл лл      лл   лл     лл     лл      лл   лл лл   лл лл        лллл");
gotoxy(10,10); printf("        лллл	  ллллллл лл лл лллл ллллллл ллл лллллл лл      лл   лл ллллллл ллллллл   лллл");
gotoxy(10,11); printf("        лллл	  лл   лл лл лл   лл лл   лл         лл лл      лл   лл лл  лл  лл        лллл");
gotoxy(10,12); printf("        лллл	  лл   лл лл ллллллл лл   лл     лллллл ллллллл ллллллл лл   лл ллллллл   лллл");
gotoxy(10,13); printf("        лллл                                                                            лллл");
gotoxy(10,14); printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
gotoxy(10,15); printf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
color(15);
}
//modul untuk memilih banyak pemain untuk melihat highscore
void menuhighscore()
{
	system("cls");
	headscore();
	gotoxy(30,16);printf("КллллллллК                                        КллллллллК\n");
	gotoxy(30,17);printf("КллллллллК             Choose Player              КллллллллК\n");
	gotoxy(30,18);printf("КллллллллК                1 vs 1                  КллллллллК\n");
	gotoxy(30,19);printf("КллллллллК                1 vs 2                  КллллллллК\n");
	gotoxy(30,20);printf("КллллллллК                1 vs 3                  КллллллллК\n");
	gotoxy(30,21);printf("КллллллллК             BACK TO MENU               КллллллллК\n");
	gotoxy(30,22);printf("КллллллллллллллллллллллллллллллллллллллллллллллллллллллллллК\n");
	
	menu=kursor(4,52,18); switch(menu) {
	case 1 : pemain=1; 
			 menuhighscorelevel();break;
	case 2 : pemain=2;
			menuhighscorelevel(); break;
	case 3 : pemain=3;
			menuhighscorelevel(); break;
	case 4 : menu_game();break;
	}
}
//modul untuk memilih level untuk melihat highscore
void menuhighscorelevel()
{
	system("cls");
	headscore();
	gotoxy(30,16);printf("КллллллллК                                        КллллллллК\n");
	gotoxy(30,17);printf("КллллллллК             Choose Level               КллллллллК\n");
	gotoxy(30,18);printf("КллллллллК                EASY                    КллллллллК\n");
	gotoxy(30,19);printf("КллллллллК               MEDIUM                   КллллллллК\n");
	gotoxy(30,20);printf("КллллллллК                HARD                    КллллллллК\n");
	gotoxy(30,21);printf("КллллллллК             BACK TO MENU               КллллллллК\n");
	gotoxy(30,22);printf("КллллллллллллллллллллллллллллллллллллллллллллллллллллллллллК\n");
	
	menu=kursor(4,52,18); switch(menu) {
	case 1 : level=1;
			 highscore(pemain,level);break;
	case 2 : level=2;
			 highscore(pemain,level);break;
	case 3 : level=3;
			 highscore(pemain,level);break;
	case 4 : menu_game();break;
	}
}
