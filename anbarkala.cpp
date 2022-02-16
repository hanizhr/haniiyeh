#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include <cstdlib>
#include <stdlib.h>


//structs

struct date {
	int day;
	int month;
	int year;
};

struct item {
	char name[20];
	date expiration_date;
	int count;
	int ID;
	int price;
};

//global variables
item items[10000];
int coant_items = 0;

//functhions
int menu() {
	int i = 0;
	printf("********************WELCOME********************\n");
	printf("\nwhat would you like to do ? inter it's number :\n");
	printf("1.insert new item\n2.search\n3.edit\n4.delete\n5.add\n6.sell\n7.show\n");
	printf("\n*************************************************\n");
	scanf_s("%d", &i);
	return i;
}
void input(item& new_item) {
	printf("name :");
	scanf_s("%s", &new_item.name, 20);
	printf("dd/mm/yyyy : ");
	scanf_s("%d", &new_item.expiration_date.day);
	scanf_s("%d", &new_item.expiration_date.month);
	scanf_s("%d", &new_item.expiration_date.year);
	printf("counts : ");
	scanf_s("%d", &new_item.count);
	printf("price : ");
	scanf_s("%d", &new_item.price);
	new_item.ID = 0;
}

void output(int i) {
	printf("%20s                %4d.%2d.%2d       %5d     %5d     %7d\n", items[i].name, items[i].expiration_date.year, items[i].expiration_date.month, items[i].expiration_date.day, items[i].count, items[i].ID, items[i].price);
}

void insert(item newitem) {
	int i = coant_items;
	strcpy_s(items[i].name, newitem.name);
	items[i].expiration_date = newitem.expiration_date;
	items[i].count = newitem.count;
	items[i].ID = coant_items + 1;
	items[i].price = newitem.price;
	coant_items++;
}
int search_by_name(char new_name[]) {
	int i;
	for (i = 0; i < coant_items; i++) {
		if (strcmp(items[i].name, new_name) == 0) return i;
		else continue;
	}
	return -1;
}
int search_by_id(int new_id) {
	int i;
	int A = 0, Z = (coant_items - 1);
	while (A <= Z) {
		int mid = (A + Z) / 2;
		if (new_id == items[mid].ID) {

			return mid;
		}
		else if (new_id < items[mid].ID) {
			Z = mid - 1;

		}
		else A = mid + 1;
	}
	return -1;
}
void eadit(int id) {
	int i = 0;
	printf("you want eadit what ?\n1.name\n2.expiration date\n3.count\n4.price\n");
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		char newname[20];
		printf("new name :\n");
		scanf_s("%s", newname, 20);
		strcpy_s(items[id].name, newname);
		break;
	case 2:
		printf("new :dd/mm/yyyy\n");
		scanf_s("%d %d %d", &items[id].expiration_date.day, &items[id].expiration_date.month, &items[id].expiration_date.year);
		break;
	case 3:
		printf("new counts :\n");
		scanf_s("%d", &items[id].count);
		break;
	case 4:
		printf("new price :\n");
		scanf_s("%d", &items[id].price);
		break;
	default:
		break;
	}
}
void delet(int id) {
	for (int k = id; k < coant_items - 1; k++) {
		items[k].count = items[k + 1].count;
		items[k].expiration_date = items[k + 1].expiration_date;
		items[k].ID = items[k + 1].ID;
		items[k].price = items[k + 1].price;
		strcpy_s(items[k].name, items[k + 1].name);
	}
	coant_items--;
}
void sell(int id) {
	int i = 0, n;
	printf("\nhow mene/much you sell? \n");
	scanf_s("%d", &n);
	for (i; i < n; i++)
		items[id].count--;
}
void CleenScreen() {
	for (int i = 0; i < 100; i++) {
		printf("\n");
	}
}
//main
int main() {
	int count_new_item, i, id, item_menu, ch, j;
	char name[20];
	item new_item[2000], new_items;
	date today;
	printf("inter today's date : (format:dd/mm/yyyy)\n");
	scanf_s("%d %d %d", &today.day, &today.month, &today.year);

	//اقلام قبلی موجود در انبار
	items[0] = { "chips",24,9,1400,10,1 ,6500 }; coant_items++;
	items[1] = { "tea",01,8,1401,0,2,15000 }; coant_items++;
	items[2] = { "glass",11,9,1111,100,3,60000 }; coant_items++;
	items[3] = { "pencel_blue",11,11,1111,150,4,3000 }; coant_items++;
	items[4] = { "pencel_red",11,11,1111,0,5,3000 }; coant_items++;
	items[5] = { "watter",20,01,1401,53,6,2000 }; coant_items++;
	//***********************************************************************
	do {
		CleenScreen();
		item_menu = menu();
		switch (item_menu)
		{
		case 1: //insert new item
			input(new_items);
			insert(new_items);
			printf("***one item's insert***\n");
			break;
		case 2: //search
			printf("would you like to search by name or id ? \n");
			printf("1.name\n2.id\n");
			scanf_s("%d", &i);
			switch (i)
			{
			case 1:printf("inter item's name for search :");
				scanf_s("%s", &name, 20);
				i = search_by_name(name);
				if (i == -1) printf(" not exist\n");
				else printf("it is foand wit id: %d\n", i + 1);
				break;
			case 2:	printf("inter item's ID for search :");
				scanf_s("%d", &id);
				i = search_by_id(id);
				if (i == -1) printf(" not exist\n");
				else printf("it is foand wit name: %s\n", items[i].name);
				break;
			default:
				break;
			}
			break;
		case 3://eadit
			printf("inter item's id for EDIT :\n");
			scanf_s("%d", &j);
			printf("--------------------------------------------------------------------------------\n");
			printf("       Name                        Expiration Date     Count      ID       price\n");
			output(j - 1);
			printf("--------------------------------------------------------------------------------\n");
			eadit((j - 1));
			printf("****eadit is done****\n");
			printf("--------------------------------------------------------------------------------\n");
			printf("       Name                        Expiration Date     Count      ID       price\n");
			output(j - 1);
			printf("--------------------------------------------------------------------------------\n");
			break;
		case 4://delet
			printf("inter item's id for DELET :\n");
			scanf_s("%d", &j);
			delet((j - 1));
			printf("****delet is done****");
			break;
		case 5://add or buy
			printf("How many new ITEM do you want to add ? \n");
			scanf_s("%d", &count_new_item);
			i = 0;
			while (i < count_new_item)
			{
				input(new_item[i]);
				i++;
			}

			for (int j = 0; j < count_new_item; j++) {
				int sw = 0;
				for (int i = 0; i < coant_items; i++) {
					if (strcmp(new_item[j].name, items[i].name) == 0) {
						sw = 1;
						items[i].count += new_item[j].count;
						if (new_item[j].price > items[i].price) items[i].price = new_item[j].price;
						if (new_item[j].expiration_date.year < items[i].expiration_date.year) items[i].expiration_date = new_item[j].expiration_date;
						else if (new_item[j].expiration_date.year == items[i].expiration_date.year) {
							if (new_item[j].expiration_date.month < items[i].expiration_date.month)items[i].expiration_date = new_item[j].expiration_date;
							else if (new_item[j].expiration_date.month == items[i].expiration_date.month) {
								if (new_item[j].expiration_date.day < items[i].expiration_date.day)items[i].expiration_date = new_item[j].expiration_date;
							}
						}
					}
					else continue;
				}
				if (sw == 0) insert(new_item[j]);
			}
			break;
		case 6://sell
			printf("inter item's id you selled :\n");
			scanf_s("%d", &j);
			sell((j - 1));
			printf("****count chek****");
			break;
		case 7://show
			printf("would you like to show with wich way ?\n");
			printf("1.all the item\n2.ziro inventory\n3.near expration date\n");
			scanf_s("%d", &i);
			switch (i)
			{
			case 1:
				printf("--------------------------------------------------------------------------------\n");
				printf("       Name                        Expiration Date     Count      ID       price\n");
				for (int i = 0; i < coant_items; i++) {
					output(i);
				}
				printf("--------------------------------------------------------------------------------\n");
				break;
			case 2:
				printf("--------------------------------------------------------------------------------\n");
				printf("       Name                        Expiration Date     Count      ID       price\n");
				for (int j = 0; j < coant_items; j++) {
					if (items[j].count == 0) output(j);
					else continue;
				}
				printf("--------------------------------------------------------------------------------\n");
				break;
			case 3:
				printf("--------------------------------------------------------------------------------\n");
				printf("       Name                        Expiration Date     Count      ID       price\n");
				for (int j = 0; j < coant_items; j++) {
					if (items[j].expiration_date.month - today.month == 2 && items[j].expiration_date.year >= today.year && items[j].expiration_date.year != 1111) output(j);
					if (items[j].expiration_date.year < today.year && items[j].expiration_date.year != 1111) output(j);
					else continue;
				}
				printf("--------------------------------------------------------------------------------\n");
				break;

			default:
				break;
			}

		default:
			break;
		}
		printf("\ndo you want to continue ?\n1.yes\n2.no\n");
		scanf_s("%d", &ch);
		if (ch == 2) {
			CleenScreen(); printf("\n***********GOODBUY************\n");
		}
	} while (ch == 1);
	return 0;
}
