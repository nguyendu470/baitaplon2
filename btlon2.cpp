#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
struct book_st{
	char Ten[30];
	char theloai[30];
	int giatien;
};
void nhap(book_st booklist[] ,int n);
void hoanvi(book_st &book1, book_st &book2);
void sapxep(book_st booklist[],int n);
void xuatChiTietCuonSach(book_st booklist[], int n);
int thongke(book_st booklist[],int n);
void xuatthongke(book_st booklist[],int n);
int timsach(book_st booklist[],int n);
book_st xuatvaotep(book_st booklist[],int n, char fileName[]);
void menu(book_st booklist[], int n);


int main()
	{
	int n=3;
 book_st *bookList = (struct book_st *)malloc(n * sizeof(struct book_st));
	char fileName[] = "book.dat";
	book_st booklist[3];
	 system("color e");
	menu(booklist,n);	
	return 0;
}
void menu(book_st booklist[], int n){
	char fileName[] = "book.dat";
    int luachon;
    do{
    	system("cls");
        printf("\n\t\t******************************************\n");
        printf("\t\t**    CHUONG TRINH QUAN LY SACH         **\n");
        printf("\t\t**     1. Nhap Thong Tin sach           **\n");
        printf("\t\t**     2. xuat chi tiet tung cuon sach  **\n");
        printf("\t\t******************************************\n");
        printf("\t\t**     3. tim kiem sach theo the loai   **\n");
        printf("\t\t**     4.  xuat vao tep                 **\n");
        printf("\t\t**     5. Thoat                         **\n");
        printf("\t\t******************************************\n");
        printf("\t\t**       Nhap lua chon cua ban          **\n");
         scanf("%d", &luachon);
    switch (luachon)
    {
    case 1:
        nhap(booklist,n);
        printf("\nBam phim bat ky de tiep tuc!");
        getch();
       
        break;
    case 2:
        xuatChiTietCuonSach(booklist,n);
        xuatthongke(booklist,n);
        printf("\nBam phim bat ky de tiep tuc!");
        getch();
       
        break;
    case 3:
    	timsach(booklist,n);
    	printf("\nBam phim bat ky de tiep tuc!");
         getch();
         break;
     case 4:
     	xuatvaotep(booklist, n, fileName);
   	     printf("\nghi thong tin sach thanh cong vao file %s!\n", fileName);
   	     printf("\nBam phim bat ky de tiep tuc!");
         getch();
     
         break;
      case 5:
            printf("\nBan da chon thoat chuong trinh!\n");
            
                exit(0);
            default:
                printf("\nKhong co chuc nang nay!");
                
                break;
        }
    }
        while(luachon<6);
	    	
    }
   



void nhap(book_st booklist[] ,int n){
	for(int i=0;i<n;i++){
	printf("\n\n\t\tNHAP THONG TIN QUYEN SACH %d ",i);
	fflush(stdin);
	printf("\nNhap ten quyen sach : ");
	gets(booklist[i].Ten);
	fflush(stdin);
	printf("\nnhap the loai: ");
	gets(booklist[i].theloai);
	fflush(stdin);
	printf("\nNhap gia tien: ");
	scanf("%d",&booklist[i].giatien);
   }
}

int timsach(book_st booklist[],int n)
	{
	 char timsach[30];
    printf("\n Nhap ten the loai : ");
    fflush(stdin);
    gets(timsach);
    for(int i=0;i<n;i++)
    {
	 if(strcmp(timsach,booklist[i].theloai) == 0)
 
        {
       	 printf("STT\t ten\t theloai\t giatien\n");
       	 printf("%d\t %s\t %s\t   \t%d\n",i,booklist[i].Ten,booklist[i].theloai,booklist[i].giatien);
	    }

    }
			 
    
}
void hoanvi( book_st &book1,book_st &book2){
	book_st tempt;
	tempt = book1;
             book1=book2;
             book2 = tempt;
}
void sapxep(book_st booklist[],int n){
	for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(strcmp(booklist[j].theloai,booklist[j+1].theloai)<0){
            	hoanvi(booklist[j],booklist[j+1]);
            	
             
            }
        }
	}
}

void xuatChiTietCuonSach(book_st booklist[], int n){
     sapxep(booklist,n);
     printf("STT\t ten\t theloai\t giatien\n");
    for(int i=0;i<n;i++){
    
        printf("%d\t %s\t\t %s\t\t %d\n",i,booklist[i].Ten,booklist[i].theloai,booklist[i].giatien);
    }
    
}
int thongke(book_st booklist[],int n){
	char theloai[30];
	int dem=1;
    for(int i=1;i<n;i++)
 {
 	for(int j=0;j<n-i;j++)
 	{
	 	
	 if(strcmp(booklist[j].theloai,booklist[j+1].theloai) == 0)
        {
           dem= dem + 1;
        } 
    
   if(strcmp(booklist[j].theloai,booklist[j+1].theloai) != 0)
		{
			dem=dem;
		}   
 	}
 }
   return dem;
}
void xuatthongke(book_st booklist[],int n)
{
	int dem = thongke(booklist,n);
	for(int i=0;i<n;i++){
	printf("\nthe loai %s co so %d quyen",booklist[i].theloai,dem);
}
}
book_st xuatvaotep( book_st booklist[],int n, char fileName[]){
	FILE *fp;
	fp = fopen (fileName,"w");
     fprintf(fp, "\t%20s\t%5s\t%5s\n", "Ten","theloai", "giatien");
    for(int i = 0;i < n;i++){
        fprintf(fp, "\t%20s\t%5s\t%5d\n", booklist[i].Ten,booklist[i].theloai, booklist[i].giatien);
    }
    fclose (fp);
}
	

   	

 
