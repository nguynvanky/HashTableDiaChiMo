//#include <iostream>
//#include <stdio.h>
//#define daXoa -99
//int MAXSIZE = 7;
//typedef int ItemType;
//#define THESHOLD 0.6 // nguong cho phep them phan tu
//int size = 0; // so phan tu da them
//
//int maxCount = THESHOLD * MAXSIZE; // so phan tu co the them, neu vuot thi resize
//void resize(ItemType*& bucket);
//int HashFunction(int value)
//{
//	return value % MAXSIZE;
//}
//void menu()
//{
//	printf("1. Them 1 phan tu vao bang bam\n");
//	printf("2. Xuat bang bam\n");
//	printf("3. Resize\n");
//	printf("4. Tim kiem K\n");
//	printf("5. Xoa K\n");
//	printf("0. Thoat");
//}
//void initBucket(ItemType* bucket)
//{
//	for (int i = 0; i < MAXSIZE; i++)
//	{
//		bucket[i] = NULL;
//	}
//}
//int P(int i)
//{
//	return i;
//}
//void insert(ItemType*& bucket, int value)
//{
//	int id = HashFunction(value);
//	int dt = id;
//	int i = 1;
//	if (size > maxCount)
//		resize(bucket);
//	while (bucket[id] != NULL && bucket[id] != daXoa)
//	{
//		if (bucket[id] == value) // trung`
//			return;
//		id = HashFunction(P(i) + dt);
//		i++;
//	}
//	size++;
//	bucket[id] = value;
//}
//void display(ItemType* bucket)
//{
//	for (int i = 0; i < MAXSIZE; i++)
//	{
//		if (bucket[i] != daXoa && bucket[i] != NULL)
//			printf("bucket[%d] = %d\n", i, bucket[i]);
//		else
//		{
//			printf("bucket[%d] = NULL\n", i);
//
//		}
//	}
//}
//int search(ItemType* bucket, int k);
//
//void Delete_K(ItemType*& bucket, int k)
//{
//	int index = search(bucket, k);
//	if (index == -1)
//	{
//		printf("Khong co %d trong bang bam\n", k);
//
//	}
//	else
//	{
//		bucket[index] = daXoa;
//		size--;
//	}
//}
//int search(ItemType* bucket, int k)
//{
//	int b = HashFunction(k);
//	int dt = b;
//	int i = 1;
//	while (bucket[b] != NULL && bucket[b] != k)
//	{
//		b = HashFunction(P(i) + dt);
//		i++;
//	}
//	if (bucket[b] == k)
//		return b;
//	else
//		return -1;
//
//}
//void resize(ItemType*& bucket)
//{
//	int oldMAXSIZE = MAXSIZE;
//	MAXSIZE = MAXSIZE * 2;
//	maxCount = THESHOLD * MAXSIZE;
//	ItemType* NEW = new ItemType[MAXSIZE];
//	initBucket(NEW);
//	size = 0;
//	for (int i = 0; i < oldMAXSIZE; i++)
//	{
//		if (bucket[i] != NULL)
//		{
//			insert(NEW, bucket[i]);
//		}
//	}
//	delete bucket;
//	bucket = NEW;
//}
//int main()
//{
//	int chon, x, k;
//	ItemType* bucket = new ItemType[MAXSIZE];
//	initBucket(bucket);
//	menu();
//	do {
//		printf("\nChon: ");
//		scanf_s("%d", &chon);
//		switch (chon)
//		{
//		case 1:
//			printf("Nhap 1 phan tu: ");
//			scanf_s("%d", &x);
//			insert(bucket, x);
//
//			break;
//		case 2:
//			display(bucket);
//			break;
//		case 3:
//			resize(bucket);
//			break;
//		case 4:
//			printf("k = ");
//			scanf_s("%d", &k);
//			if (search(bucket, k) != -1)
//				printf("Co %d trong bang bam\n", k);
//			else
//				printf("Khong co %d trong bang bam\n", k);
//			break;
//		case 5:
//			printf("k = ");
//			scanf_s("%d", &k);
//			Delete_K(bucket, k);
//			break;
//		default:
//			break;
//		}
//	} while (chon != 0);
//	system("pause");
//	return 0;
//}