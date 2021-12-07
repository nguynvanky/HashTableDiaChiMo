#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#define THESHOLD 0.6
int MAXSIZE = 7; // do lon cua bang bam
int count = 0; // so phan tu da duoc them
int maxCount = MAXSIZE * THESHOLD; // so phan tu co the them, neu lon hon thi resize
struct Book {
	char MaSach[5];
	char TenSach[50];
	int Trang;
	float Gia;
};
typedef Book ItemType;
int hashFunction(char* key)
{
	int s = 0;
	int len = strlen(key);
	for (int i = 0; i < len; i++)
		s += (int)key[i];
	return s % MAXSIZE;
}
void initHashtable(ItemType*& hashtable)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		hashtable[i].Trang = -1;
	}
}
void insert(ItemType*& hashtable, ItemType value);

void resize(ItemType*& hashtable)
{
	int old = MAXSIZE;
	MAXSIZE = MAXSIZE * 2;
	maxCount = MAXSIZE * THESHOLD;
	ItemType* NEW = new ItemType[MAXSIZE];
	initHashtable(NEW);
	count = 0;
	for (int i = 0; i < old; i++)
	{
		if (hashtable[i].Trang != -1)
		{
			insert(NEW, hashtable[i]);
		}
	}
	delete hashtable;
	hashtable = NEW;
}
void insert(ItemType*& hashtable, ItemType value)
{

	int id = hashFunction(value.MaSach);
	int res = id;
	int i = 1;
	while (hashtable[id].Trang != -1)
	{
		if (_strcmpi(hashtable[id].MaSach, value.MaSach) == 0) // trung`
		{
			return;
		}
		id = (res + i) % MAXSIZE;
		i++;
	}
	count++;
	hashtable[id] = value;

	if (count >= maxCount)
		resize(hashtable);
}
int search(ItemType*& hashtable, char Ma[])
{
	int id = hashFunction(Ma);
	int res = id;
	int i = 1;
	while (hashtable[id].Trang != -1 && strcmpi(hashtable[id].MaSach, Ma) != 0)
	{
		id = (res + i) % MAXSIZE;
		i++;
	}
	if (strcmpi(hashtable[id].MaSach, Ma) != 0) // khong tim thay
	{
		return -1;
	}
	else
		return id;
}
void nhap(ItemType& value)
{
	std::cin.ignore(); // xoa bo nho dem <=> fflush(stdin)
	printf("Ma sach: ");
	gets_s(value.MaSach);
	printf("Ten sach: ");
	gets_s(value.TenSach);
	printf("So trang: ");
	scanf("%d", &value.Trang);
	printf("Gia: ");
	scanf("%f", &value.Gia);
}
void xuat(ItemType value)
{
	printf("%-10s|%-30s|%-10d|%-10.1f|\n", value.MaSach, value.TenSach, value.Trang, value.Gia);
}
void display(ItemType*& hashtable)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (hashtable[i].Trang != -1)
		{
			printf("\nhashtable[%d] :\n", i);
			xuat(hashtable[i]);
		}
		else
		{
			printf("hashtable[%d] : NULL\n", i);
		}

	}
}
void nhap_File(ItemType*& hashtable)
{
	FILE* f;
	fopen_s(&f, "input.txt", "rt");
	if (!f)
		return;
	ItemType value;
	while (feof(f) == false)
	{
		fscanf(f, "%[^-]-%[^-]-%d-%f\n", &value.MaSach, &value.TenSach, &value.Trang, &value.Gia);
		insert(hashtable, value);
	}
	fclose(f);
}
void menu()
{
	printf("1. Nhap tu file\n");
	printf("2. Nhap 1 sach\n");
	printf("3. In danh sach bang bam\n");
	printf("4. Tim kiem 1 sach\n");
}
int main()
{
	ItemType* hashtable = new ItemType[MAXSIZE];
	ItemType value;
	char x[5];
	int chon,tim;
	initHashtable(hashtable);
	menu();
	do {
		printf("Chon: ");
		scanf("%d", &chon);
		switch (chon)
		{
		case 1:
			nhap_File(hashtable);
			break;
		case 2:
			nhap(value);
			insert(hashtable, value);
			break;
		case 3:
			display(hashtable);
			break;
		case 4:
			std::cin.ignore(); // xoa bo nho dem <=> fflush(stdin)
			printf("Nhap ma sach ban muon tim: ");
			gets_s(x);
			 tim = search(hashtable, x);
			if (tim == -1)
			{
				printf("Khong tim thay\n");
			}
			else
			{
				printf("Tim thay %s trong bang bam\n", x);
				xuat(hashtable[tim]);
			}
			break;
		default:
			break;
		}
	} while (chon != 0);

	_getch();
}