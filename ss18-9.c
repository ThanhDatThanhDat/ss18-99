#include<stdio.h>
#include<string.h>

    struct Dish{
		int id;
		char name[100];
		int price; 
	};
	struct Dish menu[100]={
		{1, "Bim Bim", 5.000},
		{2, "Nuoc Ngot", 10.000},
		{3, "Pho Bo Nam Dinh", 30.000},
		{4, "Xiu Pao", 6.000},
		{5, "Banh mi cau Do Quan", 25.000},
	};

// Khai bao nguyen mau ham
void Menu();
void inMenu();
void themMenu();
void suaMenu();
void xoaMenu();
void sapxepMenu();
void timkiemMenu();
void thoatMenu();

int cound=5;

int main(){
	int choice;
	do{
		Menu();
		printf("\nLua chon cua ban la : ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				inMenu();
			break;
			case 2:
				themMenu();
			break;
			case 3:
				suaMenu();
			break;
			case 4:
				xoaMenu();
			break;
			case 5: 
			    sapxepMenu();
			break;
			case 6: 
			    timkiemMenu();
			break;
			case 7:
				thoatMenu();
				return 0;
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai!\n");	
		}
	}while(choice!=7);
	return 0; 
} 

// Khai bao logic ham
void Menu(){
	printf("\n              MENU              \n");
	printf("\n 1. In ra gia tri cac phan tu co trong menu mon an.\n");
	printf("\n 2. Them mot phan tu.\n");
	printf("\n 3. Sua mot phan tu.\n");
	printf("\n 4. Xoa mot phan tu.\n");
	printf("\n 5. Sap xep cac phan.\n");
	printf("\n 6. Tim kiem phan tu theo name nhap vao.\n");
	printf("\n 7. Thoat.\n");
}
void inMenu(){
	printf("\n        THUC DON       \n");
	for(int i=0;i<cound;i++){
		printf(" %d, %s, %d.000 VND\n", menu[i].id, menu[i].name, menu[i].price);
	}
	printf("\n");
}

void themMenu(){
	fflush(stdin); 
    menu[cound].id = cound + 1;
    printf("Them mon an: \n");
    printf("Nhap ten mon an muon them: ");
    fgets(menu[cound].name, sizeof(menu[cound].name), stdin);
    // loai bo so \n 
    menu[cound].name[strcspn(menu[cound].name, "\n")] = '\0';
    
    printf("Nhap gia moi cho mon an: ");
    scanf("%d", &menu[cound].price);
    cound++; 
    
    printf("\nTHUC DON SAU KHI THEM\n");
    for(int  i=0;i<cound;i++){
        printf(" %d. %s, %d.000 VND\n", menu[i].id, menu[i].name, menu[i].price);
	}
}

void suaMenu(){
	int id;
    printf("Nhap vi tri mon an muon sua: ");
    scanf("%d", &id);
    fflush(stdin); 
    id--; 
    printf("Nhap ten moi cho mon an : ");
    fgets(menu[id].name, sizeof(menu[id].name), stdin);
    // loai bo so \n 
    menu[id].name[strcspn(menu[id].name, "\n")] = '\0';
    
    printf("Nhap gia moi cho mon an: ");
    scanf("%d", &menu[id].price);

    printf("\nTHUC DON SAU KHI SUA\n");
	for (int i=0;i<cound;i++){
        printf(" %d. %s, %d.000 VND\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

void xoaMenu(){
	int id;
    printf("Nhap vi tri mon an muon xoa : "); 
    scanf("%d", &id);
    id -= 1;
    for (int i=id;i<cound-1;i++){
        menu[i] = menu[i + 1];
    }
    cound--; 
    
    printf("\nTHUC DON SAU KHI XOA\n");
    for (int i=0;i<cound;i++){
        printf(" %d. %s, %d.000 VND\n", menu[i].id, menu[i].name, menu[i].price);
    }
} 

void sapxepMenu(){
	for (int i=0;i<cound-1;i++){
        for (int j=i+1;j<cound;j++){
            if (menu[i].price > menu[j].price){
                struct Dish temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }

    printf("\nTHUC DON SAU KHI SAP XEP THEO GIA\n");
    for (int i=0;i<cound;i++){
        printf(" %d. %s, %d.000 VND\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

void  timkiemMenu(){
	
}

void thoatMenu(){
	printf("   THOAT CHUONG TRINH.   \n");
}
